
#include <stdio.h>

int main () {



//////////////////////////////////////////MATRIZ CON VALORES NUMÉRICOS, USANDO POINTERS////////////////////////////////////////////////////////
   int MAX = 3;
   int Matriz[] = {10, 100, 200};
   int *ptr[MAX];//It declares ptr as an array of MAX integer pointers. Thus, each element in ptr, holds a pointer to an int value.
   int i;
   for ( i=0 ; i<MAX ; i++) {
      ptr[i] = &Matriz[i]; /* assign the address of each integer of each the Matriz*/
   }

   for ( i=0 ; i<MAX ; i++) {
      printf("Address of Matriz[%d]= %x\n", i, &Matriz[i] );
   }
   printf("\n");
  //  for ( i=0 ; i<MAX ; i++) {
  //     printf("Address of Matriz[%d]= %p\n", i, &Matriz[i] );
  //  }
  //  printf("\n");
  //  for ( i=0 ; i<MAX ; i++) {
  //     printf("Address of Matriz[%d]= %x\n", i, ptr[i] );
  //  }
  //  printf("\n");
   for ( i=0 ; i<MAX ; i++) {
      printf("Address of Matriz[%d]= %p\n", i, ptr[i] );
   }
   printf("\n");
   for ( i=0 ; i<MAX ; i++) {
      printf("Value of Matriz[%d]= %d\n", i, *ptr[i] );
   }











   printf("____________________________________________________________________________________________\n");
   /*
   You can also use an array of pointers to character to store a list of strings as follows −
   */
   //////////////////////////////////////////MATRIZ CON CADENAS DE CARACTERES, USANDO POINTERS////////////////////////////////////////////////////////
   //                             (SIN Utilizar POINTERS NO Se Pueden Hacer Cadenas De Caracteres!!!)
   int MAXIMO = 4;

      char *names[] = { "Zara Ali",      //''ESTA NOTACIÓN NO SE PUEDE HACER CON VALORES NUMERICOS''
                        "Hina Ali",
                        "Nuha Ali",
                        "Sara Ali" };

      for ( i=0 ; i<MAXIMO ; i++) {
         printf("Address of names[%d] = %p\n", i, names[i] );//Indica la dirección del primer caracter(el [0]) de cada cadena.
      }
      printf("\n");
      for ( i=0 ; i<MAXIMO ; i++) {
         printf("Value of names[%d] = %s\n", i, names[i] );
      }











   return 0;
}
