#define __FF7FILE__ "C:\\lib\\src\\file\\is_lib.cpp"

#include "ff7.h"

//(archive/LGP related)

////////////////////////////////////////
struct t_is_lib_fileentry {//size 0x18
    /*+00*/char name[0x10];
    /*+10*/int dwOffset;//in archive
    /*+14*/short f_14;//unused?
    /*+16*/unsigned short f_16;//index[+1] to path info
};

struct t_is_lib_fileinfo {//size 8
    /*+00*/struct t_is_lib_fileentry *pFileEntries;
    /*+04*/int dwNumEntries;
};

struct t_is_lib_pathentry {//size 0x82
    /*+00*/char f_00[0x80];//path
    /*+80*/unsigned short dwEntryIndex;
};

struct t_is_lib_pathinfo {//size 8
    /*+00*/char f_00; char __01[3];//# of entries
    /*+04*/struct t_is_lib_pathentry *f_04;
};

struct t_is_lib_index {//size 4
    /*+00*/unsigned short _first;//first index + 1
    /*+02*/unsigned short _num;//# of elements
};
////////////////////////////////////////
struct t_is_lib_fileinfo D_00D8F678[0x12];
int D_00D8F708[0x12];//# of "path info" objects?
struct t_is_lib_pathinfo D_00D8F750[0x12][0x3e8];//0x1f40=0x3e8*8
int D_00DB29D0[0x12];//file handles
char D_00DB2A18[0x80];//"virtual path"
struct t_is_lib_index *D_00DB2A98[0x12];//"fast indexes" -- 30x30 array
short D_00DB2AE0;//# of opened archives?
int D_00DB2AE4;//use "virtual path" flag
int D_00DB2AE8;//archive id[unused]
////////////////////////////////////////
//is_lib:set archive id(unused)
void C_006750E0(int bp08) {
    D_00DB2AE8 = bp08;
}

//is_lib:get archive id(unused)
int __006750ED() {
    return D_00DB2AE8;
}

//is_lib:fopen
FILE *__006750F7(const char *bp08, const char *bp0c) {
    FILE *local_1;

    local_1 = fopen(bp08, bp0c);

    return local_1;
}

//is_lib:fclose
short __00675115(FILE *bp08) {
    short local_1;

    if (bp08)
        local_1 = fclose(bp08);

    return local_1;
}

//is_lib:fseek
void C_00675137(FILE *bp08, long bp0c, int bp10) {
    fseek(bp08, bp0c, bp10 & 0xffff);
}

//is_lib:ftell
long C_00675155(FILE *bp08) {
    return ftell(bp08);
}

//is_lib:ffile size?
long __00675166(FILE *bp08) {
    long local_2;
    long local_1;

    local_2 = C_00675155(bp08);//is_lib:ftell
    C_00675137(bp08, 0, SEEK_END);//is_lib:fseek
    local_1 = C_00675155(bp08);//is_lib:ftell
    C_00675137(bp08, local_2, SEEK_SET);//is_lib:fseek

    return local_1;
}

//fread_u8
int __006751B3(FILE *bp08, void *bp0c) {
    int local_2;
    int local_1;

    local_1 = fread(bp0c, 1, 1, bp08);
    local_2 = (local_1 != 1);

    return !local_2;
}

//fread_u16
int __006751E9(FILE *bp08, void *bp0c) {
    int local_2;
    int local_1;

    local_1 = fread(bp0c, 1, 2, bp08);
    local_2 = (local_1 != 2);

    return !local_2;
}

//fread_u32
int __0067521F(FILE *bp08, void *bp0c) {
    int local_2;
    int local_1;

    local_1 = fread(bp0c, 1, 4, bp08);
    local_2 = (local_1 != 4);

    return !local_2;
}

//fread_bytes
short __00675255(FILE *bp08, void *bp0c, unsigned bp10) {
    int local_2;
    unsigned local_1;

    if (bp10 < 0)//nonsense
        return 0;
    local_1 = fread(bp0c, 1, bp10, bp08);
    local_2 = (local_1 != bp10);

    return !local_2;
}

