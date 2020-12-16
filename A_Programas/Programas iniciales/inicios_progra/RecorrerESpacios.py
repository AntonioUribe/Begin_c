print("Recorrer Espacios")
n=int(input("Cuantos alumnos quieres?\n"))
i=0
alumnos=[]
for i in range(n):
    alumnos.append(input("Escribe el nombre: "))
    i=i+1

for i in range(n):
    if len(alumnos[i]) == 0:
        alumnos[i]="2"
    print(alumnos[i])
print(len(1))


    
