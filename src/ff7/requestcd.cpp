//"request cd"

#include "ff7.h"

#include "loadmenu.h"

#include 

////////////////////////////////////////
int D_007BA278 = 0xff;//fade out alpha

const char *D_007BA280[] = {
    /*007BA35C*/"disk1_a.tim",/*007BA368*/"disk1_b.tim",
    /*007BA374*/"disk2_a.tim",/*007BA380*/"disk2_b.tim",
    /*007BA38C*/"disk3_a.tim",/*007BA398*/"disk3_b.tim"
};
const char *D_007BA298[] = {
    /*007BA3A4*/"disk1_x.tim",
    /*007BA3B0*/"disk2_x.tim",
    /*007BA3BC*/"disk3_x.tim"
};

const char *D_007BA2A8[] = {
    "aeris_a.tim", "aeris_b.tim", "aeris_c.tim", "aeris_d.tim",
    "barr_a.tim", "barr_b.tim", "barr_c.tim", "barr_d.tim",
    "cid_a.tim", "cid_b.tim", "cid_c.tim", "cid_d.tim",
    "cloud_a.tim", "cloud_b.tim", "cloud_c.tim", "cloud_d.tim",
    "kets_a.tim", "kets_b.tim", "kets_c.tim", "kets_d.tim",
    "red_a.tim", "red_b.tim", "red_c.tim", "red_d.tim",
    "tifa_a.tim", "tifa_b.tim", "tifa_c.tim", "tifa_d.tim",
    "vinc_a.tim", "vinc_b.tim", "vinc_c.tim", "vinc_d.tim",
    "yuff_a.tim", "yuff_b.tim", "yuff_c.tim", "yuff_d.tim"
};
const char *D_007BA338[] = {
    /*007BA578*/"aeris_x.tim",
    /*007BA584*/"barr_x.tim",
    /*007BA590*/"cid_x.tim",
    /*007BA59C*/"cloud_x.tim",
    /*007BA5A8*/"kets_x.tim",
    /*007BA5B4*/"red_x.tim",
    /*007BA5C0*/"tifa_x.tim",
    /*007BA5CC*/"vinc_x.tim",
    /*007BA5D8*/"yuff_x.tim"
};
////////////////////////////////////////
char D_009A04F8[4];
int D_009A04FC;
int D_009A0500;//viewport:height
int D_009A0504;//viewport:left
int D_009A0508;//viewport:width
struct t_dx_sfx_e0 *D_009A0510[6];
struct t_dx_sfx_e0 *D_009A0528[2];
struct t_dx_sfx_e0 *D_009A0530;
int D_009A0534;
int D_009A0538;
int D_009A053C;//viewport:top
int D_009A0540;
int D_009A0544;//fade in alpha
//009A0548//maybe ""?
////////////////////////////////////////
extern void C_006C09C0(const char *);//[menu related]?
////////////////////////////////////////
//set picture alpha(fade in/out)?
void C_00402EF0(unsigned char bp08) {
    struct {
        struct t_dx_rend_vertex_20 *local_6[4];
        float local_2;
        tRGBA local_1;
    }lolo;

    lolo.local_1.c.b = lolo.local_1.c.g = lolo.local_1.c.r = 0;
    lolo.local_1.c.a = bp08;
    lolo.local_2 = 0;
    if (C_0066E272(1, D_009A0530)) {
        MK_QUAD_2D_NOTEXTURE(
            D_009A0530->f_70.asVertex, lolo.local_6,
            (float)D_009A0504, (float)D_009A053C, (float)D_009A0508, (float)D_009A0500,
            lolo.local_2, 1.0f,
            lolo.local_1.rgba, 0xff000000
            );
    }
}

