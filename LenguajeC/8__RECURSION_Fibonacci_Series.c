

#include <stdio.h>
//NOTA: T0DO ESTE PROGRAMA ES MUY INEFICIENTE, Y MIENTRAS MÁS GRANDE ES EL NÚMERO DE LA SERIE, SE DEMORA CADA VEZ MÁS
long int Fibonacci( int i ) {
   if( i==0 ) {
      return 0;
   }
   if( i==1 ) {
      return 1;
   }
   return Fibonacci(i-1) + Fibonacci(i-2);
}

int  main() {
   int n;
   printf("Ingrese un argumento entero: ");
   scanf("%d", &n);
   for ( int i=0; i<=n; i++) {
      printf(" %ld\n", Fibonacci(i));
   }
   return 0;
}






// //////////////Programa Eficiente para SERIE DE FIBONACCI, (No usa Rcursión)/////////////////////
// /*  El único límite de este programa es la cantidad máxima de bits que puede almacenar las variables en C */
// #include <stdio.h>
//
// int main() {
//    int i;
//    long long int FiboAnterior=0;
//    long long int Fibo=1;
//    long long int RETENGO;
//    printf(" %lld\n %lld\n", FiboAnterior, Fibo);
//    for ( i=0 ; i<77 ; i++ ) {
//        RETENGO=Fibo;
//        Fibo=Fibo+FiboAnterior;
//        printf(" %lld\n", Fibo);
//        FiboAnterior=RETENGO;
//    }
// return 0;
// };









//
