''''print("FACEBOOK")



print("1-Registrarse\n")

correo="antonio01@gmail.com"
if correo.index("@") != 1:
    print("Correcto")
    
    print(correo.split("@"))
    print(correo.split("@")[1].split("."))


    

i=0
near=bool
near=True
while near==True:
    correo=input("Escribe el correo")
    while i < len(correo):
        if (ord(correo[i])==46 or ord(correo[i])>45 and ord(correo[i])<58)  or  ord(correo[i])==64 or ord(correo[i])>64 and ord(correo[i])<90 or ord(correo[i])==95 or ord(correo[i])>96 and ord(correo[i])<122 :
            
            if correo[i]=="@":
                nuevo=correo.split("@")
                print(nuevo[1])
                
            
            
        else: 
            print("Vuelve a escribir")
            correo=input("Escribe el correo")
        i=i+1
            
    near=False
            
        
print("Completado",correo)'''


print("FACEBOOK")

print("1-Registrarse\n")

correo="antonio01 gmail.com"
#correo=input("Escribe tu correo:  ")

while switch:
    print("Vuelve a escribir")
    correo=input("Escribe tu correo:  ")

print("Evaluacion")
while i<len(correo)
    if correo[i]=="@":
        print("perfecto")
    else:
        
    


