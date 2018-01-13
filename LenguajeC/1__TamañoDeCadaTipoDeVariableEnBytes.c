/*
      COMANDO:   sizeof()
*/



// #include <stdio.h>
// #include <limits.h>
//
// int main() {
//
//    printf("Storage size for int : %d \n", sizeof(int)); //The expressions sizeof(type) yields the storage size of the object or type, in bytes.
//
//    return 0;
// }






#include <stdio.h>
#include <float.h>//The header file float.h defines macros that allow you to use these values and other details about the binary representation of real numbers in your programs.
                  //(Nota: no existen librerias para otro tipo de variable, solo para el float)
int main() {

   printf("Storage size for float: %d \n", sizeof(float));
   printf("Minimum float positive value: %E\n", FLT_MIN );
   printf("Maximum float positive value: %E\n", FLT_MAX );
   printf("Precision value: %d\n", FLT_DIG );

   return 0;
}
