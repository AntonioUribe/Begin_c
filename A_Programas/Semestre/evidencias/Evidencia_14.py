def calif():
    print("Ingresa las calificaciones obtenidas con números del 1 al 100")
    numuno = float(input("Primera Materia: "))
    if numuno <= 100 and numuno >= 0:
        numdos = float(input("Segundo Materia: "))
        if numdos <= 100 and numdos >= 0:
            numtres = float(input("Tercera Materia: "))
            if numtres <= 100 and numtres >= 0:
                suma = numuno + numdos + numtres
                promedio = suma/3
                print("Tu promedio final es: ", promedio)
                if promedio>70:
                    print("***Felicidades, aprovaste!***")
                else:
                    print("Reprobaste.")
            else:
                print("")
                print("-------------------------------------------------------------")
                print("Intentalo otra vez.")
                calif()
        else:
            print("")
            print("-------------------------------------------------------------")
            print("Intentalo otra vez.")
            calif()
    else:
        print("")
        print("-------------------------------------------------------------")
        print("Intentalo otra vez.")
        calif()
calif()