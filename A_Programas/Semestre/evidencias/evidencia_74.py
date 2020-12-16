import sqlite3
conexion = sqlite3.connect("c:/Users/schedule/Desktop/A_Programas/Semestre/interfaz/bd/dbpa.db")
try:
    conexion.execute("""
    create table articulos(
    codigo integer primary key autoincrement,
    descripcion text,
    precio real
    );                      """)
    print("La tabla se creo correctamente")
except sqlite3.OperationalError:
    print("la tbla articulos ya existe")
conexion.close()