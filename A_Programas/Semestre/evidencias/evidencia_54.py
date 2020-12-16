lista = list()
for x in range(5):
    valor = int(input("Ingresa valor: "))
    lista.append(valor)
mayor = lista[0]
for x in range(1,5):
    if lista[x] >mayor:
        mayor = lista[x]
print(f'lista: {lista} \n mayor: {mayor} ')