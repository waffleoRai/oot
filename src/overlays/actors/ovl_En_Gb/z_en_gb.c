/*
 * File: z_en_gb.c
 * Overlay: ovl_En_Gb
 * Description: Poe Seller
 */

#include "z_en_gb.h"
#include "objects/object_ps/object_ps.h"

#define FLAGS 0x00000009

#define THIS ((EnGb*)thisx)

void EnGb_Init(Actor* thisx, GlobalContext* globalCtx);
void EnGb_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnGb_Update(Actor* thisx, GlobalContext* globalCtx);
void EnGb_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80A2F83C(EnGb* this, GlobalContext* globalCtx);
void func_80A2FC70(EnGb* this, GlobalContext* globalCtx);
void func_80A2FA50(EnGb* this, GlobalContext* globalCtx);
void func_80A2F9C0(EnGb* this, GlobalContext* globalCtx);
void func_80A2F94C(EnGb* this, GlobalContext* globalCtx);
void func_80A2FB40(EnGb* this, GlobalContext* globalCtx);
void func_80A2FBB0(EnGb* this, GlobalContext* globalCtx);
void func_80A2FC0C(EnGb* this, GlobalContext* globalCtx);

void EnGb_DrawCagedSouls(EnGb* this, GlobalContext* globalCtx);
void EnGb_UpdateCagedSouls(EnGb* this, GlobalContext* globalCtx);

const ActorInit En_Gb_InitVars = {
    ACTOR_EN_GB,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_PS,
    sizeof(EnGb),
    (ActorFunc)EnGb_Init,
    (ActorFunc)EnGb_Destroy,
    (ActorFunc)EnGb_Update,
    (ActorFunc)EnGb_Draw,
};

static EnGbCagedSoulInfo sCagedSoulInfo[] = {
    { { 255, 255, 170, 255 }, { 255, 200, 0, 255 }, gPoeSellerAngrySoulTex, -15 },
    { { 255, 255, 170, 255 }, { 0, 150, 0, 255 }, gPoeSellerHappySoulTex, -12 },
    { { 255, 170, 255, 255 }, { 100, 0, 150, 255 }, gPoeSellerSadSoulTex, -8 },
};

static ColliderCylinderInitType1 sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_NONE,
        OC1_ON | OC1_TYPE_ALL,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0x00000000, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_NONE,
        OCELEM_ON,
    },
    { 40, 75, 0, { 0, 0, 0 } },
};

static ColliderCylinderInitType1 sBottlesCylindersInit[] = {
    {
        {
            COLTYPE_NONE,
            AT_NONE,
            AC_NONE,
            OC1_ON | OC1_TYPE_ALL,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x00000000, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_NONE,
            OCELEM_ON,
        },
        { 4, 20, 0, { 0, 0, 0 } },
    },
    {
        {
            COLTYPE_NONE,
            AT_NONE,
            AC_NONE,
            OC1_ON | OC1_TYPE_ALL,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x00000000, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_NONE,
            OCELEM_ON,
        },
        { 4, 20, 0, { 0, 0, 0 } },
    },
    {
        {
            COLTYPE_NONE,
            AT_NONE,
            AC_NONE,
            OC1_ON | OC1_TYPE_ALL,
            COLSHAPE_CYLINDER,
        },
        {
            ELEMTYPE_UNK0,
            { 0x00000000, 0x00, 0x00 },
            { 0x00000000, 0x00, 0x00 },
            TOUCH_NONE,
            BUMP_NONE,
            OCELEM_ON,
        },
        { 10, 20, 0, { 0, 0, 0 } },
    },
};

static InitChainEntry sInitChain[] = {
    ICHAIN_U8(targetMode, 6, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 2200, ICHAIN_STOP),
};

// relative positions of poe souls
static Vec3f sCagedSoulPositions[] = {
    { -8.0f, 112.0f, -8.0f },
    { -3.0f, 112.0f, 29.0f },
    { 31.0f, 112.0f, 29.0f },
    { 31.0f, 112.0f, -8.0f },
};

