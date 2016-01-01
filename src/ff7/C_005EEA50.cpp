//coaster -- hit/clip?

#include "ff7.h"

#include "coaster_data.h"

////////////////////////////////////////
int D_00C5D328,D_00C5D32C;
struct VECTOR D_00C5D330,D_00C5D340;
int D_00C5D350,D_00C5D354;
int D_00C5D358,D_00C5D35C;
////////////////////////////////////////
__inline int __the_inline_1(struct VECTOR &a, int bp08, int bp0c, int bp10, int b) {
	return 
		+ (a.f_08 * (bp10 >> 2) + 0)
		+ (a.f_04 * (bp0c >> 2) + b)
		+ (a.f_00 * (bp08 >> 2) + 0)
	;
}

__inline int __005EEEAD_inline(int bp08, int bp0c, int bp10) { return __the_inline_1(D_00C5D330, bp08, bp0c, bp10, D_00C5D328); }
__inline int __005EEEEA_inline(int bp08, int bp0c, int bp10) { return __the_inline_1(D_00C5D340, bp08, bp0c, bp10, D_00C5D32C); }
////////////////////////////////////////
//coaster.hit:init?
void C_005EEA50() {
	struct {
		struct VECTOR clip_up_right;//   = { 160,  120, 256};//local_32
		struct VECTOR clip_down_right;// = { 160, -120, 256};//local_28
		struct VECTOR clip_up_left;//    = {-160,  120, 256};//local_24
		struct VECTOR clip_down_left;//  = {-160, -120, 256};//local_20
		struct VECTOR local_16;
		struct VECTOR local_12;
		struct VECTOR local_8;
		struct VECTOR local_4;
	}lolo;
	
	VECTOR_init(lolo.clip_up_left,    -160,  120, 256);
	VECTOR_init(lolo.clip_up_right,    160,  120, 256);
	VECTOR_init(lolo.clip_down_left,  -160, -120, 256);
	VECTOR_init(lolo.clip_down_right,  160, -120, 256);

	lolo.local_8.f_00 = lolo.clip_down_left.f_00 >> 2; lolo.local_8.f_04 = lolo.clip_down_left.f_04 >> 2; lolo.local_8.f_08 = lolo.clip_down_left.f_08 >> 2;
	lolo.local_4.f_00 = lolo.clip_up_left.f_00 >> 2; lolo.local_4.f_04 = lolo.clip_up_left.f_04 >> 2; lolo.local_4.f_08 = lolo.clip_up_left.f_08 >> 2;

	lolo.local_16.f_00 = lolo.clip_down_right.f_00 >> 2; lolo.local_16.f_04 = lolo.clip_down_right.f_04 >> 2; lolo.local_16.f_08 = lolo.clip_down_right.f_08 >> 2;
	lolo.local_12.f_00 = lolo.clip_up_right.f_00 >> 2; lolo.local_12.f_04 = lolo.clip_up_right.f_04 >> 2; lolo.local_12.f_08 = lolo.clip_up_right.f_08 >> 2;

	C_00663B32(&lolo.local_8, &lolo.local_4, &D_00C5D330);//psx:vector cross product
	C_00663B32(&lolo.local_16, &lolo.local_12, &D_00C5D340);//psx:vector cross product

	D_00C5D328 =
		- (D_00C5D330.f_00 * (lolo.clip_down_left.f_00 >> 2))
		- (D_00C5D330.f_04 * (lolo.clip_down_left.f_04 >> 2))
		- (D_00C5D330.f_08 * (lolo.clip_down_left.f_08 >> 2))
	;
	D_00C5D32C =
		- (D_00C5D340.f_00 * (lolo.clip_down_right.f_00 >> 2))
		- (D_00C5D340.f_04 * (lolo.clip_down_right.f_04 >> 2))
		- (D_00C5D340.f_08 * (lolo.clip_down_right.f_08 >> 2))
	;
	D_00C5D350 = __005EEEAD_inline(lolo.clip_down_right.f_00, lolo.clip_down_right.f_04, lolo.clip_down_right.f_08);
	D_00C5D354 = __005EEEEA_inline(lolo.clip_down_left.f_00, lolo.clip_down_left.f_04, lolo.clip_down_left.f_08);
	D_00C5D358 = C_00663736(D_00C5D330.f_00 * D_00C5D330.f_00 + D_00C5D330.f_04 * D_00C5D330.f_04 + D_00C5D330.f_08 * D_00C5D330.f_08);//psx:SquareRoot0?
	D_00C5D35C = C_00663736(D_00C5D340.f_00 * D_00C5D340.f_00 + D_00C5D340.f_04 * D_00C5D340.f_04 + D_00C5D340.f_08 * D_00C5D340.f_08);//psx:SquareRoot0?
}

