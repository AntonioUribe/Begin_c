'''
61.-Desarrollar un programa con dos funciones. La primer solicite el ingreso de un entero y muestre el cuadrado de dicho valor.
a)La segunda que solicite la carga de dos valores y muestre el cubo de los mismos.
b)LLamar desde el bloque del programa principal a ambas funciones.
'''
def cuadrado():
    valor1 = int(input("Ingrese el valor del cuadrado"))
    cuadrado = valor1**2
    return cuadrado
    
def cubo():
    valor1 = int(input("Ingresa el primer valor para el cubo"))
    valor2 = int(input("ingresa el segundo valor para el cubo"))
    cubo1 = valor1**3
    cubo2 = valor2**3
    return cubo1, cubo2
print("     Menu principal")
print("Cuadrado")
print(cuadrado())
print("Cubo")
print(f'el primer numero {cubo()[0]}')
print(f'el segundo numero {cubo()[1]}')
    