/*
Escriba una función que reciba como parámetro una matriz de M x N elementos, y calcule
la transpuesta de la matriz. El resultado debe ser almacenado en la misma matriz (es decir
que no se debe reservar memoria para el resultado ni devolver ningún apuntador).
*/

//     gcc TP4_ejer12.c ValoresAleatorios.c ManejoDinamicoDeMemoria.c OperacionesConArreglos.c

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

  TransponerMatriz( &Matriz, M, N );//Pasamos la dirección de memoria del doble apuntador: Matriz //Ver  3__INIZIALIZATION.c
  printf("\n    Matriz_Transpuesta=\n");
  MostrarMatriz( Matriz, M, N );
  printf("\n");

  LiberarMemoriaMatriz( Matriz, M);

  return 0;
}













//