//is_lib:_open
int C_0067529A(const char *bp08, int bp0c) {
    int local_1;

    local_1 = _open(bp08, bp0c);

    return local_1;
}

//is_lib:_close
short C_006752B8(int bp08) {
    short local_1;

    if (bp08 != -1)
        local_1 = _close(bp08);

    return local_1;
}

//is_lib:_lseek
void C_006752DA(int bp08, int bp0c, int bp10) {
    _lseek(bp08, bp0c, bp10 & 0xffff);
}

//is_lib:_tell
int C_006752F8(int bp08) {
    return _tell(bp08);
}

//is_lib:file size?
long __00675309(int bp08) {
    int local_2;
    int local_1;

    local_2 = C_006752F8(bp08);//is_lib:_tell
    C_006752DA(bp08, 0, SEEK_END);//is_lib:_lseek
    local_1 = C_006752F8(bp08);//is_lib:_tell
    C_006752DA(bp08, local_2, SEEK_SET);//is_lib:_lseek

    return local_1;
}

//read_u8
int C_00675356(int bp08, void *bp02) {
    int local_2;
    int local_1;

    local_1 = _read(bp08, bp02, 1);
    local_2 = (local_1 != 1);

    return !local_2;
}

//read_u16
int C_0067538A(int bp08, void *bp02) {
    int local_2;
    int local_1;

    local_1 = _read(bp08, bp02, 2);
    local_2 = (local_1 != 2);

    return !local_2;
}

//read_u32
int C_006753BE(int bp08, void *bp02) {
    int local_2;
    int local_1;

    local_1 = _read(bp08, bp02, 4);
    local_2 = (local_1 != 4);

    return !local_2;
}

//read_bytes
unsigned short C_006753F2(int bp08, void *bp0c, unsigned bp10) {
    int local_2;
    unsigned local_1;

    if (bp10 < 0)//nonsense
        return 0;
    local_1 = _read(bp08, bp0c, bp10);
    local_2 = (local_1 != bp10);

    return !local_2;
}

//fwrite_bytes
int __00675435(FILE *bp08, void *bp0c, int bp10) {
    int local_2;
    int local_1;

    local_1 = fwrite(bp0c, 1, bp10, bp08);
    local_2 = (local_1 != bp10);

    return !local_2;
}

//fwrite_u8
int __0067546F(FILE *bp08, void *bp0c) {
    int local_2;
    int local_1;

    local_1 = fwrite(&bp0c, 1, 1, bp08);
    local_2 = (local_1 != 1);

    return !local_2;
}

//fwrite_u16
int __006754A5(FILE *bp08, void *bp0c) {
    int local_2;
    int local_1;

    local_1 = fwrite(&bp0c, 1, 2, bp08);
    local_2 = (local_1 != 2);

    return !local_2;
}

//fwrite_u32
int __006754DB(FILE *bp08, void *bp0c) {
    int local_2;
    int local_1;

    local_1 = fwrite(&bp0c, 1, 4, bp08);
    local_2 = (local_1 != 4);

    return !local_2;
}

int C_0067564E(int file, int id);//read archive header?
void C_0067577A(int file, int id);//read path infos?

