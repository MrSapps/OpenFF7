//coaster -- game objects

#include "ff7.h"

#include "coaster_data.h"

#include <time.h>

////////////////////////////////////////
int D_00C3F908;
int D_00C3F90C;
int D_00C3F910;
//00C3F914
short D_00C3F918;//ray_00.x
int D_00C3F91C;//current object number
short D_00C3F920;//ray_01.x
short D_00C3F924;//ray_01.y
short D_00C3F928;//ray_00.y
struct t_coaster_GameObject D_00C3F930;//temporary object for creation
short D_00C3FA6C;//current index
char D_00C3FA70;//shoot
char D_00C3FA74;//shoot repeat counter
short D_00C3FA78;//ray_11.y
short D_00C3FA7C;//ray_11.x
short D_00C3FA80[0x64];//indexes pool
short D_00C3FB48;//ray_10.y
short D_00C3FB4C;//ray_10.x
short D_00C3FB50;//shoot power
short D_00C3FB54;//# gameObjects
short D_00C3FB58,D_00C3FB5C;//cursor X,Y
struct SVECTOR *D_00C3FB60;//trajectory stream vector?
//00C3FB64
struct t_coaster_GameObject D_00C3FB68[0x64];
int D_00C476D8;//object stream index?
char D_00C476DC;//shoot related counter[for beam display]
int D_00C476E0;//trajectory stream index?
////////////////////////////////////////
//init this module
void C_005EAB70() {
	int i;//local_1

	for(i = 0; i < 0x64; i ++) {
		D_00C3FB68[i].wObjIndex = -1;
		D_00C3FB68[i].wIsActive = 0;
	}
	D_00C3FA6C = 0;
	for(i = 0; i < 0x64; i ++) {
		D_00C3FA80[i] = i + 1;
	}
	D_00C3FB50 = 0x80;
	D_00C3FA70 = 0;
	D_00C3FA74 = 0;
	D_00C3FB58 = 0xa0;
	D_00C3FB5C = 0x78;
	D_00C3F91C = 0;
	D_00C476D8 = 0;
	D_00C3FB54 = 0;
}

//start trajectory?
void C_005EAC30(unsigned char bp08, int bp0c) {
	struct {
		int *pLength;//local_3
		int *pOffset;//local_2
		int dwOffset;//local_1
	}lolo;

	if(bp0c == 0) {
		lolo.pLength = (int *)D_00C3F738.getStream_inline(0xd);
		lolo.pOffset = (int *)D_00C3F738.getStream_inline(0xc);
		D_00C476E0 = lolo.pLength[bp08];
		lolo.dwOffset = lolo.pOffset[bp08];
		D_00C3FB60 = (struct SVECTOR *)(D_00C3F738.getStream_inline(0xb) + lolo.dwOffset);
	}
	if(bp0c == 1) {//player's car only?
		lolo.pLength = (int *)D_00C3F738.getStream_inline(6);
		lolo.pOffset = (int *)D_00C3F738.getStream_inline(5);
		D_00C476E0 = lolo.pLength[bp08];
		lolo.dwOffset = lolo.pOffset[bp08];
		D_00C3FB60 = (struct SVECTOR *)(D_00C3F738.getStream_inline(4) + lolo.dwOffset);
	}
}

//update trajectory?
void C_005EADE6(int bp08, struct SVECTOR *bp0c, struct VECTOR *bp10, char bp14) {
	struct {
		struct SVECTOR point_1;//local_10
		int paramDecPart;//local_8
		struct SVECTOR point_0;//local_7
		struct VECTOR local_5;
		int paramIntPart;//local_1
	}lolo;

	lolo.paramIntPart = (bp08 & 0xffff0000) >> 0x10;
	lolo.paramDecPart = bp08 & 0x0000ffff;

	lolo.point_0.f_00 = bp0c[lolo.paramIntPart].f_00;
	lolo.point_0.f_02 = bp0c[lolo.paramIntPart].f_02;
	lolo.point_0.f_04 = bp0c[lolo.paramIntPart].f_04;

	lolo.point_1.f_00 = bp0c[lolo.paramIntPart + 1].f_00;
	lolo.point_1.f_02 = bp0c[lolo.paramIntPart + 1].f_02;
	lolo.point_1.f_04 = bp0c[lolo.paramIntPart + 1].f_04;

	lolo.local_5.f_00 = lolo.point_1.f_00 - lolo.point_0.f_00;
	lolo.local_5.f_04 = lolo.point_1.f_02 - lolo.point_0.f_02;
	lolo.local_5.f_08 = lolo.point_1.f_04 - lolo.point_0.f_04;
	//-- --
	lolo.local_5.f_00 *= lolo.paramDecPart;
	lolo.local_5.f_04 *= lolo.paramDecPart;
	lolo.local_5.f_08 *= lolo.paramDecPart;
	lolo.local_5.f_00 >>= 0x10;
	lolo.local_5.f_04 >>= 0x10;
	lolo.local_5.f_08 >>= 0x10;
	//note:bp14 is always 0
	if(bp14 == 0) {
		bp10->f_00 = bp0c[lolo.paramIntPart].f_00 + lolo.local_5.f_00;
		bp10->f_04 = -bp0c[lolo.paramIntPart].f_02 - lolo.local_5.f_04;
		bp10->f_08 = -bp0c[lolo.paramIntPart].f_04 - lolo.local_5.f_08;
	} else {
		bp10->f_00 = bp0c[lolo.paramIntPart].f_00 + lolo.local_5.f_00;
		bp10->f_04 = bp0c[lolo.paramIntPart].f_02 + lolo.local_5.f_04;
		bp10->f_08 = bp0c[lolo.paramIntPart].f_04 + lolo.local_5.f_08;
	}
}

short C_005EB342(void);//generate new index

