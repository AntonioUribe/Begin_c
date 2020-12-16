while True:
    try:
        cantEstudiantes=int(input("Escribe la cantidad de estudiantes: "))+1
        break
    except:
        print("Volver a escribir..")
        input("Continue...")
reprobados=list()
Cal=[("ID","c1","c2","c3"," Promedio")]
idn=0
prom=0
#sCal=list()
for i in range(1,cantEstudiantes):
    
    Cal.append(list())
    prom=0
    for j in range(5):
        
        if j==0:
            idn+=1
            Cal[i].append(idn)
        elif j==4:
            Cal[i].append(prom/3)
            if prom/3<70:
                reprobados.append(idn)
                
        else:
            while True:
                try:
                    Cal[i].append(int(input(f"Id {idn}: Escribe la Califacion {j}: ")))
                    prom+=Cal[i][j]
                    break
                except:
                    print("Volver a escribir..")
                    input("Continue...")


print("\n\t<<--CALIFIACIONES-->\n")
for i in range(cantEstudiantes):
    b=""
    for j in range(5):
        if i>0 and j==4:
            b+="|  "+str(Cal[i][j])+"\t"
        else:
            b+=str(Cal[i][j])+"\t"
    if i==1:
        print("_________________________________________")
    elif i>1 :
        print("________________________________")    
        
    print(b)
print(f"\n\t**---ID Reprobados: {reprobados}---**")