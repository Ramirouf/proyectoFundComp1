#include <stdio.h>
#include <stdlib.h>

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

void SeparateCross(int cant){
	for (int i = 1; i < cant; i++) printf("*");
	printf("\n");
}

void SeparateLine(int cant){
	if (cant == 0) cant = 25;

	for (int i = 1; i < cant; i++) printf("-");
	printf("\n");
}

void PrintMessageError(char *message, char *type){
	printf("\n");
	SeparateLine(0);
	printf("%s: %s\n", type, message);
	SeparateLine(0);
	printf("\n");
}

void MenuTitle(char *title){
	// https://misc.flogisoft.com/bash/tip_colors_and_formatting
	printf("%s\n", title);
}

void PrintInTheMiddle(char *message, int cant){

}

struct ConfigTicket GetConfigTicket(char *mode){
	// File mode - https://www.tutorialesprogramacionya.com/cya/detalleconcepto.php?punto=80&codigo=80&inicio=75
	struct ConfigTicket config;
	FILE *fptr; // File pointer
	char *filename = "./public/ticket_config.txt";

	fptr = fopen(filename, mode); // Open the file

	// Program exits if the file pointer returns NULL.
	if (fptr == NULL){
		printf("Error! opening file");
		exit(1);
	}

	fread(&config, sizeof(config), 1, fptr);

	fclose(fptr);

	return config;
}

void PreviewTicket(){
	// Ticket data
	struct ConfigTicket configT;
	char *mode = "r";
	configT = GetConfigTicket(mode);
	// Ticket Dimension
	int WIDTH_TICKET = 50;

	MenuTitle("Preview Ticket");
	// Line Top 
	SeparateLine(WIDTH_TICKET);

	// Print Text in the middle
	PrintInTheMiddle(configT.businessName, WIDTH_TICKET);


	SeparateCross(WIDTH_TICKET);
	SeparateCross(WIDTH_TICKET);

	// Line Bottom 
	SeparateLine(WIDTH_TICKET);

}

void PrintConfigTicket(){
	char *mode = "at";
	struct ConfigTicket config;
	config = GetConfigTicket(mode);

	// Print the text from the file.
	printf("INFORMACION DEL TICKET\n");
	printf("- Razon Social: %s\n", config.businessName);
	printf("- Direccion: %s\n", config.address);
	printf("- Telefono: %s\n", config.phone);
	printf("- Codigo Postal: %s\n", config.postalCode);
	printf("- CUIT: %s\n", config.cuit);
	printf("- Leyenda: %s\n", config.messageGB);
}

void SetConfigTicket(){
	struct ConfigTicket config;

	FILE *fptr;
	fptr = fopen("./public/ticket_config.txt", "a+t");

	fflush(stdin);
	printf("Enter business name: ");
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

	fwrite(&config, sizeof(config), 1, fptr);

	fclose(fptr);
}


void TicketSettings(){
	int option;

	do{
		MenuTitle("CONFIGURACION DE TICKET");
		printf("1) Ver informacion\n");
		printf("2) Cambiar informacion\n");
		printf("3) Preview Ticket\n");
		printf("4) Volver atras\n");

		printf("\n");

		printf("Ingrese una opcion: ");
		scanf("%d", &option);

		switch (option){
			case 1:
				printf("\n");
				PrintConfigTicket();
				printf("\n\n");
				break;
			case 2:
				printf("\n");
				SetConfigTicket();
				printf("\n\n");
				break;
			case 3:
				printf("\n");
				PreviewTicket();
				printf("\n\n");
				break;
			case 4:
				// Vuelve al men� principal
				break;
			default:
				printf("Opcion no valida\n");
		}
	} while (option != 4);

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
		printf("5) Configuracion de cuenta\n");
		printf("6) Configuracion del ticket \n"); // Mostrar c�mo se ve el ticket y preguntar que quiere cambiar
		printf("7) Cerrar sesion\n");
		printf("8) Salir\n");

		printf("\n");

		printf("Ingrese una opcion: ");
		scanf("%d", &option);

		switch (option){
			case 1:
				printf("\n\n");
				// GenerateTicket ();
				printf("\n\n");
				break;
			case 2:
				printf("\n\n");
				// ValidateTicket ();
				printf("\n\n");
				break;
			case 3:
				printf("\n\n");
				// ViewTicket ();
				printf("\n\n");
				break;
			case 4:
				printf("\n\n");
				// ViewAllTickets ();
				printf("\n\n");
				break;
			case 5:
				printf("\n\n");
				// AccountSettings ();
				printf("\n\n");
				break;
			case 6:
				printf("\n\n");
				TicketSettings();
				printf("\n\n");
				break;
			case 7:
				printf("\n\n");
				// Logout ();
				printf("\n\n");
				break;
			case 8:
				printf("\n\n");
				// Exit ();
				printf("\n\n");
				break;
			default:
				PrintMessageError("Opcion invalida", "Error");
		}
	} while (option != 8);
}


int main(int argc, char *argv[]){

	MenuSystem();

	return 0;
}

