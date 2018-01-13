#include <stdio.h>
int main(void){
		//Entero corto
		short int a, b, c;
		a = 1;   //00000001
		b = 2;   //00000010
		c = 10;  //00001010



		// printf("Operaciones AND, OR y XOR: \n");
		// printf("a: %d\n", a);
		// printf("b: %d\n", b);
		// printf("c: %d\n", c);
		// printf("a&b: %d\n", a&b);	//							[ Operan bit por bit..
		// printf("a|b: %d\n", a|b);	// 							 ..pero entregan números en..
		// printf("a^c: %d\n", a^c);	// 	 						 ..base decimal              !]
		// printf("\n");

		//LO MISMO PERO EN UNA SOLA LÍNEA:
		printf("Operaciones AND, OR y XOR:\n   a= %d\n   b= %d\n   c= %d\n a&b= %d\n a|b= %d\n a^c= %d\n\n", a, b, c, a&b, a|b, a^c);



		printf("Corrimiento de bits: \n");
		a <<= 1; //Corrimiento de 1 bit a la IZQUIERDA: EQUIVALE A MULTIPLICAR POR 2               (>>= A LA DERECHA A DIVIDIR POR 2)
		b = b << 1; //Esta expresión es equivalente a la anterior para la operación de corrimiento de bits.
		printf("(a << 1)= %d\n", a);
		printf("(b << 1)= %d\n", b);
		printf("(c >> 1)= %d\n", c>>1); //Otra expresión equivalente para la operación de corrimiento de bits.
		printf("\n");



		return 0;
	}
