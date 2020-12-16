import os
print("Calculadora\n")
switch=bool
Near=bool
switch=True

contador_letra=0
posicion=0
while switch==True:

    
    print("Menu\n")
    print("1-Sumar\n")
    print("2-restar\n")
    print("3-TEXTO\n")
    print("X-Salir")
    opcion=input("    Escribe la opcion que deseas: \n")
    
    if opcion=="X":
        switch=False
        print("Hasta la prxima")
        
    elif opcion != "1" and opcion!="2" and opcion!="3" and opcion!="X":
        print("Vuelve a escribir: \n")
        
    elif opcion=="1":
        print("Suma\n")
        Near=True
        
        while Near==True:
            print("1-Suma de 2 digitos\n")
            print("2-Suma de 3 digitos\n")
            print("X-SAlir\n")
            opcion=input("    Escribe la opcion que deseas: \n")
            if opcion=="X":
                Near=False
            elif opcion != "1" and opcion!="2" and opcion!="3" and opcion!="X":
                print("Vuelve a escribir\n")
            elif opcion=="1":
                print("Suma de 2 digitos")
                digito_uno=int(input("Escribe el primer numero:\n"))
                digito_dos=int(input("Escribe el segundo numero:\n"))
                print("Tu resultado es: ",digito_uno+digito_dos)
            elif opcion=="2":
                print("Suma de 3 digitos")
                digito_uno=int(input("Escribe el primer numero:\n"))
                digito_dos=int(input("Escribe el segundo numero:\n")) 
                digito_tres=int(input("Escribe el tres numero:\n"))
                print("Tu resultado es: ",digito_uno+digito_dos+digito_tres)

                
    elif opcion=="2":
        print("Restar\n")
        Near=True
        
        while Near==True:
            print("1-Resta de 2 digitos\n")
            print("2-Resta de 3 digitos\n")
            print("X-Salir\n")
            opcion=input("    Escribe la opcion que deseas: \n")
            if opcion=="X":
                Near=False
            elif opcion != "1" and opcion!="2" and opcion!="3" and opcion!="X":
                print("Vuelve a escribir\n")
            if opcion=="1":
                print("Resta de 2 digitos")
                digito_uno=int(input("Escribe el primer numero:\n"))
                digito_dos=int(input("Escribe el segundo numero:\n"))
                print("Tu resultado es: ",digito_uno-digito_dos)
            elif opcion=="2":
                print("Resta de 3 digitos")
                digito_uno=int(input("Escribe el primer numero:\n"))
                digito_dos=int(input("Escribe el segundo numero:\n")) 
                digito_tres=int(input("Escribe el tres numero:\n"))
                print("Tu resultado es: ",digito_uno-digito_dos-digito_tres)

    elif opcion=="3":
        print("TEXTO\n")
        Near=True
    while Near==True:
        print( "---Menu texto---")
        print( "1-Invertir Mensaje")
        print(  "2-Contar las e o E del mensaje")
        print( "X.-Salir a Menu principal")
        print(  "Elige la opcion")
        opcion=input("Escribir: ")
        if opcion=="X":
            print( "Salir...")
            Near=False
        elif  opcion!="1" and opcion!="2" and opcion!="X":
            opcion=input("Vuelve a escribir: ")
        elif  opcion=="1":
            
             print("-.Invertir una frase.-")
             posicion=0
             frase=input("Escribe un mensaje: ")
             print("mensaje invertido es: ",frase[:-1])
        elif opcion=="2":
            print("-.Registar las letras e/E en un mensaje.-")
            contador_letra=0
            posicion=0
            frase=input("Escribe un mensaje: ")
            while posicion<len(frase):
                letra=frase[posicion]
                if letra.lower()=="e":
                    contador_letra=contador_letra+1
                print(letra)
                posicion=posicion+1
            print("La cantidad de letras e o E fueron:",contador_letra)
   
    
