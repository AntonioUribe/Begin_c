from cursor_pool import CursorDelPool 
from conexion import Conexion
from logger_base import logger
from persona import Persona
from personadao import PersonaDao


if __name__ == '__main__':
    Near=True 

    while(Near):
        
        print("\t\t<<-Registro de personas->>")
        print("1-Agregar persona")
        print("2-Imprimr persona")
        print("3-Actualizar persona")
        print("4-Eliminar persona")
        print("X-Salir")
        opcion=input("Elige: ")
        
        if opcion=="X":
            Near=False
            print("Salir")
                
        elif opcion != "1" and opcion !="2" and opcion !="3" and opcion !="4" and opcion !="x":
            print("Vuelve a escribir")
            input("<<PRESS ENTER TO CONTINUE>>")
            
        elif opcion=="1":
            print("\t\tAgregar personas")
            
            nombre=input('Escribe nombre: ')
            apellido = input('Escirbe apellido: ')
            email = input('Escribe el correo: ')
            personas_agregar = Persona(None,nombre, apellido, email)
            PersonaDao.insertar(personas_agregar)
            input("<<PRESS ENTER TO CONTINUE>>")
            
                
            
        elif opcion == '2':
            print("\t\tImprimr persona")
            personas_imprimir = PersonaDao.seleccionar()
            
            for imprimir in personas_imprimir:
                logger.debug(imprimir)
                
            input("<<PRESS ENTER TO CONTINUE>>")
            
        elif opcion == '3':
            print("\t\tActualizar")
            id_persona = int(input("Escribe id actuaizar: "))
            nombre=input('Escribe nombre: ')
            apellido = input('Escirbe apellido: ')
            email = input('Escribe el correo: ')
            personas_actualizadas = Persona(id_persona,nombre,apellido,email)
            actualizo=PersonaDao.actualizar(personas_actualizadas)
            logger.debug(f'Actulizado {actualizo}')
            
            input("<<PRESS ENTER TO CONTINUE>>")
        
        elif opcion == '4':
            print("\t\t Eliminar")
            id_persona = int(input("Escribe el id a eliminar:"))
            personas_eliminadas = Persona(id_persona)
            elimino = PersonaDao.eliminar(personas_eliminadas)
            logger.debug(f'Id eliminado {elimino}')
            
            input("<<PRESS ENTER TO CONTINUE>>")

    