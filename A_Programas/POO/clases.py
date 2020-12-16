class Punto:


    def __init__(self,padre,madre,hijo=list()):
        self.padre = padre
        self.madre = madre
        self.hijo = hijo

    def __str__(self):
        cadena = self.padre + self.madre
        for i in self.hijo:
            cadena += ','+i
        return cadena
class Punto2(Punto):
    def __init__(self):
        super(Punto2, self).__init__()
    


    
    
    
p1= Punto("Eleazar","Teresa",["Antonio","Pedro"])
print(p1)
p2= Punto("Eleazar","Teresa")
print(p2)