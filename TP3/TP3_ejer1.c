// Escribir un programa que pida 3 números por pantalla e identifique cual es el valor central,
// si es posible. Ej. a es central si y solo si b > a > c.

#include <stdio.h>// Librería básica para entrada y salida

int main() {
  printf("Ingrese 3 números naturales\n");
  int a,b,c;
  scanf("%d%d%d", &a, &b, &c );          ////The symbol & ("AMPERSAND") returns the actual address of the variable.
  if ((b<a && a<c) || (c<a && a<b)) {
    printf("%d es el valor central\n", a);
  }else if ((a<b && b<c) || (c<b && b<a)) {
    printf("%d es el valor central\n", b);
  }else if ((b<c && c<a) || (a<c && c<b)) {
    printf("%d es el valor central\n", c);
  }else
    printf("No se pudo encontrar el valor central\n");

  return 0;
}
