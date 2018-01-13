/*
 * 	DESCRIPCION:
 * 	Ejemplo de multiprocessing
 *
 * 	Creado el 29/09/2012
 *
 * 	Informatica - Ingenieria en Mecatronica
 *  Facultad de Ingenieria - Universidad Nacional de Cuyo
 *
 *  Autor: Dr. Ing. Martin G. Marchetta
 *
 * */

 //                     gcc -lpthread multiPROCESSING.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>//Biblioteca para multiprocessing (fork)
#include <signal.h>//Biblioteca para enviar senales a los procesos (kill)
#include <bits/signum.h>//Biblioteca conconstantes para los tipos de senales
//Bibliotecas relacionadas con Semaforos:
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <sys/wait.h>

#define ID_Semaforo "/Semaforo_Prueba"//TANTO  ID_Semaforo  COMO  /Semaforo_Prueba(nunca lo usamos)   PUEDEN TENER CUALQUIER NOMBRE
#define ENTRADA_PIPE 0//CORRESPONDE A LECTURA
#define SALIDA_PIPE 1//CORRESPONDE A ESCRITURA


void Escribe_en_buffer(int pid, int Extremo_tuberia) {
  char mensaje[100];
  sem_t* Semaforo;
  printf("EXTREMO DE LA TUBERIA:  %d", Extremo_tuberia);//ESTA LÍNEA NUNCA SE IMPRIME!!!!!!!!!!!!!!!!!!!!!!!!!!! PREGUNTAR PORQUE

  /* Creamos el Semaforo que usarán los hijos para coordinar la transmision de informacion. Al crear el Semaforo:
	 	 1. O_CREAT indica que se cree el Semaforo si no existe
	 	 2. Permitimos al usuario "dueño" leer (S_IRUSR) y escribir (S_IWUSR) sobre el Semaforo
	 	 3. Permitimos los usuarios del grupo del "dueno" leer (S_IRGRP) y escribir (S_IWGRP) sobre el Semaforo..
	      ..como a los usuarios de su grupo leer/escribir en el. Inicializamos el Semaforo a 1*/
  Semaforo = sem_open(ID_Semaforo, O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP, 1);//Tamb. podemos poner NULL EN LUGAR DE:  ID_Semaforo

  while(1) {
	  //Generamos el texto a transmitir al padre:
	  sprintf(mensaje, "Hijo %d: %d\n", pid, rand()%100);

	  //Down sobre el Semaforo (lo bloqueamos) para la escritura:
	  sem_wait(Semaforo);

	  //Enviamos el mensaje al padre:
	  write(Extremo_tuberia, mensaje, sizeof(mensaje));

	  //Liberamos el Semaforo:
	  sem_post(Semaforo);

	  usleep(200000);//Sleep 200 ms (200000 microsegundos)
  }
}


