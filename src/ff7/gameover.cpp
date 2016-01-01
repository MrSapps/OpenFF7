//"Game Over" module

#include "ff7.h"

////////////////////////////////////////
int D_007BA668 = 0xff;//fade out alpha

const char *D_007BA670[] = {
    /*007BA690*/"e_over_a.tim",
    /*007BA6A0*/"e_over_b.tim",
    /*007BA6B0*/"e_over_c.tim",
    /*007BA6C0*/"e_over_d.tim",
    /*007BA6D0*/"e_over_e.tim",
    /*007BA6E0*/"e_over_f.tim"
};
const char *D_007BA688[] = {
    /*007BA6F0*/"e_over_la.tim",
    /*007BA700*/"e_over_lb.tim"
};
////////////////////////////////////////
struct t_dx_sfx_e0 *D_009A0550[6];
struct t_dx_sfx_e0 *D_009A0568[2];
struct t_dx_sfx_e0 *D_009A0570;

int D_009A0574;//viewport:height
int D_009A0578;
int D_009A057C;//viewport:left
int D_009A0580;//viewport:width
int D_009A0584;//fade out flag
int D_009A0588;//viewport:top
int D_009A058C;//fade in flag
int D_009A0590;//fade in alpha
//009A0594:""
////////////////////////////////////////
//set picture alpha(fade in/out)?
void C_00404E00(unsigned char bp08) {
    struct {
        struct t_dx_rend_vertex_20 *local_6[4];
        float local_2;
        tRGBA local_1;
    }lolo;

    lolo.local_1.c.b = lolo.local_1.c.g = lolo.local_1.c.r = 0;
    lolo.local_1.c.a = bp08;
    lolo.local_2 = 0;
    if (C_0066E272(1, D_009A0570)) {
        MK_QUAD_2D_NOTEXTURE(
            D_009A0570->f_70.asVertex, lolo.local_6,
            (float)D_009A057C, (float)D_009A0588, (float)D_009A0580, (float)D_009A0574,
            lolo.local_2, 1.0f,
            lolo.local_1.rgba, 0xff000000
            );
    }
}

//image[gr mode 0]
void C_00404F83() {
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
    lolo.tex_width = 1.0f;
    lolo.tex_height = (216.0f / 256.0f);//0.84375f
    lolo.local_1 = 0.01f;
    if (C_0066E272(1, D_009A0568[0])) {
        MK_QUAD_2D(
            D_009A0568[0]->f_70.asVertex, lolo.local_9,
            16.0f, 12.0f, 256.f, 216.0f,
            lolo.local_1, 1.0f,
            0x80ffffff, 0xff000000,
            lolo.tex_u, lolo.tex_v, lolo.tex_width, lolo.tex_height
            );
    }

    if (C_0066E272(1, D_009A0568[1])) {
        MK_QUAD_2D(
            D_009A0568[1]->f_70.asVertex, lolo.local_13,
            272.0f, 12.0f, 32.f, 216.0f,
            lolo.local_1, 1.0f,
            0x80ffffff, 0xff000000,
            lolo.tex_u, lolo.tex_v, lolo.tex_width, lolo.tex_height
            );
    }
}

//image[gr mode 1]
void C_004052C8() {
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
    lolo.tex_width = 1.0f;
    lolo.tex_height = (216.0f / 256.0f);//0.84375f
    lolo.local_1 = 0.01f;
    if (C_0066E272(1, D_009A0568[0])) {
        MK_QUAD_2D(
            D_009A0568[0]->f_70.asVertex, lolo.local_9,
            176.0f, 132.0f, 256.f, 216.0f,
            lolo.local_1, 1.0f,
            0x80ffffff, 0xff000000,
            lolo.tex_u, lolo.tex_v, lolo.tex_width, lolo.tex_height
            );
    }

    if (C_0066E272(1, D_009A0568[1])) {
        MK_QUAD_2D(
            D_009A0568[1]->f_70.asVertex, lolo.local_13,
            432.0f, 132.0f, 32.0f, 216.0f,
            lolo.local_1, 1.0f,
            0x80ffffff, 0xff000000,
            lolo.tex_u, lolo.tex_v, lolo.tex_width, lolo.tex_height
            );
    }
}

