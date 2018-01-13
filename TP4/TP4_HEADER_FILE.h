

#ifndef HEADER_FILE_TP4
#define HEADER_FILE_TP4
   #include <stdio.h>
   #include <stdlib.h>
   #include <string.h> //Para incluir a la función:  MEMSET
   #include <time.h>

   double *ReservarMemoriaVector(int TamanioVector);
   void LiberarMemoriaVector( double *Vector );
   double **ReservarMemoriaMatriz( int CantFILAS, int CantColumnas );
   void LiberarMemoriaMatriz( double **MATRIZ, int CantFILAS );

   void EstablecerSEMILLA( int Count );
   void CargarVectorAleatorio( double *VectorRandom, int TamanioVector );
   void CargarMatrizAleatoria( double **MatrizRandom, int CantFILAS, int CantCOLUMNAS );
   void MostrarVector( double *VECTOR, int Tamanio);
   void MostrarMatriz( double **MATRIZ, int CantFILAS, int CantCOLUMNAS );

   void EscalarVector( double *Vector, int Tamanio, double Escalar );
   void EscalarMatriz( double **Matriz, int CantFILAS, int CantCOLUMNAS, int Escalar );
   double *ProductoVectorial( double *U, double *V, int N);
   double **ProductoMatricial( double **A, double **B, int CantFILAS, int NN, int CantCOLUMNAS );
   void TransponerMatriz( double ***Matriz, int CantFILAS, int CantCOLUMNAS );

#endif
