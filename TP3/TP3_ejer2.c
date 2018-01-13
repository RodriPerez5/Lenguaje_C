/*
Elaborar un algoritmo en el cual se ingrese una letra y se detecte si se trata es una vocal o
cualquier otro tipo de caracter.
*/


// #include <stdio.h>
//
// int main() {
//   char CualquierCaracter;
//   printf("Ingrese una letra:\n");
//   scanf("%s", &CualquierCaracter);
//   if ((CualquierCaracter=='a') || (CualquierCaracter=='A')){
//     printf("El Caracter ingresado SI es una vocal\n");
//   }else if ((CualquierCaracter=='e') || (CualquierCaracter=='E')) {
//       printf("El Caracter ingresado SI es una vocal\n");
//     }else if ((CualquierCaracter=='i') || (CualquierCaracter=='I')) {
//       printf("El Caracter ingresado SI es una vocal\n");
//     }else if ((CualquierCaracter=='o') || (CualquierCaracter=='O')) {
//       printf("El Caracter ingresado SI es una vocal\n");
//     }else if ((CualquierCaracter=='u') || (CualquierCaracter=='U')) {
//       printf("El Caracter ingresado SI es una vocal\n");
//     }else {
//       printf("El Caracter ingresado NO una vocal\n");
//     }
// return 0;
// }



// #include <stdio.h>
// #include <ctype.h>
//
// int main(int argc, char const *argv[]) {
//   int count;
// // char letra = argv[1];
//   if (argc > 1) {
//       for (count = 1; count < argc; count++) {
//
//           switch (tolower(*argv[count])) {
//             case 'a':printf("Vocal!\n");
//             break;
//             case 'e':printf("Vocal!\n");
//             break;
//             case 'i':printf("Vocal!\n");
//             break;
//             case 'o':printf("Vocal!\n");
//             break;
//             case 'u':printf("Vocal!\n");
//             break;
//             default:printf("No es vocal :(\n");
//           }
//       }
//   } else {
//     printf("El uso es: %s <caracter>\n", argv[0]);
//   }
//   return 0;
// }
