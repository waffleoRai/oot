#include "global.h"
#include "vt.h"

StackEntry sDmaMgrStackInfo;
OSMesgQueue sDmaMgrMsgQueue;
OSMesg sDmaMgrMsgs[0x20];
OSThread sDmaMgrThread;
u8 sDmaMgrStack[0x500];
const char* sDmaMgrCurFileName;
s32 sDmaMgrCurFileLine;

u32 D_80009460 = 0;
u32 gDmaMgrDmaBuffSize = 0x2000;
u32 sDmaMgrDataExistError = 0;

const char* sDmaMgrFileNames[0x5FC] = {
    "makerom",
    "boot",
    "dmadata",
    "Audiobank",
    "Audioseq",
    "Audiotable",
    "link_animetion",
    "icon_item_static",
    "icon_item_24_static",
    "icon_item_field_static",
    "icon_item_dungeon_static",
    "icon_item_gameover_static",
    "icon_item_nes_static",
    "icon_item_ger_static",
    "icon_item_fra_static",
    "item_name_static",
    "map_name_static",
    "do_action_static",
    "message_static",
    "message_texture_static",
    "nes_font_static",
    "nes_message_data_static",
    "ger_message_data_static",
    "fra_message_data_static",
    "staff_message_data_static",
    "map_grand_static",
    "map_i_static",
    "map_48x85_static",
    "code",
    "ovl_title",
    "ovl_select",
    "ovl_opening",
    "ovl_file_choose",
    "ovl_kaleido_scope",
    "ovl_player_actor",
    "ovl_map_mark_data",
    "ovl_En_Test",
    "ovl_Arms_Hook",
    "ovl_Arrow_Fire",
    "ovl_Arrow_Ice",
    "ovl_Arrow_Light",
    "ovl_Bg_Bdan_Objects",
    "ovl_Bg_Bdan_Switch",
    "ovl_Bg_Bom_Guard",
    "ovl_Bg_Bombwall",
    "ovl_Bg_Bowl_Wall",
    "ovl_Bg_Breakwall",
    "ovl_Bg_Ddan_Jd",
    "ovl_Bg_Ddan_Kd",
    "ovl_Bg_Dodoago",
    "ovl_Bg_Dy_Yoseizo",
    "ovl_Bg_Ganon_Otyuka",
    "ovl_Bg_Gate_Shutter",
    "ovl_Bg_Gjyo_Bridge",
    "ovl_Bg_Gnd_Darkmeiro",
    "ovl_Bg_Gnd_Firemeiro",
    "ovl_Bg_Gnd_Iceblock",
    "ovl_Bg_Gnd_Nisekabe",
    "ovl_Bg_Gnd_Soulmeiro",
    "ovl_Bg_Haka",
    "ovl_Bg_Haka_Gate",
    "ovl_Bg_Haka_Huta",
    "ovl_Bg_Haka_Megane",
    "ovl_Bg_Haka_MeganeBG",
    "ovl_Bg_Haka_Sgami",
    "ovl_Bg_Haka_Ship",
    "ovl_Bg_Haka_Trap",
    "ovl_Bg_Haka_Tubo",
    "ovl_Bg_Haka_Water",
    "ovl_Bg_Haka_Zou",
    "ovl_Bg_Heavy_Block",
    "ovl_Bg_Hidan_Curtain",
    "ovl_Bg_Hidan_Dalm",
    "ovl_Bg_Hidan_Firewall",
    "ovl_Bg_Hidan_Fslift",
    "ovl_Bg_Hidan_Fwbig",
    "ovl_Bg_Hidan_Hamstep",
    "ovl_Bg_Hidan_Hrock",
    "ovl_Bg_Hidan_Kousi",
    "ovl_Bg_Hidan_Kowarerukabe",
    "ovl_Bg_Hidan_Rock",
    "ovl_Bg_Hidan_Rsekizou",
    "ovl_Bg_Hidan_Sekizou",
    "ovl_Bg_Hidan_Sima",
    "ovl_Bg_Hidan_Syoku",
    "ovl_Bg_Ice_Objects",
    "ovl_Bg_Ice_Shelter",
    "ovl_Bg_Ice_Shutter",
    "ovl_Bg_Ice_Turara",
    "ovl_Bg_Ingate",
    "ovl_Bg_Jya_1flift",
    "ovl_Bg_Jya_Amishutter",
    "ovl_Bg_Jya_Bigmirror",
    "ovl_Bg_Jya_Block",
    "ovl_Bg_Jya_Bombchuiwa",
    "ovl_Bg_Jya_Bombiwa",
    "ovl_Bg_Jya_Cobra",
    "ovl_Bg_Jya_Goroiwa",
    "ovl_Bg_Jya_Haheniron",
    "ovl_Bg_Jya_Ironobj",
    "ovl_Bg_Jya_Kanaami",
    "ovl_Bg_Jya_Lift",
    "ovl_Bg_Jya_Megami",
    "ovl_Bg_Jya_Zurerukabe",
    "ovl_Bg_Menkuri_Eye",
    "ovl_Bg_Menkuri_Kaiten",
    "ovl_Bg_Menkuri_Nisekabe",
    "ovl_Bg_Mizu_Bwall",
    "ovl_Bg_Mizu_Movebg",
    "ovl_Bg_Mizu_Shutter",
    "ovl_Bg_Mizu_Uzu",
    "ovl_Bg_Mizu_Water",
    "ovl_Bg_Mjin",
    "ovl_Bg_Mori_Bigst",
    "ovl_Bg_Mori_Elevator",
    "ovl_Bg_Mori_Hashigo",
    "ovl_Bg_Mori_Hashira4",
    "ovl_Bg_Mori_Hineri",
    "ovl_Bg_Mori_Idomizu",
    "ovl_Bg_Mori_Kaitenkabe",
    "ovl_Bg_Mori_Rakkatenjo",
    "ovl_Bg_Po_Event",
    "ovl_Bg_Po_Syokudai",
    "ovl_Bg_Pushbox",
    "ovl_Bg_Relay_Objects",
    "ovl_Bg_Spot00_Break",
    "ovl_Bg_Spot00_Hanebasi",
    "ovl_Bg_Spot01_Fusya",
    "ovl_Bg_Spot01_Idohashira",
    "ovl_Bg_Spot01_Idomizu",
    "ovl_Bg_Spot01_Idosoko",
    "ovl_Bg_Spot01_Objects2",
    "ovl_Bg_Spot02_Objects",
    "ovl_Bg_Spot03_Taki",
    "ovl_Bg_Spot05_Soko",
    "ovl_Bg_Spot06_Objects",
    "ovl_Bg_Spot07_Taki",
    "ovl_Bg_Spot08_Bakudankabe",
    "ovl_Bg_Spot08_Iceblock",
    "ovl_Bg_Spot09_Obj",
    "ovl_Bg_Spot11_Bakudankabe",
    "ovl_Bg_Spot11_Oasis",
    "ovl_Bg_Spot12_Gate",
    "ovl_Bg_Spot12_Saku",
    "ovl_Bg_Spot15_Rrbox",
    "ovl_Bg_Spot15_Saku",
    "ovl_Bg_Spot16_Bombstone",
    "ovl_Bg_Spot16_Doughnut",
    "ovl_Bg_Spot17_Bakudankabe",
    "ovl_Bg_Spot17_Funen",
    "ovl_Bg_Spot18_Basket",
    "ovl_Bg_Spot18_Futa",
    "ovl_Bg_Spot18_Obj",
    "ovl_Bg_Spot18_Shutter",
    "ovl_Bg_Sst_Floor",
    "ovl_Bg_Toki_Hikari",
    "ovl_Bg_Toki_Swd",
    "ovl_Bg_Treemouth",
    "ovl_Bg_Umajump",
    "ovl_Bg_Vb_Sima",
    "ovl_Bg_Ydan_Hasi",
    "ovl_Bg_Ydan_Maruta",
    "ovl_Bg_Ydan_Sp",
    "ovl_Bg_Zg",
    "ovl_Boss_Dodongo",
    "ovl_Boss_Fd",
    "ovl_Boss_Fd2",
    "ovl_Boss_Ganon",
    "ovl_Boss_Ganon2",
    "ovl_Boss_Ganondrof",
    "ovl_Boss_Goma",
    "ovl_Boss_Mo",
    "ovl_Boss_Sst",
    "ovl_Boss_Tw",
    "ovl_Boss_Va",
    "ovl_Demo_6K",
    "ovl_Demo_Du",
    "ovl_Demo_Ec",
    "ovl_Demo_Effect",
    "ovl_Demo_Ext",
    "ovl_Demo_Geff",
    "ovl_Demo_Gj",
    "ovl_Demo_Go",
    "ovl_Demo_Gt",
    "ovl_Demo_Ik",
    "ovl_Demo_Im",
    "ovl_Demo_Kankyo",
    "ovl_Demo_Kekkai",
    "ovl_Demo_Sa",
    "ovl_Demo_Shd",
    "ovl_Demo_Tre_Lgt",
    "ovl_Door_Ana",
    "ovl_Door_Gerudo",
    "ovl_Door_Killer",
    "ovl_Door_Shutter",
    "ovl_Door_Toki",
    "ovl_Door_Warp1",
    "ovl_Efc_Erupc",
    "ovl_Eff_Dust",
    "ovl_Effect_Ss_Blast",
    "ovl_Effect_Ss_Bomb",
    "ovl_Effect_Ss_Bomb2",
    "ovl_Effect_Ss_Bubble",
    "ovl_Effect_Ss_D_Fire",
    "ovl_Effect_Ss_Dead_Db",
    "ovl_Effect_Ss_Dead_Dd",
    "ovl_Effect_Ss_Dead_Ds",
    "ovl_Effect_Ss_Dead_Sound",
    "ovl_Effect_Ss_Dt_Bubble",
    "ovl_Effect_Ss_Dust",
    "ovl_Effect_Ss_En_Fire",
    "ovl_Effect_Ss_En_Ice",
    "ovl_Effect_Ss_Extra",
    "ovl_Effect_Ss_Fcircle",
    "ovl_Effect_Ss_Fhg_Flash",
    "ovl_Effect_Ss_Fire_Tail",
    "ovl_Effect_Ss_G_Fire",
    "ovl_Effect_Ss_G_Magma",
    "ovl_Effect_Ss_G_Magma2",
    "ovl_Effect_Ss_G_Ripple",
    "ovl_Effect_Ss_G_Spk",
    "ovl_Effect_Ss_G_Splash",
    "ovl_Effect_Ss_Hahen",
    "ovl_Effect_Ss_HitMark",
    "ovl_Effect_Ss_Ice_Piece",
    "ovl_Effect_Ss_Ice_Smoke",
    "ovl_Effect_Ss_K_Fire",
    "ovl_Effect_Ss_Kakera",
    "ovl_Effect_Ss_KiraKira",
    "ovl_Effect_Ss_Lightning",
    "ovl_Effect_Ss_Sibuki",
    "ovl_Effect_Ss_Sibuki2",
    "ovl_Effect_Ss_Solder_Srch_Ball",
    "ovl_Effect_Ss_Stick",
    "ovl_Effect_Ss_Stone1",
    "ovl_Elf_Msg",
    "ovl_Elf_Msg2",
    "ovl_En_Am",
    "ovl_En_Ani",
    "ovl_En_Anubice",
    "ovl_En_Anubice_Fire",
    "ovl_En_Anubice_Tag",
    "ovl_En_Arow_Trap",
    "ovl_En_Arrow",
    "ovl_En_Attack_Niw",
    "ovl_En_Ba",
    "ovl_En_Bb",
    "ovl_En_Bdfire",
    "ovl_En_Bigokuta",
    "ovl_En_Bili",
    "ovl_En_Bird",
    "ovl_En_Blkobj",
    "ovl_En_Bom",
    "ovl_En_Bom_Bowl_Man",
    "ovl_En_Bom_Bowl_Pit",
    "ovl_En_Bom_Chu",
    "ovl_En_Bombf",
    "ovl_En_Boom",
    "ovl_En_Box",
    "ovl_En_Brob",
    "ovl_En_Bubble",
    "ovl_En_Butte",
    "ovl_En_Bw",
    "ovl_En_Bx",
    "ovl_En_Changer",
    "ovl_En_Clear_Tag",
    "ovl_En_Cow",
    "ovl_En_Crow",
    "ovl_En_Cs",
    "ovl_En_Daiku",
    "ovl_En_Daiku_Kakariko",
    "ovl_En_Dekubaba",
    "ovl_En_Dekunuts",
    "ovl_En_Dh",
    "ovl_En_Dha",
    "ovl_En_Diving_Game",
    "ovl_En_Dns",
    "ovl_En_Dnt_Demo",
    "ovl_En_Dnt_Jiji",
    "ovl_En_Dnt_Nomal",
    "ovl_En_Dodojr",
    "ovl_En_Dodongo",
    "ovl_En_Dog",
    "ovl_En_Door",
    "ovl_En_Ds",
    "ovl_En_Du",
    "ovl_En_Dy_Extra",
    "ovl_En_Eg",
    "ovl_En_Eiyer",
    "ovl_En_Elf",
    "ovl_En_Encount1",
    "ovl_En_Encount2",
    "ovl_En_Ex_Item",
    "ovl_En_Ex_Ruppy",
    "ovl_En_Fd",
    "ovl_En_Fd_Fire",
    "ovl_En_Fhg_Fire",
    "ovl_En_Fire_Rock",
    "ovl_En_Firefly",
    "ovl_En_Fish",
    "ovl_En_Floormas",
    "ovl_En_Fr",
    "ovl_En_Fu",
    "ovl_En_Fw",
    "ovl_En_Fz",
    "ovl_En_G_Switch",
    "ovl_En_Ganon_Mant",
    "ovl_En_Ganon_Organ",
    "ovl_En_Gb",
    "ovl_En_Ge1",
    "ovl_En_Ge2",
    "ovl_En_Ge3",
    "ovl_En_GeldB",
    "ovl_En_GirlA",
    "ovl_En_Gm",
    "ovl_En_Go",
    "ovl_En_Go2",
    "ovl_En_Goma",
    "ovl_En_Goroiwa",
    "ovl_En_Gs",
    "ovl_En_Guest",
    "ovl_En_Hata",
    "ovl_En_Heishi1",
    "ovl_En_Heishi2",
    "ovl_En_Heishi3",
    "ovl_En_Heishi4",
    "ovl_En_Hintnuts",
    "ovl_En_Holl",
    "ovl_En_Honotrap",
    "ovl_En_Horse",
    "ovl_En_Horse_Game_Check",
    "ovl_En_Horse_Ganon",
    "ovl_En_Horse_Link_Child",
    "ovl_En_Horse_Normal",
    "ovl_En_Horse_Zelda",
    "ovl_En_Hs",
    "ovl_En_Hs2",
    "ovl_En_Hy",
    "ovl_En_Ice_Hono",
    "ovl_En_Ik",
    "ovl_En_In",
    "ovl_En_Insect",
    "ovl_En_Ishi",
    "ovl_En_It",
    "ovl_En_Jj",
    "ovl_En_Js",
    "ovl_En_Jsjutan",
    "ovl_En_Kakasi",
    "ovl_En_Kakasi2",
    "ovl_En_Kakasi3",
    "ovl_En_Kanban",
    "ovl_En_Karebaba",
    "ovl_En_Ko",
    "ovl_En_Kusa",
    "ovl_En_Kz",
    "ovl_En_Light",
    "ovl_En_Lightbox",
    "ovl_En_M_Fire1",
    "ovl_En_M_Thunder",
    "ovl_En_Ma1",
    "ovl_En_Ma2",
    "ovl_En_Ma3",
    "ovl_En_Mag",
    "ovl_En_Mb",
    "ovl_En_Md",
    "ovl_En_Mk",
    "ovl_En_Mm",
    "ovl_En_Mm2",
    "ovl_En_Ms",
    "ovl_En_Mu",
    "ovl_En_Nb",
    "ovl_En_Niw",
    "ovl_En_Niw_Girl",
    "ovl_En_Niw_Lady",
    "ovl_En_Nutsball",
    "ovl_En_Nwc",
    "ovl_En_Ny",
    "ovl_En_OE2",
    "ovl_En_Okarina_Effect",
    "ovl_En_Okarina_Tag",
    "ovl_En_Okuta",
    "ovl_En_Ossan",
    "ovl_En_Owl",
    "ovl_En_Part",
    "ovl_En_Peehat",
    "ovl_En_Po_Desert",
    "ovl_En_Po_Field",
    "ovl_En_Po_Relay",
    "ovl_En_Po_Sisters",
    "ovl_En_Poh",
    "ovl_En_Pu_box",
    "ovl_En_Rd",
    "ovl_En_Reeba",
    "ovl_En_River_Sound",
    "ovl_En_Rl",
    "ovl_En_Rr",
    "ovl_En_Ru1",
    "ovl_En_Ru2",
    "ovl_En_Sa",
    "ovl_En_Sb",
    "ovl_En_Scene_Change",
    "ovl_En_Sda",
    "ovl_En_Shopnuts",
    "ovl_En_Si",
    "ovl_En_Siofuki",
    "ovl_En_Skb",
    "ovl_En_Skj",
    "ovl_En_Skjneedle",
    "ovl_En_Ssh",
    "ovl_En_St",
    "ovl_En_Sth",
    "ovl_En_Stream",
    "ovl_En_Sw",
    "ovl_En_Syateki_Itm",
    "ovl_En_Syateki_Man",
    "ovl_En_Syateki_Niw",
    "ovl_En_Ta",
    "ovl_En_Takara_Man",
    "ovl_En_Tana",
    "ovl_En_Tg",
    "ovl_En_Tite",
    "ovl_En_Tk",
    "ovl_En_Torch",
    "ovl_En_Torch2",
    "ovl_En_Toryo",
    "ovl_En_Tp",
    "ovl_En_Tr",
    "ovl_En_Trap",
    "ovl_En_Tubo_Trap",
    "ovl_En_Vali",
    "ovl_En_Vase",
    "ovl_En_Vb_Ball",
    "ovl_En_Viewer",
    "ovl_En_Vm",
    "ovl_En_Wall_Tubo",
    "ovl_En_Wallmas",
    "ovl_En_Weather_Tag",
    "ovl_En_Weiyer",
    "ovl_En_Wf",
    "ovl_En_Wonder_Item",
    "ovl_En_Wonder_Talk",
    "ovl_En_Wonder_Talk2",
    "ovl_En_Wood02",
    "ovl_En_Xc",
    "ovl_En_Yabusame_Mark",
    "ovl_En_Yukabyun",
    "ovl_En_Zf",
    "ovl_En_Zl1",
    "ovl_En_Zl2",
    "ovl_En_Zl3",
    "ovl_En_Zl4",
    "ovl_En_Zo",
    "ovl_En_fHG",
    "ovl_End_Title",
    "ovl_Fishing",
    "ovl_Item_B_Heart",
    "ovl_Item_Etcetera",
    "ovl_Item_Inbox",
    "ovl_Item_Ocarina",
    "ovl_Item_Shield",
    "ovl_Magic_Dark",
    "ovl_Magic_Fire",
    "ovl_Magic_Wind",
    "ovl_Mir_Ray",
    "ovl_Obj_Bean",
    "ovl_Obj_Blockstop",
    "ovl_Obj_Bombiwa",
    "ovl_Obj_Comb",
    "ovl_Obj_Dekujr",
    "ovl_Obj_Elevator",
    "ovl_Obj_Hamishi",
    "ovl_Obj_Hana",
    "ovl_Obj_Hsblock",
    "ovl_Obj_Ice_Poly",
    "ovl_Obj_Kibako",
    "ovl_Obj_Kibako2",
    "ovl_Obj_Lift",
    "ovl_Obj_Lightswitch",
    "ovl_Obj_Makekinsuta",
    "ovl_Obj_Makeoshihiki",
    "ovl_Obj_Mure",
    "ovl_Obj_Mure2",
    "ovl_Obj_Mure3",
    "ovl_Obj_Oshihiki",
    "ovl_Obj_Roomtimer",
    "ovl_Obj_Switch",
    "ovl_Obj_Syokudai",
    "ovl_Obj_Timeblock",
    "ovl_Obj_Tsubo",
    "ovl_Obj_Warp2block",
    "ovl_Object_Kankyo",
    "ovl_Oceff_Spot",
    "ovl_Oceff_Storm",
    "ovl_Oceff_Wipe",
    "ovl_Oceff_Wipe2",
    "ovl_Oceff_Wipe3",
    "ovl_Oceff_Wipe4",
    "ovl_Shot_Sun",
    "gameplay_keep",
    "gameplay_field_keep",
    "gameplay_dangeon_keep",
    "gameplay_object_exchange_static",
    "object_link_boy",
    "object_link_child",
    "object_box",
    "object_human",
    "object_okuta",
    "object_poh",
    "object_wallmaster",
    "object_dy_obj",
    "object_firefly",
    "object_dodongo",
    "object_fire",
    "object_niw",
    "object_tite",
    "object_reeba",
    "object_peehat",
    "object_kingdodongo",
    "object_horse",
    "object_zf",
    "object_goma",
    "object_zl1",
    "object_gol",
    "object_bubble",
    "object_dodojr",
    "object_torch2",
    "object_bl",
    "object_tp",
    "object_oA1",
    "object_st",
    "object_bw",
    "object_ei",
    "object_horse_normal",
    "object_oB1",
    "object_o_anime",
    "object_spot04_objects",
    "object_ddan_objects",
    "object_hidan_objects",
    "object_horse_ganon",
    "object_oA2",
    "object_spot00_objects",
    "object_mb",
    "object_bombf",
    "object_sk2",
    "object_oE1",
    "object_oE_anime",
    "object_oE2",
    "object_ydan_objects",
    "object_gnd",
    "object_am",
    "object_dekubaba",
    "object_oA3",
    "object_oA4",
    "object_oA5",
    "object_oA6",
    "object_oA7",
    "object_jj",
    "object_oA8",
    "object_oA9",
    "object_oB2",
    "object_oB3",
    "object_oB4",
    "object_horse_zelda",
    "object_opening_demo1",
    "object_warp1",
    "object_b_heart",
    "object_dekunuts",
    "object_oE3",
    "object_oE4",
    "object_menkuri_objects",
    "object_oE5",
    "object_oE6",
    "object_oE7",
    "object_oE8",
    "object_oE9",
    "object_oE10",
    "object_oE11",
    "object_oE12",
    "object_vali",
    "object_oA10",
    "object_oA11",
    "object_mizu_objects",
    "object_fhg",
    "object_ossan",
    "object_mori_hineri1",
    "object_Bb",
    "object_toki_objects",
    "object_yukabyun",
    "object_zl2",
    "object_mjin",
    "object_mjin_flash",
    "object_mjin_dark",
    "object_mjin_flame",
    "object_mjin_ice",
    "object_mjin_soul",
    "object_mjin_wind",
    "object_mjin_oka",
    "object_haka_objects",
    "object_spot06_objects",
    "object_ice_objects",
    "object_relay_objects",
    "object_mori_hineri1a",
    "object_mori_hineri2",
    "object_mori_hineri2a",
    "object_mori_objects",
    "object_mori_tex",
    "object_spot08_obj",
    "object_warp2",
    "object_hata",
    "object_bird",
    "object_wood02",
    "object_lightbox",
    "object_pu_box",
    "object_trap",
    "object_vase",
    "object_im",
    "object_ta",
    "object_tk",
    "object_xc",
    "object_vm",
    "object_bv",
    "object_hakach_objects",
    "object_efc_crystal_light",
    "object_efc_fire_ball",
    "object_efc_flash",
    "object_efc_lgt_shower",
    "object_efc_star_field",
    "object_god_lgt",
    "object_light_ring",
    "object_triforce_spot",
    "object_medal",
    "object_bdan_objects",
    "object_sd",
    "object_rd",
    "object_po_sisters",
    "object_heavy_object",
    "object_gndd",
    "object_fd",
    "object_du",
    "object_fw",
    "object_horse_link_child",
    "object_spot02_objects",
    "object_haka",
    "object_ru1",
    "object_syokudai",
    "object_fd2",
    "object_dh",
    "object_rl",
    "object_efc_tw",
    "object_demo_tre_lgt",
    "object_gi_key",
    "object_mir_ray",
    "object_brob",
    "object_gi_jewel",
    "object_spot09_obj",
    "object_spot18_obj",
    "object_bdoor",
    "object_spot17_obj",
    "object_shop_dungen",
    "object_nb",
    "object_mo",
    "object_sb",
    "object_gi_melody",
    "object_gi_heart",
    "object_gi_compass",
    "object_gi_bosskey",
    "object_gi_medal",
    "object_gi_nuts",
    "object_sa",
    "object_gi_hearts",
    "object_gi_arrowcase",
    "object_gi_bombpouch",
    "object_in",
    "object_tr",
    "object_spot16_obj",
    "object_oE1s",
    "object_oE4s",
    "object_os_anime",
    "object_gi_bottle",
    "object_gi_stick",
    "object_gi_map",
    "object_oF1d_map",
    "object_ru2",
    "object_gi_shield_1",
    "object_dekujr",
    "object_gi_magicpot",
    "object_gi_bomb_1",
    "object_oF1s",
    "object_ma2",
    "object_gi_purse",
    "object_hni",
    "object_tw",
    "object_rr",
    "object_bxa",
    "object_anubice",
    "object_gi_gerudo",
    "object_gi_arrow",
    "object_gi_bomb_2",
    "object_gi_egg",
    "object_gi_scale",
    "object_gi_shield_2",
    "object_gi_hookshot",
    "object_gi_ocarina",
    "object_gi_milk",
    "object_ma1",
    "object_ganon",
    "object_sst",
    "object_ny",
    "object_fr",
    "object_gi_pachinko",
    "object_gi_boomerang",
    "object_gi_bow",
    "object_gi_glasses",
    "object_gi_liquid",
    "object_ani",
    "object_demo_6k",
    "object_gi_shield_3",
    "object_gi_letter",
    "object_spot15_obj",
    "object_jya_obj",
    "object_gi_clothes",
    "object_gi_bean",
    "object_gi_fish",
    "object_gi_saw",
    "object_gi_hammer",
    "object_gi_grass",
    "object_gi_longsword",
    "object_spot01_objects",
    "object_md",
    "object_km1",
    "object_kw1",
    "object_zo",
    "object_kz",
    "object_umajump",
    "object_masterkokiri",
    "object_masterkokirihead",
    "object_mastergolon",
    "object_masterzoora",
    "object_aob",
    "object_ik",
    "object_ahg",
    "object_cne",
    "object_gi_niwatori",
    "object_skj",
    "object_gi_bottle_letter",
    "object_bji",
    "object_bba",
    "object_gi_ocarina_0",
    "object_ds",
    "object_ane",
    "object_boj",
    "object_spot03_object",
    "object_spot07_object",
    "object_fz",
    "object_bob",
    "object_ge1",
    "object_yabusame_point",
    "object_gi_boots_2",
    "object_gi_seed",
    "object_gnd_magic",
    "object_d_elevator",
    "object_d_hsblock",
    "object_d_lift",
    "object_mamenoki",
    "object_goroiwa",
    "object_toryo",
    "object_daiku",
    "object_nwc",
    "object_blkobj",
    "object_gm",
    "object_ms",
    "object_hs",
    "object_ingate",
    "object_lightswitch",
    "object_kusa",
    "object_tsubo",
    "object_gi_gloves",
    "object_gi_coin",
    "object_kanban",
    "object_gjyo_objects",
    "object_owl",
    "object_mk",
    "object_fu",
    "object_gi_ki_tan_mask",
    "object_gi_redead_mask",
    "object_gi_skj_mask",
    "object_gi_rabit_mask",
    "object_gi_truth_mask",
    "object_ganon_objects",
    "object_siofuki",
    "object_stream",
    "object_mm",
    "object_fa",
    "object_os",
    "object_gi_eye_lotion",
    "object_gi_powder",
    "object_gi_mushroom",
    "object_gi_ticketstone",
    "object_gi_brokensword",
    "object_js",
    "object_cs",
    "object_gi_prescription",
    "object_gi_bracelet",
    "object_gi_soldout",
    "object_gi_frog",
    "object_mag",
    "object_door_gerudo",
    "object_gt",
    "object_efc_erupc",
    "object_zl2_anime1",
    "object_zl2_anime2",
    "object_gi_golonmask",
    "object_gi_zoramask",
    "object_gi_gerudomask",
    "object_ganon2",
    "object_ka",
    "object_ts",
    "object_zg",
    "object_gi_hoverboots",
    "object_gi_m_arrow",
    "object_ds2",
    "object_ec",
    "object_fish",
    "object_gi_sutaru",
    "object_gi_goddess",
    "object_ssh",
    "object_bigokuta",
    "object_bg",
    "object_spot05_objects",
    "object_spot12_obj",
    "object_bombiwa",
    "object_hintnuts",
    "object_rs",
    "object_spot00_break",
    "object_gla",
    "object_shopnuts",
    "object_geldb",
    "object_gr",
    "object_dog",
    "object_jya_iron",
    "object_jya_door",
    "object_spot01_objects2",
    "object_spot11_obj",
    "object_kibako2",
    "object_dns",
    "object_dnk",
    "object_gi_fire",
    "object_gi_insect",
    "object_gi_butterfly",
    "object_gi_ghost",
    "object_gi_soul",
    "object_bowl",
    "object_po_field",
    "object_demo_kekkai",
    "object_efc_doughnut",
    "object_gi_dekupouch",
    "object_ganon_anime1",
    "object_ganon_anime2",
    "object_ganon_anime3",
    "object_gi_rupy",
    "object_spot01_matoya",
    "object_spot01_matoyab",
    "object_po_composer",
    "object_mu",
    "object_wf",
    "object_skb",
    "object_gj",
    "object_geff",
    "object_haka_door",
    "object_gs",
    "object_ps",
    "object_bwall",
    "object_crow",
    "object_cow",
    "object_cob",
    "object_gi_sword_1",
    "object_door_killer",
    "object_ouke_haka",
    "object_timeblock",
    "object_zl4",
    "g_pn_01",
    "g_pn_02",
    "g_pn_03",
    "g_pn_04",
    "g_pn_05",
    "g_pn_06",
    "g_pn_07",
    "g_pn_08",
    "g_pn_09",
    "g_pn_10",
    "g_pn_11",
    "g_pn_12",
    "g_pn_13",
    "g_pn_14",
    "g_pn_15",
    "g_pn_16",
    "g_pn_17",
    "g_pn_18",
    "g_pn_19",
    "g_pn_20",
    "g_pn_21",
    "g_pn_22",
    "g_pn_23",
    "g_pn_24",
    "g_pn_25",
    "g_pn_26",
    "g_pn_27",
    "g_pn_28",
    "g_pn_29",
    "g_pn_30",
    "g_pn_31",
    "g_pn_32",
    "g_pn_33",
    "g_pn_34",
    "g_pn_35",
    "g_pn_36",
    "g_pn_37",
    "g_pn_38",
    "g_pn_39",
    "g_pn_40",
    "g_pn_41",
    "g_pn_42",
    "g_pn_43",
    "g_pn_44",
    "g_pn_45",
    "g_pn_46",
    "g_pn_47",
    "g_pn_48",
    "g_pn_49",
    "g_pn_50",
    "g_pn_51",
    "g_pn_52",
    "g_pn_53",
    "g_pn_54",
    "g_pn_55",
    "g_pn_56",
    "g_pn_57",
    "z_select_static",
    "nintendo_rogo_static",
    "title_static",
    "parameter_static",
    "vr_fine0_static",
    "vr_fine0_pal_static",
    "vr_fine1_static",
    "vr_fine1_pal_static",
    "vr_fine2_static",
    "vr_fine2_pal_static",
    "vr_fine3_static",
    "vr_fine3_pal_static",
    "vr_cloud0_static",
    "vr_cloud0_pal_static",
    "vr_cloud1_static",
    "vr_cloud1_pal_static",
    "vr_cloud2_static",
    "vr_cloud2_pal_static",
    "vr_cloud3_static",
    "vr_cloud3_pal_static",
    "vr_holy0_static",
    "vr_holy0_pal_static",
    "vr_holy1_static",
    "vr_holy1_pal_static",
    "vr_MDVR_static",
    "vr_MDVR_pal_static",
    "vr_MNVR_static",
    "vr_MNVR_pal_static",
    "vr_RUVR_static",
    "vr_RUVR_pal_static",
    "vr_LHVR_static",
    "vr_LHVR_pal_static",
    "vr_KHVR_static",
    "vr_KHVR_pal_static",
    "vr_K3VR_static",
    "vr_K3VR_pal_static",
    "vr_K4VR_static",
    "vr_K4VR_pal_static",
    "vr_K5VR_static",
    "vr_K5VR_pal_static",
    "vr_SP1a_static",
    "vr_SP1a_pal_static",
    "vr_MLVR_static",
    "vr_MLVR_pal_static",
    "vr_KKRVR_static",
    "vr_KKRVR_pal_static",
    "vr_KR3VR_static",
    "vr_KR3VR_pal_static",
    "vr_IPVR_static",
    "vr_IPVR_pal_static",
    "vr_KSVR_static",
    "vr_KSVR_pal_static",
    "vr_GLVR_static",
    "vr_GLVR_pal_static",
    "vr_ZRVR_static",
    "vr_ZRVR_pal_static",
    "vr_DGVR_static",
    "vr_DGVR_pal_static",
    "vr_ALVR_static",
    "vr_ALVR_pal_static",
    "vr_NSVR_static",
    "vr_NSVR_pal_static",
    "vr_LBVR_static",
    "vr_LBVR_pal_static",
    "vr_TTVR_static",
    "vr_TTVR_pal_static",
    "vr_FCVR_static",
    "vr_FCVR_pal_static",
    "elf_message_field",
    "elf_message_ydan",
    "syotes_scene",
    "syotes_room_0",
    "syotes2_scene",
    "syotes2_room_0",
    "depth_test_scene",
    "depth_test_room_0",
    "spot00_scene",
    "spot00_room_0",
    "spot01_scene",
    "spot01_room_0",
    "spot02_scene",
    "spot02_room_0",
    "spot02_room_1",
    "spot03_scene",
    "spot03_room_0",
    "spot03_room_1",
    "spot04_scene",
    "spot04_room_0",
    "spot04_room_1",
    "spot04_room_2",
    "spot05_scene",
    "spot05_room_0",
    "spot06_scene",
    "spot06_room_0",
    "spot07_scene",
    "spot07_room_0",
    "spot07_room_1",
    "spot08_scene",
    "spot08_room_0",
    "spot09_scene",
    "spot09_room_0",
    "spot10_scene",
    "spot10_room_0",
    "spot10_room_1",
    "spot10_room_2",
    "spot10_room_3",
    "spot10_room_4",
    "spot10_room_5",
    "spot10_room_6",
    "spot10_room_7",
    "spot10_room_8",
    "spot10_room_9",
    "spot11_scene",
    "spot11_room_0",
    "spot12_scene",
    "spot12_room_0",
    "spot12_room_1",
    "spot13_scene",
    "spot13_room_0",
    "spot13_room_1",
    "spot15_scene",
    "spot15_room_0",
    "spot16_scene",
    "spot16_room_0",
    "spot17_scene",
    "spot17_room_0",
    "spot17_room_1",
    "spot18_scene",
    "spot18_room_0",
    "spot18_room_1",
    "spot18_room_2",
    "spot18_room_3",
    "ydan_scene",
    "ydan_room_0",
    "ydan_room_1",
    "ydan_room_2",
    "ydan_room_3",
    "ydan_room_4",
    "ydan_room_5",
    "ydan_room_6",
    "ydan_room_7",
    "ydan_room_8",
    "ydan_room_9",
    "ydan_room_10",
    "ydan_room_11",
    "ddan_scene",
    "ddan_room_0",
    "ddan_room_1",
    "ddan_room_2",
    "ddan_room_3",
    "ddan_room_4",
    "ddan_room_5",
    "ddan_room_6",
    "ddan_room_7",
    "ddan_room_8",
    "ddan_room_9",
    "ddan_room_10",
    "ddan_room_11",
    "ddan_room_12",
    "ddan_room_13",
    "ddan_room_14",
    "ddan_room_15",
    "ddan_room_16",
    "bdan_scene",
    "bdan_room_0",
    "bdan_room_1",
    "bdan_room_2",
    "bdan_room_3",
    "bdan_room_4",
    "bdan_room_5",
    "bdan_room_6",
    "bdan_room_7",
    "bdan_room_8",
    "bdan_room_9",
    "bdan_room_10",
    "bdan_room_11",
    "bdan_room_12",
    "bdan_room_13",
    "bdan_room_14",
    "bdan_room_15",
    "Bmori1_scene",
    "Bmori1_room_0",
    "Bmori1_room_1",
    "Bmori1_room_2",
    "Bmori1_room_3",
    "Bmori1_room_4",
    "Bmori1_room_5",
    "Bmori1_room_6",
    "Bmori1_room_7",
    "Bmori1_room_8",
    "Bmori1_room_9",
    "Bmori1_room_10",
    "Bmori1_room_11",
    "Bmori1_room_12",
    "Bmori1_room_13",
    "Bmori1_room_14",
    "Bmori1_room_15",
    "Bmori1_room_16",
    "Bmori1_room_17",
    "Bmori1_room_18",
    "Bmori1_room_19",
    "Bmori1_room_20",
    "Bmori1_room_21",
    "Bmori1_room_22",
    "HIDAN_scene",
    "HIDAN_room_0",
    "HIDAN_room_1",
    "HIDAN_room_2",
    "HIDAN_room_3",
    "HIDAN_room_4",
    "HIDAN_room_5",
    "HIDAN_room_6",
    "HIDAN_room_7",
    "HIDAN_room_8",
    "HIDAN_room_9",
    "HIDAN_room_10",
    "HIDAN_room_11",
    "HIDAN_room_12",
    "HIDAN_room_13",
    "HIDAN_room_14",
    "HIDAN_room_15",
    "HIDAN_room_16",
    "HIDAN_room_17",
    "HIDAN_room_18",
    "HIDAN_room_19",
    "HIDAN_room_20",
    "HIDAN_room_21",
    "HIDAN_room_22",
    "HIDAN_room_23",
    "HIDAN_room_24",
    "HIDAN_room_25",
    "HIDAN_room_26",
    "MIZUsin_scene",
    "MIZUsin_room_0",
    "MIZUsin_room_1",
    "MIZUsin_room_2",
    "MIZUsin_room_3",
    "MIZUsin_room_4",
    "MIZUsin_room_5",
    "MIZUsin_room_6",
    "MIZUsin_room_7",
    "MIZUsin_room_8",
    "MIZUsin_room_9",
    "MIZUsin_room_10",
    "MIZUsin_room_11",
    "MIZUsin_room_12",
    "MIZUsin_room_13",
    "MIZUsin_room_14",
    "MIZUsin_room_15",
    "MIZUsin_room_16",
    "MIZUsin_room_17",
    "MIZUsin_room_18",
    "MIZUsin_room_19",
    "MIZUsin_room_20",
    "MIZUsin_room_21",
    "MIZUsin_room_22",
    "jyasinzou_scene",
    "jyasinzou_room_0",
    "jyasinzou_room_1",
    "jyasinzou_room_2",
    "jyasinzou_room_3",
    "jyasinzou_room_4",
    "jyasinzou_room_5",
    "jyasinzou_room_6",
    "jyasinzou_room_7",
    "jyasinzou_room_8",
    "jyasinzou_room_9",
    "jyasinzou_room_10",
    "jyasinzou_room_11",
    "jyasinzou_room_12",
    "jyasinzou_room_13",
    "jyasinzou_room_14",
    "jyasinzou_room_15",
    "jyasinzou_room_16",
    "jyasinzou_room_17",
    "jyasinzou_room_18",
    "jyasinzou_room_19",
    "jyasinzou_room_20",
    "jyasinzou_room_21",
    "jyasinzou_room_22",
    "jyasinzou_room_23",
    "jyasinzou_room_24",
    "jyasinzou_room_25",
    "jyasinzou_room_26",
    "jyasinzou_room_27",
    "jyasinzou_room_28",
    "HAKAdan_scene",
    "HAKAdan_room_0",
    "HAKAdan_room_1",
    "HAKAdan_room_2",
    "HAKAdan_room_3",
    "HAKAdan_room_4",
    "HAKAdan_room_5",
    "HAKAdan_room_6",
    "HAKAdan_room_7",
    "HAKAdan_room_8",
    "HAKAdan_room_9",
    "HAKAdan_room_10",
    "HAKAdan_room_11",
    "HAKAdan_room_12",
    "HAKAdan_room_13",
    "HAKAdan_room_14",
    "HAKAdan_room_15",
    "HAKAdan_room_16",
    "HAKAdan_room_17",
    "HAKAdan_room_18",
    "HAKAdan_room_19",
    "HAKAdan_room_20",
    "HAKAdan_room_21",
    "HAKAdan_room_22",
    "HAKAdanCH_scene",
    "HAKAdanCH_room_0",
    "HAKAdanCH_room_1",
    "HAKAdanCH_room_2",
    "HAKAdanCH_room_3",
    "HAKAdanCH_room_4",
    "HAKAdanCH_room_5",
    "HAKAdanCH_room_6",
    "ice_doukutu_scene",
    "ice_doukutu_room_0",
    "ice_doukutu_room_1",
    "ice_doukutu_room_2",
    "ice_doukutu_room_3",
    "ice_doukutu_room_4",
    "ice_doukutu_room_5",
    "ice_doukutu_room_6",
    "ice_doukutu_room_7",
    "ice_doukutu_room_8",
    "ice_doukutu_room_9",
    "ice_doukutu_room_10",
    "ice_doukutu_room_11",
    "men_scene",
    "men_room_0",
    "men_room_1",
    "men_room_2",
    "men_room_3",
    "men_room_4",
    "men_room_5",
    "men_room_6",
    "men_room_7",
    "men_room_8",
    "men_room_9",
    "men_room_10",
    "ganontika_scene",
    "ganontika_room_0",
    "ganontika_room_1",
    "ganontika_room_2",
    "ganontika_room_3",
    "ganontika_room_4",
    "ganontika_room_5",
    "ganontika_room_6",
    "ganontika_room_7",
    "ganontika_room_8",
    "ganontika_room_9",
    "ganontika_room_10",
    "ganontika_room_11",
    "ganontika_room_12",
    "ganontika_room_13",
    "ganontika_room_14",
    "ganontika_room_15",
    "ganontika_room_16",
    "ganontika_room_17",
    "ganontika_room_18",
    "ganontika_room_19",
    "market_day_scene",
    "market_day_room_0",
    "market_night_scene",
    "market_night_room_0",
    "testroom_scene",
    "testroom_room_0",
    "testroom_room_1",
    "testroom_room_2",
    "testroom_room_3",
    "testroom_room_4",
    "kenjyanoma_scene",
    "kenjyanoma_room_0",
    "tokinoma_scene",
    "tokinoma_room_0",
    "tokinoma_room_1",
    "sutaru_scene",
    "sutaru_room_0",
    "link_home_scene",
    "link_home_room_0",
    "kokiri_shop_scene",
    "kokiri_shop_room_0",
    "kokiri_home_scene",
    "kokiri_home_room_0",
    "kakusiana_scene",
    "kakusiana_room_0",
    "kakusiana_room_1",
    "kakusiana_room_2",
    "kakusiana_room_3",
    "kakusiana_room_4",
    "kakusiana_room_5",
    "kakusiana_room_6",
    "kakusiana_room_7",
    "kakusiana_room_8",
    "kakusiana_room_9",
    "kakusiana_room_10",
    "kakusiana_room_11",
    "kakusiana_room_12",
    "kakusiana_room_13",
    "entra_scene",
    "entra_room_0",
    "moribossroom_scene",
    "moribossroom_room_0",
    "moribossroom_room_1",
    "syatekijyou_scene",
    "syatekijyou_room_0",
    "shop1_scene",
    "shop1_room_0",
    "hairal_niwa_scene",
    "hairal_niwa_room_0",
    "ganon_tou_scene",
    "ganon_tou_room_0",
    "sasatest_scene",
    "sasatest_room_0",
    "market_alley_scene",
    "market_alley_room_0",
    "spot20_scene",
    "spot20_room_0",
    "market_ruins_scene",
    "market_ruins_room_0",
    "entra_n_scene",
    "entra_n_room_0",
    "enrui_scene",
    "enrui_room_0",
    "market_alley_n_scene",
    "market_alley_n_room_0",
    "hiral_demo_scene",
    "hiral_demo_room_0",
    "kokiri_home3_scene",
    "kokiri_home3_room_0",
    "malon_stable_scene",
    "malon_stable_room_0",
    "kakariko_scene",
    "kakariko_room_0",
    "bdan_boss_scene",
    "bdan_boss_room_0",
    "bdan_boss_room_1",
    "FIRE_bs_scene",
    "FIRE_bs_room_0",
    "FIRE_bs_room_1",
    "hut_scene",
    "hut_room_0",
    "daiyousei_izumi_scene",
    "daiyousei_izumi_room_0",
    "hakaana_scene",
    "hakaana_room_0",
    "yousei_izumi_tate_scene",
    "yousei_izumi_tate_room_0",
    "yousei_izumi_yoko_scene",
    "yousei_izumi_yoko_room_0",
    "golon_scene",
    "golon_room_0",
    "zoora_scene",
    "zoora_room_0",
    "drag_scene",
    "drag_room_0",
    "alley_shop_scene",
    "alley_shop_room_0",
    "night_shop_scene",
    "night_shop_room_0",
    "impa_scene",
    "impa_room_0",
    "labo_scene",
    "labo_room_0",
    "tent_scene",
    "tent_room_0",
    "nakaniwa_scene",
    "nakaniwa_room_0",
    "ddan_boss_scene",
    "ddan_boss_room_0",
    "ddan_boss_room_1",
    "ydan_boss_scene",
    "ydan_boss_room_0",
    "ydan_boss_room_1",
    "HAKAdan_bs_scene",
    "HAKAdan_bs_room_0",
    "HAKAdan_bs_room_1",
    "MIZUsin_bs_scene",
    "MIZUsin_bs_room_0",
    "MIZUsin_bs_room_1",
    "ganon_scene",
    "ganon_room_0",
    "ganon_room_1",
    "ganon_room_2",
    "ganon_room_3",
    "ganon_room_4",
    "ganon_room_5",
    "ganon_room_6",
    "ganon_room_7",
    "ganon_room_8",
    "ganon_room_9",
    "ganon_boss_scene",
    "ganon_boss_room_0",
    "jyasinboss_scene",
    "jyasinboss_room_0",
    "jyasinboss_room_1",
    "jyasinboss_room_2",
    "jyasinboss_room_3",
    "kokiri_home4_scene",
    "kokiri_home4_room_0",
    "kokiri_home5_scene",
    "kokiri_home5_room_0",
    "ganon_final_scene",
    "ganon_final_room_0",
    "kakariko3_scene",
    "kakariko3_room_0",
    "hairal_niwa2_scene",
    "hairal_niwa2_room_0",
    "hakasitarelay_scene",
    "hakasitarelay_room_0",
    "hakasitarelay_room_1",
    "hakasitarelay_room_2",
    "hakasitarelay_room_3",
    "hakasitarelay_room_4",
    "hakasitarelay_room_5",
    "hakasitarelay_room_6",
    "shrine_scene",
    "shrine_room_0",
    "turibori_scene",
    "turibori_room_0",
    "shrine_n_scene",
    "shrine_n_room_0",
    "shrine_r_scene",
    "shrine_r_room_0",
    "hakaana2_scene",
    "hakaana2_room_0",
    "gerudoway_scene",
    "gerudoway_room_0",
    "gerudoway_room_1",
    "gerudoway_room_2",
    "gerudoway_room_3",
    "gerudoway_room_4",
    "gerudoway_room_5",
    "hairal_niwa_n_scene",
    "hairal_niwa_n_room_0",
    "bowling_scene",
    "bowling_room_0",
    "hakaana_ouke_scene",
    "hakaana_ouke_room_0",
    "hakaana_ouke_room_1",
    "hakaana_ouke_room_2",
    "hylia_labo_scene",
    "hylia_labo_room_0",
    "souko_scene",
    "souko_room_0",
    "souko_room_1",
    "souko_room_2",
    "miharigoya_scene",
    "miharigoya_room_0",
    "mahouya_scene",
    "mahouya_room_0",
    "takaraya_scene",
    "takaraya_room_0",
    "takaraya_room_1",
    "takaraya_room_2",
    "takaraya_room_3",
    "takaraya_room_4",
    "takaraya_room_5",
    "takaraya_room_6",
    "ganon_sonogo_scene",
    "ganon_sonogo_room_0",
    "ganon_sonogo_room_1",
    "ganon_sonogo_room_2",
    "ganon_sonogo_room_3",
    "ganon_sonogo_room_4",
    "ganon_demo_scene",
    "ganon_demo_room_0",
    "besitu_scene",
    "besitu_room_0",
    "face_shop_scene",
    "face_shop_room_0",
    "kinsuta_scene",
    "kinsuta_room_0",
    "ganontikasonogo_scene",
    "ganontikasonogo_room_0",
    "ganontikasonogo_room_1",
    "test01_scene",
    "test01_room_0",
    "bump_texture_static",
    "anime_model_1_static",
    "anime_model_2_static",
    "anime_model_3_static",
    "anime_model_4_static",
    "anime_model_5_static",
    "anime_model_6_static",
    "anime_texture_1_static",
    "anime_texture_2_static",
    "anime_texture_3_static",
    "anime_texture_4_static",
    "anime_texture_5_static",
    "anime_texture_6_static",
    "softsprite_matrix_static",
};

