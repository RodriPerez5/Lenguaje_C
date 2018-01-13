//(ver tamb. uso en TP4__CREAR_VECTOR)
#include <stdio.h>
#include <string.h>

int main () {
   char Str[50];

   strcpy(Str,"This is string.h library function");
   puts(Str);

   memset(Str,'$',7);
   puts(Str);

   return(0);
}
/*
When the abone program is compiled and executed, it produces the following result -

This is string.h library function
$$$$$$$ string.h library function

*/
