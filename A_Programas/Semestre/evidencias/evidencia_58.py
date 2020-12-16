nombres = []
sueldos = []
total_sueldos = []
for x in range(3):
    nom = input("Ingresaal nombre del empleado")
    nombres.append(nom)
    
    su1 = int(input("ingresa 1 sueldo"))
    su2 = int(input("ingresa 2 sueld"))
    su3 = int(input("ingresa 3 sueld"))
    sueldos.append([su1,su2,su3])
for x in range(3):
    for y in range(3):
        total = sueldos[x][y] + sueldos[x][y] + sueldos[x][y]
    total_sueldos.append(total)
print(sueldos)
for x in range(3):
    print(nombres[x], total_sueldos[x])