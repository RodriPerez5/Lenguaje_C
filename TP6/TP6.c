//Rehacer implementando la variable mutex



//      gcc -lpthread TP6.c

#include <pthread.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>		//Sockets
#include <arpa/inet.h>		//Sockets
#include <unistd.h> 	 	//Biblioteca para multiprocessing (fork)
#include <signal.h> 		//Biblioteca para enviar senales a los procesos (kill)
#include <bits/signum.h> 	//Biblioteca conconstantes para los tipos de senales
#include <sys/wait.h>
#include <string.h>			//memset

typedef int boolean;
#define TRUE 1
#define FALSE 0
boolean en_ejecucion;

#define MAX_LARGO_COLA 100
#define PUERTO_SERVER 3302

// #define SERVER 0
// #define CLIENTE 1
// int rolProceso;
int sd; //socket descriptor
int sd_aceptado;
int c;
char buffer_lectura[100];
char *datos[100];






void cliente(pid_t pidB, char *texto, int largo) {
	 int sd; //socket descriptor
	 en_ejecucion = 1;
	 // rolProceso = CLIENTE;
	 printf("Soy cliente %d\n", pidB);
	 //Creamos el socket:
	 //	AF_INET: Familia de protocolos TCP/IP
	 //	SOCK_STREAM: Servicio orientado a la conexion (normalmente protocolo TCP)
	 sd = socket(AF_INET, SOCK_STREAM, 0);
	 if (sd < 0) {
	 		perror("Error al crear socket (cliente)");
	 		abort();
	 }

	 //Creamos la configuracion de direccion para el socket
	 struct sockaddr_in direccionSocket; //Estructura para configurar el socket
	 memset(&direccionSocket, 0, sizeof(direccionSocket)); //Utilizamos memset para inicializar a 0 todos los bytes de la estructura de configuracion del socket
	 direccionSocket.sin_family = AF_INET; //Familia de direcciones de TCP/IP
	 inet_aton("127.0.0.1", &(direccionSocket.sin_addr)); //Especificamos la direccion IP al que se conectara el socket, y la convertimos al formato de la red
	 direccionSocket.sin_port = htons(PUERTO_SERVER); //Especificamos el puerto TCP al que se conectara el socket, y lo convertimos al byte order de la red

	 //Establecemos conexion con el server
	 int conectado;
	 do{
	 	 sleep(1);//Es para esperar a que el proceso B cree el socket y se bloquee esperando conexiones
	 	 conectado = connect(sd, (struct sockaddr *) &direccionSocket, sizeof(direccionSocket));
	 }while (conectado < 0);

	 //char buffer_lectura[10];
	 char buffer_envio[100];
	 sprintf(buffer_envio, "%s", texto);

	 printf("Cliente envia: %s", buffer_envio);
	 send(sd, buffer_envio, sizeof(buffer_envio), 0);
	 getchar();
	 close(sd);
}







char *leer_archivo(const char *filename) {
	long int size = 0;
	FILE *file = fopen(filename, "r");

	if(!file) {
		fputs("File error.\n", stderr);
		return NULL;
	}

	fseek(file, 0, SEEK_END);//The fseek function is used to move the pointer to any position within the file.(En este caso lo mueve hasta el final del texto)
	size = ftell(file);//The ftell function lets the user to know the current location of the file pointer.
	rewind(file);//The rewind function lets the user to move the file pointer again to the beginning of the file.

	char *texto = (char *) malloc(size+1);
	texto[size]='\0';

	if(!texto) {
		fputs("Memory error.\n", stderr);
		return NULL;
	}
	//size_t Nbloques = fread(texto, 10, size/10, file);
	if(fread(texto, 1, size, file ) != size) {
		fputs("Read error.\n", stderr);
		return NULL;
	}
	//printf("hay bloques: %d \n",Nbloques );
	fclose(file);
	return texto;
}





void *save_thread() {
	FILE *file = fopen("mensaje2.txt", "r+");// lectura, escritura.

	if(!file) {
		fputs("File error.\n", stderr);
	}
	//fputs( buffer_lectura, file );
	if(fputs( buffer_lectura, file )<0) {
		fputs("Writing error.\n", stderr); //(Si no le doy permiso de escritura, da este error)
	}
	else{
		printf("Los datos recibidos se guardaron correctamente.\n");
	}

	return NULL;
	fclose(file);
}






void *print_thread(){
	int i=0;
	if (c > 0) {
		while(en_ejecucion) {
			if(i==0) {
				printf("Servidor t2  recibio: '%s'\n", buffer_lectura);
			}
			i++;
			sleep(5);
		}
	}
	return NULL;
}






