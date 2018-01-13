#include <stdio.h>

int main () {
   /* an array with 5 rows and 2 columns*/
   int a[5][2] = { {0,1}, {2,3}, {4,5}, {6,7},{8,9}};//Los paréntesis intemedios si se deben colocar!
   int i, j;

   /* output each array element's value */
   for ( i=0; i<5; i++ ) {/////////////////////////////////OJO QUE NO SE PUEDE USAR NUNCA i=1 !!!!!!!!,   (ni j=1), ya que las Matrices..
      for ( j = 0; j < 2; j++ ) {//////////////////////////..vienen por defecto con el primer casillero con un cero como nombre de posición.
         printf("a[%d][%d]= %d    ", i,j, a[i][j] );
      }
      printf("\n");
   }

   return 0;
}
