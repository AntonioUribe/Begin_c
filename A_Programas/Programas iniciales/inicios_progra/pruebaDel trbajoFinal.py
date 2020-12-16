import os
print("Calculadora\n")
switch=bool
Near=bool
switch=True

while switch==True:

    
    print("Menu\n")
    print("1-Sumar\n")
    print("2-restar\n")
    print("3-Multiplicar\n")
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
        print("Multiplicar\n")
        Near=True
        while Near==True:
            print("1-Multiplicacion de 2 digitos\n")
            print("2-Multiplcacion de 3 digitos\n")
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
                print("Tu resultado es: ",digito_uno*digito_dos)
            elif opcion=="2":
                print("Resta de 3 digitos")
                digito_uno=int(input("Escribe el primer numero:\n"))
                digito_dos=int(input("Escribe el segundo numero:\n")) 
                digito_tres=int(input("Escribe el tres numero:\n"))
                print("Tu resultado es: ",digito_uno*digito_dos*digito_tres)
                
   


     
