/*
Header File to print a ticket on screen
It receives a structure of type Ticket and prints it on screen
*/

#include <stdlib.h>
#include <stdio.h>

#define CONFIG_TICKET_NAME_LENGTH 20
#define CONFIG_TICKET_ADDRESS_LENGTH 50
#define CONFIG_TICKET_PHONE_LENGTH 20
#define CONFIG_TICKET_CP_LENGTH 50
#define CONFIG_TICKET_CUIT_LENGTH 11
#define CONFIG_TICKET_GB_LENGTH 20

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
typedef struct Ticket
{
    int id;
    char *date;
    char *time;
    char *resIVA;
    struct ItemTicket *ProductsTicket;
    struct Ticket *left;
    struct Ticket *right;
    int height;
} Ticket;

typedef struct ConfigTicket
{
    char businessName[CONFIG_TICKET_NAME_LENGTH];
    char address[CONFIG_TICKET_ADDRESS_LENGTH];
    char phone[CONFIG_TICKET_PHONE_LENGTH];
    char postalCode[CONFIG_TICKET_CP_LENGTH];
    char cuit[CONFIG_TICKET_CUIT_LENGTH];
    char messageGB[CONFIG_TICKET_GB_LENGTH];
} Config;

void printTicket(Ticket ticket)
{
    double total = 0;
    Config config;

    printf("%s", config.businessName);
    printf("%s", config.address);
    printf("%s", config.phone);
    printf("%s", config.postalCode);
    printf("%s\n", config.cuit);
    printf("**************************\n");
    printf("----------TICKET----------\n");
    printf("**************************\n");
    printf("Descripcion\t\tCantidad\t\tPrecio Unitario\t\tPrecio\n");
    // Mostrar productos
    // Esto implica recorrer la lista de productos e ir mostrando

    while (ticket.ProductsTicket->next)
    {
        printf("Nombre: %s\n", ticket.ProductsTicket->itemInfo->name);
        printf("Cantidad: %d", ticket.ProductsTicket->quantity);
        ticket.ProductsTicket = ticket.ProductsTicket->next;
    }
    // Mostrar el total
    printf("TOTAL\t\t\t\t\t\t\t\t\t %lf\n", total);

    // Saludo
    printf("%s", config.messageGB);
}
/*
void printProduct() {
    struct nodo *reco = raiz;
    printf("Lista completa.\n");
    while (reco != NULL)
    {
        printf("%i ", reco->info);
        reco = reco->sig;
    }
    printf("\n");
}
*/
/*
void
*/