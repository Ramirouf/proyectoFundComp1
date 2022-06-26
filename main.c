#include <stdio.h>
#include <stdlib.h>
#include "./libs/Init.h" // Los struct del programa
#include "./libs/Products.h"
#include "./libs/utilities.h"
#include "./libs/momentC.h"

#include "./libs/methods-item-ticket.h"
#include "./libs/methods-ticket.h"
#include "./libs/methods-tree.h"

// Testing
#include<conio.h>
// Testing




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
				// Vuelve al menu principal
				break;
			default:
				printf("Opcion no valida\n");
		}
	} while (option != 4);

}

void GenerateTicket(){
	// Pasos para generar un ticket
	// 1. Elegir un item del menu (se muestra el nombre y el precio)
	// 2. Elegir la cantidad de items
	// 3. Agregar el item a la lista de items
	/*
		4. Una vez que se termina de agregar todos los items, se muestra todos los items, se muestra el total,
		se puede modificar y/o eliminar items, se puede agregar nuevos items.
	*/
	// 5. Se guarda la lista de items en un archivo
	// 6. Se imprime el ticket

	// Implementacion
	// 1. Elegir un item del menu (se muestra el nombre y el precio)


	//TESTING
	printf("AGREGANDO TICKET...\n");
	InsertTicket();
	printf("TICKET AGREGADO\n");
	// TESTING
}

void ViewAllTickets(){
	// Imprimir direccion de memoria de todos los tickets
	printf("TODOS LOS TICKETS\n");
	PrintTicketTreePre(pTicketTree);
	printf("\nFin.\n");
}

void MenuSystem(){
	int option;

	do{
		MenuTitle("MENU PRINCIPAL");
		printf("1) Generar un Ticket\n");
		printf("2) Validar un Ticket (dont work)\n");
		printf("3) Ver un Ticket (dont work)\n");
		printf("4) Ver todos los Tickets\n");

		printf("\n");

		MenuTitle("MENU SYSTEM");
		printf("5) Configuracion de cuenta\n");
		printf("6) Configuracion del ticket \n"); // Mostrar como se ve el ticket y preguntar que quiere cambiar
		printf("7) Cerrar sesion (dont work)\n");
		printf("8) Salir\n");

		printf("\n");

		printf("Ingrese una opcion: ");
		scanf("%d", &option);

		switch (option){
			case 1:
				printf("\n\n");
				GenerateTicket();
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
				ViewAllTickets();
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

void PrintManyTimes(char *string, int times){
	int i;
	for (i = 0; i < times; i++){
		printf("%s", string);
	}
}

void PrintItemTable(char *nameProduct, int widthColumn){
	int TEXT_WIDTH = widthColumn - 1; // -1 para el espacio entre el limite del nombre y el final de la columna

	/*
		Ejemplos

		Hola, buenas cómo... | // Esto pasa si la longitud del string es mayor a TEXT_WIDTH
		Hola, buenas!        | // Esto pasa si la longitud del string es manor a TEXT_WITDH
		Hola, buenas buenas! | // Esto pasa si la longitud del string es igual a TEXT_WIDTH
	*/

	int lengthText = strlen(nameProduct);
	for (int i = 0; i < widthColumn; i++){
		if ((lengthText > TEXT_WIDTH) && (i >= (TEXT_WIDTH - 3))){
			if (i == TEXT_WIDTH) printf(" ");
			else printf(".");
		} else{
			if (i < lengthText){
				printf("%c", nameProduct[i]);
			} else{
				printf(" ");
			}
		}
	}
}

char *DoubleToString(double number){
	char *string = malloc(sizeof(char) * 10);
	sprintf(string, "%.2lf", number);
	return string;
}

void PrintListProductTicket(){
	int PRODUCT_COLUMN_WIDTH = 30 + 1;
	int QUANTITY_COLUMN_WIDTH = 10 + 1;
	int PRICE_COLUMN_WIDTH = 10;
	int TOTAL_COLUMN_WIDTH = PRICE_COLUMN_WIDTH + QUANTITY_COLUMN_WIDTH + PRODUCT_COLUMN_WIDTH;

	struct ListProducts *pAuxListProducts = pListProducts;


	// Header
	PrintManyTimes("*", TOTAL_COLUMN_WIDTH);

	printf("\n");

	PrintItemTable("Producto", PRODUCT_COLUMN_WIDTH);
	PrintItemTable("Cantidad", QUANTITY_COLUMN_WIDTH);
	PrintItemTable("Precio U.", PRICE_COLUMN_WIDTH);

	// Productos
	while (pAuxListProducts != NULL){
		printf("\n");
		PrintItemTable(pAuxListProducts->itemInfo.name, PRODUCT_COLUMN_WIDTH);
		PrintItemTable(DoubleToString(pAuxListProducts->itemInfo.price), QUANTITY_COLUMN_WIDTH);
		PrintItemTable(DoubleToString(pAuxListProducts->itemInfo.price), QUANTITY_COLUMN_WIDTH);
		pAuxListProducts = pAuxListProducts->next;
	}


	printf("\n");
}

int main(){

	MenuSystem();

	// SetListProducts();
	// PrintListProductTicket();



	return 0;
}
