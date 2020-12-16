print("ARROJAR NUMERO")
print("1-Saludar")
print("2-Sumar")
print("3-jugar lol")
print("0-Salir")
asies=10

numero=int(input("Elige una opcion: "))

while asies != 0 :
    if numero==1:
       print("Como estas?")
       print("ARROJAR NUMERO")
       print("1-Saludar")
       print("2-Sumar")
       print("3-jugar lol")
       print("0-Salir")
       numero=int(input("Elige otra opcion: "))
    elif numero==2:
        print("Sumaras dos numeros")
        numero1=int(input("Escribe el primer numero: "))
        numero2=int(input("Escribe el segundo numero: "))
        suma=numero1+numero2
        print(suma)
        print("ARROJAR NUMERO")
        print("1-Saludar")
        print("2-Sumar")
        print("3-jugar lol")
        print("0-Salir")
        numero=int(input("Elige otra opcion: "))
    elif numero==3:
        print("No juegues LOL")
        print("ARROJAR NUMERO")
        print("1-Saludar")
        print("2-Sumar")
        print("3-jugar lol")
        print("0-Salir")
        numero=int(input("Elige otra opcion: "))
    elif numero<1 or numero>3:
        
        numero=int(input("Elige otra opcion: "))
        asies=12
    if numero==0:
        asies=0
        
        
         
            
else:
    print("Fin del programa")
