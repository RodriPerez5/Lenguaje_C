# La empresa de mantenimiento “La pinturita” desea calcular la cantidad de latas de
# pintura necesarias del mismo color para pintar las paredes de todas las habitaciones de
# una casa. Se conoce la siguiente información: Las puertas son de 0.75 x 2.00 mts
# (ancho x alto) y las ventanas son de 1.20 x 1.50 mts. La pintura tiene las siguientes
# características:
# Tipo de Latex Cada litro rinde (por
# mano) Viene en latas de
# (litros)
# Mate 14 m^2  =  1, 4, 10 y 20
# La información variable consiste de:
# El ancho, largo y alto de cada habitación.
# Cantidad de cada tipo de aberturas en cada habitación.
# Cantidad de manos a pintar (una “mano” representa cubrir completamente la
# superficie con pintura).
# El progama debe determinar la cantidad de latas de pintura a utilizar de manera tal que
# se minimice el costo total, informando al usuario dicho costo. El costo de cada lata es el
# siguiente: la lata de 1 litro cuesta $50, la de 4 cuesta $170, la de 10 cuesta $400 y la de
# 20 litros cuesta $700. Observe que cuantas menos latas se compren menos se paga,
# ya que, por ejemplo, una lata de 4 lts cuesta menos que 4 latas de 1 lts.
import casa
import math
rooms = casa.habitaciones
latas = {1: 50, 4: 170, 10: 400, 20: 700}


class ventana:
    x = 1.20
    y = 1.50
    area = x * y


class puerta:
    x = 0.75
    y = 2.00
    area = x * y


def calcSuperficie(casa):
    sup = 0
    for i in casa:
        sup += i['manos'] * ((i['largo'] * i['alto']) * 2) + 2 * (i['ancho'] * i['alto'])
        sup -= i['puertas'] * puerta.area + i['ventanas'] * ventana.area
    return sup


def calcLatas(sup):
    sup /= 14
    cant = {'veinte': 0, 'diez': 0, 'cuatro': 0, 'uno': 0}
    if (sup % 20) > 16:
        veinte = math.ceil(sup / 20)
        cant['veinte'] = veinte
        return cant
    else:
        veinte = int(sup / 20)
    cant['veinte'] = veinte
    if (sup - veinte * 20) % 10 > 8:
        diez = math.ceil((sup - veinte * 20) / 10)
        cant['diez'] = diez
        return cant
    else:
        diez = int((sup - veinte * 20) / 10)
    cant['diez'] = diez
    if (sup - veinte * 20 - diez * 10) % 4 > 3:
        cuatro = math.ceil((sup - veinte * 20 - diez * 10) / 4)
        cant['cuatro'] = cuatro
        return cant
    else:
        cuatro = int((sup - veinte * 20 - diez * 10) / 4)
    cant['cuatro'] = cuatro
    if (sup - veinte * 20 - diez * 10 - cuatro * 4) < 1:
        uno = math.ceil((sup - veinte * 20 - diez * 10 - cuatro * 4))
    else:
        uno = math.ceil((sup - veinte * 20 - diez * 10 - cuatro * 4))
    cant['uno'] = uno
    return cant


def precio(LATAS):
    guita = 0
    guita += LATAS['veinte'] * latas[20]
    guita += LATAS['diez'] * latas[10]
    guita += LATAS['cuatro'] * latas[4]
    guita += LATAS['uno'] * latas[1]
    return guita


holi = calcSuperficie(rooms)
print("La superficie total a pintar es:", holi)
print("Son necesarios entonces {0}l de pintura".format(holi / 14))
cantidad = calcLatas(holi)
print("Distribuidos en latas de:", cantidad)
garpar = precio(cantidad)
print("Y el total a pagar es: ${0}".format(garpar))
