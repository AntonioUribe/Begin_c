def calendario():
    print("Ingresa una fecha en números:")
    dia=int(input("Día: "))
    if dia<=31:
        mes=int(input("Mes: "))
        if mes<=12:
            print("----------------------")
            if mes==1:
                print(dia, "de Enero")
                if dia==1:
                    print("Año Nuevo")
                else:
                   print("Día común")
            elif mes==9:
                print(dia, "de Septiembre")
                if dia==16:
                    print("Día de la Independencia")
            elif mes==10:
                print(dia, "de Octubre")
                if dia==18:
                    print("Feliz Cumpleaños")
                elif dia==31:
                    print("HALLOWEEN")
            else:
                print(dia, "de Diciembre")
                if dia==25:
                    print("NAVIDAD")
                else:
                    print("Día común")
            print("----------------------")
        else:
            print("")
            print("-------------------------")
            print("Número de mes INCORRECTO")
            print("Vuelve a intentarlo")
            print("-------------------------")
            calendario()
    else:
        print("")
        print("-------------------------")
        print("Número de día INCORRECTO")
        print("Vuelve a intentarlo")
        print("-------------------------")
        calendario()
calendario()