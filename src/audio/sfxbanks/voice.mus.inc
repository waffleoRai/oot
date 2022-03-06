.table_voice:
entry .voice_link_old_attack
entry .voice_link_old_attack_long
entry .voice_link_old_epona
entry .voice_link_old_ledge_grab
entry .voice_link_old_ledge_climb
entry .voice_link_old_hurt
entry .voice_link_old_frozen
entry .voice_link_old_fall_short
entry .voice_link_old_fall_long
entry .voice_link_old_low_health
entry .voice_link_old_drink_gasp
entry .voice_link_old_death
entry .voice_link_old_wallmaster
entry .voice_link_old_grabbed
entry .voice_link_old_sneeze
entry .voice_link_old_sweat
entry .voice_link_old_drink
entry .voice_link_old_idle
entry .voice_link_old_sword_swing_unused
entry .voice_link_kid_shiver
entry .voice_link_old_jump
entry .voice_link_old_cast_spell1
entry .voice_link_old_shock
entry .voice_link_old_cast_spell2
entry .voice_link_old_push_block
entry .voice_link_old_hookshot_hang
entry .voice_link_old_knockback
entry .voice_link_old_unused
entry .voice_link_old_cast_spell3
entry .voice_link_old_fall_long
entry .voice_link_old_knockback_unused
entry .voice_link_old_attack
entry .voice_link_kid_attack
entry .voice_link_kid_attack_long
entry .voice_link_old_epona
entry .voice_link_kid_ledge_grab
entry .voice_link_kid_ledge_climb
entry .voice_link_kid_hurt
entry .voice_link_kid_frozen
entry .voice_link_kid_fall_short
entry .voice_link_kid_fall_long
entry .voice_link_kid_low_health
entry .voice_link_kid_drink_gasp
entry .voice_link_kid_death
entry .voice_link_kid_wallmaster
entry .voice_link_kid_grabbed
entry .voice_link_kid_sneeze
entry .voice_link_kid_sweat
entry .voice_link_kid_drink
entry .voice_link_kid_idle
entry .voice_link_kid_sword_swing_unused
entry .voice_link_kid_shiver
entry .voice_link_kid_jump
entry .voice_link_kid_cast_spell1
entry .voice_link_kid_shock
entry .voice_link_kid_cast_spell2
entry .voice_link_kid_push_block
entry .voice_link_kid_hookshot_hang
entry .voice_link_kid_knockback
entry .voice_link_kid_unused
entry .voice_link_kid_cast_spell3
entry .voice_link_kid_fall_long
entry .voice_link_kid_cutscene_attacked
entry .voice_link_old_attack
entry .voice_navi_unused
entry .voice_navi_unused
entry .voice_navi_unused
entry .voice_navi_target
entry .voice_navi_greeting
entry .voice_navi_target
entry .voice_navi_target
entry .voice_navi_target
entry .voice_navi_target
entry .voice_navi_target
entry .voice_navi_target
entry .voice_navi_target
entry .voice_navi_target
entry .voice_navi_target
entry .voice_navi_target
entry .voice_navi_target
entry .voice_npcs
entry .voice_npcs
entry .voice_npcs
entry .voice_npcs
entry .voice_npcs
entry .voice_npcs
entry .voice_npcs
entry .voice_npcs
entry .voice_npcs
entry .voice_npcs
entry .voice_npcs
entry .voice_npcs
entry .voice_npcs
entry .voice_npcs
entry .voice_npcs
entry .voice_npcs
entry .voice_npcs
entry .voice_npcs
entry .voice_npcs
entry .voice_npcs
entry .voice_npcs
entry .voice_npcs
entry .voice_npcs
entry .voice_npcs
entry .voice_npcs
entry .voice_npcs
entry .voice_npcs
entry .voice_npcs
entry .voice_npcs
entry .voice_npcs
entry .voice_npcs
entry .voice_npcs
entry .voice_npcs
entry .voice_npcs
entry .voice_npcs
entry .voice_npcs
entry .voice_npcs
entry .voice_npcs
entry .voice_npcs
entry .voice_other_npcs
entry .voice_other_npcs
entry .voice_other_npcs
entry .voice_other_npcs
entry .voice_other_npcs
entry .voice_other_npcs
entry .voice_npcs
entry .voice_npcs
entry .voice_npcs