//image[gr mode 0]
void C_00403073() {
    struct {
        struct t_dx_rend_vertex_20 *local_13[4];
        struct t_dx_rend_vertex_20 *local_9[4];
        float tex_height;//local_5
        float tex_width;//local_4
        float tex_v;//local_3
        float tex_u;//local_2
        float local_1;
    }lolo;

    lolo.tex_u = 0.0f;
    lolo.tex_v = 0.0f;
    lolo.tex_width = (200.0f / 256.0f);//0.78125f
    lolo.tex_height = (150.0f / 256.0f);//0.5859375f
    lolo.local_1 = 0.01f;
    if (C_0066E272(1, D_009A0528[0])) {
        MK_QUAD_2D(
            D_009A0528[0]->f_70.asVertex, lolo.local_9,
            60.0f, 8.0f, 200.f, 150.0f,
            lolo.local_1, 1.0f,
            0x80ffffff, 0xff000000,
            lolo.tex_u, lolo.tex_v, lolo.tex_width, lolo.tex_height
            );
    }
    lolo.tex_height = (148.0f / 256.0f);//0.578125f
    if (C_0066E272(1, D_009A0528[1])) {
        MK_QUAD_2D(
            D_009A0528[1]->f_70.asVertex, lolo.local_13,
            60.0f, 158.0f, 200.f, 74.0f,
            lolo.local_1, 1.0f,
            0x80ffffff, 0xff000000,
            lolo.tex_u, lolo.tex_v, lolo.tex_width, lolo.tex_height
            );
    }
}

//image[gr mode 1]
void C_004033BF() {
    struct {
        struct t_dx_rend_vertex_20 *local_13[4];
        struct t_dx_rend_vertex_20 *local_9[4];
        float tex_height;//local_5
        float tex_width;//local_4
        float tex_v;//local_3
        float tex_u;//local_2
        float local_1;
    }lolo;

    lolo.tex_u = 0.0f;
    lolo.tex_v = 0.0f;
    lolo.tex_width = (200.0f / 256.0f);//0.78125f
    lolo.tex_height = (150.0f / 256.0f);//0.5859375f
    lolo.local_1 = 0.01f;
    if (C_0066E272(1, D_009A0528[0])) {
        MK_QUAD_2D(
            D_009A0528[0]->f_70.asVertex, lolo.local_9,
            220.0f, 128.0f, 200.f, 150.0f,
            lolo.local_1, 1.0f,
            0x80ffffff, 0xff000000,
            lolo.tex_u, lolo.tex_v, lolo.tex_width, lolo.tex_height
            );
    }
    lolo.tex_height = (148.0f / 256.0f);//0.578125f
    if (C_0066E272(1, D_009A0528[1])) {
        MK_QUAD_2D(
            D_009A0528[1]->f_70.asVertex, lolo.local_13,
            220.0f, 278.0f, 200.f, 74.0f,
            lolo.local_1, 1.0f,
            0x80ffffff, 0xff000000,
            lolo.tex_u, lolo.tex_v, lolo.tex_width, lolo.tex_height
            );
    }
}

