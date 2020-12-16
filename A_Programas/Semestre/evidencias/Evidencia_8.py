print("-$20/Hora-")
horas=float(input("Número de Horas laboradas: "))
if horas<=50:
    salario=horas*30000
else:
    salario=(horas-50)*40000 + 50*30000
print("El salario es: ", salario)
