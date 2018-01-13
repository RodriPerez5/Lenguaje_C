/*
  Recursion is the process of repeating items in a self-similar way. In programming languages, if a..
..program allows you to call a function inside the same function, then it is called a recursive call..
..of the function.
*/

#include <stdio.h>


int factorial( int a) {
   if(a <= 1) {
      return 1;
   }
   return a * factorial(a - 1);//Aquí la función recursiva se llama a sí mismaS
}


int  main() {
   int A = 7;
   printf("\n Factorial of %d is:  %d\n\n", A, factorial(A));
   return 0;
}







//
