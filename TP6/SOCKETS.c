/*
 * 	DESCRIPCION:
 * 	Ejemplo de uso de sockets como mecanismo de comunicacion entre procesos (en el mismo host o en hosts remotos)
 *
 * 	Creado el 02/10/2012
 *
 * 	Informatica - Ingenieria en Mecatronica
 *  Facultad de Ingenieria - Universidad Nacional de Cuyo
 *
 *  Autor: Dr. Ing. Martin G. Marchetta
 *
 * */

 //      gcc -lpthread SOCKETS.c

#include <sys/socket.h>		//Sockets
#include <arpa/inet.h>		//Sockets
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 	 	//Biblioteca para multiprocessing (fork)
#include <signal.h> 		//Biblioteca para enviar senales a los procesos (kill)
#include <bits/signum.h> 	//Biblioteca conconstantes para los tipos de senales
#include <sys/wait.h>
#include <string.h>			//memset

typedef int boolean;
#define TRUE 1
#define FALSE 0
boolean en_ejecucion;

#define PUERTO_SERVER 3333
#define MAX_LARGO_COLA 100

#define SERVER 0
#define CLIENTE 1
int rolProceso;



//Esta funcion maneja las señales que recibe del kernel ("interrupciones de software")
void manejador_signals(int signal_type) {
  char rolProceso[10];
  if(rolProceso == SERVER)
	  strcpy(rolProceso, "Servidor");
  else//if(rolProceso == CLIENTE)
	  strcpy(rolProceso, "Cliente");

  if (signal_type == SIGTERM){
	  en_ejecucion = FALSE;
	  printf("%s: Señal SIGTERM recibida. Terminando proceso.\n", rolProceso);
  }
  else if (signal_type == SIGKILL){
	  en_ejecucion = FALSE;
	  printf("%s: Señal SIGKILL recibida. Terminando proceso.\n", rolProceso);
  }
  else
	printf("Señal desconocida. Ignorando...\n\n");
}



//Funcion que ejecuta el proceso servidor
void servidor() {
	int sd; //socket descriptor

	rolProceso = SERVER;

	//Creamos el socket:
	//	AF_INET: Familia de protocolos TCP/IP
	//	SOCK_STREAM: Servicio orientado a la conexion (normalmente protocolo TCP)
  //__protocol: (el único protocolo para la familia de prots. TCP/IP con servicio orientado a la conexion es TCP, por lo que se deja en cero)
	sd = socket(AF_INET, SOCK_STREAM, 0);
	if(sd < 0){
		 perror("Error al crear socket (servidor)");
		 abort();
	}

	//Creamos la configuracion de direccion para el socket
	struct sockaddr_in direccionSocket; 						//Estructura para configurar el socket
	memset(&direccionSocket, 0, sizeof(direccionSocket));//Utilizamos memset para inicializar a 0 todos los bytes de la estructura de configuracion del socket
	direccionSocket.sin_family = AF_INET; 				  //Familia de direcciones de TCP/IP
	inet_aton("127.0.0.1", &(direccionSocket.sin_addr));//Especificamos la direccion IP al que se conectara el socket, y la convertimos al formato de la red
	direccionSocket.sin_port = htons(PUERTO_SERVER);//Especificamos el puerto TCP al que se conectará el socket, y lo convertimos al byte order de la red

	//Enlazamos el socket con la direccion local
	if(bind(sd, (struct sockaddr *)&direccionSocket,sizeof(direccionSocket)) < 0) {
		perror("Error al enlazar socket al puerto (servidor)");
		abort();
	}

	//Configuramos el socket para que escuche conexiones, y configuramos una cantidad maxima MAX_LARGO_COLA de conexiones que podemos poner en la cola
	listen(sd, MAX_LARGO_COLA);

	//Creamos las variables requeridas para esperar una conexion
	struct sockaddr_in direccionSocketCliente;
	socklen_t longitudDireccionCliente;
	int sd_aceptado;  //socket creado automaticamente cuando se acepta una conexion

	//El proceso se bloquea esperando una conexion
	sd_aceptado = accept(sd, (struct sockaddr *)&direccionSocketCliente, &longitudDireccionCliente);

	char buffer_lectura[100];
	char buffer_envio[100];
	while(en_ejecucion){
		//Ahora intentamos leer los bytes transferidos. El proceso se bloquea si no hay nada que leer
		recv(sd_aceptado, buffer_lectura, sizeof(buffer_lectura), 0);

		//Esta verificacion solo se necesita para minimizar mensajes y ejecucion si se modifica la bandera en la mitad del bucle
		if(en_ejecucion){
			//Mostramos lo recibido por pantalla
			printf("Servidor recibio: '%s'\n", buffer_lectura);

			//Enviamos una respuesta al cliente
			sprintf(buffer_envio, "Respuesta = %d", rand());
			send(sd_aceptado, buffer_envio, strlen(buffer_envio), 0);
		}
	}

	//Cerramos el nuevo socket creado con accept
	close(sd_aceptado);

	//Cerramos el socket original
	close(sd);
}



