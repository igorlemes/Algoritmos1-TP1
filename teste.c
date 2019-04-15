#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  FILE *filePointer;
  filePointer = fopen(argv[1], "r");
  int number[5];
  for (size_t i = 0; i < 5; i++) {
    fscanf(filePointer, "%d", &number[i]);
  }
  for (size_t i = 0; i < 5; i++) {
    printf("%d\n", number[i]);
  }
  return 0;
}
