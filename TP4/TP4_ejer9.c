/*
Repita el ejercicio (3) para el caso de una matriz de M x N elementos
*/
/*
Escriba una función que reciba una matriz de M x N elementos double (donde M y N pueden ser
variables) y un escalar double s, y escale el mismo arreglo utilizando el factor s (es decir, no
debe devolver un puntero ni crear otro arreglo).
*/

//     gcc TP4_ejer9.c ValoresAleatorios.c ManejoDinamicoDeMemoria.c OperacionesConArreglos.c

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

  EstablecerSEMILLA( 1 );
  double S = (double) ( rand()%10000 )/123;
  printf("    Escalar= %lf\n", S);

  EscalarMatriz( Matriz, M, N, S);
  printf("\n    Matriz_Escalada=\n");
  MostrarMatriz( Matriz, M, N );
  printf("\n");

  LiberarMemoriaMatriz( Matriz, M);

  return 0;
}



















//
