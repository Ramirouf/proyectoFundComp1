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

// Estructura de los Productos
struct Item{
  int idItem;
  char *name;
  double price;
};

// Estructura de los Productos del Ticket
struct ItemTicket{
  float quantity;
  struct Item itemInfo;
  struct ItemTicket *next;
};

// Estructura de arbol aVL
struct Ticket{
  int id;
  char *date;
  char *time;
  char *resIVA;
  struct ItemTicket *ProductsTicket;
  struct Ticket *left;
  struct Ticket *right;
  int height;
};

struct ListProducts{
  struct Item itemInfo;
  struct ListProducts *next;
};

// Inicializacion de variables globales y estructuras
struct Ticket *pTicketTree = NULL;
struct ItemTicket *pAuxItemTicket = NULL;
struct ListProducts *pListProducts = NULL;
unsigned int id_tickets = 1;




// struct Item{
//   int id;
//   char name[50];
//   // char unit;
//   double price;
// };

// struct ItemTicket{
//   int quantity;
//   struct Item *itemInfo;
//   struct ItemTicket *next;
// };

// struct Ticket{
//   char *date;
//   char *time;
//   char *resIVA;
//   struct ItemTicket *itemTicket;
// };

// struct TicketTree{
//   unsigned int id;
//   struct Ticket ticket;
//   struct TicketTree *left;
//   struct TicketTree *right;
// };
