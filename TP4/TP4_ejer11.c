/*
Repita el ejercicio (5) para el caso de una matriz de M x N elementos
*/
/*     IDEM EJER10
Escriba una función que reciba una matriz de M x N elementos (M y N variables) e imprima por
pantalla la matriz en un formato legible para el ser humano.
*/

//     gcc TP4_ejer11.c ValoresAleatorios.c ManejoDinamicoDeMemoria.c

#include "/home/rodri/INFORMATICA/TP4/TP4_HEADER_FILE.h"

int main() {
  int M, N;
  printf(" Ingrese el tamaño de la Matriz(MxN):\n");
  printf("    M= ");
  scanf("%d", &M);
  printf("    N= ");
  scanf("%d", &N);

  double **Matriz;
  Matriz = ReservarMemoriaMatriz( M, N);
  EstablecerSEMILLA( 0 );
  CargarMatrizAleatoria( Matriz, M, N );
  printf("\n    Matriz=\n");
  MostrarMatriz( Matriz, M, N );
  printf("\n");

  LiberarMemoriaMatriz( Matriz, M);

  return 0;
}


















//
