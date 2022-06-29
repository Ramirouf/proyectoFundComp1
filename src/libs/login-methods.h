#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SetSession(struct User user){
  pSessionUser = (struct User *)malloc(sizeof(struct User));
  sprintf(pSessionUser->name, "%s", Descrypt(user.name));
  sprintf(pSessionUser->username, "%s", Descrypt(user.username));
  sprintf(pSessionUser->password, "%s", Descrypt(user.password));
}

void WelcomeUser(){
  printf("Bienvenido %s\n", pSessionUser->name);
}

void DeleteSession(){
  free(pSessionUser);
  pSessionUser = NULL;
}

void LogOut(){
  DeleteSession();
  printf("\nSesion cerrada\n");
}