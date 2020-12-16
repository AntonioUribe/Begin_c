import sqlite3
conexion = sqlite3.connect("c:/Users/schedule/Desktop/A_Programas/Semestre/interfaz/bd/dbpa.db")
cursor = conexion.execute("select * from articulos")
for fila in cursor:
    print(fila)

conexion.close()