//create new object
short C_005EAF45(struct t_coaster_GameObject *bp08, short bp0c) {
	struct {
		short x_0; char _ocal_8[2];//local_8
		short y_1; char _ocal_7[2];//local_7
		short x_1; char _ocal_6[2];//local_6
		short z_0; char _ocal_5[2];//local_5
		short wObjIndex; char _ocal_4[2];//local_4
		short y_0; char _ocal_3[2];//local_3
		short z_1; char _ocal_2[2];//local_2
		short wModelId; char _ocal_1[2];//local_1
	}lolo;

	if(D_00C3FB54 < 0x63) {//else 005EB2D5
		D_00C3FB54 ++;
		lolo.wObjIndex = C_005EB342();//generate new index
		D_00C3FB68[lolo.wObjIndex] = *bp08;
		lolo.wModelId = bp08->f_028.dwModelId;
		D_00C3FB68[lolo.wObjIndex].wObjIndex = lolo.wObjIndex;
		D_00C3FB68[lolo.wObjIndex].wIsActive = 1;
		if(bp0c == 0)
			D_00C3FB68[lolo.wObjIndex].pNode = C_005EF31E(lolo.wModelId, &D_00C60150, bp08->sPos.f_00, bp08->sPos.f_04, bp08->sPos.f_08, bp08->sRot.f_00, bp08->sRot.f_02, bp08->sRot.f_04);//allocate "Node"
		else
			D_00C3FB68[lolo.wObjIndex].pNode = C_005EF31E(lolo.wModelId, D_00C3FB68[bp0c].pNode, bp08->sPos.f_00, bp08->sPos.f_04, bp08->sPos.f_08, bp08->sRot.f_00, bp08->sRot.f_02, bp08->sRot.f_04);//allocate "Node"
		//-- compute bounding volume, center of each six faces  --
		lolo.x_0 = D_00C5D0E4[lolo.wModelId].f_04.f_00; lolo.x_1 = D_00C5D0E4[lolo.wModelId].f_0c.f_00;
		lolo.y_0 = D_00C5D0E4[lolo.wModelId].f_04.f_02; lolo.y_1 = D_00C5D0E4[lolo.wModelId].f_0c.f_02;
		lolo.z_0 = D_00C5D0E4[lolo.wModelId].f_04.f_04; lolo.z_1 = D_00C5D0E4[lolo.wModelId].f_0c.f_04;

		D_00C3FB68[lolo.wObjIndex].sBoundingBox[0].f_00 = (lolo.x_1 + lolo.x_0) >> 1;
		D_00C3FB68[lolo.wObjIndex].sBoundingBox[0].f_02 = (lolo.y_1 + lolo.y_0) >> 1;
		D_00C3FB68[lolo.wObjIndex].sBoundingBox[0].f_04 = lolo.z_1;

		D_00C3FB68[lolo.wObjIndex].sBoundingBox[1].f_00 = (lolo.x_1 + lolo.x_0) >> 1;
		D_00C3FB68[lolo.wObjIndex].sBoundingBox[1].f_02 = (lolo.y_1 + lolo.y_0) >> 1;
		D_00C3FB68[lolo.wObjIndex].sBoundingBox[1].f_04 = lolo.z_0;

		D_00C3FB68[lolo.wObjIndex].sBoundingBox[2].f_00 = (lolo.x_1 + lolo.x_0) >> 1;
		D_00C3FB68[lolo.wObjIndex].sBoundingBox[2].f_02 = lolo.y_1;
		D_00C3FB68[lolo.wObjIndex].sBoundingBox[2].f_04 = (lolo.z_1 + lolo.z_0) >> 1;

		D_00C3FB68[lolo.wObjIndex].sBoundingBox[3].f_00 = (lolo.x_1 + lolo.x_0) >> 1;
		D_00C3FB68[lolo.wObjIndex].sBoundingBox[3].f_02 = lolo.y_0;
		D_00C3FB68[lolo.wObjIndex].sBoundingBox[3].f_04 = (lolo.z_1 + lolo.z_0) >> 1;

		D_00C3FB68[lolo.wObjIndex].sBoundingBox[4].f_00 = lolo.x_1;
		D_00C3FB68[lolo.wObjIndex].sBoundingBox[4].f_02 = (lolo.y_1 + lolo.y_0) >> 1;
		D_00C3FB68[lolo.wObjIndex].sBoundingBox[4].f_04 = (lolo.z_1 + lolo.z_0) >> 1;

		D_00C3FB68[lolo.wObjIndex].sBoundingBox[5].f_00 = lolo.x_0;
		D_00C3FB68[lolo.wObjIndex].sBoundingBox[5].f_02 = (lolo.y_1 + lolo.y_0) >> 1;
		D_00C3FB68[lolo.wObjIndex].sBoundingBox[5].f_04 = (lolo.z_1 + lolo.z_0) >> 1;
	}

	return lolo.wObjIndex;
}

void C_005EB36E(short);//release index

//release object
void C_005EB2DF(struct t_coaster_GameObject *bp08) {
	if(bp08->wObjIndex != -1) {
		D_00C3FB54 --;
		C_005EF3BF(bp08->pNode);//release "Node"
		C_005EB36E(bp08->wObjIndex);//release index
		bp08->wObjIndex = -1;
		bp08->wIsActive = 0;
	}
}

//generate new index
short C_005EB342() {
	short wObjIndex;//local_1

	wObjIndex = D_00C3FA6C;
	D_00C3FA6C = D_00C3FA80[D_00C3FA6C];

	return wObjIndex;
}

//release index
void C_005EB36E(short wObjIndex/*bp08*/) {
	D_00C3FA80[wObjIndex] = D_00C3FA6C;
	D_00C3FA6C = wObjIndex;
}

struct t_coaster_GameObjectInfo {//size 0x60
	/*+00*/int dwObjType;
	/*+04*/int dwModelId;
	/*+08*/int f_08;//trajectory index
	/*+0c*/int f_0c;//some increment?
	/*+10*/int f_10[0x14];//scratchpad
};

void C_005EB507(short, short, short, short, short);//create new object[1]

//add new objects?
void C_005EB391() {
	struct {
		char *bp_14;
		int k;//bp_10
		struct t_coaster_GameObjectInfo *bp_0c;
		int j;//bp_08
		int i;//bp_04
	}lolo;

	for(lolo.i = D_00C3F91C; lolo.i < D_00C3F75C; lolo.i ++) {
		lolo.bp_14 = (char *)(D_00C3F738.getStream_inline(0xf) + lolo.i);
		for(lolo.j = 0; lolo.j < *lolo.bp_14; lolo.j ++) {
			lolo.bp_0c = (struct t_coaster_GameObjectInfo *)D_00C3F738.getStream_inline(0xe);
			for(lolo.k = 0; lolo.k < 0x14; lolo.k ++)
				D_00C3F930.f_028.f_50[lolo.k] = lolo.bp_0c[D_00C476D8].f_10[lolo.k];
			D_00C3F930.f_028.f_18 = lolo.bp_0c[D_00C476D8].f_08;
			D_00C3F930.f_028.f_1c = lolo.bp_0c[D_00C476D8].f_0c;
			C_005EB507(0, 0, 0, lolo.bp_0c[D_00C476D8].dwObjType, lolo.bp_0c[D_00C476D8].dwModelId);//create new object[1]
			D_00C476D8 ++;
		}
	}
	D_00C3F91C = D_00C3F75C;
}

//create new object[1]
void C_005EB507(short x/*bp08*/, short  y/*bp0c*/, short z/*bp10*/, short wObjType/*bp14*/, short wModelId/*bp18*/) {
	short wObjIndex;//local_1

	D_00C3F930.sPos.f_00 = x;
	D_00C3F930.sPos.f_04 = y;
	D_00C3F930.sPos.f_08 = z;
	D_00C3F930.f_028.dwType = wObjType;
	D_00C3F930.f_028.dwMustInit = 1;
	D_00C3F930.f_028.dwModelId = wModelId;
	D_00C3F930.f_028.dwIsHit = 0;

	wObjIndex = C_005EAF45(&D_00C3F930, 0);//create new object
}

//create new object[2]
void C_005EB566(short x/*bp08*/, short  y/*bp0c*/, short z/*bp10*/, short wObjType/*bp14*/, short wModelId/*bp18*/) {
	short wObjIndex;//local_1

	D_00C3F930.sPos.f_00 = x;
	D_00C3F930.sPos.f_04 = y;
	D_00C3F930.sPos.f_08 = z;
	D_00C3F930.f_028.dwType = wObjType;
	D_00C3F930.f_028.dwMustInit = 1;
	D_00C3F930.f_028.dwModelId = wModelId;
	D_00C3F930.f_028.dwIsHit = 0;
	D_00C3F930.f_028.f_50[0xc] = 0;
	wObjIndex = C_005EAF45(&D_00C3F930, 0);//create new object
}

