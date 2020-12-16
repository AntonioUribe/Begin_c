import logging
#Variable logger a utilizar
logger=logging

logger.basicConfig(level=logging.DEBUG,
                   format='%(asctime)s: %(levelname)s [%(filename)s:%(lineno)s] %(message)s',
                   datefmt='%I:%M:%S %p',
                   handlers=[logging.FileHandler('capa_datos.log'),
                    logging.StreamHandler()
                    ])
logger.debug(__name__)
if __name__=='__main__':
    logging.warning("Mensaje warning")
    logging.info('Mensaje de info')
    logging.debug('Mensaje debug')
    logging.error('ocrrio un error en la base de datos')
    logging.debug('Se realizo la conexion con exito')



