from logger_base import logger
from psycopg2 import pool
import sys

class Conexion:
    __DATEBASE='test_db'
    __USERNAME='postgres'
    __PASSWORD='admin'
    __DB_port='5432'
    __HOST='127.0.0.1'
    __MIN_CON=1
    __MAX_CON=5
    __pool=None
    
    @classmethod
    def ObtenerPool(cls):
        if cls.__pool == None:
            try:
                cls.__pool = pool.SimpleConnectionPool(
                                            cls.__MIN_CON,
                                            cls.__MAX_CON,
                                            host = cls.__HOST,
                                            user = cls.__USERNAME,
                                            password = cls.__PASSWORD,
                                            port = cls.__DB_port,
                                            database = cls.__DATEBASE)
                logger.debug(f'Creacion pool exitosa: {cls.__pool}')
                return cls.__pool
            except Exception as e:
                logger.error(f'Error al crear el pool de conexiones {e}')
                sys.exit()
        else:
            return cls.__pool
    
    
    
      
    @classmethod
    def obtenerConexion(cls):
        #Obtener una conexion del objeto pool
        conexion = cls.ObtenerPool().getconn()
        logger.debug(f'Conexion obtenida {conexion}')
        return conexion
    
    @classmethod
    def liberarConexion(cls,conexion):
        #Regresar la conexion
        cls.ObtenerPool().putconn(conexion)
        logger.debug(f'Regrsamos la Conexion al pool {conexion}')
        logger.debug(f'Estado del pool: {cls.__pool}')
    
    @classmethod
    def cerrarConexiones(cls):
        cls.ObtenerPool().closeall()
        logger.debug(f'Cerramos todas las conexiones del pool : {cls.__pool}')
            
if __name__=='__main__':
   #obterner una conexion del pool
   conexion1=Conexion.obtenerConexion()
   conexion2=Conexion.obtenerConexion()
   #Regresar las conexiones
   Conexion.liberarConexion(conexion1)
   #cerrar conexiones
   Conexion.cerrarConexiones()
   #Si intentamos pedir una conexion de un pool cerrado
   #conexion3=Conexion.obtenerConexion()
   
   