s32 DmaMgr_CompareName(const char* name1, const char* name2) {
    while (*name1 != 0u) {
        if (*name1 > *name2) {
            return 1;
        }

        if (*name1 < *name2) {
            return -1;
        }

        name1++;
        name2++;
    }

    if (*name2 > 0) {
        return -1;
    }

    return 0;
}

s32 DmaMgr_DMARomToRam(u32 rom, u32 ram, u32 size) {
    OSIoMesg ioMsg;
    OSMesgQueue queue;
    OSMesg msg;
    s32 ret;
    u32 buffSize = gDmaMgrDmaBuffSize;
    s32 pad[2];

    if (buffSize == 0) {
        buffSize = 0x2000;
    }

    osInvalICache((void*)ram, size);
    osInvalDCache((void*)ram, size);
    osCreateMesgQueue(&queue, &msg, 1);

    while (size > buffSize) {
        if (1) {} // Necessary to match

        ioMsg.hdr.pri = OS_MESG_PRI_NORMAL;
        ioMsg.hdr.retQueue = &queue;
        ioMsg.devAddr = rom;
        ioMsg.dramAddr = (void*)ram;
        ioMsg.size = buffSize;

        if (D_80009460 == 10) {
            osSyncPrintf("%10lld ノーマルＤＭＡ %08x %08x %08x (%d)\n", OS_CYCLES_TO_USEC(osGetTime()), ioMsg.dramAddr,
                         ioMsg.devAddr, ioMsg.size, gPiMgrCmdQ.validCount);
        }

        ret = osEPiStartDma(gCartHandle, &ioMsg, OS_READ);
        if (ret) {
            goto DmaMgr_DMARomToRam_end;
        }

        if (D_80009460 == 10) {
            osSyncPrintf("%10lld ノーマルＤＭＡ START (%d)\n", OS_CYCLES_TO_USEC(osGetTime()), gPiMgrCmdQ.validCount);
        }

        osRecvMesg(&queue, NULL, 1);
        if (D_80009460 == 10) {
            osSyncPrintf("%10lld ノーマルＤＭＡ END (%d)\n", OS_CYCLES_TO_USEC(osGetTime()), gPiMgrCmdQ.validCount);
        }

        size -= buffSize;
        rom += buffSize;
        ram += buffSize;
    }

    if (1) {} // Also necessary to match

    ioMsg.hdr.pri = OS_MESG_PRI_NORMAL;
    ioMsg.hdr.retQueue = &queue;
    ioMsg.devAddr = rom;
    ioMsg.dramAddr = (void*)ram;
    ioMsg.size = size;

    if (D_80009460 == 10) {
        osSyncPrintf("%10lld ノーマルＤＭＡ %08x %08x %08x (%d)\n", OS_CYCLES_TO_USEC(osGetTime()), ioMsg.dramAddr,
                     ioMsg.devAddr, ioMsg.size, gPiMgrCmdQ.validCount);
    }

    ret = osEPiStartDma(gCartHandle, &ioMsg, OS_READ);
    if (ret) {
        goto DmaMgr_DMARomToRam_end;
    }

    osRecvMesg(&queue, NULL, 1);
    if (D_80009460 == 10) {
        osSyncPrintf("%10lld ノーマルＤＭＡ END (%d)\n", OS_CYCLES_TO_USEC(osGetTime()), gPiMgrCmdQ.validCount);
    }

DmaMgr_DMARomToRam_end:
    osInvalICache((void*)ram, size);
    osInvalDCache((void*)ram, size);

    return ret;
}

