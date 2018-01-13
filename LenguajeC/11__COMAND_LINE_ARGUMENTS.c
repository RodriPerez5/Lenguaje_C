/*
It is possible to pass some values from the command line to your C programs when they are executed. These values are called..
.. command line arguments and many times they are important for your program especially when you want to control your program..
.. from outside instead of hard coding those values inside the code.

argc refers to the number of arguments passed.

argv[] is a pointer array which points to each argument passed to the program

*/

#include <stdio.h>



int main(int argc, char const *argv[]) {// SI NO PUSIÉRAMOS:   int argc, char const *argv[]    ENTONCES NO NOS RECONOCERÁ LAS FUNCIONES:  argc  Y  argv

  printf(" ARGC:  %d\n", argc);//Aquí imprimo la Cantidad de Argumentos Pasados (contando al argumento:  ./a.out )

  printf(" ARGV[0]:  %s\n", argv[0]);// argv[0]  holds the name of the program itself
  printf(" ARGV[1]:  %s\n", argv[1]);// argv[1]  is a pointer to the first command line argument supplied  ///VER MEJOR
  // for (int i=2 ; i<27 ; i++) {              //TODOO ESTE for LO PUSE YO
  //   printf(" ARGV[%d]:  %s\n", i, argv[i]);////QUE ES TODOO ESTO QUE TIRA ????????????????????????????????? // *argv[n] is the last argument  -->Que significa esto?
  // }                                        //


   if( argc == 2 ) {
      printf(" The Argument Supplied Is:  %s\n", argv[1]);
   }
   else if( argc > 2 ) {
      printf(" Too Many Arguments Supplied.\n");
   }
   else {
      printf(" One Argument Expected.\n");
   }
   /* If no arguments are supplied, argc will be one, and if you pass one argument then argc is set at 2
      You pass all the command line arguments separated by a space, but if argument itself has a space then..
    ..you can pass such arguments by putting them inside double quotes "" or single quotes ''.
   */
}
/*
When the above code is compiled and executed with single argument, it produces the following result:
  $./a.out  testing
  The argument supplied is testing

  $./a.out  "testing1 testing2"
  The argument supplied is testing1 testing2


When the above code is compiled and executed with a two arguments, it produces the following result.
  $./a.out  testing1 testing2
  Too many arguments supplied.


When the above code is compiled and executed without passing any argument, it produces the following result.
  $./a.out
  One argument expected

*/























//
