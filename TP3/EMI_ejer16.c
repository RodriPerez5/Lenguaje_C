/*
 * ej16.c
 *
 *  Created on: 11/09/2017
 *      Author: emiliano
 */
#include "/home/rodri/INFORMATICA/TP3/cabeza.h"
struct vector {
	  float h1;
		float h2;
		float h3;
		float h4;
		float h5;
		float h6;
		float h7;
		float h8;
		float h9;
		float h10;
		float h11;
		float h12;
		float h13;
};

void ej16(){
	int i,j;
	float q,k,l,prom,d;
	q=100;
	k=12;
	l=0;
	d=21;
	j=21;
	srand(time(NULL));
	struct vector v[j];
	for (i=1;i<22;i++) {/////estructura de valores de mw cada 2 horas en 21 dias
		v[i].h1=rand()%500/q;
		v[i].h2=rand()%500/q;
		v[i].h3=rand()%500/q;
		v[i].h4=rand()%500/q;
		v[i].h5=rand()%500/q;
		v[i].h6=rand()%500/q;
		v[i].h7=rand()%500/q;
		v[i].h8=rand()%500/q;
		v[i].h9=rand()%500/q;
		v[i].h10=rand()%500/q;
		v[i].h11=rand()%500/q;
		v[i].h12=rand()%500/q;
	}
	for (i=1;i<22;i++){//promedio
		v[i].h13=(v[i].h1+v[i].h2+v[i].h3+v[i].h4+v[i].h5+v[i].h6+v[i].h7+v[i].h8+v[i].h9+v[i].h10+v[i].h11+v[i].h12)/k;
	}
	for (i=1;i<22;i++){
		l=l+v[i].h13;
	}
	prom=l/d;
		printf("La produccion promedio del dia de mañana es: %f MW",prom);
}












//
