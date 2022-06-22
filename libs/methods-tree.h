#include <stdio.h>
#include <stdlib.h>

void InsertTicket(){
  // printf("PROBLEMS 1\n");
  struct TicketTree *pNewTicketTreeItem = (struct TicketTree *)malloc(sizeof(struct TicketTree));
  // printf("PROBLEMS 2\n");

  // DATOS DEL TICKET
  // id
  pNewTicketTreeItem->id = id_tickets;
  // Hora y Fecha
  pNewTicketTreeItem->ticket.time = getTime();
  // // printf("TIME: %s\n", pNewTicketTreeItem->ticket.time);
  pNewTicketTreeItem->ticket.date = getDate();
  // // printf("DATE: %s\n", pNewTicketTreeItem->ticket.date);

  // Items del ticket - Dont work
  // InsertItemTicket(); 
  // pNewTicketTreeItem->ticket.itemTicket = pAuxItemTicket;


  // Responsabilidad frente al IVA del emisor
  pNewTicketTreeItem->ticket.resIVA = IVAResponsability();


  pNewTicketTreeItem->left = NULL;
  pNewTicketTreeItem->right = NULL;



  if (pTicketTree == NULL){
    pTicketTree = pNewTicketTreeItem;
  } else{
    struct TicketTree *previus, *current;
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
  printf("Cantidad: %d\n", pItemTicket->quantity);
  printf("Nombre Producto: %s\n", pItemTicket->itemInfo->name);
  printf("Unidad: %s\n", pItemTicket->itemInfo->unit);
  printf("Precio: %.2f\n", pItemTicket->itemInfo->price);
}

void PrintTicketTreePre(struct TicketTree *CopyTicketTree){
  if (CopyTicketTree != NULL){
    printf("ID: %u \n", CopyTicketTree->id);
    printf("Fecha: %s \n", CopyTicketTree->ticket.date);
    printf("Hora: %s \n", CopyTicketTree->ticket.time);
    printf("Leyenda: A CONSUMIDOR FINAL \n");
    printf("Responsabilidad IVA: %s \n", CopyTicketTree->ticket.resIVA);
    // printf("\n");
    // PrintItemTicket(CopyTicketTree->ticket.itemTicket);
    printf("\n");
    PrintTicketTreePre(CopyTicketTree->left);
    PrintTicketTreePre(CopyTicketTree->right);
  }
}


void PrintTicketTreeEntre(struct TicketTree *CopyTicketTree){
  if (CopyTicketTree != NULL){
    PrintTicketTreeEntre(CopyTicketTree->left);
    printf("ID: %u \n", CopyTicketTree->id);
    PrintTicketTreeEntre(CopyTicketTree->right);
  }
}

void PrintTicketTreePost(struct TicketTree *CopyTicketTree){
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
