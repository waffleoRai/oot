#include "z_en_goma.h"
#include "objects/gameplay_dangeon_keep/gameplay_dangeon_keep.h"
#include "objects/object_gol/object_gol.h"
#include "overlays/actors/ovl_Boss_Goma/z_boss_goma.h"
#include "overlays/effects/ovl_Effect_Ss_Hahen/z_eff_ss_hahen.h"

#define FLAGS 0x00000035

#define THIS ((EnGoma*)thisx)

void EnGoma_Init(Actor* thisx, GlobalContext* globalCtx);
void EnGoma_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnGoma_Update(Actor* thisx, GlobalContext* globalCtx);
void EnGoma_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnGoma_Flee(EnGoma* this, GlobalContext* globalCtx);
void EnGoma_EggFallToGround(EnGoma* this, GlobalContext* globalCtx);
void EnGoma_Egg(EnGoma* this, GlobalContext* globalCtx);
void EnGoma_Hatch(EnGoma* this, GlobalContext* globalCtx);
void EnGoma_Hurt(EnGoma* this, GlobalContext* globalCtx);
void EnGoma_Die(EnGoma* this, GlobalContext* globalCtx);
void EnGoma_Dead(EnGoma* this, GlobalContext* globalCtx);
void EnGoma_PrepareJump(EnGoma* this, GlobalContext* globalCtx);
void EnGoma_Land(EnGoma* this, GlobalContext* globalCtx);
void EnGoma_Jump(EnGoma* this, GlobalContext* globalCtx);
void EnGoma_Stand(EnGoma* this, GlobalContext* globalCtx);
void EnGoma_ChasePlayer(EnGoma* this, GlobalContext* globalCtx);
void EnGoma_Stunned(EnGoma* this, GlobalContext* globalCtx);
void EnGoma_LookAtPlayer(EnGoma* this, GlobalContext* globalCtx);
void EnGoma_UpdateHit(EnGoma* this, GlobalContext* globalCtx);
void EnGoma_Debris(EnGoma* this, GlobalContext* globalCtx);
void EnGoma_SpawnHatchDebris(EnGoma* this, GlobalContext* globalCtx2);
void EnGoma_BossLimb(EnGoma* this, GlobalContext* globalCtx);

void EnGoma_SetupFlee(EnGoma* this);
void EnGoma_SetupHatch(EnGoma* this, GlobalContext* globalCtx);
void EnGoma_SetupHurt(EnGoma* this, GlobalContext* globalCtx);
void EnGoma_SetupDie(EnGoma* this);
void EnGoma_SetupDead(EnGoma* this);
void EnGoma_SetupStand(EnGoma* this);
void EnGoma_SetupChasePlayer(EnGoma* this);
void EnGoma_SetupPrepareJump(EnGoma* this);
void EnGoma_SetupLand(EnGoma* this);
void EnGoma_SetupJump(EnGoma* this);
void EnGoma_SetupStunned(EnGoma* this, GlobalContext* globalCtx);

const ActorInit En_Goma_InitVars = {
    ACTOR_BOSS_GOMA,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_GOL,
    sizeof(EnGoma),
    (ActorFunc)EnGoma_Init,
    (ActorFunc)EnGoma_Destroy,
    (ActorFunc)EnGoma_Update,
    (ActorFunc)EnGoma_Draw,
};

static ColliderCylinderInit D_80A4B7A0 = {
    {
        COLTYPE_HIT3,
        AT_ON | AT_TYPE_ENEMY,
        AC_NONE,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x00, 0x08 },
        { 0xFFDFFFFF, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL,
        BUMP_NONE,
        OCELEM_ON,
    },
    { 15, 30, 10, { 0, 0, 0 } },
};

static ColliderCylinderInit D_80A4B7CC = {
    {
        COLTYPE_HIT3,
        AT_NONE,
        AC_ON | AC_TYPE_PLAYER,
        OC1_NONE,
        OC2_TYPE_1,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0xFFCFFFFF, 0x00, 0x08 },
        { 0xFFDFFFFF, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_ON,
        OCELEM_NONE,
    },
    { 15, 30, 10, { 0, 0, 0 } },
};

static u8 sSpawnNum = 0;
static Vec3f sDeadEffectVel = { 0.0f, 0.0f, 0.0f };

static InitChainEntry sInitChain[] = {
    ICHAIN_U8(targetMode, 3, ICHAIN_CONTINUE),
    ICHAIN_S8(naviEnemyId, 0x03, ICHAIN_CONTINUE),
    ICHAIN_F32_DIV1000(gravity, 0, ICHAIN_CONTINUE),
    ICHAIN_F32(targetArrowOffset, 20, ICHAIN_STOP),
};

