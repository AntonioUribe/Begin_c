import tkinter as tk
from tkinter import ttk
from tkinter import messagebox as mb
from tkinter import scrolledtext as st
import Pruebade
class FormularioJefe:
    def __init__(self):
        self.jefe1=Pruebade.Jefes()
        self.ventana1=tk.Tk()
        self.ventana1.title("Jefe")
        self.cuaderno1 = ttk.Notebook(self.ventana1)        
        self.cargajefe()
        self.consulta_jefe()
        self.listado_completo()
        self.borrado()
        self.modificar()
        self.cuaderno1.grid(column=0, row=0, padx=10, pady=10)
        self.ventana1.mainloop()

    def cargajefe(self):
        self.pagina1 = ttk.Frame(self.cuaderno1)
        self.cuaderno1.add(self.pagina1, text="Carga")
        self.labelframe1=ttk.LabelFrame(self.pagina1, text="jefe")        
        self.labelframe1.grid(column=0, row=0, padx=5, pady=10)
        self.label1=ttk.Label(self.labelframe1, text="nombre:")
        self.label1.grid(column=0, row=0, padx=4, pady=4)
        self.nombrecarga=tk.StringVar()
        self.entrynombre=ttk.Entry(self.labelframe1, textvariable=self.nombrecarga)
        self.entrynombre.grid(column=1, row=0, padx=4, pady=4)
        self.label2=ttk.Label(self.labelframe1, text="ocupacion:")        
        self.label2.grid(column=0, row=1, padx=4, pady=4)
        self.ocupacioncarga=tk.StringVar()
        self.entryocupacion=ttk.Entry(self.labelframe1, textvariable=self.ocupacioncarga)
        self.entryocupacion.grid(column=1, row=1, padx=4, pady=4)
        self.boton1=ttk.Button(self.labelframe1, text="Confirmar", command=self.agregar)
        self.boton1.grid(column=1, row=2, padx=4, pady=4)

    def agregar(self):
        datos=(self.nombrecarga.get(), self.ocupacioncarga.get())
        self.jefe1.alta(datos)
        mb.showinfo("Información", "Los datos fueron cargados")
        self.nombrecarga.set("")
        self.ocupacioncarga.set("")

    def consulta_jefe(self):
        self.pagina2 = ttk.Frame(self.cuaderno1)
        self.cuaderno1.add(self.pagina2, text="Consulta")
        self.labelframe2=ttk.LabelFrame(self.pagina2, text="jefe")
        self.labelframe2.grid(column=0, row=0, padx=5, pady=10)
        self.label1=ttk.Label(self.labelframe2, text="Código:")
        self.label1.grid(column=0, row=0, padx=4, pady=4)
        self.codigo=tk.StringVar()
        self.entrycodigo=ttk.Entry(self.labelframe2, textvariable=self.codigo)
        self.entrycodigo.grid(column=1, row=0, padx=4, pady=4)
        self.label2=ttk.Label(self.labelframe2, text="Nombre:")        
        self.label2.grid(column=0, row=1, padx=4, pady=4)
        self.descripcion=tk.StringVar()
        self.entrynombre=ttk.Entry(self.labelframe2, textvariable=self.descripcion, state="readonly")
        self.entrynombre.grid(column=1, row=1, padx=4, pady=4)
        self.label3=ttk.Label(self.labelframe2, text="Ocupacion:")        
        self.label3.grid(column=0, row=2, padx=4, pady=4)
        self.precio=tk.StringVar()
        self.entryocupacion=ttk.Entry(self.labelframe2, textvariable=self.precio, state="readonly")
        self.entryocupacion.grid(column=1, row=2, padx=4, pady=4)
        self.boton1=ttk.Button(self.labelframe2, text="Consultar", command=self.consultar)
        self.boton1.grid(column=1, row=3, padx=4, pady=4)

    def consultar(self):
        datos=(self.codigo.get(), )
        respuesta=self.jefe1.consulta(datos)
        if len(respuesta)>0:
            self.descripcion.set(respuesta[0][0])
            self.precio.set(respuesta[0][1])
        else:
            self.descripcion.set('')
            self.precio.set('')
            mb.showinfo("Información", "No existe un jefe con dicho código")

    def listado_completo(self):
        self.pagina3 = ttk.Frame(self.cuaderno1)
        self.cuaderno1.add(self.pagina3, text="Listado completo")
        self.labelframe3=ttk.LabelFrame(self.pagina3, text="Jefe")
        self.labelframe3.grid(column=0, row=0, padx=5, pady=10)
        self.boton1=ttk.Button(self.labelframe3, text="Listado completo", command=self.listar)
        self.boton1.grid(column=0, row=0, padx=4, pady=4)
        self.scrolledtext1=st.ScrolledText(self.labelframe3, width=30, height=10)
        self.scrolledtext1.grid(column=0,row=1, padx=10, pady=10)

    def listar(self):
        respuesta=self.jefe1.recuperar_todos()
        self.scrolledtext1.delete("1.0", tk.END)        
        for fila in respuesta:
            self.scrolledtext1.insert(tk.END, "código:"+str(fila[0])+
                                              "\nNombre:"+fila[1]+
                                              "\n Ocupacion:"+str(fila[2])+"\n\n")

    def borrado(self):
        self.pagina4 = ttk.Frame(self.cuaderno1)
        self.cuaderno1.add(self.pagina4, text="Borrado de jefe")
        self.labelframe4=ttk.LabelFrame(self.pagina4, text="Jefe")        
        self.labelframe4.grid(column=0, row=0, padx=5, pady=10)
        self.label1=ttk.Label(self.labelframe4, text="Código:")
        self.label1.grid(column=0, row=0, padx=4, pady=4)
        self.codigoborra=tk.StringVar()
        self.entryborra=ttk.Entry(self.labelframe4, textvariable=self.codigoborra)
        self.entryborra.grid(column=1, row=0, padx=4, pady=4)
        self.boton1=ttk.Button(self.labelframe4, text="Borrar", command=self.borrar)
        self.boton1.grid(column=1, row=1, padx=4, pady=4)

    def borrar(self):
        datos=(self.codigoborra.get(), )
        cantidad=self.jefe1.baja(datos)
        if cantidad==1:
            mb.showinfo("Información", "Se borró el jefe con dicho código")
        else:
            mb.showinfo("Información", "No existe un jefe con dicho código")

    def modificar(self):
        self.pagina5 = ttk.Frame(self.cuaderno1)
        self.cuaderno1.add(self.pagina5, text="Modificar jefe")
        self.labelframe5=ttk.LabelFrame(self.pagina5, text="jefe")
        self.labelframe5.grid(column=0, row=0, padx=5, pady=10)
        self.label1=ttk.Label(self.labelframe5, text="Código:")
        self.label1.grid(column=0, row=0, padx=4, pady=4)
        self.codigomod=tk.StringVar()
        self.entrycodigo=ttk.Entry(self.labelframe5, textvariable=self.codigomod)
        self.entrycodigo.grid(column=1, row=0, padx=4, pady=4)
        self.label2=ttk.Label(self.labelframe5, text="nombre:")        
        self.label2.grid(column=0, row=1, padx=4, pady=4)
        self.nombremod=tk.StringVar()
        self.entrynombre=ttk.Entry(self.labelframe5, textvariable=self.nombremod)
        self.entrynombre.grid(column=1, row=1, padx=4, pady=4)
        self.label3=ttk.Label(self.labelframe5, text="ocupacion:")        
        self.label3.grid(column=0, row=2, padx=4, pady=4)
        self.ocupacionmod=tk.StringVar()
        self.entryocupacion=ttk.Entry(self.labelframe5, textvariable=self.ocupacionmod)
        self.entryocupacion.grid(column=1, row=2, padx=4, pady=4)
        self.boton1=ttk.Button(self.labelframe5, text="Consultar", command=self.consultar_mod)
        self.boton1.grid(column=1, row=3, padx=4, pady=4)
        self.boton1=ttk.Button(self.labelframe5, text="Modificar", command=self.modifica)
        self.boton1.grid(column=1, row=4, padx=4, pady=4)

    def modifica(self):
        datos=(self.nombremod.get(), self.ocupacionmod.get(), self.codigomod.get())
        cantidad=self.jefe1.modificacion(datos)
        if cantidad==1:
            mb.showinfo("Información", "Se modificó el jefe")
        else:
            mb.showinfo("Información", "No existe un jefe con dicho código")

    def consultar_mod(self):
        datos=(self.codigomod.get(), )
        respuesta=self.jefe1.consulta(datos)
        if len(respuesta)>0:
            self.nombremod.set(respuesta[0][0])
            self.ocupacionmod.set(respuesta[0][1])
        else:
            self.nombremod.set('')
            self.ocupacionmod.set('')
            mb.showinfo("Información", "No existe un jefe con dicho código")