s32 DmaMgr_DmaCallback0(OSPiHandle* pihandle, OSIoMesg* mb, s32 direction) {
    s32 ret;

    ASSERT(pihandle == gCartHandle, "pihandle == carthandle", "../z_std_dma.c", 530);
    ASSERT(direction == OS_READ, "direction == OS_READ", "../z_std_dma.c", 531);
    ASSERT(mb != NULL, "mb != NULL", "../z_std_dma.c", 532);

    if (D_80009460 == 10) {
        osSyncPrintf("%10lld サウンドＤＭＡ %08x %08x %08x (%d)\n", OS_CYCLES_TO_USEC(osGetTime()), mb->dramAddr,
                     mb->devAddr, mb->size, gPiMgrCmdQ.validCount);
    }

    ret = osEPiStartDma(pihandle, mb, direction);
    if (ret) {
        osSyncPrintf("OOPS!!\n");
    }
    return ret;
}

void DmaMgr_DmaCallback1(u32 ram, u32 rom, u32 size) {
    OSPiHandle* handle = osDriveRomInit();
    OSMesgQueue queue;
    OSMesg msg;
    OSIoMesg ioMsg;

    osInvalICache((void*)ram, size);
    osInvalDCache((void*)ram, size);
    osCreateMesgQueue(&queue, &msg, 1);

    ioMsg.hdr.retQueue = &queue;
    ioMsg.hdr.pri = OS_MESG_PRI_NORMAL;
    ioMsg.devAddr = rom;
    ioMsg.dramAddr = (void*)ram;
    ioMsg.size = size;
    handle->transferInfo.cmdType = 2;

    osEPiStartDma(handle, &ioMsg, 0);
    osRecvMesg(&queue, NULL, OS_MESG_BLOCK);
    return;
}