//image[gr mode 2]
void C_0040560D() {
    struct {
        struct t_dx_rend_vertex_20 *local_31[4];
        struct t_dx_rend_vertex_20 *local_27[4];
        struct t_dx_rend_vertex_20 *local_23[4];
        struct t_dx_rend_vertex_20 *local_19[4];
        struct t_dx_rend_vertex_20 *local_15[4];
        struct t_dx_rend_vertex_20 *local_11[4];
        float tex_height;//local_7
        float tex_width;//local_6
        float tex_v;//local_5
        float tex_u;//local_4
        float local_3;
        int local_2;
        int local_1;
    }lolo;

    lolo.local_2 = 0x18;
    lolo.local_1 = 0x20;
    lolo.tex_u = 0.0f;
    lolo.tex_v = 0.0f;
    lolo.tex_width = 1.0f;
    lolo.tex_height = 1.0f;
    lolo.local_3 = 0.01f;
    if (C_0066E272(1, D_009A0550[0])) {
        MK_QUAD_2D(
            D_009A0550[0]->f_70.asVertex, lolo.local_11,
            (float)lolo.local_1, (float)lolo.local_2, 256.f, 256.0f,
            lolo.local_3, 1.0f,
            0x80ffffff, 0xff000000,
            lolo.tex_u, lolo.tex_v, lolo.tex_width, lolo.tex_height
            );
    }

    if (C_0066E272(1, D_009A0550[1])) {
        MK_QUAD_2D(
            D_009A0550[1]->f_70.asVertex, lolo.local_15,
            (float)lolo.local_1 + 256.f, (float)lolo.local_2, 256.0f, 256.0f,
            lolo.local_3, 1.0f,
            0x80ffffff, 0xff000000,
            lolo.tex_u, lolo.tex_v, lolo.tex_width, lolo.tex_height
            );
    }


    if (C_0066E272(1, D_009A0550[2])) {
        MK_QUAD_2D(
            D_009A0550[2]->f_70.asVertex, lolo.local_19,
            (float)lolo.local_1 + 256.f + 256.0f, (float)lolo.local_2, 64.0f, 256.0f,
            lolo.local_3, 1.0f,
            0x80ffffff, 0xff000000,
            lolo.tex_u, lolo.tex_v, lolo.tex_width, lolo.tex_height
            );
    }
    lolo.tex_height = (176.0f / 256.0f);//0.6875f
    if (C_0066E272(1, D_009A0550[3])) {
        MK_QUAD_2D(
            D_009A0550[3]->f_70.asVertex, lolo.local_23,
            (float)lolo.local_1, (float)lolo.local_2 + 256.0f, 256.f, 176.0f,
            lolo.local_3, 1.0f,
            0x80ffffff, 0xff000000,
            lolo.tex_u, lolo.tex_v, lolo.tex_width, lolo.tex_height
            );
    }


    if (C_0066E272(1, D_009A0550[4])) {
        MK_QUAD_2D(
            D_009A0550[4]->f_70.asVertex, lolo.local_27,
            (float)lolo.local_1 + 256.0f, (float)lolo.local_2 + 256.0f, 256.f, 176.0f,
            lolo.local_3, 1.0f,
            0x80ffffff, 0xff000000,
            lolo.tex_u, lolo.tex_v, lolo.tex_width, lolo.tex_height
            );
    }

    if (C_0066E272(1, D_009A0550[5])) {
        MK_QUAD_2D(
            D_009A0550[5]->f_70.asVertex, lolo.local_31,
            (float)lolo.local_1 + 256.0f + 256.0f, (float)lolo.local_2 + 256.0f, 64.f, 176.0f,
            lolo.local_3, 1.0f,
            0x80ffffff, 0xff000000,
            lolo.tex_u, lolo.tex_v, lolo.tex_width, lolo.tex_height
            );
    }
}

