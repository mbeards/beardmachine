
#ifndef __BEARD_CPU_H__
#define __BEARD_CPU_H__

typedef unsigned char BYTE;

enum special_registers {
  PROGRAM_COUNTER=0,
  STACK_POINTER=1,
  JUMP_TARGET=2,
  UNDEFINED=3
};

enum opcodes {
  NOP=0,
  LOAD,
  CP,
  CSP,
  CPS,
  INC,
  NOR,
  JLE,
  PRINT,
  READ
};

typedef struct BeardCPU {
  BYTE[4] registers;
  BYTE[4] special_registers;
  BYTE[256] memory;
} BeardCPU;

void step(BeardCPU* inCPU);

BYTE read_ram(const BYTE address, const BeardCPU* const inCPU);

void write_ram(const BYTE address, const BYTE value, BeardCPU* const inCPU);

BYTE read_register(const unsigned int register_id, const bool special, const BeardCPU* const inCPU);

void write_register(const unsigned int register_id, const bool special, const BYTE value, BeardCPU* const inCPU);

#endif