void DmaMgr_Error(DmaRequest* req, const char* file, const char* errorName, const char* errorDesc) {
    u32 vrom = req->vromAddr;
    u32 ram = (u32)req->dramAddr;
    u32 size = req->size;
    char buff1[80];
    char buff2[80];

    osSyncPrintf("%c", 7);
    osSyncPrintf(VT_FGCOL(RED));
    osSyncPrintf("DMA致命的エラー(%s)\nROM:%X RAM:%X SIZE:%X %s\n",
                 errorDesc != NULL ? errorDesc : (errorName != NULL ? errorName : "???"), vrom, ram, size,
                 file != NULL ? file : "???");

    if (req->filename) {
        osSyncPrintf("DMA ERROR: %s %d", req->filename, req->line);
    } else if (sDmaMgrCurFileName) {
        osSyncPrintf("DMA ERROR: %s %d", sDmaMgrCurFileName, sDmaMgrCurFileLine);
    }

    osSyncPrintf(VT_RST);

    if (req->filename) {
        sprintf(buff1, "DMA ERROR: %s %d", req->filename, req->line);
    } else if (sDmaMgrCurFileName) {
        sprintf(buff1, "DMA ERROR: %s %d", sDmaMgrCurFileName, sDmaMgrCurFileLine);
    } else {
        sprintf(buff1, "DMA ERROR: %s", errorName != NULL ? errorName : "???");
    }

    sprintf(buff2, "%07X %08X %X %s", vrom, ram, size, file != NULL ? file : "???");
    Fault_AddHungupAndCrashImpl(buff1, buff2);
}

