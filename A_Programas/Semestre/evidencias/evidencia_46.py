
nombre  = ["juan","ana","marcos","Carlos","luis"]

cantidad = 0
x=0
while x<len(nombre):
    if len(nombre[x])>=5:
        cantidad +=1
    x+=1
print("Todos los nombres")
print(nombre)
print("cantidad de nombres con 5 o mas caracteres: ")
print(cantidad)