//is_lib:open archive?
int C_00675511(const char *bp08, int dwArchiveId/*bp0c*/) {
    struct {
        int j;//local_3
        int i;//local_2
        int local_1;
    }lolo;

    if (dwArchiveId >= 0x12)
        return 0;
    lolo.local_1 = C_0067529A(bp08, _O_RDONLY | _O_BINARY);//is_lib:_open
    if (lolo.local_1 == -1)
        return 0;
    D_00DB29D0[dwArchiveId] = lolo.local_1;
    if (C_0067564E(lolo.local_1, dwArchiveId) == 0)
        return 0;
    //-- read "fast indexes" --
    D_00DB2A98[dwArchiveId] = (struct t_is_lib_index *)C_0065FDA1(30 * 30 * sizeof(struct t_is_lib_index), /*0090D16C*/__FF7FILE__, 0x192);
    if (D_00DB2A98[dwArchiveId] == 0)
        return 0;
    for (lolo.i = 0; lolo.i < 30; lolo.i++) {
        for (lolo.j = 0; lolo.j < 30; lolo.j++) {
            /*read_u16*/C_0067538A(lolo.local_1, &((D_00DB2A98[dwArchiveId] + lolo.i * 30 + lolo.j)->_first));
            /*read_u16*/C_0067538A(lolo.local_1, &((D_00DB2A98[dwArchiveId] + lolo.i * 30 + lolo.j)->_num));
        }
    }
    C_0067577A(lolo.local_1, dwArchiveId);//read path infos?
    D_00DB2AE0++;

    return 1;
}

//read archive header?
int C_0067564E(int bp08, int bp0c) {
    struct {
        unsigned i;//local_7
        short local_6;
        unsigned dwNumEntries;//local_5
        char local_4[0xa + 6];
    }lolo;

    /*read_u16*/C_0067538A(bp08, &lolo.local_6);//usually [00 00]
    /*read_bytes*/C_006753F2(bp08, lolo.local_4, 0xa);//'SQUARESOFT'
    /*read_u32*/C_006753BE(bp08, &lolo.dwNumEntries);
    D_00D8F678[bp0c].dwNumEntries = lolo.dwNumEntries;
    D_00D8F678[bp0c].pFileEntries = (struct t_is_lib_fileentry *)C_0065FDA1(lolo.dwNumEntries * sizeof(struct t_is_lib_fileentry), /*0090D188*/__FF7FILE__, 0x1cc);
    if (D_00D8F678[bp0c].pFileEntries == 0)
        return 0;
    for (lolo.i = 0; lolo.i < lolo.dwNumEntries; lolo.i++) {
        /*read_bytes*/C_006753F2(bp08, D_00D8F678[bp0c].pFileEntries[lolo.i].name, 0x14);//0x14 > 0x10: they like risks
        /*read_u32*/C_006753BE(bp08, &(D_00D8F678[bp0c].pFileEntries[lolo.i].dwOffset));
        /*read_u8*/C_00675356(bp08, &(D_00D8F678[bp0c].pFileEntries[lolo.i].f_14));
        /*read_u16*/C_0067538A(bp08, &(D_00D8F678[bp0c].pFileEntries[lolo.i].f_16));
    }

    return 1;
}

////////////////////////////////////////

//read path infos?
void C_0067577A(int bp08, int bp0c) {
    int local_2;
    int local_1;

    D_00D8F708[bp0c] = 0;
    /*read_u16*/C_0067538A(bp08, &D_00D8F708[bp0c]);
    for (local_1 = 0; local_1 < D_00D8F708[bp0c]; local_1++) {
        /*read_u16*/C_0067538A(bp08, &D_00D8F750[bp0c][local_1].f_00);//read "int" as "u16":they like risks
        D_00D8F750[bp0c][local_1].f_04 = (struct t_is_lib_pathentry *)C_0065FDA1(D_00D8F750[bp0c][local_1].f_00 * sizeof(struct t_is_lib_pathentry), /*0090D1A4*/__FF7FILE__, 0x1f3);
        for (local_2 = 0; local_2 < D_00D8F750[bp0c][local_1].f_00; local_2++) {
            /*read_bytes*/C_006753F2(bp08, D_00D8F750[bp0c][local_1].f_04[local_2].f_00, 0x80);
            /*read_u16*/C_0067538A(bp08, &(D_00D8F750[bp0c][local_1].f_04[local_2].dwEntryIndex));
        }
    }
}

