#include <stdio.h>
#include <stdlib.h>
#include "../libs/dataTypes.h"
#include "MenuTitle.h"


// void GetConfigTicket(){
//   struct ConfigTicket config;
//   FILE *fptr; // File pointer
//   char *filename = "../public/ticket_config.txt"; // File name
//   char *mode = "r"; // File mode - https://www.tutorialesprogramacionya.com/cya/detalleconcepto.php?punto=80&codigo=80&inicio=75


//   fptr = fopen(filename, mode); // Open the file

//   // Program exits if the file pointer returns NULL.
//   if (fptr == NULL){
//     printf("Error! opening file");
//     exit(1);
//   }

//   fread(&config, sizeof(struct ConfigTicket), 1, fptr);

//   // Print the text from the file.
//   printf("here is the content of the file:\n");
//   printf("%s\n", config.businessName ? config.businessName : "No hay nombre de empresa");
//   printf("%s\n", config.address ? config.address : "No hay dirección");
//   printf("%s\n", config.phone ? config.phone : "No hay teléfono");
//   printf("%s\n", config.postalCode ? config.postalCode : "No hay código postal");
//   printf("%s\n", config.cuit ? config.cuit : "No hay CUIT");
//   printf("%s\n", config.messageGB ? config.messageGB : "No hay mensaje de gracias");

//   fclose(fptr);

// }

void SetConfigTicket(){
  struct ConfigTicket config;
  struct ConfigTicket config_new;

  FILE *fptr;

  fptr = fopen("../public/ticket_config.txt", "wb");

  fflush(stdin);
  printf("Enter business name: ");
  gets(config.businessName);

  fflush(stdin);
  printf("Enter address: ");
  gets(config.address);

  fflush(stdin);
  printf("Enter phone: ");
  gets(config.phone);

  fflush(stdin);
  printf("Enter postal code: ");
  gets(config.postalCode);

  fflush(stdin);
  printf("Enter CUIT: ");
  gets(config.cuit);

  fflush(stdin);
  printf("Enter message of thanks: ");
  gets(config.messageGB);


  fwrite(config, sizeof(config), 1, fptr);
  fclose(fptr);

  fptr = fopen("../public/ticket_config.txt", "rb");
  fread(config_new, sizeof(config_new), 1, fptr);
  // // #include "MenuTitle.h"
  .address ? config.address : "No hay dirección");
  printf("%s\n", config.phone ? config.phone : "No hay teléfono");
  printf("%s\n", config.postalCode ? config.postalCode : "No hay código postal");
  printf("%s\n", config.cuit ? config.cuit : "No hay CUIT");
  printf("%s\n", config.messageGB ? config.messageGB : "No hay mensaje de gracias");

  fclose(fptr);
}


void TicketSettings(){
  int option;

  do{
    MenuTitle("CONFIGURACIÓN DE TICKET \e[3m(diseño)\e[0m");
    printf("1) Ver configuración\n");
    printf("2) Cambiar configuración\n");
    printf("3) Volver atras\n");

    printf("Ingrese una opción: ");
    fflush(stdin);
    scanf("%d", &option);

    switch (option){
      case 1:
        // GetConfigTicket();
        printf("GET T \n");
        break;
      case 2:
        SetConfigTicket();
        printf("SET T \n");
        break;
      case 3:
        // Vuelve al menú principal
        break;
      default:
        printf("Opción no válida\n");
    }
  } while (option != 3);

}