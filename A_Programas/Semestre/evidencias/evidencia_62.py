'''
Desarrollar un programa que solicite la carga de tres valores y muestre el menor.
a)Desde el bloque principal del programa llamar 2 veces a dicha función (sin utilizar una estructura repetitiva)
'''
def num_menor():
    menor = 0
    valor1 = int(input("ingrese el primer valor"))
    valor2 = int(input("ingrese el segundo valor"))
    valor3 = int(input("Ingrese el tercer valor"))
    
    if valor1 <valor2 and valor1<valor3:
        menor = valor1
    elif valor2 < valor3:
        menor = valor2
    else:
        menor = valor3
        
    return menor
#Llamar la funcion dos veces
print(f'Primera vez {num_menor()}')
print(f'Segunda vez {num_menor()}')