/*  reutilizacion_codigo.c
 *
 * 	DESCRIPCION:
 * 	Ejemplo de reutilizacion de codigo y encapsulamiento
 *
 * 	Creado el 22/09/2011
 *
 * 	Informatica - Ingenieria en Mecatronica
 *  Facultad de Ingenieria - Universidad Nacional de Cuyo
 *
 *  Autor: Dr. Ing. Martin G. Marchetta
 *
 */

#include "/home/rodri/INFORMATICA/LenguajeC/EjemploSUBRUTINA/EjemploSubrutina_REUTILIZACION_DE_CODIGO.h"

int motores[2];	//Tipo de cada motor (stepper o servo)



void inicializa_brazo(){
	//Configuración de los motores del brazo:
	motores[MOTOR_EJE] = SERVO;////////////////////////////////////////PORQUE MOTOR_EJE=0 MIENTRAS QUE SERVO=1 ????????????????
	motores[MOTOR_BRAZO] = STEPPER;////////////////////////////////////NO ESTÁN AL REVÉS ?????????????????????
}



/* Mueve un brazo robotizado ficticio hasta una posicion determinada y toma una pieza*/
void tomar_pieza(double x, double y){
	double angulo_motor_eje;
	double angulo_motor_brazo;
	//Movemos el brazo a la posicion indicada:
	//a. Primero el motor que controla el eje
	angulo_motor_eje = asin(y / sqrt(pow(x,2) + pow(y,2)));
	mover_motor(MOTOR_EJE, angulo_motor_eje);////////////////////////////////////////////CUANTO VALE AHORA MOTOR_EJE ???????????????
	//b. "Extendemos" el brazo hasta la posicion:
	//Asumimos que el rango completo se alcanza en 360 grados del motor (se usa 2*PI para escalar porque esta en radianes; 2PI = 360)
	angulo_motor_brazo = 2*PI/DISTANCIA_MAXIMA_AL_EJE*sqrt(pow(x,2)+pow(y,2));//'Primero se hacen las multiplicaciones y luego la división'
	mover_motor(MOTOR_BRAZO, angulo_motor_brazo);
}




/* Mueve el motor indicado a la posicion especificada, y maneja de manera
 * "encapsulada" el tipo del motor y las diferencias en relacion con el hardware */
void mover_motor(int motor, double posicion){
	if(motores[motor] == STEPPER)
		mover_stepper(posicion);
	else if(motores[motor] == SERVO)
		mover_servo(posicion);
}




/* Implementacion del movimiento de un motor tipo stepper*/
void mover_stepper(double posicion){
	//Aqui deberia ir al codigo que envia las señales al hardware a través del driver del dispositivo
	printf(" Moviendo stepper a la posicion:  %f°\n", posicion);
}




/* Implementacion del movimiento de un motor tipo servo*/
void mover_servo(double posicion){
	//Aqui deberia ir al codigo que envia las señales al hardware a través del driver del dispositivo
	printf(" Moviendo servo a la posicion:  %f°\n", posicion);
}










//
