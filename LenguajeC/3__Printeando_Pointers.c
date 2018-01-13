/*
  The actual data type of the value of all pointers, whether integer, float, character,
or otherwise, is the same, a long hexadecimal number that represents a memory address.
*/







// #include <stdio.h>
//
// int main () {
//
//    int *ptr = NULL;
//
//    printf("The value of ptr is: %x\n", ptr);////PONER %p  EN LUGAR DE %x !! // %p (un puntero )
//
//    if(!ptr) { /* succeeds if p is null */           //  if(ptr)   /* succeeds if p is not null */
//       int parapaapapa=7;
//       printf("parapaapapa = %d\n", parapaapapa);
//    }
//
//    return 0;
// }










#include <stdio.h>

int main () {

/////////////////////////////////////////////////////PRINTEANDO UN VALOR NUMÉRICO(un int por ej.)/////////////////////////////////////////////////////////////////////

   int  var = 21;   /* actual variable declaration */
   int  *ip;        /* pointer variable declaration */
   ip = &var;  /* store address of var in pointer variable*/

   /* ADDRESS of the variable var*/
   printf("Address of var variable:          %x\n", &var );
  //  printf("Address of var variable:       %p\n", &var );///////////Si en vez de %x coloco %p entonces nos tira una dirección que empieza con:  0x7ff...    ENTENDER!!
  //  printf("Address of var variable:       %d\n", &var );//////¿Esto es válido??????????????????(nos tira números decimales a veces positivos y otras veces negativos)
  //  printf("\n");

   /* ADDRESS stored in pointer variable */
  //  printf("Address stored in ip variable: %x\n", ip );
   printf("Address stored in ip variable:    %p\n", ip );///////Si en vez de %x coloco %p entonces nos tira una dirección que empieza con:  0x7ff...    ENTENDER!!
  //  printf("Address stored in ip variable: %d\n", ip );//¿Esto es válido??????????????????(nos tira números decimales a veces positivos y otras veces negativos)
  //  printf("\n");

   /* access the VALUE using the pointer */
  //  printf("Value of *ip variable:         %x\n", *ip );//Nos da el VALOR de la variable a la que apunta el pointer, pero en HEXADECIMAL
  //  printf("Value of *ip variable:         %p\n", *ip );//Nos da el VALOR de la variable a la que apunta el pointer, pero en HEXADECIMAL y empezando con: 0x
   printf("Value of *ip variable:            %d\n", *ip );
  //  printf("\n");









//////////////////////////////////////////////////////PRINTEANDO UNA CADENA DE CARACTERES////////////////////////////////////////////////////////////

  // //////////////////UNA FORMA/////////////////
  // char CadenaDeCacarteres[] = {"...Y Ella..?"};
  // char *IP = &CadenaDeCacarteres[3];//Entre paréntesis debemos si o si especificar por que caracter empezar.(SI COLOCAMOS Por ej.: [3] entonces solo nos imprimirá: Y Ella..? )
  //
  // printf("Address of position indicated: %x\n", &CadenaDeCacarteres );//(Addres of position 0)
  // printf("Address of position 1:         %x\n", &CadenaDeCacarteres[1] );
  // printf("Address of position 2:         %x\n", &CadenaDeCacarteres[2] );
  // printf("Address of position 3:         %x\n", &CadenaDeCacarteres[3] );
  // printf("Address of position indicated: %p\n", &CadenaDeCacarteres );////Si en vez de %x coloco %p entonces nos tira una dirección que empieza con:  0x7ff...    ENTENDER!!
  // printf("Value of CadenaDeCacarteres:   %s\n", &CadenaDeCacarteres );//Nos muestra TODA la Cadena sin importar la posición indicada para 'empezar'
  // printf("\n");
  //
  // printf("Address of position indicated: %x\n", IP );
  // printf("Address of position indicated: %p\n", IP );//Este es la posta para tirar la ADDRESS de las Cadena De Cacarteres de la posición indicada.
  // printf("Value of CadenaDeCacarteres:   %s\n", IP );//Solo nos muestra la PARTE de la Cadena luego de la posición indicada para 'empezar'
  // printf("\n");
  //
  // printf("Address of position indicated: %x\n", *IP );
  // printf("Address of position indicated: %p\n", *IP );
  // printf("Value of CadenaDeCacarteres:   %s\n", *IP );//No funca Esta línea    (core dumped)
  // printf("\n");




//////////////////OTRA FORMA/////////////////
  char *IPP = {"...Y Ella..?"};//ESTA NOTACIÓN NO SE PUEDE HACER CON VALORES NUMERICOS!! (int *PTR=11;)-->la inicialización crea un puntero desde un entero sin una conversión[-Wint-conversion]
                               
  printf("Address of position 0:       %x\n", IPP );
  printf("Address of position 0:       %p\n", IPP );//Este es la posta para tirar la ADDRESS de las Cadena De Cacarteres de la posición indicada.
  printf("Value of CadenaDeCacarteres: %s\n", IPP );//Este es la posta para tirar el VALUE(caracteres) de las Cadena De Cacarteres
  printf("\n");

  printf("Address of position 0:       %x\n", *IPP );
  printf("Address of position 0:       %p\n", *IPP );
  printf("Value of CadenaDeCacarteres: %s\n", *IPP );//No funca Esta línea    (core dumped)
  printf("\n");










  return 0;
}





















//
