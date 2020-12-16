from cuadrado import Cuadrado
from figura_geometrica import FiguraGeometrica
#No es posible crear objetos de una clase abstracta
#figura_Geometrica=FiguraGeometrica()
cuadrado=Cuadrado(4,"Rojo")

print(cuadrado.area())
print(cuadrado.color)
#Method Resolution Order
print(Cuadrado.mro())

'''


'''
