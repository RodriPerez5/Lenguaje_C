# Dada la siguiente estructura de datos que representa un listado hipotético de
#  alumnos de esta cátedra:
# Escriba un programa que:
# 1. Agregue un valor a cada alumno con
# clave ‘condición’ que indique si ‘recursa’,
# ‘regular’ o ‘promoción’ siguiendo las reglas de evaluación descriptas en el
# programa de la cátedra
# 2. Imprima por pantalla un listado que indique el nombre y la condición
# de cada
# alumno en forma de lista.
# 3. Indique un resumen estadístico: Total de alumnos, cantidad de alumnos por
# condición y promedio general de todas las notas de todos los alumnos.


def notafinal(notas):
    nota = notas[0] * 0.30 + notas[1] * 0.30 + notas[2] * 0.40
    return nota


def condicion(alumno):
    if alumno['entregoTPs?']:
        notas = alumno['notas']
        a = 0
        for i in notas:
            if i < 6:
                if alumno['recuperatorios'][a] > 5:
                    notas[notas.index(i)] = alumno['recuperatorios'][a]
                    a += 1
                else:
                    alumno['condición'] = 'recursa'
        promedio = notafinal(notas)
        if promedio > 6:
            alumno['condición'] = 'promoción'
        elif promedio == 6:
            alumno['condición'] = 'regular'
    else:
        alumno['condición'] = 'recursa'


def resumen(alumnos):
    totalAlumnos = len(alumnos)
    condiciones = {}
    todasLasNotas = []
    for i in alumnos:
        if i['condición'] not in condiciones:
            condiciones[i['condición']] = 1
        else:
            condiciones[i['condición']] += 1
        todasLasNotas += i['notas']
        if 'recuperatorios' in i:
            todasLasNotas += i['recuperatorios']
    promedio = 0
    for i in todasLasNotas:
        promedio += i
    promedio = promedio / len(todasLasNotas)
    print("Resumen: ")
    print("Cantidad de Alumnos:", totalAlumnos)
    print("Cantidad de Alumnos en c/condicion: ", condiciones)
    print("Promedio total:", promedio)


informatica = [
    {
        'apellido': 'Aronofsky',
        'entregoTPs?': True,
        'notas': [6, 7, 6],
    },
    {
        'apellido': 'Nolan',
        'entregoTPs?': True,
        'notas': [7, 3, 6],
        'recuperatorios':[6],
    },
    {
        'apellido': 'Bielinski',
        'entregoTPs?': False,
        'notas': [7, 8, 8],
    },
    {
        'apellido': 'Miyazaki',
        'entregoTPs?': True,
        'notas': [4, 4, 6],
        'recuperatorios':[4, 7],
    }
]

for i in informatica:
    condicion(i)
    pibe = [i['apellido'], i['condición']]
    print(pibe)

resumen(informatica)
