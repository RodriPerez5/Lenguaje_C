// Bucle for
// for(inicializacion; condicion de continuidad; actualizacion){   //Siempre que se cumpla la condición de continuidad, se ejecutarán las sentencias del for.
//          [sentencias]


// Ejemplo con creación y lectura de un Vector:
#include <stdio.h>

int main() {
  int i;//(También se puede poner dentro del for, ''pero hace al programa un poquillo menos eficiente'')
  int Vector[10];
  printf("El vector creado es:\n");
  for( i=0 ; i<10 ; i++ ) {
    Vector[i] = i;
    printf(" Vector[%d]= %d\n", i, Vector[i]);
  }
  return 0;
}
