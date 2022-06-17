void SeparateCross(int cant){
  for (int i = 1; i < cant; i++) printf("*");
  printf("\n");
}

void SeparateLine(int cant){
  if (cant == 0) cant = 25;

  for (int i = 1; i < cant; i++) printf("-");
  printf("\n");
}

void PrintMessageError(char *message, char *type){
  printf("\n");
  SeparateLine(0);
  printf("%s: %s\n", type, message);
  SeparateLine(0);
  printf("\n");
}

void MenuTitle(char *title){
  // https://misc.flogisoft.com/bash/tip_colors_and_formatting
  printf("%s\n", title);
}

void PrintInTheMiddle(char *message, int cant){

}