#if 0 //with MACRO
#define cleanPathInfo_inline(_archive_id, _file_, _line_) {                    \
 int _var_;                                                                 \
                                                                            \
 for(_var_ = 0; _var_ < D_00D8F708[_archive_id]; _var_ ++) {                \
  if(D_00D8F750[_archive_id][_var_].f_04) {                              \
   C_0065FB40(D_00D8F750[_archive_id][_var_].f_04, _file_, _line_);   \
   D_00D8F750[_archive_id][_var_].f_04 = 0;                           \
      }                                                                      \
   }                                                                          \
}
#else //with inline
static inline void cleanPathInfo_inline(int _archive_id, const char *_file_, int _line_) {
    int _var_;

    for (_var_ = 0; _var_ < D_00D8F708[_archive_id]; _var_++) {
        if (D_00D8F750[_archive_id][_var_].f_04) {
            C_0065FB40(D_00D8F750[_archive_id][_var_].f_04, _file_, _line_);
            D_00D8F750[_archive_id][_var_].f_04 = 0;
        }
    }
}
#endif

//clean path info[all archives]?
/**/static void C_00676172() {
    int local_1;

    for (local_1 = 0; local_1 < 0x12; local_1++)
        cleanPathInfo_inline(local_1, /*0090D1C0*/__FF7FILE__, 0x224);
}

//clean path info?
/**/static void C_00675FDE(int dwArchiveId/*bp08*/) {
    if (dwArchiveId >= 0x12)
        return;
    cleanPathInfo_inline(dwArchiveId, /*0090D1DC*/__FF7FILE__, 0x233);
}

////////////////////////////////////////

//is_lib:set "virtual path"
int C_006758C3(const char *bp08) {
    int local_1;

    strcpy(D_00DB2A18, bp08);
    local_1 = strlen(D_00DB2A18);
    if (D_00DB2A18[local_1 - 1] != '\\' && D_00DB2A18[local_1 - 1] != '/') {
        D_00DB2A18[local_1] = '/';
        D_00DB2A18[local_1 + 1] = 0;
    }
    D_00DB2AE4 = 1;

    return 1;
}

//is_lib:"virtual path" off
int C_00675949() {
    D_00DB2AE4 = 0;

    return 1;
}

char C_0067595D(char bp08) {
    char local_1;

    local_1 = tolower(bp08);
    if (local_1 >= 'a' && local_1 <= 'z')
        return local_1;
    if (local_1 >= '0' && local_1 <= '9')
        return local_1 + ('a' - '0');//0x31
    if (local_1 == '_')
        return 0x6b;//'k'?
    if (local_1 == '-')
        return 0x6c;//'l'?
    if (local_1 == '.')
        return local_1;

    return local_1;
}


