import sqlite3
conexion = sqlite3.connect("C:/Users/schedule/Desktop/A_Programas/Semestre/interfaz/bd/prueba1.db")

#conexion.execute("insert into departamentoi(nombre,seccion) VALUES (?,?)",("tecnologia","A"))
#conexion.execute("insert into departamento(especialidad,seccion) values (?,?)",("Finanzas","B"))


conexion.execute("insert into trabajador(nombre,sueldo) values (?,?)",("Antonio",15000.00))
#conexion.execute("insert into jefe(nombre,ocupacion) values (?,?)",("Santino","Programador"))


conexion.commit()
conexion.close()