void C_004060D1() {
    struct {
        int local_161;
        const char *local_160;

        struct t_rsd_74 local_159;
        unsigned local_130;
        struct t_aa0 *local_129;
        char local_128[256];
        char local_64[256];
    }lolo;

    lolo.local_129 = C_00676578();
    lolo.local_161 = C_00404D80();//Get "Graphics/Mode" Key
    //-- --


    //-- open archive--
    strcpy(lolo.local_64, C_004076EA());//initpath:...
    strcat(lolo.local_64, "cd/disc_us.lgp");
    if (C_00675511(lolo.local_64, 0x10) == 0) {//is_lib:open archive?
        sprintf(lolo.local_128, "Failed to load: %s\n", lolo.local_64);
        C_00664E30(lolo.local_128);
    }
    //-- --
    C_0067453A(0);//rsd:set some flag
    C_006745E6(4, &lolo.local_159);//rsd:...
    lolo.local_159.f_40.f_04 = 1;
    lolo.local_159.f_40.f_08 = 0x10;
    lolo.local_159.f_40.f_0c = 0;
    lolo.local_159.f_24 = "";//009A0594
    if (lolo.local_161 == 2) {//else 00406284
        lolo.local_159.f_50 |= 1;
        lolo.local_159.f_54.rgba = 0xff141414;
        C_00674659(4, &lolo.local_159);//rsd:set struct t_rsd_74::f_20
        for (lolo.local_130 = 0; lolo.local_130 < 6; lolo.local_130++) {
            lolo.local_160 = D_007BA670[lolo.local_130];
            D_009A0550[lolo.local_130] = C_006710AC(1, 0xc, &lolo.local_159, lolo.local_160, lolo.local_129->f_910);//dx_sfx:alloc/create?
        }
    }
    else {
        lolo.local_159.f_50 |= 1;
        lolo.local_159.f_54.rgba = 0xff141414;
        C_00674659(4, &lolo.local_159);//rsd:set struct t_rsd_74::f_20
        for (lolo.local_130 = 0; lolo.local_130 < 2; lolo.local_130++) {
            lolo.local_160 = D_007BA688[lolo.local_130];
            D_009A0568[lolo.local_130] = C_006710AC(1, 0xc, &lolo.local_159, lolo.local_160, lolo.local_129->f_910);//dx_sfx:alloc/create?
        }
    }
    lolo.local_159.f_70 |= 0x4000;
    C_00674659(0, &lolo.local_159);//rsd:set struct t_rsd_74::f_20
    D_009A0570 = C_006710AC(0, 8, &lolo.local_159, 0, lolo.local_129->f_910);//dx_sfx:alloc/create?
}

//GameOver[START][callback]
void C_00406367(struct t_aa0 *bp08) {
    int local_1;

    local_1 = C_00404D80();//Get "Graphics/Mode" Key

    D_009A058C = 1;//start fade in
    D_009A0584 = 1;//start fade out
    D_009A0578 = 0;
    D_009A0590 = 0;//fade in alpha
    D_007BA668 = 0xff;//fade out alpha
    if (local_1 == 0) {
        D_009A057C = 0;
        D_009A0588 = 0;
        D_009A0580 = 0x140;
        D_009A0574 = 0xf0;
    }
    else if (local_1 == 1) {
        D_009A057C = 0xa0;
        D_009A0588 = 0x78;
        D_009A0580 = 0x140;
        D_009A0574 = 0xf0;
    }
    else {
        D_009A057C = 0;
        D_009A0588 = 0;
        D_009A0580 = 0x280;
        D_009A0574 = 0x1e0;
    }
    C_004060D1();
}

