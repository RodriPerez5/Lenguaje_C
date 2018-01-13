#include "/home/rodri/INFORMATICA/TP4/TP4_HEADER_FILE.h"



double *ReservarMemoriaVector(int Tamanio) {
    double *VECTOR = malloc( Tamanio*sizeof(double) );

    // memset( VECTOR, 0, Tamanio);//LOS VALORES DEL VECTOR RESERVADO, SUELEN SER NULL, PERO POR LAS DUDAS PARA NO TENER BASURA..
    //                             //..PODEMOS USAR memset PARA DEFINIR LOS VALORES DEL VECTOR TODOS COMO NULL.

    return VECTOR;
    // free( VECTOR );//''También se puede liberar la memoria luego del return!''
}




void LiberarMemoriaVector( double *VECTOR ) {
    free(VECTOR);
}





double **ReservarMemoriaMatriz( int CantFILAS, int CantCOLUMNAS ) {
  double **MATRIZ = /*(double **)*/malloc( CantFILAS*sizeof(double *) );//OJO! SI USAMOS malloc HAY QUE PONER: sizeof(double *) CON EL * !!!!!!!
  // memset( MATRIZ , 0, CantFILAS);
  for ( int i=0; i<CantFILAS; i++) {//OJO! ES: CantFILAS, NO CantCOLUMNAS!
    MATRIZ[i] = /*(double *)*/malloc( CantCOLUMNAS*sizeof(double) );
    // memset( MATRIZ[i] , 0, CantCOLUMNAS);
  }
  return MATRIZ;
}




void LiberarMemoriaMatriz( double **MATRIZ, int CantFILAS ) {//OJO, NO ERA CANTIDAD DE COLUMNAS!
  for ( int i=0; i<CantFILAS; i++) {
    free( MATRIZ[i] );
  }
  free(MATRIZ);
}






// double **RedimensionarMatriz( CantCOLUMNAS, CantFILAS ) {
//   double **MATRIZ = /*(double **)*/realloc( CantFILAS*sizeof(double *) );
//   for ( int i=0; i<CantFILAS; i++) {
//     MATRIZ[i] = /*(double *)*/realloc( CantCOLUMNAS*sizeof(double) );
//   }
//   return MATRIZ;
// }
















//
