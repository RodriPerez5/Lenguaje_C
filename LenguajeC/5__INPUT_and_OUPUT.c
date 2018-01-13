
///////////////////The GETCHAR and PUTCHAR Functions//////////////////////////
#include <stdio.h>
int main( ) {

   int UnSoloCaracterPorVez; //LO DEFINIMOS COMO UN int PORQUE EL CARACTER SE GUARDA COMO UN ENTERO, (PERO SE LEE Y ESCRIBE COMO CARACTER)

   printf( "Enter a value: ");
   UnSoloCaracterPorVez = getchar( );//SOLO NOS LEE EL PRIMER CARACTER QUE INGRESAMOS  //(Debemos presionar enter para ingresarlo)

   printf( "\nYou entered: ");
   putchar( UnSoloCaracterPorVez );
   printf( "\n");//(Si no coloco esta línea, entonces nos imprime un % al final)

   return 0;
}
/*
When the above code is compiled and executed, it produces the following result −

 Enter a value: this is test
 You entered: t
*/








// ///////////////////////////The GETS and PUTS Functions//////////////////////////
// #include <stdio.h>
// int main( ) {
//
//    char MOJOJOJO[100];// Es lo mismo que poner:   char MOJOJOJO[] = "HOLAaa puedo, escribir todo lo que quiera fácil!:) ";    ..
//
//    printf( "\n Enter a string: ");
//    gets( MOJOJOJO );
//
//    printf( " You entered: \n");//
//    puts( MOJOJOJO );//Es lo mismo que directamente poner:     printf("You entered: %s", MOJOJOJO);
//
//    return 0;
// }
// /*
// When the above code is compiled and executed, it produces the following result −
//
// Enter a value : this is test
// You entered: this is test
// */










// /////////////////////////The SCANF and PRINTF Functions////////////////////////
// #include <stdio.h>
// int main( ) {
//
//    char str[100];
//    int i;
//
//    printf( " Enter a value: ");
//    scanf("%s %d", str, &i);
//
//    printf( "\n You entered: %s  %d \n\n", str, i);
//
//    return 0;
// }
/*
// When the above code is compiled and executed, it produces the following result −
//
// Enter a value : this_is_test  77
// You entered: this_is_test  77
// */








//
