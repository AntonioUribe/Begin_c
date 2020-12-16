print("Recibo de nomina")
lista=list()

while True:
    print("°°|MENU|°°") 
    print("1-Registro") 
    print("2-Imprimir") 
    print("3-Eliminar registro")
    print("X-Salir")
    
    opcion= input("Elige la opcion:" )
    if opcion=="X":
        print("Salir")
        break
              
    elif opcion != "1" and opcion !="2" and opcion !="3" and opcion !="4" and opcion !="x":
        print("Vuelve a escribir")
        
    elif opcion == "1":
        
        for i in range(2):
            lista.append(input(f"Escribe nombre {i+1}: "))
            
    elif opcion =="2":
        for i in range(2):
            print(lista[i])
        
        
            
        
    