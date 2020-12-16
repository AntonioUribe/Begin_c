#                evidencia03_cuadrado
'''
print("     Cuadrado")
lado= int(input("Escribe el lado del cuadrado: "))
print(f'Perimetro: {lado*4} \nArea: {lado*lado}')
'''
#               evidencia04_SM
'''
print("\n\t\tSuma y Multiplicacion\n")
valor1 = int(input("Escribe el primer valor"))
valor2 = int(input("Escribe el segundo valor"))
print(f'Suma {valor1+valor2}\nMultiplicacion {valor1*valor2} ')
'''
#               evidencia05_producto
'''
print("     Precios")
producto = int(input("Escribe la cantidad de producto"))
precio = int(input("Escribe el precio del producto"))
print(f'Importe a pagar es: {prodcuto*precio}')
'''
#               evidencia06_REST_DIV
'''
print("\n\t\tCalculaodra\n")
valor1 = int(input("Escribe el primer valor"))
valor2 = int(input("Escribe el segundo valor"))
valor3 = int(input("Escribe el tercer valor dividendo"))
valor4 = int(input("Escribe el cuarto valor divisor"))
print(f'Resta {valor1-valor2}\nDivision {valor3*valor4} ')
'''
#               evidencia07_promedio
'''
print("Valores numericos")
sumal=[]
c=0
for i in range(4):
    sumal.append(int(input("Escribe valor")))
    c+=sumal[i]
print(f'Suma {c} | Promedio: {c/4}')
'''

#               evidencia08_sueldo
'''
print("Sueldo")
horas = int(input("Escribe la hora: "))
cantidad = float(input('Escribe el precio'))
print(f'Sueldo por la cantidad de horas trabajadas {horas*cantidad}')
'''
#               evidenica09_impuesto
'''
sueldo = int(input("Escribe sueldo"))
if sueldo>3000:
    print("Pagas impuesto")
'''
#               evidenica10_mayor
'''
valor1 = int(input("Escribe el primer valor: "))
valor2 = int(input("Escribe el segundo valor: "))

if valor1>valor2:
    print(valor1)
else:
    print(valor2)
'''
#               evidenica11_calculadora
'''
valor1 = int(input("Escribe el primer valor: "))
valor2 = int(input("Escribe el segundo valor: "))

if valor1>valor2:
    suma = valor1+valor2
    restar= valor1-valor2
    print(f'sumaa: {suma}')
    print(f'restaa: {restar}')
else:
    multiplicar = valor1*valor2
    div= valor1/valor2
    print(f'multiplicar: {multiplicar}')
    print(f'divicion: {div}')
'''
#       evidencia 12_calificaciones4
'''

cal1 = int(input("Escribe la califiacion "))
cal2 = int(input("Escribe la califiacion "))
cal3 = int(input("Escribe la califiacion "))

prom = (cal1+cal2+cal3)/3

if prom <40:
    print("reprobo")
elif prom >=40 and prom < 70:
    print('regular')
else:
    print("Aprobado")
'''

#       evidencia13_calificacionesmayores
'''
cal1 = int(input("Escribe la califiacion "))
cal2 = int(input("Escribe la califiacion "))
cal3 = int(input("Escribe la califiacion "))
if cal1>cal2:
    if cal1>cal3:
        print(cal1)
elif cal2>cal3:
    if cal2>cal1:
        print(cal2)
else:
    print(cal3)
 '''
#evidencia_14
'''
14.-Se ingresan tres notas de un alumno, si el promedio es mayor o igual a siete mostrar un mensaje "Promocionado".

prom = 0
for i in range(3):
    c = float(input("Escribe la nota"))
    prom+=c
if (prom/3) > 7:
    print ("Promocionado")
'''
#evidencia_15 
''' 
15.-Se ingresa por teclado un número positivo de uno o dos dígitos (1..99) mostrar un mensaje indicando si el 

 número tiene uno o dos dígitos. (Tener en cuenta que condición debe cumplirse para tener dos dígitos un número entero)

c=int(input("Escribe un numero: "))
if len(c)==1:
    print("un digito")
elif len(c)==2:
    print("dos digitos")
else:
    print("Mas digitos")
'''
#evidenica_16
'''
16.-Se ingresa por teclado un valor entero, mostrar una leyenda que indique si el número es positivo, negativo o nulo (es decir cero)

c=int(input("Escribe un numero: "))
if c>0:
    print("positivo")
elif c<0:
    print("negativo")
else:
    print("Nulo")
'''
#evidencia_17

