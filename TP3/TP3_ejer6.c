/*
Escribir un programa que le pida al usuario una fecha del estilo DD/MM/AAAA y determine:
     a. El día anterior y posterior.
     b. El último día del mes y cuantos días faltan para el mismo.
Considere la existencia de los años bisiestos.
*/

#include <stdio.h>

int main() {
  int D, M, A;
  printf("Ingrese una fecha:  ");
  scanf("%d/%d/%d", &D, &M, &A);
  printf("Su fecha ingresada es: %d/%d/%d \n", D, M, A);


  int UltimoDia;
  if (M==1||M==3||M==5||M==7||M==8||M==10||M==12) {
    UltimoDia=31;
  }
  if (M==4||M==6||M==9||M==11) {
    UltimoDia=30;
  }
  int Vec[10];
  // for (size_t i = 1; i < 11; i++) {
  //   Vec[];
  // }
  // if (A==pow(4,n)) {
  //   /* code11 */
  // }
  //
  //
  // }
  //
  // int Danterior=D-1;
  // printf("El día anterior es: %d/%d/%d \n", Danterior, M, A);
  // int Dposterior=D+1;
  // printf("El día anterior es: %d/%d/%d \n", Dposterior, M, A);


return 0;
}



//Hacer también con:  if (anio % 4==0)
//Esta condición dice que si anio al dividirlo por 4 da resto cero, entonces que entre.
















//
