lista = list()
suma = 0
mayor = 0
menor = 0
for i in range(5):
    altura = float(input("Escribe altura:"))
    suma  = suma+ altura
    lista.append(altura)
promedio = suma/5
for i in lista:
    if i > promedio:
        mayor +=1
    else:
        menor+=1
    
    
print(f'lista son {lista} y promedio {suma/5} \n mayor{mayor} \n menor {menor}')