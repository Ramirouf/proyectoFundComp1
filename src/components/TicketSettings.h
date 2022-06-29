#include <stdio.h>
#include <stdlib.h>

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

          do{
            printf("\n\nATENCION\n");
            printf("Ya se establecio la configuracion del ticket, desea reestablecerla?\n");
            printf("1. Si\n");
            printf("2. No\n");

            printf("\n");
            printf("Ingrese una opcion: ");
            scanf("%d", &selection);
            if (selection != 1 && selection != 2) PrintMessage("Opcion invalida", "Atencion");

          } while (selection != 1 && selection != 2);

          if (selection == 2)
            selection = 0;

          if (selection){
            SetConfigTicket();
            pConfigTicket = GetConfigTicket();
          } else{
            printf("\nNO SE REESTABLECIO LA CONFIGURACION DEL TICKET\n\n");
          }
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