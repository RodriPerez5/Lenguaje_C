/*
Escribir un programa que calcule la siguiente ecuación:
∑i=0-->100 ∑j=0-->100  [ (i*j)/(i+j) ]         ∀  i,j / (i y j son números pares)
*/

#include <stdio.h>
 int main() {

   short int i, j;
   float Ecuacion=0;
   for ( i=0 ; i<=100 ; i++ ) {
      for ( j=0 ; j<=100 ; j++) {
        if ( (i+j)!=0 ) {
          if (  (i % 2 == 0)  &&  (j % 2 == 0)  ) {
            Ecuacion+=((float)(i*j)/(i+j));//OJO con los paréntesis!-->Si hacemos: Ecuacion+=(float)((i*j)/(i+j)); No toma el (float)!
          }
        }
     }
   }
   printf ("El resultado de la Ecuación es: %f\n", Ecuacion);

   return 0;
 }
