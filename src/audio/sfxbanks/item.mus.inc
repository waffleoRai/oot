.table_item:
entry .item_map_select_cursor
entry .item_sword_swing
entry .item_sword_sheathe
entry .item_sword_draw
entry .item_arrow_shoot
entry .item_boomerang_throw
entry .item_shield_strike
entry .item_bow_draw
entry .item_shield_blade_bounce
entry .item_arrow_strike
entry .item_hammer_strike
entry .item_hookshot_extend
entry .item_mirror_fire
entry .item_bomb_fuse
entry .item_bomb_explode
entry .item_bomb_defuse
entry .item_boomerang_fly
entry .item_sword_strike
entry .item_hammer_swing
entry .item_hookshot_strike
entry .item_arrow_hit_enemy
entry .item_arrow_hit_object
entry .item_unused1
entry .item_unused2
entry .item_fishing_rod
entry .env_bomb_rebound
entry .item_sword_strike_wall
entry .item_sword_strike_bwall
entry .item_sword_strike_stone
entry .item_stick_break
entry .item_whip_epona
entry .item_shield
entry .item_slingshot_fly
entry .item_slingshot_draw
entry .item_sword_charge
entry .item_sword_spin
entry .item_sword_strike_unused
entry .item_slingshot_reflect
entry .item_shield_sheathe
entry .item_hookshot_ready
entry .item_hookshot_unused
entry .item_hookshot_strike_object
entry .item_sword_reflect
entry .item_deku_nut_strike
entry .item_jabu_struck
entry .item_sword_unused
entry .item_sword_spin_small
entry .item_sword_spin_large
entry .item_bow_empty
entry .item_bombchu_fuse
entry .item_shield_charge_1
entry .item_shield_charge_2
entry .item_shield_charge_3
entry .item_slingshot_empty
entry .item_sword_unused2
entry .item_sword_strike_wood
entry .item_shield_unused
entry .item_arrow_magic_fly
entry .item_arrow_fire_strike
entry .item_arrow_ice_strike
entry .item_arrow_light_strike
entry .item_reel_slow
entry .item_reel_fast
entry .item_bow_draw
entry .item_goddess_zoom
entry .item_goddess_launch
entry .item_goddess_boom
entry .item_explosion_unused
entry .env_horse_neigh
entry .item_explosion_unused
entry .item_explosive_flames
entry .item_scarecrow_jump
entry .item_flame_wall
entry .env_triforce_glow
entry .item_fishing_rod_strike
entry .item_explosion_unused2
entry .item_sword_break
entry .item_unused4
entry .item_sword_swing_magic
entry .item_bomb_defuse

.item_map_select_cursor:
chan_setinstr F0_I_SWORD_STRIKE
chan_setlayer 0, .layer_F89
chan_end

.layer_F89:
layer_note1 PITCH_F4, 0x18, 110
layer_end

.item_sword_swing:
chan_setlayer 0, .layer_F91
chan_end

.layer_F91:
layer_setinstr F0_I_SWORD_MISS
layer_portamento 0x81, 29, 255
layer_note1 PITCH_D2, 0x2a, 100
layer_end

.item_sword_sheathe:
chan_setinstr F0_I_SWORD_SHEATHE
chan_setlayer 0, .layer_FA1
chan_end

.layer_FA1:
layer_note1 PITCH_A3, 0x30, 100
layer_end

.item_sword_draw:
chan_setinstr F0_I_SWORD_DRAW
chan_setlayer 0, .layer_FAB
chan_end

.layer_FAB:
layer_note1 PITCH_A3, 0x30, 100
layer_end

.item_arrow_shoot:
chan_setlayer 0, .layer_FB3
chan_end

.layer_FB3:
layer_setinstr F0_I_SWORD_SWING
layer_note1 PITCH_A3, 0x30, 100
layer_end

.item_boomerang_throw:
chan_setinstr F0_I_WHISTLE_AIR
chan_setlayer 0, .layer_FBF
chan_end

.layer_FBF:
layer_enablelegato
layer_portamento 0x85, 0, 255
layer_note1 PITCH_A3, 0xc, 80
layer_note1 PITCH_F2, 0x19, 80
layer_end

.item_shield_strike:
chan_setinstr F0_I_SWORD_HIT_SHIELD
chan_setenvelope .envelope_664C
chan_setlayer 0, .layer_FD4
chan_end

