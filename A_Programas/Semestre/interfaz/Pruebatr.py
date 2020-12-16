import sqlite3

class Trabajador:

    def abrir(self):
        conexion=sqlite3.connect("C:/Users/schedule/Desktop/A_Programas/Semestre/interfaz/bd/prueba1.db")
        return conexion


    def alta(self, datos):
        cone=self.abrir()
        cursor=cone.cursor()
        sql="insert into trabajador(nombre,sueldo) values (?,?)"
        cursor.execute(sql, datos)
        cone.commit()
        cone.close()

    def consulta(self, datos):
        try:
            cone=self.abrir()
            cursor=cone.cursor()
            sql="select nombre, sueldo  from trabajador where id_trabajador =? "
            cursor.execute(sql, datos)
            return cursor.fetchall()
        finally:
            cone.close()
            

    def recuperar_todos(self):
        try:
            cone=self.abrir()
            cursor=cone.cursor()
            sql="select id_trabajador,nombre, sueldo from trabajador"
            cursor.execute(sql)
            return cursor.fetchall()
        finally:
            cone.close()

    def baja(self, datos):
        try:
            cone=self.abrir()
            cursor=cone.cursor()
            sql="delete from trabajador where id_trabajador=?"
            cursor.execute(sql, datos)
            cone.commit()
            return cursor.rowcount # retornamos la cantidad de filas borradas
        except:
            cone.close()
    
    def modificacion(self, datos):
        try:
            cone=self.abrir()
            cursor=cone.cursor()
            sql="update trabajador set nombre=?, sueldo=? where id_trabajador=?"
            cursor.execute(sql, datos)
            cone.commit()
            return cursor.rowcount # retornamos la cantidad de filas modificadas            
        except:
            cone.close()