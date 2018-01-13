/*
Escriba una función que reciba un vector de N elementos double (donde N puede ser
variable) y un escalar double s, y escale el mismo arreglo utilizando el factor s (es decir, no
debe devolver un puntero ni crear otro arreglo)
*/

//     gcc TP4_ejer3.c ValoresAleatorios.c OperacionesConArreglos.c

#include "/home/rodri/INFORMATICA/TP4/TP4_HEADER_FILE.h"

int main() {
  int N;
  printf(" Ingrese el tamaño del vector:  ");
  scanf("%d", &N);

  double *Vector;
  Vector = ReservarMemoriaVector( N );
  EstablecerSEMILLA( 0 );
  CargarVectorAleatorio( Vector, N);

  printf("\n         Vector=");
  MostrarVector( Vector, N);

  EstablecerSEMILLA( 1 );
  double S = (double) ( rand()%10000 )/123;//OJO ACORDARSE DE COLOCAR EL CAST: (double)  PARA QUE NO REDONDEE A ENTEROS LOS NROS FRACCIONARIOS!
  printf("        Escalar= %lf\n", S);

  EscalarVector( Vector, N, S );

  printf("\n VectorEscalado=");
  MostrarVector( Vector, N);

  return 0;
}











//
