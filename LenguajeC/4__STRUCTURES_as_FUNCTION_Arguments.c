#include <stdio.h>
#include <string.h>


struct Books {  char title[50];
                char author[50];
                char subject[100];
                int  id;           };


/* function declaration */
void PrintearBOOK( struct Books book, int i );



int main( ) {
   struct Books Book1;
   struct Books Book2;
   strcpy( Book1.title, "C Programming");
   strcpy( Book1.author, "Nuha Ali");
   strcpy( Book1.subject, "C Programming Tutorial");
   Book1.id = 6495407;
   strcpy( Book2.title, "Telecom Billing");
   strcpy( Book2.author, "Zara Ali");
   strcpy( Book2.subject, "Telecom Billing Tutorial");
   Book2.id = 6495700;
   PrintearBOOK( Book1, 1 );
   printf("\n");
   PrintearBOOK( Book2, 2 );
   return 0;
}



void PrintearBOOK( struct Books book, int i ) {
   printf( "Book %d title : %s\n", i, book.title);
   printf( "Book %d author : %s\n", i, book.author);
   printf( "Book %d subject : %s\n", i, book.subject);
   printf( "Book %d book_id : %d\n", i, book.id);
}





















//