// relative positions of bottles
static Vec3f sBottlesPositions[] = {
    { -48.0f, 0.0f, 34.0f },
    { -55.0f, 0.0f, 49.0f },
    { -48.0f, 0.0f, 60.0f },
};

void func_80A2F180(EnGb* this) {
    if (gSaveContext.infTable[0xB] & 0x40) {
        this->textId = 0x70F5;
    } else {
        this->textId = 0x70F4;
    }
}

void EnGb_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnGb* this = THIS;
    s32 pad;
    CollisionHeader* colHeader = NULL;
    s32 i;
    f32 rand;
    Vec3f focusOffset;

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    DynaPolyActor_Init(&this->dyna, DPM_UNK);
    CollisionHeader_GetVirtual(&gPoeSellerCol, &colHeader);
    this->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &this->dyna.actor, colHeader);
    SkelAnime_InitFlex(globalCtx, &this->skelAnime, &gPoeSellerSkel, &gPoeSellerIdleAnim, this->jointTable,
                       this->morphTable, 12);
    Collider_InitCylinder(globalCtx, &this->collider);
    Collider_SetCylinderType1(globalCtx, &this->collider, &this->dyna.actor, &sCylinderInit);

    for (i = 0; i < ARRAY_COUNT(sBottlesCylindersInit); i++) {
        Collider_InitCylinder(globalCtx, &this->bottlesColliders[i]);
        Collider_SetCylinderType1(globalCtx, &this->bottlesColliders[i], &this->dyna.actor, &sBottlesCylindersInit[i]);
    }

    this->light = LightContext_InsertLight(globalCtx, &globalCtx->lightCtx, &this->lightInfo);
    Lights_PointNoGlowSetInfo(&this->lightInfo, this->dyna.actor.home.pos.x, this->dyna.actor.home.pos.y,
                              this->dyna.actor.home.pos.z, 255, 255, 255, 200);

    ActorShape_Init(&this->dyna.actor.shape, 0.0f, ActorShadow_DrawCircle, 35.0f);
    Actor_SetScale(&this->dyna.actor, 0.01f);
    this->dyna.actor.colChkInfo.mass = 0xFF;
    this->dyna.actor.speedXZ = 0.0f;
    this->dyna.actor.velocity.y = 0.0f;
    this->dyna.actor.gravity = -1.0f;
    this->actionTimer = (s16)Rand_ZeroFloat(100.0f) + 100;

    for (i = 0; i < ARRAY_COUNT(sCagedSoulPositions); i++) {
        this->cagedSouls[i].infoIdx = (s32)Rand_ZeroFloat(30.0f) % 3;
        this->cagedSouls[i].unk_14.x = this->cagedSouls[i].translation.x =
            sCagedSoulPositions[i].x + this->dyna.actor.world.pos.x;
        this->cagedSouls[i].unk_14.y = this->cagedSouls[i].translation.y =
            sCagedSoulPositions[i].y + this->dyna.actor.world.pos.y;
        this->cagedSouls[i].unk_14.z = this->cagedSouls[i].translation.z =
            sCagedSoulPositions[i].z + this->dyna.actor.world.pos.z;
        this->cagedSouls[i].unk_1 = 1;
        this->cagedSouls[i].unk_3 = this->cagedSouls[i].unk_2 = 0;
        this->cagedSouls[i].unk_20 = this->cagedSouls[i].unk_24 = 0.0f;
        this->cagedSouls[i].unk_6 = Rand_ZeroFloat(40.0f);
        this->cagedSouls[i].rotate180 = this->cagedSouls[i].unk_6 & 1;
        this->cagedSouls[i].unk_28 = 0.2f;
    }

    rand = Rand_ZeroOne();
    this->lightColor.r = (s8)(rand * 30.0f) + 225;
    this->lightColor.g = (s8)(rand * 100.0f) + 155;
    this->lightColor.b = (s8)(rand * 160.0f) + 95;
    this->lightColor.a = 200;
    Matrix_Translate(this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y, this->dyna.actor.world.pos.z,
                     MTXMODE_NEW);
    Matrix_RotateRPY(this->dyna.actor.world.rot.x, this->dyna.actor.world.rot.y, this->dyna.actor.world.rot.z,
                     MTXMODE_APPLY);
    focusOffset.x = focusOffset.y = 0.0f;
    focusOffset.z = 44.0f;
    Matrix_MultVec3f(&focusOffset, &this->dyna.actor.focus.pos);
    this->dyna.actor.focus.pos.y += 62.5f;
    func_80A2F180(this);
    this->actionFunc = func_80A2F83C;
}

