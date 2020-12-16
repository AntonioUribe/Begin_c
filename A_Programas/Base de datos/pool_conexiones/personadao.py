from cursor_pool import CursorDelPool 
from conexion import Conexion
from logger_base import logger
from persona import Persona

class PersonaDao:
    '''
    DAO (DATE ACCES OBJECT)
    CRUD: CREATE-READ-UPDATE-DELETE entidad persona
    
    '''
    __SELECCIONAR = 'SELECT * FROM persona ORDER BY persona'
    __INSERTAR = 'INSERT INTO persona(nombre, apellido,email) VALUES(%s,%s,%s)'
    __ACTUALIZAR = 'UPDATE persona SET nombre=%s,apellido=%s,email=%s WHERE id_persona= %s'
    __ELIMINAR = 'DELETE FROM persona WHERE id_persona= %s'
    
    @classmethod
    def seleccionar(cls):
        with CursorDelPool() as cursor:
            logger.debug(cursor.mogrify(cls.__SELECCIONAR))
            cursor.execute(cls.__SELECCIONAR)
            registros = cursor.fetchall()
            personas=[]
            for registro in registros:
                persona=Persona(registro[0],registro[1],registro[2],registro[3])
                personas.append(persona)
            return personas
        
    
    @classmethod
    def insertar(cls,persona):
        with CursorDelPool() as cursor:
            
            logger.debug(cursor.mogrify(cls.__INSERTAR))
            logger.debug(f'Persona a insertar: {persona}')
            valores = (persona.get_nombre(),persona.get_apellido(), persona.get_email())
            cursor.execute(cls.__INSERTAR, valores)
            return cursor.rowcount
        
            
            
    @classmethod
    def actualizar(cls,persona):
        with CursorDelPool() as cursor:
            logger.debug(cursor.mogrify(cls.__ACTUALIZAR))
            logger.debug(f'Persona a actualizar: {persona}')
            valores = (persona.get_nombre(),persona.get_apellido(), persona.get_email(), persona.get_id_persona())
            cursor.execute(cls.__ACTUALIZAR, valores)
        
            return cursor.rowcount
       
            
            
    @classmethod
    def eliminar(cls, persona):
        with CursorDelPool() as cursor:
            logger.debug(cursor.mogrify(cls.__ELIMINAR))
            logger.debug(f'Persona a eliminar: {persona}')
            valores = (persona.get_id_persona(),)
            cursor.execute(cls.__ELIMINAR, valores)
            
            return cursor.rowcount
        
    
    
    
if __name__=='__main__':
    #listado de personas
    
    personas = PersonaDao.seleccionar()
    for persona in personas:   
        logger.debug(persona)
        logger.debug(persona.get_id_persona())
    
    
    #insertamos un nuevo registro
    #persona = Persona(nombre = 'Pedro', apellido = 'Najera', email = 'pnajera@mail.com') 
    #registros_insertados = PersonaDao.insertar(persona)
    
    #logger.debug(f'Personas insertados: {registros_insertados}')
    
    #Actualizar un registro
    #persona= Persona(24,'Antonio','Uribe','salazarantoniosa@gmail.com')
    #registros_actualizar = PersonaDao.actualizar(persona)
    #logger.debug(f'Personas actualizadas: {registros_actualizar}')
    
    #Eliminar
    #persona2 = Persona(id_persona=1)
    #personas_eliminadas = PersonaDao.eliminar(persona2)
    #logger.debug(f'Personas eliminadas: {personas_eliminadas}')