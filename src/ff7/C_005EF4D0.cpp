//coaster -- Class_coaster_D8

#include "ff7.h"

#include "coaster_data.h"

Class_coaster_D8::Class_coaster_D8() {//::005EF4D0
	//local_1 this
	//-- --
	this->f_c0 = this->C_005EF89D(0xc, 4, "score.tim", 0x80);
	this->f_c4 = this->C_005EF89D(0xc, 4, "co1.tim", 0x80);
	this->f_cc = this->C_005EF89D(0xa, 4, 0, 0);
	this->f_d0 = this->C_005EF89D(0xc, 4, "waku2.tim", 0x80);
	this->f_c8 = this->C_005EF89D(0xc, 4, "pause.tim", 0x80);
	//-- for objects --
	this->f_88 = this->C_005EF89D(2, 4, 0, 0);
	this->f_8c = this->C_005EF89D(3, 4, 0, 0);
	this->f_90 = new t_dx_sfx_xxx_08;
	//-- for objects(transparent) --
	this->f_94 = this->C_005EF89D(2, 1, 0, 0);
	this->f_98 = this->C_005EF89D(3, 1, 0, 0);
	this->f_9c = new t_dx_sfx_xxx_08;
	//-- for tracks --
	this->f_a0 = this->C_005EF89D(0xc, 4, "rail.tim", 0);
	this->f_a4 = this->C_005EF89D(0xd, 4, "rail.tim", 0);
	this->f_a8 = new t_dx_sfx_xxx_08;
	//-- --
	this->f_ac = this->C_005EF89D(0xc, 4, "sight.tim", 0x80);
	//-- --
	this->f_b4[0] = this->C_005EF89D(0xc, 1, "beam1.tim", 0);
	this->f_b4[1] = this->C_005EF89D(0xc, 1, "beam2.tim", 0);
	this->f_b4[2] = this->C_005EF89D(0xc, 1, "beam3.tim", 0);
	this->f_b0 = this->f_b4[0];
	//-- --
	this->f_d4 = this->C_005EF89D(8, 0, 0, 0x4000);
	this->f_80 = &(this->f_00);
	this->f_84 = &(this->f_40);
	C_0066C4F0(this->f_80);//set matrix to identity?
	C_0066C4F0(this->f_84);//set matrix to identity?
}

Class_coaster_D8::~Class_coaster_D8() {//::005EF728
	//local_4 this
	C_00670FD3(this->f_88);//dx_sfx:release "struct t_dx_sfx_e0 *"
	C_00670FD3(this->f_8c);//dx_sfx:release "struct t_dx_sfx_e0 *"

	C_00670FD3(this->f_94);//dx_sfx:release "struct t_dx_sfx_e0 *"
	C_00670FD3(this->f_98);//dx_sfx:release "struct t_dx_sfx_e0 *"

	C_00670FD3(this->f_a0);//dx_sfx:release "struct t_dx_sfx_e0 *"
	C_00670FD3(this->f_a4);//dx_sfx:release "struct t_dx_sfx_e0 *"

	C_00670FD3(this->f_ac);//dx_sfx:release "struct t_dx_sfx_e0 *"

	C_00670FD3(this->f_b4[0]);//dx_sfx:release "struct t_dx_sfx_e0 *"
	C_00670FD3(this->f_b4[1]);//dx_sfx:release "struct t_dx_sfx_e0 *"
	C_00670FD3(this->f_b4[2]);//dx_sfx:release "struct t_dx_sfx_e0 *"

	C_00670FD3(this->f_c0);//dx_sfx:release "struct t_dx_sfx_e0 *"
	C_00670FD3(this->f_c4);//dx_sfx:release "struct t_dx_sfx_e0 *"
	C_00670FD3(this->f_cc);//dx_sfx:release "struct t_dx_sfx_e0 *"
	C_00670FD3(this->f_d0);//dx_sfx:release "struct t_dx_sfx_e0 *"
	C_00670FD3(this->f_c8);//dx_sfx:release "struct t_dx_sfx_e0 *"

	C_00670FD3(this->f_d4);//dx_sfx:release "struct t_dx_sfx_e0 *"

	delete this->f_90;
	delete this->f_9c;
	delete this->f_a8;
}

struct t_dx_sfx_e0 *Class_coaster_D8::C_005EF89D(int bp08/*polygon type*/, int bp0c/*blend mode*/, const char *bp10/*texture*/, int bp14) {
	struct {
		//local_32 this
		struct t_rsd_74 local_31;
		struct t_aa0 *local_2;
		struct t_dx_sfx_e0 *local_1;
	}lolo;

	lolo.local_2 = C_00676578();
	lolo.local_1 = 0;
	memset(&lolo.local_31, 0, sizeof(struct t_rsd_74));
	C_006745E6(bp0c, &lolo.local_31);//rsd:set blend mode?
	lolo.local_31.f_24 = C_00407851();//minigame path(4)?
	if(bp0c != 4)
		C_00674659(bp0c, &lolo.local_31);//rsd:set struct t_rsd_74::f_20
	lolo.local_31.f_08 = 0;
	lolo.local_31.f_40.f_04 = 1;
	lolo.local_31.f_40.f_08 = 9;
	lolo.local_31.f_40.f_0c = 0;
	lolo.local_31.f_70 |= bp14;
	lolo.local_1 = C_006710AC(1, bp08, &lolo.local_31, bp10, lolo.local_2->f_910);//dx_sfx:alloc/create?
	if(lolo.local_1)
		lolo.local_1->f_34 |= 2;

	return lolo.local_1;
}

//projection:cube?
void Class_coaster_D8::C_005EF95A(struct SVECTOR *bp08, int *bp0c) {
	struct {
		//local_6 this
		float local_5[4];
		int i;//local_1
	}lolo;

	for(lolo.i = 0; lolo.i < 8; lolo.i ++) {
		this->C_005F2639(&(bp08[lolo.i]), this->f_84, lolo.local_5);
		bp0c[lolo.i] = ((int)lolo.local_5[1] << 0x10) | ((int)lolo.local_5[0] & 0xffff);
	}
}

//projection:triangle?
void Class_coaster_D8::C_005EF9CA(struct SVECTOR *bp08, int *bp0c) {
	struct {
		//local_6 this
		float local_5[4];
		int i;//local_1
	}lolo;

	for(lolo.i = 0; lolo.i < 3; lolo.i ++) {
		this->C_005F2639(&(bp08[lolo.i]), this->f_84, lolo.local_5);
		bp0c[lolo.i] = ((int)lolo.local_5[1] << 0x10) | ((int)lolo.local_5[0] & 0xffff);
	}
}

