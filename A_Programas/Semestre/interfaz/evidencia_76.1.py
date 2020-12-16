import sqlite3
conexion = sqlite3.connect("c:/Users/schedule/Desktop/A_Programas/Semestre/interfaz/bd/prueba1.db")
#cursor = conexion.execute("select trabajador.id_trabajador,departamento.especialidad, trabajador.nombre from departamento,trabajador")

#cursor = conexion.execute("select * from departamento ")
cursor = conexion.execute("select * from trabajador ")
for fila in cursor:
    print(fila)

conexion.close()