//image[gr mode 2]
void C_0040370B() {
    struct {
        struct t_dx_rend_vertex_20 *local_30[4];
        struct t_dx_rend_vertex_20 *local_26[4];
        struct t_dx_rend_vertex_20 *local_22[4];
        struct t_dx_rend_vertex_20 *local_18[4];
        struct t_dx_rend_vertex_20 *local_14[4];
        struct t_dx_rend_vertex_20 *local_10[4];

        float tex_height;//local_6
        float tex_width;//local_5
        float tex_v;//local_4
        float tex_u;//local_3
        float local_2;
        int local_1;
    }lolo;

    lolo.local_1 = 0x18;

    lolo.tex_u = 0.0f;
    lolo.tex_v = 0.0f;
    lolo.tex_width = 1.0f;
    lolo.tex_height = 1.0f;
    lolo.local_2 = 0.01f;
    if (C_0066E272(1, D_009A0510[0])) {
        MK_QUAD_2D(
            D_009A0510[0]->f_70.asVertex, lolo.local_10,
            120.0f, (float)lolo.local_1, 256.f, 256.0f,
            lolo.local_2, 1.0f,
            0x80ffffff, 0xff000000,
            lolo.tex_u, lolo.tex_v, lolo.tex_width, lolo.tex_height
            );
    }
    lolo.tex_width = (144.0f / 256.0f);//0.5625f
    if (C_0066E272(1, D_009A0510[1])) {
        MK_QUAD_2D(
            D_009A0510[1]->f_70.asVertex, lolo.local_14,
            376.0f, (float)lolo.local_1, 144.0f, 256.0f,
            lolo.local_2, 1.0f,
            0x80ffffff, 0xff000000,
            lolo.tex_u, lolo.tex_v, lolo.tex_width, lolo.tex_height
            );
    }
    lolo.tex_height = (176.0f / 256.0f);//0.6875f
    lolo.tex_width = 1.0f;
    if (C_0066E272(1, D_009A0510[2])) {
        MK_QUAD_2D(
            D_009A0510[2]->f_70.asVertex, lolo.local_18,
            120.0f, (float)lolo.local_1 + 256.0f, 256.0f, 44.0f,
            lolo.local_2, 1.0f,
            0x80ffffff, 0xff000000,
            lolo.tex_u, lolo.tex_v, lolo.tex_width, lolo.tex_height
            );
    }
    lolo.tex_width = (144.0f / 256.0f);//0.5625f
    if (C_0066E272(1, D_009A0510[3])) {
        MK_QUAD_2D(
            D_009A0510[3]->f_70.asVertex, lolo.local_22,
            376.0f, (float)lolo.local_1 + 256.0f, 144.0f, 44.0f,
            lolo.local_2, 1.0f,
            0x80ffffff, 0xff000000,
            lolo.tex_u, lolo.tex_v, lolo.tex_width, lolo.tex_height
            );
    }
    lolo.tex_height = (148.0f / 256.0f);//0.578125f
    lolo.tex_width = 1.0f;
    if (C_0066E272(1, D_009A0510[4])) {
        MK_QUAD_2D(
            D_009A0510[4]->f_70.asVertex, lolo.local_26,
            120.0f, (float)lolo.local_1 + 300.0f, 256.0f, 148.0f,
            lolo.local_2, 1.0f,
            0x80ffffff, 0xff000000,
            lolo.tex_u, lolo.tex_v, lolo.tex_width, lolo.tex_height
            );
    }
    lolo.tex_width = (144.0f / 256.0f);//0.5625f
    if (C_0066E272(1, D_009A0510[5])) {
        MK_QUAD_2D(
            D_009A0510[5]->f_70.asVertex, lolo.local_30,
            376.0f, (float)lolo.local_1 + 300.0f, 144.0f, 148.0f,
            lolo.local_2, 1.0f,
            0x80ffffff, 0xff000000,
            lolo.tex_u, lolo.tex_v, lolo.tex_width, lolo.tex_height
            );
    }
}

