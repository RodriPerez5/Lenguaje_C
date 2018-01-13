#include <stdio.h>

/* GLOBAL VARIABLE declaration */ //Global variables are less powerful than local variables..
int a = 77;                       //..but the locals aren't known to functions outside their own.
float Squanchy=7.777;


int Subrutina(int a, int b);



int main () {
  /* LOCAL VARIABLE declaration in main function */ //Local variables are more powerful than global variables..
  int a = 10;                                       //..but the locals aren't known to functions outside their own.
  int b = 20;
  int c = 0;
  printf ("value of a in main = %d\n\n",  a);
  c = Subrutina( a, b);
  printf ("value of c in main = %d\n",  c);
  return 0;
}




/* function to add two integers *///FORMAL PARAMETERS //Formal parameters, are treated as local variables with-in a function..
int Subrutina(int a, int b) {                         //..and they take precedence over global variables.
   printf ("value of a in Subrutina = %d\n",  a);
   printf ("value of b in Subrutina = %d\n",  b);
   printf ("value of Squanchy in Subrutina = %f\n\n",  Squanchy);
   return a + b;
}














//
