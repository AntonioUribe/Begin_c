
'''
class FiguraGeometrica:
    
    def __init__(self,lado,base):
        self.lado=lado
        self.base=base
        
    
    
class Color:
    
    def __init__(self,color):
        self.color = color
    
class Cuadrado(FiguraGeometrica,Color):
    
    def __init__(self,lado,color):
        FiguraGeometrica.__init__(self,lado,lado)
        Color.__init__(self,color)
    
    def area(self):
        return self.lado*self.base

class Triangulo(FiguraGeometrica,Color):
    def __init__(self,lado,base,color):
        FiguraGeometrica.__init__(self,lado,base)
        Color.__init__(self, color)
        
    def area(self):
        
        return (self.lado * self.base)/2
    
t1 = Triangulo(4,3,"rojo")
print(t1.area())
print(t1.color)    
'''
    
#c1=Cuadrado(4,"verde")
#print(c1.base)

class FiguraGeometrica:
    
    def __init__(self,lado,base):
        self.__lado=lado
        self.__base=base
    def __str__(self):
        return (f'''{str(self.__lado)} {str(self.__base)}''')
        
    def get_lado(self):
        return self.__lado
    def set_lado(self,lado):
        self.__lado = lado
    def get_base(self):
        return self.__base
    def set_base(self,base):
        self.__base = base
        
class Color:
    
    def __init__(self,color):
        self.__color = color
    
class Cuadrado(FiguraGeometrica,Color):
    
    def __init__(self,lado,color):
        FiguraGeometrica.__init__(self,lado,lado)
        Color.__init__(self,color)
    
    
    def __str__(self):
        area = self.__lado*self.__lado
        return str(a).__str__()
    
    

class Triangulo(FiguraGeometrica,Color):
    def __init__(self,lado,base,color):
        FiguraGeometrica.__init__(self,lado,base)
        Color.__init__(self, color)
        
    def area(self):
        return (self.__lado*self.__base)/2
    
t1 = Cuadrado(4,"rojo")

print(t1)
  