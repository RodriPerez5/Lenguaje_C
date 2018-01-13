#include <stdio.h>
#include <stdlib.h> //Para incluir:    rand()%MaxValor    y    srand(ValorSemilla)   --> Función de generación ramdom de números desde cero hasta MaxValor, y función que le da un valor semilla a la rand.
#include <time.h> //Para incluir:    time(NULL) --> Es una función para saber la hora actual del sistema.


int main() {
//Declaracion de variables
  int NumeroAletorio, Cantidad, Contador;
  int SegundosDelSistema = time(NULL);///Es lo mismo que hacer:    time_t SegundosDelSistema = time(NULL);  //This macro 'NULL' is the value of a null pointer constant.

//Semilla de rand();
  srand(SegundosDelSistema); ///SI EJECUTAMOS DOS O MÁS VECES EN UN MISMO SEGUNDO --->   !!ENTONCES rand NOS VA A DAR EXACTAMENTE LOS MISMOS NÚMEROS!!

//Recogemos por teclado la cantidad de números que quiere el usuario.
  printf("Ingrese la cantidad de numeros aleatorios que desea generar: \n");
  scanf("%d", &Cantidad);
  printf("\n");

//Generamos un ciclo que se repite la cantidad de veces indicada. En cada vuelta del ciclo se genera y se imprime un número aleatorio.
  for(Contador=0 ; Contador<Cantidad ; Contador++) {
      NumeroAletorio = rand()% 1000; //Here the funcion rand() returns a random number in the range of 0 to (MaxValor-1).//Para definir otro rango, simplemente restamos o sumamos un número, y ese número va ha ser nuestro nuevo MinValor:     // ((rand()%MaxValor) - MinValor) -->  MaxValor=(MinValor/2)+1          // ((rand()%MaxValor) + MinValor) -->  MaxValor=(MinValor*2)
      printf(" %d", NumeroAletorio);
  }
  printf("\n\n");
  return 0;
}
