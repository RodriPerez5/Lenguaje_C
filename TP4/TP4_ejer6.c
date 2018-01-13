Cargar/*
Escriba un programa que:
 a. lea por teclado un entero N,
 b. cree 4 vectores de N elementos double dinámicamente con valores aleatorios,
 c. lea por teclado un factor de escala double
 d. escale 2 de los vectores generados en (b) por el factor s
 e. calcule el producto vectorial de los vectores de a pares, el primero por el segundo y..
    ..el tercero por el cuarto, generando como resultado 2 vectores u y v
 f. calcule el producto vevtorial de u x v
 g. muestre todos los resultados intermedios por pantalla
 h. Libere la memoria dinámica utilizada
*/

//     gcc TP4_ejer6.c ManejoDinamicoDeMemoria.c ValoresAleatorios.c OperacionesConArreglos.c

#include "/home/rodri/INFORMATICA/TP4/TP4_HEADER_FILE.h"


int main() {
  int N;
  printf(" Ingrese el tamaño de los vectores: ");
  scanf("%d", &N);

  double *Vec1 = ReservarMemoriaVector(N);
  EstablecerSEMILLA(0);
  CargarVectorAleatorio( Vec1, N );
  double *Vec2 = ReservarMemoriaVector(N);
  EstablecerSEMILLA(1);
  CargarVectorAleatorio( Vec2, N );
  double *Vec3 = ReservarMemoriaVector(N);
  EstablecerSEMILLA(2);
  CargarVectorAleatorio( Vec3, N );
  double *Vec4 = ReservarMemoriaVector(N);
  EstablecerSEMILLA(3);
  CargarVectorAleatorio( Vec4, N );

  double S;
  printf("\n Ingrese un escalar fraccionario: ");
  scanf("%lf", &S);

  EscalarVector( Vec1, N, S);
  EscalarVector( Vec2, N, S);

  double *U = ProductoVectorial( Vec1, Vec2 );
  double *V = ProductoVectorial( Vec3, Vec4 );

  double *UxV = ProductoVectorial( U, V);

  printf("\n Vec1=");
  MostrarVector( Vec1, N);
  printf(" Vec2=");
  MostrarVector( Vec2, N);
  printf(" Vec3=");
  MostrarVector( Vec3, N);
  printf(" Vec4=");
  MostrarVector( Vec4, N);
  printf("\n Vec1ESCALADO=");
  MostrarVector( Vec1, N);
  printf(" Vec2ESCALADO=");
  MostrarVector( Vec2, N);
  printf("\n U=");
  MostrarVector( U, N);
  printf(" V=");
  MostrarVector( V, N);
  printf("\n UxV=");
  MostrarVector( UxV, N);
  printf("\n");

  LiberarMemoriaVector(Vec3);
  LiberarMemoriaVector(Vec4);
  LiberarMemoriaVector(Vec1);
  LiberarMemoriaVector(Vec2);
  LiberarMemoriaVector(U);
  LiberarMemoriaVector(V);
  LiberarMemoriaVector(UxV);

  return 0;
}
