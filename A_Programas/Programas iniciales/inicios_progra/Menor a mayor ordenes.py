'''
lista=[1,2,3,4,5,6,7,8,9,10]





for i in range(10):
    print(lista[i:],"                      ",lista[:-i])
    
for i in range(10):
    print(lista[i::-1])
#   print(lista[:i])
    
''' 
    


def menorAmayor(unaLista):
    for numPasado in range(len(unaLista)-1,0,-1):
        for j in range(numPasado):
            if unaLista[j]>unaLista[j+1]:
                temp = unaLista[j]
                unaLista[j] = unaLista[j+1]
                unaLista[j+1] = temp

unaLista = [50,3,5,7]
menorAmayor(unaLista)
print(unaLista)

'''   
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




            


