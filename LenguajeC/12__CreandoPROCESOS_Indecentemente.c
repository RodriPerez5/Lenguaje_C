//CUANTOS PROCESOS SE CREEAN?:                      OJO! NO COMPILAR CON  ctr+shift+b  DA CUALQUIERA!!!!
//NO HACER COMO EL SGTE PROGRAMA PORQUE OBTENEMOS MÁS DE UN PROCESO PADRE --> (ENTENDER QUE OCURRE CON MÁS DE UN SOLO PADRE)!!!!!!





// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
//
// int main() {
//   pid_t pid_A;
//   pid_t pid_B;
//   pid_t pid_C;
//   // printf("                        ##########\n");
//
//   pid_A = fork();
//
//   pid_B = fork();
//
//   pid_C = fork();
//
//   /* TODOS LOS PROCESOS CREADOS HASTA EL MOMENTO EJECUTARÁN, EN PSEUDO PARALELISMO, LO SIGUIENTE: */
//   printf(" A = %d         B = %d         C = %d\n", pid_A, pid_B, pid_C);//Esto nos muetra la mitad de procesos creados son..
//                                                                          //..padres(pid>0), y la otra mitad son hijos(pi==0)
//   // printf("                        ##########\n");
//
//
//   return 0;
// }//SE CREAN 2^N = 8 PROCESOS   Siendo N el nro de procesos






#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  pid_t pid_A;

  for (int i=0; i<4; i++) {
    pid_A = fork();

    printf("pid: A = %d\n", pid_A);//Es lo mismo si ponemos esta línea antes del fork
                                   //SI PRINTEAMOS DENTRO DEL FOR SE OBTIENE 30printeadas

  }//SI PUSIÉRAMOS DOS for(separados, de dos iteraciones cada uno), SE CREARÍAN TANTO LA MISMA CANT DE PROCESOS COMO DE PRINTEADAS

  // printf("pid: A = %d\n", pid_A);

  return 0;
  // }//SE CREAN 2^N = 16 PROCESOS   Siendo N el nro de procesos
}














//
