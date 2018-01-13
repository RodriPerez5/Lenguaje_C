
#  python 2_Subrutinas_y_Modulacion.py

"""
Módulo para resolver el Máximo común divisor
"""
mcdTit = 'Máximo común divisor: '
def mcd(a, b):
    if b == 0:
       return a
    else:
       return mcd(b, a % b)
