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

int InsertItemTicket()
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
<<<<<<< HEAD
  } else{
    PrintMessage("Id incorrecto, vuelva a intentarlo", "Error");
  }
}

// struct Item getOneProduct(int *cant_prod_min){
//   struct Item *pNewItemProduct = (struct Item *)malloc(sizeof(struct Item));

//   int option;

//   do{
//     ListOfItems(); // Imprime la lista de productos

//     printf("Ingrese una opcion: ");
//     scanf("%d", &option);

//     if (option >= 1 && option <= 10){
//       pNewItemProduct = products[option - 1]; // producs va del 0 al 9
//       *cant_prod_min = *cant_prod_min + 1;
//     } else{
//       PrintMessage("Debe de haber al menos un producto para generar un ticket", "Error");
//     }

//   } while (cant_prod_min < 1);

//   return *pNewItemProduct;
// }

=======
    return 1;
  }
  else if (option == -1)
  {
    printf("\nDeteniendo carga de tickets\n");
    return 0;
  }
  else
  {
    PrintMessageError("Debe de haber al menos un producto para generar un ticket", "Error");
    return 1;
  }
}
>>>>>>> fcb7d26107b2e4f1f1e5e8617f88445332b90d1d
