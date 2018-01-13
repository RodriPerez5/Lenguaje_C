/*
Escriba una función que reciba como argumento un entero N, cree un vector de N
elementos de tipo double dinámicamente (utilizando la función malloc), y devuelva un
apuntador con la dirección de memoria del arreglo creado.
*/

//     gcc TP4_ejer1.c ManejoDinamicoDeMemoria.c ValoresAleatorios.c

#include "/home/rodri/INFORMATICA/TP4/TP4_HEADER_FILE.h"


int main () {
  int N;
  printf(" Ingrese el tamaño del vector:  ");
  scanf("%d", &N);

 double *Vector;
 // printf(" El puntero %p ubica %p en %p\n\n", *Vector, Vector, &Vector);/////////////////////////////////////////////////VER MEJOR
 Vector = ReservarMemoriaVector(N);
 printf("\n Vector=");
 MostrarVector( Vector, N);
 printf("\n");


 // printf(" La dirección de memoria del vector creado es:  %p\n\n", Vector);//REVISAR ESTO
 printf(" El puntero %f ubica %p en %p\n\n", *Vector, Vector, &Vector);///////////&Vector e la dirección del puntero¿?


 LiberarMemoriaVector(Vector);
 return 0;
}
















//
