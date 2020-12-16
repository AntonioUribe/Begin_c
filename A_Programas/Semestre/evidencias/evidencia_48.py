lista=[]
valor = int(input("ingresa un valor (presiona 0 para finalizar: "))
while valor != 0:
    lista.append(valor)
    valor = int(input("Ingresa valor(presiona 0 par finalizar) :"))
    
print("tamaño de la lista")
print(len(lista))