aprobados=0
reprobados=0
for f in range(10):
    nota=int(input("Ingresa la nota: "))
    if nota>=7:
        aprobados=aprobados+1
    else:
        reprobados=reprobados+1
print("Cantidad de Aprobados: ")
print(aprobados)
print("Cantidad de Reprobados: ")
print(reprobados)