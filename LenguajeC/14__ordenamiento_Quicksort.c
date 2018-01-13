 /*
El algoritmo elige un pivote y mueve todos los elementos menores que él a su
izquierda, y el resto a su derecha, y luego repite el proceso para la mitad izquierda, y luego
para la mitad derecha
*/

//Ordenamiento de menor a mayor:
#include <stdio.h>

#define Tam 10//NOTA: si en lugar de esta línea, pusieramos dentro del for:  const int Tam=7;   entonces el  int Vector[Tam]..
             //..toma a Tam como una variable (no como una constante) y lanza error.

void QuickSort( int *Vector, int Ext_IZQ, int Ext_DER, int Pivote);


int CONDITION=0;

int main() {
  int Vector[Tam]={8,9,3,0,5,2,6,4,7,1};
  int i;

  printf(" Vector= {");
  for( i=0; i<Tam; i++ ) {
    printf(" %d ", Vector[i]);
  }
  printf("}\n");

  QuickSort( Vector, 0, (Tam-1), (int)(Tam-1)/2 );//(El Pivote puede ser cualquier nro entre 0 y Tam, incluyéndolos)


  printf("#################################################################################################\n");
  printf(" Vector= [");
  for( i=0; i<Tam; i++ ) {
    printf(" %d ", Vector[i]);
  }
  printf("]\n");


  return 0;
}





void QuickSort( int *Vector, int Ext_IZQ, int Ext_DER, int Pivote) {
  int valor_pivote, i, j, a, I;
  valor_pivote = Vector[Pivote];
  i=Ext_IZQ;
  j=Ext_DER;
  while( i<j ) {
    while ( Vector[i]<valor_pivote ) {
      i++;
    }
    while ( Vector[j]>valor_pivote ) {
      j--;
    }
    if ( i<j ) {
      a=Vector[i];
      Vector[i]=Vector[j];
      Vector[j]=a;
      i++;
      j--;
    }
  }


  printf(" Vector= [");
  for( I=0; I<Tam; I++ ) {
    printf(" %d ", Vector[I]);
  }
  printf("]\n");

  printf(" Ext_IZQ= %d        ", Ext_IZQ);
  printf(" i= %d   ", i);
  printf(" j= %d\n", j);

  getchar();

  if (  (j-Ext_IZQ)>=1 ) {
    QuickSort( Vector, Ext_IZQ, j, (int)(Ext_IZQ+j)/2  );
  }

  printf("YEAHHHHHHH     Ext_DER= %d\n", Ext_DER);
  printf(" i= %d\n", i);
  printf(" j= %d\n\n", j);

  if ( (Ext_DER-i)>=1   &&   CONDITION==0  ) {
    if (   (Ext_DER-i)==1   &&   i==j ) {
        CONDITION=777;//Puse esta CONDICIÓN porque sino nunca lograba salir del bucle recursivo --> MEJORAR PROGRAMA
    }
    QuickSort( Vector, i, Ext_DER, (int)(i+Ext_DER)/2  );
    CONDITION=0;
  }

  printf("ssssssssssssssssssssssssssssssssssssssssssssssssssssssss\n\n");

  return;
}












//
