/*
Pointers may be compared by using relational operators, such as ==, <, and >
If p1 and p2 point to variables that are related to each other, such as elements of the same array, then p1 and p2 can be meaningfully compared.
*/

#include <stdio.h>
int MAX = 3;

int main () {

   int  Matriz[] = {10, 100, 200};
   int  i=0, *ptr;

   /* let us have address of the first element in pointer */
   ptr = Matriz;

   while ( ptr <= &Matriz[MAX - 1] ) { ///(La condición es hasta que el valor del pointer sea el de la Dirección del Último Casillero de la Matriz

      printf("Address of Matriz[%d] = %x\n", i, ptr );
      printf("Value of Matriz[%d] = %d\n", i, *ptr );

      /* point to the next location */
      ptr++;

      i++;
   }

   return 0;
}
