/*  memoria dinámica
 * 	DESCRIPCION:
 * 	Ejemplos de manejo de tipos definidos por el usuario
 *
 * 	Creado el 23/09/2012
 *
 * 	Informatica - Ingenieria en Mecatronica
 *  Facultad de Ingenieria - Universidad Nacional de Cuyo
 *
 *  Autor: Dr. Ing. Martin G. Marchetta
 *
 * */
///  gcc -lm EjEst_MAIN.c  EjEst_MEMORIA_DINAMICA.c

#include "/home/rodri/INFORMATICA/LenguajeC/EjemploESTRUCTURAS_DATOS/EjEst_ESTRUCTURAs_DATOS.h"

//Definicion de un tipo de dato simple. (Le damos un Aleas("apodo") a un Nombre cualquiera)
//Normalmente conviene colocar esto en el header file o en un archivo fuente .c compartido, pero por cuestiones
//didacticas se lo coloca aqui:
typedef int boolean;
#define TRUE 1
#define FALSE 0

//Definicion de un tipo de dato complejo, para ser utilizado como lista enlazada
//Normalmente conviene colocar esto en el header file o en un archivo fuente .c compartido, pero por cuestiones
//didacticas se lo coloca aqui:
struct LISTA_SUBSISTEMAS {
	boolean activo;
	char nombre[50];
	struct LISTA_SUBSISTEMAS *siguiente;//Esta es la ÚNICA FORMA en que puede utilizarse la misma estructura como elemento de..
	                                    //..sí misma: como un APUNTADOR!!!. ESTO ES: UNA STRUC APUNTA A OTRA STRUC DEL MISMO FORMATO.
};

typedef struct LISTA_SUBSISTEMAS lista_subsistemas;









