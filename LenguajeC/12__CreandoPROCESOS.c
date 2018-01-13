


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
  //"Soy" el proceso PADRE("PRINCIPAL")
  printf(" Soy el proceso PADRE(PRINCIPAL)\n\n");

	pid_t pid_HIJO_1;
	pid_t pid_HIJO_2;
	pid_t pid_HIJO_3;

  pid_HIJO_1 = fork();
	if(pid_HIJO_1 == -1){
		perror("Error al crear proceso hijo 1\n");
		return 1;
	}
	else if(pid_HIJO_1 == 0){//"Soy" el proceso HIJO 1
      /* CODIGO A EJECUTAR SOLO POR EL PROCESO HIJO 1 */
      printf(" Soy el proceso HIJO 1.  pid HIJO 1= %d\n", pid_HIJO_1);
  }
	else{ //"Soy" el proceso PADRE1
    /* CODIGO A EJECUTAR SOLO POR EL PROCESO PADRE */
    printf(" Soy el proceso PADRE1.  pid PADRE1= %d\n", pid_HIJO_1);


    pid_HIJO_2 = fork();
    if(pid_HIJO_2 == -1){
			perror("Error al crear proceso hijo 2\n");
			return 1;
		}
		else if(pid_HIJO_2 == 0){//"Soy" el proceso HIJO 2
        /* CODIGO A EJECUTAR SOLO POR EL PROCESO HIJO 2 */
        printf(" Soy el proceso HIJO 2.  pid HIJO 2= %d\n", pid_HIJO_2);
		}
		else{ //Soy el PADRE2
      /* CODIGO A EJECUTAR SOLO POR EL PROCESO PADRE */
      printf(" Soy el proceso PADRE2.  pid PADRE2= %d\n", pid_HIJO_2);


      pid_HIJO_3 = fork();
      if(pid_HIJO_3 == -1){
				perror("Error al crear proceso hijo 3\n");
				return 1;
			}
			else if(pid_HIJO_3 == 0){//"Soy" el proceso HIJO 3
           /* CODIGO A EJECUTAR SOLO POR EL PROCESO HIJO 3 */
           printf(" Soy el proceso HIJO 3.  pid HIJO 3= %d\n", pid_HIJO_3);
			}
			else{ //Soy el PADRE
        /* CODIGO A EJECUTAR SOLO POR EL PROCESO PADRE */
        printf(" Soy el proceso PADRE3.  pid PADRE3= %d\n", pid_HIJO_3);
			}

    }
  }

  // printf("\n###########################################\n");//ESTA LÍNEA SE EJECUTA 4 VECES(Una en el Padre y las otras 3 en cada hijo)
	return 0;
}
/* SE OBTIENE:

 Soy el proceso PADRE(PRINCIPAL)                   //Esta línea siempre es igual en cada ejecución
                                                   
 Soy el proceso PADRE1.  pid PADRE1= 16898         //Esta línea siempre es igual en cada ejecución
 Soy el proceso HIJO 1.  pid HIJO 1= 0             //Esta línea varía de posición con cada ejecución
 Soy el proceso PADRE2.  pid PADRE2= 16899         //Esta línea varía de posición con cada ejecución
 Soy el proceso PADRE3.  pid PADRE3= 16900         //Esta línea varía de posición con cada ejecución
 Soy el proceso HIJO 2.  pid HIJO 2= 0             //Esta línea varía de posición con cada ejecución
 Soy el proceso HIJO 3.  pid HIJO 3= 0             //Esta línea varía de posición con cada ejecución
*/



















//
