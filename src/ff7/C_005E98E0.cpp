//coaster -- main?

#include "ff7.h"

#include "coaster_data.h"

////////////////////////////////////////
int D_009014A8 = 1;//display on/off flag

char D_00C3F7A8[200];
struct SVECTOR *D_00C3F870;//track related vectors
struct SVECTOR *D_00C3F874;//track related vectors
struct SVECTOR *D_00C3F878;//track related vectors
//00C3F87C
struct t_coaster_Node *D_00C3F880;//used for "last shoot score"
//00C3F884
class Class_coaster_D8 *D_00C3F888;
//00C3F88C
////////////////////////////////////////
//coaster:begin
void C_005E98E0() {
	C_006900FC(C_00407851(), D_00C3F7A8);//direct:change directory?
	C_005E91B5();
	D_00C3F888 = new Class_coaster_D8();

	D_00C3F870 = (struct SVECTOR *)D_00C3F738.getStream_inline(7);
	//-- --
	C_005EAAF3(0);//prepare data from stream #4?
	D_00C3F874 = (struct SVECTOR *)D_00C3F8D0;
	//-- --
	C_005EAAF3(1);//prepare data from stream #4?
	D_00C3F878 = (struct SVECTOR *)D_00C3F8D0;
	//-- --
	C_005E938D();//sound related(1)
	//-- used for "last shoot score" --
	D_00C3F880 = C_005EF31E(0x1e, &D_00C60150, 1200, 50, 3000, 0, 1000, 0);//allocate "Node"
}

//render objects
void C_005E99FB(struct t_coaster_Node *pNode/*bp08*/, struct t_coaster_GameObject *bp0c) {
	struct {
		short hit_bottom; char _ocal_34[2];//local_34
		int local_33;
		short hit_right; char _ocal_32[2];//local_32
		short proj_V[6+2];//bp_7c//local_31
		struct t_coaster_RenderInfo local_27;
		short proj_H[6+2];//bp_5c//local_23
		struct MATRIX local_19; char _ocal_19[2];
		struct MATRIX local_11; char _ocal_11[2];
		short hit_top; char _ocal_3[2];//local_3
		short i; char _ocal_2[2];//local_2
		short hit_left; char _ocal_1[2];//local_1
	}lolo;

	D_00C3F8A0.f_12[0] =
	D_00C3F8A0.f_12[1] =
	D_00C3F8A0.f_12[2] = 0;
	if(pNode->pParentNode != &D_00C60150) {
		//-- multiply with parent(if any)'s matrix[unused] --
		C_00661E85(&(pNode->pParentNode->f_04), &(pNode->f_04), &lolo.local_19);//psx:matrix multiplication too?
		C_00661E85(&lolo.local_19, &D_00C3F8A0, &lolo.local_11);//psx:matrix multiplication too?
	} else {
		C_00661E85(&(pNode->f_04), &D_00C3F8A0, &lolo.local_11);//psx:matrix multiplication too?
	}
	lolo.local_27.pTriangles = pNode->pModel->pTriangles;
	lolo.local_27.pModel = pNode->pModel;
	D_00C3F888->C_005F27BF(&lolo.local_11);//update some matrix stuff?
	if(D_009014A8)
		D_00C3F888->C_005EFA3A(&lolo.local_27);//render object
	//-- make 2D bounding box --
	D_00C3F888->C_005EF95A(bp0c->sBoundingBox, bp0c->f_11c);//projection:cube?
	lolo.proj_V[0] = (bp0c->f_11c[0] & 0xffff0000) >> 0x10;
	lolo.proj_H[0] = bp0c->f_11c[0] & 0x0000ffff;
	lolo.hit_right = lolo.proj_H[0];
	lolo.hit_left = lolo.proj_H[0];
	lolo.hit_bottom = lolo.proj_V[0];
	lolo.hit_top = lolo.proj_V[0];
	for(lolo.i = 1; lolo.i < 6; lolo.i ++) {//else 005E9BFF
		lolo.proj_V[lolo.i] = (bp0c->f_11c[lolo.i] & 0xffff0000) >> 0x10;
		lolo.proj_H[lolo.i] = bp0c->f_11c[lolo.i] & 0x0000ffff;
		if(lolo.hit_right > lolo.proj_H[lolo.i])
			lolo.hit_right = lolo.proj_H[lolo.i];
		if(lolo.hit_left < lolo.proj_H[lolo.i])
			lolo.hit_left = lolo.proj_H[lolo.i];
		if(lolo.hit_bottom > lolo.proj_V[lolo.i])
			lolo.hit_bottom = lolo.proj_V[lolo.i];
		if(lolo.hit_top < lolo.proj_V[lolo.i])
			lolo.hit_top = lolo.proj_V[lolo.i];
	}
	//-- --
	lolo.local_33 = C_005EECB5((struct VECTOR *)lolo.local_11.f_12);//coaster.hit:check?
	if(lolo.local_33) {//else 005E9CB1
		bp0c->f_028.dwIsHit = 0;
		if(
			lolo.hit_left > D_00C3FB58 * D_0090147C + D_00C3F784 && lolo.hit_right < D_00C3FB58 * D_0090147C + D_00C3F784 &&
			lolo.hit_top > D_00C3FB5C * D_00901480 + D_00C3F788 && lolo.hit_bottom < D_00C3FB5C * D_00901480 + D_00C3F788 &&
			D_00C3FA70 == 1
		) {
			bp0c->f_028.dwIsHit = 1;
		}
	}
}

