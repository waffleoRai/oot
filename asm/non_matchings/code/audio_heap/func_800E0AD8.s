glabel func_800E0AD8
/* B57C78 800E0AD8 27BDFFD0 */  addiu $sp, $sp, -0x30
/* B57C7C 800E0ADC AFB50028 */  sw    $s5, 0x28($sp)
/* B57C80 800E0AE0 3C158017 */  lui   $s5, %hi(gAudioContext) # $s5, 0x8017
/* B57C84 800E0AE4 26B5F180 */  addiu $s5, %lo(gAudioContext) # addiu $s5, $s5, -0xe80
/* B57C88 800E0AE8 8EAE2834 */  lw    $t6, 0x2834($s5)
/* B57C8C 800E0AEC AFBF002C */  sw    $ra, 0x2c($sp)
/* B57C90 800E0AF0 AFB40024 */  sw    $s4, 0x24($sp)
/* B57C94 800E0AF4 AFB30020 */  sw    $s3, 0x20($sp)
/* B57C98 800E0AF8 AFB2001C */  sw    $s2, 0x1c($sp)
/* B57C9C 800E0AFC AFB10018 */  sw    $s1, 0x18($sp)
/* B57CA0 800E0B00 AFB00014 */  sw    $s0, 0x14($sp)
/* B57CA4 800E0B04 85D40000 */  lh    $s4, ($t6)
/* B57CA8 800E0B08 00809025 */  move  $s2, $a0
/* B57CAC 800E0B0C 00008025 */  move  $s0, $zero
/* B57CB0 800E0B10 1A80001F */  blez  $s4, .L800E0B90
/* B57CB4 800E0B14 00008825 */   move  $s1, $zero
/* B57CB8 800E0B18 241300FF */  li    $s3, 255
.L800E0B1C:
/* B57CBC 800E0B1C 8EAF2844 */  lw    $t7, 0x2844($s5)
/* B57CC0 800E0B20 82450002 */  lb    $a1, 2($s2)
/* B57CC4 800E0B24 01F11021 */  addu  $v0, $t7, $s1
/* B57CC8 800E0B28 90430002 */  lbu   $v1, 2($v0)
/* B57CCC 800E0B2C 90440003 */  lbu   $a0, 3($v0)
/* B57CD0 800E0B30 10730003 */  beq   $v1, $s3, .L800E0B40
/* B57CD4 800E0B34 00000000 */   nop   
/* B57CD8 800E0B38 50650007 */  beql  $v1, $a1, .L800E0B58
/* B57CDC 800E0B3C 24040001 */   li    $a0, 1
.L800E0B40:
/* B57CE0 800E0B40 10930003 */  beq   $a0, $s3, .L800E0B50
/* B57CE4 800E0B44 00000000 */   nop   
/* B57CE8 800E0B48 50850003 */  beql  $a0, $a1, .L800E0B58
/* B57CEC 800E0B4C 24040001 */   li    $a0, 1
.L800E0B50:
/* B57CF0 800E0B50 14A0000C */  bnez  $a1, .L800E0B84
/* B57CF4 800E0B54 24040001 */   li    $a0, 1
.L800E0B58:
/* B57CF8 800E0B58 24050002 */  li    $a1, 2
/* B57CFC 800E0B5C 0C037C1D */  jal   func_800DF074
/* B57D00 800E0B60 02003025 */   move  $a2, $s0
/* B57D04 800E0B64 50400008 */  beql  $v0, $zero, .L800E0B88
/* B57D08 800E0B68 26100001 */   addiu $s0, $s0, 1
/* B57D0C 800E0B6C 0C03862C */  jal   func_800E18B0
/* B57D10 800E0B70 02002025 */   move  $a0, $s0
/* B57D14 800E0B74 10400003 */  beqz  $v0, .L800E0B84
/* B57D18 800E0B78 02402025 */   move  $a0, $s2
/* B57D1C 800E0B7C 0C038259 */  jal   func_800E0964
/* B57D20 800E0B80 02002825 */   move  $a1, $s0
.L800E0B84:
/* B57D24 800E0B84 26100001 */  addiu $s0, $s0, 1
.L800E0B88:
/* B57D28 800E0B88 1614FFE4 */  bne   $s0, $s4, .L800E0B1C
/* B57D2C 800E0B8C 26310014 */   addiu $s1, $s1, 0x14
.L800E0B90:
/* B57D30 800E0B90 8FBF002C */  lw    $ra, 0x2c($sp)
/* B57D34 800E0B94 8FB00014 */  lw    $s0, 0x14($sp)
/* B57D38 800E0B98 8FB10018 */  lw    $s1, 0x18($sp)
/* B57D3C 800E0B9C 8FB2001C */  lw    $s2, 0x1c($sp)
/* B57D40 800E0BA0 8FB30020 */  lw    $s3, 0x20($sp)
/* B57D44 800E0BA4 8FB40024 */  lw    $s4, 0x24($sp)
/* B57D48 800E0BA8 8FB50028 */  lw    $s5, 0x28($sp)
/* B57D4C 800E0BAC 03E00008 */  jr    $ra
/* B57D50 800E0BB0 27BD0030 */   addiu $sp, $sp, 0x30
