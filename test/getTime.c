// #include <stdio.h> 
// #include <time.h> 
// #include <stdint.h> 

// // Get Date and Time into char array

// void getDate(char *dateTime){
//   time_t t = time(NULL);
//   struct tm tm = *localtime(&t);
//   sprintf(dateTime, "%d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
// }

// void getTime(char *pTime){
//   time_t t = time(NULL);
//   struct tm tm = *localtime(&t);
//   sprintf(pTime, "%02d:%02d:%02d", tm.tm_hour, tm.tm_min, tm.tm_sec);
// }



// int main(){

//   // char dateTime[20];
//   // char time[20];

//   // getDate(dateTime);
//   // getTime(time);

//   // printf("%s %s\n", dateTime, time);




//   return 0;
// }

#include <stdio.h> 
#include <time.h> 
#include <stdint.h> 

int  main(void){
  time_t  result = time(NULL);
  struct tm *t = localtime(&result);

  printf("%d-%02d-%02d %02d:%02d:%02d\n", t->tm_mday, t->tm_mon + 1, t->tm_year + 1900, t->tm_hour, t->tm_min, t->tm_sec);

}