// Play a random voice clip, but not two equal in a row.
.play_random_voice:
chan_writeseq 0, .getrand+1
chan_writeseq 0, .random_voice_cmpmax_instr+1
chan_setval 0
chan_writeseq 0, .layer_play_voice+1  // overwrite delay = 0
chan_call .getrand
chan_ioreadvalsub 6
chan_beqzrel .random_voice_same
chan_call .getrand
chan_jumprel .random_voice_store_last
.random_voice_same:
chan_call .getrand
chan_subtract 255
chan_iowriteval 6
.random_voice_cmpmax_instr:
chan_subtract 0
chan_beqzrel .random_voice_store_last
chan_ioreadval 6
.random_voice_store_last:
// Store the last index for both channel 14 and 15
chan_iowriteval2 14, 6
chan_iowriteval2 15, 6
.play_voice_readtone_instr:
chan_readseq .addr_616D  // read tone at index. source gets overwritten by caller
chan_writeseq 64, .layer_play_voice  // overwrite "layer_note1 tone"
chan_ioreadval 6
.play_voice_readvelocity_instr:
chan_readseq .addr_6171  // read velocity (~volume) at index. source gets overwritten by caller
.play_voice_with_velocity:
chan_writeseq 0, .layer_play_voice+2  // overwrite velocity
chan_setlayer 0, .layer_play_voice

.voice_navi_unused:
chan_end

.layer_play_voice:
layer_note1 PITCH_A0, 0x0, 127
layer_end

.getrand:
chan_rand 0
chan_end

.play_dynamic_voice:
chan_iowriteval 6
chan_setval 0
chan_writeseq 0, .layer_play_voice+1  // overwrite delay = 0
chan_ioreadval 6
chan_jumprel .play_voice_readtone_instr

.play_single_voice:
chan_setval 0
chan_writeseq 0, .layer_play_voice+1  // overwrite delay = 0
chan_dynsetdyntablelarge
chan_setval 0
chan_readdyntable  // read tone from large[0]
chan_writeseq 64, .layer_play_voice  // overwrite "layer_note1 tone"
chan_setval 1
chan_readdyntable  // read velocity from large[1]
chan_jumprel .play_voice_with_velocity

// Same as play_random_voice but only supports two voice clips.
.play_alternating_voice:
chan_writeseq 0, .layer_play_voice+1  // overwrite delay = argument
chan_ioreadval 6
chan_subtract 255
chan_bitand 1
chan_iowriteval 6
chan_jumprel .play_voice_readtone_instr

.voice_link_old_attack:
chan_setvallargeaddr .addr_616D
chan_writeseqlarge .play_voice_readtone_instr+1
chan_setvallargeaddr .addr_6171
chan_writeseqlarge .play_voice_readvelocity_instr+1
chan_setval 4
chan_jumprel .play_random_voice

.addr_616D:
.byte F0_E_LINK_OLD_ATTACK_0
.byte F0_E_LINK_OLD_ATTACK_1
.byte F0_E_LINK_OLD_ATTACK_2
.byte F0_E_LINK_OLD_ATTACK_3

.addr_6171:
.byte 105
.byte 105
.byte 105
.byte 105

.voice_link_old_attack_long:
chan_setvallargeaddr .addr_6197
chan_writeseqlarge .play_voice_readtone_instr+1
chan_setvallargeaddr .addr_6199
chan_writeseqlarge .play_voice_readvelocity_instr+1
chan_rand 2
chan_jumprel .play_dynamic_voice

