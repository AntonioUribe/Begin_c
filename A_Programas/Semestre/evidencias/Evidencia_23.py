print("Ingresa 3 números, al menos uno con valor menor a 10 ")
numuno=int(input("Primer Número: "))
numdos=int(input("Segundo Número: "))
numtres=int(input("Tercer Número: "))
if numuno<=10:
    print("Al menos uno de tús numeros es menor a Diez")
else:
    if numdos<=10:
        print("Al menos uno de tús numeros es menor a Diez")
    else:
        if numtres<=10:
            print("Al menos uno de tús numeros es menor a Diez")
        else:
            print("Ninguno de tús números es menor a Diez")