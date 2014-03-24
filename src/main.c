#include<stdio.h>

#include "beard_cpu.h"

int main(int argc, char** argv) {
  printf("Beardmachine test\n");

  // Set up a machine
  BeardCPU* cpu = beardmachine_init();


  // Load a program into the cpu
  int lValueCount = 9;
  unsigned char lValues[9] = { 204,7,93,204,254,54,100,157,240 };
  for(int i = 0; i<lValueCount; ++i) {
    cpu->memory[i] = lValues[i];
  }

  char input[128];

  while(true) {
    printf("> ");
    scanf("%s", input);

    if(input[0] == 'r' || (input[0] == 's' && input[1] == 'r')) {
      unsigned int addr;
      scanf("%u", &addr);
      if(addr < 0 || addr > 3) {
        printf("Target %sregister %u does not exist.\n", input[0]=='s'?"special ":"", addr);
        continue;
      }
      BYTE_T value = read_register(addr, input[0]=='s', cpu);
      printf("%sRegister %u: 0x%.2x\n", input[0]=='s'?"Special ":"", addr, value);
    } else if (input[0] == 'm' && input[1] == 'r') {
      printf("Memory Read\n");
      unsigned int addr;
      scanf("%u", &addr);
      if(addr < 0 || addr > 255) {
        printf("Address 0x%.2x does not exist.\n", addr);
        continue;
      }
      BYTE_T value = read_ram(addr, cpu);
      printf("Address 0x%.2x: 0x%.2x\n", addr, value);
    } else if (input[0] == 'm' && input[1] == 'w') {
      printf("Memory Write\n");
    } else if (input[0] == 's') {
      printf("Step\n");
      step(cpu);
    } else if (input[0] == 'q') {
      printf("Goodbye.\n");
      beardmachine_teardown(cpu);
      return 0;
    } else {
      printf("Unknown command.\n");
    }
  }
}


// Register (r #)
// Special Register (sr #)
// Memory Read (mr #ADDR#)
// Memory Write (mw #ADDR# #VALUE#)
// Step (s)
// Quit (q)