//render "car"/compute "rays" projection?
void C_005E9CB5(struct t_coaster_Node *pNode/*bp08*/) {
	struct {
		struct SVECTOR *local_27;
		struct t_coaster_RenderInfo local_26;
		int local_22[6];
		struct MATRIX local_16; char _ocal_16[2];
		struct MATRIX local_8; char _ocal_8[2];
	}lolo;

	D_00C3F8A0.f_12[0] =
	D_00C3F8A0.f_12[1] =
	D_00C3F8A0.f_12[2] = 0;
	if(pNode->pParentNode != &D_00C60150) {
		//-- multiply with parent(if any)'s matrix[unused] --
		C_00661E85(&(pNode->pParentNode->f_04), &(pNode->f_04), &lolo.local_16);//psx:matrix multiplication too?
		C_00661E85(&lolo.local_16, &D_00C3F8A0, &lolo.local_8);//psx:matrix multiplication too?
	} else {
		C_00661E85(&(pNode->f_04), &D_00C3F8A0, &lolo.local_8);//psx:matrix multiplication too?
	}
	lolo.local_26.pTriangles = pNode->pModel->pTriangles;
	lolo.local_26.pModel = pNode->pModel;
	D_00C3F888->C_005F27BF(&lolo.local_8);//update some matrix stuff?
	if(D_009014A8)
		D_00C3F888->C_005EFA3A(&lolo.local_26);//render object
	//-- right ray --
	lolo.local_27 = D_00C5D22C->pTriangles[0].f_00;
	D_00C3F888->C_005EF9CA(lolo.local_27, lolo.local_22);//projection:triangle?
	D_00C3F928 = (lolo.local_22[1] & 0xffff0000) >> 0x10;
	D_00C3F918 = lolo.local_22[1] & 0x0000ffff;
	D_00C3F924 = (lolo.local_22[2] & 0xffff0000) >> 0x10;
	D_00C3F920 = lolo.local_22[2] & 0x0000ffff;
	//-- left ray --
	lolo.local_27 = D_00C5D22C->pTriangles[1].f_00;
	D_00C3F888->C_005EF9CA(lolo.local_27, lolo.local_22);//projection:triangle?
	D_00C3FB48 = (lolo.local_22[1] & 0xffff0000) >> 0x10;
	D_00C3FB4C = lolo.local_22[1] & 0x0000ffff;
	D_00C3FA78 = (lolo.local_22[2] & 0xffff0000) >> 0x10;
	D_00C3FA7C = lolo.local_22[2] & 0x0000ffff;
}

