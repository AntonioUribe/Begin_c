#Cadenas en Python

nombre = "Rodimiro" 
otro_nombre = 'Lucrecia'

'''
En Python, un valor de cadena consiste en una colección de elementos
donde cada elemento representa una posición en ella (un caracter),
incluyendo los espacios en blanco y símbolos especiales.

Estas posiciones se identifican mediante un número, el "índice", el cual
se empieza a contar a partir de 0 (cero); por lo anterior, el primer caracter
de una cadena siempre se encuentra en la posición 0.
'''
print(nombre[0])   #"R"
print(nombre[1])   #"o"
print(nombre[2])   #"d"

#Debido a que es un conjunto de elementos, se puede saber la longitud del mismo
print(len(otro_nombre)) #8

'''
Para accesar secciones de una cadena, se utiliza la notación de slice.
cadena[pos_inicial : pos_final + 1 : offset]
Si se omite pos_inicial, se asume el principio
Si se omite pos_final + 1, se asume el final del string
Si se omite offset, se asume 1
'''

#Desplegar los primeros tres caracteres de la variable nombre
print(nombre[0:3:1])    #Rod

#Desplegar del segundo al quinto caracter de la variable nombre
print(nombre[1:5:1])    #odim

#Desplegar el último caracter de la variable nombre
print(nombre[-1::])     #o





#Desplegar caracteres en las posiciones índice impares de la variable nombre
print(nombre[1::2])     #oiio

#Desplegar caracteres en las posiciones índice pares de la variable nombre
print(nombre[2::2])     #dmr

#Desplegar el valor de la variable nombre en orden invertido
print(nombre[::-1])     #orimidoR

#Las variables de tipo string contienen métodos propios, ejemplo:
print(nombre.upper())     #RODIMIRO
print(nombre.count("o"))  #2
print(nombre.find("mx"))   #4
print(nombre.find("x"))   #-1 debido a que el caracter "x" no se encuentra

#Determinar si un valor se encuentra contenido en una colección de elementos de tipo compatible.
print("mi" in nombre)     #True
print("Rod" in nombre)    #True
print("rod" in nombre)    #False

#Dividir y combinar cadenas
letras = "A, B, C, D"
print(letras.split(", ")) #['A', 'B', 'C', 'D']

#Métodos para comprobación de caracteres
cadena_numeros = "64000"
print(cadena_numeros.isalpha())  #False
print(cadena_numeros.isdigit())  #True

print(nombre.isalpha())          #True
print(nombre.isdigit())          #False

cadena_num_letras = "CP64000"
print(cadena_num_letras.isalpha())  #False
print(cadena_num_letras.isdigit())  #False
