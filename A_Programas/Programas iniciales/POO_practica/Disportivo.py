
class DispotivoEntrada:

    def __init__(self,marca,tipo_entrada,):
        self.__tipo_entrada=tipo_entrada
        self.__marca=marca

    def get_entrada(self):
        return self.__tipo_entrada

    def set_entrada(self):
        self.__tipo_entrada=tipo_entrada

    def get_marca(self):
         return self._marca

    def set_marca(self):
        self.__marca=marca

class Raton(DispotivoEntrada):
    contador_ratones=0

    def __init__(self,marca,tipo_entrada):
        Raton.contador_ratones+=1
        self.__id_raton=Raton.contador_ratones
        self.__tipo_entrada=tipo_entrada
        self.__marca=marca

    def __str__(self):
        return (
            f"Id:{self.__id_raton},"
            f" marca: {self.__marca}, "
            f"Tipo entrada:{self.__tipo_entrada}"
        )
    def get_marca(self):
        return self.__marca

class Teclado(DispotivoEntrada):
    contador_teclados=0

    def __init__(self,marca,tipo_entrada):
        Teclado.contador_teclados+=1
        self.__id_teclado=Teclado.contador_teclados
        self.__tipo_entrada=tipo_entrada
        self.__marca=marca
        
    def get_tipo_entrada(self):
        return self.__tipo_entrada
        
'''
    def __str__(self):
        return (
            f"Id:{self.__id_teclado},"
            f" marca: {self.__marca}, "
            f"Tipo entrada:{self.__tipo_entrada}"
        )
'''
lel=Teclado('Lenovo','USB')
print(lel.get_tipo_entrada())