//render object[score]
void C_005E9E37(struct t_coaster_Node *pNode/*bp08*/) {
	struct t_coaster_RenderInfo local_4;

	local_4.pTriangles = pNode->pModel->pTriangles;
	local_4.pModel = pNode->pModel;
	D_00C3F888->C_005F27BF(&(pNode->f_04));//update some matrix stuff?
	if(D_009014A8)
		D_00C3F888->C_005EFACA(&local_4);//render object[for score]
}

//render objects[static]
void C_005E9E7E() {
	struct {
		unsigned short local_3; char _ocal_3[2];
		struct t_coaster_Triangle *local_2;
		struct t_coaster_Triangle *local_1;
	}lolo;

	lolo.local_2 = (struct t_coaster_Triangle *)D_00C3F738.getStream_inline(0xa);
	if(D_00C5039C) {
		lolo.local_3 = D_00C5BF44;
		D_00C3F888->C_005F27BF(&D_00C3F8A0);//update some matrix stuff?
		do {
			lolo.local_1 = &(lolo.local_2[lolo.local_3]);
			if(D_009014A8)
				D_00C3F888->C_005F0482(lolo.local_1);//render triangle[static]
			lolo.local_3 = D_00C503B0[lolo.local_3].wNext;
		} while(lolo.local_3 != 0xffff);
	}
}

//render track
void C_005E9F33() {
	unsigned short local_1;

	local_1 = D_00C503A4;
	D_00C3F888->C_005F27BF(&D_00C3F8A0);//update some matrix stuff?
	do {
		if(D_009014A8)
			D_00C3F888->C_005EFB5A(&(D_00C3F874[local_1]), &(D_00C3F878[local_1]));//render track element
		local_1 = D_00C476F0[local_1].wNext;
	} while(local_1 != 0xffff);
}

//update transform matrix for track
void C_005E9FB3(struct MATRIX *bp08) {
	C_00661939(bp08);//psx:init transformation/matrix?
	bp08->f_12[0] = -D_00C3F8D8.f_00;
	bp08->f_12[1] = -D_00C3F8D8.f_04;
	bp08->f_12[2] = -D_00C3F8D8.f_08;
}

void C_005E9FED(struct MATRIX *bp08, struct MATRIX *bp0c, struct MATRIX *bp10) {
	struct {
		struct t_g_drv_0c local_23;
		float local_20[4];
		D3DMATRIX local_16;
	}lolo;

	lolo.local_23.f_00 = (float)bp0c->f_12[0];
	lolo.local_23.f_04 = (float)bp0c->f_12[1];
	lolo.local_23.f_08 = (float)bp0c->f_12[2];
	C_00661E85(bp08, bp0c, bp10);//psx:matrix multiplication too?
	C_006611FB(bp10, &lolo.local_16);//psx:transformation to D3DMATRIX(1)
	lolo.local_16._41 =
	lolo.local_16._42 =
	lolo.local_16._43 = 0;
	C_0066CE40(&lolo.local_16, &lolo.local_23, lolo.local_20);
	bp10->f_12[0] = (int)lolo.local_20[0] + bp08->f_12[0];
	bp10->f_12[1] = (int)lolo.local_20[1] + bp08->f_12[1];
	bp10->f_12[2] = (int)lolo.local_20[2] + bp08->f_12[2];
}

struct MATRIX *C_005EA099(struct SVECTOR *bp08, struct MATRIX *bp0c) {
	struct {
		D3DMATRIX local_80;
		D3DMATRIX local_64;
		D3DMATRIX local_48;
		D3DMATRIX local_32;
		D3DMATRIX local_16;
	}lolo;

