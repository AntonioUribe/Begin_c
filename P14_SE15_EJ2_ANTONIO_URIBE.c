#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
/*ESTRUCTRURA.

P13_SE14_EJ2_ANTONIO_URIBE*/


int main (){
	char name[50];

	float cal[10],p=0,prom;
	int i,dia,m;
	int mes;
	int anio;
	FILE *arch;
	printf("\t\tInserte nombre: \n");
	gets(name);
		printf("\t\tInserte Matricula \n");
		scanf("%d",&m);
			printf("\t\tInserte su fecha de nacimiento:\nDia:");
			scanf("%d",&dia);
				printf("Mes(Ejemplo->Enero=01):\n");
				scanf("%d",&mes);
					printf("anio:\n");
					scanf("%d",&anio);
for(i=0;i<10;i++){

	printf("Calificacion del examen %d\n",i+1);
	scanf("%f",&cal[i]);
	p=p+cal[i];
	}
	arch=fopen("archivo.txt","w");
	prom=p/10;
	if(prom>=70){
	
	fprintf(arch,"\n\n\n\n\n\t\t\t\t APROBADO\n\n");}
		else {
		
			system("cls");fprintf(arch,"\n\n\n\n\n\t\t\t\t REPROBADO\n\n");system("pause");}
	
	system("cls");
fprintf(arch,"		Registro\n");
fprintf(arch,"\n\t\t\tNombre:%s\n\t\t\t\n\t\t\tFecha: %d/%d/%d\n\n\t\t\tMatricula:%d\n\t\t\tPromedio:%.2f\n",name,dia,mes,anio,m,prom);
fprintf(arch,"\nCalificaciones\n");
	for(i=0;i<10;i++)
	{
	
	fprintf(arch,"calificacion %d: %.2f\n",i+1,cal[i]);
}
	fclose(arch);
	
	printf("se ha creado el archivo");
	
}
