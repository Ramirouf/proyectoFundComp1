#include <stdio.h>
#include "PrintMessageError.h"
#include "SettingsTicket.h"
#include "MenuTitle.h"

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
    fflush(stdin);
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