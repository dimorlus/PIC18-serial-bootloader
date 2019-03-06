//---------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SysUtils.hpp>


#pragma hdrstop
#include "types.h"
#include "Hex.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

u16 AddrHi = 0;

//---------------------------------------------------------------------------
bool h2d(char c, u8* d)
{
 if ((c >= '0') && (c <= '9')) *d += c-'0';
 else
 if ((c >= 'A') && (c <= 'F')) *d += 10 + c-'A';
 else
 if ((c >= 'a') && (c <= 'f')) *d += 10 + c-'a';
 else return false;
 return true;
}

//---------------------------------------------------------------------------
int hex2dat(const char* xstr, int data_len, unsigned char* data)
{
 int i;
 u8 d = 0;
 for(i = 0; i < data_len; i++)
  {
   char c = xstr[i];
   if ((c >= '0') && (c <= '9')) d += c-'0';
   else
   if ((c >= 'A') && (c <= 'F')) d += 10 + c-'A';
   else
   if ((c >= 'a') && (c <= 'f')) d += 10 + c-'a';
   else break;

   if (i%2)
    {
     *data++ = d;
     d = 0;
    }
   else d *= 16;
  }
 if (i < data_len) return -1;
 return i;
}

//---------------------------------------------------------------------------
int hex2byte(const char* xstr, u8* data)
{
 int i;
 u8 d = 0;
 for(i = 0; i < 2; i++)
  {
   char c = xstr[i];
   if ((c >= '0') && (c <= '9')) d += c-'0';
   else
   if ((c >= 'A') && (c <= 'F')) d += 10 + c-'A';
   else
   if ((c >= 'a') && (c <= 'f')) d += 10 + c-'a';
   else break;

   if (i%2)
    {
     *data = d;
     d = 0;
    }
   else d *= 16;
  }
 return i;
}

//---------------------------------------------------------------------------
bool isHex(char c)
{
 return ((c >= '0') && (c <= '9'))||
        ((c >= 'A') && (c <= 'F'))||
        ((c >= 'a') && (c <= 'f'));
}

//---------------------------------------------------------------------------
int hex2word(const char* xstr, u16* data)
{
 int i;
 u8 d = 0;
 *data = 0;
 for(i = 0; i < 4; i++)
  {
   char c = xstr[i];
   if ((c >= '0') && (c <= '9')) d += c-'0';
   else
   if ((c >= 'A') && (c <= 'F')) d += 10 + c-'A';
   else
   if ((c >= 'a') && (c <= 'f')) d += 10 + c-'a';
   else break;

   if (i%2)
    {
     *data *= 256;
     *data += d;
     d = 0;
    }
   else d *= 16;
  }
 return i;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//:CCDDEEFFGGHH
//AABB = hex line number
//CC   = n
//DDEE = Address low
//FF   = Record type 00 - data, 01 - end, 04 Address high
//n x GG = data
//HH = checksum
bool HexStr(const char* shex, hexrec *rec)
{
 const char *cp = shex;
 int i;

 memset(rec, 0, sizeof(hexrec));
 bool ok = false;
 if (*cp++ == ':')
  {
   const char *cph = cp;
   u8 cs = 0;
   cp += hex2byte(cp, &rec->n);
   cp += hex2word(cp, &rec->AddrLo);
   cp += hex2byte(cp, &rec->type);
   for(i = 0; i<rec->n; i++)
    cp += hex2byte(cp, &rec->data[i]);
   hex2byte(cp, &rec->ch);

   while(isHex(*cph)) //calculate checksum, 0 if OK.
    {
     u8 bb;
     cph += hex2byte(cph, &bb);
     cs += bb;
    }
   if (cs == 0)
    {
     if (rec->type == htExtAddr) AddrHi = rec->data[0]*256+rec->data[1];
     rec->AddrHi = AddrHi;
     ok = true;
    }
  }
 return ok;
}
