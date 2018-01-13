/*
 The keyword typedef can be used to give a type, a new name. For example:        typedef unsigned char BYTE;
After this type definition, the identifier BYTE can be used as an abbreviation for the type:      unsigned char b1, b2;      ~      BYTE  b1, b2;
*/


//***************************************************************************************************************************//


/*
 Also, you can use typedef to give a name to your user defined data types as well. For example, you can use typedef with..
..structure to define a new data type and then use that data type to define structure variables directly as follows −
*/
#include <stdio.h>
#include <string.h>


typedef struct Books {  //The structure tag (' Books ') isn't necessary!
   char title[50];
   char author[50];
   char subject[100];
   int id;
} BBOOOOKK;//AQUÍ DEFINIMOS QUE PONER EL TIPO DE VARIABLE:  'struct Books'  SEA LO MISMO QUE PONER SIMPLEMENTE:  'BBOOOOKK'


int main( ) {

   BBOOOOKK book;

   strcpy( book.title, "C Programming");
   strcpy( book.author, "Nuha Ali");
   strcpy( book.subject, "C Programming Tutorial");
   book.id = 6495407;

   printf( "\n Book title: %s\n", book.title);
   printf( " Book author: %s\n", book.author);
   printf( " Book subject: %s\n", book.subject);
   printf( " Book book_id: %d\n\n", book.id);

   return 0;
}





















//
