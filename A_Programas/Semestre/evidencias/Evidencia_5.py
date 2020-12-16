'''
dia = ['lunes','martes']
ingreso_dia = list()
dinero = 0
total_dia = 0

for i in range(2):
    total_dia = 0
    for j in range(3):
        dinero = int(input(f'Escribe el sueldo {j} en {dia[i]}'))
        total_dia += dinero
    ingreso_dia.append(total_dia)

saber = int(input("Verifica que dia se vendio \n0-lunes\n1-martes\nEscribe: "))
if saber == 0:
    print(f'Dia {dia[saber]} vendio {ingreso_dia[saber]}')
elif saber ==1:
    print(f'Dia {dia[saber]} vendio {ingreso_dia[saber]}')
else:
    print("Dia equivocado")

'''   


'''

'''  