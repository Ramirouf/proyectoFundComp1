#include <stdio.h>
#include <stdlib.h>

void PrintItemTicket(struct ItemTicket *pItemTicket){
  int column_width_product = 40;
  int column_width_subtotal = 10;
  char text[15];
  char price[15];
  double total = 0;
  while (pItemTicket != NULL){
    PrintItemTable(pItemTicket->itemInfo->name, column_width_product);
    PrintItemTable("", column_width_subtotal);
    printf("\n");
    // PrintItemTable(DoubleToString(pItemTicket->quantity), column_width_quantity);
    // printf("\n%.2f x %.2f  ", pItemTicket->quantity, pItemTicket->itemInfo->price);
    sprintf(text, "%.2f x %.2f", pItemTicket->quantity, pItemTicket->itemInfo->price);
    sprintf(price, "$ %.2f", pItemTicket->itemInfo->price * pItemTicket->quantity);
    PrintItemTable(text, column_width_product);
    // PrintItemTable(DoubleToString(pItemTicket->itemInfo->price), column_width_price);
    PrintItemTable(price, column_width_subtotal);
    printf("\n");
    total += pItemTicket->itemInfo->price * pItemTicket->quantity;
    pItemTicket = pItemTicket->next;
  }
  // Si ya no hay más elementos en la lista
  if (pItemTicket == NULL){
    printf("\n------------------------------------------------\n");
    printf("\t\t\t\tTOTAL: $ %.2f", total);
    printf("\n------------------------------------------------\n");
  }
  printf("\n");
}

void PrintTicket(struct Ticket *pTicket){
  int column_width_product = 40;
  int column_width_subtotal = 10;

  // Imprimir los metadatos del ticket
  printf("Ticket #%d\n", pTicket->id);

  struct ConfigTicket *pConfigTicket = GetConfigTicket();

  // Config Ticket
  printf("Razon Social: %s\n", pConfigTicket->businessName);
  printf("Direccion: %s\n", pConfigTicket->address);
  printf("Telefono: %s\n", pConfigTicket->phone);
  printf("Codigo Postal: %s\n", pConfigTicket->postalCode);
  printf("CUIT: %s\n", pConfigTicket->cuit);
  printf("Res IVA: %s\n", pConfigTicket->resIVA);

  printf("Fecha: %s\n", pTicket->date);
  printf("Hora: %s\n", pTicket->time);
  printf("A CONSUMIDOR FINAL\n\n");

  // Imprimir el Header de los items del ticket
  PrintItemTable("Producto", column_width_product);
  PrintItemTable("Subtotal", column_width_subtotal);
  printf("\n");
  // Subline header
  PrintItemTable("--------", column_width_product);
  PrintItemTable("--------", column_width_subtotal);
  printf("\n\n");

  // Imprimir los items del ticket
  PrintItemTicket(pTicket->ProductsTicket);

  // Leyenda
  printf("### %s ###\n\n", pConfigTicket->messageGB);

  // Liberar memoria
  free(pConfigTicket);
}

void PrintTicketTreePre(struct Ticket *CopyTicketTree){
  if (CopyTicketTree != NULL){
    // Imprimir Ticket
    PrintTicket(CopyTicketTree);

    // Bajar por el arbol hasta el ultimo nodo
    PrintTicketTreePre(CopyTicketTree->left);
    PrintTicketTreePre(CopyTicketTree->right);
  }
}

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

// Muestra la configuracion del ticket y datos de un ticket de ejemplo
void PreviewTicket(){
  // char *mode = "r";
  // // Ticket data
  // struct ConfigTicket *configT = GetConfigTicket(mode);
}