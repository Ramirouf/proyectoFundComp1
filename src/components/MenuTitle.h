#include <stdio.h>

void MenuTitle(char *title){
  // https://misc.flogisoft.com/bash/tip_colors_and_formatting
  printf("\e[34m\e[1m%s\e[0m\e[0m\n", title);
}