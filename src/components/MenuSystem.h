#include <stdio.h>
#include <stdlib.h>

void MenuSystem()
{
  int option;

  do
  {
    printf("\n\n");
    MenuTitle("MENU PRINCIPAL");
    printf("\t1) Generar un Ticket\n");
    printf("\t2) Ver un Ticket\n");
    printf("\t3) Ver todos los Tickets\n");

    printf("\n");

    MenuTitle("MENU SYSTEM");
    // printf("4) Configuracion de cuenta (?)\n");
    printf("\t4) Configuracion del ticket \n"); // Mostrar como se ve el ticket y preguntar que quiere cambiar
    // printf("6) Cerrar sesion\n");
    printf("\t5) Salir\n");

    printf("\n");

    printf("\tIngrese una opcion: ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
      printf("\n");
      pTicketTree = insert(pTicketTree);
      printf("\tTICKET GENERADO CORRECTAMENTE\n\n");
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
    // case 4:
    //   printf("\n\n");
    //   // AccountSettings ();
    //   printf("\n\n");
    //   break;
    case 4:
      printf("\n\n");
      TicketSettings();
      printf("\n\n");
      break;
    // case 6:
    //   printf("\n\n");
    //   LogOut();
    //   Login();
    //   printf("\n\n");
    //   break;
    case 5:
      printf("\n\n");
      Exit();
      printf("\n\n");
      break;
    default:
      PrintMessage("\tOpcion invalida", "Error");
    }
  } while (option != 8);
}
