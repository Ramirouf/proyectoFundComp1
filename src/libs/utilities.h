#include <stdio.h>
#include <stdlib.h>

void SeparateCross(int cant)
{
  for (int i = 1; i < cant; i++)
    printf("*");
  printf("\n");
}

void SeparateLine(int cant)
{
  if (cant == 0)
    cant = 25;

  for (int i = 1; i < cant; i++)
    printf("-");
  printf("\n");
}

void PrintMessage(char *message, char *type)
{
  printf("\n");
  SeparateLine(0);
  printf("%s: %s\n", type, message);
  SeparateLine(0);
  printf("\n");
}

void MenuTitle(char *title)
{
  // https://misc.flogisoft.com/bash/tip_colors_and_formatting
  printf("%s\n", title);
}

void PrintInTheMiddle(char *message, int cant)
{
}

// New things, coming from another files
// This comes from methods-tree.h
char *DoubleToString(double number)
{
  char *string = malloc(sizeof(char) * 10);
  sprintf(string, "%.2lf", number);
  return string;
}

void PrintManyTimes(char *string, int times)
{
  int i;
  for (i = 0; i < times; i++)
  {
    printf("%s", string);
  }
}

// This comes from Products.h"

// La funcion IntToString que convierte un entero a un string y lo devuelve
char *IntToString(int number)
{
  char *string = malloc(sizeof(char) * 10);
  sprintf(string, "%d", number);
  return string;
}

// La funcion FloatToString que convierte un float a un string y lo devuelve
char *FloatToString(float number)
{
  char *string = malloc(sizeof(char) * 10);
  sprintf(string, "%.2f", number);
  return string;
}
