from orden import Orden
from  Monitor_PC import Monitor, Computadora
from  Disportivo import DispotivoEntrada, Raton, Teclado

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

