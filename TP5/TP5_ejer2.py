#!/usr/bin/env python
# # Escriba un programa que pida un número positivo de 3 a 6 cifras
#  al usuario y luego
# # imprima los 3 números capicúa que se encuentren más cercanos.
# Considerar que los
# # valores capicúa más cercanos pueden ser mayores o
# menores al valor de referencia.
import mismodulos.capicua as capi
a = input("Ingrese un número positivo de 3 a 6 cifras ")
b = capi.capicuas(a)
print(b)