//render object
void Class_coaster_D8::C_005EFA3A(struct t_coaster_RenderInfo *bp08) {
	struct {
		//local_4 this
		int i;//local_3
		short wNumTri; char _ocal_2[2];//local_2
		struct t_coaster_Triangle *pTriangle;//local_1
	}lolo;

	lolo.pTriangle = bp08->pTriangles;
	lolo.wNumTri = bp08->pModel->wNumTri;
	for(lolo.i = lolo.wNumTri; lolo.i > 0; lolo.i --) {
		this->C_005F04D7(lolo.pTriangle, this->f_88, this->f_8c, this->f_94, this->f_98, this->f_90, this->f_9c);//render triangle[most of the 3D models]
		lolo.pTriangle ++;
	}
}

//render object[for score]
void Class_coaster_D8::C_005EFACA(struct t_coaster_RenderInfo *bp08) {
	struct {
		//local_4 this
		int i;//local_3
		short wNumTri; char _ocal_2[2];//local_2
		struct t_coaster_Triangle *pTriangle;//local_1
	}lolo;

	lolo.pTriangle = bp08->pTriangles;
	lolo.wNumTri = bp08->pModel->wNumTri;
	for(lolo.i = lolo.wNumTri; lolo.i > 0; lolo.i --) {
		this->C_005F04D7(lolo.pTriangle, this->f_88, this->f_8c, this->f_94, this->f_98, this->f_90, this->f_9c);//render triangle[most of the 3D models]
		lolo.pTriangle ++;
	}
}

float D_00901550[][2] = {
	{1.0f,0.0f},
	{1.0f,1.0f},
	{0.0f,0.0f},
	{0.0f,1.0f}
};
float D_00901570[][2] = {
	{0.0f,0.0f},
	{0.0f,1.0f},
	{1.0f,0.0f},
	{1.0f,1.0f}
};

//render track element
void Class_coaster_D8::C_005EFB5A(struct SVECTOR *bp08, struct SVECTOR *bp0c) {
	struct {
		//local_55 this
		int local_54;
		struct t_dx_sfx_84 *local_53;
		struct t_dx_rend_vertex_20 *local_52[4];
		struct t_dx_rend_vertex_20 *local_48[4];
		float local_44[4];
		float local_40[4];
		float local_36[4];
		float local_32[4];
		float local_28;
		int local_27;
		float local_26;
		float (*local_25)[2];
		unsigned local_24[4];//bp_60
		int local_20;
		int i;//local_19
		struct SVECTOR *local_18[4];//bp_48
		struct t_g_drv_0c local_14[4];//bp_38
		int local_2;
		unsigned local_1;
	}lolo;

	lolo.local_1 = 0xffffffff;
	lolo.local_25 = /*lolo.local_56*/0?D_00901550:D_00901570;
	lolo.local_2 = 0;
	lolo.local_20 = 0;
	lolo.local_18[0] = &(bp08[0]);
	lolo.local_18[1] = &(bp0c[1]);
	lolo.local_18[2] = &(bp08[8]);
	lolo.local_18[3] = &(bp0c[9]);
	for(lolo.i = 0; lolo.i < 4; lolo.i ++) {
		lolo.local_28 = this->C_005F2759(lolo.local_18[lolo.i], this->f_80);//dot product with matrix column 3
		if(lolo.local_28 < 0)
			lolo.local_2 = 1;
		if(lolo.local_28 > 0)
			lolo.local_20 = 1;
		lolo.local_26 = this->C_005F2838(lolo.local_28);//get light ratio
		lolo.local_27 = (int)(lolo.local_26 * 255.0f);
		lolo.local_24[lolo.i] = 0xff000000 | ((lolo.local_27 << 0x10)) | (lolo.local_27 << 8) | lolo.local_27;
	}
	if(lolo.local_20) {//else 005F047B
		if(lolo.local_2 == 0) {//else 005F0189
			C_0066E272(2, this->f_a0);
			this->C_005F2639(&(bp08[0]), this->f_84, lolo.local_32);
			this->C_005F2639(&(bp0c[1]), this->f_84, lolo.local_36);
			this->C_005F2639(&(bp08[8]), this->f_84, lolo.local_40);
			this->C_005F2639(&(bp0c[9]), this->f_84, lolo.local_44);
			MK_VERTEX(&(this->f_a0->f_70.asVertex[0]), lolo.local_48[3], lolo.local_32[0], lolo.local_32[1], lolo.local_32[2], lolo.local_32[3], lolo.local_24[0], lolo.local_1, D_00901550[0][0], D_00901550[0][1]);
			MK_VERTEX(&(this->f_a0->f_70.asVertex[2]), lolo.local_48[2], lolo.local_36[0], lolo.local_36[1], lolo.local_36[2], lolo.local_36[3], lolo.local_24[1], lolo.local_1, D_00901550[1][0], D_00901550[1][1]);
			MK_VERTEX(&(this->f_a0->f_70.asVertex[1]), lolo.local_48[1], lolo.local_40[0], lolo.local_40[1], lolo.local_40[2], lolo.local_40[3], lolo.local_24[2], lolo.local_1, D_00901550[2][0], D_00901550[2][1]);
			MK_VERTEX(&(this->f_a0->f_70.asVertex[3]), lolo.local_48[0], lolo.local_44[0], lolo.local_44[1], lolo.local_44[2], lolo.local_44[3], lolo.local_24[3], lolo.local_1, D_00901550[3][0], D_00901550[3][1]);
			this->f_a0->f_70.asUnsignedChar += this->f_a0->f_40;
			MK_VERTEX(&(this->f_a0->f_70.asVertex[0]), lolo.local_52[3], lolo.local_32[0], lolo.local_32[1], lolo.local_32[2], lolo.local_32[3], lolo.local_24[0], lolo.local_1, lolo.local_25[0][0], lolo.local_25[0][1]);
			MK_VERTEX(&(this->f_a0->f_70.asVertex[1]), lolo.local_52[2], lolo.local_36[0], lolo.local_36[1], lolo.local_36[2], lolo.local_36[3], lolo.local_24[1], lolo.local_1, lolo.local_25[1][0], lolo.local_25[1][1]);
			MK_VERTEX(&(this->f_a0->f_70.asVertex[2]), lolo.local_52[1], lolo.local_40[0], lolo.local_40[1], lolo.local_40[2], lolo.local_40[3], lolo.local_24[2], lolo.local_1, lolo.local_25[2][0], lolo.local_25[2][1]);
			MK_VERTEX(&(this->f_a0->f_70.asVertex[3]), lolo.local_52[0], lolo.local_44[0], lolo.local_44[1], lolo.local_44[2], lolo.local_44[3], lolo.local_24[3], lolo.local_1, lolo.local_25[3][0], lolo.local_25[3][1]);
			//goto 005F047B
		} else {
			lolo.local_53 = 0;
			this->C_005F26EB(&(bp08[0]), this->f_80, &(lolo.local_14[0]));
			this->C_005F26EB(&(bp0c[1]), this->f_80, &(lolo.local_14[1]));
			this->C_005F26EB(&(bp08[8]), this->f_80, &(lolo.local_14[2]));
			this->C_005F26EB(&(bp0c[9]), this->f_80, &(lolo.local_14[3]));
			//-- --
			C_00672C61(this->f_a8, this->f_a4);//dx_sfx:...
			C_0066C4F0(this->f_a8->f_00);//set matrix to identity?
			lolo.local_53 = this->f_a8->f_04;
			for(lolo.i = 0; lolo.i < 4; lolo.i ++) {
				lolo.local_53->f_0c[lolo.i].f_00 = lolo.local_14[lolo.i].f_00;
				lolo.local_53->f_0c[lolo.i].f_04 = lolo.local_14[lolo.i].f_04;
				lolo.local_53->f_0c[lolo.i].f_08 = lolo.local_14[lolo.i].f_08;
				lolo.local_53->f_5c[lolo.i] = lolo.local_24[lolo.i];
				lolo.local_53->f_6c[lolo.i] = 0.5f;
				lolo.local_53->f_3c[lolo.i].f_00 = lolo.local_25[lolo.i][0];
				lolo.local_53->f_3c[lolo.i].f_04 = lolo.local_25[lolo.i][1];
			}
			//-- --
			C_00672C61(this->f_a8, this->f_a4);//dx_sfx:...
			C_0066C4F0(this->f_a8->f_00);//set matrix to identity?
			lolo.local_53 = this->f_a8->f_04;
			for(lolo.i = 0; lolo.i < 4; lolo.i ++) {
				lolo.local_54 = lolo.i;
				if(lolo.i == 1)
					lolo.local_54 = 2;
				else if(lolo.i == 2)
					lolo.local_54 = 1;
				lolo.local_53->f_0c[lolo.local_54].f_00 = lolo.local_14[lolo.i].f_00;
				lolo.local_53->f_0c[lolo.local_54].f_04 = lolo.local_14[lolo.i].f_04;
				lolo.local_53->f_0c[lolo.local_54].f_08 = lolo.local_14[lolo.i].f_08;
				lolo.local_53->f_5c[lolo.local_54] = lolo.local_24[lolo.i];
				lolo.local_53->f_6c[lolo.local_54] = 0.5f;
				lolo.local_53->f_3c[lolo.local_54].f_00 = D_00901550[lolo.i][0];
				lolo.local_53->f_3c[lolo.local_54].f_04 = D_00901550[lolo.i][1];
			}
		}
	}
}

