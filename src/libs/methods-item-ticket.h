#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
// Insertar un producto en un ticket
struct Item *GetProductById(int id){
  struct ListProducts *product = pListProducts;
  while (product != NULL){
    if (product->itemInfo.idItem == id){
      return &product->itemInfo;
    }
    product = product->next;
  }

  return NULL;
}

int InsertItemTicket(){
  int option;

  PrintListProducts();
  printf("Ingrese el codigo del producto (o -1 para terminar): ");
  scanf("%d", &option);

  if (option >= 1 && option <= 10){
    struct ItemTicket *pNewItemTicket = (struct ItemTicket *)malloc(sizeof(struct ItemTicket));
    // Info del nuevo item
    pNewItemTicket->itemInfo = GetProductById(option);
    // Pedir la cantidad de productos
    do{
      printf("Ingrese la cantidad: ");
      scanf("%f", &pNewItemTicket->quantity);
      if (pNewItemTicket->quantity < 0) PrintMessage("La cantidad debe ser mayor a 0", "Error");
    } while (pNewItemTicket->quantity <= 0);

    printf("\n");

    // Enlazar la nueva lista con la anterior
    if (pAuxItemTicket == NULL){
      pAuxItemTicket = pNewItemTicket;
      pNewItemTicket->next = NULL;
      // printf("pAuxItemTicket null\n");
    } else{
      // printf("pAuxItemTicket not null\n");
      pNewItemTicket->next = pAuxItemTicket;
      pAuxItemTicket = pNewItemTicket;
    }
    return 1;
  } else if (option == -1){
    printf("Carga de productos detenida\n\n");
    return 0;
  } else{
    PrintMessage("ID del producto desconocido, vuelva a intentarlo", "Error");
    return 1;
  }
}
