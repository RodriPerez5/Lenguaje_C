/*
Escriba un programa que
  a. Genere un vector con valores aleatorios enteros.
  b. Recorra el vector y guarde el promedio de los valores en una variable.
  c. Encuentre el menor de los elementos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 int main() {
   //***************************************************************************
   //a.
   //***************************************************************************
   int Cantidad, Contador;
   int SegundosDelSistema = time(NULL);
   srand(SegundosDelSistema);
   printf("Ingrese el tamaño del vetor: ");
   scanf("%d", &Cantidad);
   printf("Su vector aleatorio es:  ");
   int NumerosAleatorios[Cantidad];
   for ( Contador=1; Contador<=Cantidad; Contador++) {
        NumerosAleatorios[Contador] = rand()% 500000;
       printf("%d ", NumerosAleatorios[Contador]);
   }

   //***************************************************************************
   //b.
   //***************************************************************************
   int Sum;
   for ( Contador=1; Contador<=Cantidad; Contador++) {
       Sum+=NumerosAleatorios[Contador];
   }
   float Promedio=(float)(Sum/Cantidad);
   printf("\nEl valor promedio es: %f\n", Promedio);

   //***************************************************************************
   //c.
   //***************************************************************************
   int MenorValor=NumerosAleatorios[1], Valor;
   for ( Contador=1; Contador<=Cantidad; Contador++) {
       Valor=NumerosAleatorios[Contador];
       if (Valor<MenorValor) {
         MenorValor=Valor;
       }
   }
   printf("El menor elemento es: %d\n ", MenorValor);



   return 0;
 }


















//
