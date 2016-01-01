#define __FF7FILE__ "C:\\FF7\\coaster\\psxdata_c.cpp"

#include "ff7.h"

#include "coaster_data.h"

int psxdata_c::C_005EE620(const char *bp08, const char *bp0c) {
	struct {
		unsigned i;//local_2
		int local_1;
	}lolo;

	if(this->f_10 == 0) {
		lolo.local_1 = 0;
		this->f_00 = this->C_005EE743(bp0c, &(this->f_04));//psxdata_c:load & alloc resource
		this->f_0c = (int *)this->C_005EE743(bp08, &lolo.local_1);//psxdata_c:load & alloc resource
		this->f_08 = this->f_0c[0];
		for(lolo.i = 0; lolo.i < (unsigned)lolo.local_1 / 4; lolo.i ++)
			this->f_0c[lolo.i] -= this->f_08;
		this->f_10 = 1;
	}

	return this->f_10;
}

//clean
void psxdata_c::C_005EE6CC() {
	if(this->f_0c)
		C_0065FB40(this->f_0c, __FF7FILE__, 0x46);
	if(this->f_00)
		C_0065FB40(this->f_00, __FF7FILE__, 0x48);
	this->f_0c = 0;
	this->f_00 = 0;
	this->f_10 = 0;
}

psxdata_c::~psxdata_c() {//C_005EE730
	this->C_005EE6CC();//clean
}

//psxdata_c:load & alloc resource
void *psxdata_c::C_005EE743(const char *bp08, int *bp0c) {
	void *local_2;
	int local_1;

	local_1 = 0;
	local_2 = 0;
	local_1 = C_006759D2(bp08, 9);//is_lib:get entry offset?
	if(local_1) {
		*bp0c = C_006762EA(local_1, 9);//is_lib:get entry size
		if(*bp0c) {
			local_2 = C_0065FDA1(*bp0c, __FF7FILE__, 0x64);
			if(local_2) {
				if(C_0067633E(local_1, 9, local_2, *bp0c) == 0) {//is_lib:load entry
					free(local_2);
					local_2 = 0;
				}
			}
		}
	}

	return local_2;
}