const char* DmaMgr_GetFileNameImpl(u32 vrom) {
    DmaEntry* iter = gDmaDataTable;
    const char** name = sDmaMgrFileNames;

    while (iter->vromEnd) {
        if (vrom >= iter->vromStart && vrom < iter->vromEnd) {
            return *name;
        }

        iter++;
        name++;
    }
    //! @bug Since there is no return, in case the file isn't found, the return value will be a pointer to the end
    // of gDmaDataTable
}

const char* DmaMgr_GetFileName(u32 vrom) {
    const char* ret = DmaMgr_GetFileNameImpl(vrom);

    if (ret == NULL) {
        return "(unknown)";
    }

    if (DmaMgr_CompareName(ret, "kanji") == 0 || DmaMgr_CompareName(ret, "link_animetion") == 0) {
        return NULL;
    }

    return ret;
}

void DmaMgr_ProcessMsg(DmaRequest* req) {
    u32 vrom = req->vromAddr;
    void* ram = req->dramAddr;
    u32 size = req->size;
    u32 romStart;
    u32 romSize;
    u8 found = false;
    DmaEntry* iter;
    const char* filename;

    if (0) {
        // the string is defined in .rodata but not used, suggesting
        // a debug print is here but optimized out in some way
        osSyncPrintf("DMA ROM:%08X RAM:%08X SIZE:%08X %s\n");
        // the last arg of this print looks like it may be filename, but
        // filename above this block does not match
    }

    filename = DmaMgr_GetFileName(vrom);
    iter = gDmaDataTable;

    while (iter->vromEnd) {
        if (vrom >= iter->vromStart && vrom < iter->vromEnd) {
            if (1) {} // Necessary to match

            if (iter->romEnd == 0) {
                if (iter->vromEnd < vrom + size) {
                    DmaMgr_Error(req, filename, "Segment Alignment Error",
                                 "セグメント境界をまたがってＤＭＡ転送することはできません");
                }

                DmaMgr_DMARomToRam(iter->romStart + (vrom - iter->vromStart), (u32)ram, size);
                found = true;

                if (0) {
                    osSyncPrintf("No Press ROM:%08X RAM:%08X SIZE:%08X\n", vrom, ram, size);
                }
            } else {
                romStart = iter->romStart;
                romSize = iter->romEnd - iter->romStart;

                if (vrom != iter->vromStart) {
                    DmaMgr_Error(req, filename, "Can't Transfer Segment",
                                 "圧縮されたセグメントの途中からはＤＭＡ転送することはできません");
                }

                if (size != iter->vromEnd - iter->vromStart) {
                    DmaMgr_Error(req, filename, "Can't Transfer Segment",
                                 "圧縮されたセグメントの一部だけをＤＭＡ転送することはできません");
                }

                osSetThreadPri(NULL, Z_PRIORITY_MAIN);
                Yaz0_Decompress(romStart, ram, romSize);
                osSetThreadPri(NULL, Z_PRIORITY_DMAMGR);
                found = true;

                if (0) {
                    osSyncPrintf("   Press ROM:%X RAM:%X SIZE:%X\n", vrom, ram, size);
                }
            }
            break;
        }
        iter++;
    }

    if (!found) {
        if (sDmaMgrDataExistError) {
            DmaMgr_Error(req, NULL, "DATA DON'T EXIST", "該当するデータが存在しません");
            return;
        }

        DmaMgr_DMARomToRam(vrom, (u32)ram, size);

        if (0) {
            osSyncPrintf("No Press ROM:%08X RAM:%08X SIZE:%08X (非公式)\n", vrom, ram, size);
        }
    }
}