.layer_FD4:
layer_note1 PITCH_B3, 0x6, 82
layer_note1 PITCH_E3, 0x0, 82
layer_end

.item_bow_draw:
chan_setinstr F0_I_BOW
chan_setlayer 0, .layer_FE1
chan_end

.layer_FE1:
layer_portamento 0x81, 43, 255
layer_note1 PITCH_GF4, 0xe, 110
layer_end

.item_shield_blade_bounce:
chan_setinstr F0_I_SWORD_HIT_SHIELD
chan_setenvelope .envelope_65E8
chan_setlayer 0, .layer_FF5
chan_setlayer 1, .layer_FF9
chan_end

.layer_FF5:
layer_note1 PITCH_C4, 0x24, 105
layer_end

.layer_FF9:
layer_setinstr F0_I_SWORD_STRIKE
layer_transpose 48
layer_note1 PITCH_DF3, 0x0, 100
layer_end

.item_arrow_strike:
chan_setinstr F0_I_ARROW_WOOD
chan_setlayer 0, .layer_1007
chan_end

.layer_1007:
layer_note1 PITCH_C4, 0x45, 100
layer_end

.item_hammer_strike:
chan_sethilogain 20
chan_setlayer 0, .layer_1011
chan_end

.layer_1011:
layer_setinstr F0_I_SWORD_STRIKE
layer_setreleaserate 236
layer_note1 PITCH_DF1, 0x6, 76
layer_setinstr F0_I_SLAM_HEAVY
layer_setenvelope .envelope_65E8, 240
layer_note1 PITCH_B3, 0x24, 110
layer_end

.item_hookshot_extend:
chan_setlayer 0, .layer_1033
chan_setlayer 1, .layer_1029
chan_end

.layer_1029:
layer_setinstr F0_I_EXPLOSION_0
layer_setenvelope .envelope_664C, 255
layer_note1 PITCH_B5, 0xc, 108
layer_end

.layer_1033:
layer_setinstr F0_I_CHAIN
.layer_1035:
layer_note1 PITCH_B4, 0x7, 93
layer_jumprel .layer_1035

.item_mirror_fire:
chan_sethilogain 15
chan_setlayer 0, .layer_1045
chan_setlayer 1, .layer_105C
chan_end

.layer_1043:
layer_transpose -9

.layer_1045:
layer_setinstr F0_I_SWORD_HIT_SHIELD
layer_setenvelope .envelope_65E8, 251
layer_portamento 0x81, 16, 100
layer_note1 PITCH_F4, 0x6, 102
layer_portamento 0x81, 20, 100
layer_note1 PITCH_E5, 0x28, 110
layer_end

.layer_105A:
layer_transpose -9

.layer_105C:
layer_setinstr F0_I_SYNTH_BUZZ
layer_setenvelope .envelope_6610, 251
layer_portamento 0x81, 32, 208
layer_note1 PITCH_B5, 0x28, 80
layer_end

.item_bomb_fuse:
chan_setinstr F0_I_BOMB
chan_setlayer 0, .layer_1070
chan_end

.layer_1070:
layer_enablelegato
.layer_1071:
layer_note1 PITCH_A3, 0x30, 80
layer_jumprel .layer_1071

.item_bomb_explode:
chan_setlayer 0, .layer_107A
chan_end

.layer_107A:
layer_setinstr F0_I_EXPLOSION_0
layer_setenvelope .envelope_66D0, 225
layer_note1 PITCH_F4, 0xa0, 110
layer_end

.item_bomb_defuse:
chan_setlayer 0, .layer_1089
chan_end

.layer_1089:
layer_setinstr F0_I_BOMB
layer_setenvelope .envelope_65E8, 245
layer_portamento 0x85, 34, 255
layer_note1 PITCH_E4, 0x8, 105
layer_note1 PITCH_F3, 0x18, 105
layer_end

.layer_unused_109A:
layer_portamento 0x81, 32, 255
layer_note1 PITCH_F2, 0x1e, 105
layer_end

.item_boomerang_fly:
chan_setinstr F0_I_SWORD_SWING
chan_setenvelope .envelope_6688
chan_setlayer 0, .layer_10AB
chan_end

