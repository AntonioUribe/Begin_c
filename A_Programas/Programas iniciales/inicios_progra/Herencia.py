print("***HERENCIA***")

'''
            PARTE 1
class Persona:
    def __init__(self,nombre,edad):

        self.nombre=nombre
        self.edad=edad
    def __str__(self):
        return "Nombre: "+self.nombre+ ", Edad: "+str(self.edad)

class Empleado(Persona):
    def __init__(self, nombre, edad, sueldo):
        super().__init__(nombre,edad)
        self.sueldo=sueldo
    def __str__(self):
        return super().__str__()+", Sueldo:"+str(self.sueldo)

persona=Persona("Juan",28)
print(persona)

empleado=Empleado("Karla",30,500.00)
print(empleado)

empleado.nombre="Karla Ivonne"
empleado.sueldo="2500.00"
print(empleado)
'''

class Vehiculo:

    def __init__(self,color,ruedas):
        self.color=color
        self.ruedas=ruedas
    def __str__(self):
        return "Color: " + self.color + ", Ruedas: "+ self.ruedas

class Coche(Vehiculo):
    def __init__(self, color,ruedas, velocidad):
        super().__init__(color,ruedas)
        self.velocidad=velocidad
    def __str__(self):
        return super().__str__() + ", velocidad: " + str(self.velocidad)


class Bicicleta(Vehiculo):
    def __init__ (self,color,ruedas, tipo,):
        super().__init__(color,ruedas)
        self.tipo=tipo
    def __str__(self):
        return super().__str__()+ ", Tipo: " + self.tipo
        
vehiculo=Vehiculo("Rojo","Michellin")
print(vehiculo)

coche=Coche("Amarillo","Michellin", 54.00)
print(coche)

bicicleta=Bicicleta("Verde", "Desconocida","Montaña")
print(bicicleta)
