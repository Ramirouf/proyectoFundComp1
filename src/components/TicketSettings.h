#include <stdio.h>
#include <stdlib.h>

void TicketSettings(){
  int option;

  do{
    printf("\n\n");
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
        printf("\n");
        PrintConfigTicket();
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

          if (selection == 1){
            SetConfigTicket();
          } else{
            printf("\nSE CANCELO REESTABLECIO LA CONFIGURACION DEL TICKET\n\n");
          }
        } else{
          SetConfigTicket();
        }
        break;
      case 3:
        PreviewTicket();
        break;
      case 4:
        // Vuelve al menu principal
        break;
      default:
        printf("Opcion no valida\n");
    }
  } while (option != 4);
}