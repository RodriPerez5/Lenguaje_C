


#include <stdio.h>

/* function declaration */
double conseguirPromedio(int *Array, int TAMANIO);


int main () {
   /* an int array with 5 elements */
   int Balance[5] = {1000, 2, 3, 17, 50};
   double PROM;
   /* pass pointer to the array as an argument */
   PROM = conseguirPromedio( Balance, 5 ) ;/////////////////// NO SE PONE EL &  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!11
   /* output the returned value  */
   printf("Average value is: %f\n", PROM );
   return 0;
}




double conseguirPromedio(int *Array, int TAMANIO) {
  for (int i=0 ; i<TAMANIO ; i++) {
     printf("Value of Matriz[%d]= %d\n\n", i, Array[i] );//OJO, AHORA NO PONEMOS EL * ANTES DEL  Array[i]!!!-->[ESTO SOLO ES PARA CUANDO USAMOS ARRAYS Y EN UNA SUBFUNCIÓN]
  }
   int sum=0;
   for (int i=0 ; i<TAMANIO ; ++i) {
      sum+=Array[i];
   }
   return (double)sum/TAMANIO;//Es lo mismo que hacer:   //  double PROM = (double)sum/TAMANIO;
                                                         //  return PROM;
}












//
