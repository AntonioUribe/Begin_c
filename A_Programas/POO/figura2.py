
class FiguraGeometrica:

    __lado: object

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


    def __str__(self):
        return str(self.__lado)



# a = FiguraGeometrica(8,9)
# b = Color("Amarillo")
# print(a)
# print(b)
c = Cuadrado(4, "rojo")
print(c)


#print(c.get_ladoo())
#print(c.area())