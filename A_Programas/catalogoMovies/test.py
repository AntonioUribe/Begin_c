from pelicula import Pelicula
from CatalogoPelicula import Catalogo
pelicula=None
Near=True 

while(Near):
    
    print("\t\t<<-Peliculass->>")
    print("1-Agregar Pelicula")
    print("2-Imprimir Pelicula")
    print("3-Eliminar")
    print("X-Salir")
    opcion=input("Elige: ")
    
    if opcion=="X":
        Near=False
        print("Salir")
              
    elif opcion != "1" and opcion !="2" and opcion !="3" and opcion !="4" and opcion !="x":
        print("Vuelve a escribir")
        
    elif opcion=="1":
        name_movie=input("Escribe la pelicula: ")
        pelicula=Pelicula(name_movie)
        Catalogo.agregar_pelicula(pelicula) 
    elif opcion=="2":
        if pelicula is None:
            name_movie=input("Escribe la pelicula: ")
            pelicula=Pelicula(name_movie)
            Catalogo.agregar_pelicula(pelicula)
        else:
            print("Catalogo de peliculas")
            Catalogo.lista()
        
        
    elif opcion=="3": 
        Catalogo.eliminar()