void EnGb_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnGb* this = THIS;

    Collider_DestroyCylinder(globalCtx, &this->collider);
    LightContext_RemoveLight(globalCtx, &globalCtx->lightCtx, this->light);
    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, this->dyna.bgId);
}

void func_80A2F608(EnGb* this) {
    s32 i;
    Vec3f sp48;
    Vec3f sp3C;

    Matrix_Translate(this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y, this->dyna.actor.world.pos.z,
                     MTXMODE_NEW);
    Matrix_RotateRPY(this->dyna.actor.world.rot.x, this->dyna.actor.world.rot.y, this->dyna.actor.world.rot.z,
                     MTXMODE_APPLY);
    sp48.x = sp48.y = 0.0f;
    sp48.z = 25.0f;
    Matrix_MultVec3f(&sp48, &sp3C);
    this->collider.dim.pos.x = sp3C.x;
    this->collider.dim.pos.y = sp3C.y;
    this->collider.dim.pos.z = sp3C.z;

    for (i = 0; i < ARRAY_COUNT(sBottlesPositions); i++) {
        Matrix_Translate(this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y, this->dyna.actor.world.pos.z,
                         MTXMODE_NEW);
        Matrix_RotateRPY(this->dyna.actor.world.rot.x, this->dyna.actor.world.rot.y, this->dyna.actor.world.rot.z,
                         MTXMODE_APPLY);
        Matrix_MultVec3f(&sBottlesPositions[i], &sp3C);
        this->bottlesColliders[i].dim.pos.x = sp3C.x;
        this->bottlesColliders[i].dim.pos.y = sp3C.y;
        this->bottlesColliders[i].dim.pos.z = sp3C.z;
    }
}

s32 func_80A2F760(EnGb* this) {
    s32 i;
    for (i = 0; i < ARRAY_COUNT(this->cagedSouls); i++) {
        if (this->cagedSouls[i].unk_3) {
            return 1;
        }
    }
    return 0;
}

void func_80A2F7C0(EnGb* this) {
    Animation_Change(&this->skelAnime, &gPoeSellerSwingStickAnim, 1.0f, 0.0f,
                     Animation_GetLastFrame(&gPoeSellerSwingStickAnim), ANIMMODE_ONCE, 0.0f);
    Audio_PlayActorSound2(&this->dyna.actor, NA_SE_EV_NALE_MAGIC);
    this->actionFunc = func_80A2FC70;
}

void func_80A2F83C(EnGb* this, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    if (!func_80A2F760(this)) {
        if (this->actionTimer != 0) {
            this->actionTimer--;
        } else {
            func_80A2F7C0(this);
            return;
        }
    }
    if (func_8002F194(&this->dyna.actor, globalCtx)) {
        switch (func_8002F368(globalCtx)) {
            case EXCH_ITEM_NONE:
                func_80A2F180(this);
                this->actionFunc = func_80A2F94C;
                break;
            case EXCH_ITEM_POE:
                player->actor.textId = 0x70F6;
                this->actionFunc = func_80A2F9C0;
                break;
            case EXCH_ITEM_BIG_POE:
                player->actor.textId = 0x70F7;
                this->actionFunc = func_80A2FA50;
                break;
        }
        return;
    }
    if (this->dyna.actor.xzDistToPlayer < 100.0f) {
        func_8002F298(&this->dyna.actor, globalCtx, 100.0f, EXCH_ITEM_POE);
    }
}

void func_80A2F94C(EnGb* this, GlobalContext* globalCtx) {
    if (func_8010BDBC(&globalCtx->msgCtx) == 6 && func_80106BC8(globalCtx)) {
        if (!(gSaveContext.infTable[0xB] & 0x40)) {
            gSaveContext.infTable[0xB] |= 0x40;
        }
        func_80A2F180(this);
        this->actionFunc = func_80A2F83C;
    }
}