void EnGoma_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnGoma* this = THIS;
    s16 params;

    this->eggTimer = Rand_ZeroOne() * 200.0f;
    Actor_ProcessInitChain(&this->actor, sInitChain);
    Actor_SetScale(&this->actor, 0.01f);
    params = this->actor.params;

    if (params >= 100) { // piece of boss goma
        Actor_ChangeCategory(globalCtx, &globalCtx->actorCtx, &this->actor, ACTORCAT_BOSS);
        this->actionFunc = EnGoma_BossLimb;
        this->gomaType = ENGOMA_BOSSLIMB;
        ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawCircle, 0.0f);
        this->actionTimer = this->actor.params + 150;
        this->actor.flags &= ~1;
    } else if (params >= 10) { // Debris when hatching
        this->actor.gravity = -1.3f;
        this->actor.flags &= ~1;
        this->actionTimer = 50;
        this->gomaType = ENGOMA_HATCH_DEBRIS;
        this->eggScale = 1.0f;
        this->actor.velocity.y = Rand_ZeroOne() * 5.0f + 5.0f;
        this->actionFunc = EnGoma_Debris;
        this->actor.speedXZ = Rand_ZeroOne() * 2.3f + 1.5f;
        this->actionTimer = 30;
        this->actor.scale.x = Rand_ZeroOne() * 0.005f + 0.01f;
        this->actor.scale.y = Rand_ZeroOne() * 0.005f + 0.01f;
        this->actor.scale.z = Rand_ZeroOne() * 0.005f + 0.01f;
        ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawCircle, 0.0f);
    } else { // Egg
        ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawCircle, 40.0f);
        SkelAnime_Init(globalCtx, &this->skelanime, &gObjectGolSkel, &gObjectGolStandAnim, this->jointTable,
                       this->morphTable, GOMA_LIMB_MAX);
        Animation_PlayLoop(&this->skelanime, &gObjectGolStandAnim);
        this->actor.colChkInfo.health = 2;

        if (this->actor.params < 3) { // Spawned by boss
            this->actionFunc = EnGoma_EggFallToGround;
            this->invincibilityTimer = 10;
            this->actor.speedXZ = 1.5f;
        } else if (this->actor.params == 8 || this->actor.params == 6) {
            this->actionFunc = EnGoma_Egg;
            this->spawnNum = sSpawnNum++;
        } else if (this->actor.params == 9 || this->actor.params == 7) {
            this->actionFunc = EnGoma_Egg;
        }

        if (this->actor.params >= 8) { // on ceiling
            this->eggYOffset = -1500.0f;
        } else {
            this->eggYOffset = 1500.0f;
        }

        this->gomaType = ENGOMA_EGG;
        this->eggScale = 1.0f;
        this->eggSquishAngle = Rand_ZeroOne() * 1000.0f;
        this->actionTimer = 50;
        Collider_InitCylinder(globalCtx, &this->colCyl1);
        Collider_SetCylinder(globalCtx, &this->colCyl1, &this->actor, &D_80A4B7A0);
        Collider_InitCylinder(globalCtx, &this->colCyl2);
        Collider_SetCylinder(globalCtx, &this->colCyl2, &this->actor, &D_80A4B7CC);
    }
}

void EnGoma_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnGoma* this = THIS;

    if (this->actor.params < 10) {
        Collider_DestroyCylinder(globalCtx, &this->colCyl1);
        Collider_DestroyCylinder(globalCtx, &this->colCyl2);
    }
}

void EnGoma_SetupFlee(EnGoma* this) {
    Animation_Change(&this->skelanime, &gObjectGolRunningAnim, 2.0f, 0.0f,
                     Animation_GetLastFrame(&gObjectGolRunningAnim), ANIMMODE_LOOP, -2.0f);
    this->actionFunc = EnGoma_Flee;
    this->actionTimer = 20;

    if (this->actor.params < 6) {
        Audio_PlayActorSound2(&this->actor, NA_SE_EN_GOMA_BJR_DAM2);
    } else {
        Audio_PlayActorSound2(&this->actor, NA_SE_EN_GOMA_JR_DAM2);
    }
}

void EnGoma_Flee(EnGoma* this, GlobalContext* globalCtx) {
    SkelAnime_Update(&this->skelanime);
    Math_ApproachF(&this->actor.speedXZ, 6.6666665f, 0.5f, 2.0f);
    Math_ApproachS(&this->actor.world.rot.y,
                   Actor_WorldYawTowardActor(&this->actor, &GET_PLAYER(globalCtx)->actor) + 0x8000, 3, 2000);
    Math_ApproachS(&this->actor.shape.rot.y, this->actor.world.rot.y, 2, 3000);

    if (this->actionTimer == 0) {
        EnGoma_SetupStand(this);
    }
}

