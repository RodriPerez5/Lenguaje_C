/*  tipos de datos definidos por el usuario
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

#include "/home/rodri/INFORMATICA/LenguajeC/EjemploESTRUCTURAS_DATOS/EjEst_ESTRUCTURAs_DATOS.h"


//Definición de un TIPO DE DATO SIMPLE -->(Se definen como un “alias("apodo")” de otro tipo simple ya existente)
//Normalmente conviene colocar esto en el header file o en un archivo fuente .c compartido, pero por cuestiones
//didacticas se lo coloca aquí:
typedef int boolean;//Ej: definimos un tipo “boolean” para guardar valores lógicos true/false, algo que no existe en C
#define TRUE 1 //(El 1 es el dato que ya existe)
#define FALSE 0 //(El 0 es el dato que ya existe)

//Definimos una "macro" de mapeo para el tipo boolean (para desplegar en pantalla). Consideraciones:
//	a) 	Cada vez que se llame a la "funcion" MAP_BOOLEAN (en realidad no es una funcion, sino una macro), se reemplaza
//		la llamada por lo que esta a la derecha, reemplazando el argumento de la llamada en todos los lugares donde
//		aparezca X
//	b) 	La estructura condicional  "<condicion> ? <accion_si_verdadero> : <accion_si_falso>"  evalua la <condicion>, y de
//		ser verdadera, toma el primer valor luego del ?; si es falsa, se toma el valor luego del :
//
//Normalmente conviene colocar esto en el header file o en un archivo fuente .c compartido, pero por cuestiones
//didacticas se lo coloca aqui
#define MAP_BOOLEAN(X)  X==TRUE? "TRUE" : "FALSE"






//Definicion de un TIPO DE DATO COMPLEJO.
//Normalmente conviene colocar esto en el header file o en un archivo fuente .c compartido, pero por cuestiones
//didacticas se lo coloca aquí:
struct SUBSISTEMA{
	boolean Activo;//boolean ahora es un tipo de variable(ó dato) (así como int, char, etc.)!
	char Nombre[50];
};

//Creación de un "ALIAS" del tipo de dato complejo (recordar que el lenguaje C es "case sensitive", SUBSISTEMA != subsistema)
typedef struct SUBSISTEMA subsistema;////AQUÍ DEFINIMOS QUE PONER EL TIPO DE VARIABLE:  'struct SUBSISTEMA'  SEA LO MISMO QUE PONER..
                                     ////..SIMPLEMENTE:  'subsistema'  .¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿ ESTO ES SOLAMENTE PARA SIMPLIFICAR ??????????????????????






void ejemplo_tipos_definidos_por_usuario(){
	printf("\n==========================================\n");
	printf("EJEMPLOS DE TIPOS DEFINIDOS POR EL USUARIO:\n");
	printf("==========================================\n\n");


	//Uso de un TIPO DE DATO SIMPLE definido por el usuario:
	printf("UTILIZACIÓN DE UNA ESTRUCTURA SIMPLE:\n");
	boolean Condicion;// definimos a:  Condicion  como un tipo de variable:  boolean
	if(1 > 2)
		Condicion = TRUE;//(Es lo mismo si reemplazamos TRUE por 1)
	else
		Condicion = FALSE;//(Es lo mismo si reemplazamos FALSE por 0)

	if(Condicion == TRUE)
		printf("Condicion = TRUE (%d)\n", Condicion);
	else
		printf("Condicion = FALSE (%d)\n", Condicion);

	printf("\n\n");





	//Uso de un TIPO DE DATO COMPLEJO definido por el usuario -->Creamos un Arreglo de Subsistemas:
	printf("UTILIZACIÓN DE UNA ESTRUCTURA COMPLEJA (STRUCT):\n");
	struct SUBSISTEMA componentes[3];// definimos a:   componentes[3]   como un tipo de estructura:   SUBSISTEMA

	componentes[0].Activo = TRUE;
	strcpy(componentes[0].Nombre, "Nucleo");

	componentes[1].Activo = FALSE;
	strcpy(componentes[1].Nombre, "GPS");

	componentes[2].Activo = TRUE;
	strcpy(componentes[2].Nombre, "Actuadores");

	int i;
	printf("             Estado del sistema:\n");
	for(i = 0; i < 3; i++)
		printf("Componente %s: %s\n", componentes[i].Nombre, MAP_BOOLEAN(componentes[i].Activo));//Si en lugar, colocáramos:..
    //.. printf("Componente %s: %d\n", componentes[i].Nombre, componentes[i].Activo);  entonces en lugar de imprimir TRUE ó FALSE, imprime 1 ó 0


	//Similar, pero utilizando el "ALIAS". Notese que no es necesario utilizar la palabra "struct" en este caso
	printf("\nUTILIZACION DE UNA ESTRUCTURA REDEFINIDA CON TYPEDEF:\n");
	subsistema componentes2[3];

	componentes2[0].Activo = TRUE;
	strcpy(componentes2[0].Nombre, "Nucleo");

	componentes2[1].Activo = FALSE;
	strcpy(componentes2[1].Nombre, "GPS");

	componentes2[2].Activo = TRUE;
	strcpy(componentes2[2].Nombre, "Actuadores");

	printf("             Estado del sistema:\n");
	for(i = 0; i < 3; i++)
		printf("Componente %s: %s\n", componentes2[i].Nombre, MAP_BOOLEAN(componentes2[i].Activo));
}










//
