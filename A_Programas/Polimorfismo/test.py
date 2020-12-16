from empleado  import Empleado
from Gerente import Gerente

def imprimir_detalles(objeto):
    print(objeto, end="\n\n")
    print(type(objeto),end="\n\n")
    if isinstance (objeto,Gerente):
        (objeto.departamento)

empleado=Empleado("Antonio",1000.00)

imprimir_detalles(empleado)

empleado=Gerente("Pedro",2000.00,"Sistemas")
imprimir_detalles(empleado)
