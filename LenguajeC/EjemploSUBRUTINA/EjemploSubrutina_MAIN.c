/*  main
 *
 * 	DESCRIPCION:
 * 	Este es el programa principal para todos los ejercicios de Informatica
 *
 * 	Creado el 22/09/2011
 *
 * 	Informatica - Ingenieria en Mecatronica
 *  Facultad de Ingenieria - Universidad Nacional de Cuyo
 *
 *  Autor: Dr. Ing. Martin G. Marchetta
 *
 */

//   gcc -lm EjemploSubrutina_MAIN.c EjemploSubrutina_REUTILIZACION_DE_CODIGO.c 

#include "/home/rodri/INFORMATICA/LenguajeC/EjemploSUBRUTINA/EjemploSubrutina_REUTILIZACION_DE_CODIGO.h"


int suma_recursiva(int n){
	if(n == 0)
		return 0;
	else
		return n + suma_recursiva(n-1);
}



int main(void){
	//Ejemplo de encapsulamiento y reutilizacion de codigo:
	printf(" EJEMPLO DE REUTILIZACION DE CODIGO Y ENCAPSULAMIENTO - BRAZO CON 2 GRADOS DE LIBERTAD\n");
	inicializa_brazo();
	tomar_pieza(2.0, 2.0);

	//Ejemplo de recursion:
	int s = suma_recursiva(10);
	printf(" Suma recursiva de nros. entre 0 y 10:  %d\n", s);

	//Sale del programa sin error:
	return 0;
}


















//