.layer_10AB:
layer_enablelegato
layer_portamento 0x85, 8, 255
layer_note1 PITCH_F2, 0x18, 90
layer_note1 PITCH_B3, 0xe, 90
layer_disablelegato
layer_enablelegato
layer_portamento 0x85, 10, 255
layer_note1 PITCH_G2, 0x14, 90
layer_note1 PITCH_C4, 0xc, 90
layer_disablelegato
.layer_10C3:
layer_enablelegato
layer_portamento 0x85, 12, 255
layer_note1 PITCH_A2, 0x11, 90
layer_note1 PITCH_D4, 0xa, 90
layer_disablelegato
layer_jump .layer_10C3

.item_sword_strike:
chan_setinstr F0_I_DIRT
chan_setenvelope .envelope_66C8
chan_setlayer 0, .layer_10DB
chan_end

.layer_10DB:
layer_note1 PITCH_GF2, 0x3, 110
layer_portamento 0x2, 11, 0xc
layer_note1 PITCH_AF3, 0x6, 110
layer_end

.item_hammer_swing:
chan_setlayer 0, .layer_10EA
chan_end

.layer_10EA:
layer_setinstr F0_I_SWORD_MISS
layer_portamento 0x81, 19, 255
layer_note1 PITCH_E1, 0x60, 100
layer_end

.item_hookshot_strike:
chan_setlayer 0, .layer_10F8
chan_end

.layer_10F8:
layer_call .layer_fn_1103
layer_portamento 0x1, 34, 0x18
layer_note1 PITCH_D4, 0x48, 100
layer_end

.layer_fn_1103:
layer_setinstr F0_I_SWORD_STRIKE
layer_transpose -18
layer_note1 PITCH_E3, 0x9, 100
layer_end

.item_arrow_hit_enemy:
chan_setinstr F0_I_SWORD_SWING
chan_setlayer 0, .layer_1111
chan_end

.layer_1111:
layer_portamento 0x81, 38, 127
layer_note1 PITCH_E1, 0x14, 105
layer_portamento 0x81, 3, 127
layer_note1 PITCH_F3, 0xa, 105
layer_end

.item_arrow_hit_object:
chan_jump .item_arrow_strike

.item_unused1:
chan_setlayer 0, .layer_112A
chan_setlayer 1, .layer_113A
chan_end

.layer_112A:
layer_transpose -2
layer_setinstr F0_I_SWORD_SWING
layer_enablelegato
layer_portamento 0x85, 3, 255
layer_note1 PITCH_C2, 0x9, 90
layer_note1 PITCH_BF3, 0x12, 90
layer_end

.layer_113A:
layer_transpose -1
layer_setinstr F0_I_EGG_BREAK
layer_portamento 0x81, 34, 255
layer_note1 PITCH_C3, 0x1b, 80
layer_end

.item_unused2:
chan_setlayer 0, .layer_114D
chan_setlayer 1, .layer_115D
chan_end

.layer_114D:
layer_transpose 4
layer_setinstr F0_I_SWORD_SWING
layer_enablelegato
layer_portamento 0x85, 3, 255
layer_note1 PITCH_F2, 0xc, 103
layer_note1 PITCH_F4, 0x18, 103
layer_end

.layer_115D:
layer_transpose 4
layer_setinstr F0_I_EGG_BREAK
layer_portamento 0x81, 34, 255
layer_note1 PITCH_C3, 0x28, 87
layer_end

.item_fishing_rod:
chan_setlayer 0, .layer_1170
chan_setlayer 1, .layer_117C
chan_end

.layer_1170:
layer_setinstr F0_I_SWORD_MISS
layer_portamento 0x81, 32, 255
layer_note1 PITCH_F2, 0x24, 105
layer_delay 0x68
layer_end

.layer_117C:
layer_setinstr F0_I_WHOOSH
layer_portamento 0x81, 46, 44
layer_note1 PITCH_G3, 0x8c, 75
layer_end

.item_sword_strike_wall:
chan_setinstr F0_I_SWORD_STRIKE
chan_setenvelope .envelope_6674
chan_setlayer 0, .layer_1196
.chan_118F:
chan_setvibratorate 127
chan_setvibratoextentlinear 0, 128, 56
chan_end

.layer_1196:
layer_note1 PITCH_E2, 0x60, 110
layer_end

.item_sword_strike_bwall:
chan_setinstr F0_I_SWORD_STRIKE
chan_setlayer 0, .layer_11A3
chan_setlayer 1, .layer_11AF
chan_end

.layer_11A3:
layer_setenvelope .envelope_6674, 251
layer_portamento 0x1, 27, 0x1e
layer_note1 PITCH_A3, 0x60, 100
layer_end

.layer_11AF:
layer_note1 PITCH_C3, 0x60, 96
layer_end

