import psycopg2

conexion = psycopg2.connect(user='postgres',
                 password='admin', 
                 host='127.0.0.1',
                 port='5432',
                 database='test_db')
cursor = conexion.cursor()
sentencia =  'SELECT * FROM persona WHERE id_persona= %s'
#id_persona=2
id_persona = input("Inserte la llave primaria a buscar:")
llave_primaria=(id_persona,)
cursor.execute(sentencia, llave_primaria)
registro = cursor.fetchone()
print(registro)

cursor.close()
conexion.close()