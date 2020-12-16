nombres = []
edades = -[]

for x in range(5):
    nombre = input("Escribe nombre:")
    nombres.append(nombre)
    
    edad = int(input("Escribe tu edad: "))
    edades.append(edad)
print("Nombres de las personas")
for x in range(5):
    if edades[x]>=10:
        print(nombres[x])