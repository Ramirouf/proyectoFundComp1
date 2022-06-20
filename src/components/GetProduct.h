/*
Header file to get product from text file
It receives a product's id and a pointer to an empty product struct,
     and returns that product struct with values
*/

#define productsLocation "../db/products.txt"

typedef struct nodo
{
    int dato;
    struct nodo *siguiente;
} nodo;

nodo *primero = NULL;
nodo *ultimo = NULL;