.chan_unused_6185:
chan_ioreadvalsub 6
chan_beqzrel .chan_618C
chan_rand 2
chan_jumprel .chan_6196
.chan_618C:
chan_rand 2
chan_subtract 255
chan_iowriteval 6
chan_subtract 2
chan_beqzrel .chan_6196
chan_ioreadval 6
.chan_6196:
chan_iowriteval 6

.addr_6197:
.byte F0_E_LINK_OLD_MAJOR_0
.byte F0_E_LINK_OLD_MAJOR_1

.addr_6199:
.byte 110
.byte 110

.voice_link_old_epona:
chan_setvallargeaddr .addr_61BD
chan_writeseqlarge .play_voice_readtone_instr+1
chan_setvallargeaddr .addr_61BF
chan_writeseqlarge .play_voice_readvelocity_instr+1
chan_rand 2
chan_jumprel .play_dynamic_voice

.chan_unused_61AB:
chan_ioreadvalsub 6
chan_beqzrel .chan_61B2
chan_rand 2
chan_jumprel .chan_61BC
.chan_61B2:
chan_rand 2
chan_subtract 255
chan_iowriteval 6
chan_subtract 2
chan_beqzrel .chan_61BC
chan_ioreadval 6
.chan_61BC:
chan_iowriteval 6

.addr_61BD:
.byte F0_E_LINK_OLD_SPUR_0
.byte F0_E_LINK_OLD_SPUR_1

.addr_61BF:
.byte 105
.byte 105

.voice_link_old_ledge_grab:
chan_setvallargeaddr .addr_61D1
chan_writeseqlarge .play_voice_readtone_instr+1
chan_setvallargeaddr .addr_61D3
chan_writeseqlarge .play_voice_readvelocity_instr+1
chan_setval 0
chan_jumprel .play_alternating_voice

.addr_61D1:
.byte F0_E_LINK_OLD_LEDGE_0
.byte F0_E_LINK_OLD_LEDGE_2

.addr_61D3:
.byte 95
.byte 105

.voice_link_old_ledge_climb:
chan_setvallargeaddr .addr_61E6
chan_writeseqlarge .play_voice_readtone_instr+1
chan_setvallargeaddr .addr_61E8
chan_writeseqlarge .play_voice_readvelocity_instr+1
chan_rand 2
chan_jump .play_dynamic_voice

.addr_61E6:
.byte F0_E_LINK_OLD_CLIMB
.byte F0_E_LINK_OLD_LEDGE_1

.addr_61E8:
.byte 72
.byte 80

.voice_link_old_hurt:
chan_setvallargeaddr .addr_61FB
chan_writeseqlarge .play_voice_readtone_instr+1
chan_setvallargeaddr .addr_61FE
chan_writeseqlarge .play_voice_readvelocity_instr+1
chan_setval 3
chan_jump .play_random_voice

.addr_61FB:
.byte F0_E_LINK_OLD_HURT_0
.byte F0_E_LINK_OLD_HURT_1
.byte F0_E_LINK_OLD_HURT_2

.addr_61FE:
.byte 117
.byte 117
.byte 117

.voice_link_old_frozen:
chan_setvallargeaddr .addr_6212
chan_writeseqlarge .play_voice_readtone_instr+1
chan_setvallargeaddr .addr_6215
chan_writeseqlarge .play_voice_readvelocity_instr+1
chan_setval 3
chan_jump .play_random_voice

.addr_6212:
.byte F0_E_LINK_OLD_HURT_3
.byte F0_E_LINK_OLD_KNOCKBACK
.byte F0_E_LINK_OLD_HURT_4

.addr_6215:
.byte 113
.byte 113
.byte 113

.voice_link_old_fall_short:
chan_setvallargeaddr .addr_6229
chan_writeseqlarge .play_voice_readtone_instr+1
chan_setvallargeaddr .addr_622B
chan_writeseqlarge .play_voice_readvelocity_instr+1
chan_rand 2
chan_jump .play_dynamic_voice

