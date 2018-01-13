/*
Este algoritmo de ordenamiento no es el más eficiente.
*/

//Ordenamiento de menor a mayor:  
#include <stdio.h>

int main() {

  int Vector[7]={6,5,4,3,2,1,0};//(Peor de los casos)
  int i, a, count=-1, CantIter=0;
  while (count!=0) {//(mientras hayan substituciones)
     count=0;
     for ( i=0; i<7; i++ ) {
       if ( Vector[i]>Vector[i+1] ) {
          a=Vector[i];
          Vector[i]=Vector[i+1];
          Vector[i+1]=a;
          count++;
       }
     }
     CantIter++;
  }
  printf(" Vector= [");
  for( i=0; i<7; i++ ) {
    printf(" %d ", Vector[i]);
  }
  printf("]\n");
  printf("          Cantidad de iteraciones: %d\n", CantIter);

  return 0;
}
/*RESULTADO:

Vector= [ 0  1  2  3  4  5  6 ]
          Cantidad de iteraciones: 7

*/












//