//Funcion que ejecuta el proceso cliente
void cliente() {
	int sd; //socket descriptor

	rolProceso = CLIENTE;

	//Creamos el socket:
	//	AF_INET: Familia de protocolos TCP/IP
	//	SOCK_STREAM: Servicio orientado a la conexion (normalmente protocolo TCP)
	sd = socket(AF_INET, SOCK_STREAM, 0);
	if(sd < 0){
		perror("Error al crear socket (cliente)");
		abort();
	}

	//Creamos la configuracion de direccion para el socket
	struct sockaddr_in direccionSocket; 						//Estructura para configurar el socket
	memset(&direccionSocket, 0, sizeof(direccionSocket));//Utilizamos memset para inicializar a 0 todos los bytes de la estructura de configuracion del socket
	direccionSocket.sin_family = AF_INET; 					//Familia de direcciones de TCP/IP
	inet_aton("127.0.0.1", &(direccionSocket.sin_addr));//Especificamos la direccion IP al que se conectara el socket, y la convertimos al formato de la red
	direccionSocket.sin_port = htons(PUERTO_SERVER);  //Especificamos el puerto TCP al que se conectara el socket, y lo convertimos al byte order de la red

	//Establecemos conexion con el server
	int conectado;
	do{
		sleep(1);
		conectado = connect(sd, (struct sockaddr *)&direccionSocket,sizeof(direccionSocket));
	}while(conectado < 0);

	char buffer_lectura[100];
	char buffer_envio[100];
	while(en_ejecucion){
		//Enviamos mensaje al servidor
		sprintf(buffer_envio, "Mensaje = %d", rand());
		send(sd, buffer_envio, strlen(buffer_envio), 0);

		//Ahora intentamos leer los bytes transferidos. El proceso se bloquea si no hay nada que leer
		recv(sd, buffer_lectura, sizeof(buffer_lectura), 0);

		//Esta verificacion solo se necesita para minimizar mensajes y ejecucion si se modifica la bandera en la mitad del bucle
		if(en_ejecucion){
			//Mostramos lo recibido por pantalla
			printf("\t|--> Cliente recibio: '%s'\n", buffer_lectura);
		}

		usleep(100000);
	}

	close(sd);
}







int main(void) {
	pid_t pid_servidor;
	pid_t pid_cliente;

	//Inicializacion
	en_ejecucion=TRUE;

	//Registramos con el kernel la funcion que maneja las signals
	signal(SIGINT, manejador_signals);
	signal(SIGTERM, manejador_signals);

	pid_servidor = fork();
	if(pid_servidor == -1){
		printf("Error al iniciar servidor");
		return 1;
	}
	else if(pid_servidor == 0){
		servidor();
	}
	else{
		pid_cliente = fork();
		if(pid_cliente == -1){
			printf("Error al iniciar el cliente");
			return 1;
		}
		else if(pid_cliente == 0){
			cliente();
		}
		else{
			getchar();

			kill(pid_servidor, SIGTERM);
			kill(pid_cliente, SIGTERM);

			int Status;
			waitpid(pid_servidor, &Status, 0);
			waitpid(pid_cliente, &Status, 0);

			printf("\nEjecución terminada. Bye\n");
		}
	}

	return 0;
}






















//
