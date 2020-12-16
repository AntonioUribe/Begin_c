class Cuadrado:
    
    def __init__(self,lado):
        self.lado=lado
    
    def areaCuadrado(self):
        return self.lado*self.lado
#cuadrado1=Cuadrado(5)
#print(cuadrado1.areaCuadrado())

class Triangulo:
    
    def __init__(self,altura,base):
        self.__altura=altura
        self.__base=base
    
    def Gett(self):
        return self.__altura
    

    def __str__(self):
        return (f"El area es: {self.__altura*self.__base}" )
triangulo1= Triangulo(6,7)
print(triangulo1.Gett())
        
    