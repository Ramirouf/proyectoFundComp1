#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <string.h>

// Funciones cortas con utilidades especificas, las cuales se utilizan en todo el sistema

void PrintMessage(char *message, char *type)
{
  printf("\n------------------------\n");
  printf("%s: %s\n", type, message);
  printf("------------------------\n\n");
}

void MenuTitle(char *title)
{
  // Imprime un titulo en formato de menu
  printf("\t%s\n", title);
}

void PrintManyTimes(char *string, int times)
{
  int i;
  for (i = 0; i < times; i++)
  {
    printf("%s", string);
  }
}

// La funcion IntToString convierte un entero a un string y lo devuelve
char *IntToString(int number)
{
  char *string = malloc(sizeof(char) * 10);
  sprintf(string, "%d", number);
  return string;
}

// La funcion FloatToString convierte un float a un string y lo devuelve
char *FloatToString(float number)
{
  char *string = malloc(sizeof(char) * 10);
  sprintf(string, "%.2f", number);
  return string;
}

char *DoubleToString(double number)
{
  char *string = malloc(sizeof(char) * 10);
  sprintf(string, "%.2lf", number);
  return string;
}

// FUNCIONES PARA IMPRIMIR EN FORMA DE TABLAS
void PrintItemTable(char *nameProduct, int widthColumn)
{
  int TEXT_WIDTH = widthColumn - 1; // -1 para el espacio entre el limite del nombre y el final de la columna

  /*
    Ejemplos

    Hola, buenas cómo... | // Esto pasa si la longitud del string es mayor a TEXT_WIDTH
    Hola, buenas!        | // Esto pasa si la longitud del string es manor a TEXT_WITDH
    Hola, buenas buenas! | // Esto pasa si la longitud del string es igual a TEXT_WIDTH
  */

  int lengthText = strlen(nameProduct);
  for (int i = 0; i < widthColumn; i++)
  {
    if ((lengthText > TEXT_WIDTH) && (i >= (TEXT_WIDTH - 3)))
    {
      if (i == TEXT_WIDTH)
        printf(" ");
      else
        printf(".");
    }
    else
    {
      if (i < lengthText)
      {
        printf("%c", nameProduct[i]);
      }
      else
      {
        printf(" ");
      }
    }
  }
}

// Funciones para obtener la fecha y hora, para guardar en el ticket
char *getDate()
{
  char *date = (char *)malloc(sizeof(char) * 11);

  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  // Se suman 1900 porque este valor es el año actual - 1900
  // Se suman 1 porque los valores de meses empiezan en 0 (enero) al 11 (diciembre)
  sprintf(date, "%02d-%02d-%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

  return date;
}

char *getTime()
{
  char *dateTime = (char *)malloc(sizeof(char) * 9);

  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  sprintf(dateTime, "%02d:%02d:%02d", tm.tm_hour, tm.tm_min, tm.tm_sec);

  return dateTime;
}