//GameOver[END][callback]
void C_00406436(struct t_aa0 *bp08) {
    int local_1;

    C_00740D80(0xc1, 0x3c, 0, 0, 0, 0, 0, 0, 0);
    C_006C12B1();
    for (local_1 = 0; local_1 < 6; local_1++)
        C_00671082(&(D_009A0550[local_1]));//dx_sfx:release "struct t_dx_sfx_e0 **"
    C_00671082(&D_009A0568[0]);//dx_sfx:release "struct t_dx_sfx_e0 **"
    C_00671082(&D_009A0568[1]);//dx_sfx:release "struct t_dx_sfx_e0 **"
    C_00671082(&D_009A0570);//dx_sfx:release "struct t_dx_sfx_e0 **"

    D_00CC0D88.f_01 = 0;
    D_00CBF9DC = 0x1b;
    D_00CC0D84 = 0x1a;
    C_00675F1D(0x10);//is_lib:close archive

}

//GameOver[UPDATE][callback]
void C_004064D7(struct t_aa0 *bp08) {
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
            C_0040560D();//image[gr mode 2]
            C_0066E641(D_009A0550[0], bp08);//dx_spr:render something?
            C_0066E641(D_009A0550[1], bp08);//dx_spr:render something?
            C_0066E641(D_009A0550[2], bp08);//dx_spr:render something?
            C_0066E641(D_009A0550[3], bp08);//dx_spr:render something?
            C_0066E641(D_009A0550[4], bp08);//dx_spr:render something?
            C_0066E641(D_009A0550[5], bp08);//dx_spr:render something?
        }
        else if (lolo.local_9 == 0) {
            C_00404F83();//image[gr mode 0]
            C_0066E641(D_009A0568[0], bp08);//dx_spr:render something?
            C_0066E641(D_009A0568[1], bp08);//dx_spr:render something?
        }
        else if (lolo.local_9 == 1) {
            C_004052C8();//image[gr mode 1]
            C_0066E641(D_009A0568[0], bp08);//dx_spr:render something?
            C_0066E641(D_009A0568[1], bp08);//dx_spr:render something?
        }
        //-- manage input --
        C_0041A21E(0);//Refresh input driver?
        if (C_0041AB74(0xffffffff))//test input mask[trigger]?
            D_009A0578 = 1;
        //-- --
        if (D_009A0578 && D_009A0584) {
            //--------------
            //-- fade out --
            C_00404E00(D_009A0590);//set picture alpha(fade in/out)?
            C_00660E95(1, bp08);//G_DRV_84?change_layer
            C_0066E641(D_009A0570, bp08);//dx_spr:render something?
            D_009A0590 += 0x33;
            if (D_009A0590 > 0xff) {
                D_009A0584 = 0;
                lolo.local_7.f_08 = C_00408FA6;//MainDispatcher[BEGIN][callback]
                lolo.local_7.f_10 = C_004090E6;//MainDispatcher[UPDATE][callback]
                lolo.local_7.f_14 = C_00409DF1;//MainDispatcher[ONMOUSE][callback]
                lolo.local_7.f_18 = C_00409E39;//MainDispatcher[ONKEY][callback]
                lolo.local_7.f_0c = C_004090C7;//MainDispatcher[END][callback]
                C_00666CF2(&lolo.local_7, bp08);//set main loop callbacks?
            }
        }
        if (D_009A058C) {
            //-------------
            //-- fade in --
            C_00404E00(D_007BA668);//set picture alpha(fade in/out)?
            C_00660E95(1, bp08);//G_DRV_84?change_layer
            C_0066E641(D_009A0570, bp08);//dx_spr:render something?
            D_007BA668 -= 0x33;
            if (D_007BA668 <= 0x33)
                D_009A058C = 0;
        }
        C_00660EEB(bp08);//G_DRV_8C:EndScene
    }
}

//[callback]
void C_00406770(int bp08, int bp0c, int _p10, struct t_aa0 *_p14) {
    unsigned char local_1;

    switch (bp08) {
    case WM_CHAR://0x102
        local_1 = (unsigned char)bp0c;
        switch (local_1) {
        case 0x00: break;//0x00 or whatever ...
        }
        break;
    }
}

//[callback]
void C_00406797(int _p08, int _p0c, int _p10, struct t_aa0 *_p14) {
}
