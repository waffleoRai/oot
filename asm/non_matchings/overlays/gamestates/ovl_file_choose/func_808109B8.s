glabel func_808109B8
/* 0CC78 808109B8 27BDFF60 */  addiu   $sp, $sp, 0xFF60           ## $sp = FFFFFF60
/* 0CC7C 808109BC AFBF002C */  sw      $ra, 0x002C($sp)           
/* 0CC80 808109C0 AFB10028 */  sw      $s1, 0x0028($sp)           
/* 0CC84 808109C4 AFB00024 */  sw      $s0, 0x0024($sp)           
/* 0CC88 808109C8 8C850000 */  lw      $a1, 0x0000($a0)           ## 00000000
/* 0CC8C 808109CC 00808825 */  or      $s1, $a0, $zero            ## $s1 = 00000000
/* 0CC90 808109D0 3C068081 */  lui     $a2, %hi(D_80812EE4)       ## $a2 = 80810000
/* 0CC94 808109D4 24C62EE4 */  addiu   $a2, $a2, %lo(D_80812EE4)  ## $a2 = 80812EE4
/* 0CC98 808109D8 27A4007C */  addiu   $a0, $sp, 0x007C           ## $a0 = FFFFFFDC
/* 0CC9C 808109DC 24070AC1 */  addiu   $a3, $zero, 0x0AC1         ## $a3 = 00000AC1
/* 0CCA0 808109E0 0C031AB1 */  jal     Graph_OpenDisps              
/* 0CCA4 808109E4 00A08025 */  or      $s0, $a1, $zero            ## $s0 = 00000000
/* 0CCA8 808109E8 8E0202C0 */  lw      $v0, 0x02C0($s0)           ## 000002C0
/* 0CCAC 808109EC 3C0FE700 */  lui     $t7, 0xE700                ## $t7 = E7000000
/* 0CCB0 808109F0 3C188016 */  lui     $t8, %hi(gGameInfo)
/* 0CCB4 808109F4 244E0008 */  addiu   $t6, $v0, 0x0008           ## $t6 = 00000008
/* 0CCB8 808109F8 AE0E02C0 */  sw      $t6, 0x02C0($s0)           ## 000002C0
/* 0CCBC 808109FC AC400004 */  sw      $zero, 0x0004($v0)         ## 00000004
/* 0CCC0 80810A00 AC4F0000 */  sw      $t7, 0x0000($v0)           ## 00000000
/* 0CCC4 80810A04 8F18FA90 */  lw      $t8, %lo(gGameInfo)($t8)
/* 0CCC8 80810A08 0C01DE0D */  jal     Math_CosS
              ## coss?
/* 0CCCC 80810A0C 870407AA */  lh      $a0, 0x07AA($t8)           ## 801607AA
/* 0CCD0 80810A10 3C198016 */  lui     $t9, %hi(gGameInfo)
/* 0CCD4 80810A14 8F39FA90 */  lw      $t9, %lo(gGameInfo)($t9)
/* 0CCD8 80810A18 E7A00040 */  swc1    $f0, 0x0040($sp)           
/* 0CCDC 80810A1C 0C01DE1C */  jal     Math_SinS
              ## sins?
/* 0CCE0 80810A20 872407AA */  lh      $a0, 0x07AA($t9)           ## 801607AA
/* 0CCE4 80810A24 3C01447A */  lui     $at, 0x447A                ## $at = 447A0000
/* 0CCE8 80810A28 44811000 */  mtc1    $at, $f2                   ## $f2 = 1000.00
/* 0CCEC 80810A2C C7A40040 */  lwc1    $f4, 0x0040($sp)           
/* 0CCF0 80810A30 3C028016 */  lui     $v0, %hi(gGameInfo)
/* 0CCF4 80810A34 8C42FA90 */  lw      $v0, %lo(gGameInfo)($v0)
/* 0CCF8 80810A38 46041182 */  mul.s   $f6, $f2, $f4              
/* 0CCFC 80810A3C 00000000 */  nop
/* 0CD00 80810A40 46020202 */  mul.s   $f8, $f0, $f2              
/* 0CD04 80810A44 46083281 */  sub.s   $f10, $f6, $f8             
/* 0CD08 80810A48 E7AA0098 */  swc1    $f10, 0x0098($sp)          
/* 0CD0C 80810A4C 844807AE */  lh      $t0, 0x07AE($v0)           ## 801607AE
/* 0CD10 80810A50 44888000 */  mtc1    $t0, $f16                  ## $f16 = 0.00
/* 0CD14 80810A54 00000000 */  nop
/* 0CD18 80810A58 468084A0 */  cvt.s.w $f18, $f16                 
/* 0CD1C 80810A5C E7B20094 */  swc1    $f18, 0x0094($sp)          
/* 0CD20 80810A60 0C01DE1C */  jal     Math_SinS
              ## sins?
