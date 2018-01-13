# Realizar un programa que modele una partida del juego del ta-te-ti. El mismo debe
# permitir cargar la elección de los competidores, es decir la coordenada (i,j) de cada X y
# O, alternando los turnos, y debe determinar si algún jugador ha ganado la partida, o si
# ha habido un empate. En caso de completar el tablero y que no haya habido ningún
# ganador se debe mostrar un mensaje. Luego de cada turno, se debe dibujar el tablero
# en la pantalla con un formato matricial del tipo:
# XOX
# X
# OO
# Un resumen de las reglas del juego son:
# (a) El tablero es de 3x3 y cualquier cuadricula podrá estar vacía u ocupada sólo por
# una cruz (X en rojo en el dibujo) o un círculo (O en azul en el dibujo).
# (b) Los jugadores juegan por turnos colocando una figura por vez en el tablero. No es
# importante si comienzan las cruces o los círculos.
# (c) Cada casillero es ocupado una vez por un jugador en la partida y no es posible
# cambiar dicho valor.
fin = False
jugador1 = 'X'
jugador2 = 'O'
fila1 = ['.', '.', '.']
fila2 = ['.', '.', '.']
fila3 = ['.', '.', '.']
tablero = [fila1, fila2, fila3]


def mostrar_tablero(tablero):
    # print("\n" * 20)
    for i in tablero:
        print("")
        for j in i:
            print("\t\t\t", j, end="")
        print("\n")


def turno(player):
    mostrar_tablero(tablero)
    satisfactorio = False
    while not satisfactorio:
        x, y = input(
            "\nJugador {0}, ingrese coordenadas (ej. 2,1) (min 0, máx 2):"
            .format(player)).split(',')
        x = int(x)
        y = int(y)
        if x < 3 and y < 3:
            satisfactorio = True
        else:
            print("Le pegaste afuera, intentá devuelta.")
    print(x, y)
    if tablero[x][y] == '.':
        tablero[x][y] = player
    else:
        turno(player)
        print("Ubicacíon previamente elegida, intente de nuevo...")


def diagonal():
    if fila1[0] == fila2[1] and fila2[1] == fila3[2] and fila1[0] != '.':
        print("El ganador es:", fila1[0])
        fin = True
        return fin
    elif fila1[2] == fila2[1] and fila2[1] == fila3[0] and fila1[2] != '.':
        print("El ganador es:", fila1[2])
        fin = True
        return fin
    else:
        return False


def rectaV():
    for i in range(0, 2):
        if fila1[i] == fila2[i] and fila2[i] == fila3[i] and fila1[i] != '.':
            print("El ganador es:", fila1[i])
            fin = True
            return fin
        return False


def rectaH():
    for i in tablero:
        if i[0] == i[1] and i[1] == i[2] and i[0] != '.':
            print("El ganador es:", i[0])
            fin = True
            return fin
        else:
            return False


def lleno():
    a = 0
    for i in tablero:
        if '.' not in i:
            a += 1
    if a == 3:
        print("¡Empate!")
        fin = True
        return fin
    else:
        return False


# def check():
#     print("diagonal", diagonal())
#     print("rectaH", rectaH())
#     print("rectaV", rectaV())
#     print("lleno", lleno())


while not fin:
    turno(jugador1)
    # check()
    if diagonal() or rectaH() or rectaV() or lleno():
        mostrar_tablero(tablero)
        break
    turno(jugador2)
    # check()
    if diagonal() or rectaH() or rectaV() or lleno():
        mostrar_tablero(tablero)
        break


print("\t\t\tGame Over")
