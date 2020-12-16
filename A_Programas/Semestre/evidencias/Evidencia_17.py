def l():
    entrada=int(input("Ingresa un número con valor de hasta tres cifras: "))
    if entrada>=0 and entrada<=1000:
        if entrada >=0 and entrada<=10:
            print("Tu número tiene *1* cifra")
        elif entrada >=9 and entrada<=100:
            print("Tu número tiene *2* cifras")
        else:
            print("Tu número tiene *3* cifras")   
    else:
        print("")
        print("---------------------------------------------------------")
        print("ERROR, vuelve a intentarlo.")
        l()
l()
print("")
print("---------------------------------------------------------")     