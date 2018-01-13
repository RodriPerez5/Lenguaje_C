/*
Repita el ejercicio (1) para el caso de una matriz de MxN elementos.
*/
/*
Escriba una función que reciba como argumento un entero M y otro N, cree una matriz de MxN
elementos de tipo double dinámicamente (utilizando la función malloc), y devuelva un
apuntador con la dirección de memoria del arreglo creado.
*/

//     gcc TP4_ejer7.c ManejoDinamicoDeMemoria.c ValoresAleatorios.c

#include "/home/rodri/INFORMATICA/TP4/TP4_HEADER_FILE.h"


int main() {
  int M;
  printf(" Ingrese la cantidad de Filas de la matriz:  ");
  scanf("%d", &M);
  int N;
  printf(" Ingrese la cantidad de Columnas de la matriz:  ");
  scanf("%d", &N);

  double **Matriz;
  Matriz = ReservarMemoriaMatriz( M ,N );//A diferencia de los vec, para reservar memoria para una matriz 2D se debe usar..
  printf("\n Matriz:\n");                //..un doble apuntador.
  MostrarMatriz( Matriz, M, N );         //Una vez resevada la memoria, luego ya esta siempre se trata con apuntadores!

  printf("\n La dirección de memoria la matriz creada es:  %p\n\n", Matriz);//REVISAR ESTO

  LiberarMemoriaMatriz( Matriz, M);
  return 0;
}











//
