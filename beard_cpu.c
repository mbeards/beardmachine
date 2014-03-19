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
      BYTE_T address = read_register(argument_a, false, inCPU);
      BYTE_T value = read_ram(address, inCPU);
      write_register(argument_b, false, value, inCPU);
      advance(inCPU);
      break;
    }
    case STORE: {
      BYTE_T address = read_register(argument_a, false, inCPU);
      BYTE_T value = read_register(argument_b, false, inCPU);
      write_ram(address, value, inCPU);
      advance(inCPU);
      break;
    }
    case CP:
      break;
    case CSP:
      break;
    case CPS:
      break;
    case INC:
      break;
    case NOR:
      break;
    case J:
      break;
    case JLE:
      break;
    case PRINT:
      break;
    case READ:
      break;
    case NOP:
    default:
      break;
  }
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
  write_register(0, true, program_counter + 1, inCPU);
}
