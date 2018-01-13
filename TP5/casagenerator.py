import random
random.seed()
Casa = []
for a in range(1, random.randint(2, 10)):
    cuartos = {
        'largo': random.randint(1, 15),
        'ancho': random.randint(1, 15),
        'alto': 2.5,
        'puertas': random.randint(1, 4),
        'ventanas': random.randint(1, 5),
        'manos': random.randint(1, 2)
    }
    Casa.append(cuartos)
thefile = open('casa.py', 'w')
thefile.write("habitaciones = [\n")
for i in Casa:
    print(i)
    if i is not Casa[-1]:
        thefile.write("    %s,\n" % i)
    else:
        thefile.write("    %s\n" % i)
thefile.write("]\n")
thefile.close()