void C_0040414A() {
    struct {
        int local_162;
        const char *local_161;
        unsigned local_160;
        struct t_rsd_74 local_159;
        int local_130;
        struct t_aa0 *local_129;
        char local_128[256];
        char local_64[256];
    }lolo;

    lolo.local_129 = C_00676578();
    lolo.local_162 = C_00404D80();//Get "Graphics/Mode" Key
    //-- pick a "random" number --
    lolo.local_160 = C_0040AC84();//get frame count
    lolo.local_130 = lolo.local_160 % 9;
    //-- open archive --
    strcpy(lolo.local_64, C_004076EA());//initpath:...
    strcat(lolo.local_64, "cd/disc_us.lgp");
    if (C_00675511(lolo.local_64, 0x10) == 0) {//is_lib:open archive?
        sprintf(lolo.local_128, "Failed to load: %s\n", lolo.local_64);
        C_00664E30(lolo.local_128);
    }
    //-- --
    C_0067453A(0);//rsd:set some flag
    C_006745E6(4, &lolo.local_159);//rsd:set blend mode?
    lolo.local_159.f_40.f_04 = 1;
    lolo.local_159.f_40.f_08 = 0x10;
    lolo.local_159.f_40.f_0c = 0;
    lolo.local_159.f_24 = "";//009A0548
    if (lolo.local_162 == 2) {//else 00404572
        lolo.local_130 <<= 2;
        C_00674659(4, &lolo.local_159);//rsd:set struct t_rsd_74::f_20
        lolo.local_161 = D_007BA2A8[lolo.local_130];
        lolo.local_130++;
        D_009A0510[0] = C_006710AC(1, 0xc, &lolo.local_159, lolo.local_161, lolo.local_129->f_910);//dx_sfx:alloc/create?
        lolo.local_161 = D_007BA2A8[lolo.local_130];
        lolo.local_130++;
        D_009A0510[1] = C_006710AC(1, 0xc, &lolo.local_159, lolo.local_161, lolo.local_129->f_910);//dx_sfx:alloc/create?
        lolo.local_161 = D_007BA2A8[lolo.local_130];
        lolo.local_130++;
        D_009A0510[2] = C_006710AC(1, 0xc, &lolo.local_159, lolo.local_161, lolo.local_129->f_910);//dx_sfx:alloc/create?
        lolo.local_161 = D_007BA2A8[lolo.local_130];
        lolo.local_130++;
        D_009A0510[3] = C_006710AC(1, 0xc, &lolo.local_159, lolo.local_161, lolo.local_129->f_910);//dx_sfx:alloc/create?
        lolo.local_159.f_50 |= 1;
        lolo.local_159.f_54.rgba = 0xFF141414;
        if (D_00DC0BDC == 1) {
            lolo.local_161 = D_007BA280[0];
            D_009A0510[4] = C_006710AC(1, 0xc, &lolo.local_159, lolo.local_161, lolo.local_129->f_910);//dx_sfx:alloc/create?
            lolo.local_161 = D_007BA280[1];
            D_009A0510[5] = C_006710AC(1, 0xc, &lolo.local_159, lolo.local_161, lolo.local_129->f_910);//dx_sfx:alloc/create?
        }
        else  if (D_00DC0BDC == 2) {
            lolo.local_161 = D_007BA280[2];
            D_009A0510[4] = C_006710AC(1, 0xc, &lolo.local_159, lolo.local_161, lolo.local_129->f_910);//dx_sfx:alloc/create?
            lolo.local_161 = D_007BA280[3];
            D_009A0510[5] = C_006710AC(1, 0xc, &lolo.local_159, lolo.local_161, lolo.local_129->f_910);//dx_sfx:alloc/create?
        }
        else  if (D_00DC0BDC == 3) {
            lolo.local_161 = D_007BA280[4];
            D_009A0510[4] = C_006710AC(1, 0xc, &lolo.local_159, lolo.local_161, lolo.local_129->f_910);//dx_sfx:alloc/create?
            lolo.local_161 = D_007BA280[5];
            D_009A0510[5] = C_006710AC(1, 0xc, &lolo.local_159, lolo.local_161, lolo.local_129->f_910);//dx_sfx:alloc/create?
        }
    }
    else {
        C_00674659(4, &lolo.local_159);//rsd:set struct t_rsd_74::f_20
        lolo.local_161 = D_007BA338[lolo.local_130];
        D_009A0528[0] = C_006710AC(1, 0xc, &lolo.local_159, lolo.local_161, lolo.local_129->f_910);//dx_sfx:alloc/create?
        if (D_00DC0BDC == 1)
            lolo.local_161 = D_007BA298[0];
        else if (D_00DC0BDC == 2)
            lolo.local_161 = D_007BA298[1];
        else if (D_00DC0BDC == 3)
            lolo.local_161 = D_007BA298[2];
        D_009A0528[1] = C_006710AC(1, 0xc, &lolo.local_159, lolo.local_161, lolo.local_129->f_910);//dx_sfx:alloc/create?
    }
    lolo.local_159.f_70 |= 0x4000;
    C_00674659(0, &lolo.local_159);//rsd:set struct t_rsd_74::f_20
    D_009A0530 = C_006710AC(0, 8, &lolo.local_159, 0, lolo.local_129->f_910);//dx_sfx:alloc/create?
}

//Request CD[START][callback]
void C_00404688(struct t_aa0 *_p0c) {
    int local_1;

    local_1 = C_00404D80();//Get "Graphics/Mode" Key
    strncpy(D_009A04F8, D_009A06C0, 2);
    D_009A0540 = 1;
    D_009A0534 = 1;
    D_009A04FC = 1;
    D_009A0544 = 0;
    D_007BA278 = 0xff;
    if (local_1 == 0) {
        D_009A0504 = 0;
        D_009A053C = 0;
        D_009A0508 = 0x140;
        D_009A0500 = 0xF0;
    }
    else if (local_1 == 1) {
        D_009A0504 = 0xa0;
        D_009A053C = 0x78;
        D_009A0508 = 0x140;
        D_009A0500 = 0xF0;
    }
    else {
        D_009A0504 = 0;
        D_009A053C = 0;
        D_009A0508 = 0x280;
        D_009A0500 = 0x1e0;
    }
    C_0040414A();
}

