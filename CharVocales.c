/*
-Leer 20 lineas 
-Max 80 lineas de cadena de caracteres
-Mostrar el numero de vocales que tiene cada linea
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contarVocales(char *);
char *frase[80];

int main(){
	int linea;
	printf("Contador de vocales\n");
	for(linea=0;linea<2;linea++){
	
		printf("\nEscribe texto en la linea %d\n",linea+1);
		fgets(frase,80,stdin);
		
		strupr(frase);//Funcion que convierte la cadena en Mayusculas. 
		printf("Numero de vocales en la linea es: %d\n",contarVocales(&frase));
	
	}
	return 0;
}
int contarVocales(char *texto){
	int contador = 0;
	while(*texto){ //Recorre letra x letra para coincidir con alguna vocal.
		switch(*texto){
		
			case 'A': 
			case 'E':
			case 'I':
			case 'O':
			case 'U': contador++;
		}
		texto++;
	}
	return contador;
}
