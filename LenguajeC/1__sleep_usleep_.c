#include <stdio.h>
#include <unistd.h>//Para las funciones: sleep y usleep

int main() {

  int contador;//Al no ponerle =(a algún int) entonces lo toma como 0
  for(int i = 0; i < 101; i++){
     printf("  Contador= %d\n", contador++);
     //  sleep(1);Hace una pausa de 1seg, Nota: solo admite enteros
     usleep(70000);//Hace una pausa de: 70000useg = 0.07seg
  }

  return 0;
}
