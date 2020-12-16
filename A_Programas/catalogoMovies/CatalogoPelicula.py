import os
class Catalogo:
    
    ruta_archivo="pelicula.txt"
    
    
    @staticmethod
    def agregar_pelicula(pelicula):
        
        try:
            archivo=open(Catalogo.ruta_archivo,"a")
            
            archivo.write(pelicula.__str__())
        except Exception as e:
            print("Cargo un error al cargar. ",e)
        finally:
            archivo.close()
    
    @staticmethod
    def lista():
        try:
            archivo=open(Catalogo.ruta_archivo,"r")
            print("Catalogo de peliculas")
            print(archivo.read())
        except Exception as e:
            print("Cargo un error al ver Catalogo. ",e)
        finally:
            archivo.close()
    
    @staticmethod
    def eliminar():
        try:
            os.remove(Catalogo.ruta_archivo)
            print("Archivo eliminado: ",Catalogo.ruta_archivo)
        except Exception as e:
            print("Cargo un error al eliminar. ",e)