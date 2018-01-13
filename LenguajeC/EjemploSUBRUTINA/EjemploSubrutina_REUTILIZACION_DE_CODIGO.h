/*  REUTILIZACION_CODIGO.h
 *
 *  DESCRIPCION:
 *  Ejemplo de reutilizacion de codigo y encapsulamiento - encabezados
 *
 * 	Creado el 22/09/2011
 *
 * 	Informatica - Ingenieria en Mecatronica
 *  Facultad de Ingenieria - Universidad Nacional de Cuyo
 *
 *  Autor: Dr. Ing. Martin G. Marchetta
 *
 */

#ifndef EjemploSubrutina_REUTILIZACION_DE_CODIGO_H_ //(No importa que nombre pongamos)
 #define EjemploSubrutina_REUTILIZACION_DE_CODIGO_H_

  #include <stdio.h>
  #include <math.h>
  #define MOTOR_EJE 0
  #define MOTOR_BRAZO 1
  #define STEPPER 0
  #define SERVO 1
  #define DISTANCIA_MAXIMA_AL_EJE 100
  #define PI 3.141592654
  void inicializa_brazo();
  void tomar_pieza(double x, double y);
  void mover_motor(int motor, double posicion);
  void mover_stepper(double posicion);
  void mover_servo(double posicion);

#endif /* EjemploSubrutina_REUTILIZACION_DE_CODIGO_H_ */










//
