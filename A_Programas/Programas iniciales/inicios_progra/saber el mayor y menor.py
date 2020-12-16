print("           **Registro de empelados**")

n=int(input("Escribe el numero de empleados nuevos: "))
i=0
sueldoma=0
sueldome=0
empleados=[]
sueldo=[]
while i<n :
    
    empleados.append(input("Escribe el nombre del usuario:"))
    print("El empleado registrado sera el No.",i+1)
    sueldo.append(float(input("Escribe el sueldo:")))
    i=i+1
i=0
while i<n :
    
    if sueldo[i]>sueldoma:
        sueldoma=sueldo[i]
        empleadoM=empleados[i]
    else:
        sueldome=sueldo[i]
        empleadoMm=empleados[i]
    i=i+1
else:
        print("Mayor",sueldoma,empleadoM)
        print("Menor",sueldome,empleadoMm)

'''
****************************************
while(True):
    try:
        n=float(input("Escribe un nnumero: "))
        print("Bien hecho")
        
        
    except:
        print("Escribe otra vez")
    else:
        print("lel")
        break
        
print(n*3)
****************************************
'''

'''
try:
    n=input("Escribe un nnumero: ")
    print(n/0)
except Exception as x:
    print(type(x).__name__)
 '''   
    
    
    



    

    
