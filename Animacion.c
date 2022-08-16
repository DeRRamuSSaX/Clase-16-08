#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  while (1) {
    printf("Espera...\n");
    unsleep(1000000/24.0);
    printf("Listo\n");
    
  }
  return 0;
}
