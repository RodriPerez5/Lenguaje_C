/*
An structure is simply an array which allows to combine data items of different kinds.
Structures are used to represent a record(registro).
*/
#include <stdio.h>
#include <string.h> //Es para incluir la función:  strcpy -->(STRingCoPY)



struct Books { char title[50];//Esto es la definición de un Array de Caracteres con capacidad de almacenar hasta 49 elementos, más el carácter de fin de cadena: '/0'
               char author[50];
               char subject[100];
               int id;            };




int main( ) {
   /* You would use the keyword union to define variables of union type */
   struct Books Book1; /* Declare Book1 of type Book */
   struct Books Book2; /* Declare Book2 of type Book */

   /* book 1 specification */                    ///////To access any member of a structure, we use the MEMBER ACCESS OPERATOR: .
   strcpy( Book1.title, "C Programming");//Esto sería como poner: Book1.title[]="C Programming"; pero esto no se puede para las..
   strcpy( Book1.author, "Nuha Ali");    //..cadenas de caracteres en las structures, por lo que usamos la función: STRCPY
   strcpy( Book1.subject, "C Programming Tutorial");
   Book1.id = 6495407;

   /* book 2 specification */
   strcpy( Book2.title, "Telecom Billing");
   strcpy( Book2.author, "Zara Ali");
   strcpy( Book2.subject, "Telecom Billing Tutorial");
   Book2.id = 6495700;

   /* print Book1 info */
   printf( "Book 1 title : %s\n", Book1.title);
   printf( "Book 1 author : %s\n", Book1.author);
   printf( "Book 1 subject : %s\n", Book1.subject);
   printf( "Book 1 book_id : %d\n\n", Book1.id);

   /* print Book2 info */
   printf( "Book 2 title : %s\n", Book2.title);
   printf( "Book 2 author : %s\n", Book2.author);
   printf( "Book 2 subject : %s\n", Book2.subject);
   printf( "Book 2 book_id : %d\n", Book2.id);

   return 0;
}











//
