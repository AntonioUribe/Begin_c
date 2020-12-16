def num_mayor(valor1,valor2,valor3):
    mayor = 0
    
    
    if valor1 >valor2 and valor1>valor3:
        mayor=valo1
    elif valor2 > valor3:
        mayor=valor2
    else:
        mayor=valor3
    return mayor
    
def carga_de_valores():
    valor1 = int(input("ingrese el primer valor"))
    valor2 = int(input("ingrese el segundo valor"))
    valor3 = int(input("Ingrese el tercer valor"))
    
    return num_mayor(valor1,valor2,valor3)
#Llamar la funcion dos veces
print(f'Maoyor es: {carga_de_valores()}')