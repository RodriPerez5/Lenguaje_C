/*
  A pointer in c is an address, which is a numeric value. Therefore, you can perform arithmetic operations on a pointer.
There are four arithmetic operators that can be used on pointers: ++, --, +, and -

  Si se le suma un valor a un apuntador, no se modifica el valor apuntado,..
..sino que se modifica la dirección de memoria almacenada en el apuntador
*/


///////////////////INCREMENTING AND DECREMENTING A POINTER//////////////////////
#include <stdio.h>

int main () {

  int Valor = 10;
  int *V;//ES LO MISMO SI PONEMOS ESTO LÍNEA Y LA SGTE DIRECTAMENTE COMO:   int *V= &Valor;
  V = &Valor;

  printf("Address of V1 = %p\n", V );
  printf("Value of V1 = %d\n\n", *V );

   V += 1;
   printf("Address of V2 = %p\n", V );
   printf("Value of V2 = %d\n\n", *V );//AQUÍ NOS ENTREGARÁ UN VALOR BASURA(CUALQUIERA) QUE HAY ESTA NUEVA DIRRECCIÓN

   V -= 1;
   printf("Address of V3 = %p\n", V );
   printf("Value of V3 = %d\n\n", *V );

   return 0;
}
/*
When the avone code is compiled and executed, it produces the following result -
  Address of V1 = 0x7ffde48cbd4c
  Value of V1 = 10
 
  Address of V2 = 0x7ffde48cbd50
  Value of V2 = -460538544
 
  Address of V3 = 0x7ffde48cbd4c
  Value of V3 = 10
*/






////////////////////////INCREMENTING A POINTER OF AN ARRAY//////////////////////
// #include <stdio.h>
// int MAX = 3;
//
// int main () {
//
//    int Matriz[] = {10, 100, 200};
//    int *ptr = Matriz;//(Here we have the array address in the pointer)    //No se puede poner:     int *ptr = {10, 100, 200};
//
//    for (int i=1; i<=MAX; i++) {
//       printf("Address of Matriz[%d] = %x\n", i, ptr );
//       printf("Value of Matriz[%d] = %d\n", i, *ptr );
//
//       /* move to the next location */
//       ptr++;  // We prefer using a pointer in our program instead of an array because the variable pointer can be
//    }          //incremented, unlike the array name which cannot be incremented.
//
//    return 0;
// }






// ///////////////////DECREMENTING A POINTEROF AN ARRAY/////////////////////////
// #include <stdio.h>
// int MAX = 3;
//
// int main () {
//
//    int  Matriz[] = {10, 100, 200};
//    int  *ptr = &Matriz[MAX-1];
//
//    for (int i=MAX; i>0; i--) {
//       printf("Address of Matriz[%d] = %x\n", i-1, ptr ); ////////EMPIEZA DESDE EL ÚLTIMO CASILLERO DE LA MATRIZ..
//       printf("Value of Matriz[%d] = %d\n", i-1, *ptr );  ////////..HASTA EL PRIMERO
//
//       /* move to the previous location */
//       ptr--;
//    }
//
//    return 0;
// }
