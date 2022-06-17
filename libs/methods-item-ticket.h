#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>


void ListOfItems(){
  printf("LISTA DE PRODUCTOS\n");
  for (int i = 0; i < CANT_PRODUCTS; i++){
    printf("%d. %s\n", i + 1, products[i].name);
  }
  printf("\n");
}

void GenerateItemsTicket(struct ItemTicket *pItemTicket){
  int option, cant_prod_min;
  pItemTicket = NULL;
  // Cantidad de productos minimos para generar un ticket = 1
  cant_prod_min = 0;

  // Generar un ticket con una cantidad de productos minimos
  while (cant_prod_min < 1){
    struct ItemTicket *pNewItemTicket;
    pNewItemTicket = (struct ItemTicket *)malloc(sizeof(struct ItemTicket));
    printf("HERE: \n");
    ListOfItems();

    printf("\nIngrese el codigo del producto: ");
    scanf("%d", &option);

    if (option >= 1 && option <= 10){
      // Asignar el producto a la nueva lista y enlazarla con la anterior
      // Info del nuevo item
      pNewItemTicket->itemInfo->name = products[option - 1].name;
      pNewItemTicket->itemInfo->unit = products[option - 1].unit;
      pNewItemTicket->itemInfo->price = products[option - 1].price;
      // Pedir la cantidad de productos
      printf("\nIngrese la cantidad: ");
      scanf("%d", &pNewItemTicket->quantity);
      printf("\n");

      // Enlazar la nueva lista con la anterior
      if (pItemTicket == NULL){
        pItemTicket = pNewItemTicket;
        pNewItemTicket->next = NULL;
      } else{
        pNewItemTicket->next = pItemTicket;
        pItemTicket = pNewItemTicket;
      }

      // Incrementar la cantidad de productos minimos
      cant_prod_min++;
    } else{
      PrintMessageError("Debe de haber al menos un producto para generar un ticket", "Error");
    }
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

