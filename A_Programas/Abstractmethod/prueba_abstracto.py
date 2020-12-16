print("")
#ABC=Abstract Base Class

from abc import ABC, abstractmethod



class FiguraGeometrica(ABC):
    def __init__(self,ancho, altura):
        self.ancho=ancho
        self.altura=altura
        
    @abstractmethod
    def area(self):
        pass


    
class Color:
    def __init__(self,color):
        self.color=color

class Cuadrado(FiguraGeometrica,Color):
    def __init__(self,lado,color):
        FiguraGeometrica.__init__(self,lado,lado)
        # opcioanl cuando no son bibliotecas super().__init__(lado,lado)
        Color.__init__(self,color)
        
    def area(self):
        return (self.ancho * self.altura)

cuadrado=Cuadrado(4,"Rojo")

print(cuadrado.area())
print(cuadrado.color)
#Method Resolution Order
print(Cuadrado.mro())
