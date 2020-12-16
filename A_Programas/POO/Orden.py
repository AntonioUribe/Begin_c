class Producto:
    idp=0
    def __init__(self,nombre,precio):
        Producto.idp+=1
        self.__id =  Producto.idp
        self.__nombre = nombre
        self.__precio = precio
        
    def __str__(self):
        
        return str(self.__id)+self.__nombre +"  "+ str(self.__precio)
    
class Orden:
    ido=0
    def __init__(self,producto):
        Orden.ido+=1
        self.__id = Orden.ido
        self.__producto = producto
        
    def __str__(self):
        cadena=""
        for lel in self.__producto:
            cadena += lel.__str__() + "|"
            
        return "No."+str(self.__id) + "."+cadena

p1 = Producto("Television",2000.00)   
p2 = Producto("Doritos",14.00)
productos = [p1,p2]
orden1 = Orden(productos)
print(orden1)