//render triangle[static]
void Class_coaster_D8::C_005F0482(struct t_coaster_Triangle *bp08) {
	this->C_005F04D7(bp08, this->f_88, this->f_8c, this->f_94, this->f_98, this->f_90, this->f_9c);//render triangle[most of the 3D models]
}

float D_00901590[][2] = {
	{1.0f,0.0f},
	{1.0f,1.0f},
	{0.0f,0.0f},
	{0.0f,1.0f}
};
float D_009015B0[][2] = {
	{0.0f,0.0f},
	{0.0f,1.0f},
	{1.0f,0.0f},
	{1.0f,1.0f}
};

//render triangle[most of the 3D models]
void Class_coaster_D8::C_005F04D7(struct t_coaster_Triangle *bp08, struct t_dx_sfx_e0 *bp0c, struct t_dx_sfx_e0 *bp10, struct t_dx_sfx_e0 *bp14, struct t_dx_sfx_e0 *bp18, struct t_dx_sfx_xxx_08 *bp1c, struct t_dx_sfx_xxx_08 *bp20) {
	struct {
		//local_44 this
		struct t_dx_rend_vertex_20 *local_43[3];
		float local_40[4];
		float local_36[4];
		float local_32[4];
		float local_28;
		float (*local_27)[2];
		struct t_dx_sfx_e0 *local_26;
		int local_25;
		int i;//local_24
		struct t_dx_sfx_xxx_08 *local_23;
		struct t_dx_sfx_e0 *local_22;
		struct SVECTOR *local_21[3];//bp_54
		struct t_g_drv_0c local_18[3];//bp_48
		unsigned local_9[3];
		struct t_dx_sfx_84 *local_6;
		int local_5;
		float local_4[3];
		unsigned local_1;
	}lolo;

	lolo.local_1 = 0xffffffff;
	lolo.local_5 = 0;
	lolo.local_25 = 0;
	lolo.local_27 = /*local_45*/0?D_00901590:D_009015B0;
	lolo.local_6 = 0;
	lolo.local_21[0] = &(bp08->f_00[0]);
	lolo.local_21[1] = &(bp08->f_00[1]);
	lolo.local_21[2] = &(bp08->f_00[2]);
	for(lolo.i = 0; lolo.i < 3; lolo.i ++) {
		lolo.local_28 = this->C_005F2759(lolo.local_21[lolo.i], this->f_80);//dot product with matrix column 3
		if(lolo.local_28 < -100.0f)
			lolo.local_5 = 1;
		if(lolo.local_28 > 0)
			lolo.local_25 = 1;
		lolo.local_4[lolo.i] = this->C_005F2838(lolo.local_28);//get light ratio
	}
	if(lolo.local_25) {
		//-- --
		if(bp08->f_18[0].c.a & 2) {
			//transparent
			lolo.local_22 = bp14;
			lolo.local_26 = bp18;
			lolo.local_23 = bp20;
		} else {
			//solid
			lolo.local_22 = bp0c;
			lolo.local_26 = bp10;
			lolo.local_23 = bp1c;
		}
		//-- --
		if(lolo.local_5 == 0) {
			C_0066E272(1, lolo.local_22);
			this->C_005F2639(&(bp08->f_00[0]), this->f_84, lolo.local_32);
			this->C_005F2639(&(bp08->f_00[1]), this->f_84, lolo.local_36);
			this->C_005F2639(&(bp08->f_00[2]), this->f_84, lolo.local_40);
			lolo.local_9[0] = this->C_005F2897(&(bp08->f_18[0]), lolo.local_4[0]);//apply light ratio to color?
			lolo.local_9[1] = this->C_005F2897(&(bp08->f_18[1]), lolo.local_4[1]);//apply light ratio to color?
			lolo.local_9[2] = this->C_005F2897(&(bp08->f_18[2]), lolo.local_4[2]);//apply light ratio to color?
			MK_VERTEX(&(lolo.local_22->f_70.asVertex[0]), lolo.local_43[2], lolo.local_32[0], lolo.local_32[1], lolo.local_32[2], lolo.local_32[3], lolo.local_9[0], lolo.local_1, 0, 0);
			MK_VERTEX(&(lolo.local_22->f_70.asVertex[2]), lolo.local_43[1], lolo.local_36[0], lolo.local_36[1], lolo.local_36[2], lolo.local_36[3], lolo.local_9[1], lolo.local_1, 0, 0);
			MK_VERTEX(&(lolo.local_22->f_70.asVertex[1]), lolo.local_43[0], lolo.local_40[0], lolo.local_40[1], lolo.local_40[2], lolo.local_40[3], lolo.local_9[2], lolo.local_1, 0, 0);
		} else {
			this->C_005F26EB(&(bp08->f_00[0]), this->f_80, &(lolo.local_18[0]));
			this->C_005F26EB(&(bp08->f_00[1]), this->f_80, &(lolo.local_18[2]));
			this->C_005F26EB(&(bp08->f_00[2]), this->f_80, &(lolo.local_18[1]));
			lolo.local_9[0] = this->C_005F2897(&(bp08->f_18[0]), lolo.local_4[0]);//apply light ratio to color?
			lolo.local_9[2] = this->C_005F2897(&(bp08->f_18[1]), lolo.local_4[1]);//apply light ratio to color?
			lolo.local_9[1] = this->C_005F2897(&(bp08->f_18[2]), lolo.local_4[2]);//apply light ratio to color?
			C_00672C61(lolo.local_23, lolo.local_26);//dx_sfx:...
			C_0066C4F0(lolo.local_23->f_00);//set matrix to identity?
			lolo.local_6 = lolo.local_23->f_04;
			for(lolo.i = 0; lolo.i < 3; lolo.i ++) {
				lolo.local_6->f_0c[lolo.i].f_00 = lolo.local_18[lolo.i].f_00;
				lolo.local_6->f_0c[lolo.i].f_04 = lolo.local_18[lolo.i].f_04;
				lolo.local_6->f_0c[lolo.i].f_08 = lolo.local_18[lolo.i].f_08;
				lolo.local_6->f_5c[lolo.i] = lolo.local_9[lolo.i];
				lolo.local_6->f_6c[lolo.i] = 0.5f;
				lolo.local_6->f_3c[lolo.i].f_00 = lolo.local_27[lolo.i][0];
				lolo.local_6->f_3c[lolo.i].f_04 = lolo.local_27[lolo.i][1];
			}
		}
	}
}

