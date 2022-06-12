// #include <stdio.h>
// #include <stdlib.h>
// #include "dinamic-memory.h"

// void WelcomeMessage(){
//   printf("Welcome to the C programming language!\n");
// }

// void SeparateLine(){
//   printf("----------------------------------------\n");
// }

// void PrintMessageError(char *message, char *type){

//   printf("\n");
//   SeparateLine();
//   printf("%s: %s\n", type, message);
//   SeparateLine();
//   printf("\n");
// }

// void MenuSystem(){
//   int option;

//   do{
//     printf("MENU PRINCIPAL\n");
//     printf("1) Generar un Ticket\n");
//     printf("2) Validar un Ticket\n");
//     printf("3) Ver un Ticket\n");
//     printf("4) Ver todos los Tickets\n");

//     printf("\n");

//     printf("MENU SYSTEM\n");
//     printf("5) Configuración de cuenta\n");
//     printf("6) Configuración del ticket \n"); // Mostrar cómo se ve el ticket y preguntar que quiere cambiar
//     printf("7) Cerrar sesión\n");
//     printf("8) Salir\n");

//     printf("\n");

//     printf("Ingrese una opción: ");
//     fflush(stdin);
//     scanf("%d", &option);

//     switch (option){
//       case 1:
//         // GenerateTicket ();
//         printf("Hello\n");
//         break;
//       case 2:
//         // ValidateTicket ();
//         break;
//       case 3:
//         // ViewTicket ();
//         break;
//       case 4:
//         // ViewAllTickets ();
//         break;
//       case 5:
//         // AccountSettings ();
//         break;
//       case 6:
//         // TicketSettings ();
//         break;
//       case 7:
//         // Logout ();
//         break;
//       case 8:
//         // Exit ();
//         break;
//       default:
//         PrintMessageError("Opción inválida", "Error");
//     }
//   } while (option != 8);

// }

// int main(int argc, char *argv[]){


//   WelcomeMessage();
//   // insertar(10);
//   // insertar(40);
//   // insertar(3);
//   // imprimir();
//   // printf("Extraemos de la pila:%i\n", extraer());
//   // imprimir();
//   // liberar();


//   return 0;
// }