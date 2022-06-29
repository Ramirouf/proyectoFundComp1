#include <stdio.h>

#define CONFIG_TICKET_NAME_LENGTH 21
#define CONFIG_TICKET_ADDRESS_LENGTH 51
#define CONFIG_TICKET_PHONE_LENGTH 21
#define CONFIG_TICKET_CP_LENGTH 51
#define CONFIG_TICKET_CUIT_LENGTH 12
#define CONFIG_TICKET_RES_IVA_LENGTH 26
#define CONFIG_TICKET_GB_LENGTH 31

#define ITEM_NAME_LENGTH 41

#define TICKET_DATE_LENGTH 11 // dd/mm/yyyy (10) mas el \0 (11 )
#define TICKET_TIME_LENGTH 9  // hh:mm:ss (8) mas el \0 (9)

#define CANT_PRODUCTS 10

struct ConfigTicket{
  char businessName[CONFIG_TICKET_NAME_LENGTH];
  char address[CONFIG_TICKET_ADDRESS_LENGTH];
  char phone[CONFIG_TICKET_PHONE_LENGTH];
  char postalCode[CONFIG_TICKET_CP_LENGTH];
  char cuit[CONFIG_TICKET_CUIT_LENGTH];
  char resIVA[CONFIG_TICKET_RES_IVA_LENGTH];
  char messageGB[CONFIG_TICKET_GB_LENGTH];
};

// Estructura de los Productos
struct Item{
  int idItem;
  char name[ITEM_NAME_LENGTH];
  double price;
};

// Estructura de los Productos del Ticket
struct ItemTicket{
  float quantity;
  struct Item *itemInfo;
  struct ItemTicket *next;
};

// Estructura de arbol aVL
struct Ticket{
  int id;
  char date[TICKET_DATE_LENGTH];
  char time[TICKET_TIME_LENGTH];
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
int id_tickets = 1;

// Bandera para configurar el Ticket
// 0: No se configuro el Ticket
// 1: Se configuro el Ticket
int setTicket = 0;