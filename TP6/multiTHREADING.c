/*
 * 	DESCRIPCION:
 * 	Ejemplo de multithreading
 *
 * 	Creado el 24/09/2012
 *
 * 	Informatica - Ingenieria en Mecatronica
 *  Facultad de Ingenieria - Universidad Nacional de Cuyo
 *
 *  Autor: Dr. Ing. Martin G. Marchetta
 *
 * */

//                           gcc -lpthread multiTHREADING.c

#include <stdio.h>
#include <stdlib.h>//Para las funciones:  rand  y  abort
//Header para POSIX threads
#include <pthread.h>//  pthread_t         pthread_create   pthread_mutex_lock    pthread_cond_wait
                    //  pthread_mutex_t   pthread_join     pthread_mutex_unlock  pthread_cond_broadcast
                    //  pthread_cond_t
#include <unistd.h>//Para la función:  usleep
//Tamano del buffer
#define BUFFER_MAX 10

//Variable global compartida por todos los threads. Algunos threads escriben en el arreglo, y otros leen.
//La primera columan contiene el valor generado, la segunda columna contiene el ID del thread que lo genero
int buffer[BUFFER_MAX][2];

//Constante para la columna que contiene el valor generado
#define VALOR 0
//Constante para la columna que contiene el ID del thread
#define ID_THREAD 1

//Indica el siguiente elemento a escribir
int indice_escritura=0;
//Indica el siguiente elemento a leer (inicializado a -1 porque no hay elementos inicialmente)
int indice_lectura=-7;

//Mutex para acceder al buffer (para evitar problemas de concurrencia cuando multiples threads quieren acceder simultaneamente al buffer)
pthread_mutex_t mutex_buffer=PTHREAD_MUTEX_INITIALIZER;///  PTHREAD_MUTEX_INITIALIZER   ES ALGO YA DEFINIDO EN C!!!!!!!!

//Variable de condición para indicarle al lector que hay informacion en el buffer
pthread_cond_t hay_datos=PTHREAD_COND_INITIALIZER;///  PTHREAD_COND_INITIALIZER   ES ALGO YA DEFINIDO EN C!!!!!!!!

//Bandera que coordina la ejecucion de los threads. Mientras este activa, la ejecucion continua. Cuando se pone en FALSE, se interrumpen todos los threads
typedef int boolean;
#define TRUE 1
#define FALSE 0
boolean en_ejecucion;


//Esta funcion es llamada al crear cada thread que ESCRIBE en el buffer.
//El argumento es el n° que identifica al thread.
void *escribe_en_buffer(void *id_thread) {
  int i = *((int *)id_thread);

  while(en_ejecucion == TRUE) {
	  //Intentamos bloquear el mutex para entrar a la seccion critica
 	  pthread_mutex_lock(&mutex_buffer);//SEMAFOORO

    //Seccion critica
	  if(indice_escritura == BUFFER_MAX) {//Si el indice se sale del arreglo, lo ponemos a 0 nuevamente
 		  indice_escritura = 0;				    //
    }

 	  buffer[indice_escritura][VALOR] = rand()%1000;	//Generamos el nro aleatorio
	  buffer[indice_escritura][ID_THREAD] = i;	//Guardamos el id del thread asociado al valor
	  indice_escritura++;							//Actualizamos el indice

	  //Inicializa el indice de lectura
	  if(indice_lectura < 0) //(Para todo bucle: Si no colocamos los {} entonces solo toma la línea siguiente)
		  indice_lectura = 0;

    //Liberamos el mutex para permitir a otros threads acceder al buffer y al indice de escritura
    pthread_mutex_unlock(&mutex_buffer);

    //Si hemos llenado el elemento del buffer que debe leer el lector, le enviamos señal
    if(buffer[indice_lectura][VALOR] != -77) {///////////////////////////NECESARIO?..y pueda que se lea algún -77. PREGUNTARRRR
      pthread_cond_broadcast(&hay_datos);
    }
  }
  //El thread no devuelve nada al terminar...
  return NULL;
}


