

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
   printf( "datos.entero: %d\n", datos.entero);

   datos.fraccion = 220.5;
   printf( "datos.fraccion: %f\n", datos.fraccion);

   strcpy( datos.cadena, "C Programming");
   printf( "datos.cadena: %s\n", datos.cadena);

   return 0;
}


/*
When the above code is compiled and executed, it produces the following result −

 datos.entero: 10
 datos.fraccion: 220.500000
 datos.cadena: C Programming

Here, all the members are getting printed very well because one member is being used at a time!
*/











//
