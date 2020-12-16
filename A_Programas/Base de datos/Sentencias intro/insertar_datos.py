import psycopg2

conexion = psycopg2.connect(user='postgres',
                 password='admin', 
                 host='127.0.0.1',
                 port='5432',
                 database='test_db')
cursor = conexion.cursor()
sentencia =  'INSERT INTO persona(nombre,apellido,email) VALUES(%s,%s,%s)'
valores=('Carlos','Lara','clara@mail.com')
cursor.execute(sentencia,valores)
#guardamos la informacion en la base de datos
conexion.commit()
registros_insertados =cursor.rowcount
print(f'Registros insertados {registros_insertados}')
cursor.close()
conexion.close()