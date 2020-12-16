from figura_geometrica import FiguraGeometrica
from color import Color
class Cuadrado(FiguraGeometrica,Color):
    def __init__(self,lado,color):
        FiguraGeometrica.__init__(self,lado,lado)
        # opcioanl cuando no son bibliotecas super().__init__(lado,lado)
        Color.__init__(self,color)
        
    def area(self):
        return (self.ancho * self.altura)
     
    
'''
class Triangulo(FiguraGeometrica,Color):
    def __init__(self,ancho,altura,color):
        FiguraGeometrica.__init__(self,ancho,altura)
        Color.__init__(self,color)
        
    def area(self):
        return (self.ancho * self.altura)/2
        
'''
