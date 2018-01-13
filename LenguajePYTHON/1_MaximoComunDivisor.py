#maximo comun divisor    # python 1_MaximoComunDivisor.py


def MaxComunDivisor(a, b):
    if b==0:
        return a
    else:
        return MaxComunDivisor(b, a % b) #VER MEJOR que onda:  (b, a % b)
               #MaxComunDivisor es el nombre cualquiera de mi función


a = int(input("\n1er entero: "))
b = int(input("2do entero: "))
c = MaxComunDivisor(a, b)
print("  Máximo Común Divisor:", c)
