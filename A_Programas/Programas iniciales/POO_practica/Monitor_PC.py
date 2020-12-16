
class Monitor:
    contador_monitores=0

    def __init__(self,marca,tamanio):
        Monitor.contador_monitores+=1
        self.__id_monitor=Monitor.contador_monitores
        self.__marca=marca
        self.__tamanio=tamanio

    def __str__(self):

        return (
            f"Id: {self.__id_monitor},"
            f"marca: {self.__marca}, "
            f"Tamanio: {self.__tamanio}"
        )
        

class Computadora:
    contador_computadoras=0
    
    def __init__(self, nombre, monitor, teclado ,raton):
        Computadora.contador_computadoras+=1
        self.__id_computadora= Computadora.contador_computadoras
        self.__nombre=nombre
        self.__monitor=monitor
        self.__teclado=teclado
        self.__raton=raton

    def __str__(self):
        return (
            f"""
            {self.__nombre}: {self.__id_computadora}
                Monitor: {self.__monitor}
                Teclado: {self.__teclado}
                Raton:   {self.__raton}
            """
            )