#include <stdio.h> 
#include <time.h>
#include <stdint.h> 


char *getDate(){
  char *date = (char *)malloc(sizeof(char) * 11);

  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  // Se suman 1900 porque este valor es el año actual - 1900
  // Se suman 1 porque los valores de meses empiezan en 0 (enero) al 11 (diciembre)
  sprintf(date, "%02d-%02d-%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

  return date;
}

char *getTime(){
  char *dateTime = (char *)malloc(sizeof(char) * 9);

  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  sprintf(dateTime, "%02d:%02d:%02d", tm.tm_hour, tm.tm_min, tm.tm_sec);

  return dateTime;
}
