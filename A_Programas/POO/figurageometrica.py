from turtle import color

'''
class FiguraGeometrica:

    def __init__(self,lado,base):

        self.__lado = lado
        self.__base = base

    def __str__(self):        return fel lado es :{self.__lado} y la base es {self.__base}
    def get_lado(self):
        return self.__lado

class Color:

    def __init__(self,color):
        self.__color = color

    def __str__(self):

        return str(self.__color)

class Cuadrado(FiguraGeometrica,Color):
    def __init__(self, lado,color):
        FiguraGeometrica.__init__(self,lado,lado)
        Color.__init__(self,color)
        self.__area = lado*lado
        self.__colori= color
    def areaa(self):
        return str(self.__area) 
    def __str__(self):
        return "El areea es"+self.areaa() +self.__colori
#a = FiguraGeometrica(8,9)
#b = Color("Amarillo")
#print(a)
#print(b)
'''


class FiguraGeometrica:

    def __init__(self, lado, base):
        self.__lado = lado
        self.__base = base

    def __str__(self):
        return f'''el lado es :{self.__lado} y la base es {self.__base}'''

    def get_lado(self):
        return self.__lado


class Color:

    def __init__(self, color):
        self.__color = color

    def __str__(self):
        return str(self.__color)


class Cuadrado(FiguraGeometrica, Color):
    def __init__(self, lado, color):
        FiguraGeometrica.__init__(self, lado, lado)
        Color.__init__(self, color)
        self.__ladoCuadrado = lado
        self.__colori = color
    def get_ladoo(self):
        return self.__ladoCuadrado



    def area(self):
        areai = self.__ladoCuadrado * self.__ladoCuadrado
        return areai.__str__()

    #       return str(areai)

    def __str__(self):
        return "El area es: " + self.area() + " El color es: " + self.__colori



class Triangulo(FiguraGeometrica,Color):
    def __init__(self,lado,base,color):
        FiguraGeometrica.__init__(self, lado, base)
        Color.__init__(self, color)
        self.__ladotriangulo = lado
        self.__basetriangulo = base
        self.__colori = color
    def area(self):
        areai = int((self.__basetriangulo * self.__ladotriangulo)/2)
        return str(areai)
    def __str__(self):
        return "El area es:" + self.area() + " El color es: " + self.__colori




# a = FiguraGeometrica(8,9)
# b = Color("Amarillo")
# print(a)
# print(b)
c = Cuadrado(4, "rojo")

print(c.get_ladoo())
print(c)

t = Triangulo(4,6,"Verde")
print(t)
