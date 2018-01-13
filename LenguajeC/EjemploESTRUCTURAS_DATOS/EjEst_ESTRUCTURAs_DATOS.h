/*  estrutura de datos.h
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

#ifndef ESTRUCTURAs_DATOS_H   //(No importa que nombre pongamos)
#define ESTRUCTURAs_DATOS_H
 #include <stdio.h>
 #include <math.h>
 #include <string.h>
 #include <stdlib.h>

 //Areglos
 void multiplicacion_escalar_vector(float vector[], int longitud, float escalar);   //ESTA LÍNEA LA PODEMOS NO COLOCAL Y NO PASA NADA
 void despliega_vector(float vector[], int longitud);                               //ESTA LÍNEA LA PODEMOS NO COLOCAL Y NO PASA NADA
 void ejemplo_arreglos();

 //Apuntadores
 double potencia_valor(double base, double exponente, double resultado);            //ESTA LÍNEA LA PODEMOS NO COLOCAL Y NO PASA NADA
 void potencia_referencia(double base, double exponente, double *resultado);        //ESTA LÍNEA LA PODEMOS NO COLOCAL Y NO PASA NADA
 void multiplicacion_escalar_vector_2(double *vector, int longitud, float escalar); //ESTA LÍNEA LA PODEMOS NO COLOCAL Y NO PASA NADA
 void despliega_vector_2(double *vector, int longitud);                             //ESTA LÍNEA LA PODEMOS NO COLOCAL Y NO PASA NADA
 void ejemplo_apuntadores();

 //Tipos definidos por el usuario
 void ejemplo_tipos_definidos_por_usuario();

 //Memoria dinamica
 void ejemplo_memoria_dinamica();

#endif /* ESTRUCTURAS_DATOS_H */













//
