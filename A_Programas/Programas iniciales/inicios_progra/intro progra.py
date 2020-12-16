lista_edades=[]
cantidad= int(input("¿cuantas edades quieres te pida?"))

for turno in range(cantidad):
    edad=int(input("Dime una edad: "))
    lista_edades.append(edad)
    
print(lista_edades)

for turno in lista_edades:
    print(turno)
