#ABC=Abstract Base Class

from abc import ABC, abstractmethod
class FiguraGeometrica(ABC):
    def __init__(self,ancho, altura):
        self.ancho=ancho
        self.altura=altura
        
    @abstractmethod
    def area(self):
        pass


