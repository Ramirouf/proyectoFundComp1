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

  // Items del ticket - Dont work
  while (cant_prod_min <= 3){
    InsertItemTicket();
    cant_prod_min++;
  }
  pNewTicketTreeItem->ProductsTicket = pAuxItemTicket;


  // Responsabilidad frente al IVA del emisor
  strcpy(pNewTicketTreeItem->resIVA, IVAResponsability());


  pNewTicketTreeItem->left = NULL;
  pNewTicketTreeItem->right = NULL;



  if (pTicketTree == NULL){
    pTicketTree = pNewTicketTreeItem;
  } else{
    struct Ticket *previus, *current;
    previus = NULL;
    current = pTicketTree;
    while (current != NULL){
      previus = current;
      if (pNewTicketTreeItem->id < current->id){
        current = current->left;
      } else{
        current = current->right;
      }
    }
    if (pNewTicketTreeItem->id < previus->id){
      previus->left = pNewTicketTreeItem;
    } else{
      previus->right = pNewTicketTreeItem;
    }
  }

  // Limpio el puntero auxiliar
  pAuxItemTicket = NULL;

  // Incrementa el contador de ID de tickets para el príximo ticket
  id_tickets++;
}

void PrintItemTicket(struct ItemTicket *pItemTicket){
  printf("PrintItemTicket\n");
  printf("Cantidad: %f\n", pItemTicket->quantity);
  printf("Producto: %s\n", pItemTicket->itemInfo->name);
  printf("Precio: %.2f\n", pItemTicket->itemInfo->price);
}

void PrintTicketTreePre(struct Ticket *CopyTicketTree){
  if (CopyTicketTree != NULL){
    printf("ID: %u \n", CopyTicketTree->id);
    printf("Fecha: %s \n", CopyTicketTree->date);
    printf("Hora: %s \n", CopyTicketTree->time);
    printf("Leyenda: A CONSUMIDOR FINAL \n");
    printf("Responsabilidad IVA: %s \n", CopyTicketTree->resIVA);
    // printf("\n");
    // PrintItemTicket(CopyTicketTree->ticket.itemTicket);
    printf("\n");
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
