/*
Escriba un programa que:
  a. Lea por teclado 3 valores M, N y P
  b. Cree 4 matrices dinámicamente con valores aleatorios:
       i. 2 de M x N y
      ii. 2 de N x P
  c. Lea por teclado un factor de escala double
  d. Escale las 4 matrices generadas en (b) por el factor s
  e. Calcule el producto matricial de a pares, generando 2 matrices C1 y C2 de MxP elementos cada una
  f. Calcule la transpuesta de C2
  g. Calcule el producto de C1 x C2T (MxP y PxM respectivamente)
  h. Muestre los resultados intermedios por pantalla
  i. Libere la memoria dinámica utilizada
*/

//     gcc TP4_ejer13.c ValoresAleatorios.c ManejoDinamicoDeMemoria.c OperacionesConArreglos.c

#include "/home/rodri/INFORMATICA/TP4/TP4_HEADER_FILE.h"

int main() {
  /*  a.  */
  int M, N, P;
  printf(" Ingrese el tamaño de la Matriz(MxN):\n");
  printf("    M= ");
  scanf("%d", &M);
  printf("    N= ");
  scanf("%d", &N);
  printf("    P= ");
  scanf("%d", &P);

  /*  b.  */
  double **A1;
  A1 = ReservarMemoriaMatriz( M, N);
  EstablecerSEMILLA( 0 );
  CargarMatrizAleatoria( A1, M, N );
  printf("\n    A1=\n");
  MostrarMatriz( A1, M, N );
  double **B1;
  B1 = ReservarMemoriaMatriz( N, P);
  EstablecerSEMILLA( 0 );
  CargarMatrizAleatoria( B1, N, P );
  printf("\n    B1=\n");
  MostrarMatriz( B1, N, P );
  double **A2;
  A2 = ReservarMemoriaMatriz( M, N);
  EstablecerSEMILLA( 0 );
  CargarMatrizAleatoria( A2, M, N );
  printf("\n    A2=\n");
  MostrarMatriz( A2, M, N );
  double **B2;
  B2 = ReservarMemoriaMatriz( N, P);
  EstablecerSEMILLA( 0 );
  CargarMatrizAleatoria( B2, N, P );
  printf("\n    B2=\n");
  MostrarMatriz( B2, N, P );
  printf("\n");

  /*  c.  */
  double S;
  printf(" Ingrese un Escalar tipo double:  ");
  scanf("%lf", &S);
  printf("\n");

  /*  d.  */
  EscalarMatriz( A1, M, N, S);
  printf("    A1_Escalada=\n");
  MostrarMatriz( A1, M, N );
  printf("\n");
  EscalarMatriz( B1, N, P, S);
  printf("    B1_Escalada=\n");
  MostrarMatriz( B1, N, P );
  printf("\n");
  EscalarMatriz( A2, M, N, S);
  printf("    A2_Escalada=\n");
  MostrarMatriz( A2, M, N );
  printf("\n");
  EscalarMatriz( B2, N, P, S);
  printf("    B2_Escalada=\n");
  MostrarMatriz( B2, N, P );
  printf("\n");

  /*  e.  */
  double **C1;
  C1 = ProductoMatricial( A1, B1, M, N, P);
  printf("    C1=A1xB1=\n");
  MostrarMatriz( C1, M, P );
  printf("\n");
  double **C2;
  C2 = ProductoMatricial( A2, B2, M, N, P);
  printf("    C2=A2xB2=\n");
  MostrarMatriz( C2, M, P );
  printf("\n");

  /*  f.  */
  TransponerMatriz( &C2, M, P );
  printf("    C2T=\n");
  MostrarMatriz( C2, M, P );
  printf("\n");

  /*  g.  */
  double **C1xC2T;
  C1xC2T = ProductoMatricial( C1, C2, M, P, M);
  printf("    C1xC2T=\n");
  MostrarMatriz( C1xC2T, M, M );
  printf("\n");

  /*  h.  */
     //Listo

  /*  i.  */
  LiberarMemoriaMatriz( A1, M);
  LiberarMemoriaMatriz( B1, N);
  LiberarMemoriaMatriz( A2, M);
  LiberarMemoriaMatriz( B2, N);
  LiberarMemoriaMatriz( C1, M);
  LiberarMemoriaMatriz( C2, M);
  LiberarMemoriaMatriz( C1xC2T, M);

  return 0;
}













//
