print("Diccionario")
diccionarios=[]
diccionario={"FRASE 1":"Hola soy Goku!!","FRASE 2":"hOLA KE ASE","FRSE3":"WHY SO SERIOUS?"}
for i in range(2):
    diccionario[f"FRASE {i+4}"]=input(f"insertar FRASE: {i+4} ")
    


diccionarios=diccionario.items()
print(diccionarios)





'''
precio_T=tuple()
print("PRECIOS")
precios=[]
n=int(input("Cuantos precios quieres registrar?"))
for i in range(n):
    precios.append(float(input("Inserta precio:")))
    precio_T=tuple(precios)
    if precios[i] < 50:
        print("Menor a 50")
    elif precios[i] >50:
        print("Maoyr a 50")
    else:
        print("Es igual a 50")
print(precio_T)
'''


    