.item_sword_strike_stone:
chan_setlayer 0, .layer_11B7
chan_end

.layer_11B7:
layer_setinstr F0_I_SWORD_STRIKE
layer_setenvelope .envelope_6610, 251
layer_note1 PITCH_A1, 0x8, 110
layer_note1 PITCH_F1, 0x30, 110
layer_end

.item_stick_break:
chan_setinstr F0_I_CRUNCH
chan_setenvelope .envelope_6660
chan_setlayer 0, .layer_11CD
chan_end

.layer_11CD:
layer_note0 PITCH_AF2, 0x7, 93, 127
layer_note1 PITCH_G3, 0x5, 90
layer_end

.item_whip_epona:
chan_setlayer 0, .layer_11D9
chan_end

.layer_11D9:
layer_setinstr F0_I_SWORD_SWING
layer_note1 PITCH_A3, 0x8, 105
layer_setinstr F0_I_WHIP_CORK
layer_setenvelope .envelope_6624, 255
layer_note1 PITCH_GF3, 0x16, 87
layer_end

.item_shield:
chan_setlayer 0, .layer_11EF
chan_setlayer 1, .layer_11F5
chan_end

.layer_11EF:
layer_setinstr F0_I_SWORD_SHEATHE
layer_note1 PITCH_F3, 0x12, 110
layer_end

.layer_11F5:
layer_setinstr F0_I_SWORD_STRIKE
layer_transpose 48
layer_setenvelope .envelope_6720, 251
layer_note1 PITCH_C3, 0xa, 75
layer_note0 PITCH_E3, 0x4, 75, 127
layer_note1 PITCH_E3, 0x4, 75
layer_end

.item_slingshot_fly:
chan_setinstr F0_I_SWORD_SWING
chan_setlayer 0, .layer_120E
chan_end

.layer_120E:
layer_portamento 0x81, 48, 255
layer_note1 PITCH_A0, 0x12, 100
layer_end

.item_slingshot_draw:
chan_setinstr F0_I_BOW
chan_setlayer 0, .layer_121C
chan_end

.layer_121C:
layer_portamento 0x81, 39, 127
layer_note1 PITCH_B4, 0x7, 110
layer_end

.item_sword_charge:
chan_setval 24
chan_iowriteval 1
chan_setlayer 0, .layer_124B
chan_setlayer 1, .layer_1234
chan_setvibratorate 127
chan_setvibratoextentlinear 0, 160, 9
chan_end

.layer_1234:
layer_setinstr INSTR_WV_8PULSE
layer_portamento 0x81, 3, 255
layer_note1 PITCH_G4, 0x64, 30
layer_portamento 0x81, 15, 255
layer_note1 PITCH_G5, 0x64, 30
layer_enablelegato
.layer_1245:
layer_note1 PITCH_G5, 0xc8, 30
layer_jumprel .layer_1245

.layer_124B:
layer_setinstr F0_I_SYNTH_BUZZ
layer_enablelegato
layer_transpose 9
layer_portamento 0x81, 3, 255
.layer_1254:
layer_note1 PITCH_G5, 0xc8, 50
layer_jumprel .layer_1254

.item_sword_spin:
chan_setlayer 0, .layer_1266
chan_setlayer 1, .layer_1264
chan_setlayer 2, .layer_1170
chan_end

.layer_1264:
layer_transpose -4

.layer_1266:
layer_setinstr F0_I_WHOOSH
layer_portamento 0x81, 51, 44
layer_note1 PITCH_F3, 0x8c, 90
layer_end

.item_sword_strike_unused:
chan_setinstr F0_I_DIRT
chan_setenvelope .envelope_66C8
chan_setlayer 0, .layer_127D
chan_setlayer 1, .layer_113A
chan_end

.layer_127D:
layer_note1 PITCH_A2, 0x3, 110
layer_portamento 0x2, 14, 0xc
layer_note1 PITCH_B3, 0x6, 110
layer_delay 0x7
layer_end

.item_slingshot_reflect:
chan_setlayer 0, .layer_128E
chan_end

.layer_128E:
layer_setinstr F0_I_SWORD_STRIKE
layer_transpose 48
layer_note0 PITCH_A2, 0x3, 100, 127
layer_setreleaserate 251
layer_portamento 0x81, 15, 48
layer_note1 PITCH_DF3, 0x24, 100
layer_end

