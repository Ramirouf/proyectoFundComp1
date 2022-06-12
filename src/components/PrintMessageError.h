#include <stdio.h>
#include <stdlib.h>
#include "SeparateLine.h"

void PrintMessageError(char *message, char *type) {
  printf("\n");
  SeparateLine();
  printf("%s: %s\n", type, message);
  SeparateLine();
  printf("\n");
}