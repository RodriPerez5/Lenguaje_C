/*
C programmers can create, open, close text or binary files for their data storage.


La función OPEN devuelve un número entero que identifica a un descriptor de fichero, ó -1 en caso de error.
         int open(const char *camino, int flags);

La función close cierra el descriptor de fichero que le pasemos como parámetro. Devuelve 0 en caso de..
..éxito y -1 en caso de error.
         int close(int fd);
*/




//////////////////////////////////WRITING A FILE////////////////////////////////
#include <stdio.h>

int main() {

   FILE *Fp;//// FILE is a type of variable (like int, double, etc.) !!!
   Fp = fopen("/home/rodri/TEXT_by_C.txt", "w+");

   fprintf(Fp, "\n This is testing for fprintf. Yeah!\n");//These are tow different functions..
   fputs("\n   This is testing for fputs. Yeah!\n", Fp);  //..to write a file.

   fclose(Fp);
}
/*
When the above code is compiled and executed, it creates a new file  TEXT_by_C.txt  in  /home/rodri  directory and..
..writes two lines using two different functions.
*/










//