.item_shield_sheathe:
chan_setlayer 0, .layer_12A7
chan_setlayer 1, .layer_12AD
chan_end

.layer_12A7:
layer_setinstr F0_I_SWORD_SHEATHE
layer_note1 PITCH_A3, 0x12, 110
layer_end

.layer_12AD:
layer_setinstr F0_I_SWORD_STRIKE
layer_transpose 48
layer_setenvelope .envelope_6720, 251
layer_note1 PITCH_F3, 0xa, 75
layer_note0 PITCH_E3, 0x4, 75, 127
layer_note1 PITCH_E2, 0x4, 75
layer_end

.item_hookshot_ready:
chan_setlayer 0, .layer_12C7
chan_setlayer 1, .layer_12CD
chan_end

.layer_12C7:
layer_setinstr F0_I_SWORD_SHEATHE
layer_note1 PITCH_EF4, 0x10, 105
layer_end

.layer_12CD:
layer_setinstr F0_I_SWORD_STRIKE
layer_setenvelope .envelope_664C, 251
layer_note1 PITCH_AF3, 0x4, 86
layer_note1 PITCH_A2, 0x4, 64
layer_end

.item_hookshot_unused:
chan_setlayer 0, .layer_12E7
chan_setlayer 1, .layer_12E1
chan_end

.layer_12E1:
layer_setinstr F0_I_SWORD_SHEATHE
layer_note1 PITCH_A2, 0x28, 105
layer_end

.layer_12E7:
layer_setinstr F0_I_CHAIN
layer_setreleaserate 238
layer_note1 PITCH_D5, 0x8, 86
layer_setinstr 26
layer_note1 PITCH_GF4, 0x18, 100
layer_end

.item_hookshot_strike_object:
chan_setlayer 0, .layer_12FB
chan_setlayer 1, .layer_1309
chan_end

.layer_12FB:
layer_setinstr F0_I_EXPLOSION_0
layer_setenvelope .envelope_6624, 251
layer_portamento 0x81, 50, 144
layer_note1 PITCH_B2, 0x20, 110
layer_end

.layer_1309:
layer_setinstr F0_I_SWORD_STRIKE
layer_setenvelope .envelope_664C, 241
layer_note1 PITCH_AF2, 0x4, 64
layer_note1 PITCH_A3, 0xc, 56
layer_end

.item_sword_reflect:
chan_setval 24
chan_iowriteval 1
chan_setlayer 0, .layer_1320
chan_setlayer 1, .layer_117C
chan_end

.layer_1320:
layer_setinstr F0_I_SYNTH_BUZZ
layer_enablelegato
layer_transpose 12
layer_portamento 0x81, 56, 127
layer_note1 PITCH_F4, 0x24, 80
layer_end

.item_deku_nut_strike:
chan_setlayer 0, .layer_1334
chan_setlayer 1, .layer_1344
chan_end

.layer_1334:
layer_setinstr F0_I_SWORD_STRIKE
layer_transpose 48
layer_setenvelope .envelope_66D0, 232
layer_portamento 0x81, 19, 72
layer_note1 PITCH_GF2, 0x4, 83
layer_end

.layer_1344:
layer_setinstr F0_I_WHIP_CORK
layer_setreleaserate 225
layer_portamento 0x81, 45, 200
layer_note1 PITCH_DF3, 0x4, 110
layer_end

.item_jabu_struck:
chan_setval 32
chan_iowriteval 1
chan_setlayer 0, .layer_137F
chan_setlayer 1, .layer_1373
chan_setlayer 2, .layer_1361
.chan_135C:
chan_setvibratorate 100
chan_setvibratoextent 84
chan_end

.layer_1361:
layer_enablelegato
layer_setinstr F0_I_OCARINA_0
layer_setenvelope .envelope_6674, 251
layer_portamento 0x85, 11, 255
layer_note1 PITCH_AF2, 0x24, 60
layer_note1 PITCH_AF1, 0x24, 60
layer_end

.layer_1373:
layer_setinstr F0_I_EGG_BREAK
layer_portamento 0x82, 15, 255
layer_note1 PITCH_C3, 0x3e, 105
layer_end

.layer_137D:
layer_transpose -6

.layer_137F:
layer_delay 0x1
layer_setinstr F0_I_ROAR_BARK
layer_setenvelope .envelope_65D8, 251
layer_portamento 0x81, 20, 255
layer_note1 PITCH_AF2, 0x8, 85
layer_portamento 0x81, 27, 255
layer_note1 PITCH_C2, 0x60, 85
layer_end

