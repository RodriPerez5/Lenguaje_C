
//Las CADENAS (en inglés: STRINGS) de caracteres en C se representan con un arreglo de char, terminado con el carácter especial \0.


#include <stdio.h>
#include <string.h>//Es solo para incluir las FUNCIONES con las cadenas, (No para el char).

int main() {

  // /* UNA FORMA */
  char Greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'}; //El carácter de fin de cadena ocupa 1 espacio, por lo que un arreglo de N elementos guarda cadenas de hasta N-1 caracteres.
  printf("Su Cadena de Caracteres es:  %s\n", Greeting);
  //
  // /* LA FORMA MÁS POSTA y SIMPLE */
  // char SaludosPOSTA[] = "HOLAaa puedo, escribir todo lo que quiera fácil! JOJOOJO :)"; //The C compiler automatically places the '\0' at the end of the string when it initializes the array.
  // printf("Su Cadena de Caracteres es:  %s\n", SaludosPOSTA);
  //
  // /* OTRA FORMA */
  // char Cadena[10];
  // Cadena[0] = 'R' ;                                ////OJO! de los N elementos el cero también cuenta como una de ellos
  // Cadena[1] = 'o' ;
  // Cadena[2] = 'd' ;
  // Cadena[3] = 'r' ;
  // Cadena[4] = 'i' ;
  // Cadena[5] = ' ' ;
  // Cadena[6] = 'C' ;
  // Cadena[7] = 'a' ;
  // Cadena[8] = 'p' ;
  // Cadena[9] = 'o' ;
  // Cadena[10] = '\0' ;
  // printf("         Su otra Cadena es:  %s\n", Cadena);
  //
  // printf("\n\n");




  char s1[] = "String 1-UNO", s2[] = " String 2-DOS";
  // printf("           %s\n          %s\n\n", s1, s2);
//////******************************************************************************
//////FUNTIONS that manipulate strings:
//////******************************************************************************

  // strcpy(s1, s2);//Copies string s2 into string s1.
  // printf("\n   %s --> %s\n\n",s1, s2);
  /* También sirve para para asignar una cadena de cacaracteres a un array de caracteres:  */
  char CiudadCity[17];
  strcpy(CiudadCity, "Roma");///strcpy( <variable_destino>, <cadena_fuente> )
  printf("\n %s\n\n", CiudadCity);

  // strcat(s1, s2);//Concatenates string s2 onto the end of string s1.//OJO hay que poner un espacio en la definición de s2 porque sino se come el primer caracter.
  // printf("           %s\n\n", s1);
  // printf("           %s\n\n", s2);

  // int  len;
  // len = strlen(s1);//Returns the length of string s1.
  // printf("La longitud de la cadena 1 es:  %d\n", len);

  // int ValorTruOrFalse;
  // ValorTruOrFalse = strcmp(s1, s2);//Returns 0 if s1 and s2 are the same in all respects; less than 0 if s1<s2; greater than 0 if s1>s2.
  // printf(" %d\n", ValorTruOrFalse);


Implemntarrrrrrrr:
  // strchr(s1, ch);//Returns a pointer to the first occurrence of character ch in string s1.

Implemntarrrrrrrrr:
  // strstr(s1, s2);//Returns a pointer to the first occurrence of string s2 in string s1.



  return 0;
}





//
