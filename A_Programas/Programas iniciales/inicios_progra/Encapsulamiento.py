
'''
        ++++Primera fase METODOS PRIVADOS+++

print("POO Encapsulamiento")
class Persona:
    def __init__(self, nombre,edad):
        self.__nombre=nombre
        self.__edad=edad
    def get_nombre(self):
        return self.__nombre
        
    def set_nombre(self,nombre):
        self.__nombre=nombre
        
    def get_edad(self):
        return self.__edad
    def set_edad(self,edad):
        self.__edad=edad
        
p1=Persona("Juan",18)
#print(p1.__nombre) Error
print(p1.get_nombre())
print(p1.get_edad())
#p1.__nombre="Karla" Error
p1.set_nombre("Karla")
print(p1.get_nombre())
print(p1.set_edad(20))
print(p1.get_edad())
'''



class Persona:
    def __init__(self,nombre,ap_paterno,ap_materno):
        self.nombre=nombre
        self._ap_paterno=ap_paterno
        self.__ap_materno=ap_materno

    def metodo_publico(self):
        self.__metodo_privado()

    def __metodo_privado(self): 
        print(self.nombre)
        print(self._ap_paterno)
        print(self.__ap_materno)

    def get_materno(self):
        return self.__ap_materno

    def set_materno(self,ap_materno):
        self.__ap_materno=ap_materno

N="ANTONIO"
P="URIBE"
M="SALAZAR"
p1=Persona(N,P,M)
#p1__metodo_privado() NO SE PUEDE ACCEDER DEBIDO A QUE ES PRIVADO
p1.metodo_publico()
'''
print(p1.nombre)
print(p1._ap_paterno)
#print(p1.__ap_materno) ERROR 
print(p1.get_materno())
'''
