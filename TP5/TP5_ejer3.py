#!/usr/bin/env python
# Escriba un programa que abra el siguiente archivo de texto (a descargar de:
# http://bit.ly/noseculpeanadie) y retorne las siguientes estadísticas:
# (a) Cantidad de caracteres.
# (b) Cantidad de oraciones. Una oración culmina con punto.
# (c) Cantidad palabras. Una palabra se separa de la otra por un espacio.
# (d) La/s palabra/s de más de 6 caracteres que más veces se repite en el texto
import os
try:
    fo = open("noseculpeanadie.txt")
except FileNotFoundError:
    os.system("curl -o noseculpeanadie.txt" +
              " -L https://www.dropbox.com" +
              "/s/1u9aq34ehyu4id0/No%20se%20culpe%20a" +
              "%20nadie.txt\?dl\=0")
    fo = open("noseculpeanadie.txt")
content = fo.read()
print("Caracteres: ", len(content))
oraciones = content.split(".")
print("Oraciones: ", len(oraciones))
palabras = content.split(" ")
print("Palabras: ", len(palabras))
pala6 = []
for i in palabras:
            if len(i) > 6:
                pala6.append(i)
# d = {}
d = []
n = []
for k in pala6:
    if k[-1:] == "," or k[-1:] == ".":
        pala6[pala6.index(k)] = k[:-1]
for k in pala6:
    if k not in d:
        d.append(k)
        n.append(pala6.count(k))
indices = []
for i in n:
    if i == max(n):
        indices.append(n.index(i))
masfrecs = []
for i in indices:
    masfrecs.append(d[i])
print("Palabras de más de 6 caracteres repetidas más veces: ", masfrecs)
# print(d)
# print(pala6)
fo.close()
