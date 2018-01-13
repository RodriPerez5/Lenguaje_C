// La compañía de celulares “Chismefon” posee un mecanismo de cobro de llamadas por el
// cual mientras más se habla, menos se paga. De esta forma los primeros cinco minutos
// cuestan $ 1.00 c/u, los siguientes tres, $ 0.80 c/u, los siguientes dos minutos, $ 0.70 c/u, y a
// partir del décimo minuto, 0.50 c/u (los valores no incluyen IVA). Realice un programa para
// determinar el costo total de una llamada expresada en segundos.

#include <stdio.h>

int main() {
  printf("Ingrese la cantidad de segundos de la llamada:\n");
  float CantidadDeSegundos;//TENEMOS QUE PONER float Y NO int PORQUE LUEGO HACEMOS DIVISIÓN
  scanf("%f", &CantidadDeSegundos);     //OJO!: NO PONER \n luego del código:  %(letra) 
  float PrecioDeLaLlamada;
  if (CantidadDeSegundos<300) {
    PrecioDeLaLlamada=(CantidadDeSegundos/60)*1;
  }
  if ((300<=CantidadDeSegundos) && (CantidadDeSegundos<480)) {
    PrecioDeLaLlamada=((300/60)*1+((CantidadDeSegundos-300)/60)*0.80);
  }
  if ((480<=CantidadDeSegundos) && (CantidadDeSegundos<600)) {
    PrecioDeLaLlamada=(300/60)*1+(180/60)*0.80+((CantidadDeSegundos-480)/60)*0.70;
  }
  if (600<=CantidadDeSegundos) {
    PrecioDeLaLlamada=(300/60)*1+(180/60)*0.80+(120/60)*0.70+((CantidadDeSegundos-600))*0.50;
  }
  printf("El costo total de la llamada en dolares es:%f\n", PrecioDeLaLlamada);

  return 0;
}











//