void EnGoma_EggFallToGround(EnGoma* this, GlobalContext* globalCtx) {
    this->actor.gravity = -1.3f;
    this->eggSquishAccel += 0.03f;
    this->eggSquishAngle += 1.0f + this->eggSquishAccel;
    Math_ApproachZeroF(&this->eggSquishAmount, 1.0f, 0.005f);
    Math_ApproachF(&this->eggYOffset, 1500.0f, 1.0f, 150.0f);

    switch (this->hatchState) {
        case 0:
            if (this->actor.bgCheckFlags & 1) { // floor
                if (this->actor.params < 6) {
                    Audio_PlayActorSound2(&this->actor, NA_SE_EN_GOMA_BJR_EGG1);
                } else {
                    Audio_PlayActorSound2(&this->actor, NA_SE_EN_GOMA_EGG1);
                }

                if (this->actor.params > 5) {
                    EnGoma_SetupHatch(this, globalCtx);
                } else {
                    this->hatchState = 1;
                    this->actionTimer = 3;
                    Math_ApproachF(&this->eggScale, 1.5f, 0.5f, 1.0f);
                }
            }
            break;

        case 1:
            if (this->actionTimer == 0) {
                this->hatchState = 2;
                this->actionTimer = 3;
                Math_ApproachF(&this->eggScale, 0.75f, 0.5f, 1.0f);
                this->actor.velocity.y = 5.0f;
                this->actor.speedXZ = 2.0f;
            } else {
                Math_ApproachF(&this->eggScale, 1.5f, 0.5f, 1.0f);
            }
            break;

        case 2:
            if (this->actionTimer == 0) {
                this->hatchState = 3;
                this->actionTimer = 80;
            } else {
                Math_ApproachF(&this->eggScale, 0.75f, 0.5f, 1.0f);
            }
            break;

        case 3:
            Math_ApproachF(&this->eggScale, 1.0f, 0.1f, 0.1f);
            if (this->actionTimer == 0) {
                EnGoma_SetupHatch(this, globalCtx);
            }
            break;
    }

    if (this->actor.bgCheckFlags & 1) {
        Math_ApproachZeroF(&this->actor.speedXZ, 0.2f, 0.05f);
    }
    this->eggPitch += (this->actor.speedXZ * 0.1f);
    this->actor.shape.rot.y = this->actor.world.rot.y;
}

void EnGoma_Egg(EnGoma* this, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);
    s32 i;

    this->eggSquishAngle += 1.0f;
    Math_ApproachF(&this->eggSquishAmount, 0.1f, 1.0f, 0.005f);
    if (fabsf(this->actor.world.pos.x - player->actor.world.pos.x) < 100.0f &&
        fabsf(this->actor.world.pos.z - player->actor.world.pos.z) < 100.0f) {
        if (++this->playerDetectionTimer > 9) {
            this->actionFunc = EnGoma_EggFallToGround;
        }
    } else {
        this->playerDetectionTimer = 0;
    }

    if (!(this->eggTimer & 0xF) && Rand_ZeroOne() < 0.5f) {
        for (i = 0; i < 2; i++) {
            Vec3f vel = { 0.0f, 0.0f, 0.0f };
            Vec3f acc = { 0.0f, -0.5f, 0.0f };
            Vec3f pos;

            pos.x = Rand_CenteredFloat(30.0f) + this->actor.world.pos.x;
            pos.y = Rand_ZeroFloat(30.0f) + this->actor.world.pos.y;
            pos.z = Rand_CenteredFloat(30.0f) + this->actor.world.pos.z;
            EffectSsHahen_Spawn(globalCtx, &pos, &vel, &acc, 0, (s16)(Rand_ZeroOne() * 5.0f) + 10, HAHEN_OBJECT_DEFAULT,
                                10, NULL);
        }
    }
}

void EnGoma_SetupHatch(EnGoma* this, GlobalContext* globalCtx) {
    Animation_Change(&this->skelanime, &gObjectGolJumpHeadbuttAnim, 1.0f, 0.0f,
                     Animation_GetLastFrame(&gObjectGolJumpHeadbuttAnim), ANIMMODE_ONCE, 0.0f);
    this->actionFunc = EnGoma_Hatch;
    Actor_SetScale(&this->actor, 0.005f);
    this->gomaType = ENGOMA_NORMAL;
    this->actionTimer = 5;
    this->actor.shape.rot.y = Actor_WorldYawTowardActor(&this->actor, &GET_PLAYER(globalCtx)->actor);
    this->actor.world.rot.y = this->actor.shape.rot.y;
    EnGoma_SpawnHatchDebris(this, globalCtx);
    this->eggScale = 1.0f;
    this->actor.speedXZ = 0.0f;
}

void EnGoma_Hatch(EnGoma* this, GlobalContext* globalCtx) {
    SkelAnime_Update(&this->skelanime);
    if (this->actionTimer == 0) {
        EnGoma_SetupStand(this);
    }
}

void EnGoma_SetupHurt(EnGoma* this, GlobalContext* globalCtx) {
    Animation_Change(&this->skelanime, &gObjectGolDamagedAnim, 1.0f, 0.0f,
                     Animation_GetLastFrame(&gObjectGolDamagedAnim), ANIMMODE_ONCE, -2.0f);
    this->actionFunc = EnGoma_Hurt;

    if ((s8)this->actor.colChkInfo.health <= 0) {
        this->actionTimer = 5;
        Enemy_StartFinishingBlow(globalCtx, &this->actor);
    } else {
        this->actionTimer = 10;
    }

    this->actor.speedXZ = 20.0f;
    this->actor.world.rot.y = this->actor.yawTowardsPlayer + 0x8000;
    if (this->actor.params < 6) {
        Audio_PlayActorSound2(&this->actor, NA_SE_EN_GOMA_BJR_DAM1);
    } else {
        Audio_PlayActorSound2(&this->actor, NA_SE_EN_GOMA_JR_DAM1);
    }
}

void EnGoma_Hurt(EnGoma* this, GlobalContext* globalCtx) {
    SkelAnime_Update(&this->skelanime);

    if (this->actor.bgCheckFlags & 1) {
        Math_ApproachZeroF(&this->actor.speedXZ, 1.0f, 2.0f);
    }

    if (this->actionTimer == 0) {
        if ((s8)this->actor.colChkInfo.health <= 0) {
            EnGoma_SetupDie(this);
        } else {
            EnGoma_SetupFlee(this);
        }
    }
}

