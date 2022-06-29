#include <stdio.h>
#include <stdlib.h>

void InitialConfigTicket(){
  printf("Antes de iniciar el programa, debe configurar el ticket.\n");
  printf("Para ello, siga los siguientes pasos");

  SetConfigTicket();
  PrintConfigTicket();

  printf("Mas adelante, podra volver a ver o configurar el ticket.\n");

  // Bandera para saber que ya se configuro el ticket
  setTicket = 1;
}