//is_lib:get entry offset?
int C_006759D2(const char *bp08, int dwArchiveId/*bp0c*/) {
    struct {
        char bp_5b0[128];
        char drive[4];//bp_530
        int bp_52c;
        char dir[256];//bp_528
        char fname[256];//bp_428
        char ext[256];//bp_328
        int dwFirst;//bp_228//local_138
        int bp_224;
        int j;//bp_220//local_136
        char bp_21c[256];
        int i;//bp_11c//local_71
        char bp_118[256];
        int dwEntryIndex;//bp_018
        char name[0x10];//bp_014
        int dwNum;//bp_004//local_1
    }lolo;

    if (dwArchiveId >= 0x12)
        return 0;
    _splitpath(bp08, lolo.drive, lolo.dir, lolo.fname, lolo.ext);
    //-- append "virtual path" --
    if (D_00DB2AE4) {
        strcpy(lolo.bp_5b0, lolo.dir);
        strcpy(lolo.dir, D_00DB2A18);
        strcat(lolo.dir, lolo.bp_5b0);
    }
    //-- --
    strcpy(lolo.name, lolo.fname);
    strcat(lolo.name, lolo.ext);
    lolo.name[strlen(lolo.name)] = 0;
    //-- get "fast index" infos --
    lolo.i = C_0067595D(lolo.name[0]) - 'a';
    if (lolo.name[1] == '.')
        lolo.j = 0;
    else
        lolo.j = C_0067595D(lolo.name[1]) - 'a' + 1;

    lolo.dwFirst = (D_00DB2A98[dwArchiveId] + lolo.i * 30 + lolo.j)->_first;
    if (lolo.dwFirst <= 0)
        return 0;
    lolo.dwFirst--;
    lolo.dwNum = (D_00DB2A98[dwArchiveId] + lolo.i * 30 + lolo.j)->_num;
    //-- --
    for (lolo.i = lolo.dwFirst; lolo.i < lolo.dwFirst + lolo.dwNum; lolo.i++) {
        if (_strcmpi(lolo.name, D_00D8F678[dwArchiveId].pFileEntries[lolo.i].name) == 0) {
            //-- is file name unique? --
            if (D_00D8F678[dwArchiveId].pFileEntries[lolo.i].f_16 == 0)
                return D_00D8F678[dwArchiveId].pFileEntries[lolo.i].dwOffset;
            //-- compare pathes --
            lolo.bp_52c = D_00D8F678[dwArchiveId].pFileEntries[lolo.i].f_16 - 1;
            if (lolo.dir[0] == 0) {//else 00675CDF
                GetCurrentDirectoryA(0x100, lolo.bp_21c);
                lolo.bp_21c[strlen(lolo.bp_21c)] = '/';
                _splitpath(lolo.bp_21c, lolo.drive, lolo.dir, lolo.fname, lolo.ext);
            }
            if (lolo.dir[0] == '\\' || lolo.dir[0] == '/') {//else 00675D3C
                strncpy(lolo.bp_118, lolo.dir + 1, strlen(lolo.dir) - 1);
                lolo.bp_118[strlen(lolo.dir) - 1] = 0;
            }
            else {
                strcpy(lolo.bp_118, lolo.dir);
            }
            lolo.bp_224 = strlen(lolo.bp_118);
            if (lolo.bp_118[lolo.bp_224 - 1] == '\\' || lolo.bp_118[lolo.bp_224 - 1] == '/') {
                lolo.bp_118[lolo.bp_224 - 1] = 0;
                lolo.bp_224--;
            }
            else {
                lolo.bp_118[lolo.bp_224] = 0;
            }
            //-- --
            for (lolo.j = 0; lolo.j < D_00D8F750[dwArchiveId][lolo.bp_52c].f_00; lolo.j++) {
                strncpy(lolo.bp_21c, D_00D8F750[dwArchiveId][lolo.bp_52c].f_04[lolo.j].f_00, strlen(D_00D8F750[dwArchiveId][lolo.bp_52c].f_04[lolo.j].f_00));
                lolo.bp_21c[strlen(D_00D8F750[dwArchiveId][lolo.bp_52c].f_04[lolo.j].f_00)] = 0;
                if (_strcmpi(lolo.bp_118, lolo.bp_21c) == 0) {
                    lolo.dwEntryIndex = D_00D8F750[dwArchiveId][lolo.bp_52c].f_04[lolo.j].dwEntryIndex;
                    return D_00D8F678[dwArchiveId].pFileEntries[lolo.dwEntryIndex].dwOffset;
                }
            }
            //-- --
        }
    }

    return 0;
}

//is_lib:close archive
int C_00675F1D(int dwArchiveId/*bp08*/) {
    if (dwArchiveId >= 0x12)
        return 0;
    //-- --
    if (D_00DB29D0[dwArchiveId] != -1) {
        C_006752B8(D_00DB29D0[dwArchiveId]);//is_lib:_close
        D_00DB29D0[dwArchiveId] = 0;//should be -1?
    }
    if (D_00D8F678[dwArchiveId].pFileEntries) {
        C_0065FB40(D_00D8F678[dwArchiveId].pFileEntries, /*0090D1F8*/__FF7FILE__, 0x2d7);
        D_00D8F678[dwArchiveId].pFileEntries = 0;
    }
    if (D_00DB2A98[dwArchiveId]) {
        C_0065FB40(D_00DB2A98[dwArchiveId], /*0090D214*/__FF7FILE__, 0x2dc);
        D_00DB2A98[dwArchiveId] = 0;
    }
    C_00675FDE(dwArchiveId);//clean path info?

    return 1;
}

