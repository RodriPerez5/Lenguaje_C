/*     IDEM EJER4
Escriba una función que reciba un vector de N elementos (N variable) e imprima por
pantalla el vector en un formato legible para el ser humano (ej: utilizando notación
algebraica: “ (v 1 , v 2 , ..., v n ) ”)
*/

//     gcc TP4_ejer5.c ValoresAleatorios.c

#include "/home/rodri/INFORMATICA/TP4/TP4_HEADER_FILE.h"


int main() {
  int N;
  printf(" Ingrese el tamaño del vector:  ");
  scanf("%d", &N);

  double *Vector;
  Vector = ReservarMemoriaVector( N );
  EstablecerSEMILLA(0);
  CargarVectorAleatorio( Vector, N);

  printf("\n Vector=");
  MostrarVector( Vector, N);

  return 0;
}
