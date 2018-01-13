
////////////////////////////////INTEGER LITERAL/////////////////////////////////
/*
  An integer CONSTANT (also known as: LITERAL) can be a decimal, octal, or hexadecimal constant. A prefix
specifies the base or radix: 0x or 0X for hexadecimal, 0 for octal, and nothing for decimal.
  An integer literal can also have a suffix that is a combination of U and L, for unsigned and long,
respectively. The suffix can be uppercase or lowercase and can be in any order.
*/

//Here are some examples of various types of integer literals
// 85         /* decimal */
// 0213       /* octal */
// 0x4b       /* hexadecimal */
// 30         /* int */
// 30u        /* unsigned int */
// 30l        /* long int*/
// 30ul       /* unsigned long int*/

//Following are other examples of integer literals:
// 212         /* Legal */
// 215u        /* Legal */
// 0xFeeL      /* Legal */
// 078         /* Illegal: 8 is not an octal digit */
// 032UU       /* Illegal: cannot repeat a suffix */





//////////////////////////////FLOAT-POINT LITERAL///////////////////////////////
/*
  A floating-point literal has an integer part, a decimal point, a fractional part, and an exponent part. You can
represent floating point literals either in decimal form or exponential form.
  While representing decimal form, you must include the decimal point, the exponent, or both; and while representing
exponential form, you must include the integer part, the fractional part, or both. The signed exponent is introduced
by e or E.
*/

//Here are some examples of floating-point literals:
// 3.14159       /* Legal */
// 314159E-5L    /* Legal */
// 510E          /* Illegal: incomplete exponent */
// 210f          /* Illegal: no decimal or exponent */
// .e55          /* Illegal: missing integer or fraction */







//******************************************************************************
//                             DEFINING CONSTANTS
//******************************************************************************
/*
There are TWO simple WAYS in C to define constants:
                                                   -Using #define preprocessor.
                                                   -Using const keyword.
*/
#include <stdio.h>


/////////////////////////////USING #define PREPROCESSOR/////////////////////////
// #define LENGTH 10
// #define WIDTH 5
// #define NEWLINE '\n' //Character literals are enclosed in single quotes  ' '

int main() {
///////////////////////////////USING const KEYWORD//////////////////////////////
   const int  LENGTH = 10;
   const int  WIDTH = 5;
   const char NEWLINE = '\n';



   int area = LENGTH * WIDTH;
   printf("Value of area= %d", area);
   printf("%c%c", NEWLINE, NEWLINE);

  //  LENGTH=7;/////SI INTETAMOS CAMBIAR EL VALOR DE UNA CONSTANTE, ENTONCES NOS TIRA ERROR!..
  //  printf("Length=%d", LENGTH);////..Y ESTA LÍNEA NO LA CORRE
   return 0;
}









//
