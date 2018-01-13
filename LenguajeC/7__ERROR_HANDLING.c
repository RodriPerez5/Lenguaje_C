//////////////MER MEJOR

////////////////////////////  errno, perror(). and strerror()  /////////////////
#include <stdio.h>
#include <string.h>
#include <errno.h>


extern int errno ;


int main () {

   printf(" ERRNO:  %d\n\n", errno);/// YO, LA PUSE
   FILE *Pf = fopen("/home/rodri/Unexist.txt", "rb");//Remember that:  FILE  is a type of variable (like int, double, etc.) !!!
   printf(" ERRNO:  %d\n\n", errno);/// YO, LA PUSE


   if (Pf == NULL) {
      fprintf(stderr, "Value of errno: %d\n", errno);//////INVESTIGAR QUE ONDA LA FUNCIÓN  fprintf

      perror("Error printed by perror");

      int Errnum = errno;
      fprintf(stderr, "Error opening file: %s\n", strerror( Errnum ));

   }else {
      fclose (Pf);
   }


return 0;
}














//
