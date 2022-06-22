#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../components/GetProduct.h"
//#define productsLocation "../db/products.txt"
/*
Crear un puntero a producto en main y en el header
Se pasa un id y devuelve un puntero al producto creado en el header
*/

int main()
{

    Product product;

    product = getProductById(8);

    printf("id: %d , name: %s , price: %.2f \n", product.id, product.name, product.price);

    return 0;
}

/*

    FILE *file = fopen(productsLocation, "r"); //"r" means read-mode
    if (file == NULL)
    {
        printf("Error opening file.\n");
    }
    char line[100];
    int read = 0;
    int idSearched = 7;
    int found = 0;
    do
    {
        // fscanf returns the amount of values red from the file
        read = fscanf(file,
                      "%d,%49[^,],%lf\n",
                      &product.id,
                      product.name,
                      &product.price);
        if (read == 3)
        {
        }
        if (product1.id == idSearched)
            found = 1;
        // printf("Successfull read");
        if (ferror(file))
        {
            printf("Error reading file.\n");
        }
        if (found)
        {
            break;
        }
    } while (!feof(file)); // Continue until end of file is reached

    printf("id: %d , name: %s , price: %.2f \n", product.id, product.name, product.price);

    fclose(file);

*/