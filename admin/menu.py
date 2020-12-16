import PruebaT
import PruebaD
import PruebaJ
import PruebaE
import tkinter as tk
import wx

def trabajador(event):
    a=PruebaT.FormularioTrabajador()
    
def departamento(event):
    a=PruebaD.FormularioDepartamento()
    
def jefe(event):
    a=PruebaJ.FormularioJefe()

def empresa(event):
    a=PruebaE.FormularioEmpresa()
    
app = wx.App()
frame = wx.Frame(None, -1, 'Administrador de tareas.py')
frame.SetDimensions(100,200,300,400)

panel = wx.Panel(frame, wx.ID_ANY)
labelA = wx.StaticText(panel, wx.ID_ANY, "Administrador de la empresa", pos=(100,0))
button = wx.Button(panel, wx.ID_ANY, 'Trabajador', (120, 30),size=(100,50))
button.Bind(wx.EVT_BUTTON, trabajador)


button2 = wx.Button(panel, wx.ID_ANY, 'Departamento', (120, 80),size=(100,50))
button2.Bind(wx.EVT_BUTTON, departamento)
button2.SetBackgroundColour(wx.Colour(200,50,100))

button3 = wx.Button(panel, wx.ID_ANY, 'Jefes', (120, 130),size=(100,50))
button3.Bind(wx.EVT_BUTTON, jefe)
button3.SetBackgroundColour(wx.Colour(150,255,100))

button4 = wx.Button(panel, wx.ID_ANY, 'Empresa', (120, 180),size=(100,50))
button4.Bind(wx.EVT_BUTTON, empresa)
button4.SetBackgroundColour(wx.Colour(200,255,100))
frame.Show()
frame.Centre()
app.MainLoop()
#aplicacion1=FormularioArticulos()
#a=Prueba2.FormularioTrabajador()
#a=Prueba2.FormularioTrabajador()