//render "sight"
void Class_coaster_D8::C_005F09C4() {
	struct {
		//local_6 this;
		struct t_dx_rend_vertex_20 *local_5[4];
		unsigned local_1;
	}lolo;

	lolo.local_1 = 0xffffffff;
	if(C_0066E272(1, this->f_ac)) {
		MK_VERTEX(&(this->f_ac->f_70.asVertex[0]), lolo.local_5[3], (float)(D_00C3FB58 * D_0090147C - D_00C3F6F8 / 2) + D_00C3F784, (float)(D_00C3FB5C * D_00901480 - D_00C3F6F8 / 2) + D_00C3F788, 0.986842f, 1.0f, lolo.local_1, 0xff000000, 0.0f, 0.0f);
		MK_VERTEX(&(this->f_ac->f_70.asVertex[1]), lolo.local_5[2], (float)(D_00C3FB58 * D_0090147C - D_00C3F6F8 / 2) + D_00C3F784, (float)(D_00C3FB5C * D_00901480 + D_00C3F6F8 / 2) + D_00C3F788, 0.986842f, 1.0f, lolo.local_1, 0xff000000, 0.0f, 1.0f);
		MK_VERTEX(&(this->f_ac->f_70.asVertex[2]), lolo.local_5[1], (float)(D_00C3FB58 * D_0090147C + D_00C3F6F8 / 2) + D_00C3F784, (float)(D_00C3FB5C * D_00901480 - D_00C3F6F8 / 2) + D_00C3F788, 0.986842f, 1.0f, lolo.local_1, 0xff000000, 1.0f, 0.0f);
		MK_VERTEX(&(this->f_ac->f_70.asVertex[3]), lolo.local_5[0], (float)(D_00C3FB58 * D_0090147C + D_00C3F6F8 / 2) + D_00C3F784, (float)(D_00C3FB5C * D_00901480 + D_00C3F6F8 / 2) + D_00C3F788, 0.986842f, 1.0f, lolo.local_1, 0xff000000, 1.0f, 1.0f);
	}
}