.addr_6229:
.byte F0_E_LINK_OLD_GASP_0
.byte F0_E_LINK_OLD_GASP_1

.addr_622B:
.byte 100
.byte 100

.voice_link_old_fall_long:
chan_setvallargeaddr .addr_623E
chan_writeseqlarge .play_voice_readtone_instr+1
chan_setvallargeaddr .addr_6240
chan_writeseqlarge .play_voice_readvelocity_instr+1
chan_rand 2
chan_jump .play_dynamic_voice

.addr_623E:
.byte F0_E_LINK_OLD_FALL_0
.byte F0_E_LINK_OLD_FALL_1

.addr_6240:
.byte 110
.byte 110

.voice_link_old_low_health:
chan_setvallargeaddr .addr_6253
chan_writeseqlarge .play_voice_readtone_instr+1
chan_setvallargeaddr .addr_6255
chan_writeseqlarge .play_voice_readvelocity_instr+1
chan_rand 2
chan_jump .play_dynamic_voice

.addr_6253:
.byte F0_E_LINK_OLD_PANT_0
.byte F0_E_LINK_OLD_PANT_1

.addr_6255:
.byte 90
.byte 90

.voice_link_old_drink_gasp:
chan_setlayer 0, .layer_625B
chan_end

.layer_625B:
layer_note1 PITCH_F5, 0x0, 96
layer_end

.voice_link_old_death:
chan_setlayer 0, .layer_6263
chan_end

.layer_6263:
layer_transpose 1
layer_note1 PITCH_BF1, 0x57, 100
layer_note1 PITCH_B1, 0x61, 100
layer_note1 PITCH_C2, 0x47, 100
layer_end

.voice_link_old_wallmaster:
chan_setvallargeaddr .addr_6280
chan_writeseqlarge .play_voice_readtone_instr+1
chan_setvallargeaddr .addr_6282
chan_writeseqlarge .play_voice_readvelocity_instr+1
chan_rand 2
chan_jump .play_dynamic_voice

.addr_6280:
.byte F0_E_LINK_OLD_FALL_0
.byte F0_E_LINK_OLD_FALL_1

.addr_6282:
.byte 105
.byte 105

.voice_link_old_grabbed:
chan_jump .voice_link_old_hurt

.voice_link_old_sneeze:
chan_setlayer 0, .layer_628B
chan_end

.layer_628B:
layer_transpose 1
layer_note1 PITCH_DF2, 0x7f, 100
layer_note1 PITCH_D2, 0x118, 100
layer_note1 PITCH_EF2, 0x13e, 100
layer_end

.voice_link_old_sweat:
chan_setlayer 0, .layer_629D
chan_end

.layer_629D:
layer_transpose 1
layer_note1 PITCH_E2, 0x122, 100
layer_note1 PITCH_F2, 0xa3, 100
layer_note1 PITCH_GF2, 0x35, 100
layer_end

.voice_link_old_drink:
chan_setlayer 0, .layer_62AF
chan_end

.layer_62AF:
layer_note1 PITCH_E5, 0x50, 80
layer_jumprel .layer_62AF

.voice_link_old_idle:
chan_setlayer 0, .layer_62B8
chan_end

.layer_62B8:
layer_transpose 1
layer_note1 PITCH_G2, 0xb9, 100
layer_note1 PITCH_AF2, 0x86, 100
layer_note1 PITCH_A2, 0x74, 100
layer_end

.voice_link_old_sword_swing_unused:
chan_setvallargeaddr .addr_62CC
chan_jump .play_single_voice

.addr_62CC:
.byte F0_E_LINK_OLD_ATTACK_0
.byte 100

.voice_link_old_jump:
chan_ioreadval 6
chan_subtract 255
chan_iowriteval 6
chan_bitand 1
chan_readseq .addr_62E8
chan_writeseq 64, .layer_64BF
chan_rand 2
chan_readseq .addr_62EA
chan_writeseq 0, .layer_64BF+2
chan_setlayer 0, .layer_64BF
chan_end

