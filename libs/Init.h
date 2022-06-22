#include <stdio.h>


#define CONFIG_TICKET_NAME_LENGTH 20
#define CONFIG_TICKET_ADDRESS_LENGTH 50
#define CONFIG_TICKET_PHONE_LENGTH 20
#define CONFIG_TICKET_CP_LENGTH 50
#define CONFIG_TICKET_CUIT_LENGTH 11
#define CONFIG_TICKET_GB_LENGTH 20

#define TICKET_DATE_LENGTH 11 // dd/mm/yyyy (10) mas el \0 (11 )
#define TICKET_TIME_LENGTH 9 // hh:mm:ss (8) mas el \0 (9)

#define CANT_PRODUCTS 10

struct ConfigTicket{
  char businessName[CONFIG_TICKET_NAME_LENGTH];
  char address[CONFIG_TICKET_ADDRESS_LENGTH];
  char phone[CONFIG_TICKET_PHONE_LENGTH];
  char postalCode[CONFIG_TICKET_CP_LENGTH];
  char cuit[CONFIG_TICKET_CUIT_LENGTH];
  char messageGB[CONFIG_TICKET_GB_LENGTH];
};

struct Item{
  char *name;
  char *unit;
  double price;
};

struct ItemTicket{
  int quantity;
  struct Item *itemInfo;
  struct ItemTicket *next;
};

struct Ticket{
  char *date;
  char *time;
  char *resIVA;
  char *leyenda;
  struct ItemTicket *itemTicket;
};

struct TicketTree{
  unsigned int id;
  struct Ticket ticket;
  struct TicketTree *left;
  struct TicketTree *right;
};

// Inicializacion de variables globales y estructuras
struct TicketTree *pTicketTree = NULL;
struct ItemTicket *pAuxItemTicket = NULL;
unsigned int id_tickets = 1;


// Productos para ser usados en el ticket en forma de vector
struct Item products[CANT_PRODUCTS] = {
  {"Fideo", "c/u", 9.99},
  {"Sal", "c/u", 150},
  {"Caldo de pollo", "c/u", 60},
  {"Mayonesa", "c/u", 550},
  {"Pure de tomate", "c/u", 114.5},
  {"Pollo", "kg", 100},
  {"Queso", "kg", 120.2},
  {"Tomate", "kg", 99.9},
   {"Muslo", "kg", 150},
  {"Lechuga", "kg", 100.3}
};