//render "shoot rays"
void Class_coaster_D8::C_005F0C81() {
	struct {
		//local_19 this
		struct t_dx_rend_vertex_20 *local_18[4];
		struct t_dx_rend_vertex_20 *local_14[4];
		struct t_dx_rend_vertex_20 *local_10[4];
		struct t_dx_rend_vertex_20 *local_6[4];
		int local_2;
		unsigned local_1;
	}lolo;

	lolo.local_1 = 0xffffffff;
	this->f_b0 = this->f_b4[D_00C476DC];
	lolo.local_2 = D_00C3FB50 >> 3;
	C_0066E62C(this->f_b0);//dx_spr:reset something?
	if(C_0066E272(4, this->f_b0)) {
		MK_VERTEX(&(this->f_b0->f_70.asVertex[0]), lolo.local_6[3], (float)D_00C3F918 + lolo.local_2, (float)D_00C3F928, 0.986842f, 1.0f, lolo.local_1, 0xff000000, 0.0f, 0.0f);
		MK_VERTEX(&(this->f_b0->f_70.asVertex[1]), lolo.local_6[2], (float)(D_00C3FB58 * D_0090147C) + D_00C3F784, (float)(D_00C3FB5C * D_00901480) + D_00C3F788, 0.986842f, 1.0f, lolo.local_1, 0xff000000, 0.0f, 1.0f);
		MK_VERTEX(&(this->f_b0->f_70.asVertex[2]), lolo.local_6[1], (float)D_00C3F918 - lolo.local_2, (float)D_00C3F928, 0.986842f, 1.0f, lolo.local_1, 0xff000000, 1.0f, 0.0f);
		MK_VERTEX(&(this->f_b0->f_70.asVertex[3]), lolo.local_6[0], (float)(D_00C3FB58 * D_0090147C) + D_00C3F784, (float)(D_00C3FB5C * D_00901480) + D_00C3F788, 0.986842f, 1.0f, lolo.local_1, 0xff000000, 1.0f, 1.0f);
		this->f_b0->f_70.asUnsignedChar += this->f_b0->f_40;
		MK_VERTEX(&(this->f_b0->f_70.asVertex[0]), lolo.local_10[3], (float)D_00C3F918 + lolo.local_2, (float)D_00C3F928, 0.986842f, 1.0f, lolo.local_1, 0xff000000, 0.0f, 0.0f);
		MK_VERTEX(&(this->f_b0->f_70.asVertex[2]), lolo.local_10[2], (float)(D_00C3FB58 * D_0090147C) + D_00C3F784, (float)(D_00C3FB5C * D_00901480) + D_00C3F788, 0.986842f, 1.0f, lolo.local_1, 0xff000000, 0.0f, 1.0f);
		MK_VERTEX(&(this->f_b0->f_70.asVertex[1]), lolo.local_10[1], (float)D_00C3F918 - lolo.local_2, (float)D_00C3F928, 0.986842f, 1.0f, lolo.local_1, 0xff000000, 1.0f, 0.0f);
		MK_VERTEX(&(this->f_b0->f_70.asVertex[3]), lolo.local_10[0], (float)(D_00C3FB58 * D_0090147C) + D_00C3F784, (float)(D_00C3FB5C * D_00901480) + D_00C3F788, 0.986842f, 1.0f, lolo.local_1, 0xff000000, 1.0f, 1.0f);
		this->f_b0->f_70.asUnsignedChar += this->f_b0->f_40;
		MK_VERTEX(&(this->f_b0->f_70.asVertex[0]), lolo.local_14[3], (float)D_00C3FB4C + lolo.local_2, (float)D_00C3FB48, 0.986842f, 1.0f, lolo.local_1, 0xff000000, 0.0f, 0.0f);
		MK_VERTEX(&(this->f_b0->f_70.asVertex[1]), lolo.local_14[2], (float)(D_00C3FB58 * D_0090147C) + D_00C3F784, (float)(D_00C3FB5C * D_00901480) + D_00C3F788, 0.986842f, 1.0f, lolo.local_1, 0xff000000, 0.0f, 1.0f);
		MK_VERTEX(&(this->f_b0->f_70.asVertex[2]), lolo.local_14[1], (float)D_00C3FB4C - lolo.local_2, (float)D_00C3FB48, 0.986842f, 1.0f, lolo.local_1, 0xff000000, 1.0f, 0.0f);
		MK_VERTEX(&(this->f_b0->f_70.asVertex[3]), lolo.local_14[0], (float)(D_00C3FB58 * D_0090147C) + D_00C3F784, (float)(D_00C3FB5C * D_00901480) + D_00C3F788, 0.986842f, 1.0f, lolo.local_1, 0xff000000, 1.0f, 1.0f);
		this->f_b0->f_70.asUnsignedChar += this->f_b0->f_40;
		MK_VERTEX(&(this->f_b0->f_70.asVertex[0]), lolo.local_18[3], (float)D_00C3FB4C + lolo.local_2, (float)D_00C3FB48, 0.986842f, 1.0f, lolo.local_1, 0xff000000, 0.0f, 0.0f);
		MK_VERTEX(&(this->f_b0->f_70.asVertex[2]), lolo.local_18[2], (float)(D_00C3FB58 * D_0090147C) + D_00C3F784, (float)(D_00C3FB5C * D_00901480) + D_00C3F788, 0.986842f, 1.0f, lolo.local_1, 0xff000000, 0.0f, 1.0f);
		MK_VERTEX(&(this->f_b0->f_70.asVertex[1]), lolo.local_18[1], (float)D_00C3FB4C - lolo.local_2, (float)D_00C3FB48, 0.986842f, 1.0f, lolo.local_1, 0xff000000, 1.0f, 0.0f);
		MK_VERTEX(&(this->f_b0->f_70.asVertex[3]), lolo.local_18[0], (float)(D_00C3FB58 * D_0090147C) + D_00C3F784, (float)(D_00C3FB5C * D_00901480) + D_00C3F788, 0.986842f, 1.0f, lolo.local_1, 0xff000000, 1.0f, 1.0f);
	}
}

//render "shoot gauge"
void Class_coaster_D8::C_005F15C7() {
	struct {
		//local_7 this
		struct t_dx_rend_vertex_20 *local_11[4];
		int local_2;
		int local_1;
	}lolo;

	lolo.local_1 = (D_00C3FB50 << 7) >> 7;
	lolo.local_2 = D_00901480 * 0xdc - D_00C3FB50 * D_00901480 + D_00C3F788;
	if(C_0066E272(1, this->f_cc)) {
		MK_VERTEX(&(this->f_cc->f_70.asVertex)[0], lolo.local_11[3], (float)(D_0090147C * 0x14) + D_00C3F784, (float)lolo.local_2, 0, 1.0f, 0xff000000 | ((0x80 - lolo.local_1) << 0x10) | (lolo.local_1 << 8), 0xff000000, 0.0f, 0.0f);
		MK_VERTEX(&(this->f_cc->f_70.asVertex)[1], lolo.local_11[2], (float)(D_0090147C * 0x14) + D_00C3F784, (float)(D_00901480 * 0xdc) + D_00C3F788, 0, 1.0f, 0xFF800000, 0xff000000, 0.0f, 0.0f);
		MK_VERTEX(&(this->f_cc->f_70.asVertex)[2], lolo.local_11[1], (float)(D_0090147C * 0x1c) + D_00C3F784, (float)lolo.local_2, 0, 1.0f, 0xff000000 | ((0x80 - lolo.local_1) << 0x10) | (lolo.local_1 << 8), 0xff000000, 0.0f, 0.0f);
		MK_VERTEX(&(this->f_cc->f_70.asVertex)[3], lolo.local_11[0], (float)(D_0090147C * 0x1c) + D_00C3F784, (float)(D_00901480 * 0xdc) + D_00C3F788, 0, 1.0f, 0xFF800000, 0xff000000, 0.0f, 0.0f);
	}
}

