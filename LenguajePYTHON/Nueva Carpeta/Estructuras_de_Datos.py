
# python Estructuras_de_Datos.py


def print_peli(peli):
    if 'titulo' in peli:
        print("Título:", peli['titulo'])
    if 'año' in peli:
        print("Año:", peli['año'])

def definir_año(peli, año):
    peli['año'] = año

peli = {'titulo':'Pulp Fiction'}
definir_año(peli, 1994)
print_peli(peli)

lista_de_pelis = [peli]
nueva_peli = {'titulo':'Primer'}
lista_de_pelis.append(nueva_peli)

print('Tamaño:',len(lista_de_pelis))
for peli in lista_de_pelis:
   print_peli(peli)

lista_de_pelis.remove(peli)
