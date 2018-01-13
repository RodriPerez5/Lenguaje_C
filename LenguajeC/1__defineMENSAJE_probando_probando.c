#include <stdio.h>
#define MENSAJE "Probando, probando %d\n"  ////ES LO MISMO QUE REEMPLAZAR EN EL PRINTF LÍNEA 5, 'MENSAJE' POR: "Probando, probando %d\n"
 int main() {
    int unoDosTres = 123;
    printf(MENSAJE, unoDosTres);
 return 0;
}

// #include <stdio.h>
//  int main(int argc, char *argv[]) {
//     int unoDosTres = 123;
//     printf("Probando, probando %d\n", unoDosTres);
//  return 0;
// }
