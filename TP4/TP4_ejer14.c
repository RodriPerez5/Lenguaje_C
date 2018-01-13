/*
La Sucesión de Fibonacci viene dada por las siguientes ecuaciones:
    F(n) =F(n−1) + F(n−2)
    F(0) =1
    F(1) =1
Escriba una función recursiva que reciba como argumento un entero n, y que calcule la sucesión hasta el valor F(n).
*/

//     gcc TP4_ejer14.c

#include <stdio.h>

long int Fibonacci( int i ) { //NOTA: T0DO ESTE PROGRAMA ES MUY INEFICIENTE, Y MIENTRAS MÁS GRANDE ES EL NÚMERO..
   if( i==0 ) {               //..DE LA SERIE, SE DEMORA CADA VEZ MÁS.
      return 0;
   }
   if( i==1 ) {
      return 1;
   }
   return Fibonacci(i-1) + Fibonacci(i-2);
}

void calc_fibonacci( int n) {
  for ( int i=0; i<=n; i++) {
    printf(" %ld\n", Fibonacci(i) );
  }
}

int main() {
  int n;
  printf("Ingrese un argumento entero: ");
  scanf("%d", &n);
  calc_fibonacci( n );
  printf("\n");
  return 0;
}














//
