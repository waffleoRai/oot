/*
 * File: z_bg_haka_ship.c
 * Overlay: ovl_Bg_Haka_Ship
 * Description: Shadow Temple Ship
 */

#include "z_bg_haka_ship.h"
#include "objects/object_haka_objects/object_haka_objects.h"

#define FLAGS 0x00000030

#define THIS ((BgHakaShip*)thisx)

void BgHakaShip_Init(Actor* thisx, GlobalContext* globalCtx);
void BgHakaShip_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgHakaShip_Update(Actor* thisx, GlobalContext* globalCtx);
void BgHakaShip_Draw(Actor* thisx, GlobalContext* globalCtx);
void BgHakaShip_ChildUpdatePosition(BgHakaShip* this, GlobalContext* globalCtx);
void BgHakaShip_WaitForSong(BgHakaShip* this, GlobalContext* globalCtx);
void BgHakaShip_CutsceneStationary(BgHakaShip* this, GlobalContext* globalCtx);
void BgHakaShip_Move(BgHakaShip* this, GlobalContext* globalCtx);
void BgHakaShip_SetupCrash(BgHakaShip* this, GlobalContext* globalCtx);
void BgHakaShip_CrashShake(BgHakaShip* this, GlobalContext* globalCtx);
void BgHakaShip_CrashFall(BgHakaShip* this, GlobalContext* globalCtx);

const ActorInit Bg_Haka_Ship_InitVars = {
    ACTOR_BG_HAKA_SHIP,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_HAKA_OBJECTS,
    sizeof(BgHakaShip),
    (ActorFunc)BgHakaShip_Init,
    (ActorFunc)BgHakaShip_Destroy,
    (ActorFunc)BgHakaShip_Update,
    (ActorFunc)BgHakaShip_Draw,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

void BgHakaShip_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgHakaShip* this = THIS;
    s32 pad;
    CollisionHeader* colHeader = NULL;

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    DynaPolyActor_Init(&this->dyna, 1);
    this->switchFlag = (thisx->params >> 8) & 0xFF;
    this->dyna.actor.params &= 0xFF;

    if (this->dyna.actor.params == 0) {
        CollisionHeader_GetVirtual(&object_haka_objects_Col_00E408, &colHeader);
        this->counter = 8;
        this->actionFunc = BgHakaShip_WaitForSong;
    } else {
        CollisionHeader_GetVirtual(&object_haka_objects_Col_00ED7C, &colHeader);
        this->actionFunc = BgHakaShip_ChildUpdatePosition;
    }
    this->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &this->dyna.actor, colHeader);
    this->dyna.actor.world.rot.y = this->dyna.actor.shape.rot.y - 0x4000;
    this->yOffset = 0;
    if (this->dyna.actor.params == 0 &&
        Actor_SpawnAsChild(&globalCtx->actorCtx, &this->dyna.actor, globalCtx, ACTOR_BG_HAKA_SHIP,
                           this->dyna.actor.world.pos.x + -10.0f, this->dyna.actor.world.pos.y + 82.0f,
                           this->dyna.actor.world.pos.z, 0, 0, 0, 1) == NULL) {
        Actor_Kill(&this->dyna.actor);
    }
}

void BgHakaShip_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgHakaShip* this = THIS;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, this->dyna.bgId);
    func_800F89E8(&this->bellSoundPos);
}

void BgHakaShip_ChildUpdatePosition(BgHakaShip* this, GlobalContext* globalCtx) {
    Actor* parent = this->dyna.actor.parent;

    if (parent != NULL && parent->update != NULL) {
        this->dyna.actor.world.pos.x = parent->world.pos.x + -10.0f;
        this->dyna.actor.world.pos.y = parent->world.pos.y + 82.0f;
        this->dyna.actor.world.pos.z = parent->world.pos.z;
    } else {
        this->dyna.actor.parent = NULL;
    }
}

void BgHakaShip_WaitForSong(BgHakaShip* this, GlobalContext* globalCtx) {
    if (Flags_GetSwitch(globalCtx, this->switchFlag)) {
        if (this->counter) {
            this->counter--;
        }
        if (this->counter == 0) {
            this->counter = 130;
            this->actionFunc = BgHakaShip_CutsceneStationary;
            osSyncPrintf("シーン 外輪船 ...  アァクション！！\n");
            OnePointCutscene_Init(globalCtx, 3390, 999, &this->dyna.actor, MAIN_CAM);
        }
    }
}

void BgHakaShip_CutsceneStationary(BgHakaShip* this, GlobalContext* globalCtx) {
    if (this->counter) {
        this->counter--;
    }
    this->yOffset = sinf(this->counter * (M_PI / 25)) * 6144.0f;
    if (this->counter == 0) {
        this->counter = 50;
        this->actionFunc = BgHakaShip_Move;
    }
}

