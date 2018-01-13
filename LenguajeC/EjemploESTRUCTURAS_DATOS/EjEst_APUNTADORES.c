/*  aputadores
 * 	DESCRIPCION:
 * 	Ejemplos de manejo de apuntadores
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

double potencia_valor(double base, double exponente, double resultado){
	resultado = pow(base, exponente);
	return resultado;
}

void potencia_referencia(double base, double exponente, double *resultado){
	*resultado = pow(base, exponente);
}

void multiplicacion_escalar_vector_2(double *vector, int longitud, float escalar){
	int i;
	for(i = 0; i < longitud; i++) {
		*(vector+i) *= escalar;///////////PONER:   *(Valores+i)    ES LO MISMO QUE PONER:   Valores[i]     !!!!!!
  }
}

void despliega_vector_2(double *vector, int longitud){
	int i;
	printf("[");
	for(i = 0; i < longitud; i++) {
		printf("%.2f ", *(vector+i));
  }
	printf("]\n");
}

void ejemplo_apuntadores(){
	double v;
	double *mv;
	double resultado;
	double Valores[10];
	int i;

	printf("\n\n==========================================\n");
	printf("APUNTADORES\n");
	printf("==========================================\n\n");

	//Asignamos al apuntador mv la direccion de memoria de la variable v:
	mv = &v;
	//Inicializamos v:
	v = 10;
	//Mostramos el valor de v, y de la posicion de memoria apuntada por *mv (que es la misma que la de v):
	printf("  v= %.2f   ;   mv= %p\n\n", v, mv);

	//Pasaje por valor: elevamos v al cuadrado; intentamos colocar el resultado nuevamente en v, y tambien devolvemos el
	//resultado como valor de retorno de la funcion:
	resultado = potencia_valor(v, 2, v); //EL SEGUNGO v SE PASA PARA INTERTAR MODIFICARLO..
	printf("Pasaje por valor\n  resultado=%.2f   v=%.2f \n\n", resultado, v);//..pero por ser un PASAJE POR VALOR, v NO SE MODIFICA!

	//Pasaje por referencia: el mismo caso, pero pasando la direccion de memoria de v, en lugar del valor de v:
	potencia_referencia(v, 2, &v);
	printf("Pasaje por referencia\n  v=%.2f       &v= %p\n\n", v, &v);//Por ser un PASAJE POR REFERENCIA, v SÍ SE MODIFICA!..
                                                                    //..SÍ MODIFICA EL VALOR DE v, PERO NO SE MODIFICA LA POSICIÓN DE MEMORIA DE v !!!!!!!!!!!!!!!!!!!!


  //******************************************************************************
	//Tratamiento de arreglos como apuntadores:
	//Genera un vector de 10 elementos
	for(i = 0; i < 10; i++) {
		*(Valores+i) = (i+1) * 2;///////////PONER:   *(Valores+i)    ES LO MISMO QUE PONER:   Valores[i]     !!!!!!
  }

	multiplicacion_escalar_vector_2(Valores, 10, 2);
	despliega_vector_2(Valores, 10);
}



















//
