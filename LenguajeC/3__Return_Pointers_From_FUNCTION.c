/*
  The following function which will generate 7 random numbers and return them using an array name which
represents a pointer, i.e., address of first array element.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int * conseguirRandom( ) {
   static int r[7];//it isn't a good idea to return the address of a local variable outside the function, so you would have to define the local variable as static variable.
   srand( (unsigned)time(NULL) );
   for (int i=0 ; i<7 ; ++i) {
      r[i] = rand()% 1000;
      printf("r[%d]= %d\n", i, r[i] );
   }
   return r;//Retorna la ADDRESS DEL PRIMER ELEMENTO del array r, es decir, Retorna el Valor de un Pointer!
}




int main () {
   int *p;         //
   p = conseguirRandom();//Es lo mismo que poner: int *p=conseguirRandom();
   for (int i=0 ; i<7 ; i++ ) {
      printf("*(p + [%d]) : %d\n", i, *(p + i) );//SI EN LUGAR DE PONER: *(p + i) , SOLO PUSIÉRAMOS: *p , ENTONCES SIEMPRE SE IMPRIMIRÍA SOLO EL PRIMER NÚMERO ALEATORIO!
   }
   return 0;
}














//
