#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void InsertTicket()
{
  struct Ticket *pNewTicketTreeItem = (struct Ticket *)malloc(sizeof(struct Ticket));
  int cant_prod_min;

  // Init
  cant_prod_min = 0;

  // DATOS DEL TICKET
  // id
  pNewTicketTreeItem->id = id_tickets;
  // Hora y Fecha
  strcpy(pNewTicketTreeItem->date, getDate());
  strcpy(pNewTicketTreeItem->time, getTime());

  // Items del ticket
  while (cant_prod_min <= 3)
  {
    InsertItemTicket();
    cant_prod_min++;
  }
  pNewTicketTreeItem->ProductsTicket = pAuxItemTicket;

  // Responsabilidad frente al IVA del emisor
  strcpy(pNewTicketTreeItem->resIVA, IVAResponsability());

  // Enlazar el nuevo nodo con el arbol
  if (pTicketTree == NULL)
  {
    pTicketTree = pNewTicketTreeItem;
    pNewTicketTreeItem->left = NULL;
    pNewTicketTreeItem->right = NULL;
    pNewTicketTreeItem->height = 0;
  }
  else
  {
    struct Ticket *previus = NULL;
    struct Ticket *current = pTicketTree;
    while (current != NULL)
    {
      previus = current;
      if (pNewTicketTreeItem->id < current->id)
      {
        current = current->left;
      }
      else
      {
        current = current->right;
      }
    }
    if (previus->id < pNewTicketTreeItem->id)
    {
      previus->right = pNewTicketTreeItem;
      pNewTicketTreeItem->left = NULL;
      pNewTicketTreeItem->right = NULL;
      pNewTicketTreeItem->height = 0;
    }
    else
    {
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

void PrintItemTicket(struct ItemTicket *pItemTicket)
{
  while (pItemTicket != NULL)
  {
    printf(" %s\n %.2f x %.2f \t\t $%.2f\n",
           pItemTicket->itemInfo->name, pItemTicket->quantity,
           pItemTicket->itemInfo->price,
           pItemTicket->quantity * pItemTicket->itemInfo->price);

    pItemTicket = pItemTicket->next;
    if (!pItemTicket)
      printf("\n\n\n");
  }
}

void PrintTicketTreePre(struct Ticket *CopyTicketTree)
{
  if (CopyTicketTree != NULL)
  {
    printf(" ID del ticket: %d\n Fecha: %s\n Hora: %s\n %s\n\n", CopyTicketTree->id, CopyTicketTree->date, CopyTicketTree->time, CopyTicketTree->resIVA);
    PrintItemTicket(CopyTicketTree->ProductsTicket);
    PrintTicketTreePre(CopyTicketTree->left);
    PrintTicketTreePre(CopyTicketTree->right);
  }
}

void PrintTicketTreeEntre(struct Ticket *CopyTicketTree)
{
  if (CopyTicketTree != NULL)
  {
    PrintTicketTreeEntre(CopyTicketTree->left);
    printf("ID: %u \n", CopyTicketTree->id);
    PrintTicketTreeEntre(CopyTicketTree->right);
  }
}

void PrintTicketTreePost(struct Ticket *CopyTicketTree)
{
  if (CopyTicketTree != NULL)
  {
    PrintTicketTreePost(CopyTicketTree->left);
    PrintTicketTreePost(CopyTicketTree->right);
    printf("ID: %u \n", CopyTicketTree->id);
  }
}

void DeleteTicketTree()
{
  if (pTicketTree != NULL)
  {
    DeleteTicketTree(pTicketTree->left);
    DeleteTicketTree(pTicketTree->right);
    free(pTicketTree);
  }
}