void *bloques() {
	 while (en_ejecucion) {
			//Ahora intentamos leer los bytes transferidos. El proceso se bloquea si no hay nada que
			c = recv(sd_aceptado, buffer_lectura, sizeof(buffer_lectura), 0);

			//Esta verificacion solo se necesita para minimizar mensajes y ejecucion si se modifica la bandera en la mitad del bucle
			if (c > 0) {
				 //printf("Servidor recibio %d: '%s'\n", c, buffer_lectura);
				 printf("Servidor t1 recibio %d\n", c);
			}
			sleep(1);
			c=0;
	 }
	 //Cerramos el nuevo socket creado con accept
	 close(sd_aceptado);

	 //Cerramos el socket original
	 close(sd);
	 return NULL;
}







void servidor(pid_t pidB) {
	 en_ejecucion = 1;

	 // rolProceso = SERVER;
	 printf("Soy servidor %d\n", pidB);
	 //Creamos el socket:
	 //	AF_INET: Familia de protocolos TCP/IP
	 //	SOCK_STREAM: Servicio orientado a la conexion (normalmente protocolo TCP)
	 sd = socket(AF_INET, SOCK_STREAM, 0);
	 if (sd < 0) {
	 	  perror("Error al crear socket (servidor)");
	 	  abort();
	 }

	 //Creamos la configuracion de direccion para el socket
	 struct sockaddr_in direccionSocket; //Estructura para configurar el socket
	 memset(&direccionSocket, 0, sizeof(direccionSocket)); //Utilizamos memset para inicializar a 0 todos los bytes de la estructura de configuracion del socket
	 direccionSocket.sin_family = AF_INET; //Familia de direcciones de TCP/IP
	 inet_aton("127.0.0.1", &(direccionSocket.sin_addr)); //Especificamos la direccion IP al que se conectara el socket, y la convertimos al formato de la red
	 direccionSocket.sin_port = htons(PUERTO_SERVER); //Especificamos el puerto TCP al que se conectara el socket, y lo convertimos al byte order de la red

	 //Enlazamos el socket con la direccion local
	 if (bind(sd, (struct sockaddr *) &direccionSocket, sizeof(direccionSocket)) < 0) {
	 		perror("Error al enlazar socket al puerto (servidor)");
	 		abort();
	 }

	 //Configuramos el socket para que escuche conexiones, y configuramos una cantidad maxima MAX_LARGO_COLA de conexiones que podemos poner en la cola
	 listen(sd, MAX_LARGO_COLA);

	 //Creamos las variables requeridas para esperar una conexion
	 struct sockaddr_in direccionSocketCliente;
	 socklen_t longitudDireccionCliente;

	 //El proceso se bloquea esperando una conexion
	 sd_aceptado = accept(sd, (struct sockaddr *) &direccionSocketCliente, &longitudDireccionCliente);

	 pthread_t t1;
	 pthread_t t2;
	 pthread_t t3;
	 if (pthread_create(&t1, NULL, bloques, NULL)) {
	 		printf("Error al crear el t1.\n");
	 		abort();
	 }
	 if (pthread_create(&t2, NULL, print_thread, NULL)) {
	 		printf("Error al crear el t2.\n");
	 		abort();
	 }
	 if (pthread_create(&t3, NULL, save_thread, NULL)) {
	 		printf("Error al crear el t3.\n");
	 		abort();

	 //Esperamos a que termine el hilo secundario, para evitar que quede colgado como un zombie thread
	 pthread_join(t3, NULL);
	 pthread_join(t2, NULL);
	 pthread_join(t1, NULL);
}







//Esta funcion maneja las señales que recibe del kernel ("interrupciones de software")
void manejador_signals(int signal_type) {
		printf("Terminando proceso\n");
		en_ejecucion = FALSE;
}





int main() {
		pid_t pidB;
		pidB = fork();

		//Registramos con el kernel la funcion que maneja las signals
		signal(SIGTERM, manejador_signals);

		switch (pidB) {
		  case -1:
			  perror("No se ha podido crear el proceso hijo\n");
			  break;
		  case 0://Proceso B (Servidor)
			  printf("Soy el hijo B %d\n", pidB);
			  printf("Puerto: %d\n", PUERTO_SERVER);
			  servidor(pidB);
			  break;
		  default://Proceso A (Cliente)
			  printf("Soy el padre %d\n", pidB);

			  char Mensaje[] = "mensaje.txt";
			  char *texto = leer_archivo(Mensaje);

			  printf(" El texto a transmitir es: %s\n", texto);

			  int largo = strlen(texto);//queria enviar el largo del texto para asignar memoria dinamicamente pero no pude enviar un struct
			  printf("El largo del texto es de %d bytes\n", largo);

			  cliente(pidB, texto, largo);

			  kill(pidB, SIGTERM);
			  break;
		}

		return 0;
}


















//