void DmaMgr_ThreadEntry(void* arg0) {
    OSMesg msg;
    DmaRequest* req;

    osSyncPrintf("ＤＭＡマネージャスレッド実行開始\n");
    while (true) {
        osRecvMesg(&sDmaMgrMsgQueue, &msg, 1);
        req = (DmaRequest*)msg;
        if (req == NULL) {
            break;
        }

        if (0) {
            osSyncPrintf("ＤＭＡ登録受付 dmap=%08x\n", req);
        }

        DmaMgr_ProcessMsg(req);
        if (req->notifyQueue) {
            osSendMesg(req->notifyQueue, req->notifyMsg, OS_MESG_NOBLOCK);
            if (0) {
                osSyncPrintf("osSendMesg: dmap=%08x, mq=%08x, m=%08x \n", req, req->notifyQueue, req->notifyMsg);
            }
        }
    }
    osSyncPrintf("ＤＭＡマネージャスレッド実行終了\n");
}

s32 DmaMgr_SendRequestImpl(DmaRequest* req, u32 ram, u32 vrom, u32 size, u32 unk, OSMesgQueue* queue, OSMesg msg) {
    static s32 sDmaMgrQueueFullLogged = 0;

    if ((1 && (ram == 0)) || (osMemSize < ram + size + 0x80000000) || (vrom & 1) || (vrom > 0x4000000) ||
        (size == 0) || (size & 1)) {
        DmaMgr_Error(req, NULL, "ILLIGAL DMA-FUNCTION CALL", "パラメータ異常です");
    }

    req->vromAddr = vrom;
    req->dramAddr = (void*)ram;
    req->size = size;
    req->unk_14 = 0;
    req->notifyQueue = queue;
    req->notifyMsg = msg;

    if (1) {
        if ((sDmaMgrQueueFullLogged == 0) && (sDmaMgrMsgQueue.validCount >= sDmaMgrMsgQueue.msgCount)) {
            sDmaMgrQueueFullLogged++;
            osSyncPrintf("%c", 7);
            osSyncPrintf(VT_FGCOL(RED));
            osSyncPrintf("dmaEntryMsgQが一杯です。キューサイズの再検討をおすすめします。");
            LOG_NUM("(sizeof(dmaEntryMsgBufs) / sizeof(dmaEntryMsgBufs[0]))", ARRAY_COUNT(sDmaMgrMsgs),
                    "../z_std_dma.c", 952);
            osSyncPrintf(VT_RST);
        }
    }

    osSendMesg(&sDmaMgrMsgQueue, req, OS_MESG_BLOCK);
    return 0;
}

