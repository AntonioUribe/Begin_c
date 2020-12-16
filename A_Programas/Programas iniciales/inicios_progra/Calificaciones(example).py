print("         Calificaciones\n")

etapas=("c1","c2","c3")

calificaciones=[("ID","c1","c2","c3","|Promedio"),("_______","_____","_______","_______","_______"),[0,45,70,80,0],[0,90,100,78,0],[0,90,100,100,0]]
'''
for i in range(3):
    matriz=""
    for j in range(3):
        
        matriz+=str(calificaciones[i][j])+"\t"
        
    print(matriz)
'''
'''
Imprime y realiza las califiaciones sin ID
c=0
for i in range(2,5):
    prom=0
    for j in range(4):
        prom+=calificaciones[i][j]
        if j==3:
            calificaciones[i][j]="|"+str(prom/3)
            if prom/3>70:
                c+=1
            

for i in range(5):
    matriz=""
    for j in range(4):
        if i==1:
            matriz+=str(calificaciones[i][j])
            
        else:
            matriz+=str(calificaciones[i][j])+"\t"
            
    
    print(matriz)    

print("\n\tCantidad de aprobados:",c)      
'''

'''
Sin Formato de tablas
c=0
n=0
for i in range(2,5):
    prom=0
    for j in range(5):
        prom+=calificaciones[i][j]
        if j==0 and i>=2:
            n+=1
            calificaciones[i][j]="|"+str(n)+"|"
        if j==4:
            calificaciones[i][j]="|"+str(prom/3)
            if prom/3>70:
                c+=1
            
n=0
for i in range(5):
    matriz=""
    for j in range(5):
        if i==1:
            matriz+=str(calificaciones[i][j])
          
        else:
            matriz+=str(calificaciones[i][j])+"\t"
            
    print(matriz)    

print("\n\tCantidad de aprobados:",c)

'''
c=0
n=0
for i in range(2,5):
    prom=0
    for j in range(5):
        prom+=calificaciones[i][j]
        if j==0 and i>=2:
            n+=1
            calificaciones[i][j]=str(n)
        if j==4:
            calificaciones[i][j]="|"+str(prom/3)
            if (prom/3)>70:
                c+=1

#imprime bine sin la primera barra        
n=0
for i in range(5):
    matriz=""
    for j in range(5):
#Imprime sin el if, inserta <<matriz+=str(calificaciones[i][j])+"\t">>. Solamente por ajustar la barra.
        if i==1:
            
            matriz+=str(calificaciones[i][j])
                  
        else:
            
            matriz+=str(calificaciones[i][j])+"\t"
    if i>=3:
        print("_________________________________")
               
    
    print(matriz)    

print("\n\tCantidad de aprobados:",c)
