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
  uint8_t  command;
  uint16_t data_length;
  union
   {
    struct
     {
      uint8_t  EE_key_1;
      uint8_t  EE_key_2;
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
      uint8_t  address_L;
      uint8_t  address_H;
      uint8_t  address_U;
      uint8_t  address_unused;
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
     uint8_t data[WRITE_FLASH_BLOCKSIZE];
     answer_t answer;
    };
  };
 uint8_t buffer[WRITE_FLASH_BLOCKSIZE + sizeof(header_t)];
}frame_t;


//---------------------------------------------------------------------------
extern TStrings *List;
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
