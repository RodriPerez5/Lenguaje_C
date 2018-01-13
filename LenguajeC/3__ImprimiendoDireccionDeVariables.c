#include <stdio.h>

int main () {

   int  var1;
   float var2;
   char var3[10];

   printf("Address of var1 variable: %x\n", &var1  );  //
   printf("Address of var2 variable: %x\n", &var2  );  // %x (un entero sin signo en notación de base hexadecimal)
   printf("Address of var3 variable: %x\n", &var3  );  //

   return 0;
}
