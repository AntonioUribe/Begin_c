import sqlite3

class Empresa:

    def abrir(self):
        conexion=sqlite3.connect("C:/Users/schedule/Desktop/A_Programas/Semestre/interfaz/bd/prueba1.db")
        return conexion


    def recuperar_todos(self):
        try:
            cone=self.abrir()
            cursor=cone.cursor()
            sql="select departamento.especialidad,jefe.nombre, trabajador.nombre from departamento,trabajador,jefe"
            cursor.execute(sql)
            return cursor.fetchall()
        finally:
            cone.close()
