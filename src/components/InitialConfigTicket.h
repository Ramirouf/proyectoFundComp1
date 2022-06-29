#include <stdio.h>
#include <stdlib.h>

void InitialConfigTicket()
{
  printf("\tAntes de iniciar el programa, debe configurar el ticket.\n");
  printf("\tPara ello, siga los siguientes pasos");

  SetConfigTicket();
  PrintConfigTicket();

  printf("\tMas adelante, podra volver a ver o configurar el ticket.\n");

  // Bandera para saber que ya se configuro el ticket
  setTicket = 1;
}