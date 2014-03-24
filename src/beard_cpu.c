#include <stdlib.h>
#include <stdio.h>
#include "beard_cpu.h"

void step(BeardCPU* inCPU) {

  // Get current instruction
  BYTE_T program_counter = read_register(PROGRAM_COUNTER, true, inCPU);
  BYTE_T instruction = read_ram(program_counter, inCPU);

  // Opcode is upper 4 bits 11110000 == 0xF0.
  OPCODE_T opcode = (instruction & 0xF0) >> 4;

  // Argument A is 00001100 == 0x12
  unsigned int argument_a = (instruction & 0x12) >> 2;

  // Argument B is 00000011 == 0x03
  unsigned int argument_b = (instruction & 0x03);

  // Select operation
  switch(opcode) {
    case LOAD: {
      CPULOG("Decoded LOAD");
      BYTE_T address = read_register(argument_a, false, inCPU);
      BYTE_T value = read_ram(address, inCPU);
      write_register(argument_b, false, value, inCPU);
      break;
    }
    case STORE: {
      CPULOG("Decoded STORE");
      BYTE_T address = read_register(argument_a, false, inCPU);
      BYTE_T value = read_register(argument_b, false, inCPU);
      write_ram(address, value, inCPU);
      break;
    }
    case CP:
      CPULOG("Decoded CP");
      break;
    case CSP:
      CPULOG("Decoded CSP");
      break;
    case CPS:
      CPULOG("Decoded CPS");
      break;
    case INC:
      CPULOG("Decoded INC");
      break;
    case NOR:
      CPULOG("Decoded NOR");
      break;
    case J:
      CPULOG("Decoded J");
      break;
    case JLE:
      CPULOG("Decoded JLE");
      break;
    case PRINT:
      CPULOG("Decoded PRINT");
      break;
    case READ:
      CPULOG("Decoded READ");
      break;
    case HALT:
      CPULOG("Decoded HALT");
      break;
    case LIT:
      CPULOG("Decoded LIT");
      advance(inCPU);
      break;
    case NOP:
    default:
      CPULOG("Decoded NOP");
      break;
  }
  advance(inCPU);
}


/**
 * Read from the CPU's memory
 * @param address The address to access
 * @param inCPU The CPU to access memory from
 * @todo Set error on CPU if access fails
 * @todo Add delay simulation for caching
 **/

BYTE_T read_ram(const BYTE_T address, const BeardCPU* const inCPU) {
  return inCPU->memory[address];  
}

/**
 * Write to the CPU's memory
 * @param address The address to write to
 * @param value The value to write
 * @param inCPU The CPU to write memory to
 * @todo Set error on CPU if write fails
 * @todo Add delay simulation for caching
 **/

void write_ram(const BYTE_T address, const BYTE_T value, BeardCPU* const inCPU) {
  inCPU->memory[address] = value;
}

BYTE_T read_register(const unsigned int register_id, const bool special, const BeardCPU* const inCPU) {
  if(special) {
    return inCPU->special_registers[register_id];
  } else {
    return inCPU->registers[register_id];
  }
}

void write_register(const unsigned int register_id, const bool special, const BYTE_T value, BeardCPU* const inCPU) {
  if(special) {
    inCPU->special_registers[register_id] = value;
  } else {
    inCPU->registers[register_id] = value;
  }
}

/**
 * Advance the program counter
 **/
void advance(BeardCPU* inCPU) {
  BYTE_T program_counter = read_register(0, true, inCPU);
  printf("CPU: Advancing program counter to %.2x\n", program_counter+1);
  write_register(0, true, program_counter + 1, inCPU);
}

BeardCPU* beardmachine_init() {
  // Allocate memory
  BeardCPU* cpu_ptr = (BeardCPU*)malloc(sizeof(struct BeardCPU));

  // Initialize memory with a simple program

  return cpu_ptr;
}

void beardmachine_teardown(BeardCPU* inCPU) {
  free(inCPU);
}
