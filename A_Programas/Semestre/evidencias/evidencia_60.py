#Antonio de jesus Uribe Salazar
def carga_suma():
    valor1=int(input("Ingrese el 1er valor"))
    valor2 = int(input("Ingrese el segundo valor"))
    suma = valor1+valor2
    print("Suma",suma)
def finalizar():
    print("---------------------")
    print("Gracias por utilizar el sistema")
    
def presentacion():
    print("Programa que permite cargar dos valores")
    print("Realizar lasuma de los valores")
    print("-----------------------")
    
#Mandar llamar al programa funciones
presentacion()
carga_suma()
finalizar()