void ejemplo_memoria_dinamica() {
	printf("\n\n==========================================\n");
	printf("EJEMPLOS DE USO DE MEMORIA DINÁMICA\n");
	printf("==========================================\n\n");

	//Declaramos apuntadores de tipos simples, arreglos y estructuras complejas
	int *Entero;
	int *Vector_enteros;
	double **Matriz_double;
	struct LISTA_SUBSISTEMAS *subsistemas;//''DEFINIMOS A 'subsistemas' COMO UN APUNTADOR DEL TIPO DE VARIABLE: 'struct LISTA_SUBSISTEMAS'   ''







	//*******************************************************************
	//Reservamos memoria dinamicamente para un entero. Reservamos 1 elemento, cuyo tamaño en bytes es el tamaño de un entero:
	Entero = (int *)malloc(sizeof(int));///////////////////////ES AL CUETE PONER EL CAST:   (TipoDeVariable *)    SOLO ES PARA ORIENTARSE!
	*Entero = 10;
	printf("Entero dinámico:  %d\n\n", *Entero);

	free(Entero); //Liberamos la memoria del entero







	//*******************************************************************
	//Ahora reservamos un vector dinamicamente. Reservamos 10 elementos, cuyo tamaño en bytes es el tamaño de un entero:
	Vector_enteros = (int *)calloc(10, sizeof(int));//ES AL CUETE PONER EL CAST:   (TipoDeVariable *)    SOLO ES PARA ORIENTARSE
	int i;
	for(i = 0; i < 10; i++) {
		*(Vector_enteros+i) = i;//  *(Vector_enteros + i)    ES LO MISMO QUE PONER:   Vector_enteros[i]
	}
	printf("Arreglo dinamico: [ ");
	for(i = 0; i < 10; i++) {
		printf("%d ", *(Vector_enteros+i) );//  *(Vector_enteros + i)    ES LO MISMO QUE PONER:   Vector_enteros[i]
	}
	printf("]\n\n");

	free(Vector_enteros); //Liberamos la memoria del vector







	//*******************************************************************
	//Reservamos espacio dinamicamente para un arreglo 2D 10x10://''ESTO ES ASÍ: PRIMERO(**) RESERVAMOS UN VECTOR PARA PUNTEROS, Y LUEGO(*) RESERVAMOS OTRO VECTOR..
	                                                            //..DENTRO DE CADA COLUMNA DEL PRIMER VECTOR(vectores que son las columnas del array)''
	Matriz_double = (double **)calloc(10, sizeof(double *));//ES AL CUETE PONER EL CAST:   (double **)    SOLO ES PARA ORIENTARSE
	for(i=0; i < 10; i++) {                    //Y este * va?
		*(Matriz_double+i) = (double *)calloc(10, sizeof(double));//PONER:   *(Matriz_double+i)   ES LO MISMO QUE PONER:   Matriz_double[i]
	}                                                           //ES AL CUETE PONER EL CAST:   (double *)    SOLO ES PARA ORIENTARSE
	//Asignamos valores aleatorios, accediendo a los elementos con notacion indizada(como si fuera un arreglo):
	int j;
	for(i = 0; i < 10; i++) {
		for(j = 0; j < 10; j++) {    //PONER:   *(*(Matriz_double+i)+j)   ES LO MISMO QUE PONER:   Matriz_double[i][j]
			*(*(Matriz_double+i)+j) = (double)rand()/1000000;////Con el /100 simplemente se divide por 100, el rand() el cual por default tiene..
		}                                                  ////..un rango de números muy grande.
	}
	//Mostramos la matriz por pantalla utilizando el metodo de aritmetica de apuntadores:
	printf("Matriz dinamica:\n");
	for(i = 0; i < 10; i++) {
		for(j = 0; j < 10; j++){
			printf("%.2f   \t",  *(*(Matriz_double+i)+j)  );//PONER:   *(*(Matriz_double+i)+j)   ES LO MISMO QUE PONER:   Matriz_double[i][j]
		}
		printf("\n");
	}
	//Liberamos la memoria. Primero la segunda dimension...:
	for(i=0; i < 10; i++)
		free(*(Matriz_double+i));//PONER:   *(Matriz_double+i)   ES LO MISMO QUE PONER:   Matriz_double[i]
	//... y luego la primera dimension:
	free(Matriz_double);







	//*******************************************************************
	//Reservamos memoria dinamica para la estructura definida por el usuario:
	subsistemas = (lista_subsistemas *)malloc(sizeof(lista_subsistemas));//No usamos calloc, ya que malloc ya reserva la suma del tamaño de..
	                                                                     //..todos los tipos de variables de la estructura.
                                     //ES AL CUETE PONER EL CAST:   (TipoDeVariable *)    SOLO ES PARA ORIENTARSE
	//Asignamos valores:
	//Inicializamos el primer elemento:
	subsistemas->activo = TRUE;           //////COLOCAMOS  ->  Y NO  .   PORQUE subsistemas ES UN POINTER!!!!!!!!!!!!
	strcpy(subsistemas->nombre, "Nucleo");
	//Reservamos memoria para un segundo elemento, apuntado por el primero:
	subsistemas->siguiente = (lista_subsistemas *)malloc(sizeof(lista_subsistemas));
                                                //ES AL CUETE PONER EL CAST:   (TipoDeVariable *)    SOLO ES PARA ORIENTARSE
	//Inicializamos el segundo elemento:   //CON:  subsistemas->siguiente->  ACCEDEMOS A LA struct A LA QUE APUNTA LA PRIMERA struct
	subsistemas->siguiente->activo = FALSE;
	strcpy(subsistemas->siguiente->nombre, "Actuadores");
	subsistemas->siguiente->siguiente = NULL;//HACEMOS QUE ESTA struct YA NO APUNTE A NINGUNA OTRA stuct

	//Recorremos todos los elementos de la lista enlazada:
	lista_subsistemas *subsistema_actual;
	subsistema_actual = subsistemas;
	printf("\n\nEstado de los subsistemas:\n");
	while(subsistema_actual != NULL) {
		//Mostramos el elemento actual de la lista. Atencion a las 2 maneras de acceder a
		//los elementos de la estructura: utilizando la combinación de operadores * y . o bien utilizando ->
		printf("   %s:  %d\n",  subsistema_actual->nombre,  (*subsistema_actual).activo  );//AMBAS FORMAS SON EQUIVALENTES!

		//Actualizamos el apuntador al "elemento actual":
		subsistema_actual = subsistema_actual->siguiente;
	}

	//Liberamos la memoria, elemento por elemento:
	lista_subsistemas *subsistema_siguiente;
	subsistema_actual = subsistemas;
	while(subsistema_actual != NULL) {
		//Guardamos el apuntador al siguiente elemento:
		subsistema_siguiente = subsistema_actual->siguiente;

		//Liberamos el elemento actual:
		free(subsistema_actual);

		//Actualizamos el apuntador:
		subsistema_actual = subsistema_siguiente;
	}
}













//
