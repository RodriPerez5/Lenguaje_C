
#  python 1_Bucles.py

#programa cabulero que imprime impares
a = int(input("Entero desde: "))
b = int(input("Entero hasta: "))
while a <= b :
  if a % 2 != 0 :
     print(a, ', ', end='', sep='') # end='' es para que imprima en una sola línea.  sep='' es para que no haya separación entre a y la coma
  a += 1
  if a == 13:
     break #SI SE IMPRIME Fin! CUANDO a=13
else: #Fin! SOLO SE IMPRIME CUANDO NO SE ENTRE AL while, Ó CUANDO SE PASA POR EL break.
  print("Fin!")
