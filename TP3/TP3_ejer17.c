/*
Escriba un programa que calcule el producto vectorial de 2 vectores en R3 utilizando structs para representar los vectores.
*/

#include <stdio.h>


struct VECTOR { int x;
                int y;
                int z;  };


int main() {
   struct VECTOR U;
   struct VECTOR V;
   struct VECTOR RESULTADO;


  //  //(NO USAR esta forma de escanear, es MÁS LARGA y SIN SENTIDO)//
  //  int u1, u2, u3;
  //  printf(" Ingrese las tres componentes del vector U: \n");
  //  printf(" u1= ");
  //  scanf("%d", &u1);    //OJOO___NO HAY QUE PONER NUNCA EL \n EN LOS SCANF!!!
  //  printf(" u2= ");
  //  scanf("%d", &u2);
  //  printf(" u3= ");
  //  scanf("%d", &u3);
  //  printf(" U=[%d;%d;%d] \n\n", u1, u2, u3);
  //  U.x=u1;
  //  U.y=u2;
  //  U.z=u3;
  //
   printf(" Ingrese las tres componentes del vector U: \n");
   printf(" u1= ");
   scanf("%d", &U.x);
   printf(" u2= ");
   scanf("%d", &U.y);
   printf(" u3= ");
   scanf("%d", &U.z);
   printf(" U=[%d;%d;%d] \n\n", U.x, U.y, U.z);



   printf(" Ingrese las tres componentes del vector V: \n");
   printf(" v1= ");
   scanf("%d", &V.x);
   printf(" v2= ");
   scanf("%d", &V.y);
   printf(" v3= ");
   scanf("%d", &V.z);
   printf(" V=[%d;%d;%d] \n\n", V.x, V.y, V.z);



   /*     Cálculo del Producto Vectorial: UxV      */
   RESULTADO.x = (U.y*V.z - U.z*V.y);
   RESULTADO.y = -(U.x*V.z - U.z*V.x);
   RESULTADO.z = (U.x*V.y - U.y*V.x);
   printf(" El Producto Vectorial es:  UxV=[ %d ; %d ; %d ]\n", RESULTADO.x, RESULTADO.y, RESULTADO.z);



  return 0;
}





















//
