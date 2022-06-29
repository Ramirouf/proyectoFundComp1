#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Funciones para manipular los productos

void PrintListProducts()
{
  // printf("Selecciona un producto: \n\n");
  printf("\tSELECCIONA UN PRODUCTO \n\n");
  struct ListProducts *product = pListProducts;
  int column_width_id = 8;
  int column_width_name = 21;
  int column_width_price = 15;
  char formaterString[15];

  // Header de la lista de productos
  PrintItemTable("ID", column_width_id);
  PrintItemTable("Nombre", column_width_name);
  PrintItemTable("Precio U.", column_width_price);
  printf("\n");
  // Separador de la lista de productos
  PrintItemTable("----", column_width_id);
  PrintItemTable("---------", column_width_name);
  PrintItemTable("---------", column_width_price);
  printf("\n");

  while (product != NULL)
  {
    PrintItemTable(IntToString(product->itemInfo.idItem), column_width_id);
    PrintItemTable(product->itemInfo.name, column_width_name);
    // PrintItemTable(FloatToString(product->itemInfo.price), column_width_price);
    sprintf(formaterString, "$%.2f", product->itemInfo.price);
    PrintItemTable(formaterString, column_width_price);
    printf("\n");
    product = product->next;
  }
  printf("\n");
}

// infoProduct es cada linea del archivo de productos y con strtok se separa por comas y se guarda en un string
void AddProduct(char *infoProduct)
{
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
  newProduct->itemInfo.price = atof(token);
  // printf("price: %.2lf\n", newProduct->itemInfo.price);

  // Agregar a la lista de productos
  if (pListProducts == NULL)
  {
    pListProducts = newProduct;
    newProduct->next = NULL;
  }
  else
  {
    newProduct->next = pListProducts;
    pListProducts = newProduct;
  }
}

void SetListProducts()
{
  FILE *fp;
  char *line = NULL;
  size_t len = 0;
  size_t read;

  char *filename = "./public/products.txt";
  char *mode = "r";
  fp = fopen(filename, mode);
  if (fp == NULL)
    exit(EXIT_FAILURE);

  while ((read = getline(&line, &len, fp)) != -1)
  {
    // printf("%s", line);
    AddProduct(line);
  }

  fclose(fp);
}
