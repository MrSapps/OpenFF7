#include "ff7.h"

//#include "sw.h"

//0x0067db30
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
#pragma pack(1)
    struct {//0xac74
        LARGE_INTEGER ts_before, ts_after;//bp_538c,bp_5394
        int ssav_prev;//bp_539c
        int seed;//bp_53a0
        int bp_53a4;
        int bp_53a8;
        int ret;//bp_53ac
        MSG msg;//bp_53b0
        struct t_aa0 *bp_53cc;
        char bp_53d0[sizeof(struct t_SW_TriangleStack) + 0x1000];
    } lolo;
#pragma pack()

    //-- --
    lolo.bp_53a8 = 0;
    lolo.bp_53a4 = 0;
    C_0040A091(lolo.bp_53a8, lolo.bp_53a4);//main:some base init/config?
    //-- return value --
    lolo.ret = 0;
    //-- --
    lolo.bp_53cc = C_00676578();//directx:get some game obj?
    if (lolo.bp_53cc == 0)
        lolo.bp_53cc = C_00676E7E();//directx:init some game object?
    C_0067656B(lolo.bp_53cc);//directx:set some game object?
    //-- --
    C_00681FB1(lolo.bp_53d0, lolo.bp_53cc);//sw:some init?
    //-- randomize --
    if (lolo.bp_53cc->f_9b0) {
        srand(lolo.bp_53cc->f_9b0);
    }
    else {
        time((time_t *)&lolo.seed);
        srand(lolo.seed);
    }
    //-- --
    if (lolo.bp_53cc)
        lolo.bp_53cc->f_058 = hInstance;
    if (lolo.bp_53cc && C_0067692A(hInstance, lolo.bp_53cc)) {//else 0067DEB4
        SystemParametersInfo(SPI_SCREENSAVERRUNNING/*0x61*/, 1, &lolo.ssav_prev, 0);
        //------------------
        //-- message loop --
        while (!lolo.bp_53cc->f_000) {
            if (PeekMessage(&lolo.msg, 0, 0, 0, PM_REMOVE/*1*/)) {
                TranslateMessage(&lolo.msg);
                DispatchMessage(&lolo.msg);
            }
            else if (lolo.bp_53cc->f_a54) {//else 0067DD19
                //-- "Exit box" --
                if (lolo.bp_53cc->f_020 == 0 && C_00676F2A(lolo.bp_53cc)) {//else 0067DCF3
                    if (lolo.bp_53cc->f_a58)
                        lolo.bp_53cc->f_a58(lolo.bp_53cc);
                    lolo.bp_53cc->f_a54 = 0;
                }
                //-- --
                if (lolo.bp_53cc->f_950 || lolo.bp_53cc->f_020)
                    WaitMessage();
            }
            else {
                //-- main state --
                C_00660370(&lolo.ts_before);//get CPU's time stamp counter
                lolo.bp_53cc->f_028 += 1.0;
                C_00666C78(lolo.bp_53cc);//refresh main loop callbacks?
                //-- call the current "refresh" callback --
                if (lolo.bp_53cc->f_020 == 0 && C_00676F2A(lolo.bp_53cc)) {
                    if (lolo.bp_53cc->f_9f0.f_10) {
                        lolo.bp_53cc->f_9f0.f_10(lolo.bp_53cc);
                        lolo.bp_53cc->f_040 += 1.0;
                    }
                }
                if (lolo.bp_53cc->f_020 == 0)
                    C_0066059C(lolo.bp_53cc);//G_DRV_10:Flip
                //-- --
                if (lolo.bp_53cc->f_950 || lolo.bp_53cc->f_020)
                    WaitMessage();
                //-- update some stats --
                C_00660370(&lolo.ts_after);//get CPU's time stamp counter
                if (lolo.bp_53cc->f_794)
                    C_006603A0(&lolo.ts_after, &lolo.ts_before, &(lolo.bp_53cc->f_794->f_98));//LARGE_INTEGER diff?
                //-- --
            }
        }
        //-- message loop end --
        //----------------------
        //-- call the current "end" callback --
        if (lolo.bp_53cc->f_9f0.f_0c)
            lolo.bp_53cc->f_9f0.f_0c(lolo.bp_53cc);
        //-- --
        C_0069CD26();//TexCache:clean?
        //-- call main "clean" callback --
        if (lolo.bp_53cc->f_9f0.f_04)
            lolo.bp_53cc->f_9f0.f_04(lolo.bp_53cc);
        //-- --
        SystemParametersInfo(SPI_SCREENSAVERRUNNING/*0x61*/, 0, &lolo.ssav_prev, 0);
        DestroyWindow(lolo.bp_53cc->f_05c);
        lolo.ret = lolo.bp_53cc->f_060;
    }

    C_006765BD();//directx:clean some game object?

    return lolo.ret;
}
