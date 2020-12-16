#Iterar repetidamente un bloque de código

numero_inicial = int(input("Dime el número inicial para contar de uno en uno: "))
numero_final = int(input("Dime el número final hasta el cual contar: "))

contador = numero_inicial

while contador <= numero_final:        #Modo procedural tradicional
    print(contador)
    contador = contador + 1

print("@" * 30)  

for valor in range(numero_inicial, numero_final+1):   #Alternativa "pythónica"
    print(valor)
    
    