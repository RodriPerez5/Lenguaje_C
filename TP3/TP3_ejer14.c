/*
Escriba un programa que calcule el producto de 2 matrices AxB = C, con A[m*n], B[n*p].
*/
//////////////////////////Porque/no/me/funciona/esta/línea/?///////////////// #include <conio.h>  /* required for clrscr() */
//////////////////////////Porque/no/me/funciona/esta/línea/?///////////////// clrscr();  /* clear the screen */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main() {
  int SegsDelSistema = time(NULL);
  srand(SegsDelSistema);
  int m= rand()%10 + 1, n= rand()%10 + 1, p= rand()%10 + 1;//Si lo definimos antes de la semilla, entonces no toma la semilla
  printf("   Cantidad de Filas A: m=%d\nCantidad de Columnas A: n=%d\n", m, n);
  printf("   Cantidad de Filas B: n=%d\nCantidad de Columnas B: p=%d\n", n, p);

  printf("\nLa matriz (aleatoria) A es:\n");
  int A[m][n];
  for (int i=0; i<m; i++) {
      for (int j=0; j<n; j++) {
          A[i][j] = ((rand()% 1999) - 999);//Rango: [-999 ; 999]  // ((rand()% MaxValor) - MinValor)--> MaxValor=(MinValor/2)+1

          if (i==0 && j==0 ) {
              printf("                           [ ");
          }
          if ( A[i][j] >= 0 ) {
             if ( A[i][j] < 10 ) {
                printf("   %d ", A[i][j]);
             }else if ( A[i][j] < 100 ) {
             printf("  %d ", A[i][j]);
             }else {
             printf(" %d ", A[i][j]);
             }
          }
          if ( A[i][j] < 0 ) {
             if ( A[i][j] > -10 ) {
                printf("  %d ", A[i][j]);
             }else if ( A[i][j] > -100 ) {
             printf(" %d ", A[i][j]);
             }else {
             printf("%d ", A[i][j]);
             }
          }

          if (i==(m-1) && j==(n-1) ) {
             printf("]");
          }
      }
      printf("\n                             ");
  }



  printf("\nLa matriz (aleatoria) B es:\n");
  int B[n][p];
  for (int i=0; i<n; i++) {
      for (int j=0; j<p;  j++) {
          B[i][j] = ((rand()% 1999) - 999);

          if (i==0 && j==0 ) {
              printf("                           [ ");
          }
          if ( B[i][j] >= 0 ) {
             if ( B[i][j] < 10 ) {
                printf("   %d ", B[i][j]);
             }else if ( B[i][j] < 100 ) {
             printf("  %d ", B[i][j]);
             }else {
             printf(" %d ", B[i][j]);
             }
          }
          if ( B[i][j] < 0 ) {
             if ( B[i][j] > -10 ) {
                printf("  %d ", B[i][j]);
             }else if ( B[i][j] > -100 ) {
             printf(" %d ", B[i][j]);
             }else {
             printf("%d ", B[i][j]);
             }
          }

          if (i==(n-1) && j==(p-1) ) {
             printf("]");
          }
      }
      printf("\n                             ");
  }


  printf("\n");



  printf("La Matriz RESULTADO C es:\n");
  int Multiplicacion, Suma, C[m][p];
  for (int i=0; i<m; i++) {
      for (int k=0; k<p; k++) {
          Suma=0;
          for (int j=0; j<n; j++) {
              Multiplicacion = A[i][j] * B[j][k] ;
              Suma+=Multiplicacion;
          }
          C[i][k]=Suma;
          if ( C[i][k]<0 ) {
            printf(" %d\t", C[i][k]);
          }else {
          printf("  %d\t", C[i][k]);
        }
      }
      printf("\n");
  }
  printf("\n");

  return 0;
}













//
