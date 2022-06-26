#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main(void){
  FILE *fp;
  char *line = NULL;
  size_t len = 0;
  size_t read;

  fp = fopen("testing.txt", "r");
  if (fp == NULL)
    exit(EXIT_FAILURE);

  while ((read = getline(&line, &len, fp)) != -1){
    printf("%s", line);

  }

  free(line);
  exit(EXIT_SUCCESS);
}