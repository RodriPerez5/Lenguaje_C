/*
   Return_Type   Function_Name  ( parameter list ) {
                |body of the function|
}
*/


#include <stdio.h>



float Potencia(float BBasee, int EExponentee){ /////El Primer float es debido a que p es un decimal, y El Segundo float es debido a que la base es un decimal
		float PoOotencia = 1.0; ///Se tiene que definir toda variable que no tomemos de la funcion main
		int i;
		for(i = 0; i < EExponentee; i++){
			PoOotencia *= BBasee;
		}
		return PoOotencia;/////(no es necesario que PoOotencia tenga el mismo nombre que nada)
	}



	int main(void){
		float base, p;
		int exponente;
		  printf("Ingrese base: ");
			scanf("%f", &base);
			printf("Ingrese exponente: ");
			scanf("%d", &exponente);

			p = Potencia(base, exponente);//Esto es un ¡CALL BY VALUE! //CUANDO PONEMOS: algo=UnaSubrutina , ENTONCES SI O SÍ LA SUBRUTINA NOS TIENE QUE RETORNAR Algo!!!
			printf("%f ^ %d = %f\n", base, exponente, p);
			//printf("%f ^ %d = %f\n", base, exponente, Potencia(base, exponente));  //ES LO MISMO SI REEMPLAZAMOS LAS DOS LÍNEAS ANTERIORES POR ÉSTA



		printf("\n");
		return 0;
	}
