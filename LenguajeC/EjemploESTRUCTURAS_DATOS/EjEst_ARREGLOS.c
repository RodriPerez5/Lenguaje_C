/*  arreglos
 * 	DESCRIPCION:
 * 	Ejemplos de manejo de arreglos
 *
 * 	Creado el 23/09/2012
 *
 * 	Informatica - Ingenieria en Mecatronica
 *  Facultad de Ingenieria - Universidad Nacional de Cuyo
 *
 *  Autor: Dr. Ing. Martin G. Marchetta
 *
 * */

#include "/home/rodri/INFORMATICA/LenguajeC/EjemploESTRUCTURAS_DATOS/EjEst_ESTRUCTURAs_DATOS.h"

void multiplicacion_escalar_vector(float vector[], int longitud, float escalar) {
	int i;
	for(i = 0; i < longitud; i++)
		vector[i] *= escalar;//El * No es un operadorde indirección, sino que simplemente es un por
}

void despliega_vector(float vector[], int longitud) {
	int i;
	printf("[");
	for(i = 0; i < longitud; i++)
		printf("%.2f  ", vector[i]);
	printf("]\n");
}

void ejemplo_arreglos() {
	float valores[10];
	float matriz[15][15];
	int i;
	int j;

	printf("==========================================\n");
	printf("ARREGLOS\n");
	printf("==========================================\n\n");

	//Genera un vector de 10 elementos
	for(i = 0; i < 10; i++) {
		valores[i] = (i+1)*2.33;
	}

	//Muestra el vector
	printf("Arreglo generado:\n");
	despliega_vector(valores, 10);////NO SE PONEN LOS  []  LUEGO DE:  valores !!!

	//Inicializamos una matriz 15x15 nula
	for(i = 0; i < 15; i++) {
		for(j = 0; j < 15; j++)
			matriz[i][j] = 0;
	}

	//Asignamos valores en la parte superior (matriz triangular superior)
	for(i = 0; i < 15; i++) {
		for(j = i; j < 15; j++) {
			matriz[i][j] = i+j;
		}
	}

	//Muestra la matriz
	printf("\nMatriz generada:\n");
	for(i = 0; i < 15; i++){
		for(j = 0; j < 15; j++){
			if(matriz[i][j] < 10)
				printf("%.2f   ", matriz[i][j]);
			else
				printf("%.2f  ", matriz[i][j]);
		}
		printf("\n");
	}

	//Multiplicamos vector por un escalar: Pasaje del vector como parametro a una funcion
	multiplicacion_escalar_vector(valores, 10, 2.5);
	printf("\nVector escalado:\n");
	despliega_vector(valores, 10);
}















//
