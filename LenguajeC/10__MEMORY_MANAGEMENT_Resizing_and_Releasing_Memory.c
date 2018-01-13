/*
RESIZING MEMORY:
  You can increase or decrease the size of an allocated memory block by calling the function realloc().


REALEASING MEMORY:
  El compilador no inserta código automáticamente para liberar la memoria, por lo que la misma debe..
..liberarse manualmente una vez que ya no se utiliza.
 Al finalizar la ejecución de una función, el compilador
automáticamente libera la memoria de las variables locales de la
función, pero no libera la memoria de las variables dinámicas!
 Cuando termina la ejecución de la función, los apuntadores locales
de la función se liberan, pero si no se libera la memoria dinámica
explícitamente, esa memoria queda marcada como “utilizada” (no
puede ser asignada a otro proceso), y sin embargo no hay forma
de accederla porque el apuntador se liberó!!!
A esto se le llama FUGA DE MEMORIA (MEMORY LEAK)
*/


//////////////////////////RESIZING and REALEASING MEMORY////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {

   char Name[100];
   char *Description;

   strcpy(Name, "Zara Ali");

   /* allocate memory dynamically */
   Description = malloc( 30*sizeof(char) );


   if( Description == NULL ) {
      fprintf(stderr, "Error - unable to allocate required memory\n");
   }
   else {
      strcpy( Description, "Zara ali a DPS student.");
   }


   /* suppose you want to store bigger description */
   Description = realloc( Description,  100*sizeof(char) );// void *realloc( void *address  ,   int NuevoNumero_de_elementos*sizeof(Tipo_de_Variable) );
              //Note: Without re-allocating extra memory, then  strcat()  function will give an error due to lack of available memory in description.

   if( Description == NULL ) {
      fprintf(stderr, "Error - unable to allocate required memory\n");
   }
   else {
      strcat( Description, " She is in class 10th");//Concatenamos:  " She is in class 10th"  al final de la cadena de caracteres.
   }

   printf("Name = %s\n", Name );
   printf("Description: %s\n", Description );


   /* release memory using free() function */
   free( Description );
}










//
