#include <stdio.h>
	int main(){



		//Entero corto
		short int c;

		// c = 32767; /////////////////////////////////Valor máximo del rango: 01111111 11111111 (2 bytes)
		// printf("Valor entero: %d\n\n", c);
    //
		// c = 32768; //Overflow que terminan representando un número negativo: 10000000 00000000
		// printf("Valor entero: %d\n", c);
		// c = 32769;
		// printf("Valor entero: %d\n", c);
		// c = 32770;
		// printf("Valor entero: %d\n", c);
		// c = 32771;
		// printf("Valor entero: %d\n\n", c);



		//Entero corto
		c = 12.7123412341234;//SOLO SE VA A IMPRIMIR LA PARTE ENTERA, y ¡NO REDONDEA!
		printf("Valor entero:      %d\n", c);

		//Punto flotante precisión simple
		float f_;
		f_ = 12.7123412341234;
		printf("Valor flotante f:  %f\n", f_);

		//Punto flotante precisión simple
		float fAmedida_0;
		fAmedida_0 = 12.7123412341234;
		printf("Valor flotante f:  %.0f\n", fAmedida_0); //El  .número  nos indica la CANTIDAD DE DÍGITOS que toma A LA IZQUIERDA DE LA COMA, y ¡SÍ REDONDEA !
		//Punto flotante precisión simple
		float fAmedida_2;
		fAmedida_2 = 12.7123412341234;
		printf("Valor flotante f:  %.2f\n", fAmedida_2); //El  .número  nos indica la CANTIDAD DE DÍGITOS que toma A LA IZQUIERDA DE LA COMA, y ¡SÍ REDONDEA !
		//Punto flotante precisión simple
		float fAmedidaa_2;
		fAmedidaa_2 = 12.7153412341234;
		printf("Valor flotante f:  %.2f\n\n", fAmedidaa_2); //El  .número  nos indica la CANTIDAD DE DÍGITOS que toma A LA IZQUIERDA DE LA COMA, y ¡SÍ REDONDEA !





		//Punto flotante precisión simple
		float f;
		f = 12.123456789123456789123456789123456789;
		printf("Valor flotante f:  %f\n", f);//MÁXIMO ES %.6f

		//Punto flotante doble precisión
		double lf;
		lf = 12.123456789123456789123456789123456789;
		printf("Valor flotante lf: %.17lf\n", lf);////MÁXIMO ES %.15f    SI O SI HAY QUE PONERLE EL . número PARA QUE TOME MÁS DÍGITOS QUE EL float--------->VERRRRR PORQUE!!!!!!!

		//Punto flotante de gran precisión
		long double LF;
		LF = 12.123456789123456789123456789123456789;
		printf("Valor flotante LF: %.19LF\n\n", LF);////MÁXIMO ES %.15f    SI O SI HAY QUE PONERLE EL . número PARA QUE TOME MÁS DÍGITOS QUE EL float-------->VERRRRR PORQUE!!!!!!! ¿Porque igual que el double?







		// //Punto flotante precisión simple
		// double e;
		// e = 12712.3412341234E-3;
		// printf("Valor flotante e:  %e\n", e);
		//
		// //Punto flotante precisión simple
		// double E;
		// E = 12712.3412341234E-3;
		// printf("Valor flotante E:  %E\n", E);
		//
		// //Punto flotante precisión simple
		// double g;
		// g = 12712.3412341234E-3;
		// printf("Valor flotante g:  %g\n", g);
		//
		// //Punto flotante precisión simple
		// double G;
		// G = 12712.3412341234E-3;
		// printf("Valor flotante G:  %G\n", G);






		return 0;
	}