//render "waku"
void Class_coaster_D8::C_005F1838() {
	struct {
		//local_6 this
		struct t_dx_rend_vertex_20 *local_5[4];
		unsigned local_1;
	}lolo;

	lolo.local_1 = 0xffffffff;
	if(C_0066E272(1, this->f_d0)) {
		MK_VERTEX(&(this->f_d0->f_70.asVertex)[0], lolo.local_5[3], (float)(D_0090147C * 0x12) + D_00C3F784, (float)(D_00901480 * 0x56) + D_00C3F788, 0, 1.0f, lolo.local_1, 0xff000000, 0.0f, 0.0f);
		MK_VERTEX(&(this->f_d0->f_70.asVertex)[1], lolo.local_5[2], (float)(D_0090147C * 0x12) + D_00C3F784, (float)(D_00901480 * 0xe2) + D_00C3F788, 0, 1.0f, lolo.local_1, 0xff000000, 0.0f, 1.0f);
		MK_VERTEX(&(this->f_d0->f_70.asVertex)[2], lolo.local_5[1], (float)(D_0090147C * 0x1e) + D_00C3F784, (float)(D_00901480 * 0x56) + D_00C3F788, 0, 1.0f, lolo.local_1, 0xff000000, 1.0f, 0.0f);
		MK_VERTEX(&(this->f_d0->f_70.asVertex)[3], lolo.local_5[0], (float)(D_0090147C * 0x1e) + D_00C3F784, (float)(D_00901480 * 0xe2) + D_00C3F788, 0, 1.0f, lolo.local_1, 0xff000000, 1.0f, 1.0f);
	}
}

//render "status box"
void Class_coaster_D8::C_005F1A71() {
	struct {
		//local_8 this
		struct t_dx_rend_vertex_20 *local_7[4];
		int local_3;
		unsigned local_2;
		int local_1;
	}lolo;

	lolo.local_1 = D_0090147C * 0xc8 + D_00C3F784;
	lolo.local_3 = D_00901480 * 0x137 + D_00C3F784;
	//-- make larger for score >= 9999 --
	if(D_00C3F74C >= 9999)
		lolo.local_3 += D_0090147C * 0xf + D_00C3F784;
	//-- --
	lolo.local_2 = 0xffffffff;
	if(C_0066E272(1, this->f_c4)) {
		MK_VERTEX(&(this->f_c4->f_70.asVertex[0]), lolo.local_7[3], (float)lolo.local_1, (float)(D_00901480 * 0xc0) + D_00C3F788, 0, 1.0f, lolo.local_2, 0xff000000, 0.0f, 0.0f);
		MK_VERTEX(&(this->f_c4->f_70.asVertex[1]), lolo.local_7[2], (float)lolo.local_1, (float)(D_00901480 * 0xdf) + D_00C3F788, 0, 1.0f, lolo.local_2, 0xff000000, 0.0f, 1.0f);
		MK_VERTEX(&(this->f_c4->f_70.asVertex[2]), lolo.local_7[1], (float)lolo.local_3, (float)(D_00901480 * 0xc0) + D_00C3F788, 0, 1.0f, lolo.local_2, 0xff000000, 1.0f, 0.0f);
		MK_VERTEX(&(this->f_c4->f_70.asVertex[3]), lolo.local_7[0], (float)lolo.local_3, (float)(D_00901480 * 0xdf) + D_00C3F788, 0, 1.0f, lolo.local_2, 0xff000000, 1.0f, 1.0f);
	}
}

//render "pause"
void Class_coaster_D8::C_005F1CB5() {
	struct {
		//local_6 this
		struct t_dx_rend_vertex_20 *local_5[4];
		unsigned local_1;
	}lolo;

	lolo.local_1 = 0xffffffff;
	if(C_0066E272(1, this->f_c8)) {
		MK_VERTEX(&(this->f_c8->f_70.asVertex)[0], lolo.local_5[3], (float)(D_0090147C * 0xc8) + D_00C3F784, (float)(D_00901480 * 0xc0) + D_00C3F788, 0, 1.0f, lolo.local_1, 0xff000000, 0.0f, 0.0f);
		MK_VERTEX(&(this->f_c8->f_70.asVertex)[1], lolo.local_5[2], (float)(D_0090147C * 0xc8) + D_00C3F784, (float)(D_00901480 * 0xe0) + D_00C3F788, 0, 1.0f, lolo.local_1, 0xff000000, 0.0f, 1.0f);
		MK_VERTEX(&(this->f_c8->f_70.asVertex)[2], lolo.local_5[1], (float)(D_0090147C * 0x137) + D_00C3F784, (float)(D_00901480 * 0xc0) + D_00C3F788, 0, 1.0f, lolo.local_1, 0xff000000, 1.0f, 0.0f);
		MK_VERTEX(&(this->f_c8->f_70.asVertex)[3], lolo.local_5[0], (float)(D_0090147C * 0x137) + D_00C3F784, (float)(D_00901480 * 0xe0) + D_00C3F788, 0, 1.0f, lolo.local_1, 0xff000000, 1.0f, 1.0f);
	}
}

