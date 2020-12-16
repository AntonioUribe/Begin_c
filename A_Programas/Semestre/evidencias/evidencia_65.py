def Menu():
    lado = Cuadrado()
    print("Menu")
    print("1-Area")
    print("2-perimetro")
    print("3-salir")
    opcion = input("Elige una variable")
    if opcion =="1": 
        print(f'El area es: {area(lado)}')
    elif opcion =="2":
        print(f'El perimetro es: {perimetro(lado)}')
    else:
        print("fin del programa")
    return  lado
def Cuadrado():
    print("Lado")
    lado=int(input("Escribe el lado del cuadrado: "))
    return lado

def area(lado):
    area1=lado*lado
    return area1

def perimetro(lado):
    perimetro1=lado*4
    return perimetro1
print(f'Lado es: {Menu()}')
