/*
Escriba un programa que lea por teclado 3 coeficientes a, b y c, un valor inicial x1, un valor
final x2 y un un incremento delta Δx, y que calcule p(x) utilizando la función que se muestra a
continuación, en el intervalo [x1, x2], según el incremento delta. Muestre los valores
calculados por pantalla.
                                p(x) = a*x^2 + b*x + c
*/

//  gcc -lm TP3_ejer12.c

#include <stdio.h>
#include <math.h>

int main() {
  float a, b, c, x1, x2, Delta, x, p;

  printf("Ingrese las tres constantes a, b y c: \n   a= ");
  scanf("%f", &a);
  printf("   b= ");
  scanf("%f", &b);
  printf("   c= ");
  scanf("%f", &c);
  printf("Ingrese los valores extremos [x1,x2]: \n   x1= ");
  scanf("%f", &x1);
  printf("   x2= ");
  scanf("%f", &x2);
  printf("Ingrese el incremento Delta: \n   Delta= ");
  scanf("%f", &Delta);

  // int TamanioVector = (x2-x1)/Delta;
  // float p[TamanioVector];
  for ( x=x1; x<=x2; x+=Delta) {
      p = a*pow(x,2) + b*x + c;
      printf("P(%f) es: %f\n", x, p);
  }
  return 0;
}



// #include <stdio.h>
// #include <math.h>
//
// float calcular(float a, float b, float c, float i) {
//   float p = a*pow(i,2) + b*i + c;
//   return p;
// }
//
// int main(int argc, char const *argv[]) {
//   float a, b, c, x1, x2, delta;
//   printf("Ingrese a:");
//   scanf("%f", &a);
//   printf("Ingrese b:");
//   scanf("%f", &b);
//   printf("Ingrese c:");
//   scanf("%f", &c);
//   printf("Ingrese x1:");
//   scanf("%f", &x1);
//   printf("Ingrese x2:");
//   scanf("%f", &x2);
//   printf("Ingrese delta:");
//   scanf("%f", &delta);
//   int count = round((x2 - x1) / delta) + 1;
//   float entrada = x1;
//   float P;
//   for (size_t i = 0; i < count; i++) {
//     P = calcular(a, b, c, entrada);
//     printf("P(%f) es: %f\n",entrada, P);
//     entrada += delta;
//   }
//
//   return 0;
// }