//render "score"
void Class_coaster_D8::C_005F1F00() {
	struct {
		//local_10 this
		struct t_dx_rend_vertex_20 *local_9[4];
		int local_5;
		unsigned local_4;
		int local_3;
		int local_2;
		int local_1;
	}lolo;

	lolo.local_4 = 0xffffffff;
	lolo.local_2 = D_0090147C * 0xcc + D_00C3F784;
	lolo.local_5 = D_0090147C * 0xf3 + D_00C3F784;
	lolo.local_1 = D_00901480 * 0xc8 + D_00C3F788;
	lolo.local_3 = D_00901480 * 0xe8 + D_00C3F788;
	C_0066E272(1, this->f_c0);
	MK_VERTEX(&(this->f_c0->f_70.asVertex[0]), lolo.local_9[3], (float)lolo.local_2, (float)lolo.local_1, 0, 1.0f, lolo.local_4, 0xff000000, (0.0f/255.0f), (0.0f/255.0f));
	MK_VERTEX(&(this->f_c0->f_70.asVertex[1]), lolo.local_9[2], (float)lolo.local_2, (float)lolo.local_3, 0, 1.0f, lolo.local_4, 0xff000000, (0.0f/255.0f), (255.0f/255.0f));
	MK_VERTEX(&(this->f_c0->f_70.asVertex[2]), lolo.local_9[1], (float)lolo.local_5, (float)lolo.local_1, 0, 1.0f, lolo.local_4, 0xff000000, (47.0f/255.0f), (0.0f/255.0f));
	MK_VERTEX(&(this->f_c0->f_70.asVertex[3]), lolo.local_9[0], (float)lolo.local_5, (float)lolo.local_3, 0, 1.0f, lolo.local_4, 0xff000000, (47.0f/255.0f), (255.0f/255.0f));
	this->C_005F2119(D_00C3F74C, D_0090147C * 0xec, D_00901480 * 0xc8, 0);//render number
}

//render number
void Class_coaster_D8::C_005F2119(int bp08, short x/*bp0c*/, short y/*bp10*/, short bp14) {
	struct {
		//local_16 this
		struct t_dx_rend_vertex_20 *local_15[4];
		float fu_1;//local_11
		float fu_0;//local_10
		float fy;//local_9
		float fx;//local_8
		int dwDigitIndex;//local_7
		int local_6;
		int dwRemain;//local_5
		unsigned local_4;
		int i;//local_3
		int dwCurPower;//local_2
		int dwMaxDigits;//local_1
	}lolo;

	lolo.dwMaxDigits = 4;
	lolo.dwCurPower = 1000;
	lolo.local_4 = 0xffffffff;
	lolo.local_6 = 1;
	lolo.dwRemain = bp08 + 1;
	if(bp08 > 9999) {
		lolo.dwMaxDigits = 5;
		lolo.dwCurPower = 10000;
	}
	for(lolo.i = 0; lolo.i < lolo.dwMaxDigits; lolo.i ++) {
		lolo.dwDigitIndex = 0;
		while(lolo.dwRemain > lolo.dwCurPower) {
			lolo.dwDigitIndex ++;
			lolo.dwRemain -= lolo.dwCurPower;
		}
		if(lolo.dwDigitIndex)
			lolo.local_6 = 0;
		if(bp08 == 0 && lolo.dwCurPower == 1)
			lolo.local_6 = 0;
		if(bp14 == 1 || lolo.dwDigitIndex || lolo.local_6 == 0) {//else 005F23FE
			lolo.fx = (float)(x + lolo.i * (D_0090147C * 13)) + D_00C3F784;
			lolo.fy = (float)(y) + D_00C3F788;
			lolo.fu_0 = (float)(lolo.dwDigitIndex * 0x10 + 0x30) / 255.0f;
			lolo.fu_1 = (float)(lolo.dwDigitIndex * 0x10 + 0x40) / 255.0f;
			C_0066E272(1, this->f_c0);
			MK_VERTEX(&(this->f_c0->f_70.asVertex[0]), lolo.local_15[3], lolo.fx                           , lolo.fy                           , 0, 1.0f, lolo.local_4, 0xff000000, lolo.fu_0, 0.0f);
			MK_VERTEX(&(this->f_c0->f_70.asVertex[1]), lolo.local_15[2], lolo.fx                           , lolo.fy + (float)(D_00901480 * 29), 0, 1.0f, lolo.local_4, 0xff000000, lolo.fu_0, 1.0f);
			MK_VERTEX(&(this->f_c0->f_70.asVertex[2]), lolo.local_15[1], lolo.fx + (float)(D_0090147C * 15), lolo.fy                           , 0, 1.0f, lolo.local_4, 0xff000000, lolo.fu_1, 0.0f);
			MK_VERTEX(&(this->f_c0->f_70.asVertex[3]), lolo.local_15[0], lolo.fx + (float)(D_0090147C * 15), lolo.fy + (float)(D_00901480 * 29), 0, 1.0f, lolo.local_4, 0xff000000, lolo.fu_1, 1.0f);
		}
		lolo.dwCurPower /= 10;
	}
}

//render alpha quad
void Class_coaster_D8::C_005F2417(unsigned char bp08) {
	struct {
		//local_6 this
		struct t_dx_rend_vertex_20 *local_5[4];
		tRGBA local_1;
	}lolo;

	lolo.local_1.c.r = 0;
	lolo.local_1.c.g = 0;
	lolo.local_1.c.b = 0;
	lolo.local_1.c.a = bp08;
	C_0066E272(1, this->f_d4);
	MK_VERTEX(&(this->f_d4->f_70.asVertex[0]), lolo.local_5[3], (float)(D_0090147C * 0)   + D_00C3F784, (float)(D_00901480 * 0)   + D_00C3F788, 0, 1.0f, lolo.local_1.rgba, 0xff000000, 0.0f, 0.0f);
	MK_VERTEX(&(this->f_d4->f_70.asVertex[1]), lolo.local_5[2], (float)(D_0090147C * 0)   + D_00C3F784, (float)(D_00901480 * 240) + D_00C3F788, 0, 1.0f, lolo.local_1.rgba, 0xff000000, 0.0f, 1.0f);
	MK_VERTEX(&(this->f_d4->f_70.asVertex[2]), lolo.local_5[1], (float)(D_0090147C * 320) + D_00C3F784, (float)(D_00901480 * 0)   + D_00C3F788, 0, 1.0f, lolo.local_1.rgba, 0xff000000, 1.0f, 0.0f);
	MK_VERTEX(&(this->f_d4->f_70.asVertex[3]), lolo.local_5[0], (float)(D_0090147C * 320) + D_00C3F784, (float)(D_00901480 * 240) + D_00C3F788, 0, 1.0f, lolo.local_1.rgba, 0xff000000, 1.0f, 1.0f);
}

void Class_coaster_D8::C_005F2639(struct SVECTOR *bp08, LPD3DMATRIX bp0c, float *bp10) {
	struct {//local_5 this
		struct t_g_drv_0c local_4;
		float local_1;
	}lolo;

	lolo.local_4.f_00 = (float)bp08->f_00;
	lolo.local_4.f_04 = (float)bp08->f_02;
	lolo.local_4.f_08 = (float)bp08->f_04;
	C_0066CE40(bp0c, &lolo.local_4, bp10);
	//-- normalize --
	if(bp10[3] == 0.0f)
		bp10[3] = 0.1f;
	lolo.local_1 = 1.0f / bp10[3];
	bp10[0] *= lolo.local_1;
	bp10[1] *= lolo.local_1;
	bp10[2] *= lolo.local_1;
	bp10[3] = lolo.local_1;
}

