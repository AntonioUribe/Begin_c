"""Ingrese por teclado 3 numeros distintos, mostrar en pantalla el mayor de
esos 3 numeros"""

#Lectura de datos
num1=int(input("Ingresa el primer numero: "))
num2=int(input("Ingresa el segundo numero: "))
num3=int(input("Ingresa el tercer numero: "))

#Condicionales
if num1>num2:
    if num1>num3:
        print(num1)
    else:
        print(num3)
else:
    if num2>num1:
        if num2>num3:
            print(num2)
    else:
         print(num3)