	C_0067BE13((float)bp08->f_00 * 0.087890625f, &lolo.local_64);//dx_mat:x_rotate
	C_0067BE71((float)bp08->f_02 * 0.087890625f, &lolo.local_16);//dx_mat:y_rotate
	C_0067BECE((float)bp08->f_04 * 0.087890625f, &lolo.local_48);//dx_mat:z_rotate
	C_0066C56E(&lolo.local_48, &lolo.local_64, &lolo.local_80);//[optimized]matrix multiplication 3x3
	C_0066C56E(&lolo.local_80, &lolo.local_16, &lolo.local_32);//[optimized]matrix multiplication 3x3
	C_0066C53C(&lolo.local_32);//set matrix to "something"?
	lolo.local_32._41 = (float)bp0c->f_12[0];
	lolo.local_32._42 = (float)bp0c->f_12[1];
	lolo.local_32._43 = (float)bp0c->f_12[2];
	C_0066134B(bp0c, &lolo.local_32);//psx:D3DMATRIX to transformation(1)

	return bp0c;
}

//compute POV/camera vectors?
void C_005EA194(int bp08/*position on track*/, int bp0c, struct VECTOR *bp10, struct SVECTOR *bp14) {
	struct {
		struct SVECTOR *local_55;
		struct VECTOR local_54;
		struct VECTOR local_50;
		struct VECTOR local_46;
		struct SVECTOR *local_42;
		struct VECTOR local_41;
		int local_37;
		struct VECTOR local_36;
		struct SVECTOR *local_32;
		struct VECTOR local_31;
		int local_27;
		int local_26;
		struct SVECTOR *local_25;
		struct VECTOR local_24;
		int local_20;
		struct VECTOR local_19;
		struct SVECTOR *local_15;
		struct VECTOR local_14;
		struct SVECTOR *local_10;
		int local_9;
		struct VECTOR local_8;
		struct VECTOR local_4;
	}lolo;

	lolo.local_37 = (bp08 & 0xffff0000) >> 0x10;
	lolo.local_9 = bp08 & 0x0000ffff;
	//--
	lolo.local_10 = &(D_00C3F870[lolo.local_37]);
	lolo.local_32 = &(D_00C3F870[lolo.local_37+1]);
	lolo.local_20 = lolo.local_32->f_00 - lolo.local_10->f_00;
	lolo.local_26 = (lolo.local_32->f_02 - lolo.local_10->f_02) / 0x20;
	lolo.local_27 = lolo.local_32->f_04 - lolo.local_10->f_04;
	if(lolo.local_20 > 0x800)
		lolo.local_20 -= 0x1000;
	if(lolo.local_26 > 0x800)
		lolo.local_26 -= 0x1000;
	if(lolo.local_27 > 0x800)
		lolo.local_27 -= 0x1000;
	if(lolo.local_20 < -0x800)
		lolo.local_20 += 0x1000;
	if(lolo.local_26 < -0x800)
		lolo.local_26 += 0x1000;
	if(lolo.local_27 < -0x800)
		lolo.local_27 += 0x1000;
	lolo.local_20 = lolo.local_9 * lolo.local_20;
	lolo.local_26 = lolo.local_9 * lolo.local_26;
	lolo.local_27 = lolo.local_9 * lolo.local_27;
	lolo.local_20 >>= 0x10;
	lolo.local_26 >>= 0x10;
	lolo.local_27 >>= 0x10;
	//--
	lolo.local_25 = &(D_00C3F874[lolo.local_37]);
	lolo.local_55 = &(D_00C3F874[lolo.local_37+1]);
	lolo.local_4.f_00 = (lolo.local_55->f_00 - lolo.local_25->f_00) * lolo.local_9;
	lolo.local_4.f_04 = (lolo.local_55->f_02 - lolo.local_25->f_02) * lolo.local_9;
	lolo.local_4.f_08 = (lolo.local_55->f_04 - lolo.local_25->f_04) * lolo.local_9;
	lolo.local_8.f_00 = lolo.local_25->f_00 + (short)(lolo.local_4.f_00 >> 0x10);
	lolo.local_8.f_04 = lolo.local_25->f_02 + (short)(lolo.local_4.f_04 >> 0x10);
	lolo.local_8.f_08 = lolo.local_25->f_04 + (short)(lolo.local_4.f_08 >> 0x10);
	//--
	lolo.local_15 = &(D_00C3F878[lolo.local_37]);
	lolo.local_42 = &(D_00C3F878[lolo.local_37+1]);
	lolo.local_46.f_00 = (lolo.local_42->f_00 - lolo.local_15->f_00) * lolo.local_9;
	lolo.local_46.f_04 = (lolo.local_42->f_02 - lolo.local_15->f_02) * lolo.local_9;
	lolo.local_46.f_08 = (lolo.local_42->f_04 - lolo.local_15->f_04) * lolo.local_9;
	lolo.local_31.f_00 = lolo.local_15->f_00 + (short)(lolo.local_46.f_00 >> 0x10);
	lolo.local_31.f_04 = lolo.local_15->f_02 + (short)(lolo.local_46.f_04 >> 0x10);
	lolo.local_31.f_08 = lolo.local_15->f_04 + (short)(lolo.local_46.f_08 >> 0x10);
	//--
	lolo.local_41.f_00 = (lolo.local_31.f_00 + lolo.local_8.f_00) >> 1;
	lolo.local_41.f_04 = (lolo.local_31.f_04 + lolo.local_8.f_04) >> 1;
	lolo.local_41.f_08 = (lolo.local_31.f_08 + lolo.local_8.f_08) >> 1;

	lolo.local_54.f_00 = (lolo.local_15->f_00 + lolo.local_25->f_00) >> 1;
	lolo.local_54.f_04 = (lolo.local_15->f_02 + lolo.local_25->f_02) >> 1;
	lolo.local_54.f_08 = (lolo.local_15->f_04 + lolo.local_25->f_04) >> 1;

	lolo.local_24.f_00 = (lolo.local_42->f_00 + lolo.local_55->f_00) >> 1;
	lolo.local_24.f_04 = (lolo.local_42->f_02 + lolo.local_55->f_02) >> 1;
	lolo.local_24.f_08 = (lolo.local_42->f_04 + lolo.local_55->f_04) >> 1;
	//-- lolo.local_50 = lolo.local_24 - lolo.local_54
	lolo.local_50.f_00 = lolo.local_24.f_00 - lolo.local_54.f_00;
	lolo.local_50.f_04 = lolo.local_24.f_04 - lolo.local_54.f_04;
	lolo.local_50.f_08 = lolo.local_24.f_08 - lolo.local_54.f_08;
	//--lolo.local_19 = lolo.local_31 - lolo.local_8
	lolo.local_19.f_00 = lolo.local_31.f_00 - lolo.local_8.f_00;
	lolo.local_19.f_04 = lolo.local_31.f_04 - lolo.local_8.f_04;
	lolo.local_19.f_08 = lolo.local_31.f_08 - lolo.local_8.f_08;
	//--
	C_00663B32(&lolo.local_50, &lolo.local_19, &lolo.local_36);//psx:vector cross product
	C_006638B0(&lolo.local_36, &lolo.local_14);//psx:VectorNormal?
	//-- POV//lookAt vector?
	bp10->f_00 = (short)lolo.local_41.f_00 + ((lolo.local_14.f_00 * bp0c) >> 0xc);
	bp10->f_04 = (short)lolo.local_41.f_04 + ((lolo.local_14.f_04 * bp0c) >> 0xc);
	bp10->f_08 = (short)lolo.local_41.f_08 + ((lolo.local_14.f_08 * bp0c) >> 0xc);
	//--
	bp14->f_00 = lolo.local_10->f_00 + lolo.local_20;
	bp14->f_02 = -lolo.local_10->f_02 + lolo.local_26;
	bp14->f_04 = lolo.local_10->f_04 + lolo.local_27;
}

