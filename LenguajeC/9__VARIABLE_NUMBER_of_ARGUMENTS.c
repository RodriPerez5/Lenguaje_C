
#include <stdio.h>
#include <stdarg.h>// Para incluir el tipo de variable:  va_list       Y los macros:  va_start  va_arg  va_end




double Average(int NUM, ...) {  //(SIempre va a ser int este argumento)  //NOTAR QUE HAY QUE PONER LOS TRES PUNTOS:  ...  !!!(sino tira error)

   va_list  VALIST;/////////////////////////  va_list  is a type variable (like int, double, etc.)  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

   /* initialize VALIST for NUM NUMber of arguments */
   va_start(VALIST, NUM);

   /* access all the arguments assigned to VALIST */
   double Sum = 0.0;
   for (int i = 0; i < NUM; i++) {
      Sum += va_arg(VALIST, int);/////En cada nueva iteración, va_arg entrega el argumento siguiente !
   }

   /* clean memory reserved for VALIST */
   va_end(VALIST);

   return Sum/NUM;
}






int main() {
   printf("Average of 2, 3, 4, 5 = %f\n", Average(4,  2,3,4,5));////   SubFunctionName( CantidadCualquieraDeArgumentos ,         Argumento1,Argumento2,Argumento3,Etc )
   printf("Average of 5, 10, 15 = %f\n", Average(3,  5,10,15));
}












//