.item_sword_unused:
chan_setinstr F0_I_SWORD_DRAW
chan_setlayer 0, .layer_139C
chan_end

.layer_139C:
layer_portamento 0x83, 32, 127
layer_note1 PITCH_G3, 0x8, 100
layer_note1 PITCH_EF4, 0x18, 100
layer_end

.item_sword_spin_small:
chan_setlayer 0, .layer_13C5
chan_setlayer 1, .layer_13B1
chan_setlayer 2, .layer_1170
chan_end

.layer_13B1:
layer_transpose 17
.layer_13B3:
layer_setinstr F0_I_SYNTH_BUZZ
layer_setenvelope .envelope_6638, 251
layer_enablelegato
layer_portamento 0x85, 44, 255
layer_note1 PITCH_F5, 0x10, 68
layer_note1 PITCH_D1, 0x2c, 68
layer_end

.layer_13C5:
layer_transpose -2
layer_jump .layer_1266

.item_sword_spin_large:
chan_setlayer 0, .layer_1266
chan_setlayer 1, .layer_13D4
chan_setlayer 2, .layer_13D8
chan_end

.layer_13D4:
layer_transpose 20
layer_jumprel .layer_13B3

.layer_13D8:
layer_setinstr F0_I_FLAME_THUNDER
layer_setreleaserate 221
layer_enablelegato
layer_portamento 0x85, 28, 255
layer_note1 PITCH_DF4, 0x10, 74
layer_note1 PITCH_A3, 0x44, 74
layer_end

.item_bow_empty:
chan_sethilogain 22
chan_setlayer 0, .layer_13EE
chan_end

.layer_13EE:
layer_setinstr F0_I_BOW
layer_setenvelope .envelope_65D8, 251
layer_transpose 48
layer_portamento 0x81, 43, 127
layer_note1 PITCH_AF4, 0x60, 95
layer_end

.item_bombchu_fuse:
chan_setlayer 0, .layer_1402
chan_end

.layer_1402:
layer_setinstr F0_I_BOMB
layer_transpose 48
layer_enablelegato
layer_portamento 0x1, 36, 0x38
.layer_140B:
layer_note1 PITCH_E4, 0x7d00, 80
layer_jumprel .layer_140B

.item_shield_charge_1:
chan_setval 0
chan_iowriteval 6
.chan_1414:
chan_readseq .addr_142D
chan_writeseq 0, .layer_fn_145A+1
chan_ioreadval 6
chan_readseq .addr_1431
chan_writeseq 0, .layer_1455+1
chan_setval 24
chan_iowriteval 1
chan_setlayer 0, .layer_1448
chan_setlayer 1, .layer_1435
chan_end

.addr_142D:
.byte 0x0
.byte 0x4
.byte 0x8
.byte 0x0

.addr_1431:
.byte 0x60
.byte 0x30
.byte 0x18
.byte 0x60

.layer_1435:
layer_call .layer_fn_145A

.layer_1438:
layer_setinstr F0_I_SYNTH
layer_enablelegato
layer_portamento 0x85, 24, 255
layer_note1 PITCH_C2, 0x6, 90
layer_note1 PITCH_B4, 0x50, 90
layer_delay 0x21
layer_end

.layer_1448:
layer_call .layer_fn_145A
layer_setinstr F0_I_SYNTH
layer_setenvelope .envelope_66C8, 251
.layer_1451:
layer_portamento 0x81, 3, 255
.layer_1455:
layer_note1 PITCH_A2, 0x60, 88
layer_jumprel .layer_1451

.layer_fn_145A:
layer_transpose 0
layer_end

.item_shield_charge_2:
chan_setval 1
chan_iowriteval 6
chan_jumprel .chan_1414

.item_shield_charge_3:
chan_setval 2
chan_iowriteval 6
chan_jumprel .chan_1414

.item_slingshot_empty:
chan_setinstr F0_I_BOW
chan_setenvelope .envelope_67BC
chan_sethilogain 8
chan_setlayer 0, .layer_1472
chan_end

.layer_1472:
layer_transpose 48
layer_portamento 0x81, 48, 127
layer_note1 PITCH_DF5, 0x30, 105
layer_end

.item_sword_unused2:
chan_setlayer 0, .layer_1483
chan_setlayer 1, .layer_148D
chan_end

