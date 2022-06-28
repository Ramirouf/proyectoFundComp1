#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
// Insertar un producto en un ticket
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

int InsertItemTicket()
{
  int option;

  PrintListProducts();
  printf("\nIngrese el codigo del producto (o -1 para terminar): ");
  scanf("%d", &option);

  if (option >= 1 && option <= 10)
  {
    struct ItemTicket *pNewItemTicket = (struct ItemTicket *)malloc(sizeof(struct ItemTicket));
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
      // printf("pAuxItemTicket Null\n");
    }
    else
    {
      // printf("pAuxItemTicket Things\n");
      pNewItemTicket->next = pAuxItemTicket;
      pAuxItemTicket = pNewItemTicket;
    }
    return 1;
  }
  else if (option == -1)
  {
    printf("\nDeteniendo carga de tickets\n");
    return 0;
  }
  else
  {
    PrintMessage("Debe de haber al menos un producto para generar un ticket", "Error");
    return 1;
  }
}