.addr_62E8:
.byte F0_E_LINK_OLD_JUMP
.byte F0_E_LINK_OLD_GASP_2

.addr_62EA:
.byte 80
.byte 85

.voice_link_old_cast_spell1:
chan_setvallargeaddr .addr_62F2
chan_jump .play_single_voice

.addr_62F2:
.byte F0_E_LINK_OLD_MAJOR_1
.byte 110

.voice_link_old_shock:
chan_setlayer 0, .layer_62F8
chan_end

.layer_62F8:
layer_transpose 2
layer_note1 PITCH_EF1, 0x0, 85
layer_end

.voice_link_old_cast_spell2:
chan_setvallargeaddr .addr_6304
chan_jump .play_single_voice

.addr_6304:
.byte F0_E_LINK_OLD_MAJOR_0
.byte 95

.voice_link_old_push_block:
chan_setvallargeaddr .addr_630C
chan_jump .play_single_voice

.addr_630C:
.byte F0_E_LINK_OLD_CLIMB
.byte 82

.voice_link_old_hookshot_hang:
chan_setvallargeaddr .addr_6314
chan_jump .play_single_voice

.addr_6314:
.byte F0_E_LINK_OLD_LEDGE_0
.byte 95

.voice_link_old_knockback:
chan_setvallargeaddr .addr_631C
chan_jump .play_single_voice

.addr_631C:
.byte F0_E_LINK_OLD_FALL_DMG
.byte 110

.voice_link_old_unused:
chan_setvallargeaddr .addr_6324
chan_jump .play_single_voice

.addr_6324:
.byte F0_E_LINK_OLD_LIFT
.byte 100

.voice_link_old_cast_spell3:
chan_setvallargeaddr .addr_632C
chan_jump .play_single_voice

.addr_632C:
.byte F0_E_LINK_OLD_SPELL
.byte 110

.voice_link_old_knockback_unused:
chan_setvallargeaddr .addr_6334
chan_jump .play_single_voice

.addr_6334:
.byte F0_E_LINK_OLD_KNOCKBACK
.byte 113

.voice_link_kid_attack:
chan_setvallargeaddr .addr_6347
chan_writeseqlarge .play_voice_readtone_instr+1
chan_setvallargeaddr .addr_634B
chan_writeseqlarge .play_voice_readvelocity_instr+1
chan_setval 4
chan_jump .play_random_voice

.addr_6347:
.byte F0_E_LINK_KID_ATTACK_0
.byte F0_E_LINK_KID_ATTACK_1
.byte F0_E_LINK_KID_ATTACK_2
.byte F0_E_LINK_KID_ATTACK_3

.addr_634B:
.byte 110
.byte 110
.byte 110
.byte 110

.voice_link_kid_attack_long:
chan_setvallargeaddr .addr_6372
chan_writeseqlarge .play_voice_readtone_instr+1
chan_setvallargeaddr .addr_6374
chan_writeseqlarge .play_voice_readvelocity_instr+1
chan_rand 2
chan_jump .play_dynamic_voice

.chan_unused_6360:
chan_ioreadvalsub 6
chan_beqzrel .chan_6367
chan_rand 2
chan_jumprel .chan_6371
.chan_6367:
chan_rand 2
chan_subtract 255
chan_iowriteval 6
chan_subtract 2
chan_beqzrel .chan_6371
chan_ioreadval 6
.chan_6371:
chan_iowriteval 6

.addr_6372:
.byte F0_E_LINK_KID_STRONG_0
.byte F0_E_LINK_KID_STRONG_1

.addr_6374:
.byte 110
.byte 110

.voice_link_kid_ledge_grab:
chan_ioreadval 6
chan_subtract 255
chan_iowriteval 6
chan_bitand 1
chan_readseq .addr_6396
chan_writeseq 64, .layer_6390
chan_rand 2
chan_readseq .addr_6398
chan_writeseq 0, .layer_6390+2
chan_setlayer 0, .layer_6390
chan_end

