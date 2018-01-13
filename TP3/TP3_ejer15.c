/*
 Un sistema en un parque eólico predice la producción de energía del día siguiente Dt+1. La
 predicción se realiza promediando la producción de energía en el día Dt, y luego
 promediando esta producción promedio en Dt con la producción promedio de los 19 días
 anteriores. El precio de venta del MW es de U$D 100. Utilice una matriz (arreglo 2D) como
 estructura de datos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int EnergiaProducidaEnCadaHoraDelDiaDt, EnergiaPromedioDelDiaDt=0;
   int SegsDelSistema=time(NULL);
   srand(SegsDelSistema);
   for (int i=0; i<24; i++) {//(24 son las horas que tiene el día 'de hoy')
      EnergiaProducidaEnCadaHoraDelDiaDt = rand()%6;//Para obtener un prom de 2.5MW/hora colocamos un 6(¡No 5!) en el MaxValor del rand
      EnergiaPromedioDelDiaDt+=EnergiaProducidaEnCadaHoraDelDiaDt;//(Promediar los MW producidos en el día Dt es lo mismo que hacer..
   }                                                              //..la sumatoria de los MW producidos en cada hora del mismo día)

   printf("Hoy se produjeron: %dMW\n", EnergiaPromedioDelDiaDt);//El promedio de e° obtenida en el día Dt es de:  2.5MW/hs*24hs = 60MW

   printf("La producción de energía promedio en cada uno de los 19 días anteriores y hoy fue: \n");
   int EnergiaPromedioEnCadaUnoDeLos20DiasAnteriores[3][4], Sum=0;
   for (int i=0; i<4; i++) {
       printf("\t");
       for (int j=0; j<5 ; j++) {
           if ( i==3  && j==4 ) {
              EnergiaPromedioEnCadaUnoDeLos20DiasAnteriores[i][j] = EnergiaPromedioDelDiaDt ;
           }else {
              EnergiaPromedioEnCadaUnoDeLos20DiasAnteriores[i][j] = (rand()%40) + 40;
           }                                                        //Rango: [40,80]MW. El promedio en cada día es de 60MW
           printf("%dMW\t",  EnergiaPromedioEnCadaUnoDeLos20DiasAnteriores[i][j] );
           Sum+= EnergiaPromedioEnCadaUnoDeLos20DiasAnteriores[i][j];
       }
       printf("\n");
   }
   int EnergiaPromedioDelDiaDtmas1 = Sum/20;
   printf("Mañana se predice que se producirán: %dMW\n", EnergiaPromedioDelDiaDtmas1);

  return 0;
}















//
