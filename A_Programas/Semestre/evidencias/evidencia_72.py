import tkinter as tk

class Aplicacion:
    def __init__(self):
        self.ventana1=tk.Tk()
        self.ventana1.title("Prueba")
        self.boton1=tk.Button(self.ventana1, text="Hombre", command=self.presion_hombre)
        self.boton1.grid(column=0, row=0)
        self.boton2=tk.Button(self.ventana1, text="Mujer", command=self.presion_mujer)
        self.boton2.grid(column=4, row=0)
        self.ventana1.mainloop()
        
    def presion_hombre(self):
        self.ventana1.title("Hombre")
    
    def presion_mujer(self):
        self.ventana1.title("mujer")
        
aplicacion1=Aplicacion()