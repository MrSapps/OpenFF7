//coaster --

#include "ff7.h"

#include "coaster_data.h"

////////////////////////////////////////
//this module or another ?
struct MATRIX __009014B0 = {
	{
		{0x1000, 0, 0},
		{0, 0x1000, 0},
		{0, 0, 0x1000}
	},
	{0, 0, 0}
};
//00 00
struct MATRIX __009014D0 = {
	{
		{0x1000, 0, 0},
		{0, 0x1000, 0},
		{0, 0, 0x1000}
	},
	{0, 0, 0}
};
//00 00
////////////////////////////////////////
char D_00C3F890;//devel/release mode
int D_00C3F894;
int *D_00C3F898;//offsets in "getStream_inline(4)"
//00C3F89C
struct MATRIX D_00C3F8A0;//start of a structure?
int *D_00C3F8C0;
//D_00C3F8C4
unsigned char *D_00C3F8D0;
//00C3F8D4
struct VECTOR D_00C3F8D8;
struct VECTOR D_00C3F8E8;
int D_00C3F8F8;
int D_00C3F8FC;
int D_00C3F900;
////////////////////////////////////////
//init this module
void C_005EA8C0() {
	D_00C3F8C0 = (int *)D_00C3F738.getStream_inline(6);
	D_00C3F898 = (int *)D_00C3F738.getStream_inline(5);
	D_00C3F8F8 = 0;
	D_00C3F8FC = -0x1b76;
	D_00C3F900 = 0xc8;
	C_005EAAF3(0);//prepare data from stream #4?
	D_00C3F890 = 1;//release mode
}

//track matrix related
void C_005EA973() {
	struct {
		struct VECTOR local_17;
		struct MATRIX local_13; char _ocal_13[2];
		struct SVECTOR local_5;
		struct SVECTOR local_3;
		int local_1;
	}lolo;

	//-- --
	lolo.local_13.f_00[0][0] = 0x1000; lolo.local_13.f_00[0][1] = 0; lolo.local_13.f_00[0][2] = 0;
	lolo.local_13.f_00[1][0] = 0; lolo.local_13.f_00[1][1] = 0x1000; lolo.local_13.f_00[1][2] = 0;
	lolo.local_13.f_00[2][0] = 0; lolo.local_13.f_00[2][1] = 0; lolo.local_13.f_00[2][2] = 0x1000;
	lolo.local_13.f_12[0] = 0;
	lolo.local_13.f_12[1] = 0;
	lolo.local_13.f_12[2] = 0;
	//-- --
	C_005EA194(D_00C3F778, -100, &lolo.local_17, &lolo.local_5);//compute POV/camera vectors?
	D_00C3F778 += D_00C3F768;
	D_00C3F8E8.f_00 = lolo.local_17.f_00;
	D_00C3F8E8.f_04 = lolo.local_17.f_04;
	D_00C3F8E8.f_08 = lolo.local_17.f_08;
	D_00C3F8E8.f_0c = lolo.local_17.f_0c;
	D_00C3F8D8.f_00 = D_00C3F8E8.f_00;
	D_00C3F8D8.f_04 = D_00C3F8E8.f_04;
	D_00C3F8D8.f_08 = D_00C3F8E8.f_08;
	D_00C3F8D8.f_0c = D_00C3F8E8.f_0c;
	if(lolo.local_5.f_00 < 0)
		lolo.local_5.f_00 += 0x1000;
	lolo.local_1 = C_00662538(lolo.local_5.f_00) / 0xf;//psx:sin to fixed?
	if(lolo.local_1 > 0 && D_00C3F768 > 0xA7F8)
		D_00C3F768 -= lolo.local_1;
	if(lolo.local_1 < 0 && D_00C3F768 < 0x1D4C0)
		D_00C3F768 -= lolo.local_1;
	lolo.local_3.f_00 = -lolo.local_5.f_00;
	lolo.local_3.f_02 = -lolo.local_5.f_02;
	lolo.local_3.f_04 = -lolo.local_5.f_04;
	C_00662AD8(&lolo.local_3, &lolo.local_13);//psx:xyz_rotate(2)
	C_005E9FED(&lolo.local_13, &D_00C3F8A0, &D_00C3F8A0);
}

//prepare data from stream #4?
void C_005EAAF3(int bp08) {
	int local_1;

	local_1 = D_00C3F898[bp08 & 0xff];
	D_00C3F8D0 = D_00C3F738.getStream_inline(4) + local_1;
	D_00C3F894 = *D_00C3F8C0;
}

void __005EAB5E() {
}
