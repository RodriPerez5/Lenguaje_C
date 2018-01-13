/*
   #define is a C-directive which is also used to define the aliases for various data types similar to..
..typedef but with the following differences:
      - typedef is limited to giving symbolic names to types only, where #define can be used to define alias..
    ..for values as well, eg. you can define 1 as ONE.
      - typedef interpretation is performed by the compiler whereas #define statements are processed by the pre-processor.

The following example shows how to use #define in a program −
           ''definimos TRUEEE y FALSEEE para guardar valores lógicos true/false, algo que no existe en C:''
*/

#include <stdio.h>

#define TRUEEE  1
#define FALSEEE 0

int main( ) {
   printf( " Value of TRUE: %d\n", TRUEEE);
   printf( " Value of FALSE: %d\n", FALSEEE);

   return 0;
}

/*
When the above code is compiled and executed, it produces the following result −

Value of TRUE: 1
Value of FALSE: 0
*/














//
