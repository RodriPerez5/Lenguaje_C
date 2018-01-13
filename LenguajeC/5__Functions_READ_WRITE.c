/*
Las funciones read y write se usan para leer y escribir en un descriptor de fichero que previamente hayamos abierto. Sus prototipos..
..son los siguientes:

    ssize_t read(int fd, void *Buffer, size_t nbytes);
    ssize_t write(int fd, const void *Buffer, size_t nbytes);

Como véis, ambas funciones son iguales y los parámetros que reciben son el descriptor de fichero que devolvía la función..
..open, un puntero a un buffer de memoria y un tamaño que indica el número de bytes del buffer que queramos leer o escribir.
Ambas funciones devuelven el número de bytes leídos o escritos, ó -1 en caso de error.


Con TUBERÍAS(las cuales son similares a un archivo)  fd  es simplemente el Identificador del extremo de la tuberia


The read() function attempts to read nbytes from the file associated with fd, and places the characters read into Buffer.
The write() function attempts to write nbytes from Buffer to the file associated with fd.
*/






/*VER MEJOR EL SGUIENTE EJEMPLO:
Aquí os muestro un ejemplo de cómo se pueden usar estas cuatro funciones para copiar un fichero en otro. Este programa..
..recibe dos parámetros que son el archivo origen y el archivo destino. El archivo origen lo abre en modo sólo lectura (O_RDONLY),..
..mientras que el archivo destino lo abre en modo sólo escritura, creándose en caso de que no exista y..
..truncándolo (O_WRONLY|O_CREAT|O_TRUNC). Luego se usa un bucle para leer del descriptor fd1 (origen), guardarlos en un..
..buffer de memoria y escribirlos en el descriptor fd2 (destino). Finalmente cerrará ambos archivos.
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {

  /* Variables */
  int fd1,fd2;
  char buffer[1024];
  int numbytes;

  /* Comprobamos que se pasan dos argumentos */
  if (argc != 3){
    printf("Uso: %s origen destino\n", argv[0]);
    exit(1);
  }

  /* Abrimos los dos archivos */
  fd1 = open(argv[1], O_RDONLY);
  fd2 = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0700);

  /* Bucle de lectura/escritura */
  while((numbytes = read(fd1, &buffer, sizeof(char))) > 0) {
    write(fd2, &buffer, numbytes);
  }

  /* Cierre de archivos */
  close(fd1);
  close(fd2);
}
















//
