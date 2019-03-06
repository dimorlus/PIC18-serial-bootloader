//---------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <vcl.h>
#pragma hdrstop

#include "StrUtils.h"
#include "Serial.h"
#include "Hex.h"
#include "Bldr_serv.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

TStrings *List;
FILE *HexFile;
//---------------------------------------------------------------------------

int SendFrame(void* port, const frame_t *frame)
{
 u32 i;
 bool res = true;
 for(i=0; i < sizeof(header_t); i++)
  if (res) res &= PutChar(port, frame->buffer[i]);
  else break;
 switch (frame->header.command)
  {
   case cmWriteFh:
   case cmWriteEE:
    {
     for(i = 0; i < frame->header.data_length; i++)
      if (res) res &= PutChar(port, frame->data[i]);
      else break;
    }
   break;
  }
 if (res) return i;
 else return 0;
}

//---------------------------------------------------------------------------
int ReceiveFrame(void* port, frame_t *frame, u8 num, u32 timeout_ms)
{
 u32 ms = mills();
 char c;
 int i = 0;
 while((mills() - ms) < timeout_ms)
  {
   int n = Avail(port);
   if (n >= num)
    {
     while(n)
      {
       c = GetChar(port);
       if (i <= sizeof(frame_t)) frame->buffer[i++] = c;
       n--;
      }
    }
  }
 ClearPort(port);
 return i;
}
//---------------------------------------------------------------------------
typedef enum {rsTimeout, rsWait, rsOk} rresults;

rresults ReceiveFrameNW(void* port, frame_t *frame, u8 num)
{
 char c;
 int i = 0;
  {
   int n = Avail(port);
   if (n >= num)
    {
     while(n)
      {
       c = GetChar(port);
       if (i <= sizeof(frame_t)) frame->buffer[i++] = c;
       n--;
      }
     return rsOk;
    }
   else return rsWait;
  }
}
//---------------------------------------------------------------------------

u16 Version = 256;
u32 FlashWords = 8192;
u32 Offset = 0x500;
u32 RowSize = ROW_SIZE;
u32 EEaddr = 0x310000;
u32 EEsize = 0x100;
u32 CFGaddr = 0x300000;
u32 CFGsize = 0x0c;
u32 UIDaddr = 0x200000;
u32 UIDsize = 0x10;


void PrintFrame(frame_t *fsend)
{
 lprintf(List, "\nCommand: ");
 switch(fsend->header.command)
  {
   case cmVer:
    lprintf(List, "Get version\n");
   break;
   case cmReadFh:
    lprintf(List, "Read Flash\n");
   break;
   case cmWriteFh:
    lprintf(List, "Write Flash\n");
   break;
   case cmEraseFh:
    lprintf(List, "Erase Flash\n");
   break;
   case cmReadEE:
    lprintf(List, "Read EE\n");
   break;
   case cmWriteEE:
    lprintf(List, "Write EE\n");
   break;
   case cmReadCfg:
    lprintf(List, "Read Config\n");
   break;
   case cmWriteCfg:
    lprintf(List, "Write Config\n");
   break;
   case cmChkSum:
    lprintf(List, "Calculate Checksum\n");
   break;
   case cmRst:
    lprintf(List, "Reset Target\n");
   break;
   default:
    lprintf(List, "No command\n");
  }
 lprintf(List, "Address: %08x\n", fsend->header.address);
 lprintf(List, "Length: %d(0x%02x)\n", fsend->header.data_length, fsend->header.data_length);
 lprintf(List, "EE key: %04x\n", fsend->header.EE_key);
 switch(fsend->header.command)
  {
   case cmWriteFh:
   case cmWriteEE:
   case cmWriteCfg:
    {
     if (fsend->header.data_length <= WRITE_FLASH_BLOCKSIZE)
      {
       for(int i=0; i < fsend->header.data_length; i++)
        {
          if (i%16 == 0) lprintf(List, "\n");
          lprintf(List, "%02x ", fsend->data[i]);
        }
       lprintf(List, "\n");
      }
     }
   break;
  }
}

