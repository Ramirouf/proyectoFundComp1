#include <stdio.h>
#include <stdlib.h>

void InsertTicket(){
  struct TicketTree *pNewTicketTreeItem;
  pNewTicketTreeItem = (struct TicketTree *)malloc(sizeof(struct TicketTree));



  // DATOS DEL TICKET
  // id
  pNewTicketTreeItem->id = id_tickets;
  // Hora y Fecha
  pNewTicketTreeItem->ticket->time = getTime();
  pNewTicketTreeItem->ticket->date = getDate();
  // Responsabilidad frente al IVA del emisor
  pNewTicketTreeItem->ticket->resIVA = IVAResponsability();
  // Leyenda
  pNewTicketTreeItem->ticket->leyenda = "A CONSUMIDOR FINAL";



  GenerateItemsTicket(pNewTicketTreeItem->ticket->itemTicket);

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

  // Incrementa el contador de ID de tickets para el príximo ticket
  id_tickets++;
}

void PrintTicketTreePre(struct TicketTree *CopyTicketTree){
  if (CopyTicketTree != NULL){
    printf("ID: %u \n", CopyTicketTree->id);
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
