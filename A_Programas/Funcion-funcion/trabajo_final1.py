def Sumar(opcionl):
    print("Suma\n")
    Near=True
    while Near==True:
        print("1-Suma de 2 digitos\n")
        print("2-Suma de 3 digitos\n")
        print("X-SAlir\n")
        opcionl=input("    Escribe la opcion que deseas: \n")
        if opcionl=="X":
            Near=False
        elif opcionl != "1" and opcionl !="2" and opcionl !="3" and opcionl!="X":
            print("Vuelve a escribir\n")
        elif opcionl=="1":
            print("Suma de 2 digitos")
            while(True):
                try:
                    digito_uno=int(input("Escribe el primer numero:\n"))
                    digito_dos=int(input("Escribe el segundo numero:\n"))
                    print("Tu resultado es: ",digito_uno+digito_dos)
                    break
                except:
                    print("Escribe otra vez")
        
        elif opcionl=="2":
            print("Suma de 3 digitos")
            while(True):
                try:
                    digito_uno=int(input("Escribe el primer numero:\n"))
                    digito_dos=int(input("Escribe el segundo numero:\n")) 
                    digito_tres=int(input("Escribe el tres numero:\n"))
                    print("Tu resultado es: ",digito_uno+digito_dos+digito_tres)
                    break
                except:
                    print("Escribe otra vez")

                    
    return opcionl
        
def Restar(opcionl):
    print("Restar\n")
    Near=True
    while Near==True:
        print("1-Resta de 2 digitos\n")
        print("2-Resta de 3 digitos\n")
        print("X-Salir\n")
        opcionl=input("    Escribe la opcion que deseas: \n")
        if opcionl=="X":
            Near=False
        elif opcionl != "1" and opcionl!="2" and opcionl!="3" and opcionl!="X":
            print("Vuelve a escribir\n")
        if opcionl=="1":
            print("Resta de 2 digitos")
            while(True):
                try:
                    digito_uno=int(input("Escribe el primer numero:\n"))
                    digito_dos=int(input("Escribe el segundo numero:\n"))
                    print("Tu resultado es: ",digito_uno-digito_dos)
                    break
                except:
                    print("Escribe otra vez")
        elif opcionl=="2":
            print("Resta de 3 digitos")
            while(True):
                try:
                    digito_uno=int(input("Escribe el primer numero:\n"))
                    digito_dos=int(input("Escribe el segundo numero:\n")) 
                    digito_tres=int(input("Escribe el tres numero:\n"))
                    print("Tu resultado es: ",digito_uno-digito_dos-digito_tres)
                    break
                except:
                    print("Escribe otra vez")
            
    return opcionl

def Texto(opciona):
    print("TEXTO\n")
    Near=True
    while Near==True:
        print( "---Menu texto---")
        print( "1-Invertir Mensaje")
        print( "2-Contar las e o E del mensaje")
        print( "X.-Salir a Menu principal")
        print(  "Elige la opcion")
        opciona=input("Escribir: ")
        if opciona=="X":
            print( "Salir...")
            Near=False
        elif  opciona!="1" and opciona!="2" and opciona!="X":
            opciona=input("Vuelve a escribir: ")
        elif  opciona=="1":
            
             print("-.Invertir una frase.-")
             posicion=0
             while(True):
                 try:
                     
                     frase=input("Escribe un mensaje: ")
                     print("mensaje invertido es: ",frase[::-1])
                     break
                 except:
                    print("Escribe otra ez")
        elif opciona=="2":
            print("-.Registar las letras e/E en un mensaje.-")
            contador_letra=0
            posicion=0        
            frase=input("Escribe un mensaje: ")
            while posicion<len(frase):
                letra=frase[posicion]
                if letra.lower()=="e":
                    contador_letra=contador_letra+1
                posicion=posicion+1
            print("Las letras e\E fueron: ",contador_letra)
    return opciona

def Fibonacci():
    i=0
    a=[0,1]
    print("Codigo fibonacci")
    while True:
        try:
            t=int(input("Hasta que numero quieres ver la serie fibonacci: "))
            break
        except:
            print("Escribe Otra vez:\n")
    for i in range(t):
        e=a[i]+a[i+1]
        a.append(e)
    
    for i in range(t):
        
        print("position: {} and number {}".format(i+1,a[i]))
        
    print("Busca la posicion de codigo fibonacci\n")
    while True:
        try:
            o=int(input("Busca la posicion del numero: "))
            if o==1:
                print("La posicion esta en 2 y 3")
            else:
                print("Esta en la posicon:",a.index(o)+1)
            break
        except:
            print("Escribe otra vez:\n")

