#include <stdio.h>
int main(void){



		//****************************************************************************
		// SENTENCIAS CONDICIONALES
		//****************************************************************************
		int a, b;
		float r;
		printf("Sentencias Condicionales\n");
		printf("Ingrese a: ");
		scanf("%d", &a);
		printf("Ingrese b: ");
		scanf("%d", &b);
		if(b != 0){
			r = (float)a/b; //////////////CONVERSIÓN EXPLICITA DE ENTERO A FLOTANTE, y calculo del cociente
			printf("a/b = %.2f\n", r); ///MUESTRO EL VALOR CON DOS DECIMALES
		}
		else if(a != 0){
			printf("a/b = infinito\n");
		}
		else
			printf("a/b = indeterminacion\n");



		//****************************************************************************
		// BUCLE FOR
		//****************************************************************************
		printf("\n");
		printf("Bucle for Para Calcular Potenciación\n");
		int i, exponente;
		float base, potencia;
		printf("Ingrese base: ");
		scanf("%f", &base);
		printf("Ingrese exponente: ");
		scanf("%d", &exponente);
		potencia = 1.0;
		for(i = 0; i < exponente; i++){
			potencia *= base;///////ES LO MISMO QUE PONER:   potencia=potencia*base;
		}
		printf("(%f^%d)=%f\n", base, exponente, potencia);



		//****************************************************************************
		// BUCLE DO/WHILE
		//****************************************************************************
		printf("\n");
		int seguir;
		printf("Bucle while: Cálculo Repetitivo de Potencia\n");
		do{
			printf("Ingrese base: ");
			scanf("%f", &base);
			printf("Ingrese exponente: ");
			scanf("%d", &exponente);
			potencia = 1.0;
			for(i = 0; i < exponente; i++){
				potencia *= base;
			}
			printf("(%f^%d)=%f\n", base, exponente, potencia);
			printf("Desea calcular de nuevo?  (1=sí/0=no) ");
			scanf("%d", &seguir);
			printf("\n\n");
		}while(seguir==1);



		printf("\nBye\n");
		return 0;
	}