'''
17.-Confeccionar un programa que permita cargar un número entero positivo de hasta tres cifras y muestre un mensaje 

 indicando si tiene 1, 2, o 3 cifras. Mostrar un mensaje de error si el número de cifras es mayor.

c=int(input("Escribe un numero: "))
if len(c)==1:
    print("una cifra")
elif len(c)==2:
    print("dos cifras")
elif len(c)==3:
    print("tres digitos")
else:
    print("Error")
'''
#evidencia_18
'''
18.-Un postulante a un empleo, realiza un test de capacitación, se obtuvo la siguiente información: cantidad total

 de preguntas que se le realizaron y la cantidad de preguntas que contestó correctamente. Se pide confeccionar 

 un programa que ingrese los dos datos por teclado e informe el nivel del mismo según el porcentaje de respuestas 

 correctas que ha obtenido, y sabiendo que:

     Nivel máximo:    Porcentaje>=90%.

     Nivel medio:    Porcentaje>=75% y <90%.

     Nivel regular:    Porcentaje>=50% y <75%.

     Fuera de nivel:    Porcentaje<50%.
'''
#evidenica_19
'''
preguntasTotal=int(input("pregntas totales: "))
preguntas = int(input("Escribe las preguntas contestadas: "))

if (preguntas/preguntasTotal)*100 >=90:
    print("Nivel maximo")
elif (preguntas/preguntasTotal)*100 >=75 and (preguntas/preguntasTotal)*100 < 90:
    print("Nivel medio")
elif (preguntas/preguntasTotal)*100 >=50 and (preguntas/preguntasTotal)*100 < 75:
    print("Nivel regular")
else:
    print("fuera del nivel")

n1=int(input("Escribe un numero: "))
n2=int(input("Escribe un numero: "))
n3=int(input("Escribe un numero: "))
if n1>n2 and n1>n3:
    print(n1)
elif n2>n1 and n2>n3 :
    print(n2)
else:
    print(n3)
'''
#evidencia_20
'''
dia = int(input("Escribe el dia"))
mes = int(input("escribe el mes"))
ano = int(input("escribe el año"))
if mes >0 and mes <4:
    print("primer trimestre")
elif mes >3 and mes <7:
    print("segundo trimestre")
elif mes >6 and mes <10:
    print("segundo trimestre")
else:
    print("cuarto trimestre")
'''
#evidencia_21
'''
print("Cargar una fecha\nEjemplo\n Dia-02\nMes-11\nAño-2020")
dia=int(input("Escribe el dia"))
mes = int(input("escribe el mes"))
ano = int(input("escribe el año"))

if dia ==25 and mes == 12:
    print("Feliz navidad")
else:
    print("Dia normal")
'''
#evidencia_22
'''
num1=int(input("escribe numero: "))
num2=int(input("escribe numero: "))
num3=int(input("escribe numero: "))
if num1 <10 and num2<10 and num3<10:
    print("Son numeros menores a 10")
else:
    print("Numeros normales")
'''
#evidencia_23
'''
num1=int(input("escribe numero: "))
num2=int(input("escribe numero: "))
num3=int(input("escribe numero: "))
if num1 <10 or num2<10 or num3<10:
    print("algunos de esos numeros son menores a 10")
else:
    print("Numeros normales")
'''
#evidencia_24
'''
num1=int(input("escribe numero: "))
num2=int(input("escribe numero: "))
num3=int(input("escribe numero: "))
multiplicacion=0
if num1==num2 and num2==num3 and num1==num3:
    multiplicacion = (num1+num2)*num3
    print(f"multiplicacion: {multiplicacion}")
else:
    print("Numeros normales")
'''
#evidencia_24
'''
sueldo=float(input("escribe sueldo: "))
ano=int(input("escribe años de antiguedad: "))

if sueldo<500 and ano>=10:
    sueldo = sueldo*1.20
elif sueldo <500 and ano <10:
    sueldo= sueldo*1.05
else:
    aumento =sueldo
print(f"Sueldo: {sueldo}")
'''
#evidencia_26
'''
x=1
while x<=100:
    print(x)
    x+=1
'''
#evidenica_27
'''
n=int(input("escribe el numero"))
x=1
while x<=n:
    print(x)
    x+=1
'''
#evidencia_28
'''
i=0
prom=0
while i<10:
    num=int(input("escribe numero: "))
    prom+=num
print(f'Promedio {prom/10}')

'''
#evidenica 29
'''
cantidad = 0
x=1
n=int(input("numero de peias a anaizar"))
while x<
'''

