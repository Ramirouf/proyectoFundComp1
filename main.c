#include <stdio.h>
#include <stdlib.h>
#include "src/libs/Init.h" // Los struct del programa
#include "src/libs/utilities.h"
#include "src/libs/Products.h"
#include "src/libs/momentC.h"

#include "src/libs/methods-item-ticket.h"
#include "src/libs/methods-ticket.h"
#include "src/libs/method-tree.h"

// Testing
#include <conio.h>
// Testing

struct ConfigTicket *GetConfigTicket(){
	struct ConfigTicket *config = malloc(sizeof(struct ConfigTicket));
	FILE *fptr;
	char *filename = "./public/ticket_config.txt";
	char *mode = "r";
	char *line = NULL;
	size_t len = 0;
	size_t read;

	fptr = fopen(filename, mode);
	if (fptr == NULL)
		exit(EXIT_FAILURE);

	// while ((read = getline(&line, &len, fptr)) != -1){
	// 	printf("%s", line);
	// }

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

void PreviewTicket(){
	// char *mode = "r";
	// // Ticket data
	// struct ConfigTicket *configT = GetConfigTicket(mode);
}

void PrintConfigTicket(){
	// struct ConfigTicket *configT = GetConfigTicket();

	// Print the text from the file.
	printf("INFORMACION DEL TICKET\n\n");
	printf("Nombre de la empresa: %s", pConfigTicket->businessName);
	printf("Direccion: %s", pConfigTicket->address);
	printf("Telefono: %s", pConfigTicket->phone);
	printf("Codigo Postal: %s", pConfigTicket->postalCode);
	printf("CUIT: %s", pConfigTicket->cuit);
	printf("Responsabilidad IVA: %s", pConfigTicket->resIVA);
	printf("Mensaje de Gracias: %s", pConfigTicket->messageGB);
	printf("\n");
}

void SetConfigTicket(){
	char *filename = "./public/ticket_config.txt";
	char *mode = "w";

	pConfigTicket = (struct Ticket *)malloc(sizeof(struct Ticket));

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

void TicketSettings(){
	int option;

	do{
		MenuTitle("CONFIGURACION DE TICKET");
		printf("1) Ver informacion\n");
		printf("2) Establecer informacion\n");
		printf("3) Preview Ticket\n");
		printf("4) Volver atras\n");

		printf("\n");

		printf("Ingrese una opcion: ");
		scanf("%d", &option);

		switch (option){
			case 1:
				if (setTicket){
					printf("\n");
					PrintConfigTicket();
					printf("\n\n");
				} else{
					PrintMessage("Todavia no se establecio la configuracion del ticket", "Atencion");
				}
				break;
			case 2:
				if (setTicket){
					int selection;
					printf("\n\nATENCION\n");
					printf("Ya se establecio la configuracion del ticket, desea reestablecerla?\n");
					printf("1. Si\n");
					printf("2. No\n");

					printf("\n");
					printf("Ingrese una opcion: ");

					scanf("%d", &selection);

					if (selection == 2) selection = 0;

					if (selection){
						SetConfigTicket();
						pConfigTicket = GetConfigTicket();
					} else{ printf("\nNO SE REESTABLECIO LA CONFIGURACION DEL TICKET\n\n"); }

				} else{
					SetConfigTicket();
				}
				// Ya se configuro el ticket
				setTicket = 1;
				break;
			case 3:
				if (setTicket){
					printf("\n");
					PreviewTicket();
					printf("\n\n");
				} else{
					PrintMessage("Todavia no se establecio la configuracion del ticket", "Atencion");
				}
				break;
			case 4:
				// Vuelve al menu principal
				break;
			default:
				printf("Opcion no valida\n");
		}
	} while (option != 4);
}
<<<<<<< HEAD

// void GenerateTicket(){
// 	// Ticket data
// 	printf("GENERANDO UN NUEVO TICKET\n\n");
// 	InsertTicket();
// 	printf("TICKET GENERADO\n");
// }

=======
/*
void GenerateTicket(){
	// Ticket data
	printf("GENERANDO UN NUEVO TICKET\n\n");
	InsertTicket();
	printf("TICKET GENERADO\n");
}
*/
>>>>>>> 01f5db30a53124c16b91a5370c6334c6d49a1c48
void ViewAllTickets(){
	// Si no hay tickets, no se muestra nada
	if (pTicketTree == NULL){
		PrintMessage("No hay tickets aun", "Info");
		return;
	}

	printf("MOSTRANDO TODOS LOS TICKETS:\n");
	PrintTicketTreePre(pTicketTree);
	printf("\nFIN.\n");
}

// La funcion SearchTicketTree busca un ticket en el arbol de tickets
struct Ticket *SearchTicketTree(struct Ticket *pTicketAux, int id){
	// Si el arbol esta vacio, no hay ningun ticket
	if (pTicketAux == NULL){
		return NULL;
	}
	// Si el id del ticket es igual al id del ticket que se busca, se retorna el ticket
	if (pTicketAux->id == id){
		return pTicketAux;
	}
	// Si el id del ticket es menor al id del ticket que se busca, se busca en el subarbol izquierdo
	if (pTicketAux->id > id){
		return SearchTicketTree(pTicketAux->left, id);
	}
	// Si el id del ticket es mayor al id del ticket que se busca, se busca en el subarbol derecho
	if (pTicketAux->id < id){
		return SearchTicketTree(pTicketAux->right, id);
	}
	// Si no se encuentra el ticket, se retorna NULL
	return NULL;
}

// La funcion SearchTicket busca un ticket en la lista de tickets
// y lo retorna.
struct Ticket *SearchTicket(int id){
	struct Ticket *pTicket = NULL;
	struct Ticket *pTicketAux = pTicketTree;
	pTicket = SearchTicketTree(pTicketAux, id);
	return pTicket;
}

void ViewTicket(){
	int id_ticket_search;
	printf("Ingrese el ID del Ticket: ");
	scanf("%d", &id_ticket_search);

	struct Ticket *ticket_search = SearchTicket(id_ticket_search);

	if (ticket_search == NULL){
		PrintMessage("Ticket no encontrado", "Error");
	} else{
		printf("Ticket encontrado\n");
		PrintTicket(ticket_search);
	}
}
void Exit(){
	printf("Saliendo del programa...");
	exit(0);
}
void MenuSystem(){
	int option;

	do{
		MenuTitle("MENU PRINCIPAL");
		printf("1) Generar un Ticket\n");
		printf("2) Ver un Ticket\n");
		printf("3) Ver todos los Tickets\n");

		printf("\n");

		MenuTitle("MENU SYSTEM");
		printf("4) Configuracion de cuenta (?)\n");
		printf("5) Configuracion del ticket \n"); // Mostrar como se ve el ticket y preguntar que quiere cambiar
		printf("6) Cerrar sesion (?)\n");
		printf("7) Salir\n");

		printf("\n");

		printf("Ingrese una opcion: ");
		scanf("%d", &option);

		switch (option){
			case 1:
				printf("\n");
				// GenerateTicket();
				pTicketTree = insert(pTicketTree);
				printf("\n");
				break;
			case 2:
				printf("\n\n");
				ViewTicket();
				break;
			case 3:
				printf("\n");
				ViewAllTickets();
				printf("\n");
				break;
			case 4:
				printf("\n\n");
				// AccountSettings ();
				printf("\n\n");
				break;
			case 5:
				printf("\n\n");
				TicketSettings();
				printf("\n\n");
				break;
			case 6:
				printf("\n\n");
				// Logout ();
				printf("\n\n");
				break;
			case 7:
				printf("\n\n");
				Exit();
				printf("\n\n");
				break;
			default:
				PrintMessage("Opcion invalida", "Error");
		}
	} while (option != 8);
}

int main(){
	SetListProducts(); // Inicializar la lista de productos global
	MenuSystem();

	return 0;
}
