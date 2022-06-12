#include <stdio.h>

#define CONFIG_TICKET_NAME_LENGTH 20
#define CONFIG_TICKET_ADDRESS_LENGTH 50
#define CONFIG_TICKET_PHONE_LENGTH 20
#define CONFIG_TICKET_CP_LENGTH 50
#define CONFIG_TICKET_CUIT_LENGTH 11
#define CONFIG_TICKET_GB_LENGTH 20

#define ITEM_INFO_NAME_LENGTH 20
#define ITEM_INFO_UNIT_LENGTH 10

#define TICKET_ID_LENGTH 10
#define TICKET_DATE_LENGTH 8
#define TICKET_TIME_LENGTH 6
#define TICKER_RES_IVA_LENGTH 50
#define TICKET_LEYENDA_LENGTH 50

struct ConfigTicket{
  char businessName[CONFIG_TICKET_NAME_LENGTH]; // Razón social
  char address[CONFIG_TICKET_ADDRESS_LENGTH];
  char phone[CONFIG_TICKET_PHONE_LENGTH];
  char postalCode[CONFIG_TICKET_CP_LENGTH];
  char cuit[CONFIG_TICKET_CUIT_LENGTH];
  char messageGB[CONFIG_TICKET_GB_LENGTH]; // Mensaje de gracias
};

// struct Item{
//   char name[ITEM_INFO_NAME_LENGTH];
//   char unit[ITEM_INFO_UNIT_LENGTH];
//   float price;
// };

// struct ItemTicket{
//   struct Item itemInfo;
//   int quantity;
//   char id[TICKET_ID_LENGTH];
// };

// struct Ticket{
//   char id[TICKET_ID_LENGTH];
//   char date[TICKET_DATE_LENGTH];
//   char time[TICKET_TIME_LENGTH];
//   char resIVA[TICKER_RES_IVA_LENGTH];
//   char leyenda[TICKET_LEYENDA_LENGTH];
//   struct ConfigTicket configT;
// };
