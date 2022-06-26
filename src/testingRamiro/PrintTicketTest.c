#include <stdio.h>
#include <stdlib.h>

#include "../components/PrintTicket.h"

int main()
{

    // Crear lista de productos, y al ticket darle dicha lista
    ItemTicket *ticketItem;
    ticketItem->quantity = 4;
    Item item;
    item.idItem = 4;
    item.name = "Nombre!!!";
    item.price = 14.9;
    ticketItem->itemInfo = item;
    ticketItem->next = NULL;
    // ItemTicket *ticketItem2;
    // struct ItemTicket *ticketItem2 = (struct ItemTicket *)malloc(sizeof(struct ItemTicket));

    // ticketItem->next = ticketItem2;

    // Ticket ticket;

    struct Ticket *ticket = (struct Ticket *)malloc(sizeof(struct Ticket));

    ticket->id = 2;
    ticket->ProductsTicket = ticketItem;

    // ticket->ProductsTicket->quantity = 2;

    // printf("Cantidad: %f", ticket.ProductsTicket.quantity);
    /*
    ticket.ProductsTicket->itemInfo->idItem = 3;
    ticket.ProductsTicket->itemInfo->name = "Nombre";
    ticket.ProductsTicket->itemInfo->price = 10, 5;
    */
    printTicket(ticket);
    return 0;
}