s32 DmaMgr_SendRequest0(u32 ram, u32 vrom, u32 size) {
    DmaRequest req;
    OSMesgQueue queue;
    OSMesg msg;
    s32 ret;

    osCreateMesgQueue(&queue, &msg, 1);
    ret = DmaMgr_SendRequestImpl(&req, ram, vrom, size, 0, &queue, NULL);
    if (ret == -1) {
        return ret;
    }

    osRecvMesg(&queue, NULL, OS_MESG_BLOCK);
    return 0;
}

void DmaMgr_Init(void) {
    const char** name;
    s32 idx;
    DmaEntry* iter;

    DmaMgr_DMARomToRam((u32)_dmadataSegmentRomStart, (u32)_dmadataSegmentStart,
                       (u32)(_dmadataSegmentRomEnd - _dmadataSegmentRomStart));
    osSyncPrintf("dma_rom_ad[]\n");

    sDmaMgrDataExistError = 0;
    name = sDmaMgrFileNames;
    iter = gDmaDataTable;
    idx = 0;

    while (iter->vromEnd != 0) {
        if (iter->romEnd != 0) {
            sDmaMgrDataExistError = 1;
        }

        osSyncPrintf(
            "%3d %08x %08x %08x %08x %08x %c %s\n", idx, iter->vromStart, iter->vromEnd, iter->romStart, iter->romEnd,
            (iter->romEnd != 0) ? iter->romEnd - iter->romStart : iter->vromEnd - iter->vromStart,
            (((iter->romEnd != 0) ? iter->romEnd - iter->romStart : 0) > 0x10000) ? '*' : ' ', name ? *name : "");

        idx++;
        iter++;

        if (name) {
            name++;
        }
    }

    if ((u32)_bootSegmentRomStart != gDmaDataTable[0].vromEnd) {
        osSyncPrintf("_bootSegmentRomStart(%08x) != dma_rom_ad[0].rom_b(%08x)\n", _bootSegmentRomStart,
                     gDmaDataTable[0].vromEnd);
        Fault_AddHungupAndCrash("../z_std_dma.c", 1055);
    }

    osCreateMesgQueue(&sDmaMgrMsgQueue, sDmaMgrMsgs, ARRAY_COUNT(sDmaMgrMsgs));
    StackCheck_Init(&sDmaMgrStackInfo, sDmaMgrStack, sDmaMgrStack + sizeof(sDmaMgrStack), 0, 0x100, "dmamgr");
    osCreateThread(&sDmaMgrThread, 0x12, &DmaMgr_ThreadEntry, 0, sDmaMgrStack + sizeof(sDmaMgrStack),
                   Z_PRIORITY_DMAMGR);
    osStartThread(&sDmaMgrThread);
}

s32 DmaMgr_SendRequest2(DmaRequest* req, u32 ram, u32 vrom, u32 size, u32 unk5, OSMesgQueue* queue, OSMesg msg,
                        const char* file, s32 line) {
    req->filename = file;
    req->line = line;
    DmaMgr_SendRequestImpl(req, ram, vrom, size, unk5, queue, msg);
}

s32 DmaMgr_SendRequest1(void* ram0, u32 vrom, u32 size, const char* file, s32 line) {
    DmaRequest req;
    s32 ret;
    OSMesgQueue queue;
    OSMesg msg;
    u32 ram = (u32)ram0;

    req.filename = file;
    req.line = line;
    osCreateMesgQueue(&queue, &msg, 1);
    ret = DmaMgr_SendRequestImpl(&req, ram, vrom, size, 0, &queue, 0);
    if (ret == -1) {
        return ret;
    }

    osRecvMesg(&queue, NULL, 1);
    return 0;
}
