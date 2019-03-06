//---------------------------------------------------------------------------

#ifndef HexH
#define HexH
#include "types.h"
//---------------------------------------------------------------------------

#pragma pack(push, 1)

enum htypes
 {htDat = 0, htEnd = 1, htSeg = 2, htStartSeg = 3,
  htExtAddr = 4, htStartLinear = 5};

typedef struct
{
 u8 n;
 u8 i;
 u8 HiAddrSave;
 union
  {
   u8 bAddr[4];
   struct
    {
     u16 AddrLo;
     u16 AddrHi;
    };
   u32 Addr;
  };
 u8 type;
 u8 ch;
 u8 data[16];
} hexrec;

#pragma pack(pop)

extern u16 AddrHi;
//---------------------------------------------------------------------------
extern bool HexStr(const char* shex, hexrec *rec);
//---------------------------------------------------------------------------


#endif
