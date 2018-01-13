//////Este programa se corre junto con el programa:   VariablesExternasSUPPORT.c
////////////////y SE COMPILAN DE LA SIGT. MANERA:   gcc  2__VariablesExternasMAIN.c  2__VariablesExternasSUPPORT.c    /////////////////////////
///////////////Esto produce el programa ejecutable:    a.out      el cual debemos ejecutar para correr el programa.

/*
 A Variable declaration with EXTERN is useful When You Are Using MULTIPLE FILES. Though you can declare a
variable multiple times in your C program, with EXTERN it can be defined only once in a file, a function, or a block of code.
*/

#include <stdio.h>


int CoNtAdOr;
extern void EscribirDelExterior();  //Si no está esta línea, solo me dice que en este programa no está definida la función..
                                    //                                      ..pero el(o los) programa SUPPORT no tirán ningún error.


int main() {
   CoNtAdOr = 5;
   EscribirDelExterior();
}