//coaster.hit:check?
int C_005EECB5(struct VECTOR *bp08) {
	struct {
		int local_4;
		int local_3;
		int local_2;
		int local_1;
	}lolo;

	lolo.local_3 = lolo.local_2 = 0;
	lolo.local_4 = __005EEEAD_inline(bp08->f_00, bp08->f_04, bp08->f_08);
	lolo.local_1 = __005EEEEA_inline(bp08->f_00, bp08->f_04, bp08->f_08);
	if(lolo.local_4 > 0 && D_00C5D350 > 0)
		lolo.local_2 = 1;
	if(lolo.local_4 < 0 && D_00C5D350 < 0)
		lolo.local_2 = 1;
	if(lolo.local_1 > 0 && D_00C5D354 > 0)
		lolo.local_3 = 1;
	if(lolo.local_1 < 0 && D_00C5D354 < 0)
		lolo.local_3 = 1;

	return lolo.local_2 & lolo.local_3;
}

//coaster:check hit(SVECTOR)?
int __005EEDAE(struct SVECTOR *bp08) {
	struct {
		int local_4;
		int local_3;
		int local_2;
		int local_1;
	}lolo;

	lolo.local_3 = lolo.local_2 = 0;
	lolo.local_4 = __005EEEAD_inline(bp08->f_00, bp08->f_02, bp08->f_04);
	lolo.local_1 = __005EEEEA_inline(bp08->f_00, bp08->f_02, bp08->f_04);
	if(lolo.local_4 > 0 && D_00C5D350 > 0)
		lolo.local_2 = 1;
	if(lolo.local_4 < 0 && D_00C5D350 < 0)
		lolo.local_2 = 1;
	if(lolo.local_1 > 0 && D_00C5D354 > 0)
		lolo.local_3 = 1;
	if(lolo.local_1 < 0 && D_00C5D354 < 0)
		lolo.local_3 = 1;

	return lolo.local_2 & lolo.local_3;
}

//check
int __005EEEAD(int bp08, int bp0c, int bp10) {
	//return __005EEEAD_inline(bp08, bp0c, bp10);
	return __the_inline_1(D_00C5D330, bp08, bp0c, bp10, D_00C5D328);
}

int __005EEEEA(int bp08, int bp0c, int bp10) {
	//return __005EEEEA_inline(bp08, bp0c, bp10);
	return __the_inline_1(D_00C5D340, bp08, bp0c, bp10, D_00C5D32C);
}

int __005EEF27(struct VECTOR *bp08, short bp0c) {
	struct {
		int local_5;
		int local_4;
		int local_3;
		int local_2;
		int local_1;
	}lolo;

	lolo.local_5 = 0;
	lolo.local_3 = 0;
	lolo.local_4 = __005EEEAD_inline(bp08->f_00, bp08->f_04, bp08->f_08);
	if(D_00C5D350 > 0 && lolo.local_4 > 0)
		lolo.local_5 = 1;
	if(D_00C5D350 < 0 && lolo.local_4 < 0)
		lolo.local_5 = 1;
	if(lolo.local_5 == 0) {
		lolo.local_1 = abs(lolo.local_4) / D_00C5D358;
		if(bp0c < lolo.local_1)
			lolo.local_5 = 1;
	}
	lolo.local_2 = __005EEEEA_inline(bp08->f_00, bp08->f_04, bp08->f_08);
	if(D_00C5D354 > 0 && lolo.local_2 > 0)
		lolo.local_3 = 1;
	if(D_00C5D354 < 0 && lolo.local_2 < 0)
		lolo.local_3 = 1;
	if(lolo.local_3 == 0) {
		lolo.local_1 = abs(lolo.local_2) / D_00C5D35C;
		if(bp0c < lolo.local_1)
			lolo.local_3 = 1;
	}

	return lolo.local_5 | lolo.local_3;
}

int __005EF071(int bp08, int bp0c, int bp10) {
	struct {
		int local_3;
		int local_2;
		int local_1;
	}lolo;

	lolo.local_3 = 0;
	lolo.local_1 = __005EEEAD_inline(bp08, bp0c, bp10);
	if(D_00C5D350 > 0 && lolo.local_1 > 0)
		lolo.local_3 = 1;
	if(D_00C5D350 < 0 && lolo.local_1 < 0)
		lolo.local_3 = 1;
	if(lolo.local_3 == 0) {
		lolo.local_2 = abs(lolo.local_1) / D_00C5D358;
		if(bp0c < lolo.local_2)
			lolo.local_3 = 1;
	}

	return lolo.local_3;
}

int __005EF114(int bp08, int bp0c, int bp10) {
	struct {
		int local_3;
		int local_2;
		int local_1;
	}lolo;

	lolo.local_3 = 0;
	lolo.local_1 = __005EEEEA_inline(bp08, bp0c, bp10);
	if(D_00C5D354 > 0 && lolo.local_1 > 0)
		lolo.local_3 = 1;
	if(D_00C5D354 < 0 && lolo.local_1 < 0)
		lolo.local_3 = 1;
	if(lolo.local_3 == 0) {
		lolo.local_2 = abs(lolo.local_1) / D_00C5D35C;
		if(bp0c < lolo.local_2)
			lolo.local_3 = 1;
	}

	return lolo.local_3;
}