//Esta funcion es llamada al crear el thread de LECTURA del buffer. (Nota: No recibe parametros)
void *lee_buffer() {
	while(en_ejecucion == TRUE) {
    //Intentamos bloquear el mutex para entrar a la seccion critica
		pthread_mutex_lock(&mutex_buffer);

		if(indice_lectura == BUFFER_MAX) { 		//Si el indice se sale del arreglo, lo ponemos a 0 nuevamente
			indice_lectura = 0;
    }

		//Verificamos que el elemento a leer tenga valores en el buffer (si no, bloqueamos el thread)
		if(indice_lectura == -7)/////////////////////////Estas dos líneas no son necesarias porque los hilos de escritura empiezan..
			pthread_cond_wait(&hay_datos, &mutex_buffer);//..justo antes que el de lectura.
    else if(buffer[indice_lectura][VALOR] == -77) {
			pthread_cond_wait(&hay_datos, &mutex_buffer);
    }

		//Si llegamos aqui es porque hay datos en el buffer
		printf("Escritor %d: %d\n", buffer[indice_lectura][ID_THREAD], buffer[indice_lectura][VALOR]);
		buffer[indice_lectura][VALOR] = -77;		//Marcamos el dato leido como "eliminado"
		indice_lectura++;						//Actualizamos el indice de lectura

    usleep(70000);

	    //Liberamos el mutex
	    pthread_mutex_unlock(&mutex_buffer);
	}
	return NULL;
}


int main(void) {//AL main SE LO LLAMA:   Hilo Principal. Y los hilos que crea son sus hijos.
	//Handlers de los threads a ser creados
	pthread_t escritor1;//Es lo mismo si identificamos los threads fuera de toda función
	pthread_t escritor2;//Es lo mismo si identificamos los threads fuera de toda función
	pthread_t lector;//Es lo mismo si identificamos los threads fuera de toda función
	int escritor1_id = 1;
	int escritor2_id = 2;

	//Inicialización
	en_ejecucion = TRUE;
	int i;
	for(i = 0; i < BUFFER_MAX; i++) {
		buffer[i][VALOR] = -77;//Definimos toda la preimer columna de la matriz buffer con un nro negativo cualquiera
  }

	//Inicializacion de los threads de escritura     //Con &escritor1_id simplemente le pasamos un valor a la función del hilo
  if(pthread_create(&escritor1, NULL, escribe_en_buffer, &escritor1_id)) {//AL DEVOLVER UN NULL, ENTONCES NO SE ENTRA A ESTE if
		printf("Error al crear el escritor 1.\n");//""PERO SI HAY ALGÚN ERROR ENTONCES NO SE DUVUELVE NULL, Y POR LO TANTO SI SE ENTRA AL if""
		abort(); //Sale del programa y realiza un volcado del nucleo (muestra el estado completo del proceso con sus variables, instrucciones, etc.
	}
	if(pthread_create(&escritor2, NULL, escribe_en_buffer, &escritor2_id)) {
		printf("Error al crear el escritor 2.\n");
		abort();
	}

	  //Inicializacion del lector
	if(pthread_create(&lector, NULL, lee_buffer, NULL)) {
		printf("Error al crear el lector.\n");
		abort();
	}

	//EL THREAD PRINCIPAL QUEDA EN ESPERA de que el usuario presione el enter, y cuando esto ocurre cierra todos los threads y los unifica:
	getchar();

  en_ejecucion = FALSE;

	//Reunión de los 4 threads (los 2 escritores, el lector y el thread principal).
	//Esta llamada bloquea la ejecución del thread principal hasta que los otros 3 threads terminan
	if(pthread_join(escritor1, NULL) || pthread_join(escritor2, NULL) || pthread_join(lector, NULL)) {
		printf("Error reuniendo los threads de lectura y escritura con el thread principal.");
		abort();
	}
	else
	  printf("\nEjecucion finalizada con exito. Bye!\n");

	return 0;
}
























//
