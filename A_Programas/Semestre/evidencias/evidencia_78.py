import sqlite3

conexion = sqlite3.connect("bdpa.db")
precio = float(input("ingresa un precio"))
cursor = conexion.execute("select descripcion from articulos where precio>?",(precio,))
filas = cursor.fetchall()
if len(filas)>0:
    for fila in filas:
        print(fila)
else:
    print("no existenarticulos con precio mayor al indicado")
conexion.close()