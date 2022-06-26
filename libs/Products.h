#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void PrintListProducts(){
  printf("LISTA DE PRODUCTOS\n");
  struct ListProducts *product = pListProducts;
  while (product != NULL){
    printf("%d. %s  $%.2lf\n", product->itemInfo.idItem, product->itemInfo.name, product->itemInfo.price);
    product = product->next;
  }
  printf("\n");
}

// infoProduct es cada linea del archivo de productos y con strtok se separa por comas y se guarda en un string
void AddProduct(char *infoProduct){
  struct ListProducts *newProduct;
  newProduct = malloc(sizeof(struct ListProducts));

  // id
  char *token = strtok(infoProduct, ",");
  newProduct->itemInfo.idItem = atoi(token);
  // name
  token = strtok(NULL, ",");
  strcpy(newProduct->itemInfo.name, token);
  // printf("name: %s\n", newProduct->itemInfo.name);
  // price
  token = strtok(NULL, ",");
  sscanf(token, "%lf", &newProduct->itemInfo.price);
  // printf("price: %.2lf\n", newProduct->itemInfo.price);

  // Agregar a la lista de productos
  if (pListProducts == NULL){
    pListProducts = newProduct;
    newProduct->next = NULL;
  } else{
    newProduct->next = pListProducts;
    pListProducts = newProduct;
  }
}

void SetListProducts(){
  FILE *fp;
  char *line = NULL;
  size_t len = 0;
  size_t read;

  char *filename = "./public/products.txt";
  char *mode = "r";
  fp = fopen(filename, mode);
  if (fp == NULL)
    exit(EXIT_FAILURE);

  while ((read = getline(&line, &len, fp)) != -1){
    // printf("%s", line);
    AddProduct(line);
  }

  free(line);
  fclose(fp);
}
