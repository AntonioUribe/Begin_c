lista = list()
suma = 0
for i in range(5):
    sueldo = float(input("Escribe:"))
    suma  = suma+ sueldo
    lista.append(sueldo)
    
print(f'lista son {lista} y promedio {suma/5}')