void EnGoma_SetupDie(EnGoma* this) {
    Animation_Change(&this->skelanime, &gObjectGolDeathAnim, 1.0f, 0.0f, Animation_GetLastFrame(&gObjectGolDeathAnim),
                     ANIMMODE_ONCE, -2.0f);
    this->actionFunc = EnGoma_Die;
    this->actionTimer = 30;

    if (this->actor.params < 6) {
        Audio_PlayActorSound2(&this->actor, NA_SE_EN_GOMA_BJR_DEAD);
    } else {
        Audio_PlayActorSound2(&this->actor, NA_SE_EN_GOMA_JR_DEAD);
    }

    this->invincibilityTimer = 100;
    this->actor.flags &= ~1;
}

void EnGoma_Die(EnGoma* this, GlobalContext* globalCtx) {
    SkelAnime_Update(&this->skelanime);

    if (this->actor.bgCheckFlags & 1) {
        Math_ApproachZeroF(&this->actor.speedXZ, 1.0f, 2.0f);
    }

    if (this->actionTimer == 17) {
        if (this->actor.params < 6) {
            Audio_PlayActorSound2(&this->actor, NA_SE_EN_GOMA_BJR_LAND);
        } else {
            Audio_PlayActorSound2(&this->actor, NA_SE_EN_GOMA_JR_LAND);
        }
    }

    if (this->actionTimer == 0) {
        EnGoma_SetupDead(this);
    }
}

void EnGoma_SetupDead(EnGoma* this) {
    Animation_Change(&this->skelanime, &gObjectGolDeadTwitchingAnim, 1.0f, 0.0f,
                     Animation_GetLastFrame(&gObjectGolDeadTwitchingAnim), ANIMMODE_LOOP, -2.0f);
    this->actionFunc = EnGoma_Dead;
    this->actionTimer = 3;
}

void EnGoma_Dead(EnGoma* this, GlobalContext* globalCtx) {
    Vec3f accel;
    Vec3f pos;

    SkelAnime_Update(&this->skelanime);
    Math_ApproachZeroF(&this->actor.speedXZ, 1.0f, 2.0f);

    if (this->actionTimer == 2) {
        pos.x = this->actor.world.pos.x;
        pos.y = (this->actor.world.pos.y + 5.0f) - 10.0f;
        pos.z = this->actor.world.pos.z;
        accel = sDeadEffectVel;
        accel.y = 0.03f;
        EffectSsKFire_Spawn(globalCtx, &pos, &sDeadEffectVel, &accel, 40, 0);
    }

    if (this->actionTimer == 0 && Math_SmoothStepToF(&this->actor.scale.y, 0.0f, 0.5f, 0.00225f, 0.00001f) <= 0.001f) {
        if (this->actor.params < 6) {
            BossGoma* parent = (BossGoma*)this->actor.parent;
            parent->childrenGohmaState[this->actor.params] = -1;
        }
        Audio_PlaySoundGeneral(NA_SE_EN_EXTINCT, &this->actor.projectedPos, 4, &D_801333E0, &D_801333E0, &D_801333E8);
        Actor_Kill(&this->actor);
        Item_DropCollectibleRandom(globalCtx, NULL, &this->actor.world.pos, 0x30);
    }
    this->visualState = 2;
}

void EnGoma_SetupStand(EnGoma* this) {
    f32 lastFrame;

    lastFrame = Animation_GetLastFrame(&gObjectGolStandAnim);
    this->actionTimer = Rand_S16Offset(10, 30);
    Animation_Change(&this->skelanime, &gObjectGolStandAnim, 1.0f, 0.0f, lastFrame, ANIMMODE_LOOP, -5.0f);
    this->actionFunc = EnGoma_Stand;
    this->gomaType = ENGOMA_NORMAL;
}

void EnGoma_SetupChasePlayer(EnGoma* this) {
    Animation_Change(&this->skelanime, &gObjectGolRunningAnim, 1.0f, 0.0f,
                     Animation_GetLastFrame(&gObjectGolRunningAnim), ANIMMODE_LOOP, -5.0f);
    this->actionFunc = EnGoma_ChasePlayer;
    this->actionTimer = Rand_S16Offset(70, 110);
}

void EnGoma_SetupPrepareJump(EnGoma* this) {
    Animation_Change(&this->skelanime, &gObjectGolPrepareJumpAnim, 1.0f, 0.0f,
                     Animation_GetLastFrame(&gObjectGolPrepareJumpAnim), ANIMMODE_ONCE, -5.0f);
    this->actionFunc = EnGoma_PrepareJump;
    this->actionTimer = 30;
}

void EnGoma_PrepareJump(EnGoma* this, GlobalContext* globalCtx) {
    s16 targetAngle;

    SkelAnime_Update(&this->skelanime);
    Math_ApproachZeroF(&this->actor.speedXZ, 0.5f, 2.0f);

    targetAngle = Actor_WorldYawTowardActor(&this->actor, &GET_PLAYER(globalCtx)->actor);
    Math_ApproachS(&this->actor.world.rot.y, targetAngle, 2, 4000);
    Math_ApproachS(&this->actor.shape.rot.y, targetAngle, 2, 3000);

    if (this->actionTimer == 0) {
        EnGoma_SetupJump(this);
    }
    this->visualState = 0;
}

