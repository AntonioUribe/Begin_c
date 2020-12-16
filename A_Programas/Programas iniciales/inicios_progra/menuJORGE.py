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
            if numero_intro==numero_aleatorio:
                    print("Bien Hecho")
            else:
                    print("Siguue participando")
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
                elif numero_ppt==3:
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
import random
def menu():
    eleccion=0
    while eleccion!=1 and eleccion!=2 and eleccion!=3 and eleccion!=4:
        print("")
        print("----------------------------------------------")
        print("****MENÚ PRINCIPAL****")
        print("1 - Aritmetica")
        print("2 - Texto")
        print("3 - Juegos")
        print("4 - Salir")
        eleccion=int(input("Elige una opción: "))
        if eleccion==1:
            eleccion_aritmetica=0
            print("")
            print("----------------------------------------------")
            print("****MENÚ DE ARITMETICA****")
            print("1 - Suma de dos números")
            print("2 - Resta de dos números")
            print("3 - Regresar al menú principal")
            while eleccion_aritmetica!=1 and eleccion_aritmetica!=2 and eleccion_aritmetica!=3:
                eleccion_aritmetica=int(input("Elige una opción: "))
                if eleccion_aritmetica==1:
                    print("")
                    print("----------------------------------------------")
                    print("Escogiste la Suma.")
                    print("Dame dos números")
                    numero_usuario1 = int(input("Primer número: "))
                    numero_usuario2 = int(input("Segundo número: "))
                    suma=numero_usuario1+numero_usuario2
                    print("El resultado de la suma es: ", suma)
                    print("")
                    eleccion_enter = input("Presiona <ENTER> para volver.")
                    menu()
                    print("")
                    print("")
                elif eleccion_aritmetica==2:
                    print("")
                    print("----------------------------------------------")
                    print("Escogiste la Resta.")
                    print("Dame dos números")
                    numero_usuario1 = int(input("Primer número: "))
                    numero_usuario2 = int(input("Segundo número: "))
                    resta=numero_usuario1-numero_usuario2
                    print("El resultado de la resta es: ", resta)
                    print("")
                    eleccion_enter = input("presiona <ENTER> para volver.")
                    menu()
                    print("")
                    print("")
                elif eleccion_aritmetica==3:
                    print("")
                    menu()
        elif eleccion==2:
            eleccion_texto=0
            print("")
            print("----------------------------------------------")
            print("****MENÚ DE TEXTO****")
            print("1 - Invertir un nombre")
            print("2 - Contar las letras *e* dentro un texto")
            print("3 - Regresar al menú principal")
            while eleccion_texto!=1 and eleccion_texto!=2 and eleccion_texto!=3:
                eleccion_texto=int(input("Elige una opción: "))
                if eleccion_texto==1:
                    print("")
                    print("----------------------------------------------")
                    print("Escogiste Invertir un texto.")
                    texto_usuario = input("Dame un mensaje: ")
                    texto_usuario.split()
                    invertido=''.join(reversed(texto_usuario))
                    print(invertido)
                    print("")
                    eleccion_enter = input("Presiona <ENTER> para volver.")
                    menu()
                    print("")
                    print("")
                elif eleccion_texto==2:
                    print("")
                    print("----------------------------------------------")
                    print("Escogiste Contar las letras *e* dentro de un texto.")
                    texto_usuario = input("Dame un mensaje: ")
                    ocurrencia = texto_usuario.count("E") + texto_usuario.count("e")
                    print("Letras *e* dentro del texto: ", ocurrencia)
                    print("")
                    eleccion_enter = input("Presiona <ENTER> para volver.")
                    menu()
                    print("")
                    print("")
                elif eleccion_texto==3:
                    print("")
                    menu()
        elif eleccion==3:
            Juegos(eleccion)
            '''eleccion_juegos=0
            print("")
            print("----------------------------------------------")
            print("****MENÚ DE JUEGOS****")
            print("1 - Adivinar el número")
            print("2 - Piedra, papel o tijera")
            print("3 - Regresar el menu principal")
            eleccion_juegos=int(input("Elige una opción: "))
            while eleccion_juegos!=1 and eleccion_juegos!=2 and eleccion_juegos!=3:
                if eleccion_juegos==1:
                    print("")
                    print("----------------------------------------------")
                    print("Escogiste Adivinar el número.")
                    print("Tienes *5* intentos para adivinar el número.")
                    import random
                    intentos=0
                    x = random.randint (1, 20)
                    numero_usuario=0
                    while True:
                        intentos=5
                        intentos = intentos - 1
                        numero_usuario=int(input("Elige un numero del 1 al 20: "))
                        if numero_usuario<21:
                            print("")
                            if numero_usuario > (x):
                                print ("INCORRECTO, te quedan", intentos, "intentos.")
                            if numero_usuario < (x):
                                print ("INCORRECTO, te quedan", intentos, "intentos.")
                            if numero_usuario == (x):
                                print("")
                                print("Felicidades!, Acertaste el número Azar!")
                                break
                elif eleccion_juegos==2:
                    print("")
                    print("----------------------------------------------")
                    print("Escogiste Piedra, papel o tijera")
                elif eleccion_juegos==3:
                    print("")
                    menu()'''
        elif eleccion==4:
            print("")
            print("--------------------")
            print("**Saliste del Menu**")
            print("--------------------")
            break
        else:
            print("")
            print("")
            print("********************************************************")
            print("INGRESASTE UN VALOR FUERA DE RANGO, INTENTALO DE NUEVO.")
            print("********************************************************")
menu()
