/*     IDEM EJER5
Escriba una función que reciba como argumento un vector de N elementos double (donde
N puede ser variable) y que genere valores aleatorios para el mismo. Asegurese de
generar valores con cifras decimales (es decir que no sean simplemente enteros).
*/

//     gcc TP4_ejer4.c ValoresAleatorios.c

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
