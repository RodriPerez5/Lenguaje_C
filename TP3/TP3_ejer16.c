/*
Repita el ejercicio anterior, pero utilice “struct” (tipo de dato complejo definido por el
usuario) como estructura de datos.
*/
/*
 Un sistema en un parque eólico predice la producción de energía del día siguiente Dt+1. La
 predicción se realiza promediando la producción de energía en el día Dt, y luego
 promediando esta producción promedio en Dt con la producción promedio de los 19 días
 anteriores. El precio de venta del MW es de U$D 100. Utilice “struct” (tipo de dato complejo definido por el
 usuario) como estructura de datos como estructura de datos.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Vector{ int c0; int c1; int c2; int c3; int c4; };

int main() {
   int EnergiaProducidaEnCadaHoraDelDiaDt, EnergiaPromedioDelDiaDt=0;
   int SegsDelSistema=time(NULL);
   srand(SegsDelSistema);
   for (int i=0; i<24; i++) {
      EnergiaProducidaEnCadaHoraDelDiaDt = rand()%6;
      printf("EnergiaProducidaEnCadaHoraDelDiaDt: %d\n", EnergiaProducidaEnCadaHoraDelDiaDt);
      EnergiaPromedioDelDiaDt+=EnergiaProducidaEnCadaHoraDelDiaDt;
      printf("EnergiaPromedioDelDiaDt: %d\n", EnergiaPromedioDelDiaDt);
   }

   printf("Hoy se produjeron: %dMW\n", EnergiaPromedioDelDiaDt);
   printf("La producción de energía promedio en cada uno de los 19 días anteriores y hoy fue: \n");
   struct Vector f[20];
   int Sum=0;
   for (int i=0; i<4; i++) {
      f[i].c0 = (rand()%40) + 40;
      f[i].c1 = (rand()%40) + 40;
      f[i].c2 = (rand()%40) + 40;
      f[i].c3 = (rand()%40) + 40;
      if ( i==3 ) {
         f[i].c4 = EnergiaPromedioDelDiaDt ;
      }else {
          f[i].c4 = (rand()%40) + 40;
       }
       printf("\t%dMW\t%dMW\t%dMW\t%dMW\t%dMW\t",  f[i].c0, f[i].c1, f[i].c2, f[i].c3, f[i].c4 );
       Sum+= f[i].c0+f[i].c1+f[i].c2+f[i].c3+f[i].c4;
       printf("\n");
   }
   int EnergiaPromedioDelDiaDtmas1 = Sum/20;
   printf("Mañana se predice que se producirán: %dMW\n", EnergiaPromedioDelDiaDtmas1);

  return 0;
}











//
