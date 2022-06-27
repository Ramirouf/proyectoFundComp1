#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void InsertTicket(){
  struct Ticket *pNewTicketTreeItem = (struct Ticket *)malloc(sizeof(struct Ticket));
  int cant_prod_min = 0;

  // DATOS DEL TICKET
  // id
  pNewTicketTreeItem->id = id_tickets;
  // Hora y Fecha
  strcpy(pNewTicketTreeItem->date, getDate());
  strcpy(pNewTicketTreeItem->time, getTime());

  // Items del ticket
  while (cant_prod_min <= 3){
    InsertItemTicket();
    cant_prod_min++;
  }
  pNewTicketTreeItem->ProductsTicket = pAuxItemTicket;


  // Responsabilidad frente al IVA del emisor
  strcpy(pNewTicketTreeItem->resIVA, IVAResponsability());


  // Enlazar el nuevo nodo con el arbol
  if (pTicketTree == NULL){
    pTicketTree = pNewTicketTreeItem;
    pNewTicketTreeItem->left = NULL;
    pNewTicketTreeItem->right = NULL;
    pNewTicketTreeItem->height = 0;
  } else{
    struct Ticket *previus = NULL;
    struct Ticket *current = pTicketTree;
    while (current != NULL){
      previus = current;
      if (pNewTicketTreeItem->id < current->id){
        current = current->left;
      } else{
        current = current->right;
      }
    }
    if (previus->id < pNewTicketTreeItem->id){
      previus->right = pNewTicketTreeItem;
      pNewTicketTreeItem->left = NULL;
      pNewTicketTreeItem->right = NULL;
      pNewTicketTreeItem->height = 0;
    } else{
      previus->left = pNewTicketTreeItem;
      pNewTicketTreeItem->left = NULL;
      pNewTicketTreeItem->right = NULL;
      pNewTicketTreeItem->height = 0;
    }
  }

  // Limpio el puntero auxiliar
  pAuxItemTicket = NULL;

  // Incrementa el contador de ID de tickets para el príximo ticket
  id_tickets++;
}

void PrintItemTable(char *nameProduct, int widthColumn){
  int TEXT_WIDTH = widthColumn - 1; // -1 para el espacio entre el limite del nombre y el final de la columna

  /*
    Ejemplos

    Hola, buenas cómo... | // Esto pasa si la longitud del string es mayor a TEXT_WIDTH
    Hola, buenas!        | // Esto pasa si la longitud del string es manor a TEXT_WITDH
    Hola, buenas buenas! | // Esto pasa si la longitud del string es igual a TEXT_WIDTH
  */

  int lengthText = strlen(nameProduct);
  for (int i = 0; i < widthColumn; i++){
    if ((lengthText > TEXT_WIDTH) && (i >= (TEXT_WIDTH - 3))){
      if (i == TEXT_WIDTH) printf(" ");
      else printf(".");
    } else{
      if (i < lengthText){
        printf("%c", nameProduct[i]);
      } else{
        printf(" ");
      }
    }
  }
}

char *DoubleToString(double number){
  char *string = malloc(sizeof(char) * 10);
  sprintf(string, "%.2lf", number);
  return string;
}

void PrintManyTimes(char *string, int times){
  int i;
  for (i = 0; i < times; i++){
    printf("%s", string);
  }
}

void PrintItemTicket(struct ItemTicket *pItemTicket){
  int column_width_product = 30;
  int column_width_quantity = 10;
  int column_width_price = 10;
  int column_width_subtotal = 10;
  while (pItemTicket != NULL){
    PrintItemTable(pItemTicket->itemInfo->name, column_width_product);
    PrintItemTable(DoubleToString(pItemTicket->quantity), column_width_quantity);
    PrintItemTable(DoubleToString(pItemTicket->itemInfo->price), column_width_price);
    PrintItemTable(DoubleToString(pItemTicket->itemInfo->price), column_width_subtotal);
    printf("\n");
    pItemTicket = pItemTicket->next;
  }

  printf("\n\n");
}

void PrintTicket(struct Ticket *pTicket){
  int column_width_product = 30;
  int column_width_quantity = 10;
  int column_width_price = 10;
  int column_width_subtotal = 10;

  // Imprimir los metadatos del ticket
  printf("Ticket #%d\n", pTicket->id);
  printf("Fecha: %s\n", pTicket->date);
  printf("Hora: %s\n", pTicket->time);
  printf("Responsabilidad IVA: %s\n", pTicket->resIVA);
  printf("A CONSUMIDOR FINAL\n\n");

  // Imprimir el Header de los items del ticket
  PrintItemTable("Producto", column_width_product);
  PrintItemTable("Cantidad", column_width_quantity);
  PrintItemTable("Precio", column_width_price);
  PrintItemTable("Subtotal", column_width_subtotal); printf("\n");
  // Subline header    
  PrintItemTable("--------", column_width_product);
  PrintItemTable("--------", column_width_quantity);
  PrintItemTable("------", column_width_price);
  PrintItemTable("--------", column_width_subtotal); printf("\n\n");

  // Imprimir los items del ticket
  PrintItemTicket(pTicket->ProductsTicket);
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


void PrintTicketTreeEntre(struct Ticket *CopyTicketTree){
  if (CopyTicketTree != NULL){
    PrintTicketTreeEntre(CopyTicketTree->left);
    printf("ID: %u \n", CopyTicketTree->id);
    PrintTicketTreeEntre(CopyTicketTree->right);
  }
}

void PrintTicketTreePost(struct Ticket *CopyTicketTree){
  if (CopyTicketTree != NULL){
    PrintTicketTreePost(CopyTicketTree->left);
    PrintTicketTreePost(CopyTicketTree->right);
    printf("ID: %u \n", CopyTicketTree->id);
  }
}

void DeleteTicketTree(){
  if (pTicketTree != NULL){
    DeleteTicketTree(pTicketTree->left);
    DeleteTicketTree(pTicketTree->right);
    free(pTicketTree);
  }
}
