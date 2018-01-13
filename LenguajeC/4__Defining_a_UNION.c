/*
A UNION (in contrast to a STRUCTURE) is a special data type available in C that allows to store different data types in the..
..same memory location.
Unions provide an efficient way of using the same memory location for multiple-purpose.

The memory occupied by a union will be large enough to hold the largest member of the union.
  For example, in the following example, Data type will occupy 20 bytes of memory space because this is the maximum space which can be
occupied by a character string:
*/

#include <stdio.h>
//#include <string.h>

union Data {
   int i;
   float f;
   char str[20];
};

int main( ) {

   union Data datos;//You would use the keyword union to define variables of union type.

   printf("\n Memory size occupied by datos: %li\n\n", sizeof(datos));

   return 0;
}





/*
When the above code is compiled and executed, it produces the following result −

 Memory size occupied by datos: 20

*/


















//
