/*
Escribir un programa que calcule la siguiente ecuación:
∑i=0-->100 ∑j=0-->100  [ (i+j)/(i−j) ]         ∀  i,j / (i−j) ≠ 0
*/

#include <stdio.h>

int main() {
  short int i, j;
  float Ecuacion=0;
  for ( i=0 ; i<=100 ; i++ ) {
      for ( j=0 ; j<=100 ; j++) {
          if ( (i-j)!=0 ) {
             Ecuacion+=(float)((i+j)/(i-j));//Es lo mismo que hacer: Ecuacion=(float)(Ecuacion+((i+j)/(i-j)));
          }
      }
  }
  printf ("El resultado de la Ecuación es: %f\n", Ecuacion);
  //Da como resultado cero, y está bien
  return 0;
}
