class Persona:

    def __init__(self, nombre,edad):
        self.__nombre=nombre
        self.__edad=edad
    def __str__ (self):
        return "Nombre: "+ self.__nombre  + ", Edad: " + str(self.__edad)
#Cuando sea privado
    '''
    def __str__ (self):
        return "Nombre: "+ self.nombre  + ", Edad: " + str(self.edad)
    ...ARROJA los dato...
   def get_NE(self):
        return self.__nombre, self.__edad'''
