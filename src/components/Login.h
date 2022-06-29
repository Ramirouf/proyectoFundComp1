#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Login(){
  int isLogin;
  struct User user;

  // init 
  isLogin = 0;

  do{
    printf("\n\nINICIAR SESION\n\n");

    printf("Ingrese el usuario: ");
    fflush(stdin);
    gets(user.username);
    printf("Ingrese la contrasena: ");
    fflush(stdin);
    gets(user.password);

    struct ListUsers *pUser = pListUsers;

    while (pUser != NULL){
      if (strcmp(user.username, Descrypt(pUser->user.username)) == 0 && strcmp(user.password, Descrypt(pUser->user.password)) == 0){
        isLogin = 1;
        SetSession(pUser->user);
        break;
      }
      pUser = pUser->next;
    }
    if (isLogin == 0){
      printf("Usuario o contrasena incorrectos\n");
    }
  } while (isLogin == 0);


}