#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void InsertItemTicket(){
  int option;
  struct ItemTicket *pNewItemTicket = (struct ItemTicket *)malloc(sizeof(struct ItemTicket));


  ListOfItems();
  printf("\nIngrese el codigo del producto: ");
  scanf("%d", &option);

  if (option >= 1 && option <= 10){
    // Info del nuevo item
    pNewItemTicket->itemInfo->name = products[option - 1].name;
    // printf("Name product:  %s\n", pNewItemTicket->itemInfo->name);
    pNewItemTicket->itemInfo->unit = products[option - 1].unit;
    // printf("Unit product:  %s\n", pNewItemTicket->itemInfo->unit);
    pNewItemTicket->itemInfo->price = products[option - 1].price;
    // printf("Price product:  %.2f\n", pNewItemTicket->itemInfo->price);
    // Pedir la cantidad de productos
    printf("\nIngrese la cantidad: ");
    scanf("%d", &pNewItemTicket->quantity);
    // printf("Quantity product:  %d\n", pNewItemTicket->quantity);
    printf("\n");

    // Enlazar la nueva lista con la anterior
    if (pAuxItemTicket == NULL){
      pAuxItemTicket = pNewItemTicket;
      pNewItemTicket->next = NULL;
    } else{
      pNewItemTicket->next = pAuxItemTicket;
      pAuxItemTicket = pNewItemTicket;
    }
  } else{
    PrintMessageError("Debe de haber al menos un producto para generar un ticket", "Error");
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
//       PrintMessageError("Debe de haber al menos un producto para generar un ticket", "Error");
//     }

//   } while (cant_prod_min < 1);

//   return *pNewItemProduct;
// }

