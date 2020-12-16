lista = [[1,2,3],[4,5,6],[8,7,9],[10,11,12]]

#lista completa
print(lista)
print("_____________")

#imprimir el primer componente
print(lista[0])
print("______________")

#imprimir el primer componentes de la lista
print(lista[0][0])

#imprimir la lista de mi primer semestre componentes
for x in range(len(lista[0])):
    print(lista[0][x])
print("______________")
#imprimir todos los componentes de la lista
for k in range(len(lista)):
    for x in range(len(lista[k])):
        print(lista[k][x])