//Request CD[END][callback]
void C_0040476C(struct t_aa0 *_p0c) {
    int local_1;


    C_004082BF();//main:open main archives?
    for (local_1 = 0; local_1 < 6; local_1++)
        C_00671082(&(D_009A0510[local_1]));//dx_sfx:release "struct t_dx_sfx_e0 **"
    C_00671082(&D_009A0528[0]);//dx_sfx:release "struct t_dx_sfx_e0 **"
    C_00671082(&D_009A0528[1]);//dx_sfx:release "struct t_dx_sfx_e0 **"
    C_00671082(&D_009A0530);//dx_sfx:release "struct t_dx_sfx_e0 **"

    D_00CBF9DC = D_00CC0D84;

    D_00CC0D84 = 0x0c;
    C_00675F1D(0x10);//is_lib:close archive
    D_009A04FC = 0;
}

//Request CD[UPDATE][callback]
void C_004047F6(struct t_aa0 *bp08) {
    struct {
        struct fBGRA local_13;
        int local_9;
        int local_8;
        struct tMainCallbacks local_7;
    }lolo;

    lolo.local_9 = C_00404D80();//Get "Graphics/Mode" Key
    C_00666DA3(bp08);//calls "instance:reset"
    C_00666DC0(bp08);//calls "dx_sfx:reset heaps(1)"
    lolo.local_13.r = 0; lolo.local_13.g = 0; lolo.local_13.b = 0; lolo.local_13.a = 1.0f;
    C_0066075C(&lolo.local_13, bp08);//G_DRV_20:ClearColor
    C_00660626(bp08);//G_DRV_18:ClearAll
    lolo.local_8 = 0;
    C_00660C3A(G_DRV_STATE_02, 0, bp08);//G_DRV_64?
    if (C_00660EC0(lolo.local_8, bp08)) {//G_DRV_88:BeginScene
        if (lolo.local_9 == 2) {
            C_0040370B();//image[gr mode 2]
            C_0066E641(D_009A0510[0], bp08);//dx_spr:render something?
            C_0066E641(D_009A0510[1], bp08);//dx_spr:render something?
            C_0066E641(D_009A0510[2], bp08);//dx_spr:render something?
            C_0066E641(D_009A0510[3], bp08);//dx_spr:render something?
            C_0066E641(D_009A0510[4], bp08);//dx_spr:render something?
            C_0066E641(D_009A0510[5], bp08);//dx_spr:render something?
        }
        else if (lolo.local_9 == 0) {
            C_00403073();//image[gr mode 0]
            C_0066E641(D_009A0528[0], bp08);//dx_spr:render something?
            C_0066E641(D_009A0528[1], bp08);//dx_spr:render something?
        }
        else if (lolo.local_9 == 1) {
            C_004033BF();//image[gr mode 1]
            C_0066E641(D_009A0528[0], bp08);//dx_spr:render something?
            C_0066E641(D_009A0528[1], bp08);//dx_spr:render something?
        }





        if (C_00404A7D() == D_00DC0BDC && D_009A0534) {//else 00404A0A
            //--------------
            //-- fade out --
            C_00402EF0(D_009A0544);//set picture alpha(fade in/out)?
            C_00660E95(1, bp08);//G_DRV_84?change_layer
            C_0066E641(D_009A0530, bp08);//dx_spr:render something?
            D_009A0544 += 0x33;
            if (D_009A0544 > 0xff) {
                D_009A0534 = 0;
                lolo.local_7.f_08 = C_00408FA6;//MainDispatcher[BEGIN][callback]
                lolo.local_7.f_10 = C_004090E6;//MainDispatcher[UPDATE][callback]
                lolo.local_7.f_14 = C_00409DF1;//MainDispatcher[ONMOUSE][callback]
                lolo.local_7.f_18 = C_00409E39;//MainDispatcher[ONKEY][callback]
                lolo.local_7.f_0c = C_004090C7;//MainDispatcher[END][callback]
                C_00666CF2(&lolo.local_7, bp08);//set main loop callbacks?
            }
        }
        if (D_009A0540) {
            //-------------
            //-- fade in --
            C_00402EF0(D_007BA278);//set picture alpha(fade in/out)?
            C_00660E95(1, bp08);//G_DRV_84?change_layer
            C_0066E641(D_009A0530, bp08);//dx_spr:render something?
            D_007BA278 -= 0x33;
            if (D_007BA278 <= 0)
                D_009A0540 = 0;
        }
        C_00660EEB(bp08);//G_DRV_8C:EndScene
    }
}

