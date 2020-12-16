#include<stdio.h>




void punteros_(int *a,int *b,int *c){
int *px,*py,*pz;
	px=&c;
	py=&b;
	pz=&a;
	printf("\n\n\t\tPUNTEROS\n\n");
	printf("X es: %d\t",*px);
	printf("y es: %d\t",*py);
	printf("z es: %d\t",*pz);

	
}



int main(){
int x=10,y=20,z=30;
punteros_(x,y,z);
printf("			Valores iniciales\nX=10	Y=20	Z=30;");






return 0;


}

