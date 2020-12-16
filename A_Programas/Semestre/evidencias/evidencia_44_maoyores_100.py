lista=[1000,6000,400,23,130,300,60,2000]
cantidad = 0
x=0
while x<len(lista):
    if lista[x]>100:
        cantidad = cantidad+1
    x+=1
    
print("Las cantides de la lista num:")
print(lista)
print("La canitidad mayores a 100")
print(cantidad)