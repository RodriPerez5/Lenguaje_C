/*
     ¡CALL BY REFERENCE!
  This method copies the address of an argument into the formal parameter. Inside the function, the address is used
to access the actual argument used in the call. This means that changes made to the parameter affect the argument.
  To pass a value by reference, argument pointers are passed to the functions just like any other value. So accordingly
you need to declare the function parameters as pointer types as in the following function FuncionSwap(), which exchanges the
values of the two integer variables pointed to, by their arguments.  /(swap in spanish means: intercambiar )

*/

#include <stdio.h>

/* function definition to swap the values */
void FuncionSwap(int *x, int *y) {                        //LE PONEMOS void A LA SUBRUTINA!
   *y+=22;
   printf("El pointer x apunta la dirección en donde está guardado el valor:         %d\n", *x);
   printf("El pointer y apunta la dirección en donde está guardado el valor:         %d\n", *y);
   int temp = *x;    /* save the value (a=100) at address x */
   *x = *y;      /* put y into x */
   *y = temp;    /* put temp into y */
   printf("Ahora, el pointer x apunta la dirección en donde está guardado el valor: %d\n", *x);
   printf("Ahora, el pointer y apunta la dirección en donde está guardado el valor: %d\n", *y);
   return;//(Esta línea no es necesaria)    ////No nos debe retornar nada
}



/* function declaration */
//void swap(int *x, int *y);

int main () {
   /* local variable definition */
   int a = 100;
   int b = 200;
   printf("Before swap, value of a = %d\n", a );
   printf("Before swap, value of b = %d\n", b );

   /* calling a function to swap the values.
      * &a indicates pointer to a ie. address of variable a and
      * &b indicates pointer to b ie. address of variable b.
   */
   FuncionSwap(&a, &b);//En todas las CALL BY REFERENCE Nunca colocamos: algo= UnaSubrutina
   printf("After swap, value of a = %d\n", a );//AQUÍ VEMOS QUE LOS VALORES DE a Y b SÍ SE MODIFICAN AL PASAR POR..
   printf("After swap, value of b = %d\n", b );//..LA Funcion, YA QUE HICIMOS UNA: ¡CALL BY REFERENCE!

   return 0;
}







//