void func_80A2F9C0(EnGb* this, GlobalContext* globalCtx) {
    if (func_8010BDBC(&globalCtx->msgCtx) == 6 && func_80106BC8(globalCtx)) {
        if (!(gSaveContext.infTable[0xB] & 0x40)) {
            gSaveContext.infTable[0xB] |= 0x40;
        }
        func_80A2F180(this);
        Player_UpdateBottleHeld(globalCtx, GET_PLAYER(globalCtx), ITEM_BOTTLE, PLAYER_AP_BOTTLE);
        Rupees_ChangeBy(10);
        this->actionFunc = func_80A2F83C;
    }
}

void func_80A2FA50(EnGb* this, GlobalContext* globalCtx) {
    if (func_8010BDBC(&globalCtx->msgCtx) == 6 && func_80106BC8(globalCtx)) {
        if (!(gSaveContext.infTable[0xB] & 0x40)) {
            gSaveContext.infTable[0xB] |= 0x40;
        }
        func_80A2F180(this);
        Player_UpdateBottleHeld(globalCtx, GET_PLAYER(globalCtx), ITEM_BOTTLE, PLAYER_AP_BOTTLE);
        Rupees_ChangeBy(50);
        HIGH_SCORE(HS_POE_POINTS) += 100;
        if (HIGH_SCORE(HS_POE_POINTS) != 1000) {
            if (HIGH_SCORE(HS_POE_POINTS) > 1100) {
                HIGH_SCORE(HS_POE_POINTS) = 1100;
            }
            this->actionFunc = func_80A2F83C;
        } else {
            Player* player = GET_PLAYER(globalCtx);

            player->exchangeItemId = EXCH_ITEM_NONE;
            this->textId = 0x70F8;
            func_8010B720(globalCtx, this->textId);
            this->actionFunc = func_80A2FB40;
        }
    }
}

void func_80A2FB40(EnGb* this, GlobalContext* globalCtx) {
    if (func_8010BDBC(&globalCtx->msgCtx) == 6 && func_80106BC8(globalCtx)) {
        func_8002F434(&this->dyna.actor, globalCtx, GI_BOTTLE, 100.0f, 10.0f);
        this->actionFunc = func_80A2FBB0;
    }
}

void func_80A2FBB0(EnGb* this, GlobalContext* globalCtx) {
    if (Actor_HasParent(&this->dyna.actor, globalCtx)) {
        this->dyna.actor.parent = NULL;
        this->actionFunc = func_80A2FC0C;
    } else {
        func_8002F434(&this->dyna.actor, globalCtx, GI_BOTTLE, 100.0f, 10.0f);
    }
}

void func_80A2FC0C(EnGb* this, GlobalContext* globalCtx) {
    if (func_8010BDBC(&globalCtx->msgCtx) == 6 && func_80106BC8(globalCtx)) {
        func_8002F194(&this->dyna.actor, globalCtx);
        func_80A2F180(this);
        this->actionFunc = func_80A2F83C;
    }
}

void func_80A2FC70(EnGb* this, GlobalContext* globalCtx) {
    if (this->skelAnime.curFrame == Animation_GetLastFrame(&gPoeSellerSwingStickAnim)) {
        Animation_Change(&this->skelAnime, &gPoeSellerIdleAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gPoeSellerIdleAnim),
                         ANIMMODE_LOOP, 0.0f);
        this->actionFunc = func_80A2F83C;
    } else if (this->skelAnime.curFrame == 18.0f) {
        this->cagedSouls[1].unk_1 = 3;
        this->cagedSouls[1].unk_3 = 1;
        this->cagedSouls[2].unk_1 = 3;
        this->cagedSouls[2].unk_3 = 1;
        this->cagedSouls[3].unk_1 = 3;
        this->cagedSouls[3].unk_3 = 1;
        if (this->actionFunc) {} // these ifs cannot just contain a constant
        this->cagedSouls[0].unk_1 = 3;
        this->cagedSouls[0].unk_3 = 1;
        if (this->actionFunc) {}
        this->actionTimer = (s16)Rand_ZeroFloat(600.0f) + 600;
        Audio_PlayActorSound2(&this->dyna.actor, NA_SE_EV_WOOD_HIT);
    }
}

