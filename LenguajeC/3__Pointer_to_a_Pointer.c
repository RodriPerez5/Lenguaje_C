#include <stdio.h>

int main () {

   int  var;
   int  *ptr;
   int  **pptr;//Pointer to the Pointer

   var = 3000;

   /* take the address of var */
   ptr = &var;

   /* take the address of ptr using address of operator & */
   pptr = &ptr;

   /* take the value using pptr */
   printf("Value of var =                %d\n", var );
   printf("Addrees of var =              %p\n", &var );
   printf("\n");
   printf("Value available at *ptr =     %d\n", *ptr );
   printf("Address available at *ptr =   %p\n",  ptr );/////Porque me tira la misma dirección que la direción de var??????????????????????????
   printf("\n");
   printf("Value available at **pptr =   %d\n", **pptr );
   printf("Address available at **pptr = %p\n",  *pptr );///Porque me tira la misma dirección que la direción de ptr??????????????????????????

   return 0;
}
