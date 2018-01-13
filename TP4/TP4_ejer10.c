/*
Repita el ejercicio (4) para el caso de una matriz de M x N elementos
*/
/*     IDEM EJER11
Escriba una función que reciba como argumento una matriz de M x N elementos double (donde
M y N pueden ser variables) y que genere valores aleatorios para la misma. Asegurese de
generar valores con cifras decimales (es decir que no sean simplemente enteros).
*/

//     gcc TP4_ejer10.c ValoresAleatorios.c ManejoDinamicoDeMemoria.c

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