/* 0CD24 80810A64 844407AA */  lh      $a0, 0x07AA($v0)           ## 801607AA
/* 0CD28 80810A68 3C098016 */  lui     $t1, %hi(gGameInfo)
/* 0CD2C 80810A6C 8D29FA90 */  lw      $t1, %lo(gGameInfo)($t1)
/* 0CD30 80810A70 E7A00040 */  swc1    $f0, 0x0040($sp)           
/* 0CD34 80810A74 0C01DE0D */  jal     Math_CosS
              ## coss?
/* 0CD38 80810A78 852407AA */  lh      $a0, 0x07AA($t1)           ## 801607AA
/* 0CD3C 80810A7C 3C01447A */  lui     $at, 0x447A                ## $at = 447A0000
/* 0CD40 80810A80 44816000 */  mtc1    $at, $f12                  ## $f12 = 1000.00
/* 0CD44 80810A84 C7A60040 */  lwc1    $f6, 0x0040($sp)           
/* 0CD48 80810A88 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 0CD4C 80810A8C 460C0102 */  mul.s   $f4, $f0, $f12             
/* 0CD50 80810A90 8FA50098 */  lw      $a1, 0x0098($sp)           
/* 0CD54 80810A94 8FA60094 */  lw      $a2, 0x0094($sp)           
/* 0CD58 80810A98 46066202 */  mul.s   $f8, $f12, $f6             
/* 0CD5C 80810A9C 46082080 */  add.s   $f2, $f4, $f8              
/* 0CD60 80810AA0 44071000 */  mfc1    $a3, $f2                   
/* 0CD64 80810AA4 0C202BD4 */  jal     func_8080AF50              
/* 0CD68 80810AA8 E7A20090 */  swc1    $f2, 0x0090($sp)           
/* 0CD6C 80810AAC 3C010001 */  lui     $at, 0x0001                ## $at = 00010000
/* 0CD70 80810AB0 34218000 */  ori     $at, $at, 0x8000           ## $at = 00018000
/* 0CD74 80810AB4 02211021 */  addu    $v0, $s1, $at              
/* 0CD78 80810AB8 904748FB */  lbu     $a3, 0x48FB($v0)           ## 000048FB
/* 0CD7C 80810ABC 8E250000 */  lw      $a1, 0x0000($s1)           ## 00000000
/* 0CD80 80810AC0 C7AA0098 */  lwc1    $f10, 0x0098($sp)          
/* 0CD84 80810AC4 C7B00094 */  lwc1    $f16, 0x0094($sp)          
/* 0CD88 80810AC8 C7B20090 */  lwc1    $f18, 0x0090($sp)          
/* 0CD8C 80810ACC 262401E8 */  addiu   $a0, $s1, 0x01E8           ## $a0 = 000001E8
/* 0CD90 80810AD0 AFA40038 */  sw      $a0, 0x0038($sp)           
/* 0CD94 80810AD4 AFA2003C */  sw      $v0, 0x003C($sp)           
/* 0CD98 80810AD8 24060001 */  addiu   $a2, $zero, 0x0001         ## $a2 = 00000001
/* 0CD9C 80810ADC E7AA0010 */  swc1    $f10, 0x0010($sp)          
/* 0CDA0 80810AE0 E7B00014 */  swc1    $f16, 0x0014($sp)          
/* 0CDA4 80810AE4 0C02C431 */  jal     SkyboxDraw_Draw              
/* 0CDA8 80810AE8 E7B20018 */  swc1    $f18, 0x0018($sp)          
/* 0CDAC 80810AEC 8E0202C0 */  lw      $v0, 0x02C0($s0)           ## 000002C0
/* 0CDB0 80810AF0 3C0BE300 */  lui     $t3, 0xE300                ## $t3 = E3000000
/* 0CDB4 80810AF4 356B1001 */  ori     $t3, $t3, 0x1001           ## $t3 = E3001001
/* 0CDB8 80810AF8 244A0008 */  addiu   $t2, $v0, 0x0008           ## $t2 = 00000008
/* 0CDBC 80810AFC AE0A02C0 */  sw      $t2, 0x02C0($s0)           ## 000002C0
/* 0CDC0 80810B00 AC400004 */  sw      $zero, 0x0004($v0)         ## 00000004
/* 0CDC4 80810B04 AC4B0000 */  sw      $t3, 0x0000($v0)           ## 00000000
/* 0CDC8 80810B08 3C028016 */  lui     $v0, %hi(gGameInfo)
/* 0CDCC 80810B0C 8C42FA90 */  lw      $v0, %lo(gGameInfo)($v0)
/* 0CDD0 80810B10 3C010001 */  lui     $at, 0x0001                ## $at = 00010000
/* 0CDD4 80810B14 3421C8E8 */  ori     $at, $at, 0xC8E8           ## $at = 0001C8E8
/* 0CDD8 80810B18 844C07AA */  lh      $t4, 0x07AA($v0)           ## 801607AA
/* 0CDDC 80810B1C 844D07A8 */  lh      $t5, 0x07A8($v0)           ## 801607A8
/* 0CDE0 80810B20 02212821 */  addu    $a1, $s1, $at              
/* 0CDE4 80810B24 24040001 */  addiu   $a0, $zero, 0x0001         ## $a0 = 00000001
/* 0CDE8 80810B28 018D7021 */  addu    $t6, $t4, $t5              
/* 0CDEC 80810B2C A44E07AA */  sh      $t6, 0x07AA($v0)           ## 801607AA
/* 0CDF0 80810B30 0C01BF22 */  jal     Environment_UpdateSkybox              
/* 0CDF4 80810B34 8FA60038 */  lw      $a2, 0x0038($sp)           
/* 0CDF8 80810B38 8E0202C0 */  lw      $v0, 0x02C0($s0)           ## 000002C0
/* 0CDFC 80810B3C 3C18E700 */  lui     $t8, 0xE700                ## $t8 = E7000000
/* 0CE00 80810B40 244F0008 */  addiu   $t7, $v0, 0x0008           ## $t7 = 00000008
/* 0CE04 80810B44 AE0F02C0 */  sw      $t7, 0x02C0($s0)           ## 000002C0
/* 0CE08 80810B48 AC400004 */  sw      $zero, 0x0004($v0)         ## 00000004
/* 0CE0C 80810B4C AC580000 */  sw      $t8, 0x0000($v0)           ## 00000000
/* 0CE10 80810B50 0C02526A */  jal     func_800949A8              
/* 0CE14 80810B54 8E240000 */  lw      $a0, 0x0000($s1)           ## 00000000
/* 0CE18 80810B58 44800000 */  mtc1    $zero, $f0                 ## $f0 = 0.00
/* 0CE1C 80810B5C 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 0CE20 80810B60 3C074280 */  lui     $a3, 0x4280                ## $a3 = 42800000
/* 0CE24 80810B64 44050000 */  mfc1    $a1, $f0                   
/* 0CE28 80810B68 44060000 */  mfc1    $a2, $f0                   
/* 0CE2C 80810B6C 0C202BD4 */  jal     func_8080AF50              
/* 0CE30 80810B70 00000000 */  nop
/* 0CE34 80810B74 0C2030CC */  jal     func_8080C330              
/* 0CE38 80810B78 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 0CE3C 80810B7C 0C203183 */  jal     func_8080C60C              
/* 0CE40 80810B80 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 0CE44 80810B84 8E0202C0 */  lw      $v0, 0x02C0($s0)           ## 000002C0
/* 0CE48 80810B88 3C08FC11 */  lui     $t0, 0xFC11                ## $t0 = FC110000
/* 0CE4C 80810B8C 3C09FF2F */  lui     $t1, 0xFF2F                ## $t1 = FF2F0000
/* 0CE50 80810B90 24590008 */  addiu   $t9, $v0, 0x0008           ## $t9 = 00000008
/* 0CE54 80810B94 AE1902C0 */  sw      $t9, 0x02C0($s0)           ## 000002C0
/* 0CE58 80810B98 3529FFFF */  ori     $t1, $t1, 0xFFFF           ## $t1 = FF2FFFFF
/* 0CE5C 80810B9C 35089623 */  ori     $t0, $t0, 0x9623           ## $t0 = FC119623
/* 0CE60 80810BA0 AC480000 */  sw      $t0, 0x0000($v0)           ## 00000000
/* 0CE64 80810BA4 AC490004 */  sw      $t1, 0x0004($v0)           ## 00000004
/* 0CE68 80810BA8 8E0202C0 */  lw      $v0, 0x02C0($s0)           ## 000002C0
/* 0CE6C 80810BAC 8FA4003C */  lw      $a0, 0x003C($sp)           
/* 0CE70 80810BB0 3C0BFA00 */  lui     $t3, 0xFA00                ## $t3 = FA000000
/* 0CE74 80810BB4 244A0008 */  addiu   $t2, $v0, 0x0008           ## $t2 = 00000008
/* 0CE78 80810BB8 AE0A02C0 */  sw      $t2, 0x02C0($s0)           ## 000002C0
/* 0CE7C 80810BBC AC4B0000 */  sw      $t3, 0x0000($v0)           ## 00000000
/* 0CE80 80810BC0 848C4A6C */  lh      $t4, 0x4A6C($a0)           ## 00004A6C
/* 0CE84 80810BC4 84894A6A */  lh      $t1, 0x4A6A($a0)           ## 00004A6A
/* 0CE88 80810BC8 84984A68 */  lh      $t8, 0x4A68($a0)           ## 00004A68
/* 0CE8C 80810BCC 318D00FF */  andi    $t5, $t4, 0x00FF           ## $t5 = 00000000
/* 0CE90 80810BD0 000D7200 */  sll     $t6, $t5,  8               
/* 0CE94 80810BD4 848D4A72 */  lh      $t5, 0x4A72($a0)           ## 00004A72
/* 0CE98 80810BD8 312A00FF */  andi    $t2, $t1, 0x00FF           ## $t2 = 000000FF
/* 0CE9C 80810BDC 0018CE00 */  sll     $t9, $t8, 24               
/* 0CEA0 80810BE0 01D94025 */  or      $t0, $t6, $t9              ## $t0 = 00000008
/* 0CEA4 80810BE4 000A5C00 */  sll     $t3, $t2, 16               
/* 0CEA8 80810BE8 010B6025 */  or      $t4, $t0, $t3              ## $t4 = FA000008
/* 0CEAC 80810BEC 31AF00FF */  andi    $t7, $t5, 0x00FF           ## $t7 = 00000000
/* 0CEB0 80810BF0 018FC025 */  or      $t8, $t4, $t7              ## $t8 = FA000008
/* 0CEB4 80810BF4 AC580004 */  sw      $t8, 0x0004($v0)           ## 00000004
/* 0CEB8 80810BF8 8E0202C0 */  lw      $v0, 0x02C0($s0)           ## 000002C0
/* 0CEBC 80810BFC 44806000 */  mtc1    $zero, $f12                ## $f12 = 0.00
/* 0CEC0 80810C00 3C19FB00 */  lui     $t9, 0xFB00                ## $t9 = FB000000
/* 0CEC4 80810C04 244E0008 */  addiu   $t6, $v0, 0x0008           ## $t6 = 00000008
/* 0CEC8 80810C08 AE0E02C0 */  sw      $t6, 0x02C0($s0)           ## 000002C0
/* 0CECC 80810C0C 3C06C2BB */  lui     $a2, 0xC2BB                ## $a2 = C2BB0000
/* 0CED0 80810C10 34C63333 */  ori     $a2, $a2, 0x3333           ## $a2 = C2BB3333
/* 0CED4 80810C14 00003825 */  or      $a3, $zero, $zero          ## $a3 = 00000000
/* 0CED8 80810C18 AC400004 */  sw      $zero, 0x0004($v0)         ## 00000004
/* 0CEDC 80810C1C AC590000 */  sw      $t9, 0x0000($v0)           ## 00000000
/* 0CEE0 80810C20 0C034261 */  jal     Matrix_Translate              
/* 0CEE4 80810C24 46006386 */  mov.s   $f14, $f12                 
/* 0CEE8 80810C28 3C018081 */  lui     $at, %hi(D_80813018)       ## $at = 80810000
/* 0CEEC 80810C2C C42C3018 */  lwc1    $f12, %lo(D_80813018)($at) 
/* 0CEF0 80810C30 24070001 */  addiu   $a3, $zero, 0x0001         ## $a3 = 00000001
/* 0CEF4 80810C34 44066000 */  mfc1    $a2, $f12                  
/* 0CEF8 80810C38 0C0342A3 */  jal     Matrix_Scale              
/* 0CEFC 80810C3C 46006386 */  mov.s   $f14, $f12                 
/* 0CF00 80810C40 8FA9003C */  lw      $t1, 0x003C($sp)           
/* 0CF04 80810C44 3C0142C8 */  lui     $at, 0x42C8                ## $at = 42C80000
/* 0CF08 80810C48 44812000 */  mtc1    $at, $f4                   ## $f4 = 100.00
/* 0CF0C 80810C4C C5264AC4 */  lwc1    $f6, 0x4AC4($t1)           ## 00004AC4
/* 0CF10 80810C50 24050001 */  addiu   $a1, $zero, 0x0001         ## $a1 = 00000001
/* 0CF14 80810C54 0C0342DC */  jal     Matrix_RotateX              
/* 0CF18 80810C58 46043303 */  div.s   $f12, $f6, $f4             
/* 0CF1C 80810C5C 8E0202C0 */  lw      $v0, 0x02C0($s0)           ## 000002C0
/* 0CF20 80810C60 3C08DA38 */  lui     $t0, 0xDA38                ## $t0 = DA380000
/* 0CF24 80810C64 35080003 */  ori     $t0, $t0, 0x0003           ## $t0 = DA380003
/* 0CF28 80810C68 244A0008 */  addiu   $t2, $v0, 0x0008           ## $t2 = 00000008
/* 0CF2C 80810C6C AE0A02C0 */  sw      $t2, 0x02C0($s0)           ## 000002C0
/* 0CF30 80810C70 AC480000 */  sw      $t0, 0x0000($v0)           ## 00000000
/* 0CF34 80810C74 8E240000 */  lw      $a0, 0x0000($s1)           ## 00000000
/* 0CF38 80810C78 3C058081 */  lui     $a1, %hi(D_80812EF8)       ## $a1 = 80810000
/* 0CF3C 80810C7C 24A52EF8 */  addiu   $a1, $a1, %lo(D_80812EF8)  ## $a1 = 80812EF8
/* 0CF40 80810C80 24060AFA */  addiu   $a2, $zero, 0x0AFA         ## $a2 = 00000AFA
/* 0CF44 80810C84 0C0346A2 */  jal     Matrix_NewMtx              
/* 0CF48 80810C88 AFA20060 */  sw      $v0, 0x0060($sp)           
/* 0CF4C 80810C8C 8FA30060 */  lw      $v1, 0x0060($sp)           
/* 0CF50 80810C90 3C050102 */  lui     $a1, 0x0102                ## $a1 = 01020000
/* 0CF54 80810C94 34A50040 */  ori     $a1, $a1, 0x0040           ## $a1 = 01020040
/* 0CF58 80810C98 AC620004 */  sw      $v0, 0x0004($v1)           ## 00000004
/* 0CF5C 80810C9C 8E0202C0 */  lw      $v0, 0x02C0($s0)           ## 000002C0
/* 0CF60 80810CA0 3C0F0104 */  lui     $t7, 0x0104                ## $t7 = 01040000
/* 0CF64 80810CA4 25EF6F00 */  addiu   $t7, $t7, 0x6F00           ## $t7 = 01046F00
/* 0CF68 80810CA8 244B0008 */  addiu   $t3, $v0, 0x0008           ## $t3 = 00000008
/* 0CF6C 80810CAC AE0B02C0 */  sw      $t3, 0x02C0($s0)           ## 000002C0
/* 0CF70 80810CB0 AC450000 */  sw      $a1, 0x0000($v0)           ## 00000000
/* 0CF74 80810CB4 8E2D00A4 */  lw      $t5, 0x00A4($s1)           ## 000000A4
/* 0CF78 80810CB8 3C04DE00 */  lui     $a0, 0xDE00                ## $a0 = DE000000
/* 0CF7C 80810CBC 3C0A0104 */  lui     $t2, 0x0104                ## $t2 = 01040000
/* 0CF80 80810CC0 AC4D0004 */  sw      $t5, 0x0004($v0)           ## 00000004
/* 0CF84 80810CC4 8E0202C0 */  lw      $v0, 0x02C0($s0)           ## 000002C0
/* 0CF88 80810CC8 254A7118 */  addiu   $t2, $t2, 0x7118           ## $t2 = 01047118
/* 0CF8C 80810CCC 3C0B0101 */  lui     $t3, 0x0101                ## $t3 = 01010000
/* 0CF90 80810CD0 244C0008 */  addiu   $t4, $v0, 0x0008           ## $t4 = 00000008
/* 0CF94 80810CD4 AE0C02C0 */  sw      $t4, 0x02C0($s0)           ## 000002C0
/* 0CF98 80810CD8 AC4F0004 */  sw      $t7, 0x0004($v0)           ## 00000004
/* 0CF9C 80810CDC AC440000 */  sw      $a0, 0x0000($v0)           ## 00000000
/* 0CFA0 80810CE0 8E0202C0 */  lw      $v0, 0x02C0($s0)           ## 000002C0
/* 0CFA4 80810CE4 356B0020 */  ori     $t3, $t3, 0x0020           ## $t3 = 01010020
/* 0CFA8 80810CE8 24580008 */  addiu   $t8, $v0, 0x0008           ## $t8 = 00000008
/* 0CFAC 80810CEC AE1802C0 */  sw      $t8, 0x02C0($s0)           ## 000002C0
/* 0CFB0 80810CF0 AC450000 */  sw      $a1, 0x0000($v0)           ## 00000000
/* 0CFB4 80810CF4 8E2E00A4 */  lw      $t6, 0x00A4($s1)           ## 000000A4
/* 0CFB8 80810CF8 3C180104 */  lui     $t8, 0x0104                ## $t8 = 01040000
/* 0CFBC 80810CFC 27187328 */  addiu   $t8, $t8, 0x7328           ## $t8 = 01047328
/* 0CFC0 80810D00 25D90200 */  addiu   $t9, $t6, 0x0200           ## $t9 = 00000200
/* 0CFC4 80810D04 AC590004 */  sw      $t9, 0x0004($v0)           ## 00000004
/* 0CFC8 80810D08 8E0202C0 */  lw      $v0, 0x02C0($s0)           ## 000002C0
/* 0CFCC 80810D0C 24490008 */  addiu   $t1, $v0, 0x0008           ## $t1 = 00000008
/* 0CFD0 80810D10 AE0902C0 */  sw      $t1, 0x02C0($s0)           ## 000002C0
/* 0CFD4 80810D14 AC4A0004 */  sw      $t2, 0x0004($v0)           ## 00000004
/* 0CFD8 80810D18 AC440000 */  sw      $a0, 0x0000($v0)           ## 00000000
/* 0CFDC 80810D1C 8E0202C0 */  lw      $v0, 0x02C0($s0)           ## 000002C0
/* 0CFE0 80810D20 24480008 */  addiu   $t0, $v0, 0x0008           ## $t0 = 00000008
/* 0CFE4 80810D24 AE0802C0 */  sw      $t0, 0x02C0($s0)           ## 000002C0
/* 0CFE8 80810D28 AC4B0000 */  sw      $t3, 0x0000($v0)           ## 00000000
/* 0CFEC 80810D2C 8E2D00A4 */  lw      $t5, 0x00A4($s1)           ## 000000A4
/* 0CFF0 80810D30 25AC0400 */  addiu   $t4, $t5, 0x0400           ## $t4 = 00000400
/* 0CFF4 80810D34 AC4C0004 */  sw      $t4, 0x0004($v0)           ## 00000004
/* 0CFF8 80810D38 8E0202C0 */  lw      $v0, 0x02C0($s0)           ## 000002C0
/* 0CFFC 80810D3C 244F0008 */  addiu   $t7, $v0, 0x0008           ## $t7 = 00000008
/* 0D000 80810D40 AE0F02C0 */  sw      $t7, 0x02C0($s0)           ## 000002C0
/* 0D004 80810D44 AC440000 */  sw      $a0, 0x0000($v0)           ## 00000000
/* 0D008 80810D48 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 0D00C 80810D4C 0C20381D */  jal     func_8080E074              
/* 0D010 80810D50 AC580004 */  sw      $t8, 0x0004($v0)           ## 00000004
/* 0D014 80810D54 8E0202C0 */  lw      $v0, 0x02C0($s0)           ## 000002C0
/* 0D018 80810D58 3C19E700 */  lui     $t9, 0xE700                ## $t9 = E7000000
/* 0D01C 80810D5C 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 0D020 80810D60 244E0008 */  addiu   $t6, $v0, 0x0008           ## $t6 = 00000008
/* 0D024 80810D64 AE0E02C0 */  sw      $t6, 0x02C0($s0)           ## 000002C0
/* 0D028 80810D68 24050000 */  addiu   $a1, $zero, 0x0000         ## $a1 = 00000000
/* 0D02C 80810D6C 24060000 */  addiu   $a2, $zero, 0x0000         ## $a2 = 00000000
/* 0D030 80810D70 3C074280 */  lui     $a3, 0x4280                ## $a3 = 42800000
/* 0D034 80810D74 AC400004 */  sw      $zero, 0x0004($v0)         ## 00000004
/* 0D038 80810D78 0C202BD4 */  jal     func_8080AF50              
/* 0D03C 80810D7C AC590000 */  sw      $t9, 0x0000($v0)           ## 00000000
/* 0D040 80810D80 3C068081 */  lui     $a2, %hi(D_80812F0C)       ## $a2 = 80810000
/* 0D044 80810D84 24C62F0C */  addiu   $a2, $a2, %lo(D_80812F0C)  ## $a2 = 80812F0C
/* 0D048 80810D88 27A4007C */  addiu   $a0, $sp, 0x007C           ## $a0 = FFFFFFDC
/* 0D04C 80810D8C 8E250000 */  lw      $a1, 0x0000($s1)           ## 00000000
/* 0D050 80810D90 0C031AD5 */  jal     Graph_CloseDisps              
/* 0D054 80810D94 24070B12 */  addiu   $a3, $zero, 0x0B12         ## $a3 = 00000B12
/* 0D058 80810D98 8FBF002C */  lw      $ra, 0x002C($sp)           
/* 0D05C 80810D9C 8FB00024 */  lw      $s0, 0x0024($sp)           
/* 0D060 80810DA0 8FB10028 */  lw      $s1, 0x0028($sp)           
/* 0D064 80810DA4 03E00008 */  jr      $ra                        
/* 0D068 80810DA8 27BD00A0 */  addiu   $sp, $sp, 0x00A0           ## $sp = 00000000
