sueldoss = [50,1,20]
'''
for x in range(3):
    valor = int(input("Ingresa el sueldo"))
    sueldos.append(valor)
    
print("lista sin ordenar de los sueldos")
print(sueldos)
'''
for k in range(2,0,-1):
    for x in range(k):
        if sueldoss[x]<sueldoss[x+1]:
            aux = sueldoss[x]
            sueldoss[x] = sueldoss[x+1]
            sueldoss[x+1] = aux
print("sueldos de la lista")
print(sueldoss)