int Class_coaster_D8::C_005F26EB(struct SVECTOR *bp08, LPD3DMATRIX bp0c, struct t_g_drv_0c *bp10) {
	//local_4 this
	struct t_g_drv_0c local_3;

	local_3.f_00 = (float)bp08->f_00;
	local_3.f_04 = (float)bp08->f_02;
	local_3.f_08 = (float)bp08->f_04;
	C_0066CED8(bp0c, &local_3, bp10);//matrix/vector another operation(1)?
	if(bp10->f_08 > 0)
		return 1;

	return 0;
}

//dot product with matrix column 3
float Class_coaster_D8::C_005F2759(struct SVECTOR *bp08, LPD3DMATRIX bp0c) {
	struct {
		//local_5 this
		float local_4;
		struct t_g_drv_0c local_3;
	}lolo;

	lolo.local_3.f_00 = (float)bp08->f_00;
	lolo.local_3.f_04 = (float)bp08->f_02;
	lolo.local_3.f_08 = (float)bp08->f_04;
	lolo.local_4 = bp0c->_13 * lolo.local_3.f_00 + bp0c->_23 * lolo.local_3.f_04 + bp0c->_33 * lolo.local_3.f_08 + bp0c->_43;

	return lolo.local_4;
}

//update some matrix stuff?
void Class_coaster_D8::C_005F27BF(struct MATRIX *bp08) {
	struct {
		//local_20 this
		LPD3DMATRIX local_19;
		struct t_aa0 *local_18;
		D3DMATRIX local_17;
		LPD3DMATRIX local_1;
	}lolo;

	lolo.local_18 = C_00676578();
	lolo.local_19 = lolo.local_18->f_2fc;//some ratio matrix?
	lolo.local_1 = &(lolo.local_18->f_890);//projection matrix?
	C_006611FB(bp08, &lolo.local_17);//psx:transformation to D3DMATRIX(1)
	C_0066C984(&lolo.local_17, lolo.local_19, this->f_80);//[optimized]matrix multiplication 4x4
	C_0066C984(this->f_80, lolo.local_1, this->f_84);//[optimized]matrix multiplication 4x4
}

//get light ratio
float Class_coaster_D8::C_005F2838(float bp08) {
	//local_1 this
	if(D_00C3F750 > bp08)
		return 1.0f;
	if(D_00C3F754 < bp08)
		return 0.0f;

	return 1.0f - (bp08 - D_00C3F750) / (D_00C3F754 - D_00C3F750);
}

//apply light ratio to color?
unsigned int Class_coaster_D8::C_005F2897(tRGBA *bp08, float bp0c) {
	//local_2 this
	tRGBA local_1;

	local_1 = *bp08;
	local_1.c.r *= bp0c;
	local_1.c.g *= bp0c;
	local_1.c.b *= bp0c;

	return 0xff000000 | (local_1.c.r << 0x10) | (local_1.c.g << 8) | local_1.c.b;
}

//"refresh" graphics
void Class_coaster_D8::C_005F2924() {
	//local_2 this
	struct t_aa0 *local_1;

	local_1 = C_00676578();
	//-------------
	//-- LAYER 0 --
	//-------------
	//objects
	C_0066E641(this->f_88, local_1);//dx_spr:render something?
	C_0066E62C(this->f_88);//dx_spr:reset something?
	C_00660E6A(this->f_8c, local_1);//G_DRV_80?
	C_0066E62C(this->f_8c);//dx_spr:reset something?
	//-------------
	//-- LAYER 1 --
	//-------------
	C_00660E95(1, local_1);//G_DRV_84?change_layer
	//objects(transparent)
	C_0066E641(this->f_94, local_1);//dx_spr:render something?
	C_0066E62C(this->f_94);//dx_spr:reset something?
	C_00660E6A(this->f_98, local_1);//G_DRV_80?
	C_0066E62C(this->f_98);//dx_spr:reset something?
	//beam
	C_0066E641(this->f_b0, local_1);//dx_spr:render something?
	C_0066E62C(this->f_b0);//dx_spr:reset something?
	//-------------
	//-- LAYER 0 --
	//-------------
	C_00660E95(0, local_1);//G_DRV_84?change_layer
	//tracks
	C_0066E641(this->f_a0, local_1);//dx_spr:render something?
	C_0066E62C(this->f_a0);//dx_spr:reset something?
	C_00660E6A(this->f_a4, local_1);//G_DRV_80?
	C_0066E62C(this->f_a4);//dx_spr:reset something?
	//sight
	C_0066E641(this->f_ac, local_1);//dx_spr:render something?
	C_0066E62C(this->f_ac);//dx_spr:reset something?
	//gauge+waku
	C_0066E641(this->f_cc, local_1);//dx_spr:render something?
	C_0066E62C(this->f_cc);//dx_spr:reset something?
	C_0066E641(this->f_d0, local_1);//dx_spr:render something?
	C_0066E62C(this->f_d0);//dx_spr:reset something?
	//gauge+waku(why 2 times?)
	C_0066E641(this->f_cc, local_1);//dx_spr:render something?
	C_0066E62C(this->f_cc);//dx_spr:reset something?
	C_0066E641(this->f_d0, local_1);//dx_spr:render something?
	C_0066E62C(this->f_d0);//dx_spr:reset something?
	//status box
	C_0066E641(this->f_c4, local_1);//dx_spr:render something?
	C_0066E62C(this->f_c4);//dx_spr:reset something?
	C_0066E641(this->f_c0, local_1);//dx_spr:render something?
	C_0066E62C(this->f_c0);//dx_spr:reset something?
	//pause
	C_0066E641(this->f_c8, local_1);//dx_spr:render something?
	C_0066E62C(this->f_c8);//dx_spr:reset something?
	//-------------
	//-- LAYER 1 --
	//-------------
	C_00660E95(1, local_1);//G_DRV_84?change_layer
	//alpha quad
	C_0066E641(this->f_d4, local_1);//dx_spr:render something?
	C_0066E62C(this->f_d4);//dx_spr:reset something?
}
