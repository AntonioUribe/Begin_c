sueldo=int(input("Ingresa el sueldo: "))
antiguedad=int(input("Ingresa la antiguedad en años: "))
if sueldo<=500 and antiguedad >= 10:
    print("Sueldo a pagar con aumento de 20%: ", sueldo+sueldo*.20)
elif sueldo<=500 and antiguedad <= 10:
    print("Sueldo a pagar con aumento de 5%: ", sueldo+sueldo*.05)
else:
    print("Sueldo a pagar: ", sueldo)