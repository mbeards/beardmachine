#include<stdio.h>

#include "beard_cpu.h"

int main(int argc, char** argv) {
  printf("Beardmachine test\n");

  char input[128];

  while(true) {
    printf("> ");
    scanf("%s", input);

    if(input[0] == 'r') {
      printf("Register Read\n");
    } else if (input[0] == 's' && input[1] == 'r') {
      printf("Special Register Read\n");
    } else if (input[0] == 'm' && input[1] == 'r') {
      printf("Memory Read\n");
    } else if (input[0] == 'm' && input[1] == 'w') {
      printf("Memory Write\n");
    } else if (input[0] == 's') {
      printf("Step\n");
    } else if (input[0] == 'q') {
      printf("Goodbye.\n");
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
