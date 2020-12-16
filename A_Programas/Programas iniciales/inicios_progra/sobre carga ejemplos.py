#Sobre carga de operadores
class Persona:

    def __init__ (self,nombre,numero ):

        self.__nombre=nombre
        self.__numero=numero

    def __add__(self,other):
        return self.__nombre + " " + other.__nombre

    def __mod__(self, other):
        return self.__numero % other.__numero

    

persona1=Persona("Antonio",8)
persona2=Persona("Pedro",2)

print(persona1 % persona2)

print(persona1+ persona2)
