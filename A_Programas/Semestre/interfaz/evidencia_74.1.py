import sqlite3
conexion = sqlite3.connect("C:/Users/schedule/Desktop/A_Programas/Semestre/interfaz/bd/prueba1.db")
try:
    conexion.execute("""
create table trabajador(
id_trabajador integer primary key autoincrement,
nombre text,
sueldo real
)
""")
    print("La tabla se creo correctamente")
except sqlite3.OperationalError:
    print("la tabla articulos ya existe")

conexion.close()

#Colocar las tablas una por una en conexion.execute()
#Tabla para crear Trabajdor
'''
create table trabajador(
id_trabajador integer primary key autoincrement,
nombre text,
sueldo real
);
'''
#Tabla para crear departamento
'''
create table departamento(
codigo integer primary key autoincrement,
especialidad text
seccion
);
'''
#Tabla para crear Jefes
'''
create table trabajador(
id_trabajador integer primary key autoincrement,
nombre text,
sueldo real
);
'''