void C_005ED528(struct t_coaster_GameObject *);//object is hit

//refresh game objects?
void C_005EB5CF() {
	struct {//bp_6c and above for compiler
		struct t_coaster_GameObject *bp_68;
		int deltaY;//bp_64
		int newX;//bp_60
		int deltaX;//bp_5c
		int bp_58;
		char bp_54; char _p_54[3];
		char bIsPlayerCar; char _p_50[3];//bp_50
		int i;//bp_4c
		struct VECTOR bp_48;
		short bp_38; char _p_38[2];
		struct SVECTOR bp_34;
		unsigned char bp_2c; char _p_2c[3];
		int j;//bp_28
		struct t_coaster_ObjectState *bp_24;
		int bp_20;
		struct VECTOR bp_1c;
		int newZ;//bp_0c
		int deltaZ;//bp_08
		int newY;//bp_04
	}lolo;

	C_005EB391();//add new objects?
	C_005EA79B();//render "sight"
	C_005EA7B4();//refresh "shoot rays"

	for(lolo.i = 0; lolo.i < 0x64; lolo.i ++) {
		lolo.bp_68 = &(D_00C3FB68[lolo.i]);
		lolo.bp_24 = &(lolo.bp_68->f_028);
		lolo.bp_38 = 0;
		if(lolo.bp_68->wIsActive) {//else 005ED477
			lolo.bp_54 = 0;
			lolo.bIsPlayerCar = 0;
			switch(lolo.bp_24->dwType) {
				case 0x64:
					if(lolo.bp_24->dwMustInit == 1) {
						C_005EAC30(lolo.bp_24->f_18, 0);//start trajectory?
						lolo.bp_68->f_0cc = D_00C3FB60;
						lolo.bp_68->f_0c8 = D_00C476E0;
						lolo.bp_24->dwMustInit = 0;
						lolo.bp_24->f_0c = 1;
						lolo.bp_24->f_14 = 0;
						lolo.bp_24->dwIsHit = 0;
						lolo.bp_24->f_50[0xa] = 1;
						lolo.bp_24->f_28 = 0;
						lolo.bp_24->f_2c = lolo.bp_68->sPos.f_00;
						lolo.bp_24->f_30 = lolo.bp_68->sPos.f_04;
						lolo.bp_24->f_34 = lolo.bp_68->sPos.f_08;
						lolo.bp_24->f_50[0] = 0;
					} else {
						lolo.bp_24->f_14 ++;
						lolo.bp_24->f_28 ++;
					}
					if(lolo.bp_24->f_0c) {//else 005EB8B0
						lolo.bp_58 = lolo.bp_24->f_28;
						C_005EA194(D_00C3F778 + 0x2fffd, -100, &lolo.bp_1c, &lolo.bp_34);//compute POV/camera vectors?
						lolo.newX = lolo.bp_24->f_2c + ((lolo.bp_58 * (-lolo.bp_24->f_2c + lolo.bp_1c.f_00)) >> 7);
						lolo.newY = lolo.bp_24->f_30 + ((lolo.bp_58 * (-lolo.bp_24->f_30 + lolo.bp_1c.f_04)) >> 7);
						lolo.newZ = lolo.bp_24->f_34 + ((lolo.bp_58 * (-lolo.bp_24->f_34 + lolo.bp_1c.f_08)) >> 7);
						lolo.bp_68->sPos.f_00 = lolo.newX;
						lolo.bp_68->sPos.f_04 = lolo.newY;
						lolo.bp_68->sPos.f_08 = lolo.newZ;
						C_005EA194(D_00C3F778 + 0x3fffc, -100, &lolo.bp_1c, &lolo.bp_34);//compute POV/camera vectors?
						lolo.deltaX = lolo.bp_68->sPos.f_00 - lolo.bp_1c.f_00;
						lolo.deltaY = lolo.bp_68->sPos.f_04 - lolo.bp_1c.f_04;
						lolo.deltaZ = lolo.bp_68->sPos.f_08 - lolo.bp_1c.f_08;
						lolo.bp_20 = C_00663736(lolo.deltaX * lolo.deltaX + lolo.deltaY * lolo.deltaY + lolo.deltaZ * lolo.deltaZ);//psx:SquareRoot0?
						if(lolo.bp_24->f_14 > 0x80) {//else 005EB899
							if(D_00C3F74C > 5)
								D_00C3F74C -= 5;
							else
								D_00C3F74C = 0;
							lolo.bp_24->f_0c = 0;
						}
						//-- hit management --
						if(lolo.bp_24->dwIsHit)
							C_005ED528(lolo.bp_68);//object is hit
						//-- --
					} else {
						C_005EB2DF(lolo.bp_68);//release object
					}
				break;
				case 0x11:
					if(lolo.bp_24->dwMustInit == 1) {//else 005EB965
						if(lolo.bp_24->f_50[0x11])
							C_005E94E5(lolo.bp_24->f_50[0x11]);//sound related(3)
						C_005EAC30(lolo.bp_24->f_18, 0);//start trajectory?
						lolo.bp_68->f_0cc = D_00C3FB60;
						lolo.bp_68->f_0c8 = D_00C476E0;
						lolo.bp_24->dwMustInit = 0;
						lolo.bp_24->f_0c = 1;
						lolo.bp_24->f_14 = 0;
						lolo.bp_24->dwIsHit = 0;
						lolo.bp_24->f_28 = 0;
						lolo.bp_24->f_2c = (lolo.bp_68->f_0c8 - 2) << 0x10;
					} else {
						lolo.bp_24->f_14 ++;
					}
					if(lolo.bp_24->f_50[3] < D_00C3F75C)
						lolo.bp_24->f_28 += lolo.bp_24->f_1c;
					if(lolo.bp_24->f_50[2] < D_00C3F75C)
						lolo.bp_24->f_0c = 0;
					if(lolo.bp_24->f_0c) {//else 005EBA14
						//-- hit management --
						if(lolo.bp_24->dwIsHit)
							C_005ED528(lolo.bp_68);//object is hit
						//-- --
						if(lolo.bp_24->f_28 < lolo.bp_24->f_2c) {
							C_005EADE6(lolo.bp_24->f_28, lolo.bp_68->f_0cc, &(lolo.bp_68->sPos), 0);//update trajectory?
							lolo.bp_68->sRot.f_00 = 0;
							lolo.bp_68->sRot.f_02 = 0;
							lolo.bp_68->sRot.f_04 = 0;
						}
					} else {
						C_005EB2DF(lolo.bp_68);//release object
					}
				break;
				case 0x00://projectors?
					if(lolo.bp_24->dwMustInit == 1) {//else 005EBAC9
						if(lolo.bp_24->f_50[0x11])
							C_005E94E5(lolo.bp_24->f_50[0x11]);//sound related(3)
						C_005EAC30(lolo.bp_24->f_18, 0);//start trajectory?
						lolo.bp_68->f_0cc = D_00C3FB60;
						lolo.bp_68->f_0c8 = D_00C476E0;
						lolo.bp_24->dwMustInit = 0;
						lolo.bp_24->f_0c = 1;
						lolo.bp_24->f_14 = 0;
						lolo.bp_24->dwIsHit = 0;
						lolo.bp_24->f_28 = 0;
						lolo.bp_24->f_2c = (lolo.bp_68->f_0c8 - 1) << 0x10;
					} else {
						lolo.bp_24->f_14 ++;
					}
					lolo.bp_24->f_28 += lolo.bp_24->f_1c;
					if(lolo.bp_24->f_50[1] == 1)
						lolo.bp_24->f_28 %= lolo.bp_24->f_2c;
					if(lolo.bp_24->f_28 > lolo.bp_24->f_2c)
						lolo.bp_24->f_0c = 0;
					if(lolo.bp_24->f_50[2] < D_00C3F75C)
						lolo.bp_24->f_0c = 0;
					if(lolo.bp_24->f_0c) {
						C_005EADE6(lolo.bp_24->f_28, lolo.bp_68->f_0cc, &(lolo.bp_68->sPos), 0);//update trajectory?
						lolo.bp_68->sRot.f_00 += lolo.bp_24->f_50[3];
						lolo.bp_68->sRot.f_02 += lolo.bp_24->f_50[4];
						lolo.bp_68->sRot.f_04 += lolo.bp_24->f_50[5];
						//-- hit management --
						if(lolo.bp_24->dwIsHit)
							C_005ED528(lolo.bp_68);//object is hit
						//-- --
					} else {
						C_005EB2DF(lolo.bp_68);//release object
					}
				break;
				case 0x01:
					if(lolo.bp_24->dwMustInit == 1) {//else 005EBC68
						if(lolo.bp_24->f_50[0x11])
							C_005E94E5(lolo.bp_24->f_50[0x11]);//sound related(3)
						C_005EAC30(lolo.bp_24->f_18, 0);//start trajectory?
						lolo.bp_68->f_0cc = D_00C3FB60;
						lolo.bp_68->f_0c8 = D_00C476E0;
						lolo.bp_24->dwMustInit = 0;
						lolo.bp_24->f_0c = 1;
						lolo.bp_24->f_14 = 0;
						lolo.bp_24->dwIsHit = 0;
						lolo.bp_24->f_28 = 0;
						lolo.bp_24->f_2c = (lolo.bp_68->f_0c8 - 1) << 0x10;
					} else {
						lolo.bp_24->f_14 ++;
					}
					lolo.bp_24->f_28 += lolo.bp_24->f_1c;
					if(lolo.bp_24->f_50[1] == 1)
						lolo.bp_24->f_28 %= lolo.bp_24->f_2c;
					if(lolo.bp_24->f_28 > lolo.bp_24->f_2c)
						lolo.bp_24->f_0c = 0;
					if(lolo.bp_24->f_50[2] < D_00C3F75C)
						lolo.bp_24->f_0c = 0;
					if(lolo.bp_24->f_0c) {
						C_005EADE6(lolo.bp_24->f_28, lolo.bp_68->f_0cc, &(lolo.bp_68->sPos), 0);//update trajectory?
						C_005EADE6((lolo.bp_24->f_28 + (1 << 0x10)) % ((lolo.bp_68->f_0c8 - 1) << 0x10), lolo.bp_68->f_0cc, &lolo.bp_48, 0);//update trajectory?
						lolo.deltaX = lolo.bp_48.f_00 - lolo.bp_68->sPos.f_00;
						lolo.deltaY = lolo.bp_48.f_04 - lolo.bp_68->sPos.f_04;
						lolo.deltaZ = lolo.bp_48.f_08 - lolo.bp_68->sPos.f_08;
						lolo.bp_68->sRot.f_00 = C_00662573(lolo.deltaY, C_00663736(lolo.deltaX * lolo.deltaX + lolo.deltaZ * lolo.deltaZ));//psx:atan2?
						lolo.bp_68->sRot.f_02 = -C_00662573(lolo.deltaZ, lolo.deltaX) - 0x400;//psx:atan2?
						lolo.bp_68->sRot.f_04 = 0;
						//-- hit management --
						if(lolo.bp_24->dwIsHit)
							C_005ED528(lolo.bp_68);//object is hit
						//-- --
					} else {
						C_005EB2DF(lolo.bp_68);//release object
					}
				break;
				case 0x0a://player's car?
					if(lolo.bp_24->dwMustInit == 1) {//else 005EBE74
						if(lolo.bp_24->f_50[0x11])
							C_005E94E5(lolo.bp_24->f_50[0x11]);//sound related(3)
						C_005EAC30(0, 1);//start trajectory?
						lolo.bp_68->f_0cc = D_00C3FB60;
						lolo.bp_68->f_0c8 = D_00C476E0;
						lolo.bp_24->dwMustInit = 0;
						lolo.bp_24->f_0c = 1;
						lolo.bp_24->f_14 = 0;
						lolo.bp_24->dwIsHit = 0;
						lolo.bp_24->f_28 = 0;
						lolo.bp_24->f_2c = (lolo.bp_68->f_0c8 - 1) << 0x10;
					} else {
						lolo.bp_24->f_14 ++;
					}
					lolo.bp_24->f_28 += lolo.bp_24->f_1c;
					if(lolo.bp_24->f_50[1] == 1)
						lolo.bp_24->f_28 %= lolo.bp_24->f_2c;
					if(lolo.bp_24->f_28 > lolo.bp_24->f_2c)
						lolo.bp_24->f_0c = 0;
					if(lolo.bp_24->f_50[2] < D_00C3F75C)
						lolo.bp_24->f_0c = 0;
					if(lolo.bp_24->f_0c) {
						lolo.bIsPlayerCar = 1;
						C_005EA194(D_00C3F778 + 0x3fffc, 10, &(lolo.bp_68->sPos), &(lolo.bp_68->sRot));//compute POV/camera vectors?
						//-- hit management --
						if(lolo.bp_24->dwIsHit)
							C_005ED528(lolo.bp_68);//object is hit
						//-- --
					} else {
						C_005EB2DF(lolo.bp_68);//release object
					}

				break;
				case 0x04:
					if(lolo.bp_24->dwMustInit == 1) {//else 005EBFCA
						if(lolo.bp_24->f_50[0x11])
							C_005E94E5(lolo.bp_24->f_50[0x11]);//sound related(3)
						C_005EAC30(lolo.bp_24->f_18, 0);//start trajectory?
						lolo.bp_68->f_0cc = D_00C3FB60;
						lolo.bp_68->f_0c8 = D_00C476E0;
						lolo.bp_24->dwMustInit = 0;
						lolo.bp_24->f_0c = 1;
						lolo.bp_24->dwIsHit = 0;
						C_005EADE6(0, lolo.bp_68->f_0cc, &(lolo.bp_68->sPos), 0);//update trajectory?
					}
					if(lolo.bp_24->f_50[2] < D_00C3F75C)
						lolo.bp_24->f_0c = 0;
					if(lolo.bp_24->f_50[3] < D_00C3F75C)
						lolo.bp_24->f_2c += 4;
					if(lolo.bp_24->f_0c) {
						lolo.bp_68->sPos.f_04 += lolo.bp_24->f_2c;
						if(lolo.bp_68->sPos.f_04 > 0)
							lolo.bp_24->f_0c = 0;
						//-- hit management --
						if(lolo.bp_24->dwIsHit)
							C_005ED528(lolo.bp_68);//object is hit
						//-- --
					} else {
						C_005EB2DF(lolo.bp_68);//release object
					}
				break;
				case 0x05://welcome post & pole
					if(lolo.bp_24->dwMustInit == 1) {//else 005EC117
						if(lolo.bp_24->f_50[0x11])
							C_005E94E5(lolo.bp_24->f_50[0x11]);//sound related(3)
						C_005EAC30(lolo.bp_24->f_18, 0);//start trajectory?
						lolo.bp_68->f_0cc = D_00C3FB60;
						lolo.bp_68->f_0c8 = D_00C476E0;
						lolo.bp_24->dwMustInit = 0;
						lolo.bp_24->f_0c = 1;
						lolo.bp_24->dwIsHit = 0;
						lolo.bp_24->f_28 = 0;
						lolo.bp_24->f_2c = (lolo.bp_68->f_0c8 - 1) << 0x10;
						lolo.bp_68->sRot.f_00 = lolo.bp_24->f_50[3];
						lolo.bp_68->sRot.f_02 = lolo.bp_24->f_50[4];
						lolo.bp_68->sRot.f_04 = lolo.bp_24->f_50[5];
					}
					lolo.bp_24->f_28 += lolo.bp_24->f_1c;
					if(lolo.bp_24->f_50[1] == 1)
						lolo.bp_24->f_28 %= lolo.bp_24->f_2c;
					if(lolo.bp_24->f_28 > lolo.bp_24->f_2c)
						lolo.bp_24->f_0c = 0;
					if(lolo.bp_24->f_50[2] < D_00C3F75C)
						lolo.bp_24->f_0c = 0;
					lolo.bp_68->sRot.f_00 += lolo.bp_24->f_50[6];
					lolo.bp_68->sRot.f_02 += lolo.bp_24->f_50[7];
					lolo.bp_68->sRot.f_04 += lolo.bp_24->f_50[8];
					if(lolo.bp_24->f_50[0xa] == 5)
						lolo.bp_68->pNode->pModel = D_00C5D25C[lolo.bp_24->f_50[0xe]];
					if(lolo.bp_24->f_50[0xe] == 1)
						lolo.bp_24->f_50[0xe] = 0;
					if(lolo.bp_24->f_0c) {
						C_005EADE6(lolo.bp_24->f_28, lolo.bp_68->f_0cc, &(lolo.bp_68->sPos), 0);//update trajectory?
						//-- hit management --
						if(lolo.bp_24->dwIsHit) {
							if(lolo.bp_24->f_50[0xa] != 5)
								C_005ED528(lolo.bp_68);//object is hit
							else if(D_00C3F768 < 0x4015)
								C_005ED528(lolo.bp_68);//object is hit
							if(lolo.bp_24->f_50[0xa] == 5)
								lolo.bp_24->f_50[0xe] = 1;
						}
						//-- --
					} else {
						C_005EB2DF(lolo.bp_68);//release object
					}
				break;
				case 0x02:
					if(lolo.bp_24->dwMustInit == 1) {//else 005EC36D
						if(lolo.bp_24->f_50[0x11])
							C_005E94E5(lolo.bp_24->f_50[0x11]);//sound related(3)
						C_005EAC30(lolo.bp_24->f_18, 0);//start trajectory?
						lolo.bp_68->f_0cc = D_00C3FB60;
						lolo.bp_68->f_0c8 = D_00C476E0;
						lolo.bp_24->dwMustInit = 0;
						lolo.bp_24->f_0c = 1;
						lolo.bp_24->dwIsHit = 0;
						lolo.bp_24->f_28 = (rand() % lolo.bp_24->f_50[3]) * 2 - lolo.bp_24->f_50[3] - 1;
						lolo.bp_24->f_2c = 0;
						lolo.bp_24->f_30 = 0;
						lolo.bp_24->f_34 = (lolo.bp_68->f_0c8 - 1) << 0x10;
						lolo.bp_68->sRot.f_00 = 0;
						lolo.bp_68->sRot.f_02 = 0;
						lolo.bp_68->sRot.f_04 = 0;
						C_005EADE6(0, lolo.bp_68->f_0cc, &(lolo.bp_68->sPos), 0);//update trajectory?
					}
					lolo.bp_24->f_30 += lolo.bp_24->f_1c;
					if(lolo.bp_24->f_30 > lolo.bp_24->f_34)
						lolo.bp_24->f_0c = 0;
					if(lolo.bp_24->f_50[2] < D_00C3F75C)
						lolo.bp_24->f_0c = 0;
					if(lolo.bp_24->f_2c > lolo.bp_24->f_28)
						lolo.bp_24->f_2c -= 5;
					if(lolo.bp_24->f_2c < lolo.bp_24->f_28)
						lolo.bp_24->f_2c += 5;
					lolo.bp_68->sRot.f_00 = lolo.bp_24->f_2c;
					lolo.bp_68->sRot.f_02 += lolo.bp_24->f_50[4];
					if(lolo.bp_24->f_0c) {
						C_005EADE6(lolo.bp_24->f_30, lolo.bp_68->f_0cc, &(lolo.bp_68->sPos), 0);//update trajectory?
						//-- hit management --
						if(lolo.bp_24->dwIsHit)
							C_005ED528(lolo.bp_68);//object is hit
						//-- --
					} else {
						C_005EB2DF(lolo.bp_68);//release object
					}
				break;
				case 0xe6:
					if(lolo.bp_24->dwMustInit == 1) {//else 005EC483
						lolo.bp_24->dwMustInit = 0;
						lolo.bp_24->f_0c = 1;
						lolo.bp_24->dwIsHit = 0;
					}
					if(lolo.bp_24->f_50[2] < D_00C3F75C)
						lolo.bp_24->f_0c = 0;
					if(lolo.bp_24->f_0c) {
						//-- hit management --
						if(lolo.bp_24->dwIsHit)
							C_005ED528(lolo.bp_68);//object is hit
						//-- --
					} else {
						C_005EB2DF(lolo.bp_68);//release object
					}
				break;
				case 0x07:
				case 0x0d:
					if(lolo.bp_24->dwMustInit == 1) {//else 005EC56E
						C_005EAC30(lolo.bp_24->f_18, 0);//start trajectory?
						lolo.bp_68->f_0cc = D_00C3FB60;
						lolo.bp_68->f_0c8 = D_00C476E0;
						lolo.bp_24->dwMustInit = 0;
						lolo.bp_24->f_0c = 1;
						lolo.bp_24->dwIsHit = 0;
						lolo.bp_68->sRot.f_00 = lolo.bp_24->f_50[3];
						lolo.bp_68->sRot.f_02 = lolo.bp_24->f_50[4];
						lolo.bp_68->sRot.f_04 = 0;
						C_005EADE6(0, lolo.bp_68->f_0cc, &(lolo.bp_68->sPos), 0);//update trajectory?
						lolo.bp_24->f_28 = 0;
					}
					if(lolo.bp_24->f_50[2] < D_00C3F75C)
						lolo.bp_24->f_0c = 0;
					if(lolo.bp_24->f_50[5] < D_00C3F75C && (lolo.bp_24->f_28++) < lolo.bp_24->f_50[7])
						lolo.bp_68->sRot.f_00 += lolo.bp_24->f_50[6];
					if(lolo.bp_24->f_0c) {
						//-- hit management --
						if(lolo.bp_24->dwIsHit)
							C_005ED528(lolo.bp_68);//object is hit
						//-- --
					} else {
						C_005EB2DF(lolo.bp_68);//release object
					}
				break;
				case 0x0b:
					C_005E94E5(0x8e);//sound related(3)
					for(lolo.j = 0; lolo.j < lolo.bp_24->f_50[3]; lolo.j ++)
						C_005EB566(13382, -10000, 8395, 0x0c, 0x2a);//create new object[2]
					C_005EB2DF(lolo.bp_68);//release object
				//no break
				case 0x0c:
					if(lolo.bp_24->dwMustInit == 1) {//else 005EC6C0
						lolo.bp_24->dwIsHit = 0;
						lolo.bp_24->f_0c = 100;
						lolo.bp_24->dwMustInit = 0;
						lolo.bp_24->f_14 = 0;
						lolo.bp_24->f_28 = (rand() % 60) - 30;
						lolo.bp_24->f_2c = (-rand() % 200);
						lolo.bp_24->f_30 = (rand() % 60) - 30;
					} else {
						lolo.bp_24->f_14 ++;
					}
					lolo.bp_24->f_2c ++;
					lolo.bp_68->sPos.f_00 += lolo.bp_24->f_28;
					lolo.bp_68->sPos.f_04 += lolo.bp_24->f_2c;
					lolo.bp_68->sPos.f_08 += lolo.bp_24->f_30;
					lolo.bp_68->sRot.f_00 += 10;
					lolo.bp_68->sRot.f_02 += 400;
					lolo.bp_68->sRot.f_04 += 200;
					lolo.bp_24->f_0c --;
					if(lolo.bp_24->f_0c == 0)
						C_005EB2DF(lolo.bp_68);//release object
				break;
				case 0x08://firework[main]
					if(lolo.bp_24->dwMustInit == 1) {//else 005EC7EC
						C_005EAC30(lolo.bp_24->f_18, 0);//start trajectory?
						lolo.bp_68->f_0cc = D_00C3FB60;
						lolo.bp_68->f_0c8 = D_00C476E0;
						lolo.bp_24->dwMustInit = 0;
						lolo.bp_24->f_0c = 1;
						lolo.bp_24->dwIsHit = 0;
						lolo.bp_24->f_28 = 0;
						C_005EADE6(0, lolo.bp_68->f_0cc, &(lolo.bp_68->sPos), 0);//update trajectory?
					}
					if(lolo.bp_24->f_50[2] < D_00C3F75C)
						lolo.bp_24->f_0c = 0;
					if(lolo.bp_24->f_0c) {//else 005EC8A3
						lolo.bp_68->sPos.f_04 -= lolo.bp_24->f_50[3];
						lolo.bp_24->f_50[3] -= lolo.bp_24->f_50[4];
						if(lolo.bp_24->f_50[3] < 0) {//else 005EC8A1
							C_005E94E5(0x98);//sound related(3)
							for(lolo.j = 0; lolo.j < 20; lolo.j ++)
								C_005EB566(lolo.bp_68->sPos.f_00, lolo.bp_68->sPos.f_04, lolo.bp_68->sPos.f_08, 0x09, (rand() % 3) + 0x44);//create new object[2]
							lolo.bp_24->f_0c = 0;
						}
					} else {
						C_005EB2DF(lolo.bp_68);//release object
					}
				break;
				case 0x09://firework[particle]
					if(lolo.bp_24->dwMustInit == 1) {//else 005EC929
						lolo.bp_24->dwIsHit = 0;
						lolo.bp_24->f_0c = 100;
						lolo.bp_24->dwMustInit = 0;
						lolo.bp_24->f_14 = 0;
						lolo.bp_24->f_28 = (rand() % 60) - 30;
						lolo.bp_24->f_2c = (rand() % 60) - 30;
						lolo.bp_24->f_30 = (rand() % 60) - 30;
					} else {
						lolo.bp_24->f_14 ++;
					}
					lolo.bp_68->sPos.f_00 += lolo.bp_24->f_28;
					lolo.bp_68->sPos.f_04 += lolo.bp_24->f_2c;
					lolo.bp_68->sPos.f_08 += lolo.bp_24->f_30;
					lolo.bp_68->sRot.f_00 += 10;
					lolo.bp_68->sRot.f_02 += 400;
					lolo.bp_68->sRot.f_04 += 200;
					lolo.bp_24->f_0c --;
					if(lolo.bp_24->f_0c == 0)
						C_005EB2DF(lolo.bp_68);//release object
				break;
				case 0x0e:
					if(lolo.bp_24->dwMustInit == 1) {
						C_005E94E5(0xa);//sound related(3)
						C_005EAC30(lolo.bp_24->f_18, 0);//start trajectory?
						lolo.bp_68->f_0cc = D_00C3FB60;
						lolo.bp_68->f_0c8 = D_00C476E0;
						lolo.bp_24->dwMustInit = 0;
						lolo.bp_24->f_0c = 1;
						lolo.bp_24->dwIsHit = 0;
						lolo.bp_24->f_14 = 0;
						lolo.bp_24->f_28 = -70;
						C_005EADE6(0, lolo.bp_68->f_0cc, &(lolo.bp_68->sPos), 0);//update trajectory?
					}
					lolo.bp_24->f_28 ++;
					lolo.bp_24->f_14 ++;
					if(lolo.bp_24->f_14 == 5) {//else 005ECB13
						for(lolo.j = 0; lolo.j < lolo.bp_24->f_50[3]; lolo.j ++)
							C_005EB566(lolo.bp_68->sPos.f_00 + (rand() % 100) - 50, lolo.bp_68->sPos.f_04 + 500, lolo.bp_68->sPos.f_08 + (rand() % 100) - 50, 0x0f, 0x2a);//create new object[2]
						C_005EB566(lolo.bp_68->sPos.f_00, lolo.bp_68->sPos.f_04, lolo.bp_68->sPos.f_08, 0x10, 0x29);//create new object[2]
					}
					if(lolo.bp_24->f_28 < 0)
						lolo.bp_68->sRot.f_02 += 20;
					if(lolo.bp_24->f_28 == 80)
						lolo.bp_24->f_0c = 0;
					lolo.bp_68->sPos.f_04 += lolo.bp_24->f_28;
					if(lolo.bp_24->f_50[2] < D_00C3F75C)
						lolo.bp_24->f_0c = 0;
					if(lolo.bp_24->f_0c) {
						//-- hit management --
						if(lolo.bp_24->dwIsHit)
							C_005ED528(lolo.bp_68);//object is hit
						//-- --
					} else {
						C_005EB2DF(lolo.bp_68);//release object
					}
				break;
				case 0x0f:
					if(lolo.bp_24->dwMustInit == 1) {
						lolo.bp_24->dwIsHit = 0;
						lolo.bp_24->f_0c = 200;
						lolo.bp_24->dwMustInit = 0;
						lolo.bp_24->f_14 = 0;
						lolo.bp_24->f_28 = (rand() % 80) - 40;
						lolo.bp_24->f_2c = (rand() % 80) - 40;
						lolo.bp_24->f_30 = -((rand() % 40) + 40);
					} else {
						lolo.bp_24->f_14 ++;
					}
					lolo.bp_24->f_30 ++;
					lolo.bp_68->sRot.f_00 += 480;
					lolo.bp_68->sRot.f_02 += 40;
					lolo.bp_68->sRot.f_04 += 610;
					lolo.bp_68->sPos.f_00 += lolo.bp_24->f_28;
					lolo.bp_68->sPos.f_04 += lolo.bp_24->f_30;
					lolo.bp_68->sPos.f_08 += lolo.bp_24->f_2c;
					lolo.bp_24->f_0c --;
					if(lolo.bp_24->f_0c == 0)
						C_005EB2DF(lolo.bp_68);//release object
				break;
				case 0x10:
					if(lolo.bp_24->dwMustInit == 1) {
						lolo.bp_24->dwIsHit = 0;
						lolo.bp_24->f_0c = 200;
						lolo.bp_24->dwMustInit = 0;
						lolo.bp_24->f_14 = 0;
						lolo.bp_24->f_28 = -60;
					} else {
						lolo.bp_24->f_14 ++;
					}
					if(lolo.bp_24->f_14 > 20) {
						lolo.bp_68->sPos.f_04 += lolo.bp_24->f_28;
						lolo.bp_24->f_28 ++;
					}
					lolo.bp_24->f_0c --;
					if(lolo.bp_24->f_0c == 0)
						C_005EB2DF(lolo.bp_68);//release object
				break;
				case 0x03:
					lolo.bp_68->sPos.f_00 = D_00C3F8E8.f_00;
					lolo.bp_68->sPos.f_04 = D_00C3F8E8.f_04 - 2500;
					lolo.bp_68->sPos.f_08 = D_00C3F8E8.f_08;
					lolo.bp_68->sRot.f_00 = 0;
					lolo.bp_68->sRot.f_02 = 0;
					lolo.bp_68->sRot.f_04 = 0;
					lolo.bp_38 = 1000;//unused?
				break;
				case 0xc9:
					if(lolo.bp_24->dwMustInit == 1) {
						lolo.bp_24->f_0c = 20;
						lolo.bp_24->dwMustInit = 0;
						lolo.bp_24->f_14 = 0;
						lolo.bp_24->dwIsHit = 0;
					} else {
						lolo.bp_24->f_14 ++;
					}
					C_005EB566(lolo.bp_68->sPos.f_00, lolo.bp_68->sPos.f_04, lolo.bp_68->sPos.f_08, 0xca, 0x2a);//create new object[2]
					lolo.bp_24->f_0c --;
					if(lolo.bp_24->f_0c == 0)
						C_005EB2DF(lolo.bp_68);//release object
				break;
				case 0xca://impact on saucer?
					if(lolo.bp_24->dwMustInit == 1) {
						lolo.bp_24->dwIsHit = 0;
						lolo.bp_24->f_0c = 50;
						lolo.bp_24->dwMustInit = 0;
						lolo.bp_24->f_14 = 0;
						lolo.bp_24->f_28 = (rand() % 20) - 10;
						lolo.bp_24->f_2c = (rand() % 40) - 20;
						lolo.bp_24->f_30 = (rand() % 20) - 10;
					} else {
						lolo.bp_24->f_14 ++;
					}
					lolo.bp_68->sPos.f_00 += lolo.bp_24->f_28;
					lolo.bp_68->sPos.f_04 += lolo.bp_24->f_2c;
					lolo.bp_68->sPos.f_08 += lolo.bp_24->f_30;
					lolo.bp_68->sRot.f_00 += 10;
					lolo.bp_68->sRot.f_02 += 100;
					lolo.bp_68->sRot.f_04 += 20;
					lolo.bp_24->f_0c --;
					if(lolo.bp_24->f_0c == 0)
						C_005EB2DF(lolo.bp_68);//release object
				break;
				case 0xcb:
					if(lolo.bp_24->dwMustInit == 1) {
						lolo.bp_24->dwIsHit = 0;
						lolo.bp_24->f_0c = 50;
						lolo.bp_24->dwMustInit = 0;
						lolo.bp_24->f_14 = 0;
						lolo.bp_24->f_28 = (rand() % 200) - 100;
						lolo.bp_24->f_2c = (rand() % 200) - 100;
						lolo.bp_24->f_30 = (rand() % 200) - 100;
					} else {
						lolo.bp_24->f_14 ++;
					}
					lolo.bp_68->sPos.f_00 += lolo.bp_24->f_28;
					lolo.bp_68->sPos.f_04 += lolo.bp_24->f_2c;
					lolo.bp_68->sPos.f_08 += lolo.bp_24->f_30;
					lolo.bp_68->sRot.f_00 += 0;
					lolo.bp_68->sRot.f_02 += 300;
					lolo.bp_68->sRot.f_04 += 0;
					lolo.bp_24->f_0c --;
					if(lolo.bp_24->f_0c == 0)
						C_005EB2DF(lolo.bp_68);//release object
				break;
				case 0xff://speed changer?
					if(lolo.bp_24->dwMustInit == 1) {
						lolo.bp_24->dwMustInit = 0;
						lolo.bp_24->f_14 = 0;
					} else {
						lolo.bp_24->f_14 ++;
					}
					if(D_00C3F768 > lolo.bp_24->f_50[2])
						D_00C3F768 -= lolo.bp_24->f_50[0];
					if(D_00C3F768 < 0) {
						D_00C3F768 = 0;
						C_005EB566(0, 0, 0, 0xfd, 0x1d);//create new object[2]
					}
					if(lolo.bp_24->f_14 > lolo.bp_24->f_50[1])
						C_005EB2DF(lolo.bp_68);//release object
				break;
				case 0xfe://blocker?end?
					if(lolo.bp_24->dwMustInit == 1) {
						lolo.bp_24->dwMustInit = 0;
						lolo.bp_24->f_14 = 0;
						lolo.bp_24->f_28 = 0;
						lolo.bp_24->f_2c = clock();
						lolo.bp_24->f_30 = 0;
					} else {
						lolo.bp_24->f_14 ++;
					}
					if(lolo.bp_24->f_28 == 0)
						D_00C3F768 = 0;
					if(lolo.bp_24->f_28 == 1) {
						D_00C3F768 += lolo.bp_24->f_50[1];
						lolo.bp_24->f_30 ++;
					}
					if((clock() - lolo.bp_24->f_2c) / 1000 > lolo.bp_24->f_50[0] / 60)
						lolo.bp_24->f_28 = 1;
					if(lolo.bp_24->f_30 > lolo.bp_24->f_50[2])
						C_005EB2DF(lolo.bp_68);//release object
				break;
				case 0xfc://blocker?start?
					if(lolo.bp_24->dwMustInit == 1) {
						lolo.bp_24->dwMustInit = 0;
						lolo.bp_24->f_14 = 0;
						D_00C3F768 = 0;
						D_00C3F764 = 1;
						C_005EB566(0, 0, 0, 0x03, 0x3b);//create new object[2]
					} else {
						lolo.bp_24->f_14 ++;
					}
					lolo.bp_2c = 0xff - (lolo.bp_24->f_14 * 2);
					C_005EA77E(lolo.bp_2c);//draw alpha quad
					if(lolo.bp_24->f_14 > 0x7d) {
						C_005EB2DF(lolo.bp_68);//release object
						D_00C3F768 = 0x4000;
					}
				break;
				case 0xfd:
					if(lolo.bp_24->dwMustInit == 1) {
						lolo.bp_24->dwMustInit = 0;
						lolo.bp_24->f_14 = 0;
						D_00C3F768 = 0;
						C_005E9436();//sound related(2)
					} else {
						C_00744B13();//sound:refresh trans?
						lolo.bp_24->f_14 ++;
					}
					lolo.bp_2c = lolo.bp_24->f_14 * 2;
					C_005EA77E(lolo.bp_2c);//draw alpha quad
					if(lolo.bp_24->f_14 > 0x7f) {
						C_005EB2DF(lolo.bp_68);//release object
						D_00C3F768 = 0x4000;
						D_00C3F764 = 0;
						D_00C3F774 = 1;//reached the end?
					}
				break;
				case 0xfa:
					if(D_00C3F74C < lolo.bp_24->f_50[0]) {
						D_00C3F930.f_028.f_50[0] = 300;
						D_00C3F930.f_028.f_50[1] = 400;
						D_00C3F930.f_028.f_50[2] = 0;
						C_005EB566(lolo.bp_68->sPos.f_00, lolo.bp_68->sPos.f_04, lolo.bp_68->sPos.f_08, 0xff, 0x1e);//create new object[2]
					}
					C_005EB2DF(lolo.bp_68);//release object
				break;
			}//end switch --
//005ED34D
			//-- compute object's matrix --
			C_00661939(&(lolo.bp_68->pNode->f_04));//psx:init transformation/matrix?
			//-- .rotation --
			if(lolo.bp_68->sRot.f_00 || lolo.bp_68->sRot.f_02 || lolo.bp_68->sRot.f_04) {//else 005ED3F5
				if(lolo.bp_54 == 0)
					C_005EA099(&(lolo.bp_68->sRot), &(lolo.bp_68->pNode->f_04));
				else if(lolo.bp_54 == 1)
					C_006628DE(&(lolo.bp_68->sRot), &(lolo.bp_68->pNode->f_04));//psx:xyz_rotate(1)
				else if(lolo.bp_54 == 2)
					C_00662CD2(&(lolo.bp_68->sRot), &(lolo.bp_68->pNode->f_04));//psx:xyz_rotate(3)
			}
			//-- .translation --
			lolo.bp_68->pNode->f_04.f_12[0] = lolo.bp_68->sPos.f_00 - D_00C3F8D8.f_00;
			lolo.bp_68->pNode->f_04.f_12[1] = lolo.bp_68->sPos.f_04 - D_00C3F8D8.f_04;
			lolo.bp_68->pNode->f_04.f_12[2] = lolo.bp_68->sPos.f_08 - D_00C3F8D8.f_08;
			//-- render it --
			if(lolo.bIsPlayerCar == 0)
				C_005E99FB(lolo.bp_68->pNode, lolo.bp_68);//render objects
			else if(lolo.bIsPlayerCar == 1)
				C_005E9CB5(lolo.bp_68->pNode);//render "car"/compute "rays" projection?
		}
	}//end for
}

