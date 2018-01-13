/*
Escribir un programa que lea un valor entero desde el teclado, y que muestre su
configuración de bits por pantalla utilizando los operadores << y >>.
*/


// #include <stdio.h>
//
// int main() {
//   int num;
//   scanf("%d", &num);
//    int bit = num>>1;
//   printf("Configuración de bits:%d\n", bit);
//   return 0;
// }

#include <stdio.h>

void gimmebits(int numero)
{
    int i;
    for (i = (sizeof(int) * 8) - 1 ; i >= 0; i--) { //cantidad de bits 8*bytes y restamos uno por que empezamos a contar desde el 0
            (numero & (1u << i)) ? putchar('1') : putchar('0');
    }
    //recorremos el número "numero" a lo largo de su configuración de bits y comprobamos bit a bit
    // si es 0 o 1, comparando con un bit conocido que vamos corriendo a hacia la derecha o más técnicamente
    // descorriendo hacia la izquierda a medida que se ejecuta el loop 1u = 0000000000000001
    // con los operadores << y >> podemos mover ese bit hacia la izquierda o derecha por ejemplo
    // conviertiendolo en 2u = 0000000000000010, y contrastando con el operador & si ese bit es común a ambos números
    // con el operador & en caso de ser cierto imprimimos en la consola un 1 o en caso de ser falso un 0.
    printf("\n");
}

int main()
{
    int numero;
    printf("Ingrese un número entero: ");
    scanf("%d", &numero);
    printf("La configuración de bits de: %d es ", numero);
    gimmebits(numero);

    return 0;
}