//render "last shoot score"
void C_005EA5FD(short wModelId/*bp08*/, int inc_alpha/*bp0c*/, int inc_beta/*bp10*/, int inc_gamma/*bp14*/) {
	struct MATRIX local_16 = {0};
	struct MATRIX local_8 = {
		{
			0x200, 0, 0,
			0, 0x200, 0,
			0, 0, 0x200
		},
		{130, 0, 400}
	};
//	local_16.f_00[0][0] = 0; memset(&(local_16.f_00[0][1]), 0, sizeof(struct MATRIX) - 2);

//	local_8.f_00[0][0] = 0x200; local_8.f_00[0][1] = 0; local_8.f_00[0][2] = 0;
//	local_8.f_00[1][0] = 0; local_8.f_00[1][1] = 0x200; local_8.f_00[1][2] = 0;
//	local_8.f_00[2][0] = 0; local_8.f_00[2][1] = 0; local_8.f_00[2][2] = 0x200;
//	local_8.f_12[0] = 130;
//	local_8.f_12[1] = 0;
//	local_8.f_12[2] = 400;
	if(wModelId != 0 && wModelId != 0x5b) {
		D_00C3F880->pModel = D_00C5D0F0[wModelId];
		//-- rotate model --
		D_00C3F728.f_00 += inc_alpha;
		D_00C3F728.f_02 += inc_beta;
		D_00C3F728.f_04 += inc_gamma;
		//-- render --
		if(D_00C3F730 == 1) {//else 005EA72E
			C_00662AD8(&D_00C3F728, &local_16);
			C_00661E85(&local_16, &local_8, &(D_00C3F880->f_04));//psx:matrix multiplication too?
			C_005E9E37(D_00C3F880);//render object[score]
			if(D_009014A8)
				D_00C3F888->C_005F2119(D_00C3F6F4, 440, 320, 0);//render number
		}
		//-- blink --
		if((-- D_00C3F724) < 50) {//else 005EA765
			if(D_00C3F730 == 0)
				D_00C3F730 = 1;
			else
				D_00C3F730 = 0;
		}
		//-- finished --
		if(D_00C3F724 == 0)
			D_00C3F76C = 0;
	}
}

