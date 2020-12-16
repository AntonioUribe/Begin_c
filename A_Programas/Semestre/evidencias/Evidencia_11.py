"""11.-Realizar un programa que solicite ingresar por teclado de 2 numeros,
si el primero es mayor al segundo imprimir su suma y resta,
en caso contrario informar la multiplicacion y la division del primero
respecto al segundo"""

#Lectura de datos
num1=int(input("Ingresa el primer numero: "))
num2=int(input("Ingresa el segundo numero: "))

#Condicional
if num1>num2:
    suma= num1+num2
    print("La suma de los numeros ingresados es: ")
    print(suma)
    resta= num1-num2
    print("La resta de los numeros ingresados es: ")
    print(resta)
else:
    multi= num1*num2
    print("La multiplicacion de los numeros ingresados es: ")
    print(multi)
    div= num1/num2
    print("La division de los numeros ingresados es: ")
    print(div)
