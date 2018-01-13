
#      python 1_Operadores.py

#ejemplos de operadores
x = 3
y = 4
print("y= ", y)
print(x/y, "!=", x//y)#La división entera siempre toma el entero menor (No redondea!)
x = x < y**2 #ESTO DEVUELVE: UN True Ó UN False
print("x < y^2?", x)
y = not x #COMO x ES UN False, ENTONCES y SE CONVIERTE EN UN TIPO bool Y ADOPTA EL VALOR True
print("y= ", y)
print(x and y, x or y)#Los operadores lógicos son idiomáticos (and, or, not)

#RESULTAODO:
# 4.5 != 4
# x < y^2? False
# False True
