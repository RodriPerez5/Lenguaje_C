/*
Escribir un programa que lea 2 números enteros por teclado y que calcule:
          a. el número que contiene sólo los bits que son 1 en ambos números
          b. el número que contiene los bits que son 1 en alguno de los números
*/

#include <stdio.h>
int main() {
  int n1,n2;
  printf("Ingrese dos números enteros:\n");
  scanf("%d%d", &n1, &n2);
  int A = n1 & n2;
  int B = n1 | n2;
  printf("El número(en base decimal) formado (en binario) con unos en los bits que son 1 en Ambos números(en base decimal) es:%d\n", A);
  printf("El número(en base decimal) formado (en binario) con unos en los bits que son 1 en Alguno de los dos números(en base decimal) es:%d\n", B);
  return 0;
}













//
