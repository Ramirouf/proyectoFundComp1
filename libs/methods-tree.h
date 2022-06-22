#include <stdio.h>
#include <stdlib.h>

void InsertTicket(){
  printf("InsertTicket\n");
  struct TicketTree *pNewTicketTreeItem = (struct TicketTree *)malloc(sizeof(struct TicketTree));
  printf("F*ck\n");
  int cont = 1;
  // struct ItemTicket *pItemTicket = NULL;


  // DATOS DEL TICKET
  // id
  pNewTicketTreeItem->id = id_tickets;
  // Hora y Fecha
  pNewTicketTreeItem->ticket.time = getTime();
  // printf("TIME: %s\n", pNewTicketTreeItem->ticket.time);
  pNewTicketTreeItem->ticket.date = getDate();
  // printf("DATE: %s\n", pNewTicketTreeItem->ticket.date);
  // Leyenda
  pNewTicketTreeItem->ticket.leyenda = "A CONSUMIDOR FINAL"; // Puede que se elimine en el futuro*
  // Items del ticket


  pNewTicketTreeItem->ticket.itemTicket = NULL; // Inicializar el puntero a NULL


  InsertItemTicket();

  pNewTicketTreeItem->ticket.itemTicket = pAuxItemTicket;


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
