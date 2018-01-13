/*  main
 * 	DESCRIPCION:
 * 	Ejemplos de manejo de arreglos, apuntadores y estructuras de datos definidas por el usuario.
 *
 * 	Creado el 17/09/2012
 *
 * 	Informatica - Ingenieria en Mecatronica
 *  Facultad de Ingenieria - Universidad Nacional de Cuyo
 *
 *  Autor: Dr. Ing. Martin G. Marchetta
 *
 * */
 ///  gcc -lm EjEst_MAIN.c EjEst_ARREGLOS.c EjEst_APUNTADORES.c EjEst_TIPOS_DEFINIDOS_POR_USUARIO.c EjEst_MEMORIA_DINAMICA.c

#include "/home/rodri/INFORMATICA/LenguajeC/EjemploESTRUCTURAS_DATOS/EjEst_ESTRUCTURAs_DATOS.h"


int main(void){
	//Varios ejemplos con arreglos:
	ejemplo_arreglos();

	//Varios ejemplos con apuntadores, pasaje de parametros a funciones por valor y por referencia:
	ejemplo_apuntadores();

	//Ejemplos de uso de tipos definidos por el usuario:
	ejemplo_tipos_definidos_por_usuario();

	// Ejemplos de manejo de memoria dinámica:
	ejemplo_memoria_dinamica();

	return 0;
}
