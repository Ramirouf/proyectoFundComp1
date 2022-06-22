/*
Header file to get product from csv file
It receives a product's id and a pointer to an empty product struct,
     and returns that product struct with values
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define productsLocation "../db/products.txt"

struct Product{
  int id;
  char name[50];
  double price;
};

// Function to get product from csv file

Product *getProductById(int id, Product *product){
  FILE *file = fopen(productsLocation, "r"); //"r" means read-mode
  if (file == NULL){
    printf("Error opening file.\n");
    return 1;
  }
  char line[100];
  while (fgets(line, sizeof(100), file) != NULL) {
    if (strstr(line, "id") != NULL){
      continue;
    }
    char *token = strtok(line, ",");
    int i = 0;
    while (token != NULL){
      if (i == 0){
        printf("%s", token);
        product->id = atoi(token);
      }
      else if (i == 1){
        strcpy(product->name, token);
      }
      else if (i == 2){
        product->price = atoi(token);
      }
      return product;
    }
  }

  /*
  struct ConfigTicket{
    char businessName[CONFIG_TICKET_NAME_LENGTH];
    char address[CONFIG_TICKET_ADDRESS_LENGTH];
    char phone[CONFIG_TICKET_PHONE_LENGTH];
    char postalCode[CONFIG_TICKET_CP_LENGTH];
    char cuit[CONFIG_TICKET_CUIT_LENGTH];
    char messageGB[CONFIG_TICKET_GB_LENGTH];
  };
  */

  /*
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

  */