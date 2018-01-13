#!/usr/bin/env python
# Escriba un programa que solicite al usuario un valor en binario y luego
# retorne su valor # en sistema decimal, hexadecimal y octal. Implemente 2
# versiones:
# (a) Sin utilizar funciones incluidas en el intérprete (built-in functions)
# (b) Utilizando las funciones incluidas en el intérprete (ej: hex(), oct())
import mismodulos.binario_converter as mods
a = input('ingrese número en binario:')
b = mods.toDecimal(a)
c = mods.toHexadecimal(a)
d = mods.toOctal(a)
print("Conversión sin utilizar funciones incluidas en el intérprete:")
print("En Decimal ->", b)
print("En hexadecimal ->", c)
print("En Octal ->", d, "\n")
print("Conversión Utilizando las funciones incluidas en el intérprete:")
print("En Decimal ->", int(a, 2))
print("En hexadecimal ->", hex(int(a, 2)))
print("En Octal ->", oct(int(a, 2)), "\n")