void EnGoma_SetupLand(EnGoma* this) {
    Animation_Change(&this->skelanime, &gObjectGolLandFromJumpAnim, 1.0f, 0.0f,
                     Animation_GetLastFrame(&gObjectGolLandFromJumpAnim), ANIMMODE_ONCE, 0.0f);
    this->actionFunc = EnGoma_Land;
    this->actionTimer = 10;
}

void EnGoma_Land(EnGoma* this, GlobalContext* globalCtx) {
    SkelAnime_Update(&this->skelanime);

    if (this->actor.bgCheckFlags & 1) {
        Math_ApproachZeroF(&this->actor.speedXZ, 1.0f, 2.0f);
    }
    if (this->actionTimer == 0) {
        EnGoma_SetupStand(this);
    }
}

void EnGoma_SetupJump(EnGoma* this) {
    Animation_Change(&this->skelanime, &gObjectGolJumpHeadbuttAnim, 1.0f, 0.0f,
                     Animation_GetLastFrame(&gObjectGolJumpHeadbuttAnim), ANIMMODE_ONCE, 0.0f);
    this->actionFunc = EnGoma_Jump;
    this->actor.velocity.y = 8.0f;

    if (this->actor.params < 6) {
        Audio_PlayActorSound2(&this->actor, NA_SE_EN_GOMA_BJR_CRY);
    } else {
        Audio_PlayActorSound2(&this->actor, NA_SE_EN_GOMA_JR_CRY);
    }
}

void EnGoma_Jump(EnGoma* this, GlobalContext* globalCtx) {
    this->actor.flags |= 0x1000000;
    SkelAnime_Update(&this->skelanime);
    Math_ApproachF(&this->actor.speedXZ, 10.0f, 0.5f, 5.0f);

    if (this->actor.velocity.y <= 0.0f && (this->actor.bgCheckFlags & 1)) {
        EnGoma_SetupLand(this);
        if (this->actor.params < 6) {
            Audio_PlayActorSound2(&this->actor, NA_SE_EN_GOMA_BJR_LAND2);
        } else {
            Audio_PlayActorSound2(&this->actor, NA_SE_EN_GOMA_JR_LAND2);
        }
    }
    this->visualState = 0;
}

void EnGoma_Stand(EnGoma* this, GlobalContext* globalCtx) {
    SkelAnime_Update(&this->skelanime);
    Math_ApproachZeroF(&this->actor.speedXZ, 0.5f, 2.0f);
    Math_ApproachS(&this->actor.shape.rot.y, Actor_WorldYawTowardActor(&this->actor, &GET_PLAYER(globalCtx)->actor), 2,
                   3000);

    if (this->actionTimer == 0) {
        EnGoma_SetupChasePlayer(this);
    }
}

void EnGoma_ChasePlayer(EnGoma* this, GlobalContext* globalCtx) {
    SkelAnime_Update(&this->skelanime);

    if (Animation_OnFrame(&this->skelanime, 1.0f) || Animation_OnFrame(&this->skelanime, 5.0f)) {
        if (this->actor.params < 6) {
            Audio_PlayActorSound2(&this->actor, NA_SE_EN_GOMA_BJR_WALK);
        } else {
            Audio_PlayActorSound2(&this->actor, NA_SE_EN_GOMA_JR_WALK);
        }
    }

    Math_ApproachF(&this->actor.speedXZ, 3.3333333f, 0.5f, 2.0f);
    Math_ApproachS(&this->actor.world.rot.y, this->actor.yawTowardsPlayer, 3, 2000);
    Math_ApproachS(&this->actor.shape.rot.y, this->actor.world.rot.y, 2, 3000);

    if (this->actor.bgCheckFlags & 1) {
        this->actor.velocity.y = 0.0f;
    }
    if (this->actor.xzDistToPlayer <= 150.0f) {
        EnGoma_SetupPrepareJump(this);
    }
}

void EnGoma_SetupStunned(EnGoma* this, GlobalContext* globalCtx) {
    this->actionFunc = EnGoma_Stunned;
    this->stunTimer = 100;
    Animation_MorphToLoop(&this->skelanime, &gObjectGolStandAnim, -5.0f);
    this->actionTimer = (s16)Rand_ZeroFloat(15.0f) + 3;

    if (this->actor.params < 6) {
        Audio_PlayActorSound2(&this->actor, NA_SE_EN_GOMA_BJR_FREEZE);
    } else {
        Audio_PlayActorSound2(&this->actor, NA_SE_EN_GOMA_JR_FREEZE);
    }
}

void EnGoma_Stunned(EnGoma* this, GlobalContext* globalCtx) {
    Actor_SetColorFilter(&this->actor, 0, 180, 0, 2);
    this->visualState = 2;

    if (this->actionTimer != 0) {
        SkelAnime_Update(&this->skelanime);
    }

    if (this->actor.bgCheckFlags & 1) {
        this->actor.velocity.y = 0.0f;
        Math_ApproachZeroF(&this->actor.speedXZ, 0.5f, 2.0f);
    }

    if (this->stunTimer == 0) {
        EnGoma_SetupStand(this);
    } else if (--this->stunTimer < 30) {
        if (this->stunTimer & 1) {
            this->actor.world.pos.x += 1.5f;
            this->actor.world.pos.z += 1.5f;
        } else {
            this->actor.world.pos.x -= 1.5f;
            this->actor.world.pos.z -= 1.5f;
        }
    }
}

