/*
Escribir un programa que calcule el factorial de un número y muestre el valor por pantalla.
*/

#include <stdio.h>

int main() {
  short int i, n;
  long int Factorial=1;
  printf("Ingrese un número entero para obtener su factorial: \n");
  scanf("%d", &n);
  for (i=1; i<(n+1); i++) {
    Factorial*=i; //Es lo mismo que hacer: Factorial=Factorial*i;
  }
  if (n==0) {
    printf ("El factorial de 0 es: o");
  }
  else
    printf ("El factorial de %d es: %d", n, Factorial);

  return 0;
}
//MEJORAR PARA QUE CALCÚLE BIEN EL FACTORIAL DE NÚMEROS MAYORES QUE 12  MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM




// #include <stdio.h>
// #include <stdlib.h>
//
// int factorial(int);
//
// int main() {
//   int num;
//   printf("Ingrese un entero:");
//   scanf("%d", &num);
//   int facto = factorial(num);
//   printf("El factorial de %d es %d\n", num, facto);
//   return 0;
// }
//
// int factorial(int numero) {
//   if (numero == 0)
//     return 1;
//   else
//     return(numero * factorial(numero - 1));
// }
