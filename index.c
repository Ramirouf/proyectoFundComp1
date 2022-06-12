#include <stdio.h>

#define CONFIG_TICKET_NAME_LENGTH 20
#define CONFIG_TICKET_ADDRESS_LENGTH 50
#define CONFIG_TICKET_PHONE_LENGTH 20
#define CONFIG_TICKET_CP_LENGTH 50
#define CONFIG_TICKET_CUIT_LENGTH 11
#define CONFIG_TICKET_GB_LENGTH 20

#define ITEM_INFO_NAME_LENGTH 20
#define ITEM_INFO_UNIT_LENGTH 10

#define TICKET_ID_LENGTH 10
#define TICKET_DATE_LENGTH 8
#define TICKET_TIME_LENGTH 6
#define TICKER_RES_IVA_LENGTH 50
#define TICKET_LEYENDA_LENGTH 50

struct ConfigTicket{
  char businessName[CONFIG_TICKET_NAME_LENGTH];
  char address[CONFIG_TICKET_ADDRESS_LENGTH];
  char phone[CONFIG_TICKET_PHONE_LENGTH];
  char postalCode[CONFIG_TICKET_CP_LENGTH];
  char cuit[CONFIG_TICKET_CUIT_LENGTH];
  char messageGB[CONFIG_TICKET_GB_LENGTH];
};

// struct Item{
//   char name[ITEM_INFO_NAME_LENGTH];
//   char unit[ITEM_INFO_UNIT_LENGTH];
//   float price;
// };

// struct ItemTicket{
//   struct Item itemInfo;
//   int quantity;
//   char id[TICKET_ID_LENGTH];
// };

// struct Ticket{
//   char id[TICKET_ID_LENGTH];
//   char date[TICKET_DATE_LENGTH];
//   char time[TICKET_TIME_LENGTH];
//   char resIVA[TICKER_RES_IVA_LENGTH];
//   char leyenda[TICKET_LEYENDA_LENGTH];
//   struct ConfigTicket configT;
// };

void SeparateLine(){
  printf("----------------------------------------\n");
}

void PrintMessageError(char *message, char *type){
  printf("\n");
  SeparateLine();
  printf("%s: %s\n", type, message);
  SeparateLine();
  printf("\n");
}

void MenuTitle(char *title){
  // https://misc.flogisoft.com/bash/tip_colors_and_formatting
  printf("\e[34m\e[1m%s\e[0m\e[0m\n", title);
}

void TicketSettings(){
  int option;

  do{
    MenuTitle("CONFIGURACIÓN DE TICKET \e[3m(diseño)\e[0m");
    printf("1) Ver configuración\n");
    printf("2) Cambiar configuración\n");
    printf("3) Volver atras\n");

    printf("Ingrese una opción: ");
    scanf("%d", &option);

    switch (option){
      case 1:
        printf("GET T \n");
        GetConfigTicket();
        break;
      case 2:
        printf("SET T \n");
        SetConfigTicket();
        break;
      case 3:
        // Vuelve al menú principal
        break;
      default:
        printf("Opción no válida\n");
    }
  } while (option != 3);

}

void MenuSystem(){
  int option;

  do{
    MenuTitle("MENU PRINCIPAL");
    printf("1) Generar un Ticket\n");
    printf("2) Validar un Ticket\n");
    printf("3) Ver un Ticket\n");
    printf("4) Ver todos los Tickets\n");

    printf("\n");

    MenuTitle("MENU SYSTEM");
    printf("5) Configuración de cuenta\n");
    printf("6) Configuración del ticket \n"); // Mostrar cómo se ve el ticket y preguntar que quiere cambiar
    printf("7) Cerrar sesión\n");
    printf("8) Salir\n");

    printf("\n");

    printf("Ingrese una opción: ");
    scanf("%d", &option);

    switch (option){
      case 1:
        // GenerateTicket ();
        break;
      case 2:
        // ValidateTicket ();
        break;
      case 3:
        // ViewTicket ();
        break;
      case 4:
        // ViewAllTickets ();
        break;
      case 5:
        // AccountSettings ();
        break;
      case 6:
        printf("\n\n");
        TicketSettings();
        break;
      case 7:
        // Logout ();
        break;
      case 8:
        // Exit ();
        break;
      default:
        PrintMessageError("Opción inválida", "Error");
    }
  } while (option != 8);
}



void GetConfigTicket(){
  struct ConfigTicket config;
  // FILE *fptr; // File pointer
  // char *filename = "../public/ticket_config.txt"; // File name
  // char *mode = "r"; // File mode - https://www.tutorialesprogramacionya.com/cya/detalleconcepto.php?punto=80&codigo=80&inicio=75


  // fptr = fopen(filename, mode); // Open the file

  // // Program exits if the file pointer returns NULL.
  // if (fptr == NULL){
  //   printf("Error! opening file");
  //   exit(1);
  // }

  // fread(&config, sizeof(config), 1, fptr);

  printf("Enter your business name: ");
  fflush(stdin);
  gets(config.businessName);


  printf("Enter address: ");
  fflush(stdin);
  gets(config.address);

  printf("Enter phone: ");
  fflush(stdin);
  gets(config.phone);

  printf("Enter postal code: ");
  fflush(stdin);
  gets(config.postalCode);

  printf("Enter CUIT: ");
  fflush(stdin);
  gets(config.cuit);

  printf("Enter message of thanks: ");
  fflush(stdin);
  gets(config.messageGB);

  // Print the text from the file.
  printf("here is the content of the file:\n");
  printf("%s\n", config.businessName ? config.businessName : "No hay nombre de empresa");
  printf("%s\n", config.address ? config.address : "No hay dirección");
  printf("%s\n", config.phone ? config.phone : "No hay teléfono");
  printf("%s\n", config.postalCode ? config.postalCode : "No hay código postal");
  printf("%s\n", config.cuit ? config.cuit : "No hay CUIT");
  printf("%s\n", config.messageGB ? config.messageGB : "No hay mensaje de gracias");

  // fclose(fptr);

}

void SetConfigTicket(){
  struct ConfigTicket config, config_new;

  // FILE *fptr;

  // fptr = fopen("./public/ticket_config.txt", "a+t");

  // // fflush(stdin);
  // // printf("Enter business name: Carlos Ayala ");
  // // gets(config.businessName);

  printf("Enter address: ");
  fflush(stdin);
  gets(config.address);

  printf("Enter phone: ");
  fflush(stdin);
  gets(config.phone);

  printf("Enter postal code: ");
  fflush(stdin);
  gets(config.postalCode);

  printf("Enter CUIT: ");
  fflush(stdin);
  gets(config.cuit);

  printf("Enter message of thanks: ");
  fflush(stdin);
  gets(config.messageGB);

  // fwrite(&config, sizeof(config), 1, fptr);

  // if (fwrite != 0) printf("Contents to file written successfully !\n");
  // else printf("Error writing file !\n");

  // fclose(fptr);
}




int main(){


  MenuSystem();

  return 0;
}