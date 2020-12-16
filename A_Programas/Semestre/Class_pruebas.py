def Resultado (decimall,base_converter):
    resultado = ""
    siguiente = 0
    while decimall != 0:
        siguiente = decimall/base_converter
        residuo = decimall % base_converter
        if base_converter == 16:
            if residuo == 10:
                residuo ='A'
            elif residuo == 11:
                residuo ='B'
            elif residuo == 12:
                residuo ='C'
            elif residuo == 13:
                residuo ='D'
            elif residuo == 14:
                residuo ='E'
            elif residuo == 15:
                residuo ='F'
        
        decimall = int(siguiente)
        resultado += str(residuo)
    
    return resultado[::-1]

def Dec (introNum,base,base_converter):
    Indicador = True
    e = ""
    decimall=0
    case= introNum.split('.')
    exponente = 1
    conta = len(introNum[1])
    decimall = tablas(case[1],exponente,decimall,Indicador)
    for i in range(len(case[1])):
        
        resultado = decimall*base_converter
        a = resultado - int(resultado)
        l=int(resultado)
        if base_converter == 16:
            
            if l == 10:
                resultado ='A'
            
            elif l == 11:
                resultado ='B'
            
            elif l== 12:
                resultado ='C'

            elif l == 13:
                resultado ='D'
            elif l == 14:
                resultado ='E'
            elif l == 15:
                resultado ='F'
            else:
                resultado=int(resultado)
            
            e += str(resultado)
            decimall = a
        else:
            e += str(l)
            decimall = a
    return e

def tablas (inter,exponente,decimall,indicador):
    for i in inter:
        if i.upper() == 'A':
            i=10
        elif i.upper() == 'B':
            i=11         
        elif i.upper() == 'C':
            i=12     
        elif i.upper() == 'D':
            i=13         
        elif i.upper() == 'E':
            i=14         
        elif i.upper() == 'F':
            i=15
        if indicador == True:
            decimall = decimall + int(i)*base**(-exponente)
            exponente+=1
        else:
            decimall = decimall + int(i)*base**(exponente)
            exponente-=1  
    return decimall

def completado(indicador,decimall,converter):
    if indicador == 1:
        if converter == 2:
            print(f'                           Binario: {Resultado(decimall,base_converter)}')
        elif converter == 8:
            print(f'                           Octal : {Resultado(decimall,base_converter)}')
        elif converter == 10:
            print(f'                           Decimal : {decimall}')
        elif converter ==16:
            print(f'                           Hexadecimal : {Resultado(decimall,base_converter)}')
        else:
            print("Continuar")
    elif indicador == 2:
        if converter == 2:
            print(f'                           Binario: {Resultado(decimall,base_converter)}.{Dec(introNum,base,base_converter)}')
        elif converter == 8:
            print(f'                           Octal : {Resultado(decimall,base_converter)}.{Dec(introNum,base,base_converter)}')
        elif converter == 10:
            print(f'                           Decimal : {decimall}.{Dec(introNum,base,base_converter)}')
        elif converter ==16:
            print(f'                           Hexadecimal : {Resultado(decimall,base_converter)}.{Dec(introNum,base,base_converter)}')
        else:
            print("Continuar")
    else:
        print("Continuar")
    return
Near = True
while Near:
    
    print("                         **Menu**")
    print("Oprime cualquier boton para continuar la conversion")
    print("X- Salir")
    pase = input("Elige: ")
    if pase == 'X':
        Near == False
        break
    else:
        input("\n\n             Continuar..")
      
    while True:
        try:
            a = '''
            
                                                        Conversiones de sistema numericos
                                        **---------------------------------------------------------**
            '''
            print(a)
            Indicador = False
            enteroo= 1
            decimall=0
            resultado = ""
            while True:
                try:
                    base = int(input("              Escribe la base: "))
                    base_converter = int(input("              Escribe a convertir: "))
                    if base == base_converter:
                        print("Ya escribio esa base")
                    elif base != 2  and base !=8 and base !=10 and base !=16:
                        print("Solamente aceptamos")
                    elif base_converter != 2  and base_converter !=8 and base_converter !=10 and base_converter !=16:
                        print("solamente aceptamos")
                    else:
                        break
                except:
                    print("ErrorBaseInvalido\n      Vuelve a escribir")
            introNum = input("          Escribe numero: ")
            exponente=len(introNum)-1
            separador = introNum.split('.')

            if len(separador) == 2:
                exponente=len(separador[0])-1
                
                if base ==2 or base == 8 or base == 10 or base == 16:  
                    decimall = tablas(separador[0],exponente,decimall,Indicador) 
                        
                    print('\n                         Resultados..')
                    completado(len(separador),decimall,base_converter)
                    break
            elif len(separador) == 1:
                if base ==2 or base == 8 or base == 10 or base == 16:
                    decimall = tablas(introNum,exponente,decimall,Indicador)            
                    print('\n                         Resultados..')
                    completado(len(separador),decimall,base_converter)
                    break
                else:
                    print("error")
            else:
                
                print("\n\tVuelve a escribir\n")
                    
        except:
            print("\n\tVuelve a escribir\n")