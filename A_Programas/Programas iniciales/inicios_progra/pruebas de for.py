print("\t---REGISTRO DE EMPLEADOS---\n")

empleados=[]
i=0
sueldos=[]
empleadosM=0
empleadosm=0
n=int(input("Escribe la cantidad de empleados:"))
for i in range(n):
    empleados.append(input("Escribe nombre de empleados: "))
    print("Empleado\n",i+1)
    sueldos.append(float(input("Escribe el sueldo: ")))

    i=0
for i in range(n):
    if sueldos[i]>empleadosM:
        empleadosM=sueldos[i]
    elif sueldos[i]<empleadosm:
                 empleadosm=sueldos[i]

else:
    print("Mayor",empleadosM)
    print("Menor",empleadosm)
