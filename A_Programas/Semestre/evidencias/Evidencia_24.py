print("Ingresa 3 números iguales")
numuno=int(input("Primer Número: "))
numdos=int(input("Segundo Número: "))
numtres=int(input("Tercer Número: "))
suma=numuno+numdos
multi=suma*numtres
if numuno==numdos and numdos==numtres:
    print("Suma de los primeros dos números: ", suma)
    print("Multiplicado por el tercer número: ", multi)
else:
    print("Ingresaste números distintos.")