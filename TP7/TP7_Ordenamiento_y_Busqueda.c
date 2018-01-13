/*
 Ordenamiento y búsqueda
 Implemente los algoritmos de ordenamiento bubblesort y quicksort, y el
 algoritmo de búsqueda binaria. Implemente cada uno de ellos en una función.
 Utilice recursión para implementar quicksort y búsqueda binaria. Escriba
 además un programa (main) que:
        1. genere un arreglo aleatorio de 1000 elementos, cada uno tomando un valor
          entre 0 y 1000 (utilice la función rand() y el operador módulo %);
        2. guarde el valor 500 en una posición aleatoria dentro del arreglo;
        3. ordene el arreglo mediante bubblesort o quicksort (a elección del usuario);
        4. y finalmente que busque el elemento 500 dentro del arreglo especificado
          por el usuario y muestre por pantalla el subíndice donde se encontró.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LARGO 1000

void set_seed();
int caos(int MAXIMO);
void fillVector();
void mostrar_vector(int *u, int N);
void bubblesort();
void quicksort(int Ext_IZQ, int Ext_DER, int Pivote);
int buscar(int pivote, int derIndx, int izqIndx, int valor);

int array[LARGO];
int EXITO = 0;

int main(int argc, char const *argv[]) {
  set_seed();

  fillVector();
  array[caos(LARGO)] = 500;
  // mostrar_vector(array, LARGO);
  int selector;
  printf("Hay dos metodos de ordenamiento en este programa, seleccione uno.\n "
         "Bubblesort(1) Quicksort(2)[default]\n");
  selector = getchar();
  if (selector == 49) {
    bubblesort();
    printf("Bubblesort!\n");
  } else {
    quicksort(0, (LARGO - 1), (int)(LARGO - 1) / 2);
    printf("Quicksort!\n");
  }
  // mostrar_vector(array, LARGO);
  int index = buscar(LARGO / 2, 0, LARGO, 500);
  printf("%d se encuentra en la posición %d\n", array[index], index);

  return 0;
}

void set_seed() {
  time_t segundosEpoch = time(NULL);
  srand(segundosEpoch);
}

int caos(int MAXIMO) { return (rand() % (MAXIMO + 1)); }

void fillVector() {
  for (size_t i = 0; i < LARGO; i++) {
    array[i] = caos(1000);
  }
}

void mostrar_vector(int *u, int N) {
  printf("[%d", u[0]);
  for (size_t i = 1; i < N; i++) {
    printf(", %d", u[i]);
  }
  printf("]\n\n");
}

void bubblesort() {
  for (size_t j = 0; j < (LARGO - 1); j++) {
    for (size_t i = 0; i < (LARGO - j - 1); i++) {
      if (array[i] > array[i + 1]) {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}

int buscar(int pivote, int derIndx, int izqIndx, int valor) {
  if (!EXITO) {
    if (array[pivote] == valor) {
      EXITO = 1;
      return pivote;
    } else if (array[pivote] > valor) {
      izqIndx = pivote;
      pivote = izqIndx - (izqIndx - derIndx) / 2;
      buscar(pivote, derIndx, izqIndx, valor);
    } else if (array[pivote] < valor) {
      derIndx = pivote;
      pivote = derIndx + (izqIndx - derIndx) / 2;
      buscar(pivote, derIndx, izqIndx, valor);
    }
  }
}

void quicksort(int Ext_IZQ, int Ext_DER, int Pivote) {
  int valor_pivote, i, j, a;
  valor_pivote = array[Pivote];
  i = Ext_IZQ;
  j = Ext_DER;
  while (i < j) {
    while (array[i] < valor_pivote) {
      i++;
    }
    while (array[j] > valor_pivote) {
      j--;
    }
    if (i < j) {
      a = array[i];
      array[i] = array[j];
      array[j] = a;
      i++;
      j--;
    }
  }

  if ((j - Ext_IZQ) >= 1) {
    quicksort(Ext_IZQ, j, (int)(Ext_IZQ + j) / 2);
  }

  if ((Ext_DER - i) >= 1 && EXITO == 0) {
    if ((Ext_DER - i) == 1 && i == j) {
      EXITO = 777;
    }
    quicksort(i, Ext_DER, (int)(i + Ext_DER) / 2);
    EXITO = 0;
  }
  return;
}
