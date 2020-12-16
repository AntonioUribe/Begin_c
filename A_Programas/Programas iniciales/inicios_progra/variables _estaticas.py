'''
#       1er ejemplo
class Miclass:


    variable_clase="Variable clase"
    
    
    def __init__(self, variable_instancia):
        self.variable_instancia=variable_instancia


object1=Miclass("Variable de intancia!!")


Miclass.variable_instancia="Modificando"


print(Miclass.variable_clase)

print(Miclass.variable_instancia)

print(object1.variable_instancia)
'''
class Miclass:


    variable_clase="Variable clase"
    
    
    def __init__(self, variable_instancia):
        self.variable_instancia=variable_instancia


object1=Miclass("Variable de intancia!!")
Miclass.variable_instancia="Modificando"


print(Miclass.variable_instancia)#Valores distintos

print(object1.variable_instancia)#Valores distintos

#Podemos acceder a las variables de clase desde los objetos
print(object1.variable_clase)
#Podemos acceder  a las variables de con el nombre de la clase
print(Miclass.variable_clase)

object1.variable_clase="Modifiando variable clase"
print(object1.variable_clase)
print(Miclass.variable_clase)

object2=Miclass("Nuevo valor de variable de instancia")
print(object2.variable_clase)
print(object2.variable_instancia)

object3=Miclass("Tercer objeto")
Miclass.variable_clase="Cambio desde la clase"
print(object1.variable_clase)
print(object2.variable_clase)
print(object3.variable_clase)