.layer_6390:
layer_note1 PITCH_A0, 0x0, 100
layer_delay 0x30
layer_end

.addr_6396:
.byte F0_E_LINK_KID_LEDGE_0
.byte F0_E_LINK_KID_LEDGE_1

.addr_6398:
.byte 100
.byte 100

.voice_link_kid_ledge_climb:
chan_setvallargeaddr .addr_63AB
chan_writeseqlarge .play_voice_readtone_instr+1
chan_setvallargeaddr .addr_63AD
chan_writeseqlarge .play_voice_readvelocity_instr+1
chan_rand 2
chan_jump .play_dynamic_voice

.addr_63AB:
.byte F0_E_LINK_KID_SIGH_0
.byte F0_E_LINK_KID_SIGH_1

.addr_63AD:
.byte 90
.byte 70

.voice_link_kid_hurt:
chan_setvallargeaddr .addr_63C0
chan_writeseqlarge .play_voice_readtone_instr+1
chan_setvallargeaddr .addr_63C3
chan_writeseqlarge .play_voice_readvelocity_instr+1
chan_setval 3
chan_jump .play_random_voice

.addr_63C0:
.byte F0_E_LINK_KID_HURT_0
.byte F0_E_LINK_KID_HURT_1
.byte F0_E_LINK_KID_HURT_2

.addr_63C3:
.byte 110
.byte 110
.byte 110

.voice_link_kid_frozen:
chan_setvallargeaddr .addr_63D7
chan_writeseqlarge .play_voice_readtone_instr+1
chan_setvallargeaddr .addr_63DA
chan_writeseqlarge .play_voice_readvelocity_instr+1
chan_setval 3
chan_jump .play_random_voice

.addr_63D7:
.byte F0_E_LINK_KID_HURT_3
.byte F0_E_LINK_KID_KNOCKBACK
.byte F0_E_LINK_KID_HURT_4

.addr_63DA:
.byte 110
.byte 110
.byte 110

.voice_link_kid_fall_short:
chan_setvallargeaddr .addr_63EE
chan_writeseqlarge .play_voice_readtone_instr+1
chan_setvallargeaddr .addr_63F0
chan_writeseqlarge .play_voice_readvelocity_instr+1
chan_rand 2
chan_jump .play_dynamic_voice

.addr_63EE:
.byte F0_E_LINK_KID_GASP_0
.byte F0_E_LINK_KID_GASP_1

.addr_63F0:
.byte 100
.byte 100

.voice_link_kid_fall_long:
chan_setvallargeaddr .addr_6403
chan_writeseqlarge .play_voice_readtone_instr+1
chan_setvallargeaddr .addr_6405
chan_writeseqlarge .play_voice_readvelocity_instr+1
chan_rand 2
chan_jump .play_dynamic_voice

.addr_6403:
.byte F0_E_LINK_KID_FALL_0
.byte F0_E_LINK_KID_FALL_1

.addr_6405:
.byte 100
.byte 100

.voice_link_kid_low_health:
chan_setvallargeaddr .addr_6418
chan_writeseqlarge .play_voice_readtone_instr+1
chan_setvallargeaddr .addr_641A
chan_writeseqlarge .play_voice_readvelocity_instr+1
chan_rand 2
chan_jump .play_dynamic_voice

.addr_6418:
.byte F0_E_LINK_KID_WHEEZE
.byte F0_E_LINK_KID_PANT

.addr_641A:
.byte 85
.byte 85

.voice_link_kid_drink_gasp:
chan_setlayer 0, .layer_6420
chan_end

.layer_6420:
layer_note1 PITCH_DF5, 0x0, 96
layer_end

.voice_link_kid_death:
chan_setlayer 0, .layer_6428
chan_end

.layer_6428:
layer_transpose 1
layer_note1 PITCH_A0, 0x62, 100
layer_note1 PITCH_BF0, 0x6a, 100
layer_note1 PITCH_B0, 0x3a, 100
layer_end

