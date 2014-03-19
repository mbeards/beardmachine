
#ifndef __BEARD_CPU_H__
#define __BEARD_CPU_H__

typedef unsigned char BYTE_T;
typedef unsigned char bool;
#define true 1
#define false 0

enum special_registers {
  PROGRAM_COUNTER=0,
  STACK_POINTER=1,
  JUMP_TARGET=2,
  UNDEFINED=3
};

typedef enum {
  NOP=0,
  LOAD,
  STORE,
  CP,
  CSP,
  CPS,
  INC,
  NOR,
  J,
  JLE,
  PRINT,
  READ
} OPCODE_T;

typedef struct BeardCPU {
  BYTE_T registers[4];
  BYTE_T special_registers[4];
  BYTE_T memory[256];
} BeardCPU;

void step(BeardCPU* inCPU);

void advance(BeardCPU* inCPU);

BYTE_T read_ram(const BYTE_T address, const BeardCPU* const inCPU);

void write_ram(const BYTE_T address, const BYTE_T value, BeardCPU* const inCPU);

BYTE_T read_register(const unsigned int register_id, const bool special, const BeardCPU* const inCPU);

void write_register(const unsigned int register_id, const bool special, const BYTE_T value, BeardCPU* const inCPU);
#endif
