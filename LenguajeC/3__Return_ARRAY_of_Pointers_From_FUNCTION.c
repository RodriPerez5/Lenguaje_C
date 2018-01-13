/*
  C programming does not allow to return an entire array as an argument to a function. However, you can return a
pointer to an array by specifying the array's name without an index.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* function to generate and return random numbers */
int * getRandom() {

   static int r[10]; //NO CORRE SI NO PONEMOS EL static  //C doesn't advocate to return the address of a local variable to outside of the function, so you would have to define the local variable as static variable.

   /* set the seed */
   srand( (unsigned)time(NULL) ); //(Esta ES OTRA FORMA de definir el srand con los seg del sistema del time(NULL))

   for (int i=0; i<10; ++i ) {
      r[i] = rand();
      printf( "r[%d] = %d\n", i, r[i]);
   }

   return r;
}





/* main function to call above defined function */
int main () {

   /* a pointer to an int */
  int *p = getRandom(); ///////Es lo mismo que poner en dos líneas:    int *p;     p=getRandom();

   for (int i=0; i<10; i++ ) {
      printf( "*(p + %d) : %d\n", i, *(p+i) );
   }

   return 0;
}












//