void EnGoma_LookAtPlayer(EnGoma* this, GlobalContext* globalCtx) {
    s16 eyePitch;
    s16 eyeYaw;

    eyeYaw = Actor_WorldYawTowardActor(&this->actor, &GET_PLAYER(globalCtx)->actor) - this->actor.shape.rot.y;
    eyePitch = Actor_WorldPitchTowardActor(&this->actor, &GET_PLAYER(globalCtx)->actor) - this->actor.shape.rot.x;

    if (eyeYaw > 6000) {
        eyeYaw = 6000;
    }
    if (eyeYaw < -6000) {
        eyeYaw = -6000;
    }
    Math_ApproachS(&this->eyeYaw, eyeYaw, 3, 2000);
    Math_ApproachS(&this->eyePitch, eyePitch, 3, 2000);
}

void EnGoma_UpdateHit(EnGoma* this, GlobalContext* globalCtx) {
    static Vec3f sShieldKnockbackVel = { 0.0f, 0.0f, 20.0f };
    Player* player = GET_PLAYER(globalCtx);

    if (this->hurtTimer != 0) {
        this->hurtTimer--;
    } else {
        ColliderInfo* acHitInfo;
        u8 swordDamage;

        if ((this->colCyl1.base.atFlags & 2) && this->actionFunc == EnGoma_Jump) {
            EnGoma_SetupLand(this);
            this->actor.speedXZ = 0.0f;
            this->actor.velocity.y = 0.0f;
        }

        if ((this->colCyl2.base.acFlags & AC_HIT) && (s8)this->actor.colChkInfo.health > 0) {
            acHitInfo = this->colCyl2.info.acHitInfo;
            this->colCyl2.base.acFlags &= ~AC_HIT;

            if (this->gomaType == ENGOMA_NORMAL) {
                u32 dmgFlags = acHitInfo->toucher.dmgFlags;

                if (dmgFlags & 0x100000) {
                    if (this->actionFunc == EnGoma_Jump) {
                        EnGoma_SetupLand(this);
                        this->actor.velocity.y = 0.0f;
                        this->actor.speedXZ = -5.0f;
                    } else {
                        Matrix_RotateY(player->actor.shape.rot.y / 32768.0f * 3.1415927f, MTXMODE_NEW);
                        Matrix_MultVec3f(&sShieldKnockbackVel, &this->shieldKnockbackVel);
                        this->invincibilityTimer = 5;
                    }
                } else if (dmgFlags & 1) { // stun
                    if (this->actionFunc != EnGoma_Stunned) {
                        EnGoma_SetupStunned(this, globalCtx);
                        this->hurtTimer = 8;
                    }
                } else {
                    swordDamage = CollisionCheck_GetSwordDamage(dmgFlags);

                    if (swordDamage) {
                        EffectSsSibuki_SpawnBurst(globalCtx, &this->actor.focus.pos);
                    } else {
                        swordDamage = 1;
                    }

                    this->actor.colChkInfo.health -= swordDamage;
                    EnGoma_SetupHurt(this, globalCtx);
                    Actor_SetColorFilter(&this->actor, 0x4000, 255, 0, 5);
                    this->hurtTimer = 13;
                }
            } else {
                // die if still an egg
                if (this->actor.params <= 5) { //! BossGoma only has 3 children
                    BossGoma* parent = (BossGoma*)this->actor.parent;
                    parent->childrenGohmaState[this->actor.params] = -1;
                }

                EnGoma_SpawnHatchDebris(this, globalCtx);
                Actor_Kill(&this->actor);
            }
        }
    }
}

void EnGoma_UpdateEyeEnvColor(EnGoma* this) {
    static f32 sTargetEyeEnvColors[][3] = {
        { 255.0f, 0.0f, 50.0f },
        { 17.0f, 255.0f, 50.0f },
        { 0.0f, 170.0f, 50.0f },
    };

    Math_ApproachF(&this->eyeEnvColor[0], sTargetEyeEnvColors[0][this->visualState], 0.5f, 20.0f);
    Math_ApproachF(&this->eyeEnvColor[1], sTargetEyeEnvColors[1][this->visualState], 0.5f, 20.0f);
    Math_ApproachF(&this->eyeEnvColor[2], sTargetEyeEnvColors[2][this->visualState], 0.5f, 20.0f);
}

void EnGoma_SetFloorRot(EnGoma* this) {
    f32 nx;
    f32 ny;
    f32 nz;

    if (this->actor.floorPoly != NULL) {
        nx = COLPOLY_GET_NORMAL(this->actor.floorPoly->normal.x);
        ny = COLPOLY_GET_NORMAL(this->actor.floorPoly->normal.y);
        nz = COLPOLY_GET_NORMAL(this->actor.floorPoly->normal.z);
        Math_ApproachS(&this->slopePitch, -Math_FAtan2F(-nz * ny, 1.0f) * 10430.378f, 1, 1000);
        Math_ApproachS(&this->slopeRoll, Math_FAtan2F(-nx * ny, 1.0f) * 10430.378f, 1, 1000);
    }
}

