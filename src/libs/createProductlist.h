#include <stdio.h>
#include <stdlib.h>
#include "./momentC.h"
#include "./methods-item-ticket.h"
// Estructura de los Productos
struct Item
{
    int idItem;
    char *name;
    double price;
};

// Estructura de los Productos del Ticket
struct ItemTicket
{
    float quantity;
    struct Item *itemInfo;
    struct ItemTicket *next;
};

// Estructura de arbol aVL
struct Ticket
{
    int id;
    char *date;
    char *time;
    char *resIVA;
    struct ItemTicket *ProductsTicket;
    struct Ticket *left;
    struct Ticket *right;
    int height;
};

/*struct Item *GetProductById(int id)
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
*/

struct Itemticket *CreateProductList()
{
    int OptionID;
    float ItemQuantity;
    struct ItemTicket *ItemList = NULL, *ItemListAux = NULL;

    printf("\n Que Producto desea ingresar? Ingrese el ID del producto \n");
    scanf("%d", &OptionID);

    struct ItemTicket *ItemList = (struct ItemTicket *)malloc(sizeof(struct ItemList));
    ItemList->itemInfo = GetProductById(OptionID);
    printf("\nIngrese la cantidad del producto \n");
    scanf("%f", &ItemQuantity);

    ItemList->quantity = ItemQuantity;
    ItemList->next = ItemListAux;
    ItemListAux = ItemList;
    do
    {

        printf("\n Que Producto desea ingresar? Ingrese el ID del producto o de lo contrario ingrese -1 \n");
        scanf("%d", &OptionID);
        if (OptionID > -1)
        {
            struct ItemTicket *ItemList = (struct ItemTicket *)malloc(sizeof(struct ItemList));
            ItemList->itemInfo = GetProductById(int OptionID);
            printf("\nIngrese la cantidad del producto \n");
            scanf("%f", &ItemQuantity);

            ItemList->quantity = ItemQuantity;
            ItemList->next = ItemListAux;
            ItemListAux = ItemList;
        }

        struct ItemTicket *ItemList = (struct ItemTicket *)malloc(sizeof(struct ItemList));
        ItemList->itemInfo = GetProductById(int OptionID);

    } while (OptionID < 0);

    return &ItemList;
}