.voice_link_kid_wallmaster:
chan_setvallargeaddr .addr_6445
chan_writeseqlarge .play_voice_readtone_instr+1
chan_setvallargeaddr .addr_6447
chan_writeseqlarge .play_voice_readvelocity_instr+1
chan_rand 2
chan_jump .play_dynamic_voice

.addr_6445:
.byte F0_E_LINK_KID_FALL_0
.byte F0_E_LINK_KID_FALL_1

.addr_6447:
.byte 100
.byte 100

.voice_link_kid_grabbed:
chan_setvallargeaddr .addr_644F
chan_jump .play_single_voice

.addr_644F:
.byte F0_E_LINK_KID_DEATH_0
.byte 100

.voice_link_kid_sneeze:
chan_setlayer 0, .layer_6455
chan_end

.layer_6455:
layer_transpose 1
layer_note1 PITCH_C1, 0x10b, 50
layer_note1 PITCH_C1, 0xc5, 50
layer_note1 PITCH_D1, 0x87, 100
layer_note1 PITCH_EF1, 0x21, 100
layer_end

.voice_link_kid_sweat:
chan_setlayer 0, .layer_646B
chan_end

.layer_646B:
layer_transpose 1
layer_note1 PITCH_E1, 0xd9, 100
layer_note1 PITCH_F1, 0x62, 100
layer_note1 PITCH_GF1, 0x109, 100
layer_end

.voice_link_kid_drink:
chan_setlayer 0, .layer_647D
chan_end

.layer_647D:
layer_note1 PITCH_C5, 0x50, 80
layer_jumprel .layer_647D

.voice_link_kid_idle:
chan_setlayer 0, .layer_6486
chan_end

.layer_6486:
layer_transpose 1
layer_note1 PITCH_G1, 0x41, 100
layer_note1 PITCH_AF1, 0x10a, 100
layer_note1 PITCH_A1, 0x53, 100
layer_end

.voice_link_kid_sword_swing_unused:
chan_setvallargeaddr .addr_6499
chan_jump .play_single_voice

.addr_6499:
.byte F0_E_LINK_KID_ATTACK_0
.byte 100

.voice_link_kid_shiver:
chan_setlayer 0, .layer_649F
chan_end

.layer_649F:
layer_transpose 1
layer_note1 PITCH_C1, 0x0, 50
layer_end

.voice_link_kid_jump:
chan_ioreadval 6
chan_subtract 255
chan_iowriteval 6
chan_bitand 1
chan_readseq .addr_64C5
chan_writeseq 64, .layer_64BF
chan_rand 2
chan_readseq .addr_64C7
chan_writeseq 0, .layer_64BF+2
chan_setlayer 0, .layer_64BF
chan_end

.layer_64BF:
layer_note1 PITCH_A0, 0x0, 100
layer_delay 0x30
layer_end

.addr_64C5:
.byte F0_E_LINK_KID_JUMP_0
.byte F0_E_LINK_OLD_JUMP_1

.addr_64C7:
.byte 80
.byte 80

.voice_link_kid_cast_spell1:
chan_setvallargeaddr .addr_64CF
chan_jump .play_single_voice

.addr_64CF:
.byte F0_E_LINK_KID_STRONG_1
.byte 110

.voice_link_kid_shock:
chan_setlayer 0, .layer_64D5
chan_end

.layer_64D5:
layer_transpose 2
layer_note1 PITCH_E1, 0x0, 85
layer_end

.voice_link_kid_cast_spell2:
chan_setvallargeaddr .addr_64E1
chan_jump .play_single_voice

.addr_64E1:
.byte F0_E_LINK_KID_STRONG_0
.byte 95

.voice_link_kid_push_block:
chan_setvallargeaddr .addr_64E9
chan_jump .play_single_voice

.addr_64E9:
.byte F0_E_LINK_KID_SIGH_0
.byte 90

