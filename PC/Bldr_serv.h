//---------------------------------------------------------------------------

#ifndef Bldr_servH
#define Bldr_servH
#include "types.h"

#define WRITE_FLASH_BLOCKSIZE    64
#define ERASE_FLASH_BLOCKSIZE    64
#define END_FLASH                0x004000
#define ROW_SIZE                 32;
#pragma pack(1)

typedef enum {no_ans = 0, cmd_ok = 1, addr_err = 0xfe, cmd_err = 0xff} results;
typedef enum {cmVer=0, cmReadFh, cmWriteFh, cmEraseFh,
              cmReadEE, cmWriteEE, cmReadCfg, cmWriteCfg,
              cmChkSum, cmRst} commands;

typedef struct
 {
  u8 autobaud;
  u8  command;
  u16 data_length;
  union
   {
    struct
     {
      u8 EE_key_1;
      u8 EE_key_2;
     };
    struct
     {
      u16 EE_key;
     };
   };
  union
   {
    struct
     {
      u8 address_L;
      u8 address_H;
      u8 address_U;
      u8 address_unused;
     };
    struct
     {
      u32 address;
     };
   };
 } header_t;

typedef union
 {
  u8 result;
  u16 checksum;
  struct
   {
    u16 version;
    u32 max_pkt_size;
    u16 dev_id;
    u16 zero;
    u8 erase_blk;
    u8 write_blk;
    u32 config;
   };
 } answer_t;

typedef union
{
 struct
  {
   header_t header;
   union
    {
     u8 data[WRITE_FLASH_BLOCKSIZE];
     answer_t answer;
    };
  };
 u8 buffer[WRITE_FLASH_BLOCKSIZE + sizeof(header_t)];
}frame_t;


//---------------------------------------------------------------------------
extern void *List;
extern FILE *HexFile;
//---------------------------------------------------------------------------
extern u16 Version;
extern u32 FlashWords;
extern u32 Offset;
extern u32 RowSize;
extern u32 EEaddr;
extern u32 EEsize;
extern u32 CFGaddr;
extern u32 CFGsize;
extern u32 UIDaddr;
extern u32 UIDsize;

int prog_states(void* port, bool start);


//---------------------------------------------------------------------------

#endif
