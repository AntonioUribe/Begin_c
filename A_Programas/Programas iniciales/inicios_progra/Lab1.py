import os

class Pelicula:
    i=0
    def __init__(self,nombre):
        self.__nombre=nombre

    def __str__(self):
        Pelicula.i+=1
        return "Pelicula: " + self.__nombre + "----Linea: " + str(Pelicula.i) + "\n"
    
    def get_peliculas(self):
        return self.__nombre

    def set_peliculas(self):
        self.__nombre=nombre

    
   

class CatalogoPeliculas:
    ruta_archivo="pelicula.txt"
    @staticmethod
    def Agregar_pelicula(pelicula):
        try :
            archivo=open(CatalogoPeliculas.ruta_archivo,"a")
            archivo.write(pelicula.__str__())

        except Exception as e:
            print("Ocurrio un error",e)
        finally:
            archivo.close()

    @staticmethod
    def listar_peliculas():
        try :
            archivo=open(CatalogoPeliculas.ruta_archivo,"r")
            print("Catalogo de peliculas")
            print(archivo.read())
        except Exception as e:
            print("ocurrio un error al listar peliculas")
        finally:
            archivo.close()

    @staticmethod
    def eliminar():
        os.remove(CatalogoPeliculas.ruta_archivo)
        print("Archivo eliminado",CatalogoPeliculas.ruta_archivo)
            
    



Near=True

while(Near):
    
    print("\t\t<<-PELICULAS->>")
    print("1-Agregar archivo")
    print("2-Leer archivo")
    print("3-Eliminar archivo")
    print("X-Salir")
    
    opcion=input("Elige: ")
    
    if opcion != "1" and opcion !="2" and opcion !="3" and  opcion !="x":
        print("Vuelve a escribir")
    elif opcion=="X":
        Near=False
        print(Salir)
    
    elif opcion=="1":
        i=0
        nombre_pelicula=input("Escribe peliculas: ")
        movie=Pelicula(nombre_pelicula)
        CatalogoPeliculas.Agregar_pelicula(movie)
        
        
    elif opcion=="2":
        CatalogoPeliculas.listar_peliculas()
        
    elif opcion=="3":
        CatalogoPeliculas.eliminar()
        
