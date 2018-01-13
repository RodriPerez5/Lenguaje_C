/*
*/

#include <stdio.h>

int main() {

   int a = 7;
   short b;
   double c;
   int* ptr;

   /* example of sizeof operator */ //VER TamañoDeCadaTipoDeVariableEnBytes.c
   printf("Line 1 - Size of variable a = %d\n", sizeof(a) );
   printf("Line 2 - Size of variable b = %d\n", sizeof(b) );
   printf("Line 3 - Size of variable c = %d\n", sizeof(c) );

   /* example of & and * operators */
   ptr = &a;	/* 'ptr' now contains the address of 'a' */
   printf("The value of a is:  %d\n", a);
   printf("*ptr is %d.\n", *ptr);

   /* example of ternary operator ?: (Llamado "Conditional Expression") */  // Value=(Condition)?X:Y  -->If Condition is true? then Value X : otherwise Value Y 
   a = 10;
   b = (a == 1)? 20:30 ;
   printf( "Value of b is %d\n", b );

   b = (a == 10) ? 20: 30;
   printf( "Value of b is %d\n", b );


}







//
