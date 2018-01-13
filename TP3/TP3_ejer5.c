/*
Escribir un programa que resuelva los valores resultantes a las siguientes funciones
multivariables. Considere las variables como valores enteros que se le piden al usuario:
                                  x = f(a,b,c,d,e) = (3.a+b)/(c-((d+5.e)/(a-b)))
                                  y = f(a,b,c) = 3.a^4-5.b^3+c.12-7

*/

#include <stdio.h>
#include <math.h>//AL AGREGAR UNA NUEVA LIBRERÍA HAY QUE volver a COMPILAR AGRAGANDO AL FINAL: -lm   !!!

  int main() {
    int a,b,c,d,e;
   printf("Ingrese cinco números enteros:\n");
   printf("a=");
   scanf("%d", &a);
   printf("b=");
   scanf("%d", &b);
   printf("c=");
   scanf("%d", &c);
   printf("d=");
   scanf("%d", &d);
   printf("e=");
   scanf("%d", &e);
   printf("\n");
   printf("Los números ingresados son:  a=%d b=%d c=%d d=%d e=%d\n", a,b,c,d,e);
   printf("\n");

  float x;
  x = (float)(3*a+b)/(c-((d+5*e)/(a-b)));
  printf("El valor de la función x es: %f", x);
  float y;
  y = 3*pow(a,4)-5*pow(b,3)+c*12-7;
  printf("El valor de la función y es: %f", y);

  return 0;
}







// #include <stdio.h>
// #include <math.h>
//
// float funcionX() {
//   float a, b, c, d, e;
//   printf("X(a,b,c,d,e) -> ingrese a, b, c, d, e\n");
//   scanf("%f%f%f%f%f", &a, &b, &c, &d, &e);
//   float resultado = ((3 * a) + b)/(c - ((d + 5 * e)/(a - b)));
//   return resultado;
// }
// float funcionY() {
//   float a, b, c;
//   printf("Y(a,b,c) -> ingrese a, b, c\n");
//   scanf("%f%f%f", &a, &b, &c);
//   float resultado = 3 * pow( a, 4) - 5*pow( b, 3) + pow( c, 12) -7;
//   return resultado;
// }
//
// int main(int argc, char const *argv[]) {
//   float X = funcionX();
//   float Y = funcionY();
//
//   printf("X=%f\n", X);
//   printf("Y=%f\n", Y);
//
//   return 0;
// }
