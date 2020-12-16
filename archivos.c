#include<stdio.h>
#include<conio.h>
#include<string.h>
float sueldoA(float sueldo);
void main()
{
float sueldoleido, saldomas;
int i, n;
char nombres [50][40];
char nombre[40];
FILE *archemps;
archemps=fopen("sueldo.xls","w");
printf("Escribe el numero de empleados: ");
scanf("%d",&n);
fprintf(archemps,"%d\n",n);
 for(i=0;i<n;i++)
{
printf("\n\nEscribe el sueldo y nombre del empleado %d: ", i+1);
scanf("%f",&sueldoleido);
gets(nombre);
saldomas = sueldoA(sueldoleido);
fprintf(archemps, "%.2f  %s\n",saldomas, nombre);
 }
fclose(archemps);
getch();
}
float sueldoA(float sueldo){
if(sueldo>=5000)
{
return sueldo*1.1;
}
else
{
return sueldo*1.12;
}
}

