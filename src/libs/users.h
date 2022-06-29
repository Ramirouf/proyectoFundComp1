#include <stdio.h>
#include <stdlib.h>


void AddUser(char *infoUser){
  struct ListUsers *newUser;
  newUser = malloc(sizeof(struct ListUsers));

  sscanf(infoUser, "%[^,],%[^,],%[^,]", newUser->user.name, newUser->user.username, newUser->user.password);

  // Agregar a la lista de usuarios
  if (pListUsers == NULL){
    pListUsers = newUser;
    newUser->next = NULL;
  } else{
    newUser->next = pListUsers;
    pListUsers = newUser;
  }
}

void SetListUsers(){
  FILE *fp;
  char *line = NULL;
  size_t len = 0;
  size_t read;

  char *filename = "./public/users.txt";
  char *mode = "r";
  fp = fopen(filename, mode);
  if (fp == NULL) exit(EXIT_FAILURE);

  while ((read = getline(&line, &len, fp)) != -1){
    AddUser(line);
  }

  free(line);
  fclose(fp);
}


void InitialConfigUser(){
  pListUsers = (struct ListUsers *)malloc(sizeof(struct ListUsers));

  pListUsers->next = NULL;

  printf("BIENVENIDO AL SISTEMA DE TICKETS\n");
  printf("Primero debe crear un usuario\n");

  printf("Ingrese su nombre: ");
  fflush(stdin);
  gets(pListUsers->user.name);
  printf("Ingrese un usuario: ");
  fflush(stdin);
  gets(pListUsers->user.username);
  printf("Ingrese una contrasena: ");
  fflush(stdin);
  gets(pListUsers->user.password);

  // Guardar la lista de usuarios en el archivo
  FILE *fp;

  char *filename = "./public/users.txt";
  char *mode = "w";
  fp = fopen(filename, mode);
  if (fp == NULL) exit(EXIT_FAILURE);

  fprintf(fp, "%s,%s,%s,%d\n", Encrypt(pListUsers->user.name), Encrypt(pListUsers->user.username), Encrypt(pListUsers->user.password));

  fclose(fp);

  printf("\nUSUARIO CREADO CON EXITO\n");
  printf("Ahora debe iniciar sesion\n");

  SetListUsers();
}
