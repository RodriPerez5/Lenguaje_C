
#include <stdio.h>

// void Function1( int **W );
void Function2( int ***W_ptr );

int main () {


  // int *V = 10;//FORMA INCORRECTA


  // int Valor = 10;//FORMA INCORRECTA
  // int *V = Valor;//FORMA INCORRECTA


  // int Valor = 10;//FORMA CORRECTA
  // int *V = &Valor;//FORMA CORRECTA


  int Valor = 10;//FORMA CORRECTA
  int *V;//FORMA CORRECTA
  V = &Valor;//FORMA CORRECTA

  printf("\nValue(an Address) of V = %p\n", V );//Imprime lo mismo que: ..%p\n", *W );
  printf("Value stored in the Address pointed by V = %d\n\n", *V );//Imprime lo mismo que: ..%d\n\n", **W );

  // int Ala;
  // Ala=*V;
  // printf(" Ala= %d\n\n", Ala );

  int **W;
  W=&V;
  printf("Value(an Pointer's_Address) of W = %p\n", W );
  printf("Value(an Address) stored in the Pointer's_Address pointed by W = %p\n", *W );//Imprime lo mismo que: ..%p\n", V );
  printf("Value stored in the Pointer's_Address doubly-pointed by W = %d\n\n", **W );//Imprime lo mismo que: ..%d\n\n", *V );

  // Function1( W );
  Function2( &W );

  return 0;
}

// void Function1( int **W ) {
//   int **M = W;
//   printf("Value(an Pointer's_Address) of M = %p\n", M );
//   printf("Value(an Address) stored in the Pointer's_Address pointed by M = %p\n", *M );//Imprime lo mismo que: ..%p\n", V );
//   printf("Value stored in the Pointer's_Address doubly-pointed by M = %d\n\n", **M );//Imprime lo mismo que: ..%d\n\n", *V );
// }

void Function2( int ***W_ptr ) {/* Esta Function2 hace lo mismo que la Function1, pero tiene alguna diferencia(entender ejer12-TP4) */
  int **M = *W_ptr;// El:  *W_ptr  es igual a el doble puntero:  W
  printf("Value(an Pointer's_Address) of M = %p\n", M );
  printf("Value(an Address) stored in the Pointer's_Address pointed by M = %p\n", *M );//Imprime lo mismo que: ..%p\n", V );
  printf("Value stored in the Pointer's_Address doubly-pointed by M = %d\n\n", **M );//Imprime lo mismo que: ..%d\n\n", *V );
}

















//