int main(void) {
	int Tuberia[2]; //Identificador de la tuberia//Descriptores de archivos (handlers) para comunicación entre procesos
	pid_t pid_escritor_1; //PID (Process ID) del primer hijo (escritor)
	pid_t pid_escritor_2; //PID del segundo hijo (escritor)
	pid_t pid_escritor_3; //PID del tercer hijo: captura seleccion del usuario e informa al padre para terminar el programa (escritor)
	sem_t* Semaforo;

	//Creamos la tuberia (pipe). Un extremo es para escribir, el otro para leer. Estos descriptores de archivo seran heredados por los procesos..
	//..hijos, por lo que los hijos pueden escribir para que el padre pueda leer, o viceversa.

  pipe(Tuberia);
  // printf("TUBERIAAAA 0: %d\n", Tuberia[ENTRADA_PIPE]);/// Tuberia[0]=3 VERrrrrrrrrrrr QUE ONDA
  // printf("TUBERIAAAA 1: %d\n", Tuberia[SALIDA_PIPE]);/// Tuberia[1]=4 VERrrrrrrrrrrr QUE ONDA

	//Creamos el primer hijo
	pid_escritor_1 = fork();
	if(pid_escritor_1 == -1){
		perror("Error al crear proceso hijo 1");
		return 1;
	}
	else if(pid_escritor_1 == 0){  //"Soy" el proceso HIJO 1 (luego de fork, el proceso hijo toma el valor 0 en el process id devuelto)
    //El hijO cierra el extremo de la tubería que no utilizará:
		close(Tuberia[ENTRADA_PIPE]);//Cerramos el "lado" de entrada de la tuberia (los hijos solo le transmiten al padre, la tuberia es half-duplex):
		int pid1=1;
		Escribe_en_buffer(pid1, Tuberia[SALIDA_PIPE]);
    // printf("EXTREMOOOOO DE LA TUBERIA:  %d", Tuberia[SALIDA_PIPE]);//ESTA LÍNEA NUNCA SE PRINTEA!!!!!!!!!!!!!!!!!!!!!!!!!!!
	}
	else{ //"Soy" el proceso PADRE
		//Creamos el segundo hijo:
		pid_escritor_2 = fork();
		if(pid_escritor_2 == -1){
			perror("Error al crear proceso hijo 2");
			return 1;
		}
		else if(pid_escritor_2 == 0){  //"Soy" el proceso HIJO 2
			close(Tuberia[ENTRADA_PIPE]);//Cerramos el "lado" de entrada de la tuberia (los hijos solo le transmiten al padre, la tuberia es half-duplex)
			int pid2=2;
			Escribe_en_buffer(pid2, Tuberia[SALIDA_PIPE]);
		}
		else{ //Soy el PADRE
			//Creamos el tercer hijo, que captura cuando el usuario toca una tecla para termianr
			pid_escritor_3 = fork();
			if(pid_escritor_3 == -1){
				perror("Error al crear proceso hijo 3");
				return 1;
			}
			else if(pid_escritor_3 == 0){  //"Soy" el proceso HIJO 3
				close(Tuberia[ENTRADA_PIPE]);//Cerramos el "lado" de entrada de la tuberia (los hijos solo le transmiten al padre, la tuberia es half-duplex)

        /* Creamos el Semaforo que usaran los hijos para coordinar la transmision de informacion. Al crear el Semaforo:
				 	 1. O_CREAT indica que se cree el Semaforo si no existe
				 	 2. Permitimos al usuario "dueño" leer (S_IRUSR) y escribir (S_IWUSR) sobre el Semaforo
				 	 3. Permitimos los usuarios del grupo del "dueno" leer (S_IRGRP) y escribir (S_IWGRP) sobre el Semaforo
				   como a los usuarios de su grupo leer/escribir en el. Inicializamos el Semaforo a 1*/
				Semaforo = sem_open(ID_Semaforo, O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP, 1);

        getchar();//(Es lo mismo si esta línea la colocamos antes del sem_open)

  			//Down sobre el Semaforo para la escritura
				sem_wait(Semaforo);

				//Informamos al padre que el usuario detuvo la ejecucion
				write(Tuberia[SALIDA_PIPE], "0", 1);

				sem_post(Semaforo);
			}
			else{ //Soy el PADRE
				close(Tuberia[SALIDA_PIPE]);//Cerramos el "lado" de salida de la tuberia (el padre solo recibe datos de los hijos, la tuberia es half-duplex)

				/* Creamos el Semaforo que usarán los hijos para coordinar la transmision de informacion. Al crear el Semaforo:
				 	 1. O_CREAT indica que se cree el Semaforo si no existe
				 	 2. Permitimos al usuario "dueno" leer (S_IRUSR) y escribir (S_IWUSR) sobre el Semaforo
				 	 3. Permitimos los usuarios del grupo del "dueno" leer (S_IRGRP) y escribir (S_IWGRP) sobre el Semaforo
				   como a los usuarios de su grupo leer/escribir en el. Inicializamos el Semaforo a 1*/
				Semaforo = sem_open(ID_Semaforo, O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP, 1);

				//Mostramos por pantalla lo que nos mandan los procesos hijo:
				char buffer[100];
				while(1){ //CON EL NÚMERO 1 (No con otro número) SE CREA UN 'WHILE INFINITO' !
					read(Tuberia[ENTRADA_PIPE], buffer, sizeof(buffer));
					if(buffer[0] != '0')
						printf("%s", buffer);
					else{
						//Terminamos todos los procesos hijos
						kill(pid_escritor_1, SIGTERM);
						kill(pid_escritor_2, SIGTERM);
						kill(pid_escritor_3, SIGTERM);

						//Esperamos a que los procesos terminen (esto no necesariamente es inmediato)
						int Status;
						waitpid(pid_escritor_1, &Status, 0);
						waitpid(pid_escritor_2, &Status, 0);
						waitpid(pid_escritor_3, &Status, 0);

						//Cerramos el descriptor del pipe abierto
						close(Tuberia[ENTRADA_PIPE]);

						//Cerramos el Semaforo
						sem_close(Semaforo);

						//Le indicamos al kernel de linux que el Semaforo ya no se usa.
						//IMPORTANTE: dado que los Semaforos sirven para sincronizar procesos independientes, los Semaforos no se liberan al terminar
						//el proceso. Por lo tanto es necesario hacerlo explicitamente. De lo contrario esa memoria queda ocupada hasta que se reinicia
						//el sistema.
						sem_unlink(ID_Semaforo);

						//Salimos
						printf("\nEjecucion finalizada con exito. Bye!\n");
						break;//ESTE break ES PARA SALIR DEL WHILE, Y QUE NO SE SIGA IMPRIMIENDO EL Bye! eternamente.
					}
				}
			}

		}
	}


	return 0;
}
