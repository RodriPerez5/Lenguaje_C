/*
Escribir un programa que permita ingresar por teclado un valor inicial a, un valor final b, y
un número c, y que cuente la cantidad de números divisibles por c que hay en el rango
[a,b].
*/

#include <stdio.h>

 int main() {
    int a, b, c, Entero, CantNumDivisiblesPorC;
    printf("Ingrese un intervalo de números enteros de la forma [a,b] : ");
    // scanf("[%d,%d]\n", &a, &b);
    scanf("[%d,%d]", &a, &b);
    printf("Ingrese un número c entero para saber cuantos valores del intervalo [a,b] son divisibles por él: \n    c=");
    scanf("%d", &c);
    CantNumDivisiblesPorC=0;
    for (Entero=a; Entero<(b+1); Entero++) {
        if (Entero % c == 0) { ///IMPORTANTE COMANDO PARA PODER RESOLVER EL EJER: (Entero % c == 0)
          CantNumDivisiblesPorC++;
        }
    }
    printf("La cantidad de números divisibles por %d en el intervalo [%d,%d], es: %d\n", c, a, b, CantNumDivisiblesPorC);
           //El \n ES PARA QUE CUANDO LO CORRAMOS, NO NOS APAREZCA EL SÍMBOLO: % MOLESTANDO A LOS OJOS EN EL FINAL DEL PROGRAMA.
   return 0;
 }
