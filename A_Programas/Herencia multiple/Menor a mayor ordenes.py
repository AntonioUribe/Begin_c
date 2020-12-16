def menorAmayor(unaLista):
        for i in range(len(unaLista)):
                for j in range(len(unaLista)-1):
                    if unaLista[j]>unaLista[j+1]:
                        temp = unaLista[j]
                        unaLista[j] = unaLista[j+1]
                        unaLista[j+1] = temp

unaLista = [2,7,1,1]
menorAmayor(unaLista)
print(unaLista)






            