#evidenica30
'''
30.-Escribir un programa que solicite ingresar 10 notas de alumnos y nos informe cuántos tienen notas mayores o iguales a 7 y cuántos menores.
'''
'''
x=0
mayor = 0
menor = 0

while x<10:
    nota=int(input("Escribe la nota del alumno: "))
    
    if nota>=7:
        mayor +=1
    else:
        menor +=1
    x+=1
print(f"Notas mayores igual a 7 es: {mayor}")
print(f"Notas menores a 7 es {menor}")
'''
#evidencia_31
'''
 31.-Se ingresan un conjunto de n alturas de personas por teclado. Mostrar la altura promedio de las personas.
'''
'''
x=0
contador = 0
num_Personas = int(input("Escribe el numero de personas: "))
while x<num_Personas:
    altura = float(input("Escribe las aturas"))
    contador += altura
    x+=1
print(f"Promedio de alturas : {contador/num_Personas}")
'''
#Evidencia_32
'''

 32.-En una empresa trabajan n empleados cuyos sueldos oscilan entre $100 y $500, realizar un programa que lea los sueldos que cobra cada empleado e informe cuántos empleados cobran entre $100 y $300 y cuántos cobran más de $300. 
 Además el programa deberá informar el importe que gasta la empresa en sueldos al personal.
'''
 
'''
x= 0
num_empleado = int(input("Escribe numero de empleados: "))
c1=0
c2=0
contador = 0
while x<num_empleado:
    sueldo = float(input("Ingresa el sueldo"))
    if sueldo >=100 and sueldo <=300:
        c1+=1
        contador+=sueldo
    elif sueldo >300:
        c2+=1
        contador+=sueldo
        
    else:
        print("Es menor")
        contador+=sueldo
    x+=1
    
print("Empleados ganan mas entre 100 y 300 pesos", c1)
print("Empleados ganan mas de 300 pesos", c2)
print("Importe total",contador)
'''
#Evidencia_33
'''

 33.-Realizar un programa que imprima 25 términos de la serie 11 - 22 - 33 - 44, etc. (No se ingresan valores por teclado)
'''
'''
x=1
while x<=25:
    
    print(f'Termino {x}-{x*11}')  
    x+=1 
'''
#evidencia_34
'''
 34.-Mostrar los múltiplos de 8 hasta el valor 500. Debe aparecer en pantalla 8 - 16 - 24, etc
'''
'''
x=0
while x<=500:
    
    print(f'Termino {x}')
    x+=8
''' 
#evidencia_35
'''
for x in range(20,120):
    print(x)
'''
#evidencia_36
'''
valor = 0
suma = 0
for x in range(10):
    valor = int(input("Escribe el valor"))
    suma+=valor
print(f'Suma es {suma} promedio { suma/3}')
'''
#evidencia_37
'''
aprobado = 0
reprobado = 0

for x in range(10):
    valor = int(input("Escribe las notas:"))
    if valor >=70:
        aprobado+=1
    else:
        reprobado+=1
print(f"Aprobados {aprobado}, Reprobados {reprobado}")
'''
#Evidencia_39_for_n
'''
cantidad = 0
n = int(input("Cuantos valores va ingresar: "))
for f in range(n):
    valor = int(input("escribe el valor"))
    if valor >=1000:
        cantidad+=1
print("Cantidad de valores ingresados mayores a iguales a 1000")
print(cantidad)
'''
#evidencia_40_funcion_len
'''
#nombre = input("Escribe nombre")
#print("primer caracter")
#print(nombre[0])
#print("cantidad total de letra del nombre")
#print(len(nombre))
#Vocales
nombre = input("ingresar tu nombre: ")
if nombre[0]  =="a" or nombre[0]  =="e" or nombre[0]  =="i" or nombre[0]  =="o" or nombre[0] =="u":
    print("Tu nombre empieza con una vocal")
else:
    print("Tu nombren no inicia con una vocal")

contador =0
mail = input("Ingresa tu correo electronico: ")
'''
'''
for i in mail:
    if i=='@':
        contador += 1
if contador ==1:
    print(f"Arrobas contadas en el correo {contador}. Correcto")
else:
    print("incorrecto")

nombre1 = "mAriA"
print(nombre1)
nombre2 = nombre1.upper()
print(nombre2)
nombre3 = nombre1.lower()
print(nombre3)
nombre4 = nomobre1.capatalize()
print(nombre4)
'''
#evidencia_41
'''
lista = [10,7,3,7,2]
suma = 0

for x in lista:
    
    suma +=x
    
print(f"suma de lista {suma}")
'''