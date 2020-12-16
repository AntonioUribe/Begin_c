print("POO")


class Persona:

    def __init__(self,nombre,edad):
        self.nombre=nombre
        self.edad=edad
        
#Modificar los valores
Persona.nombre="Juan"
Persona.edad=28
#Acceder a los valores
print(Persona.nombre)
print(Persona.edad)

#Creacion de obejto
persona=Persona("Karla",30)
print(persona.nombre)
print(Persona.edad)
print(id(persona))

#Creacion de un segundo objeto
persona2=Persona("Carlos",40)
print(persona2.nombre)
print(persona2.edad)
print(id(persona2))



'''
    **PARTE 2**
    
class Aritmetica:

    Clase arimetica para realizar las operaicones suma,restar, etc
    def __init__(self, operando1, operando2):
        self.operando1=operando1
        self.operando2=operando2

    def sumar(self):
        return self.operando1+self.operando2

    def restar(self):
        return self.operando1-self.operando2
    def multiplicar(self):
        return self.operando1*self.operando2
    def division(self):
        return self.operando1/self.operando2
#Cremos un nuevo objeto
aritmetica=Aritmetica(2,4)
aritmetica2=Aritmetica(2,3)
aritmetica3=Aritmetica(6,6)
aritmetica4=Aritmetica(10,2)
print("Resultado de suma:",aritmetica.sumar())
print("Resultado de resta",aritmetica2.restar())
print("Resultado de mutiplicar",aritmetica3.multiplicar())
print("Resultado de division",aritmetica4.division())
'''
'''

print("AREA TRIANGULO")
class Rectangulo:

    def __init__(self,altura,base):
        self.altura=altura
        self.base=base

    def area(self):
        return self.altura*self.base
altura=int(input("Escribe la altura"))
base=int(input("Escribe la base"))
rectangulo=Rectangulo(altura,base)
print("La base del Rectangulo es:",rectangulo.area())


'''
'''
print("VOLUMEN")
class Cubo:
    def __init__(self,largo, ancho, altura):
        self.largo=largo
        self.ancho=ancho
        self.altura=altura

    def volumen(self):
        return self.largo*self.ancho*self.altura

largo=int(input("Escribe el largo: "))
ancho=int(input("Escribe el ancho"))
altura=int(input("Escribe la altura:"))
cubo=Cubo(largo,ancho,altura)
print("El volumen es:",cubo.volumen())
'''
