import sqlite3
conexion = sqlite3.connect("c:/Users/schedule/Desktop/A_Programas/Semestre/interfaz/bd/dbpa.db")

conexion.execute("insert into articulos(descripcion,precio) values (?,?)",("refreso",35.50))
conexion.execute("insert into articulos(descripcion,precio) values (?,?)",("fritos",48.50))
conexion.execute("insert into articulos(descripcion,precio) values (?,?)",("fritos",48.50))
conexion.commit()
conexion.close()


