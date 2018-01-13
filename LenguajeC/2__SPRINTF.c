/*
La función SPRINTF nos permite inicializaar una string incluyendole valores variables.
*/



#include <stdio.h>
#include <math.h>// Para usar la Macro:  M_PI  la cual nos da el valor de pi

int main () {

   char Str[80];
   sprintf(Str, "Value of Pi = %f", M_PI);

   puts(Str);//Esta línea es lo mismo que poner:   printf("%s\n", Str);

   return(0);
}