//[callback]
void C_00404A73(int, int, int, struct t_aa0 *) {
}

//[callback]
void C_00404A78(int, int, int, struct t_aa0 *) {
}

//currently inserted CD #?
int C_00404A7D() {
    struct {
        char _ocal_193[256];
        char local_129[256];
        char _ocal_65[256];
        int local_1;
    }lolo;

    D_009A0538 = 0;
    strncpy(D_009A04F8, D_009A06C0, 2);
    SetErrorMode(SEM_FAILCRITICALERRORS/*1*/);
    lolo.local_1 = GetVolumeInformation(D_009A06C0, lolo.local_129, 0x100, 0, 0, 0, 0, 0);
    if (lolo.local_1) {
        if (strcmp(lolo.local_129, "FF7DISC1") == 0)
            D_009A0538 = 1;
        else if (strcmp(lolo.local_129, "FF7DISC2") == 0)
            D_009A0538 = 2;
        else if (strcmp(lolo.local_129, "FF7DISC3") == 0)
            D_009A0538 = 3;
    }

    return D_009A0538;
}

const char D_007B6408[] = "Software\\Square Soft, Inc.\\Final Fantasy VII";

//called on WM_DEVICECHANGE
void C_00404B4A(int bp08, struct t_aa0 *_p0c) {
    struct {
        HKEY local_156;
        int local_155;
        STARTUPINFO local_154;
        int local_137;
        int local_136;
        char local_135[12];
        char local_132[256];
        PROCESS_INFORMATION local_68;
        char local_64[256];
    }lolo;

    if (D_009A04FC || bp08 == DBT_DEVICEARRIVAL)//0x8000
        return;
    if (bp08 == DBT_DEVICEREMOVECOMPLETE) {//0x8004
        lolo.local_154.cb = 0; memset(&(lolo.local_154.lpReserved), 0, sizeof(STARTUPINFO) - 4);//STARTUPINFO local_154 = {0}
        lolo.local_68.hProcess = 0; memset(&(lolo.local_68.hThread), 0, sizeof(PROCESS_INFORMATION) - 4);//PROCESS_INFORMATION local_68 = {0};
        lolo.local_137 = 1;
        memcpy(lolo.local_135, "DiscNo", 7);//char local_135[] = "DiscNo";
        D_009A04FC = 0;
        sprintf(lolo.local_132, "Please insert Disc %i to continue.", D_00DC0BDC);
        C_006C09C0(lolo.local_132);//[menu related]?
        //-- set "DiscNo" Key value ? (used by "cdcheck.exe"?)
        lolo.local_136 = RegOpenKeyEx(HKEY_LOCAL_MACHINE, D_007B6408, 0, KEY_WRITE/*0x20006*/, &lolo.local_156);
        if (lolo.local_136 == 0) {
            lolo.local_137 = 1;
            lolo.local_155 = D_00DC0BDC;
            lolo.local_136 = RegSetValueEx(lolo.local_156, lolo.local_135, 0, 4, (LPBYTE)&lolo.local_155, 4);
            if (lolo.local_136 == 0)
                lolo.local_137 = 0;
            lolo.local_136 = RegCloseKey(lolo.local_156);
        }
        lolo.local_154.cb = sizeof(STARTUPINFO);//0x44
        lolo.local_154.lpReserved = 0;
        lolo.local_154.lpReserved2 = 0;
        lolo.local_154.cbReserved2 = 0;
        lolo.local_154.lpDesktop = 0;
        lolo.local_154.dwFlags = 0;
        strcpy(lolo.local_64, D_009A0698);
        strcat(lolo.local_64, "cdcheck.exe");
        CreateProcess(0, lolo.local_64, 0, 0, 1, NORMAL_PRIORITY_CLASS, 0, 0, &lolo.local_154, &lolo.local_68);
        WaitForSingleObject(lolo.local_68.hProcess, -1);
    }
}
