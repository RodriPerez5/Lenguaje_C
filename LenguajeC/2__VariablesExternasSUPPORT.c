

#include <stdio.h>


extern int CoNtAdOr;// Aquí SÍ o SÍ le tenemos que decir qué variable (externa) vamos a incorporar.


void EscribirDelExterior(void) {
   printf("CoNtAdOr es: %d\n", CoNtAdOr);
}
