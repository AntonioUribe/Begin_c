'''print("Programa 1")
verduras=["zanahoria","tomate","brocoli"]

#coliflor,repollo y cebolla
for x in range(3) :
    verduras.append(input("Agregar mas verduras:"))
    
print(verduras)
'''

'''
print("Programa 2")
numeros=[]
promedios=0
i=0
for x in range(0,15) :
    
    numeros.append(int(input("Escribe un numero:")))
    
    promedios=numeros[i]+promedios
    i=i+1
print("Promedio es",float(promedios/15))

'''
'''
print("Programa 3")
listas=["alumno","estudiate",1,455,"hola","Melanie"]

for x in range(0,5) :
    listas.append(input("Agregar mas elementos:"))
    
print(listas[1::2])
    
'''


print("Programa 4")
print("Palabras")
mensaje=input("Escribe un mensaje: ")
print("Mayusculas:",mensaje.upper())
print("Slices")
print("Obtener slices")
i=int(input("letra inicial que desea obtener"))
f=int(input("hasta la letra final"))
while i > len(mensaje) or f >len(mensaje):
    print("Escribe otra vez: ")
    i=int(input("letra inicial que desea obtener"))
    f=int(input("hasta la letra final"))
    
print(mensaje[i-1:f+1])