void BgHakaShip_Move(BgHakaShip* this, GlobalContext* globalCtx) {
    f32 distanceFromHome;
    Actor* child;

    if (this->counter) {
        this->counter--;
    }
    if (this->counter == 0) {
        this->counter = 50;
    }
    this->dyna.actor.world.pos.y = (sinf(this->counter * (M_PI / 25)) * 50.0f) + this->dyna.actor.home.pos.y;

    distanceFromHome = this->dyna.actor.home.pos.x - this->dyna.actor.world.pos.x;
    if (distanceFromHome > 7650.0f) {
        this->dyna.actor.world.pos.x = this->dyna.actor.home.pos.x - 7650.0f;
        this->dyna.actor.speedXZ = 0.0f;
    }
    if (distanceFromHome > 7600.0f && !Gameplay_InCsMode(globalCtx)) {
        this->counter = 40;
        this->dyna.actor.speedXZ = 0.0f;
        func_8010B680(globalCtx, 0x5071, NULL);
        this->actionFunc = BgHakaShip_SetupCrash;
    } else {
        Math_StepToF(&this->dyna.actor.speedXZ, 4.0f, 0.2f);
    }
    child = this->dyna.actor.child;
    if (child != NULL && child->update != NULL) {
        child->shape.rot.z += ((655.0f / 13.0f) * this->dyna.actor.speedXZ);
    } else {
        this->dyna.actor.child = NULL;
    }
    this->yOffset = sinf(this->counter * (M_PI / 25)) * 6144.0f;
}

void BgHakaShip_SetupCrash(BgHakaShip* this, GlobalContext* globalCtx) {
    if (this->counter) {
        this->counter--;
    }
    if (this->counter == 0) {
        this->counter = 40;
        this->actionFunc = BgHakaShip_CrashShake;
    }
    Math_ScaledStepToS(&this->yOffset, 0, 128);
}

void BgHakaShip_CrashShake(BgHakaShip* this, GlobalContext* globalCtx) {
    if (this->counter != 0) {
        this->counter--;
    }
    this->dyna.actor.world.pos.y = this->counter % 4 * 3 - 6 + this->dyna.actor.home.pos.y;
    if (!this->counter) {
        this->dyna.actor.gravity = -1.0f;
        this->actionFunc = BgHakaShip_CrashFall;
    }
    func_8002F974(&this->dyna.actor, NA_SE_EV_BLOCKSINK - SFX_FLAG);
}

void BgHakaShip_CrashFall(BgHakaShip* this, GlobalContext* globalCtx) {
    Actor* child;

    if (this->dyna.actor.home.pos.y - this->dyna.actor.world.pos.y > 2000.0f) {
        Actor_Kill(&this->dyna.actor);
        child = this->dyna.actor.child;
        if (child != NULL && child->update != NULL) {
            Actor_Kill(child);
        }
    } else {
        Audio_PlayActorSound2(&this->dyna.actor, NA_SE_EV_BLOCKSINK - SFX_FLAG);
        if ((this->dyna.actor.home.pos.y - this->dyna.actor.world.pos.y > 500.0f) && func_8004356C(&this->dyna)) {
            Gameplay_TriggerVoidOut(globalCtx);
        }
    }
}

void BgHakaShip_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgHakaShip* this = THIS;

    this->actionFunc(this, globalCtx);
    if (this->dyna.actor.params == 0) {
        Actor_MoveForward(&this->dyna.actor);
    }
}

void BgHakaShip_Draw(Actor* thisx, GlobalContext* globalCtx) {
    BgHakaShip* this = THIS;
    f32 angleTemp;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_bg_haka_ship.c", 528);
    func_80093D18(globalCtx->state.gfxCtx);
    if (this->dyna.actor.params == 0) {
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_haka_ship.c", 534),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_OPA_DISP++, object_haka_objects_DL_00D330);
        angleTemp = this->yOffset * (M_PI / 0x8000);
        Matrix_Translate(-3670.0f, 620.0f, 1150.0f, MTXMODE_APPLY);
        Matrix_RotateZ(angleTemp, MTXMODE_APPLY);
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_haka_ship.c", 547),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_OPA_DISP++, object_haka_objects_DL_005A70);
        Matrix_Translate(0.0f, 0.0f, -2300.0f, MTXMODE_APPLY);
        Matrix_RotateZ(-(2.0f * angleTemp), MTXMODE_APPLY);
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_haka_ship.c", 556),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_OPA_DISP++, object_haka_objects_DL_005A70);
    } else {
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_haka_ship.c", 562),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_OPA_DISP++, object_haka_objects_DL_00E910);
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_bg_haka_ship.c", 568);
    if (this->actionFunc == BgHakaShip_CutsceneStationary || this->actionFunc == BgHakaShip_Move) {
        s32 pad;
        Vec3f sp2C;

        sp2C.x = this->dyna.actor.world.pos.x + -367.0f;
        sp2C.y = this->dyna.actor.world.pos.y + 62.0f;
        sp2C.z = this->dyna.actor.world.pos.z;

        SkinMatrix_Vec3fMtxFMultXYZ(&globalCtx->mf_11D60, &sp2C, &this->bellSoundPos);
        func_80078914(&this->bellSoundPos, NA_SE_EV_SHIP_BELL - SFX_FLAG);
    }
}
