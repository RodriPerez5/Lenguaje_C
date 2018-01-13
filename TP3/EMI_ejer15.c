/*
 * ej15.c
 *
 *  Created on: 11/09/2017
 *      Author: emiliano
 */
#include "/home/rodri/INFORMATICA/TP3/cabeza.h"


void ej15(){
	////suponiendo que la produccion de energia de un parque eolico varia entre 0 y 5mw cada 2 horas
     ///// tomamos 12 mediciones diarias que son los mw producidos cada 2 horas;
	int n,m,i,j;
	float q,p,prom;

  n=12;
	m=21;/////tomamos la produccion del dia actual mas 20 dias anteriores
	q=100;
	float produccion[m][n];
	float promedio [m];
	srand(time(NULL));
	////definicion de matriz de produccion
	printf("La matriz de produccion C es:\n");
	for(i=0;i<n;i++){
		printf("\n\n");
		for(j=0;j<m;j++){
			produccion[i][j]=rand()%500/q;
			printf("%.2f   ",produccion[i][j]);
		}
	}
	printf("\n\nEl vector de promedio es:\n");////vector promedio
	for(i=0;i<m;i++){
		p=0;
		for(j=0;j<n;j++){
			p=p+produccion[j][i];
		}
		promedio[i]=p/n;
	printf("%.2f   ",promedio[i]);
	}

	/////promdeio de promdeios que dan la prediccion del dia 22
	p=0;
	for (i=0;i<m;i++){
		p=p+promedio[i];
	}
	prom=p/m;
	printf("\n\nLa produccion promedio del dia de mañana es: %f MW",prom);

}













//
