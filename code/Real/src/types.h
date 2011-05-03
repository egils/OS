#ifndef TYPES_H
#define TYPES_H 1


#define BYTE_SIZE 8                     // Baito dydis bitais.
#define WORD_SIZE 8                     // Žodžio dydis baitais.

// Standatriniai tipai
typedef unsigned char     Byte;
typedef signed char       SByte;

typedef char              Boolean;

// 64 bitų dydžiai.
typedef unsigned  long    u64int;
typedef           long    s64int;

// 32 bitų dydžiai.
typedef unsigned  int     u32int;
typedef           int     s32int;
typedef unsigned  short   u16int;
typedef           short   s16int;
typedef unsigned  char    u8int;
typedef           char    s8int;

#define true                1
#define false               0


// Registru struktura
struct context_s
{
  u64int  vector, 
          R15, R14, R13, R12, 
          R11, R10, R9, R8, 
          DI, SI, BP,
          BX, DX, CX, AX,
          error, IP, CS,
          FLAGS, SP, SS;
};

// Interrupt lenteles adresai
typedef signed long         IntPtr;
typedef unsigned long       UIntPtr;

#endif
