class Triangulo:
    
    def __init__(self,altura,base):
        self.altura=altura
        self.base=base
    
    def sum_hello(self):
        return self.base * self.altura
    
base = int(input("Escribe la base: "))
altura = int(input("Escribe la altura: "))

triangulo1 = Triangulo(altura, base)

print(triangulo1.sum_hello())

    