////////////////////////////////////////Esto es una Subrutina: CALL BY REFERENCE!

#include <stdio.h>
#include <time.h>


void ConseguirSEGUNDOS(unsigned long *par);


int main () {
   unsigned long Segundos;//UNSIGNED es porque los segundos nunca son negativos, y LONG porque son muchos segundos
   ConseguirSEGUNDOS( &Segundos );//LE PASAMOS UNA DIRECCIÓN A LA FUNCIÓN, ES DECIR, EL VALOR DE UN POINTER!

   printf("Number of seconds: %ld\n", Segundos );// ld     (l: números grandes)  (d: números enteros en base decimal)
   return 0;
}




void ConseguirSEGUNDOS(unsigned long *par) {
   /* get the current number of seconds */
   *par = time(NULL);//GUARDAMOS LOS SEGUNDOS EN LA DIRECCIÓN: par=&Segundos //NOTA: NO SE COLOCA LA DIRRECCIÓN PORQUE YA SE LA PASÓ LA FUNCIÓN MAIN!!!!
   return;//(Esta línea no es necesaria)
}




















//
