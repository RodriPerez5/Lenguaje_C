//DYNAMIC MEMORY MANAGENMENT
/*
LA MEMORIA DINÁMICA SE UTILIZA CUANDO NO SE CONOCE LA CANT DE ELEMENTOS O EL TIPO DE VARIABLES A GUARDAR PARA EL MOMENTO DE..
..COMPILACIÓN.
CON LA MEMORIA DINÁMICA SE MANEJA LA MEMORIA MIENTRAS SE VA EJECUTANDO EL PROGRAMA (A CONTRASTE DE LA MEMORIA ESTÁTICA QUE..
..SE RESERVA LA MEMORIA CUANDO SE COMPILA DEL PROGRAMA)
Por medio de punteros se puede reservar o liberar memoria dinámicamente, es decir, según se necesite. Para ello existen varias..
..funciones estándares, de la biblioteca <stdlib.h>:


Función MALLOC:
Sirve para solicitar un bloque de memoria del tamaño suministrado como parámetro:
             void *malloc( int Numero_de_bytes );  //This function allocates an array of Numero_de_bytes bytes and leave them uninitialized.
Devuelve un puntero a la zona de memoria concedida.
Si malloc es incapaz de conceder el bloque (p.ej. no hay memoria suficiente), devuelve un puntero nulo.
El problema de malloc es conocer cuántos bytes se quieren reservar: Si se quiere reservar una zona para Numero_de_elementos de un..
..determinado Tipo_de_Variable, habrá que multiplicar Numero_de_elementos por el tamaño en bytes del Tipo_de_Variable:
             void *malloc( int Numero_de_elementos*sizeof(Tipo_de_Variable) ); //  Numero_de_bytes = Numero_de_elementos*sizeof(Tipo_de_Variable)
La función malloc devuelve un puntero inespecífico, que no apunta a un tipo de datos determinado. En C, estos punteros sin tipo se declaran como void*
Un puntero void* puede convertirse a cualquier otra clase de puntero:
	           char* ptr = (char*)malloc(1000);


Función CALLOC:
Es lo mismo que malloc, solo que el tamaño del bloque de memoria se solicita de forma diferente:
             void *calloc( int Numero_de_elementos ,  int sizeof(Tipo_de_Variable) ); //This function allocates an array of Numero_de_elementos elements..
                                                                                      //..each of which size in bytes will be:  sizeof(Tipo_de_Variable).


Función FREE:
Cuando una zona de memoria reservada con malloc (ó calloc) ya no se necesita, puede ser liberada mediante la función free:
            void free(void *address);
address es un puntero de cualquier tipo que apunta a un área de memoria reservada previamente con malloc (ó calloc).
Si address apunta a una zona de memoria indebida, los efectos pueden ser desastrosos, igual que si se libera dos veces la misma zona.


Función REALLOC:
           void *realloc( void *address  ,   int NuevoNumero_de_bytes ); // This function re-allocates memory extending it upto:  NuevoNumero_de_bytes.
           void *realloc( void *address  ,   int NuevoNumero_de_elementos*sizeof(Tipo_de_Variable) );
 );
*/



//////////////////////////ALLOCATING MEMORY DYNAMICALLY/////////////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>//To include the functions for memory allocation and management:   malloc  calloc  free   realloc

int main() {

   char Name[100];//Ejemplo sin asignar memoria dinamicamente
   char *Description;//Ejemplo asignando memoria dinamicamente

   strcpy(Name, "Zara Ali");

   /* allocate memory dynamically */  //ES AL CUETE PONER EL CAST:   (TipoDeVariable *)   SOLO ES PARA ORIENTARSE
   Description =/* (TipoDeVariable *) */malloc( 200*sizeof(char) );//  200*sizeof(char)  -->SE MULTIPLICA LA CANTIDAD MÁX DE CARACTERES QUE SE ESPERA, POR EL TAMAÑO EN bytes DE LA VARIABLE TIPO char
                //Nota: también se pudo haber usado  calloc( 200,  sizeof(char) );                                               //(El tamaño de un char siempre es 1)

   if( Description == NULL ) {
      fprintf(stderr, "Error - unable to allocate required memory\n");
   }
   else {
      strcpy( Description, "Zara ali a DPS student in class 10th");
   }

   printf(" Name: %s\n", Name );
   //printf("SIZEOF(Name): %d\n", sizeof(Name) ); //(yo agregé esta línea y la penúltima)
   printf(" Description: %s\n", Description );
   //printf("SIZEOF(Description): %d\n", sizeof(Description) ); /////ENTENDER QUE ONDA EL TAMAÑO 200 DADO POR EL EJEMPLO DE TUTORIALS POINT
}


















//
