#include <stdio.h>
int main(){
  char grupo;
  printf("Ingrese grupo sanguíneo\n");
  scanf("%c", &grupo );

  switch(grupo) {
  case 'a' :
  case 'A' :
  printf("Grupo A" );
  break;
  case 'b' :
  case 'B' :
  printf("Grupo B" );
  break;
  case 'o' :
  case 'O' :
  printf("Grupo O" );
  break;
  default :
  printf("Grupo desconocido\n" );
  }

return 0;
}
