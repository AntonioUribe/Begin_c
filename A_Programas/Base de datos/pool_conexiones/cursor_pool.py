from conexion import Conexion
from logger_base import logger


class CursorDelPool:
    
    def __init__(self):
        self.__conn= None
        self.__cursor = None
    #inicio de with
    def __enter__(self):
        logger.debug(f'Inicio de  with método __enter__(): ')
        self.__conn = Conexion.obtenerConexion()
        self.__cursor = self.__conn.cursor()
        
        return self.__cursor
    
    def __exit__(self, exception_type,exception_value,exception_traceback):
        logger.debug('Se ejecuta __exit__()')
        #if exception_value is not None:
        if exception_value:
            self.__conn.rollback()
            logger.debug(f'Ocurrio una excepcion: {exception_value}')
        else:
            self.__cursor.close()
            self.__conn.commit()
            logger.debug('Commit de la transaccion')
        #Regresa la conexion al pool
        Conexion.liberarConexion(self.__conn)

if __name__ == '__main__':
    #obtenemos el cursor de la conexion del pool
    #with se inicia con __enter__() y finalia con __exit__()
    #() para llamar la funcion '__init__()'
    with CursorDelPool() as cursor:
        cursor.execute('SELECT * FROM persona')
        logger.debug(cursor.fetchall())
        
        
        
    