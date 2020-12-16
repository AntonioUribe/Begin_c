#funcion de asiganacion de datos
def mostrar_mensaje(mensaje):
    print("-----------")
    print(mensaje)
    print("-----------")
    
def mostrar_suma():
    valor1 = int(input("ingrese el primer valor"))
    valor2 = int(input("ingrese el segundo valor"))
    suma = valor1+valor2
    print("la suma es: ",suma)
    
mostrar_mensaje("El programa muestra la suma de 2 numeros")
mostrar_suma()
mostrar_mensaje("Hasta luego")