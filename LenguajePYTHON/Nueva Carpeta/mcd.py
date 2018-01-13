
#  python mcd.py

import ejmod

print("Documentación:", ejmod.__doc__)

a = int(input("1er entero: "))
b = int(input("2do entero: "))
print(ejmod.mcdTit + str(ejmod.mcd(a, b)))
