#include "/home/rodri/INFORMATICA/TP4/TP4_HEADER_FILE.h"



void EscalarVector( double *Vector, int Tamanio, double Escalar ) {
  for ( int i=0; i<Tamanio; i++ ) {
      Vector[i] *= Escalar;
  }
}



void EscalarMatriz( double **Matriz, int CantFILAS, int CantCOLUMNAS, int Escalar ) {
  for ( int i=0; i<CantFILAS; i++ ) {
    for ( int j=0; j<CantCOLUMNAS; j++ ) {
      Matriz[i][j] *= Escalar;
    }
  }
}




////////// OJO, AL USAR ESTA FUNCIÓN LUEGO HAY QUE LIBERAR MEMORIA! ////////////
double *ProductoVectorial( double *U, double *V, int Tamanio) {
  double *W;
  W = ReservarMemoriaVector(Tamanio);
  W[0]=U[1]*V[2] - U[2]*V[1];
  W[1]= - (U[0]*V[2] - U[2]*V[0]);
  W[2]=U[0]*V[1] - U[1]*V[0];
  return W;
  // free( W );//''También se puede liberar la memoria luego del return!''
}



double **ProductoMatricial( double **A, double **B, int CantFILAS, int NN, int CantCOLUMNAS ) {
  double **C;
  C = ReservarMemoriaMatriz( CantFILAS, CantCOLUMNAS );
  double Multiplicacion, Suma;
  for ( int i=0; i<CantFILAS; i++) {
      for ( int k=0; k<CantCOLUMNAS; k++) {
          Suma=0;
          for ( int j=0; j<NN; j++) {
              Multiplicacion = A[i][j] * B[j][k] ;
              Suma+=Multiplicacion;
          }
          C[i][k]=Suma;
      }
  }
  return C;
  // free( C );
}



                //Sin los tres * entonces se produce una violacion de segmento cuando introducimos una M<N
void TransponerMatriz( double ***Matriz_ptr, int CantFILAS, int CantCOLUMNAS ) {
  double **MatrizTEMPORAL;
  double **Matriz = *Matriz_ptr;//Cargamos esta double **Matriz con la double **Matriz del main-ejer12
  MatrizTEMPORAL = ReservarMemoriaMatriz( CantCOLUMNAS, CantFILAS );
  //Calculamos la transpuesta de la Matriz y la guardamos en la MatrizTEMPORAL:
  for ( int i=0; i<CantFILAS; i++) {
      for ( int j=0; j<CantCOLUMNAS; j++) {
          MatrizTEMPORAL[j][i] = Matriz[i][j];
      }
  }
  //Calculamos la transpuesta la Matriz original:
  //(NOTA: Por ser la matriz ya transpuesta, se "invierten la cant de filas y columnas):
  Matriz = realloc( Matriz, CantCOLUMNAS*sizeof(double *) );
  for ( int i=0; i<CantCOLUMNAS; i++) {
    if( i<CantFILAS ) {
      Matriz[i] = realloc( Matriz[i], CantFILAS*sizeof(double) );
    }
    else {//Si i>=CantFILAS, es una fila "nueva", que no se había reservado nunca, entonces esa fila No se puede redimen..
      Matriz[i] = malloc( CantFILAS*sizeof(double) );//..sionar sino que se debe crear, por lo que usamos malloc y No reallloc.
    }
  }
  //Atualizamos el valor del puntero para que se vea desde afuera:
   *Matriz_ptr = Matriz;
  //Copiamos los valores de la MatrizTEMPORAL en la Matriz original:
  for ( int i=0; i<CantCOLUMNAS; i++) {
      for ( int j=0; j<CantFILAS; j++) {
        Matriz[i][j] = MatrizTEMPORAL[i][j];
      }
  }
  LiberarMemoriaMatriz( MatrizTEMPORAL, CantCOLUMNAS );
}












//
