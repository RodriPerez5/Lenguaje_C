

// #include <stdio.h>
//
// // int square(int x) {
// //    return x * x;
// // }
// /*
// We can rewrite above the code using a macro as follows −
// */
// #define square(x) ((x) * (x));
//
// int main() {
//   int X;
//   printf(" Ingrese un entero: ");
//   scanf("%d", &X);
//   int POWER = square(X);
//   printf(" Su potencia cuadrada es: %d\n", POWER);
//
//   return 0;
// }











////////////////////////Other Example///////////////////////
#include <stdio.h>

#define MAX(x,y)  (  (x)>(y)  ?  (x):(y)  )///////////////////////////////////////////VER QUE ONDA:    (  (x)>(y)  ?  (x):(y)  )

int main(void) {
   printf("\n Max between 10 and 20 is:  %d\n\n", MAX(10, 20));
   return 0;
}
/*
When the above code is compiled and executed, it produces the following result −

 Max between 20 and 10 is:  20

*/












//
