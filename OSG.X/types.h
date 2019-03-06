#ifndef types_h
#define types_h

/* types definition */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u16;
typedef signed int s16;
typedef unsigned long u32;
typedef signed long s32;
typedef union {u16 w; u8 b[2];} u16u;
typedef union {u32 dw; u8 b[4]; u16 w[2];} u32u;

enum order {Lo, Hi, HiLo, HiHi}; /* Byte ordering (LSB) */

typedef u8 u1;
typedef unsigned char BOOL;
typedef unsigned char idx8;
#define false 0
#define true 1
#define FALSE 0
#define TRUE 1
#endif /* types_h */
