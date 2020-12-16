def num():
    num_usuario=int(input("Ingresa un número positivo de uno o dos digitos: "))
    if num_usuario >= 0 and num_usuario <= 100:
        if num_usuario >= 0 and num_usuario <= 10:
            print("Tú número tiene *1* digito.")
        elif num_usuario > 9 and num_usuario <= 100:
            print("Tú número tiene *2* digitos.")
    else:
        print("")
        print("---------------------------------------------------------")
        num()    
num()
print("")
print("---------------------------------------------------------")