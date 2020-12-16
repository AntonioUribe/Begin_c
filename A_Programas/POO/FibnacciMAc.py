from matplotlib import pyplot as plt


class Fibonacci:
    def __init__(self, iniciales, posicion):
        self.iniciales = iniciales
        self.posicion = posicion

    def agregar(self):
        for i in range(self.posicion - 2):
            p1 = self.iniciales[i]
            p2 = self.iniciales[i + 1]
            r = p1 + p2
            self.iniciales.append(r)
        print(self.iniciales)
        return self.iniciales

    def grafica(self):
        self.agregar()

        return plt.plot(self.iniciales), plt.show()

g1 = Fibonacci([0, 1], 10)
g1.grafica()
