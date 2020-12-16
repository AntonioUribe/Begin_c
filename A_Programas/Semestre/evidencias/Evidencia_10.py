"""Realiza un programa que solicite 2 numeros distintos que muestre en pantalla
cual es el mayor de ellos"""

#Lectura de datos
num1=int(input("Ingres el primer numero: "))
num2=int(input("Ingresa el segundo numero: "))

#Condicional
if num1>num2:

    #Mostrar resultados
    print("El numero mas grande es: ")
    print(num1)
else:
    print(num2)
