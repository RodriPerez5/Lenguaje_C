

//////////////////////////////////READING A FILE////////////////////////////////
#include <stdio.h>

int main() {

   FILE *Fp;
   
   char Buff[255];

   Fp = fopen("/home/rodri/TEXT_by_C.txt", "r");
   fscanf(Fp, "%s", Buff);//This function stops reading after encountering the first space character.
   printf("1: %s\n", Buff );

                               //The following function:  fgets()  reads the remaining line after what fscanf has read.
   fgets(Buff, 255, (FILE*)Fp);//If this function encounters a newline character '\n' or the end of the file EOF before they have read the maximum..
   printf("2: %s", Buff );     //..number of characters, then it returns only the characters read up to that point including the new line character.

   fgets(Buff, 255, (FILE*)Fp);
   printf("3: %s", Buff );

   fgets(Buff, 255, (FILE*)Fp);
   printf("4: %s", Buff );
   fclose(Fp);
}













//
