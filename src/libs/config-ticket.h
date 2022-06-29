#include <stdio.h>
#include <stdlib.h>

// Definir responsabilidad ante el IVA del emisor del ticket
char *IVAResponsability(){
  int option;
  char *responsability[] = {
    "IVA Responsable Inscripto", "IVA no Responsable", "IVA exento", "Responsable Monotributo", "Monotributista Social"
  };

  do{
    printf("Responsabilidad frente al impuesto al valor agregado del emisor segun corresponda:\n");
    printf("1. IVA Responsable Inscripto\n");
    printf("2. IVA no Responsable\n");
    printf("3. IVA exento\n");
    printf("4. Responsable Monotributo\n");
    printf("5. Monotributista Social\n");

    printf("Ingrese una opcion: ");
    scanf("%d", &option);

    if (option < 1 || option > 5){
      PrintMessage("Opcion invalida", "Error");
    }
  } while (option < 1 || option > 5);

  return responsability[option - 1];
}

void SetConfigTicket(){
  char *filename = "./public/ticket_config.txt";
  char *mode = "w";

  pConfigTicket = (struct ConfigTicket *)malloc(sizeof(struct ConfigTicket));

  FILE *fptr;
  fptr = fopen(filename, mode);

  printf("\n\nESTABLECIENDO LA CONFIGURACION DEL TICKET\n\n");

  printf("Ingrese la razon social: ");
  fflush(stdin);
  gets(pConfigTicket->businessName);

  printf("Ingrese la direccion: ");
  fflush(stdin);
  gets(pConfigTicket->address);

  printf("Ingrese el telefono: ");
  fflush(stdin);
  gets(pConfigTicket->phone);

  printf("Ingrese el codigo postal: ");
  fflush(stdin);
  gets(pConfigTicket->postalCode);

  printf("Ingrese el CUIT: ");
  fflush(stdin);
  gets(pConfigTicket->cuit);

  sprintf(pConfigTicket->resIVA, "%s", IVAResponsability());

  printf("Ingrese el mensaje de Leyenda(mensaje al final del Ticket): ");
  fflush(stdin);
  gets(pConfigTicket->messageGB);

  fprintf(fptr, "%s", pConfigTicket->businessName);
  fprintf(fptr, "%s", pConfigTicket->address);
  fprintf(fptr, "%s", pConfigTicket->phone);
  fprintf(fptr, "%s", pConfigTicket->postalCode);
  fprintf(fptr, "%s", pConfigTicket->cuit);
  fprintf(fptr, "%s", pConfigTicket->resIVA);
  fprintf(fptr, "%s", pConfigTicket->messageGB);

  printf("\nTICKET CONFIGURADO CORRECTAMENTE\n\n");

  fclose(fptr);
}

struct ConfigTicket *GetConfigTicket(){
  struct ConfigTicket *config = malloc(sizeof(struct ConfigTicket));
  FILE *fptr;
  char *filename = "./public/ticket_config.txt";
  char *mode = "r";
  char *line = NULL;
  size_t len = 0;
  size_t read;

  fptr = fopen(filename, mode);
  if (fptr == NULL)	exit(EXIT_FAILURE);

  read = getline(&line, &len, fptr);
  sprintf(config->businessName, "%s", line);
  read = getline(&line, &len, fptr);
  sprintf(config->address, "%s", line);
  read = getline(&line, &len, fptr);
  sprintf(config->phone, "%s", line);
  read = getline(&line, &len, fptr);
  sprintf(config->postalCode, "%s", line);
  read = getline(&line, &len, fptr);
  sprintf(config->cuit, "%s", line);
  read = getline(&line, &len, fptr);
  sprintf(config->resIVA, "%s", line);
  read = getline(&line, &len, fptr);
  sprintf(config->messageGB, "%s", line);

  free(line);
  fclose(fptr);

  return config;
}

void PrintConfigTicket(){
  // struct ConfigTicket *configT = GetConfigTicket();

  // Print the text from the file.
  printf("INFORMACION DEL TICKET\n\n");
  printf("- Nombre de la empresa: %s\n", pConfigTicket->businessName);
  printf("- Direccion: %s\n", pConfigTicket->address);
  printf("- Telefono: %s\n", pConfigTicket->phone);
  printf("- Codigo Postal: %s\n", pConfigTicket->postalCode);
  printf("- CUIT: %s\n", pConfigTicket->cuit);
  printf("- Responsabilidad IVA: %s\n", pConfigTicket->resIVA);
  printf("- Mensaje de Gracias: %s\n", pConfigTicket->messageGB);
  printf("\n");
}