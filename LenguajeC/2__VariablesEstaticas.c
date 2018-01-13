#include <stdio.h>


/* function declaration */
void Func(void);


/*
 The static modifier may also be applied to GLOBAL VARIABLES. When this is done, it causes that variable's scope to be
restricted to the file in which it is declared.
 In C programming, when static is used on a global variable, it causes only one copy of that member to be shared by all
the objects of its class. -->((''ENTENDER MEJOR''))
*/
static int count = 5; /* Global Static Variable */  // ''NO PASA NARANJA SI NO PONEMOS static EN ESTA LÍNEA''


int main() {
  //printf("  YO1: %d\n", count);
   while(count--) {////(Esta condición -- significa que se entrará al while hasta que count se haga cero) //Si count fuera negativo entonces tendríamos que reemplazar -- por ++)
      Func();
   }
   //printf("  YO2: %d\n", count);
   return 0;
}




/*
 The static storage class instructs the compiler to keep a LOCAL VARIABLE in existence during the life-time of the program
instead of creating and destroying it each time it comes into and goes out of scope:
*/
/* function definition */
void Func( void ) {
   static int i = 5; /* Local Static Variable */ //SI NO COLOCARAMOS static ENTONCES i SIEMPRE SE IMPRIMIRÍA COMO 6!!!!
   i++;
   printf("i is %d and count is %d\n", i, count);
}










//
