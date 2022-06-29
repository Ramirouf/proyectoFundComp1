#include <stdio.h>
#include <stdlib.h>

void ViewTicket(){
  int id_ticket_search;
  printf("Ingrese el ID del Ticket: ");
  scanf("%d", &id_ticket_search);

  struct Ticket *ticket_search = SearchTicket(id_ticket_search);

  if (ticket_search == NULL){
    PrintMessage("Ticket no encontrado", "Error");
  } else{
    printf("Ticket encontrado\n\n");
    PrintTicket(ticket_search);
  }
}