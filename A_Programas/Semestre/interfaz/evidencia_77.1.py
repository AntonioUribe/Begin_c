import sqlite3
conexion = sqlite3.connect("c:/Users/schedule/Desktop/A_Programas/Semestre/interfaz/bd/prueba1.db")
codigo = int(input("ingresa el codigo del articulo"))
cursor = conexion.execute("select descripcion, precio from articulos where codigo=?",(codigo,))
fila = cursor.fetchone()

if fila != None:
    print(fila)
else:
    print("No existe el articulo con dicho codigo")
conexion.close()