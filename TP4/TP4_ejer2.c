/*
Escriba una función que reciba como parámetros 2 vectores U y V de N elementos tipo
double (donde N puede ser variable), cree un nuevo vector W de N elementos
dinámicamente, y calcule (almacenando el resultado en W) el producto vectorial UxV. La
función debe devolver el apuntador a W (que fue creado en la misma función).

ACLARACIÓN:
Dado que el producto vectorial no está definido en espacios vectoriales Eculideanos de dimensión arbitraria, en la función que..
..calcula este producto validamos que siempre sea N==3. Es decir que, en caso de que N!=3 la función simplemente no haga nada.
*/

//     gcc TP4_ejer2.c ValoresAleatorios.c ManejoDinamicoDeMemoria.c OperacionesConArreglos.c

#include "/home/rodri/INFORMATICA/TP4/TP4_HEADER_FILE.h"


int main () {

  int N;
  printf(" Ingrese el único tamaño factible de vectores para realizar producto vectorial:  ");
  scanf("%d", &N);

  if ( N!=3 ) {
    printf("\n ENTRADA INCORRECTA. El producto vectorial solo es factible en el espacio tridimensional!\n\n");
    abort();
  }

  /*   N siempre es igual a 3:   */

  double *U;
  U = ReservarMemoriaVector( N );//Aunque no lo pide el ejercicio, reservo memoria porque corresponde(No se conoce el tam del vector a la hora de la compilación), pero entender porque funciona sin necesidad de reservar memoria(para los vectores solo funca, para lasmatrices No se puede sin reservar memoria!)
  EstablecerSEMILLA( 0 );
  CargarVectorAleatorio( U, N);  //Una vez resevada la memoria, luego ya esta siempre se trata con apuntadores!
  printf("\n    U=");
  MostrarVector( U, N);          //Una vez resevada la memoria, luego ya esta siempre se trata con apuntadores!

  double *V;
  V = ReservarMemoriaVector( N );
  EstablecerSEMILLA( 1 );
  CargarVectorAleatorio( V, N);
  printf("    V=");
  MostrarVector( V, N);





  double *UxV;
  UxV = ProductoVectorial( U, V, N);//Una vez resevada la memoria, luego ya esta siempre se trata con apuntadores!

  printf("\n    W=");
  MostrarVector( UxV, N);

  printf(" El apuntador a W es:  %p\n\n", UxV);//////////////////////////////////REVISAR SI ESTÁ BIEN ESTO

  LiberarMemoriaVector(U);
  LiberarMemoriaVector(V);
  LiberarMemoriaVector(UxV);

  return 0;
}