void EnGb_Update(Actor* thisx, GlobalContext* globalCtx2) {
    EnGb* this = THIS;
    GlobalContext* globalCtx = globalCtx2;
    s32 i;
    f32 rand;

    this->frameTimer++;
    SkelAnime_Update(&this->skelAnime);
    this->actionFunc(this, globalCtx);
    this->dyna.actor.textId = this->textId;
    func_80A2F608(this);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &this->collider.base);

    for (i = 0; i < ARRAY_COUNT(this->bottlesColliders); i++) {
        CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &this->bottlesColliders[i].base);
    }

    rand = Rand_ZeroOne();
    this->lightColor.r = (s8)(rand * 30.0f) + 225;
    this->lightColor.g = (s8)(rand * 100.0f) + 155;
    this->lightColor.b = (s8)(rand * 160.0f) + 95;
    this->lightColor.a = 200;
    EnGb_UpdateCagedSouls(this, globalCtx);
}

void EnGb_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnGb* this = THIS;
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_gb.c", 763);

    func_80093D18(globalCtx->state.gfxCtx);

    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetEnvColor(POLY_OPA_DISP++, this->lightColor.r, this->lightColor.g, this->lightColor.b, 255);

    Lights_PointNoGlowSetInfo(&this->lightInfo, this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y,
                              this->dyna.actor.world.pos.z, this->lightColor.r, this->lightColor.g, this->lightColor.b,
                              this->lightColor.a);
    SkelAnime_DrawFlexOpa(globalCtx, this->skelAnime.skeleton, this->skelAnime.jointTable, this->skelAnime.dListCount,
                          NULL, NULL, &this->dyna.actor);
    EnGb_DrawCagedSouls(this, globalCtx);
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_gb.c", 796);
}

