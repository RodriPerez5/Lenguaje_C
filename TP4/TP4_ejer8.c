/*
Escriba una función que reciba como parámetros 2 matrices A y B de MxN y NxP
elementos tipo double, respectivamente, cree una nueva matriz C de MxP elementos
dinámicamente, y calcule (almacenando el resultado en C) el producto matricial. La función
debe devover el apuntador a C (que fue creada en la misma función). Valide los tamaños
de las matrices.
*/

//     gcc TP4_ejer8.c ValoresAleatorios.c ManejoDinamicoDeMemoria.c OperacionesConArreglos.c

#include "/home/rodri/INFORMATICA/TP4/TP4_HEADER_FILE.h"

int main() {
  int M, N, P;
  printf(" Ingrese el tamaño de las matrices A(MxN) y B(NxP):\n");
  printf("    M= ");
  scanf("%d", &M);
  printf("    N= ");
  scanf("%d", &N);
  printf("    P= ");
  scanf("%d", &P);

  double **A;
  A = ReservarMemoriaMatriz( M, N);
  EstablecerSEMILLA( 0 );
  CargarMatrizAleatoria( A, M, N );
  printf("\n      A=\n");
  MostrarMatriz( A, M, N );

  double **B;
  B = ReservarMemoriaMatriz( N, P);
  EstablecerSEMILLA( 0 );
  CargarMatrizAleatoria( B, N, P );
  printf("\n      B=\n");
  MostrarMatriz( B, N, P );

  double **AxB;
  AxB = ProductoMatricial( A, B, M, N, P);
  printf("\n      AxB=\n");
  MostrarMatriz( AxB, M, P );
  printf("\n");

  LiberarMemoriaMatriz( A, M);
  LiberarMemoriaMatriz( B, N);
  LiberarMemoriaMatriz( AxB, M);

  return 0;
}












//
