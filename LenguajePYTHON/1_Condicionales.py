
# python 1_Condicionales.py

#ej de condicional múltiple
num = float(input("Ingrese un real: "))
if num == 0:
  print("Es cero")
elif num > 0:
  print("Es positivo")
else:
  print("Es negativo")

#ej de condicional anidado
sig = int(num) # sig solo toma la parte entera de num (sin redondear!)
if sig == num:
  print("El valor es también entero")
else:
  if num - sig > 0.5:
      sig = sig + 1
  print(sig, "es el redondeo significativo")












  #
