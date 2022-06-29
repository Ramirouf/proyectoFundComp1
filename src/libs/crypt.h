#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *Encrypt(char *str){
  int numAscii;
  char ch;

  char *hash = (char *)malloc(sizeof(char) * (strlen(str) + 1));
  int i = 0;
  while (str[i] != '\0'){
    ch = str[i];
    numAscii = (int)ch;
    hash[i] = numAscii + 3;
    i++;
  }

  hash[i] = '\0';
  return hash;
}

int CompareHash(char *str1, char *str2){
  int i = 0;
  while (str1[i] != '\0'){
    if (str1[i] != str2[i]){
      return 0;
    }
    i++;
  }
  return 1;
}

char *Descrypt(char *str){
  int numAscii;
  char ch;

  char *descrypt = (char *)malloc(sizeof(char) * (strlen(str) + 1));
  int i = 0;
  while (str[i] != '\0'){
    ch = str[i];
    numAscii = (int)ch;
    descrypt[i] = numAscii - 3;
    i++;
  }

  descrypt[i] = '\0';
  return descrypt;
}