//draw alpha quad
void C_005EA77E(unsigned char bp08) {
	if(D_009014A8)
		D_00C3F888->C_005F2417(bp08);//render alpha quad
}

//render "sight"
void C_005EA79B() {
	if(D_009014A8)
		D_00C3F888->C_005F09C4();//render "sight"
}

//refresh "shoot rays"
void C_005EA7B4() {
	if(D_00C3FA70 == 1)
		D_00C3F888->C_005F0C81();//refresh "shoot rays"
}

//render 2D infos
void C_005EA7D0() {
	if(D_009014A8) {
		D_00C3F888->C_005F15C7();//render "shoot gauge"
		D_00C3F888->C_005F1838();//render "waku"
		D_00C3F888->C_005F1A71();//render "status box"
		D_00C3F888->C_005F1F00();//render "score"
	}
}

//coaster:in pause
void C_005EA80A() {
	if(D_009014A8) {
		D_00C3F888->C_005F1A71();//render "status box"
		D_00C3F888->C_005F1CB5();//render "pause"
	}
}

//coaster:"refresh" graphics
void C_005EA82E() {
	if(D_009014A8)
		D_00C3F888->C_005F2924();//"refresh" graphics
}

//coaster:end
void C_005EA847() {
	delete D_00C3F888;
	C_00675F1D(9);//is_lib:close archive
	C_005E92D8();//release psxdata_c/sounds
	C_006900FC(D_00C3F7A8, 0);//direct:change directory?
}