int copybuf(hexrec *rec, frame_t *fsend)
{
 int ofs = (rec->Addr+rec->i) - (fsend->header.address + fsend->header.data_length);
 if ((fsend->header.data_length+ofs) < WRITE_FLASH_BLOCKSIZE)
  {
   fsend->header.data_length+=ofs;
   for(;(rec->i < rec->n) && ((fsend->header.data_length) < WRITE_FLASH_BLOCKSIZE);
       rec->i++, fsend->header.data_length++)
    fsend->data[fsend->header.data_length] = rec->data[rec->i];
    return 1;
  }
 return 0;
 //return rec->n - rec->i;
}

int prog_states(void* port, bool start)
{
 static enum
  {
   stInit,
   stVerSnd,
   stVerRcv,
   stEraseSnd,
   stEraseRcv,
   stReadHex,
   stRecRdy,
   stWriteRcv,
   stWriteSnd,
   stCalcChkSnd,
   stCalcChkRcv,
   stReset,
   stTimeout,
   stError,
   stEnd
  } state = stVerSnd;
 static frame_t fsend;
 static u32 ms;
 static hexrec rec;
 static u16 checksum;
 static u32 timeout;
 static u32 lastaddr;
 frame_t freceive;
 char *cp;

 if (start) state = stInit;

 switch(state)
  {
   case stInit:
    checksum = 0;
    lastaddr = 0;
    AddrHi = 0;
    memset(&rec, 0, sizeof(hexrec));
    ClearPort(port);
    state = stVerSnd;
   break;
   case stVerSnd:
   {
    const u8 fsend[] = {0x55, cmVer, 0, 0, 0, 0, 0, 0};
    lprintf(List, "Read Version\n");
    PrintFrame((frame_t*)&fsend[0]);
    SendFrame(port, (frame_t*)&fsend[0]);
    ms = mills();
    state = stVerRcv;
   }
   break;
   case stVerRcv:
    if ((mills() - ms) > 100) state = stTimeout;
    else
     {
      int n = sizeof(header_t)+sizeof(answer_t);
      if (ReceiveFrameNW(port, &freceive, n) == rsOk)
       {
        lprintf(List, "\nVer = %d\nMax packet zise = %d\nDevID = %04x\n"
         "Erase blk = %d\nWrite blk = %d\nConfig = %08x\n\n",
         freceive.answer.version, freceive.answer.max_pkt_size, freceive.answer.dev_id,
         freceive.answer.erase_blk, freceive.answer.write_blk, freceive.answer.config);

        if (freceive.answer.version == Version) state = stEraseSnd;
        else
         {
          lprintf(List, "Version mismatch\n");
          state = stError;
         }
       }
     }
   break;
   case stEraseSnd:
    {
     u8 rows = (FlashWords*2-Offset)/(2*RowSize);
     u8 fsend[] = {0x55, cmEraseFh, rows, 0, 0x55, 0xAA, Offset%256, Offset/256, 0, 0};
     lprintf(List, "\nErase Flash\n");
     PrintFrame((frame_t*)&fsend[0]);
     SendFrame(port, (frame_t*)&fsend[0]);
     ms = mills();
     timeout = 500;
     state = stEraseRcv;
    }
   break;
   case stWriteRcv:
   case stEraseRcv:
    {
     if ((mills() - ms) > timeout) state = stTimeout;
     else
      {
       int n = sizeof(header_t)+1;
       if (ReceiveFrameNW(port, &freceive, n) == rsOk)
        {
         switch (freceive.answer.result)
          {
           case no_ans:
            state = stError;
            lprintf(List, "no answer\n");
           break;
           case cmd_ok:
            state = stReadHex;
            lprintf(List, "Ok\n");
           break;
           case addr_err:
            state = stError;
            lprintf(List, "Address error\n");
           break;
           case cmd_err:
            state = stError;
            lprintf(List, "Command error\n");
           break;
          }
        }
      }
    }
   break;
   case stReadHex:
    if (HexFile)
     {
      char hstr[64];

      memset((u8*)&fsend, 0xff, sizeof(fsend));
      fsend.header.data_length = 0;
      if (rec.n && (rec.type == htDat))
       {  //use previous hex record
        if (fsend.header.address == -1)
         {
          fsend.header.address = rec.Addr+rec.i;
          copybuf(&rec, &fsend);
          if (fsend.header.data_length == WRITE_FLASH_BLOCKSIZE)
           {
            state = stRecRdy;
            break;
           }
         }
       }
      else
      if (rec.type == htEnd)
       {
        state = stCalcChkSnd;
        break;
       }

      while (cp=fgets(hstr, sizeof(hstr), HexFile))
       {
        lprintf(List, "%s", hstr);
        if (HexStr(hstr, &rec))
         {
           if (rec.type == htDat)
            {
             if (fsend.header.address == -1) fsend.header.address = rec.Addr;
             if (copybuf(&rec, &fsend))
              {
               if (fsend.header.data_length == WRITE_FLASH_BLOCKSIZE)
                {
                 state = stRecRdy;
                 break;
                }
              }
             else
              {
               state = stRecRdy;
               break;
              }
            }
           else
           if (rec.type == htEnd)
            {
             state = stRecRdy;
             break;
            }
         }
        else
         {
          state = stError;
          break;
         }
       }
      if (!cp) state = stRecRdy;
     }
   break;
   case stRecRdy:
    if (fsend.header.data_length)
     {
      fsend.header.autobaud = 0x55;
      if (fsend.header.address < FlashWords*2)
       {
        fsend.header.data_length = WRITE_FLASH_BLOCKSIZE;
        fsend.header.command = cmWriteFh;
        fsend.header.EE_key = 0xAA55;
        for(int i=0; i < fsend.header.data_length; i++)
         if (i&1) checksum += fsend.data[i]*256;
         else checksum += fsend.data[i];
        if (lastaddr < fsend.header.address)
         lastaddr = fsend.header.address+fsend.header.data_length-1;
        state = stWriteSnd;
       }
      else
      if ((fsend.header.address >= EEaddr) &&
          (fsend.header.address < EEaddr+EEsize))
       {
        fsend.header.command = cmWriteEE;
        fsend.header.EE_key = 0xAA55;
        fsend.header.address--; //address correction
        state = stWriteSnd;
       }
      else state = stReadHex;
     }
    //PrintFrame(&fsend);
   break;
   case stWriteSnd:
     lprintf(List, "Write\n");
     PrintFrame(&fsend);
     SendFrame(port, &fsend);
     ms = mills();
     timeout = 100;
     state = stWriteRcv;
   break;
   case stCalcChkSnd:
    {
     //u32 len = FlashWords*2 - Offset;
     u32 len = lastaddr - Offset;
     u8 fsend[] = {0x55, cmChkSum, len%256, len/256, 0, 0, Offset%256, Offset/256, 0, 0};
     lprintf(List, "Calculate Checksum\n");
     PrintFrame((frame_t*)&fsend[0]);
     SendFrame(port, (frame_t*)&fsend[0]);
     ms = mills();
     timeout = 500;
     state = stCalcChkRcv;
    }
   break;
   case stCalcChkRcv:
    {
     if ((mills() - ms) > timeout) state = stTimeout;
     else
      {
       int n = sizeof(header_t)+2;
       if (ReceiveFrameNW(port, &freceive, n) == rsOk)
        {
         u16 chk = freceive.data[0]+freceive.data[1]*256;
         lprintf(List, "Checksum: %04x ", chk);
         if (chk == checksum)
          {
           lprintf(List, "match\n");
           state = stReset;
          }
         else
          {
           lprintf(List, "%04x mismatch\n", checksum);
           state = stEnd;
          }
        }
      }
    }
   break;
   case stReset:
    {
     u8 fsend[] = {0x55, cmRst, 0, 0, 0x55, 0xAA, 0, 0, 0, 0};
     lprintf(List, "Reset Target\n");
     PrintFrame((frame_t*)&fsend[0]);
     SendFrame(port, (frame_t*)&fsend[0]);
     state = stEnd;
    }
   break;
   case stTimeout:
    lprintf(List, "Timeout\n");
    state = stEnd;
   break;
   case stError:
    lprintf(List, "Error\n");
    state = stEnd;
   break;
   case stEnd:
    lprintf(List, "Done %04x\n", checksum);
    return 1;
   break;
  }
 return 0;
}