.layer_1483:
layer_setinstr F0_I_EXPLOSION_0
layer_portamento 0x81, 48, 144
layer_note1 PITCH_F2, 0xe, 96
layer_end

.layer_148D:
layer_setinstr F0_I_SWORD_STRIKE
layer_note1 PITCH_BF2, 0xe, 72
layer_end

.item_sword_strike_wood:
chan_setlayer 0, .layer_149A
chan_setlayer 1, .layer_14A4
chan_end

.layer_149A:
layer_setinstr F0_I_STICK_ATTACK
layer_setenvelope .envelope_65E8, 244
layer_note1 PITCH_GF4, 0x8, 110
layer_end

.layer_14A4:
layer_setinstr F0_I_STEP_WOOD
layer_delay 0x3
layer_setenvelope .envelope_65E8, 244
layer_note1 PITCH_GF2, 0x5, 110
layer_end

.item_shield_unused:
chan_sethilogain 15
chan_setlayer 0, .layer_1043
chan_setlayer 1, .layer_105A
chan_end

.item_arrow_magic_fly:
chan_setlayer 0, .layer_14C0
chan_setlayer 1, .layer_FB3
chan_end

.layer_14C0:
layer_setinstr F0_I_WHOOSH
layer_portamento 0x81, 15, 40
layer_note1 PITCH_F4, 0x40, 80
layer_end

.item_arrow_fire_strike:
chan_setlayer 0, .layer_14D6
.chan_14CD:
chan_setlayer 1, .layer_14E0
chan_setlayer 2, .layer_15B1
chan_sethilogain 20
chan_end

.layer_14D6:
layer_setinstr F0_I_WOOSH_LOW
layer_setenvelope .envelope_6688, 200
layer_note1 PITCH_C3, 0x44, 100
layer_end

.layer_14E0:
layer_transpose 48
layer_jump .layer_2A06

.item_arrow_ice_strike:
chan_setlayer 0, .layer_14EA
chan_jumprel .chan_14CD

.layer_14EA:
layer_setinstr F0_I_WARP
layer_transpose 10
layer_setenvelope .envelope_6688, 200
layer_note1 PITCH_C5, 0x44, 100
layer_end

.item_arrow_light_strike:
chan_setlayer 0, .layer_14FB
chan_jumprel .chan_14CD

.layer_14FB:
layer_setinstr F0_I_FAIRY
layer_setenvelope .envelope_667C, 200
layer_note1 PITCH_A4, 0x44, 54
layer_end

.item_reel_slow:
chan_setinstr F0_I_BOW
chan_setlayer 0, .layer_150B
chan_end

.layer_150B:
layer_note1 PITCH_F4, 0x6, 102
layer_jumprel .layer_150B

.item_reel_fast:
chan_setinstr F0_I_BOW
chan_setlayer 0, .layer_1516
chan_end

.layer_1516:
layer_note1 PITCH_A4, 0x3, 102
layer_jumprel .layer_1516

.item_goddess_zoom:
chan_call .chan_fn_2823
chan_setlayer 0, .layer_1528
chan_setlayer 1, .layer_1532
chan_setlayer 2, .layer_153C
chan_end

.layer_1528:
layer_setinstr F0_I_SHIMMER
layer_portamento 0x81, 55, 255
layer_note1 PITCH_E3, 0x48, 65
layer_end

.layer_1532:
layer_setinstr F0_I_MECH_CHARGE
layer_portamento 0x81, 55, 231
layer_note1 PITCH_E4, 0x48, 58
layer_end

.layer_153C:
layer_setinstr F0_I_EXPLOSION_0
layer_setenvelope .envelope_66D0, 231
layer_portamento 0x81, 51, 255
layer_note1 PITCH_A2, 0x30, 72
layer_end

.item_goddess_launch:
chan_call .chan_fn_2823
chan_setlayer 0, .layer_1557
chan_setlayer 1, .layer_1561
chan_setlayer 2, .layer_156F
chan_end

.layer_1557:
layer_setinstr F0_I_SHIMMER
layer_portamento 0x82, 44, 231
layer_note1 PITCH_E2, 0x48, 85
layer_end

.layer_1561:
layer_setinstr F0_I_MECH_CHARGE
layer_setenvelope .envelope_66F4, 231
layer_portamento 0x82, 51, 255
layer_note1 PITCH_D4, 0x48, 112
layer_end

.layer_156F:
layer_setinstr F0_I_EXPLOSION_0
layer_setenvelope .envelope_66D0, 231
layer_portamento 0x82, 51, 255
layer_note1 PITCH_A2, 0x30, 85
layer_end