void C_005ED5AC(struct t_coaster_GameObject *);//manage impact

//object is hit
void C_005ED528(struct t_coaster_GameObject *bp08) {
	char local_2;
	struct t_coaster_ObjectState *local_1;

	local_1 = &(bp08->f_028);
	local_2 = D_00C3FB50 >> 5;
	if(local_2 == 0)
		local_2 = 1;
	local_1->f_50[0xd] -= local_2;
	if(local_1->f_50[0xd] < 0)
		C_005ED5AC(bp08);//manage impact
	else
		C_005EB566(bp08->sPos.f_00, bp08->sPos.f_04, bp08->sPos.f_08, 0xca, 0x3f);//create new object[2]
}

//manage impact
void C_005ED5AC(struct t_coaster_GameObject *bp08) {
	struct t_coaster_ObjectState *local_2;
	int i;//local_1

	local_2 = &(bp08->f_028);
	if(local_2->f_50[0xa] == 1) {//else 005ED690
		D_00C3F74C += local_2->f_50[0];
		C_005E94E5(local_2->f_50[0x12]);//sound related(3)
		local_2->f_0c = 0;
		for(i = 0; i < 3; i ++)
			C_005EB566(bp08->sPos.f_00, bp08->sPos.f_04, bp08->sPos.f_08, 0xca, (rand() % 3) + 0x3f);//create new object[2]
		D_00C3F76C = bp08->pNode->wModelId;
		D_00C3F6F4 = local_2->f_50[0];
		D_00C3F724 = 100;
		D_00C3F730 = 1;
		D_00C3F728.f_00 = 0;
		D_00C3F728.f_02 = 0;
		D_00C3F728.f_04 = 0;
	}
	if(local_2->f_50[0xa] == 2) {//else 005ED765
		D_00C3F74C += local_2->f_50[0];
		C_005E94E5(local_2->f_50[0x12]);//sound related(3)
		local_2->f_0c = 0;
		for(i = 0; i < 3; i ++)
			C_005EB566(bp08->sPos.f_00, bp08->sPos.f_04, bp08->sPos.f_08, 0xcb, (rand() % 3) + 0x3c);//create new object[2]
		D_00C3F76C = bp08->pNode->wModelId;
		D_00C3F6F4 = local_2->f_50[0];
		D_00C3F724 = 100;
		D_00C3F730 = 1;
		D_00C3F728.f_00 = 0;
		D_00C3F728.f_02 = 0;
		D_00C3F728.f_04 = 0;
	}
	if(local_2->f_50[0xa] == 3) {
		D_00C3F74C += local_2->f_50[0];
		bp08->sRot.f_00 += local_2->f_50[0xb];
	}
	if(local_2->f_50[0xa] == 4) {
		D_00C3F74C += local_2->f_50[0];
		C_005E94E5(local_2->f_50[0x12]);//sound related(3)
		local_2->f_0c = 0;
		D_00C3F76C = bp08->pNode->wModelId;
		D_00C3F6F4 = local_2->f_50[0];
		D_00C3F724 = 100;
		D_00C3F730 = 1;
		D_00C3F728.f_00 = 0;
		D_00C3F728.f_02 = 0;
		D_00C3F728.f_04 = 0;
	}
	if(local_2->f_50[0xa] == 5) {//else 005ED8EC
		D_00C3F74C += local_2->f_50[0];
		C_005E94E5(local_2->f_50[0x12]);//sound related(3)
		local_2->f_0c = 0;
		for(i = 0; i < 100; i ++)
			C_005EB566(bp08->sPos.f_00, bp08->sPos.f_04, bp08->sPos.f_08, 0xcb, (rand() % 3) + 0x3f);//create new object[2]
		D_00C3F76C = bp08->pNode->wModelId;
		D_00C3F6F4 = local_2->f_50[0];
		D_00C3F724 = 100;
		D_00C3F730 = 1;
		D_00C3F728.f_00 = 0;
		D_00C3F728.f_02 = 0;
		D_00C3F728.f_04 = 0;
	}
}
