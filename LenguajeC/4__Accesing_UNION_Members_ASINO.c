

#include <stdio.h>
#include <string.h>

union Data {
   int entero;
   float fraccion;
   char cadena[20];
};

int main( ) {

   union Data datos;

   datos.entero = 10;
   datos.fraccion = 220.5;
   strcpy( datos.cadena, "C Programming");

   printf( "\n datos.entero: %d\n", datos.entero);//IMPRIME MAL
   printf( " datos.fraccion: %f\n", datos.fraccion);//IMPRIME MAL
   printf( " datos.cadena: %s\n\n", datos.cadena);

   return 0;
}


/*
When the above code is compiled and executed, it produces the following result −

 datos.entero: 1917853763
 datos.fraccion: 4122360580327794860452759994368.000000
 datos.cadena: C Programming

*/
/*
 Here, we can see that the values of entero and fraccion members of union GOT CORRUPTED BECAUSE THE FINAL VARIABLE ASSIGNED TO THE VARIABLE
HAS OCCUPIED THE MEMORY LOCATION (and this is the reason that the value of cadena member is getting printed very well)

 Now let's look into the same example once again where we will use one variable at a time which is the main
purpose of having unions − Ver: 4__Accesing_UNION_Members_ASISÍ.c
*/