def Juegos(opcionl):
    numero_aleatorio=0
    print("3- JUEGOS\n")
    Near=True
    while Near==True:
        print("MENU DE JUEGOS\n")
        print("1-Adivina el numero\n")
        print("2-Piedra, papel o tijera\n")
        print("X-Salir")
        opcionl=input("Escribe una opcion: ")
        if opcionl == "X":
            Near=False
        elif opcionl != "1" and opcionl != "2" and opcionl != "x":
            print("Vuelve a escribir\n")
        elif opcionl=="1":
            print("1-Adivina el numero\n")
            numero_aleatorio=random.randint(1,20)
            print(numero_aleatorio)
            posicion=0
            while posicion < 5:
                numero_intro=int(input("Escribe el numero"))
                if numero_aleatorio==numero_intro:
                    print("Felicidades le atinaste en la oportunidad ",posicion+1)
                    posicion=5
                elif numero_intro>0 and numero_intro<21:
                    print("llevas ",posicion+1,"oportunidad(es)")
                else:
                    print("Vuelve a escribir en tu oportunidad ",posicion+1)
                    posicion=posicion-1
                posicion=posicion+1
            else:
                print("Fin del juego")
                
        elif opcionl=="2":
            numero_ppt=0
            print("Bienvenidos al juego de PIEDRA,PAPEL O TIJERA")
            print("<Las reglas del juego: es escoger un numero que representa piedra,papel o tijera.>")
            print("	Elige el numero que quieres representar en el juego:")
            print("	1-PIEDRA")
            print("	2-PAPEL")
            print("	3-TIJERA")
            opcionl=input("Elige: ")
            juego=("Piedra,","Papel","Tijera")
            numero_ppt=random.randint(1,3)
            print(numero_ppt)
            while opcionl!="1" and opcionl!="2" and opcionl!="3":
                opcionl=input("Vuelve a escribir ")
            if opcionl=="1":
                if numero_ppt==1:
                    print(juego[0],"---",juego[0])
                    print("EMPATE")
                elif numero_ppt==2:
                    print(juego[0],"---",juego[1])
                    print("PERDISTE")
                elif numweo_ppt==3:
                    print(juego[0],"---",juego[2])
                    print("GANASTE")
            if opcionl=="2":
                if numero_ppt==1:
                    print(juego[1],"---",juego[0])
                    print("GANASTE")
                elif numero_ppt==2:
                    print(juego[1],"---",juego[1])
                    print("EMPATE")
                    
                elif numero_ppt==3:
                    print(juego[1],"---",juego[2])
                    print("PERDISTE")
            if opcionl=="3":
                if numero_ppt==1:
                    print(juego[2],"---",juego[0])
                    print("PERDISTE")
                elif numero_ppt==2:
                    print(juego[2],"---",juego[1])
                    print("GANASTE")
                elif numero_ppt==3:
                    print(juego[2],"---",juego[2])
                    print("EMPATE")
            print("\n      Game over\n")
            input("<<ENTER PARA CONTINUAR...>>")

    return opcionl
                
                
                
            
                
                    
                        
                        
                    
                    
               
        
    import os
    import random
def todo(): 
    switch=bool
    Near=bool
    switch=True

    contador_letra=0
    posicion=0
    while switch==True:

        
        print("\n    ***Menu****\n")
        print("1-SUMAR\n")
        print("2-RESTAR\n")
        print("3-TEXTO\n")
        print("4-JUEGOS\n")
        print("5-CODIGO FIBONACCI\n")
        print("X-Salir")
        opcion=input("    Escribe la opcion que deseas: \n")
        
        if opcion=="X":
            switch=False
            print("Hasta la proxima")
            
        elif opcion != "1" and opcion!="2" and opcion!="3" and opcion!="4" and opcion != "5" and opcion!="X":
            print("Vuelve a escribir: \n")
            
        elif opcion=="1":
            Sumar(opcion)
            
                    
        elif opcion=="2":
            Restar(opcion)
            

        elif opcion=="3":
            Texto(opcion)

        elif opcion=="4":
            Juegos(opcion)

            
        elif opcion=="5":
            Fibonacci()


    

