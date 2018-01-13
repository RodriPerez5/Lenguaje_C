#include "/home/rodri/INFORMATICA/TP4/TP4_HEADER_FILE.h"





void EstablecerSEMILLA ( int Count ) {
  int SegundosDelSistema = time(NULL);
  srand(SegundosDelSistema+Count);//ESTE Count EVITA QUE SE REPITAN LOS MISMOS VALORES, CUANTO SE EJECUTA MÁS DE UNA VEZ EN UN MISMO SEGUNDO.
}





void CargarVectorAleatorio( double *VectorRandom, int TamanioVector ) {//LA ÚNICA FORMA DE PASAR ARRAYS, HACIA Y DESDE LAS FUNCTIONS, ES USANDO POINTERS
  for (int i=0; i<TamanioVector; i++ ) {
      VectorRandom[i] = (double) (rand()%1000)/123;//OJO ACORDARSE DE COLOCAR EL CAST: (double)  PARA QUE NO REDONDEE A ENTEROS LOS NROS FRACCIONARIOS!
  }
}


void CargarMatrizAleatoria( double **MatrizRandom, int CantFILAS, int CantCOLUMNAS ) {
  for ( int i=0; i<CantFILAS; i++) {
    for ( int j=0; j<CantCOLUMNAS; j++) {
        MatrizRandom[i][j] = (double) (rand()%1000)/123;
    }
  }
}





void MostrarVector( double *VECTOR, int Tamanio) {
  printf(" [");
  for ( int i=0; i<Tamanio; i++) {
     printf(" %lf ", VECTOR[i] );
  }
  printf("]\n");
}



void MostrarMatriz( double **MATRIZ, int CantFILAS, int CantCOLUMNAS ) {
  for ( int i=0; i<CantFILAS; i++) {
    printf("         ");
    for ( int j=0; j<CantCOLUMNAS; j++) {
      printf("%lf\t", MATRIZ[i][j] );
    }
    printf("\n");
  }
}
























//
