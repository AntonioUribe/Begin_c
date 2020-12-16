"""Confeccionar un prgrama que pida por teclado tres notas de un alumno,
calcule el promedio e imprima alguno de estos mensajes:
Si el promedio es >=7 mostrar "Aprobado"
Si el primedio es >=4 y <7 mostrar "Regular"
Si el promedio es <4 mostrar "Reprobado"."""

#Lectura de datos
Calif1=int(input("Ingrese la primera calificacion: "))
Calif2=int(input("Ingrese la segunda calificacion: "))
Calif3=int(input("Ingrese la tercera calificacion: "))

#Operaciones
prom=(Calif1+Calif2+Calif3)/3

#Mostrar Resultado
print("El alumno esta: ")

#Condicionales
if prom>=7:
    print("Aprobado")
else:
    if prom>=4:
        print("Regular")
    else:
        if prom<4:
            print("REPROBADO")
      
