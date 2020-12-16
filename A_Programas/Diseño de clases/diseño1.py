import os
import platform
import time
productos=list()
class Producto:
    contador_productos=0
    
    def __init__(self, nombre, precio):
        Producto.contador_productos+=1
        
        self.__id_producto=Producto.contador_productos
        self.__nombre=nombre
        self.__precio=precio
    def get_precio(self):
        return self.__precio
    def hola():
        print("hello")
        return

    def __str__(self):
        return "id producto: " + str(self.__id_producto) + ", Nombre:" + self.__nombre + ", Precio: "+ str(self.__precio)

class Orden:
    contador_ordenes=0

    def __init__(self, productos):
        Orden.contador_ordenes+=1
        self.__id_orden=Orden.contador_ordenes
        self.__productos=productos


    def agregar_producto(self, producto):
        self.__productos.append(producto)

    def calcular_total(self):
        total=0
        for producto in self.__productos:
            total+=producto.get_precio()
        return total
            
    def __str__(self):
        productos_str=""

        for producto in self.__productos:
            productos_str += producto.__str__() + " | \n"
             
        return "Orden: "+ str(self.__id_orden) + ", Productos: \n"+ productos_str






print("\t\t<<-Modelo de ventas->>")
Near=True
numero_pedidos=int(input("Escribe el numero de pedidos"))
while(Near):
    
    print("\t\t<<-Modelo de ventas->>")
    print("1-Inventario")
    print("2-Imprimir invetario")
    print("3-Agregar inventario")
    print("4-Total de ventas")
    opcion=input("Elige: ")
    

    if opcion != "1" and opcion !="2" and opcion !="3" and opcion !="4" and opcion !="x":
        print("Vuelve a escribir")
    elif opcion=="X":
        Near=True
        print(Salir)
    
    elif opcion=="1":
        for n in range(numero_pedidos):
            productos.append(Producto(input("Escribe Articulo: "),float(input("Escribe precio:"))))
    elif opcion=="2":
        ordenes=Orden(productos)
        print(ordenes)
    


    



#productos.append(producto3)



'''
producto1=Producto("Camisa",100.00)
producto2=Producto("Pantalones",199.99)
producto3=Producto("Calcetines", 50.00)

productos=[producto1,producto2]

orden1=Orden(productos)
print(orden1)
#productos.append(producto3)

orden2=Orden(productos)
orden2.agregar_producto(producto3)

print(orden2)
print(orden2.calcular_total())
'''
    
