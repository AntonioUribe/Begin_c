class Pelicula:
    contador=0
    def __init__(self,nombre):
        self.__nombre=nombre
          
    def __str__(self):
        Pelicula.contador+=1
        return (f'''
                 Pelicula {Pelicula.contador}:  {self.__nombre} \n
                ''')

    def get_pelicula(self):
        return self.__nombre

    def set_pelicula(self,nombre):
        self.__nombre=nombre