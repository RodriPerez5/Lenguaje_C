
#    python Subrutinas_y_Modulacion_MCD.py


import Subrutinas_y_Modulacion_ejMODs

print("Documentación:", Subrutinas_y_Modulacion_ejMODs.__doc__)

a = int(input("1er entero: "))
b = int(input("2do entero: "))
print(Subrutinas_y_Modulacion_ejMODs.mcdTit + str(Subrutinas_y_Modulacion_ejMODs.mcd(a, b)))