void EnGoma_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnGoma* this = THIS;
    s32 pad;
    Player* player = GET_PLAYER(globalCtx);

    if (this->actionTimer != 0) {
        this->actionTimer--;
    }
    if (this->invincibilityTimer != 0) {
        this->invincibilityTimer--;
    }

    this->actionFunc(this, globalCtx);
    Actor_MoveForward(&this->actor);
    this->actor.world.pos.x = this->actor.world.pos.x + this->shieldKnockbackVel.x;
    this->actor.world.pos.z = this->actor.world.pos.z + this->shieldKnockbackVel.z;
    Math_ApproachZeroF(&this->shieldKnockbackVel.x, 1.0f, 3.0f);
    Math_ApproachZeroF(&this->shieldKnockbackVel.z, 1.0f, 3.0f);

    if (this->actor.params < 10) {
        this->eggTimer++;
        Math_SmoothStepToF(&this->actor.scale.x, 0.01f, 0.5f, 0.00075f, 0.000001f);
        Math_SmoothStepToF(&this->actor.scale.y, 0.01f, 0.5f, 0.00075f, 0.000001f);
        Math_SmoothStepToF(&this->actor.scale.z, 0.01f, 0.5f, 0.00075f, 0.000001f);
        EnGoma_UpdateHit(this, globalCtx);
        Actor_UpdateBgCheckInfo(globalCtx, &this->actor, 50.0f, 50.0f, 100.0f, 5);
        EnGoma_SetFloorRot(this);
        Actor_SetFocus(&this->actor, 20.0f);
        EnGoma_LookAtPlayer(this, globalCtx);
        EnGoma_UpdateEyeEnvColor(this);
        this->visualState = 1;
        if (player->swordState != 0) {
            this->colCyl2.dim.radius = 35;
            this->colCyl2.dim.height = 35;
            this->colCyl2.dim.yShift = 0;
        } else {
            this->colCyl2.dim.radius = 15;
            this->colCyl2.dim.height = 30;
            this->colCyl2.dim.yShift = 10;
        }
        if (this->invincibilityTimer == 0) {
            Collider_UpdateCylinder(&this->actor, &this->colCyl1);
            Collider_UpdateCylinder(&this->actor, &this->colCyl2);
            CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &this->colCyl1.base);
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &this->colCyl2.base);
            CollisionCheck_SetAT(globalCtx, &globalCtx->colChkCtx, &this->colCyl1.base);
        }
    }
}

s32 EnGoma_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnGoma* this = THIS;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_goma.c", 1976);
    gDPSetEnvColor(POLY_OPA_DISP++, (s16)this->eyeEnvColor[0], (s16)this->eyeEnvColor[1], (s16)this->eyeEnvColor[2],
                   255);

    if (limbIndex == GOMA_LIMB_EYE_IRIS_ROOT1) {
        rot->x += this->eyePitch;
        rot->y += this->eyeYaw;
    } else if (limbIndex == GOMA_LIMB_BODY && this->hurtTimer != 0) {
        gDPSetEnvColor(POLY_OPA_DISP++, (s16)(Rand_ZeroOne() * 255.0f), (s16)(Rand_ZeroOne() * 255.0f),
                       (s16)(Rand_ZeroOne() * 255.0f), 255);
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_goma.c", 2011);
    return 0;
}

Gfx* EnGoma_NoBackfaceCullingDlist(GraphicsContext* gfxCtx) {
    Gfx* dListHead;
    Gfx* dList;

    dListHead = dList = Graph_Alloc(gfxCtx, sizeof(Gfx) * 4);
    gDPPipeSync(dListHead++);
    gDPSetRenderMode(dListHead++, G_RM_PASS, G_RM_AA_ZB_TEX_EDGE2);
    gSPClearGeometryMode(dListHead++, G_CULL_BACK);
    gSPEndDisplayList(dListHead++);
    return dList;
}

