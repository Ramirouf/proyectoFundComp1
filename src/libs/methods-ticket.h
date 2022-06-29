#include <stdio.h>
#include <stdlib.h>

// Definir responsabilidad ante el IVA del emisor del ticket
char *IVAResponsability(){
  int option;
  char *responsability[] = {
    "IVA Responsable Inscripto", "IVA no Responsable", "IVA exento",
    "Responsable Monotributo", "Monotributista Social"
  };

  do{
    printf("Responsabilidad frente al impuesto al valor agregado del emisor segun corresponda:\n");
    printf("1. IVA Responsable Inscripto\n");
    printf("2. IVA no Responsable\n");
    printf("3. IVA exento\n");
    printf("4. Responsable Monotributo\n");
    printf("5. Monotributista Social\n");

    printf("Ingrese una opcion: ");
    scanf("%d", &option);

    if (option < 1 || option > 5){
      PrintMessage("Opcion invalida", "Error");
    }
  } while (option < 1 || option > 5);

  return responsability[option - 1];
}