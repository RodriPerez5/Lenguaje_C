/*
      ¡CALL BY VALUE!
 This method copies the actual value of an argument into the formal parameter of the function. In this case, changes made to
the parameter inside the function have no effect on the argument.

*/


#include <stdio.h>

int Funcion (int Aa){//''Solo en las call by reference podemos colocar el: void  Funcion''
  int B = Aa+3;
  Aa+=Aa;//(Aquí tratamos de modificar el valor de A)
  printf(" My name is Rodrillix, and A=%d\n\n", Aa);
return B;//CUANDO PONEMOS: algo=UnaSubrutina , ENTONCES SI O SÍ LA SUBRUTINA NOS TIENE QUE RETORNAR Algo!!!
}



int main() {
  int A=7;
  printf(" El valor inicial de A es: A=%d\n\n", A);
  int C = Funcion (A); //Solo si en la Funcion le asignamos un retunr_type VOID, ENTONCES podemos no colocar:   int C =    (Y no colocaríamos la línea siguiente, claro)
  printf(" El valor de B retornado de la Funcion es: C=%d\n\n", C);

  printf(" Termina siendo A=%d (es decir: !NO se modificó!)\n\n", A); //AQUÍ VEMOS QUE EL VALOR DE A NO SE MODIFICA AL PASAR POR LA Funcion, YA QUE HICIMOS UNA: ¡CALL BY VALUE!
  return 0; //No pasa naranja si no ponemos el return 0 en el main con int.
}




//
