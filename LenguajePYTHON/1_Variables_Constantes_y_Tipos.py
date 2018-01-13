
#     python 1_Variables_Constantes_y_Tipos.py

x = 200
#print(x)
#print("id")
#print(id(x))
print(x,"  id=",id(x))# 200 id VAL
y = x
print(y,"  id=",id(y))#x e y comparten el mismo valor e id(siempre que no se modifique ningún valor)
x += 1
print(x,"  id=",id(x))# id diferente: INMUTABLE!
print(id(x)==id(y))#True or False? Esta línea imprime un:   True ó False
print('')#Imprime una línea en blanco.  En cambio:  print('\n') imprime dos líneas en blanco.


cadena = 'Hola mundo'
print(cadena)
print(cadena[3]) # Imprime el cuarto elemento:  a
#cadena[7] = "M"# Ok or Error?------------------------------------------------->ENTENDERRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR QUE ONDA
print('')


peli = {'Título':"Ran",'Año':' S?'}#ESTO ES UNA ESTRUCTURA DE DATOS NATIVA DE PYTHON LLAMADA: dict (listas indexadas por claves)
print(peli,'                        id',id(peli))
peli['Año'] = 1985
peli['Título'] = 'RAN'
print(peli,'                        id',id(peli)) #mismo id: MUTABLE!
misma=peli
misma['Director'] = "Kurosawa"
print(misma,'id',id(misma)) #mismo id: MUTABLE!
print(id(misma)==id(peli)) # True or False?
print('')



#TIPOS DE DATOS:
Squanchy = 5
print(type(Squanchy), "y", type(5.0))
cadena = "Hola Mundo"
print('Primer letra:', cadena[0],'   ', type(cadena))
z = True
print(type(z), " y es:", z)
z = bool(45 and '')# and  es la funcion lógica AND. Si alguno de los elementos es vacío/cero entonces bool nos devuelve: Falso
print(type(z), " y ahora es:", z)


















#
