glabel EnKarebaba_UpdateState_Awaken
/* 006E8 80A95A38 27BDFFC8 */  addiu   $sp, $sp, 0xFFC8           ## $sp = FFFFFFC8
/* 006EC 80A95A3C AFB00030 */  sw      $s0, 0x0030($sp)           
/* 006F0 80A95A40 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 006F4 80A95A44 AFBF0034 */  sw      $ra, 0x0034($sp)           
/* 006F8 80A95A48 AFA5003C */  sw      $a1, 0x003C($sp)           
/* 006FC 80A95A4C 0C02927F */  jal     SkelAnime_FrameUpdateMatrix
              
/* 00700 80A95A50 2484014C */  addiu   $a0, $a0, 0x014C           ## $a0 = 0000014C
/* 00704 80A95A54 3C053C23 */  lui     $a1, 0x3C23                ## $a1 = 3C230000
/* 00708 80A95A58 3C063A03 */  lui     $a2, 0x3A03                ## $a2 = 3A030000
/* 0070C 80A95A5C 34C6126F */  ori     $a2, $a2, 0x126F           ## $a2 = 3A03126F
/* 00710 80A95A60 34A5D70A */  ori     $a1, $a1, 0xD70A           ## $a1 = 3C23D70A
/* 00714 80A95A64 0C01DE80 */  jal     Math_ApproxF
              
/* 00718 80A95A68 26040050 */  addiu   $a0, $s0, 0x0050           ## $a0 = 00000050
/* 0071C 80A95A6C 3C014270 */  lui     $at, 0x4270                ## $at = 42700000
/* 00720 80A95A70 44813000 */  mtc1    $at, $f6                   ## $f6 = 60.00
/* 00724 80A95A74 C604000C */  lwc1    $f4, 0x000C($s0)           ## 0000000C
/* 00728 80A95A78 C6000050 */  lwc1    $f0, 0x0050($s0)           ## 00000050
/* 0072C 80A95A7C 26040028 */  addiu   $a0, $s0, 0x0028           ## $a0 = 00000028
/* 00730 80A95A80 46062200 */  add.s   $f8, $f4, $f6              
/* 00734 80A95A84 3C0640A0 */  lui     $a2, 0x40A0                ## $a2 = 40A00000
/* 00738 80A95A88 E6000058 */  swc1    $f0, 0x0058($s0)           ## 00000058
/* 0073C 80A95A8C E6000054 */  swc1    $f0, 0x0054($s0)           ## 00000054
/* 00740 80A95A90 44054000 */  mfc1    $a1, $f8                   
/* 00744 80A95A94 0C01DE80 */  jal     Math_ApproxF
              
/* 00748 80A95A98 00000000 */  nop
/* 0074C 80A95A9C 50400004 */  beql    $v0, $zero, .L80A95AB0     
/* 00750 80A95AA0 860E00B6 */  lh      $t6, 0x00B6($s0)           ## 000000B6
/* 00754 80A95AA4 0C2A5586 */  jal     EnKarebaba_StateChange_Upright              
/* 00758 80A95AA8 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 0075C 80A95AAC 860E00B6 */  lh      $t6, 0x00B6($s0)           ## 000000B6
.L80A95AB0:
/* 00760 80A95AB0 2418000C */  addiu   $t8, $zero, 0x000C         ## $t8 = 0000000C
/* 00764 80A95AB4 24190005 */  addiu   $t9, $zero, 0x0005         ## $t9 = 00000005
/* 00768 80A95AB8 25CF1999 */  addiu   $t7, $t6, 0x1999           ## $t7 = 00001999
/* 0076C 80A95ABC A60F00B6 */  sh      $t7, 0x00B6($s0)           ## 000000B6
/* 00770 80A95AC0 24080001 */  addiu   $t0, $zero, 0x0001         ## $t0 = 00000001
/* 00774 80A95AC4 2409FFFF */  addiu   $t1, $zero, 0xFFFF         ## $t1 = FFFFFFFF
/* 00778 80A95AC8 240A000A */  addiu   $t2, $zero, 0x000A         ## $t2 = 0000000A
/* 0077C 80A95ACC AFAA0020 */  sw      $t2, 0x0020($sp)           
/* 00780 80A95AD0 AFA9001C */  sw      $t1, 0x001C($sp)           
/* 00784 80A95AD4 AFA80018 */  sw      $t0, 0x0018($sp)           
/* 00788 80A95AD8 AFA00024 */  sw      $zero, 0x0024($sp)         
/* 0078C 80A95ADC AFB90014 */  sw      $t9, 0x0014($sp)           
/* 00790 80A95AE0 AFB80010 */  sw      $t8, 0x0010($sp)           
/* 00794 80A95AE4 8FA4003C */  lw      $a0, 0x003C($sp)           
/* 00798 80A95AE8 26050008 */  addiu   $a1, $s0, 0x0008           ## $a1 = 00000008
/* 0079C 80A95AEC 3C064040 */  lui     $a2, 0x4040                ## $a2 = 40400000
/* 007A0 80A95AF0 0C00A5E9 */  jal     EffectSsHahen_SpawnBurst              
/* 007A4 80A95AF4 00003825 */  or      $a3, $zero, $zero          ## $a3 = 00000000
/* 007A8 80A95AF8 8FBF0034 */  lw      $ra, 0x0034($sp)           
/* 007AC 80A95AFC 8FB00030 */  lw      $s0, 0x0030($sp)           
/* 007B0 80A95B00 27BD0038 */  addiu   $sp, $sp, 0x0038           ## $sp = 00000000
/* 007B4 80A95B04 03E00008 */  jr      $ra                        
/* 007B8 80A95B08 00000000 */  nop