void EnGoma_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnGoma* this = THIS;
    s32 y;
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_en_goma.c", 2040);
    func_80093D18(globalCtx->state.gfxCtx);

    switch (this->gomaType) {
        case ENGOMA_NORMAL:
            this->actor.naviEnemyId = 0x03;
            Matrix_Translate(this->actor.world.pos.x,
                             this->actor.world.pos.y + ((this->actor.shape.yOffset * this->actor.scale.y) +
                                                        globalCtx->mainCamera.skyboxOffset.y),
                             this->actor.world.pos.z, MTXMODE_NEW);
            Matrix_RotateX(this->slopePitch / 32768.0f * 3.1415927f, MTXMODE_APPLY);
            Matrix_RotateZ(this->slopeRoll / 32768.0f * 3.1415927f, MTXMODE_APPLY);
            Matrix_RotateY(this->actor.shape.rot.y / 32768.0f * 3.1415927f, MTXMODE_APPLY);
            Matrix_RotateX(this->actor.shape.rot.x / 32768.0f * 3.1415927f, MTXMODE_APPLY);
            Matrix_RotateZ(this->actor.shape.rot.z / 32768.0f * 3.1415927f, MTXMODE_APPLY);
            Matrix_Scale(this->actor.scale.x, this->actor.scale.y, this->actor.scale.z, MTXMODE_APPLY);
            SkelAnime_DrawOpa(globalCtx, this->skelanime.skeleton, this->skelanime.jointTable, EnGoma_OverrideLimbDraw,
                              NULL, this);
            break;

        case ENGOMA_EGG:
            this->actor.naviEnemyId = 0x02;
            y = (s16)(sinf((this->eggTimer * 5.0f * 3.1415f) / 180.0f) * 31.9f);
            y = (s16)(y + 31);
            gSPSegment(POLY_OPA_DISP++, 0x08, func_80094E78(globalCtx->state.gfxCtx, 0, y));
            Matrix_Push();
            Matrix_Scale(this->eggScale, 1.0f / this->eggScale, this->eggScale, MTXMODE_APPLY);
            Matrix_RotateY(this->eggSquishAngle * 0.15f, MTXMODE_APPLY);
            Matrix_RotateZ(this->eggSquishAngle * 0.1f, MTXMODE_APPLY);
            Matrix_Scale(0.95f - this->eggSquishAmount, this->eggSquishAmount + 1.05f, 0.95f - this->eggSquishAmount,
                         MTXMODE_APPLY);
            Matrix_RotateZ(-(this->eggSquishAngle * 0.1f), MTXMODE_APPLY);
            Matrix_RotateY(-(this->eggSquishAngle * 0.15f), MTXMODE_APPLY);
            Matrix_Translate(0.0f, this->eggYOffset, 0.0f, MTXMODE_APPLY);
            Matrix_RotateX(this->eggPitch, MTXMODE_APPLY);
            gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_goma.c", 2101),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_OPA_DISP++, gObjectGolEggDL);
            Matrix_Pop();
            break;

        case ENGOMA_HATCH_DEBRIS:
            gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_goma.c", 2107),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(POLY_OPA_DISP++, gBrownFragmentDL);
            break;

        case ENGOMA_BOSSLIMB:
            if (this->bossLimbDl != NULL) {
                gSPSegment(POLY_OPA_DISP++, 0x08, EnGoma_NoBackfaceCullingDlist(globalCtx->state.gfxCtx));
                gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_en_goma.c", 2114),
                          G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gSPDisplayList(POLY_OPA_DISP++, this->bossLimbDl);
            }
            break;
    }
    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_en_goma.c", 2119);
}

void EnGoma_Debris(EnGoma* this, GlobalContext* globalCtx) {
    this->actor.shape.rot.y += 2500;
    this->actor.shape.rot.x += 3500;
    if (this->actionTimer == 0) {
        Actor_Kill(&this->actor);
    }
}

void EnGoma_SpawnHatchDebris(EnGoma* this, GlobalContext* globalCtx2) {
    GlobalContext* globalCtx = globalCtx2;
    s16 i;

    if (this->actor.params < 6) {
        Audio_PlaySoundAtPosition(globalCtx, &this->actor.world.pos, 0x28, NA_SE_EN_GOMA_BJR_EGG2);
    } else {
        Audio_PlaySoundAtPosition(globalCtx, &this->actor.world.pos, 0x28, NA_SE_EN_GOMA_EGG2);
    }

    for (i = 0; i < 15; i++) {
        Actor_SpawnAsChild(&globalCtx->actorCtx, &this->actor, globalCtx, ACTOR_EN_GOMA,
                           Rand_CenteredFloat(10.0f) + this->actor.world.pos.x,
                           Rand_CenteredFloat(10.0f) + this->actor.world.pos.y + 15.0f,
                           Rand_CenteredFloat(10.0f) + this->actor.world.pos.z, 0, Rand_CenteredFloat(65535.99f), 0,
                           i + 10);
    }
}

void EnGoma_BossLimb(EnGoma* this, GlobalContext* globalCtx) {
    Vec3f vel = { 0.0f, 0.0f, 0.0f };
    Vec3f accel = { 0.0f, 1.0f, 0.0f };
    Color_RGBA8 primColor = { 255, 255, 255, 255 };
    Color_RGBA8 envColor = { 0, 100, 255, 255 };
    Vec3f pos;

    this->actor.world.pos.y -= 5.0f;
    Actor_UpdateBgCheckInfo(globalCtx, &this->actor, 50.0f, 50.0f, 100.0f, 4);
    this->actor.world.pos.y += 5.0f;

    if (this->actor.bgCheckFlags & 1) {
        this->actor.velocity.y = 0.0f;
    } else if (this->actionTimer < 250) {
        this->actor.shape.rot.y += 2000;
    }

    if (this->actionTimer == 250) {
        this->actor.gravity = -1.0f;
    }

    if (this->actionTimer < 121) {
        if (Math_SmoothStepToF(&this->actor.scale.y, 0.0f, 1.0f, 0.00075f, 0) <= 0.001f) {
            Actor_Kill(&this->actor);
        }
        this->actor.scale.x = this->actor.scale.z = this->actor.scale.y;
    }

    if (this->actionTimer % 8 == 0 && this->actionTimer != 0) {
        pos.x = Rand_CenteredFloat(20.0f) + this->actor.world.pos.x;
        pos.y = Rand_CenteredFloat(10.0f) + this->actor.world.pos.y;
        pos.z = Rand_CenteredFloat(20.0f) + this->actor.world.pos.z;
        func_8002836C(globalCtx, &pos, &vel, &accel, &primColor, &envColor, 500, 10, 10);
    }
}
