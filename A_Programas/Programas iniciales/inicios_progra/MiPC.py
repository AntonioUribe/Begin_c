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

class Teclado(DispotivoEntrada):
    contador_teclados=0

    def __init__(self,marca,tipo_entrada):
        Teclado.contador_teclados+=1
        self.__id_teclado=Teclado.contador_teclados
        self.__tipo_entrada=tipo_entrada
        self.__marca=marca

    def __str__(self):
        return (
            f"Id:{self.__id_teclado},"
            f" marca: {self.__marca}, "
            f"Tipo entrada:{self.__tipo_entrada}"
        )

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
class Orden:
    contador_ordenes=0
   
    def __init__(self, computadoras):
        Orden.contador_ordenes+=1
        self.__id_orden=Orden.contador_ordenes
        self.__computadoras=computadoras

    def Agregar_computadora(self, computadora):
        self.__computadoras.append(computadora)

    def __str__(self):
        computadora_str=""
        for computadora in self.__computadoras:
            computadora_str+=computadora.__str__()

        return(
           f"Orden:{self.__id_orden}, "
           f"Computadoras : {computadora_str}"
           
           )



        


raton_hp=Raton("HP","usb")
teclado_hp=Teclado("HP","Bluetooh")
monitor_hp=Monitor("HP","15 pulgadas")
computadora_hp=Computadora("Hp", monitor_hp, teclado_hp,raton_hp)

raton_acer=Raton("acer","Bluetooh")
teclado_acer=Teclado("acer","Bluetooh")
monitor_acer=Monitor("acer","25 pulgadas")
computadora_acer=Computadora("acer", monitor_acer, teclado_acer,raton_acer)

raton_gamer=Raton("gamer","Bluetooh")
teclado_gamer=Teclado("gamer","Bluetooh")
monitor_gamer=Monitor("gamer","47 pulgadas")
computadora_gamer=Computadora("gamer", monitor_gamer, teclado_gamer,raton_gamer)

computadora1=[computadora_hp,computadora_acer]

orden1=Orden(computadora1)

print(orden1)

orden1.Agregar_computadora(computadora_gamer)
print(orden1)

