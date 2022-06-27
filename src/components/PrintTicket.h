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
typedef struct Item
{
    int idItem;
    char *name;
    double price;
} Item;

// Estructura de los Productos del Ticket
typedef struct ItemTicket
{
    float quantity;
    struct Item itemInfo;
    struct ItemTicket *next;
} ItemTicket;

// Estructura de arbol AVL
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

void printTicket(Ticket *ticket)
{
    double total = 0, productTotal = 0;
    /*
    Config config;

    printf("%s", config.businessName);
    printf("%s", config.address);
    printf("%s", config.phone);
    printf("%s", config.postalCode);
    printf("%s\n", config.cuit);
    */
    printf("**************************\n");
    printf("----------TICKET----------\n");
    printf("**************************\n");
    printf("ID del ticket: %d\n", ticket->id);
    printf("Descripcion\t\tCantidad\t\tPrecio Unitario\t\tPrecio\n");

    // printf("Cantidad: %f", ticket.ProductsTicket->quantity);

    // Show products
    // For that, we need to range over the products
    // We create a new ticket, to not change the original one
    Ticket *ticketSearch = ticket;
    // POR QUE NO APARECE PRINTTICKETTEST.C ??????
    do
    {
        printf("Codigo producto: %d\n", ticketSearch->ProductsTicket->itemInfo.idItem);
        printf("Nombre: %s\n", ticketSearch->ProductsTicket->itemInfo.name);
        printf("Precio unitario: $ %.2f\n", ticketSearch->ProductsTicket->itemInfo.price);
        printf("Cantidad: %.2f\n", ticketSearch->ProductsTicket->quantity);
        ticketSearch->ProductsTicket = ticketSearch->ProductsTicket->next;
        productTotal = ticketSearch->ProductsTicket->itemInfo.price * ticketSearch->ProductsTicket->quantity;
        printf("Valor: %.2f\n", productTotal);
        total += productTotal;
    } while (ticketSearch->ProductsTicket->next);

    // Print the total
    printf("TOTAL\t\t\t\t\t\t\t\t\t %lf\n", total);

    // Saludo
    // printf("%s", config.messageGB);
}