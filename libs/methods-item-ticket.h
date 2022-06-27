#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct Item *GetProductById(int id)
{
  struct ListProducts *product = pListProducts;
  while (product != NULL)
  {
    if (product->itemInfo.idItem == id)
    {
      return &product->itemInfo;
    }
    product = product->next;
  }

  return NULL;
}

void InsertItemTicket()
{
  int option;
  struct ItemTicket *pNewItemTicket = (struct ItemTicket *)malloc(sizeof(struct ItemTicket));

  PrintListProducts();
  printf("\nIngrese el codigo del producto: ");
  scanf("%d", &option);

  if (option >= 1 && option <= 10)
  {
    // Info del nuevo item
    pNewItemTicket->itemInfo = GetProductById(option);
    // Pedir la cantidad de productos
    printf("\nIngrese la cantidad: ");
    scanf("%f", &pNewItemTicket->quantity);
    printf("\n");

    // Enlazar la nueva lista con la anterior
    if (pAuxItemTicket == NULL)
    {
      pAuxItemTicket = pNewItemTicket;
      pNewItemTicket->next = NULL;
    }
    else
    {
      pNewItemTicket->next = pAuxItemTicket;
      pAuxItemTicket = pNewItemTicket;
    }
  }
  else
  {
    PrintMessageError("Debe de haber al menos un producto para generar un ticket", "Error");
  }
}
