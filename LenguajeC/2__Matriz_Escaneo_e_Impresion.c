//**************************************************************************
//SALIENDO DEL TAMAÑO DE UNA MATRIZ
//**************************************************************************
// #include <stdio.h>
//
// int main() {
//   int Matriz[5][5];
//   for ( int i=-1; i<5; i++) {  //Que ocurre si se accede a un casillero que no se encuentra dentro del tamaño de una Matriz?
//     for ( int j=0; j<5; j++) {                                                                //Rta: Imprime cualquier cosa.
//       Matriz[i][j] = 8;
//     }
//   }
//
//   for ( int i=0; i<5; i++) {
//     printf("         ");
//     for ( int j=0; j<5; j++) {
//       printf("%d\t", Matriz[i][j] );
//     }
//     printf("\n");
//   }
//
//   return 0;
// }






//**************************************************************************
//CREANDO UNA MATRIZ
//**************************************************************************

#include <stdio.h>
int main() {
  int NombreMatriz[2][3]={ {1,2,3},  //También se puede poner EN UNA SOLA LÍNEA: int NombreMatriz[2][3] ={{1,2,3},{4,5,6}};
                           {4,5,6} }; //(Note que si lo bajamos, antes tenemos que poner una coma)
return 0;
}


// #include <stdio.h>
//
// int main() {
//   int i, j, CantFilas, CantColumnas;
//   printf ("Ingrese el tamaño de la matriz: \n  CantFilas=");
//   scanf ("%d", &CantFilas);
//   printf ("  CantColumnas=");
//   scanf ("%d", &CantColumnas);
//   printf("Ingrese los valores de la matriz: \n");
//   int Matriz[CantFilas][CantColumnas];
//   for (i=1 ; i<=CantFilas ; ++i) {///////Acostumbrarse siempre a definir los for como:  (i=0 ; i<CantFilas ; ++i)
//       for (j=1 ; j<=CantColumnas ; ++j) {
//           scanf("%d", &Matriz[i][j]);
//       }
//       printf("\n");
//   }
//
//   printf("Su matriz es: \n");
//   for (int i=1 ; i<=CantFilas ; i++) {/////OJO!--> Solo puedo usar i=1 (en lugar de i=0) cuando la definición de la matriz se hace con un for (con  i=1, claro)
//       for (int j=1 ; j<=CantColumnas ; j++) {
//           printf("%d\t",  Matriz[i][j] );///// \t (t de tab) sirve para que al imprimir la matriz, todos los elementos queden "ordenados hacia la izquierda"  //Para que queden mejor ordenamos hacia la derecha ver VER EJER 14-TP3
//       }
//       printf("\n");
//   }
//
// return 0;
// }











// for (i = 1; i <= CantFilas; ++i) {
//   for (j = 1; j <= CantColumnas; ++j) {
//     if (i==1 && j==1 ) {
//         printf("               [ ");
//       }
//       printf("%d ", Matriz[i][j]);
//       if (i==CantFilas && j==CantColumnas ) {
//           printf("]");
//       }
//   }
//   printf("\n                 ");
// }