//void C_00675FDE(int);//clean path info?

//is_lib:clean?
int C_00676064() {
    unsigned short i;//local_1

    for (i = 0; i < 0x12; i++) {
        if (D_00DB29D0[i] != -1) {
            C_006752B8(D_00DB29D0[i]);//is_lib:_close
            D_00DB29D0[i] = 0;
        }
        if (D_00D8F678[i].pFileEntries) {
            C_0065FB40(D_00D8F678[i].pFileEntries, /*0090D230*/__FF7FILE__, 0x2fa);
            D_00D8F678[i].pFileEntries = 0;
        }
        if (D_00DB2A98[i]) {
            C_0065FB40(D_00DB2A98[i], /*0090D24C*/__FF7FILE__, 0x2ff);
            D_00DB2A98[i] = 0;
        }
    }
    C_00676172();//clean path info[all archives]?

    return 1;
}

//void C_00676172();//clean path info[all archives]?

//is_lib:get archive's handle[unused]
int __0067620F(int dwArchiveId/*bp08*/) {
    if (dwArchiveId >= 0x12)
        return 0;

    return D_00DB29D0[dwArchiveId];
}

//is_lib:seek
int C_00676228(int dwOffset/*bp08*/, int dwArchiveId/*bp0c*/) {
    int _ocal_1;

    if (dwArchiveId >= 0x12)
        return 0;
    if (D_00DB29D0[dwArchiveId] == 0)
        return 0;
    C_006752DA(D_00DB29D0[dwArchiveId], 0, SEEK_SET);//is_lib:_lseek
    C_006752DA(D_00DB29D0[dwArchiveId], dwOffset, SEEK_CUR);//is_lib:_lseek
    if (C_006752F8(D_00DB29D0[dwArchiveId]) != dwOffset) {//is_lib:_tell
        C_006752DA(D_00DB29D0[dwArchiveId], dwOffset, SEEK_SET);//is_lib:_lseek
        /*??? = */C_006752F8(D_00DB29D0[dwArchiveId]);//is_lib:_tell
    }

    return 1;
}

//is_lib:advance seek[unused]
int __006762C7(int bp08, int dwArchiveId/*bp0c*/) {
    C_006752DA(D_00DB29D0[dwArchiveId], bp08, SEEK_CUR);//is_lib:_lseek

    return 1;
}

//is_lib:get entry size
int C_006762EA(int dwEntryOffset/*bp08*/, int dwArchiveId/*bp0c*/) {
    int dwEntrySize;//local_1

    dwEntrySize = 0;
    if (C_00676228(dwEntryOffset, dwArchiveId)) {//is_lib:seek
        C_006752DA(D_00DB29D0[dwArchiveId], 0x14, SEEK_CUR);//is_lib:_lseek
        /*read_u32*/C_006753BE(D_00DB29D0[dwArchiveId], &dwEntrySize);
    }

    return dwEntrySize;
}

//is_lib:load entry
int C_0067633E(int dwEntryOffset/*bp08*/, int dwArchiveId/*bp0c*/, void *bp10, int dwEntrySize/*bp14*/) {
    if (bp10 == 0)
        return 0;
    if (C_00676228(dwEntryOffset, dwArchiveId)) {//is_lib:seek
        C_006752DA(D_00DB29D0[dwArchiveId], 0x14 + 4, SEEK_CUR);//is_lib:_lseek
        if (/*read_bytes*/C_006753F2(D_00DB29D0[dwArchiveId], bp10, dwEntrySize) == 0)
            return 0;
    }

    return 1;
}

//is_lib:...
//[used by file.cpp]
int C_006763A5(int bp08, void *bp0c, int bp10) {
    if (bp0c == 0)
        return 0;
    if (/*read_bytes*/C_006753F2(D_00DB29D0[bp08], bp0c, bp10) == 0)
        return 0;

    return 1;
}