.item_goddess_boom:
chan_setval 30
chan_iowriteval 1
chan_setlayer 0, .layer_158A
chan_setlayer 1, .layer_15A2
chan_setlayer 2, .layer_15B1
chan_end

.layer_158A:
layer_setinstr F0_I_SHIMMER
layer_portamento 0x81, 48, 231
layer_note1 PITCH_A2, 0x18, 75
layer_setinstr 77
layer_setenvelope .envelope_6740, 231
layer_portamento 0x81, 38, 255
layer_note1 PITCH_B2, 0xe8, 105
layer_end

.layer_15A2:
layer_setinstr F0_I_DISTORTION
layer_setenvelope .envelope_67CC, 231
layer_portamento 0x81, 14, 255
layer_note1 PITCH_B2, 0xe8, 95
layer_end

.layer_15B1:
layer_setinstr F0_I_EXPLOSION_0
layer_setenvelope .envelope_6610, 231
layer_note1 PITCH_A3, 0x48, 105
layer_end

.item_explosion_unused:
chan_setlayer 0, .layer_15C7
chan_setlayer 1, .layer_15C5
chan_setlayer 2, .layer_2185
chan_end

.layer_15C5:
layer_transpose -18

.layer_15C7:
layer_setinstr F0_I_EXPLOSION_0
layer_setreleaserate 221
layer_note1 PITCH_B4, 0xc8, 85
layer_end

.item_explosive_flames:
chan_setlayer 0, .layer_15D7
chan_setlayer 1, .layer_1EF0
chan_end

.layer_15D7:
layer_setinstr F0_I_EXPLOSION_0
layer_setreleaserate 240
layer_note1 PITCH_B4, 0x7f, 85
layer_end

.item_scarecrow_jump:
chan_setlayer 0, .layer_15E3
chan_end

.layer_15E3:
layer_setinstr F0_I_BOW
layer_setenvelope .envelope_65D8, 251
layer_transpose 48
layer_portamento 0x81, 19, 255
layer_note1 PITCH_AF4, 0x30, 80
layer_end

.item_flame_wall:
chan_setlayer 0, .layer_2C60
chan_setlayer 1, .layer_1BEF
chan_end

.item_fishing_rod_strike:
chan_setlayer 0, .layer_1601
chan_setlayer 1, .layer_160C
chan_end

.layer_1601:
layer_setinstr F0_I_WHIP_CORK
layer_setreleaserate 224
layer_note1 PITCH_G4, 0x6, 100
layer_note1 PITCH_AF3, 0x0, 100
layer_end

.layer_160C:
layer_setinstr F0_I_WHOOSH
layer_note1 PITCH_EF4, 0x14, 76
layer_setinstr 33
layer_note1 PITCH_EF5, 0xa, 102
layer_end

.item_explosion_unused2:
chan_setinstr F0_I_EXPLOSION_0
chan_setenvelope .envelope_66D0
chan_setlayer 0, .layer_1620
chan_end

.layer_1620:
layer_note1 PITCH_G3, 0x0, 95
layer_end

.item_sword_break:
chan_setinstr F0_I_SWORD_HIT_SHIELD
chan_setenvelope .envelope_6610
chan_setlayer 0, .layer_1633
chan_setlayer 1, .layer_105A
chan_setlayer 2, .layer_11B7
chan_end

.layer_1633:
layer_setinstr F0_I_SWORD_STRIKE
layer_transpose 36
layer_note1 PITCH_E3, 0x8, 100
layer_note1 PITCH_A3, 0x0, 100
layer_end

.item_unused4:
chan_setlayer 0, .layer_1642
chan_end

.layer_1642:
layer_setinstr F0_I_WHIP_CORK
layer_note1 PITCH_G3, 0xd, 96
layer_end

.item_sword_swing_magic:
chan_setval 16
chan_iowriteval 1
chan_setlayer 1, .layer_1651
chan_jump .item_hammer_swing

.layer_1651:
layer_setinstr F0_I_SHIMMER
layer_setenvelope .envelope_6610, 235
layer_portamento 0x82, 29, 127
layer_note1 PITCH_GF2, 0x28, 74
layer_end

.balign 16

.filter_item0:
filter 0, 0, 0, 0, 0, 0, 0, 0

.filter_item1:
filter 0, 0, 0, 0, 0, 0, 0, 0