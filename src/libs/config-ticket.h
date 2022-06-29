#include <stdio.h>
#include <stdlib.h>

// Definir responsabilidad ante el IVA del emisor del ticket
char *IVAResponsability()
{
  int option;
  char *responsability[] = {
      "IVA Responsable Inscripto", "IVA no Responsable", "IVA exento", "Responsable Monotributo", "Monotributista Social"};

  do
  {
    printf("\tResponsabilidad frente al impuesto al valor agregado del emisor segun corresponda:\n");
    printf("\t1. IVA Responsable Inscripto\n");
    printf("\t2. IVA no Responsable\n");
    printf("\t3. IVA exento\n");
    printf("\t4. Responsable Monotributo\n");
    printf("\t5. Monotributista Social\n");

    printf("\tIngrese una opcion: ");
    scanf("%d", &option);

    if (option < 1 || option > 5)
    {
      PrintMessage("Opcion invalida", "Error");
    }
  } while (option < 1 || option > 5);

  return responsability[option - 1];
}

void SetConfigTicket()
{
  char *filename = "./public/ticket_config.txt";
  char *mode = "w";

  struct ConfigTicket configT;

  FILE *fptr;
  fptr = fopen(filename, mode);

  printf("\n\n\t\tESTABLECIENDO LA CONFIGURACION DEL TICKET\n\n");

  printf("\tIngrese la razon social: ");
  fflush(stdin);
  gets(configT.businessName);

  printf("\tIngrese la direccion: ");
  fflush(stdin);
  gets(configT.address);

  printf("\tIngrese el telefono: ");
  fflush(stdin);
  gets(configT.phone);

  printf("\tIngrese el codigo postal: ");
  fflush(stdin);
  gets(configT.postalCode);

  printf("\tIngrese el CUIT: ");
  fflush(stdin);
  gets(configT.cuit);

  sprintf(configT.resIVA, "%s", IVAResponsability());

  printf("\tIngrese el mensaje de Leyenda(mensaje al final del Ticket): ");
  fflush(stdin);
  gets(configT.messageGB);

  fprintf(fptr, "%s,", configT.businessName);
  fprintf(fptr, "%s,", configT.address);
  fprintf(fptr, "%s,", configT.phone);
  fprintf(fptr, "%s,", configT.postalCode);
  fprintf(fptr, "%s,", configT.cuit);
  fprintf(fptr, "%s,", configT.resIVA);
  fprintf(fptr, "%s", configT.messageGB);

  printf("\n\t\tTICKET CONFIGURADO CORRECTAMENTE\n\n");

  fclose(fptr);
}

struct ConfigTicket *GetConfigTicket()
{
  struct ConfigTicket *config = malloc(sizeof(struct ConfigTicket));
  FILE *fptr;
  char *filename = "./public/ticket_config.txt";
  char *mode = "r";
  char *line = NULL;
  size_t len = 0;

  fptr = fopen(filename, mode);
  if (fptr == NULL)
    exit(EXIT_FAILURE);

  getline(&line, &len, fptr);
  // %[^,] -> Lee hasta que encuentre una coma
  sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,]", config->businessName, config->address, config->phone, config->postalCode, config->cuit, config->resIVA, config->messageGB);

  free(line);
  fclose(fptr);

  return config;
}

void PrintConfigTicket()
{
  struct ConfigTicket *configT = GetConfigTicket();

  // Print the text from the file.
  printf("\tCONFIGURACION DEL TICKET\n\n");
  printf("\t- Nombre de la empresa: %s\n", configT->businessName);
  printf("\t- Direccion: %s\n", configT->address);
  printf("\t- Telefono: %s\n", configT->phone);
  printf("\t- Codigo Postal: %s\n", configT->postalCode);
  printf("\t- CUIT: %s\n", configT->cuit);
  printf("\t- Responsabilidad IVA: %s\n", configT->resIVA);
  printf("\t- Mensaje de Gracias: %s\n", configT->messageGB);
  printf("\n\n");
  free(configT);

  system("pause");
  system("cls");
}