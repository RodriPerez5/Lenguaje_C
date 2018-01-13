#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   char *Str;

   /* Initial memory allocation */
   Str = (char *) malloc(15);//ES AL CUETE PONER EL CAST:   (TipoDeVariable *)    SOLO ES PARA ORIENTARSE
   strcpy(Str, "tutorialspoint");//NOTA: Esta línea es igual por más que Str sea un pointer o no (ver ejemplo abajo)
   printf("          String: %s              Address: %p\n", Str, Str);

   /* Reallocating memory */
   Str = (char *) realloc(Str, 25);
   strcat(Str, ".com");
   printf("          String: %s          Address: %p\n", Str, Str);

   free(Str);
   return(0);
}



// ////////////////////////'' LO QUE HACEMOS CON malloc ARRIBA, ES LO MISMO QUE HACER: ''////////////////////////
// int main()
// {
//    char Str[15];
//
//    strcpy(Str, "tutorialspoint");
//    printf("          String: %s              Address: %p\n", Str, Str);
//
// return(0);
// }
