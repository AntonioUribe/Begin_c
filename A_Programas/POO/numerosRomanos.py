#numero del 1-10
'''
num=[10, 9, 5, 4,1]
romano = ["X", "IX", "V", "IV","I"]
resultado = ''
numero = int(input("Escribe numero: "))
i=0
while i<len(num):
    
    
    if numero // num[i] !=0:
        resultado += romano[i]
        numero-=num[i]
    else:
        i+=1      
    
        
print(resultado)
'''

class Num_Romano:
    
    def __init__(self,numero,num,romano):
        self.numero = numero
        self.num = num
        self.romano = romano 
        
    
    def __str__(self):

        i=0
        resultado = ""
        while self.numero >0:
            while i<len(self.num):
                if self.numero // self.num[i] !=0:
                    resultado += self.romano[i]
                    self.numero-=self.num[i]
                else:
                    i+=1
        return f'''
            El numero Romano es:  {resultado}
                '''                   
print(Num_Romano(4,[40,10, 9, 5, 4,1],["XL","X", "IX", "V", "IV","I"]))


'''
class Num_Romano:
    
    def __init__(self,numero):
        self.numero = numero
        
        
    
    def __str__(self):

        i=0
        num=[10, 9, 5, 4,1]
        romano = ["X", "IX", "V", "IV","I"]
        resultado = ""
        while i<len(num):
            if self.numero // num[i] !=0:
                resultado += romano[i]
                self.numero-=num[i]
            else:
                i+=1
        return resultado

print(Num_Romano(9))
'''
    