void EnGb_UpdateCagedSouls(EnGb* this, GlobalContext* globalCtx) {
    f32 temp_f20;
    s16 rot;
    s32 i;

    for (i = 0; i < 4; i++) {
        switch (this->cagedSouls[i].unk_1) {
            case 0:
                Math_ApproachF(&this->cagedSouls[i].unk_20, 1.0f, 0.02f, this->cagedSouls[i].unk_24);
                Math_ApproachF(&this->cagedSouls[i].unk_24, 1.0f, 0.001f, 1.0f);
                if ((this->cagedSouls[i].unk_28 - .01f) <= this->cagedSouls[i].unk_20) {
                    this->cagedSouls[i].unk_20 = this->cagedSouls[i].unk_28;
                    this->cagedSouls[i].unk_24 = 0.0f;
                    this->cagedSouls[i].unk_1 = 1;
                    this->cagedSouls[i].unk_2 = 2;
                    this->cagedSouls[i].unk_6 = 0;
                }
                break;
            case 1:
                if (this->cagedSouls[i].unk_6 != 0) {
                    this->cagedSouls[i].unk_6--;
                } else {
                    this->cagedSouls[i].unk_3 = 0;
                    this->cagedSouls[i].unk_24 = 0.0f;
                    this->cagedSouls[i].unk_1 = this->cagedSouls[i].unk_2;
                }
                break;
            case 2:
                Math_ApproachF(&this->cagedSouls[i].unk_20, 0.0f, 0.02f, this->cagedSouls[i].unk_24);
                Math_ApproachF(&this->cagedSouls[i].unk_24, 1.0f, 0.001f, 1.0f);
                if (this->cagedSouls[i].unk_20 <= 0.01f) {
                    this->cagedSouls[i].unk_28 = this->cagedSouls[i].unk_28 + 0.2f;
                    if (this->cagedSouls[i].unk_28 > 1.0f) {
                        this->cagedSouls[i].unk_28 = 1.0f;
                    }
                    this->cagedSouls[i].unk_20 = 0.0f;
                    this->cagedSouls[i].unk_24 = 0.0f;
                    this->cagedSouls[i].unk_1 = 1;
                    this->cagedSouls[i].unk_2 = 0;
                    this->cagedSouls[i].unk_6 = 0;
                }
                break;
            case 3:
                Math_ApproachF(&this->cagedSouls[i].unk_20, 0.0f, 0.5f, 1.0f);
                if (this->cagedSouls[i].unk_20 <= 0.01f) {
                    this->cagedSouls[i].unk_28 = 0.2f;
                    this->cagedSouls[i].unk_20 = 0.0f;
                    this->cagedSouls[i].unk_24 = 0.0f;
                    this->cagedSouls[i].unk_1 = 1;
                    this->cagedSouls[i].unk_2 = 0;
                    this->cagedSouls[i].unk_6 = (s16)Rand_ZeroFloat(60.0f) + 60;
                }
                break;
        }

        temp_f20 = this->cagedSouls[i].unk_20 * 60.0f;
        if ((i == 0) || (i == 3)) {
            this->cagedSouls[i].translation.x = this->cagedSouls[i].unk_14.x;
            this->cagedSouls[i].translation.y = this->cagedSouls[i].unk_14.y + temp_f20;
            this->cagedSouls[i].translation.z = this->cagedSouls[i].unk_14.z;
        } else if (i == 1) {
            rot = this->dyna.actor.world.rot.y - 0x4000;
            this->cagedSouls[i].translation.x = this->cagedSouls[i].unk_14.x + Math_SinS(rot) * temp_f20;
            this->cagedSouls[i].translation.z = this->cagedSouls[i].unk_14.z + Math_CosS(rot) * temp_f20;
            this->cagedSouls[i].translation.y = this->cagedSouls[i].unk_14.y;
        } else {
            rot = this->dyna.actor.world.rot.y + 0x4000;
            this->cagedSouls[i].translation.x = this->cagedSouls[i].unk_14.x + Math_SinS(rot) * temp_f20;
            this->cagedSouls[i].translation.z = this->cagedSouls[i].unk_14.z + Math_CosS(rot) * temp_f20;
            this->cagedSouls[i].translation.y = this->cagedSouls[i].unk_14.y;
        }
    }
}

void EnGb_DrawCagedSouls(EnGb* this, GlobalContext* globalCtx) {
    s32 pad;
    s32 i;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_gb.c", 914);

    func_80093D84(globalCtx->state.gfxCtx);

    for (i = 0; i < 4; i++) {
        s32 idx = this->cagedSouls[i].infoIdx;

        gSPSegment(POLY_XLU_DISP++, 0x08,
                   Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, 0, 32, 64, 1, 0,
                                    (u32)(sCagedSoulInfo[idx].timerMultiplier * this->frameTimer) % 512, 32, 128));
        gSPSegment(POLY_XLU_DISP++, 0x09, SEGMENTED_TO_VIRTUAL(sCagedSoulInfo[idx].texture));
        gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, sCagedSoulInfo[idx].prim.r, sCagedSoulInfo[idx].prim.g,
                        sCagedSoulInfo[idx].prim.b, sCagedSoulInfo[idx].prim.a);
        gDPSetEnvColor(POLY_XLU_DISP++, sCagedSoulInfo[idx].env.r, sCagedSoulInfo[idx].env.g, sCagedSoulInfo[idx].env.b,
                       sCagedSoulInfo[idx].env.a);

        Matrix_Push();
        Matrix_Translate(this->cagedSouls[i].translation.x, this->cagedSouls[i].translation.y,
                         this->cagedSouls[i].translation.z, MTXMODE_NEW);
        func_800D1FD4(&globalCtx->mf_11DA0);

        if (this->cagedSouls[i].rotate180) {
            Matrix_RotateRPY(0, -0x8000, 0, MTXMODE_APPLY);
        }
        Matrix_Scale(0.007f, 0.007f, 1.0f, MTXMODE_APPLY);

        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_gb.c", 955),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_XLU_DISP++, gPoeSellerCagedSoulDL);

        Matrix_Pop();
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_gb.c", 962);
}