.voice_link_kid_hookshot_hang:
chan_setvallargeaddr .addr_64F1
chan_jump .play_single_voice

.addr_64F1:
.byte F0_E_LINK_KID_LEDGE_0
.byte 100

.voice_link_kid_knockback:
chan_setvallargeaddr .addr_64F9
chan_jump .play_single_voice

.addr_64F9:
.byte F0_E_LINK_KID_FALL_DMG
.byte 115

.voice_link_kid_unused:
chan_setvallargeaddr .addr_6501
chan_jump .play_single_voice

.addr_6501:
.byte F0_E_LINK_KID_CHARGE
.byte 100

.voice_link_kid_cast_spell3:
chan_setvallargeaddr .addr_6509
chan_jump .play_single_voice

.addr_6509:
.byte F0_E_LINK_KID_SPELL
.byte 110

.voice_link_kid_cutscene_attacked:
chan_setvallargeaddr .addr_6511
chan_jump .play_single_voice

.addr_6511:
.byte F0_E_LINK_KID_FALL_1
.byte 100

.voice_navi_greeting:
chan_setval 32
chan_iowriteval 1
chan_setlayer 0, .layer_651A
chan_end

.layer_651A:
layer_transpose 2
layer_note1 PITCH_DF1, 0x0, 100
layer_end

.voice_npcs:
chan_ioreadval 4
chan_subtract 80
chan_writeseq 25, .layer_6536  // set semitone = sound id - 80 + 25
chan_readseq .addr_653B
chan_writeseq 0, .layer_6536+2
chan_setlayer 0, .layer_6534
chan_setpanmix 96
chan_end

.layer_6534:
layer_transpose 1
.layer_6536:
layer_note0 33, 0x0, 100, 0
layer_end

.addr_653B:
.byte 100
.byte 100
.byte 100
.byte 100
.byte 100
.byte 100
.byte 100
.byte 100
.byte 110
.byte 100
.byte 100
.byte 100
.byte 100
.byte 100
.byte 100
.byte 100
.byte 100
.byte 100
.byte 100
.byte 100
.byte 100
.byte 100
.byte 100
.byte 100
.byte 100
.byte 100
.byte 100
.byte 100
.byte 100
.byte 100
.byte 100
.byte 100
.byte 100
.byte 100
.byte 100
.byte 100
.byte 100
.byte 100
.byte 110

.voice_other_npcs:
chan_ioreadval 4
chan_subtract 119
chan_writeseq 0, .layer_6576  // set semitone = sound id - 119
chan_readseq .addr_657B
chan_writeseq 0, .layer_6576+2
chan_setlayer 0, .layer_6574
chan_end

.layer_6574:
layer_transpose 2
.layer_6576:
layer_note0 0, 0x0, 100, 0
layer_end

.addr_657B:
.byte 100
.byte 100
.byte 100
.byte 100
.byte 100
.byte 100

.voice_navi_target:
chan_setval 32
chan_iowriteval 1
chan_setlayer 1, .layer_6598
chan_setvallargeaddr .addr_65A7
chan_writeseqlarge .play_voice_readtone_instr+1
chan_setvallargeaddr .addr_65AA
chan_writeseqlarge .play_voice_readvelocity_instr+1
chan_setval 3
chan_jump .play_random_voice

.layer_6598:
layer_setinstr F0_I_FAIRY_MAGIC
layer_setenvelope .envelope_66B8, 251
layer_enablelegato
layer_portamento 0x81, 51, 255
layer_note1 PITCH_F5, 0x30, 65
layer_end

.addr_65A7:
.byte F0_E_NAVI_WATCH_OUT
.byte F0_E_NAVI_LOOK
.byte F0_E_NAVI_HEY

.addr_65AA:
.byte 100
.byte 95
.byte 105

.balign 16

.filter_voice0:
filter 0, 0, 0, 0, 0, 0, 0, 0

.filter_voice1:
filter 0, 0, 0, 0, 0, 0, 0, 0