// #define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

char *IVAResponsability(){
  int option;
  char *responsability[] = { "IVA Responsable Inscripto", "IVA no Responsable", "IVA exento", "Responsable Monotributo",
  "Monotributista Social" };

  do{
    printf("Responsabilidad frente al impuesto al valor agregado del emisor segun corresponda:\n");
    printf("1. IVA Responsable Inscripto\n");
    printf("2. IVA no Responsable\n");
    printf("3. IVA exento\n");
    printf("4. Responsable Monotributo\n");
    printf("5. Monotributista Social\n");

    printf("Ingrese una opcion: ");
    scanf("%d", &option);

    if (option < 1 || option > 5){
      PrintMessageError("Opcion invalida", "Error");
    }
  } while (option < 1 || option > 5);

  return responsability[option - 1];
}







// void ListItemsMenu(){
//   int cont = 1;
//   FILE *fp;
//   char *line = NULL;
//   char *filename = "./public/list-items.txt";
//   size_t len = 0;
//   size_t read;

//   fp = fopen(filename, "r");
//   if (fp == NULL) exit(EXIT_FAILURE);

//   while ((read = getline(&line, &len, fp)) != -1){
//     // printf("%s", line);
//     printf("%d) ", cont);
//     char *token = strtok(line, ",");
//     while (token != NULL){
//       printf("%s ", token);
//       token = strtok(NULL, ",");
//     }
//     cont++;
//     printf("\n");
//   }

//   free(line);
//   exit(EXIT_SUCCESS);

//   // printf("LISTA DE PRODUCTOS\n");
//   // printf("");
// }


// struct nodo{
//   int info;
//   struct nodo *sig;
// };

// struct nodo *raiz = NULL;


// void FreeListTicketItems(){
//   struct nodo *reco = raiz;
//   struct nodo *bor;
//   while (reco != NULL){
//     bor = reco;
//     reco = reco->sig;
//     free(bor);
//   }
// }

// int IsListItemsTicketEmpty(){
//   if (raiz == NULL)
//     return 1;
//   else
//     return 0;
// }

// // Not used
// int cantidad(){
//   struct nodo *reco = raiz;
//   int cant = 0;
//   while (reco != NULL){
//     cant++;
//     reco = reco->sig;
//   }
//   return cant;
// }

// void insertar(int pos, int x){
//   if (pos <= cantidad() + 1){
//     struct nodo *nuevo;
//     // nuevo = malloc(sizeof(struct nodo));
//     nuevo->info = x;
//     if (pos == 1){
//       nuevo->sig = raiz;
//       raiz = nuevo;
//     } else
//       if (pos == cantidad() + 1){
//         struct nodo *reco = raiz;
//         while (reco->sig != NULL){
//           reco = reco->sig;
//         }
//         reco->sig = nuevo;
//         nuevo->sig = NULL;
//       } else{
//         struct nodo *reco = raiz;
//         int f;
//         for (f = 1; f <= pos - 2; f++){
//           reco = reco->sig;
//         }
//         struct nodo *siguiente = reco->sig;
//         reco->sig = nuevo;
//         nuevo->sig = siguiente;
//       }
//   }
// }

// void PrintListItemsTicket(){
//   struct nodo *reco = raiz;
//   printf("Lista completa.\n");
//   while (reco != NULL){
//     printf("%i ", reco->info);
//     reco = reco->sig;
//   }
//   printf("\n");
// }


// int RemoveItemFromList(int pos){
//   if (pos <= cantidad()){
//     int informacion;
//     struct nodo *bor;
//     if (pos == 1){
//       informacion = raiz->info;
//       bor = raiz;
//       raiz = raiz->sig;
//     } else{
//       struct nodo *reco;
//       reco = raiz;
//       int f;
//       for (f = 1; f <= pos - 2; f++){
//         reco = reco->sig;
//       }
//       struct nodo *prox = reco->sig;
//       reco->sig = prox->sig;
//       informacion = prox->info;
//       bor = prox;
//     }
//     free(bor);
//     return informacion;
//   } else
//     return -1;
// }


// void borrar(int pos){
//   if (pos <= cantidad()){
//     struct nodo *bor;
//     if (pos == 1){
//       bor = raiz;
//       raiz = raiz->sig;
//     } else{
//       struct nodo *reco;
//       reco = raiz;
//       int f;
//       for (f = 1; f <= pos - 2; f++){
//         reco = reco->sig;
//       }
//       struct nodo *prox = reco->sig;
//       reco->sig = prox->sig;
//       bor = prox;
//     }
//     free(bor);
//   }
// }

// // Not used
// void intercambiar(int pos1, int pos2){
//   if (pos1 <= cantidad() && pos2 <= cantidad()){
//     struct nodo *reco1 = raiz;
//     int f;
//     for (f = 1; f < pos1; f++){
//       reco1 = reco1->sig;
//     }
//     struct nodo *reco2 = raiz;
//     for (f = 1; f < pos2; f++){
//       reco2 = reco2->sig;
//     }
//     int aux = reco1->info;
//     reco1->info = reco2->info;
//     reco2->info = aux;
//   }
// }

// // Not used
// int mayor(){
//   if (!IsListItemsTicketEmpty()){
//     int may = raiz->info;
//     struct nodo *reco = raiz->sig;
//     while (reco != NULL){
//       if (reco->info > may){
//         may = reco->info;
//       }
//       reco = reco->sig;
//     }
//     return may;
//   } else
//     return -1;
// }

// // Not used
// int posMayor(){
//   if (!IsListItemsTicketEmpty()){
//     int may = raiz->info;
//     int x = 1;
//     int pos = x;
//     struct nodo *reco = raiz->sig;
//     while (reco != NULL){
//       x++;
//       if (reco->info > may){
//         may = reco->info;
//         pos = x;
//       }
//       reco = reco->sig;
//     }
//     return pos;
//   } else
//     return -1;
// }

// // Not used
// int ordenada(){
//   if (cantidad() > 1){
//     struct nodo *reco1 = raiz;
//     struct nodo *reco2 = raiz->sig;
//     while (reco2 != NULL){
//       if (reco2->info < reco1->info){
//         return 0;
//       }
//       reco2 = reco2->sig;
//       reco1 = reco1->sig;
//     }
//   }
//   return 1;
// }

// // IMPORTANT
// int existe(int x){
//   struct nodo *reco = raiz;
//   while (reco != NULL){
//     if (reco->info == x)
//       return 1;
//     reco = reco->sig;
//   }
//   return 0;
// }


// // int main(){
// //   insertar(1, 10);
// //   insertar(2, 20);
// //   insertar(3, 30);
// //   insertar(2, 15);
// //   insertar(1, 115);
// //   PrintListItemsTicket();
// //   printf("Luego de Borrar el primero\n");
// //   borrar(1);
// //   PrintListItemsTicket();
// //   printf("Luego de RemoveItemFromList el segundo\n");
// //   RemoveItemFromList(2);
// //   PrintListItemsTicket();
// //   printf("Luego de Intercambiar el primero con el tercero\n");
// //   intercambiar(1, 3);
// //   PrintListItemsTicket();
// //   if (existe(20))
// //     printf("Se encuentra el 20 en la lista\n");
// //   else
// //     printf("No se encuentra el 20 en la lista\n");
// //   printf("La posicion del mayor es:%i\n", posMayor());
// //   if (ordenada())
// //     printf("La lista esta ordenada de menor a mayor\n");
// //   else
// //     printf("La lista no esta ordenada de menor a mayor\n");
// //   FreeListTicketItems();
// //   getch();
// //   return 0;
// // }


