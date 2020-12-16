#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>

struct EMPRESA	//ESTRUCTURAS
{
	char ID[10];
	char NAME[15];
	char RFC[15];
	char DIR[50];
	char PHONE[50];
	char CONTACTO[50];
	char EMAIL[50];
	char ASIGN[15];
};
struct EMPRESA EM[' '];

struct PERFIL
{
	char ID[10];
	char NAME[35];
	char DESC[30];
	int STAT;
	int CANT;
	char ID_EM[15];
};
struct PERFIL PE[' '];

struct EMPLEADO
{
	char ID[10];
	char NAME[50];
	char PERF[30];
	int STAT;
	int FCHA;
	int FUMA;
	int SEX;
	int SUMA_ASEG;
	float TARIFA;
};
struct EMPLEADO EMP[' '];

struct EDAD
{
	int DIA;
	int MES;
	int ANIO;
};
struct EDAD ED[' '];


void INICIO();	//FUNCIONES//
void MENU();							
void SUBMENU_EMPRESA();					
void SUBMENU_PERFIL();
void SUBMENU_EMPLEADO();
void SUBMENU_BUSQUEDAS();
void ASIGNAR_EMPLEADO();

int VALIDAR_SOLO_LETRAS(char x[' ']); //FUNCIONES DE VALIDACION//
int VALIDAR_USUARIO(char x[' ']);
int VALIDAR_CONTRASENIA(char x[' ']);
int VALIDAR_CORREO(char x[' ']);
int VALIDAR_TELEFONO(char x[' ']);
int VALIDAR_LETRAS_CON_NUMEROS(char x[' ']);
int VALIDAR_SOLO_NUMERO(char x[' ']);
float VERIFICACION(int suma_asegurada,int edad);

int i=0,j=0,k=0; //VARIABLES GLOBALES

void main() //FUNCION PRINCIPAL
{
	INICIO();	
}

void INICIO() //FUNCION DE REGISTRO DE ADMIN//
{
	char usuario[50],contrasenia[50],verificar[50];
	char usuario1[50],contrasenia1[50];
	FILE *fd; 		//PUNTERO-ARCHIVO ADMIN//
	FILE *fd1;		//PUNTERO-ARCHIVO VALIDACION//
	int a=0,b=0;
	
	fd1=fopen("VALIDACION.txt","a+");
	if(fd1==NULL)
	{
		printf("NO SE PUDO CREAR EL ARCHIVO:(");
	}
	else
	{
		if(fd1!=NULL)
		{
			if(fgetc(fd1)=='a')
			{
				fd=fopen("ADMIN.txt","r");				//ABRIR//
				fgets(usuario,50,fd);
				fgets(contrasenia,50,fd);
				fclose(fd);								//CERRAR//
				do
				{
					printf("\n\n\t\t\t------INICIO DE SESION------");
					printf("\n\n\t\t\tUSUARIO: ");
					fflush(stdin);
					fgets(usuario1,50,stdin);
					printf("\n\t\t\tCONTRASE%cA: ",165);
					fflush(stdin);
					fgets(contrasenia1,50,stdin);
					if(strcmp(usuario,usuario1)!=0||strcmp(contrasenia,contrasenia1)!=0)
					{
						printf("\n\t\t\tCONTRASE%cA O USUARIO INCORRECTOS",165);
						getch();
						system("cls");
					}
					else
					{
						if(strcmp(usuario,usuario1)==0||strcmp(contrasenia,contrasenia1)==0)
						{
							system("cls");
							MENU();
						}
					}
				}while(strcmp(usuario,usuario1)!=0||strcmp(contrasenia,contrasenia1)!=0);
			}
			else
			{
				fd=fopen("ADMIN.txt","w");				//ABRIR FD//
				if(fd==NULL)
				{
					printf("NO SE PUDO CREAR EL ARCHIVO:(");
				}
				else
				{
					if(fd!=NULL)
					{
						printf("\n\n\n\n\n\n\n\n\t\tESTA ES LA PRIMERA VEZ QUE SE INICIA EL PROGRAMA");
						getch();
						system("cls");
						printf("\n\n\n\n\n\n\n\n\t\tLO PRIMERO QUE SE DEBE HACER ES REGISTRAR UN ""ADMINISTRADOR""");
						getch();
						system("cls");
						printf("\n\n\n\n\n\n\n\n\tDICHO ADMINISTRADOR SERA EL ENCARGADO DE REGISTRAR DATOS EN EL PROGRAMA");
						getch();
						system("cls");
						do
						{
							printf("\n  SI USTED SERA EL ADMINISTRADOR, INGRESE UN NOMBRE DE USUARIO Y UNA CONTRASENIA\n\n");
							do
							{
								printf("\t\t\t\tUSUARIO:");
								fgets(usuario,30,stdin);
								fflush(stdin);
								b=strlen(usuario);
								if(b==1)
								{
									system("cls");
									printf("\n  SI USTED SERA EL ADMINISTRADOR, INGRESE UN NOMBRE DE USUARIO Y UNA CONTRASENIA\n\n");
								}
							}while(b==1);
							a=VALIDAR_USUARIO(usuario);
							if(a!=1)
							{
								system("cls");
							}
						}while(a!=1);	
						fprintf(fd,"%s",usuario);
						printf("\n");
						do
						{
							system("cls");
							printf("\n  SI USTED SERA EL ADMINISTRADOR, INGRESE UN NOMBRE DE USUARIO Y UNA CONTRASENIA\n\n");
							printf("\t\t\t\tUSUARIO: %s",usuario);
							printf("\t\t\t\tCONTRASENIA:");
							fgets(contrasenia,30,stdin);
							b=strlen(contrasenia);
							a=VALIDAR_CONTRASENIA(contrasenia);
						}while(a!=1||b==1);	
						fprintf(fd,"%s",contrasenia);
						
						fclose(fd);
						fd1=fopen("VALIDACION.txt","w");	//ABRIR FD1//
						{
							fprintf(fd1,"a");
							fclose(fd1);					//CERRAR FD1//
						}
						system("cls");
						printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tBIENVENIDO!");
						getch();
						MENU();
					}	
				}
				fclose(fd);									//CERRAR FD//
			}
		}
	}
	printf("\n\n\n\t\t");
	system("pause");
}
void MENU()	//FUNCION CON EL MENU DEL SISTEMA//
{
	int numerovalidado=0,b=0;
	char op[' '];
	
	do
	{
		system ("cls");
	    printf("\n\n\t\t\t---------MENU PRINCIPAL---------\n");
	    printf("\n\t\t\t1)EMPRESA\n\t\t\t2)PERFIL\n\t\t\t");
	    printf("3)EMPLEADOS\n\t\t\t4)BUSQUEDAS\n\t\t\t5)ASIGNAR EMPLEADOS\n\t\t\t6)SALIR\n\n");	
	   	do
		{
			printf("\t\t        ==>OPCION A ELEGIR: ");
			fflush(stdin);
			gets(op);
			b=VALIDAR_SOLO_NUMEROS(op);
			numerovalidado=atoi(op);
		   	if(b==0||numerovalidado<1||numerovalidado>6)
			{
			    system("cls");
			    printf("\n\n\t\t\t---------MENU PRINCIPAL---------\n");
	  			printf("\n\t\t\t1)EMPRESA\n\t\t\t2)PERFIL\n\t\t\t");
	   			printf("3)EMPLEADOS\n\t\t\t4)BUSQUEDAS\n\t\t\t5)ASIGNAR EMPLEADOS\n\t\t\t6)SALIR\n\n");	
			}
	   }while(numerovalidado<1||numerovalidado>6||b==0);
	   
		switch(numerovalidado)
	    {
		    case 1: //EMPRESA
			    SUBMENU_EMPRESA();
		    break;
		
		    case 2: //PERFILES
			    SUBMENU_PERFIL();
		    break;
		
		    case 3: //EMPLEADOS
			    SUBMENU_EMPLEADO();
		    break;
		
		    case 4: //BUSQUEDA
			   	SUBMENU_BUSQUEDAS();
		    break;
		
		    case 5: //ASIGNAR EMPLEADOS
				ASIGNAR_EMPLEADO();
		    break;
		
		    case 6: //SALIR
			   
		    break;
	    }
	}while (numerovalidado<0||numerovalidado>6);
}


void SUBMENU_EMPRESA() //FUNCION ENCARGADA DE ACCIONES EN EMPRESAS(COMPLETO)//
{
	int x=0,y=0,bandera1=0,eliminar=0,cambio=0;
	int a=0,b=0,numerovalidado=0;
	char op1[' '],z[' '];
	
	system("cls");
	printf("\n\n\t\t\t---------MENU EMPRESA---------\n\n");	
	printf("\t\t\t1)ALTA\n\t\t\t2)BAJA\n\t\t\t3)CAMBIO\n\t\t\t4)REGRESAR AL MENU PRINCIPAL\n\n");
	do
	{
		printf("\t\t        ==>OPCION A ELEGIR: ");
		fflush(stdin);
		gets(op1);
		b=VALIDAR_SOLO_NUMEROS(op1);
		numerovalidado=atoi(op1);
	   	if(b==0||numerovalidado<1||numerovalidado>4)
		{
		    system("cls");
		    printf("\n\n\t\t\t---------MENU EMPRESA---------\n\n");	
			printf("\t\t\t1)ALTA\n\t\t\t2)BAJA\n\t\t\t3)CAMBIO\n\t\t\t4)REGRESAR AL MENU PRINCIPAL\n\n");
		}
	}while(numerovalidado<1||numerovalidado>4||b==0);
		
	switch(numerovalidado)
	{
		case 1:
				do
				{
					system ("cls");
		   			printf("\n\n\t\t\t---------MENU EMPRESA/ALTAS---------\n");	
		   			printf("\n\t\t\t     EMPRESA REGISTRADA NO.%d\n\n",i+1);
		   			
					do //PEDIR ID(LO CREA EL USUARIO)
					{
						bandera1=0;
						printf("\t\t\t=>CREE UN ID:"); //PEDIR ID DE EMPRESA//
						fflush(stdin);
		   				gets(EM[i].ID);
		   				strcpy(z,EM[i].ID);
		   				fflush(stdin);
		   				b=strlen(EM[i].ID);
		   				a=VALIDAR_CONTRASENIA(EM[i].ID);
		   				for(y=0;y<i;y++)
			   			{
			   				strupr(z);
			   				strupr(EM[y].ID);
			   				if(strcmp(z,EM[y].ID)==0)
							{
								bandera1++;
							}
						}
						if(a!=0||b==0||bandera1>0)
						{
							system ("cls");
		   					printf("\n\n\t\t\t---------MENU EMPRESA/ALTAS---------\n");	
		   					printf("\n\t\t\t     EMPRESA REGISTRADA NO.%d\n\n",i+1);
						}
		   			}while(a!=0||b==0||bandera1>0);
		   			
					do //PEDIR NOMBRE DE EMPRESA
		   			{
		   				bandera1=0;
		   				printf("\n\t\t\t=>NOMBRE DE LA EMPRESA:");
		   				fflush(stdin);
		   				gets(EM[i].NAME);
		   				strcpy(z,EM[i].NAME);
		   				fflush(stdin);
		   				b=strlen(EM[i].NAME);
		   				a=VALIDAR_LETRAS_CON_NUMEROS(EM[i].NAME);
		   				for(y=0;y<i;y++)
			   			{
			   				strupr(z);
			   				strupr(EM[y].NAME);
			   				if(strcmp(z,EM[y].NAME)==0)
							{
								bandera1++;
							}
						}
						if(a!=0||b==0||bandera1>0)
						{
							system ("cls");
		   					printf("\n\n\t\t\t---------MENU EMPRESA/ALTAS---------\n");	
		   					printf("\n\t\t\t     EMPRESA REGISTRADA NO.%d\n\n",i+1);
		   					printf("\t\t\t=>CREE UN ID:%s\n",EM[i].ID);
						}
					}while(a!=0||b==0||bandera1>0);
						
					do //PEDIR RFC DE EMPRESA//
			 		{
			 			bandera1=0;
						printf("\t\t\t=>RFC DE LA EMPRESA:");
		   				fflush(stdin);
		   				gets(EM[i].RFC);
		   				strcpy(z,EM[i].RFC);
						fflush(stdin);
			   			b=strlen(EM[i].RFC);
	   					a=VALIDAR_CONTRASENIA(EM[i].RFC);
			   			for(y=0;y<i;y++)
			   			{
			   				if(strcmp(z,EM[y].RFC)==0)
							{
								bandera1++;
							}
						}
						if(a!=0||b==0||bandera1>0)
						{
							system ("cls");
		   					printf("\n\n\t\t\t---------MENU EMPRESA/ALTAS---------\n");	
		   					printf("\n\t\t\t     EMPRESA REGISTRADA NO.%d\n\n",i+1);
		   					printf("\t\t\t=>CREE UN ID:%s",EM[i].ID);
		   					printf("\n\n\t\t\t=>NOMBRE DE LA EMPRESA:%s\n",EM[i].NAME);
						}
	   				}while(a!=0||b==0||bandera1>0);
	   					
	   				do //PEDIR DIRECCION DE LA EMPRESA//
	   				{
	   					printf("\t\t\t=>DIRECCION DE LA EMPRESA:");
	   					fflush(stdin);
	   					gets(EM[i].DIR);
	   					b=strlen(EM[i].DIR);
	   					if(b==0)
	   					{
	   						system ("cls");
		   					printf("\n\n\t\t\t---------MENU EMPRESA/ALTAS---------\n");	
		   					printf("\n\t\t\t     EMPRESA REGISTRADA NO.%d\n\n",i+1);
		   					printf("\t\t\t=>CREE UN ID:%s\n\n",EM[i].ID);
		   					printf("\t\t\t=>NOMBRE DE LA EMPRESA:%s\n",EM[i].NAME);
		   					printf("\t\t\t=>RFC DE LA EMPRESA:%s\n",EM[i].RFC);
						}
					}while(b==0);
	   		
	   				do //PEDIR TELEFONO DE LA EMPRESA//
	   				{
	   					bandera1=0;
						printf("\t\t\t=>TELEFONO DE LA EMPRESA:");
						fflush(stdin);
		   				gets(EM[i].PHONE);
		   				strcpy(z,EM[i].PHONE);
	   					fflush(stdin);
	   					b=strlen(EM[i].PHONE);
	   					a=VALIDAR_TELEFONO(EM[i].PHONE);
	   					for(y=0;y<i;y++)
			   			{
			   				if(strcmp(z,EM[y].PHONE)==0)
							{
								bandera1++;
							}
						}
						if(a!=0||b==0||bandera1>0||b<10)
						{
							system("cls");
							printf("\n\n\t\t\t---------MENU EMPRESA/ALTAS---------\n");	
		   					printf("\n\t\t\t     EMPRESA REGISTRADA NO.%d\n\n",i+1);
		   					printf("\t\t\t=>CREE UN ID:%s\n\n",EM[i].ID);
		   					printf("\t\t\t=>NOMBRE DE LA EMPRESA:%s\n",EM[i].NAME);
		   					printf("\t\t\t=>RFC DE LA EMPRESA:%s\n",EM[i].RFC);
		   					printf("\t\t\t=>DIRECCION DE LA EMPRESA:%s\n",EM[i].DIR);
						}
					}while(a!=0||b==0||bandera1>0||b<10);
				
					do //PEDIR NOMBRE DE CONTACTO//
					{
						printf("\n\t\t\t=>NOMBRE DE CONTACTO:");
						fflush(stdin);
	   					gets(EM[i].CONTACTO);
	   					fflush(stdin);
	   					b=strlen(EM[i].CONTACTO);
	   					a=VALIDAR_SOLO_LETRAS(EM[i].CONTACTO);
	   					if(a!=0||b==0)
	   					{
	   						system("cls");
							printf("\n\n\t\t\t---------MENU EMPRESA/ALTAS---------\n");	
		   					printf("\n\t\t\t     EMPRESA REGISTRADA NO.%d\n\n",i+1);
		   					printf("\t\t\t=>CREE UN ID:%s\n\n",EM[i].ID);
		   					printf("\t\t\t=>NOMBRE DE LA EMPRESA:%s\n",EM[i].NAME);
		   					printf("\t\t\t=>RFC DE LA EMPRESA:%s\n",EM[i].RFC);
		   					printf("\t\t\t=>DIRECCION DE LA EMPRESA:%s\n",EM[i].DIR);
		   					printf("\t\t\t=>TELEFONO DE LA EMPRESA:%s\n",EM[i].PHONE);
						}
	   				}while(a!=0||b==0);
	   					
	   				do //PEDIR CORREO DE CONTACTO//
	   				{
	   					bandera1=0;
	   					printf("\t\t\t=>CORREO DE CONTACTO:");
	   					gets(EM[i].EMAIL);
	   					fflush(stdin);
	   					b=strlen(EM[i].EMAIL);
	   					a=VALIDAR_CORREO(EM[i].EMAIL);
	   					if(a!=0||b==0)
	   					{
	   						system("cls");
							printf("\n\n\t\t\t---------MENU EMPRESA/ALTAS---------\n");	
		   					printf("\n\t\t\t     EMPRESA REGISTRADA NO.%d\n\n",i+1);
		   					printf("\t\t\t=>CREE UN ID:%s\n\n",EM[i].ID);
		   					printf("\t\t\t=>NOMBRE DE LA EMPRESA:%s\n",EM[i].NAME);
		   					printf("\t\t\t=>RFC DE LA EMPRESA:%s\n",EM[i].RFC);
		   					printf("\t\t\t=>DIRECCION DE LA EMPRESA:%s\n",EM[i].DIR);
		   					printf("\t\t\t=>TELEFONO DE LA EMPRESA:%s\n",EM[i].PHONE);
		   					printf("\n\t\t\t=>NOMBRE DE CONTACTO:%s\n",EM[i].CONTACTO);
						}
	   				}while(a!=0||b==0);
	   				
	   				do //PEDIR SI SE DESEA AGREGAR OTRA EMPRESA//
					{
						do
						{
							printf("\n\t\t\t=>LOS DATOS INGRESADOS SON CORRECTOS?(1/SI 2/NO):");
							fflush(stdin);
							gets(op1);
							b=VALIDAR_SOLO_NUMEROS(op1);
							if(b==0||numerovalidado<1||numerovalidado>2)
							{
								system("cls");
								printf("\n\n\t\t\t---------MENU EMPRESA/ALTAS---------\n");	
			   					printf("\n\t\t\t     EMPRESA REGISTRADA NO.%d\n\n",i+1);
			   					printf("\t\t\t=>CREE UN ID:%s\n\n",EM[i].ID);
			   					printf("\t\t\t=>NOMBRE DE LA EMPRESA:%s\n",EM[i].NAME);
			   					printf("\t\t\t=>RFC DE LA EMPRESA:%s\n",EM[i].RFC);
			   					printf("\t\t\t=>DIRECCION DE LA EMPRESA:%s\n",EM[i].DIR);
			   					printf("\t\t\t=>TELEFONO DE LA EMPRESA:%s\n",EM[i].PHONE);
			   					printf("\n\t\t\t=>NOMBRE DE CONTACTO:%s\n",EM[i].CONTACTO);
			   					printf("\t\t\t=>CORREO DE CONTACTO:%s\n",EM[i].EMAIL);
							}
						}while(b==0);
						numerovalidado=atoi(op1);
						
						if(numerovalidado==1)
						{
							do //PEDIR SI SE DESEA AGREGAR OTRA EMPRESA//
							{
								do
								{
									printf("\t\t\t=>DESEA AGREGAR OTRA EMPRESA?(1/SI 2/NO):");
									fflush(stdin);
									gets(op1);
									b=VALIDAR_SOLO_NUMEROS(op1);
									if(b==0||numerovalidado<1||numerovalidado>2)
									{
										system("cls");
										printf("\n\n\t\t\t---------MENU EMPRESA/ALTAS---------\n");	
			   							printf("\n\t\t\t     EMPRESA REGISTRADA NO.%d\n\n",i+1);
			   							printf("\t\t\t=>CREE UN ID:%s\n\n",EM[i].ID);
			   							printf("\t\t\t=>NOMBRE DE LA EMPRESA:%s\n",EM[i].NAME);
			   							printf("\t\t\t=>RFC DE LA EMPRESA:%s\n",EM[i].RFC);
			   							printf("\t\t\t=>DIRECCION DE LA EMPRESA:%s\n",EM[i].DIR);
			   							printf("\t\t\t=>TELEFONO DE LA EMPRESA:%s\n",EM[i].PHONE);
			   							printf("\n\t\t\t=>NOMBRE DE CONTACTO:%s\n",EM[i].CONTACTO);
			   							printf("\t\t\t=>CORREO DE CONTACTO:%s\n\n",EM[i].EMAIL);
			   							printf("\t\t\t=>LOS DATOS INGRESADOS SON CORRECTOS?(1/SI 2/NO):%s\n",op1);
									}
								}while(b==0);
								numerovalidado=atoi(op1);
								if(numerovalidado==1)
								{
									i++;
								}
								else
								{
									if(numerovalidado==2)
									{
										i++;
										system("cls");
										MENU();
									}
								}
							}while(numerovalidado<1||numerovalidado>2);
						}
						else
						{
							if(numerovalidado==2)
							{
								system("cls");
								numerovalidado=1;
							}
						}
					}while(numerovalidado<1||numerovalidado>2);
	   			}while(numerovalidado==1);	
	   	break;
	   			
	   	case 2:
	   			if(i>=1)
	   			{
	   				system("cls");
					printf("\n\n\t\t\t---------MENU EMPRESA/BAJAS---------\n\n");	
					for(x=0;x<i;x++)
					{
						printf("\t\t\t%d)%s\n",x,EM[x].NAME);
					}
		
					do
					{
						printf("\n\t\t\t=>NUMERO DE EMPRESA A ELIMINAR:");
						fflush(stdin);
						gets(op1);
						b=VALIDAR_SOLO_NUMEROS(op1);
						eliminar=atoi(op1);
						if(eliminar<i||eliminar>i-1||b==0)
						{
							system("cls");
							printf("\n\n\t\t\t---------MENU EMPRESA/BAJAS---------\n\n");	
							for(x=0;x<i;x++)
							{
								printf("\t\t\t%d) %s\n",x,EM[x].NAME);
							}
						}
					}while(eliminar<i-i||eliminar>i-1||b==0);
				
					system("cls");
					printf("\n\n\t\t\tSE ELIMINARAN LA EMPRESA CUYOS DATOS SON:\n\n");
					for(x=0;x<i;x++)
					{
						if(x==eliminar)
						{
							do
							{
								printf("\t\t\t=>ID:%s\n\n",EM[x].ID);
			   					printf("\t\t\t=>NOMBRE DE LA EMPRESA:%s\n",EM[x].NAME);
			   					printf("\t\t\t=>RFC DE LA EMPRESA:%s\n",EM[x].RFC);
			   					printf("\t\t\t=>DIRECCION DE LA EMPRESA:%s\n",EM[x].DIR);
			   					printf("\t\t\t=>TELEFONO DE LA EMPRESA:%s\n",EM[x].PHONE);
			   					printf("\n\t\t\t=>NOMBRE DE CONTACTO:%s\n",EM[x].CONTACTO);
			   					printf("\t\t\t=>CORREO DE CONTACTO:%s\n\n",EM[x].EMAIL);
								printf("\n\t\t\tELIMINAR?(1/SI 2/NO):");
								fflush(stdin);
								gets(op1);
								b=VALIDAR_SOLO_NUMEROS(op1);
								numerovalidado=atoi(op1);
								if(b==0||numerovalidado<1||numerovalidado>2)
								{
									system("cls");
									printf("\n\n\t\t\tSE ELIMINARAN LA EMPRESA CUYOS DATOS SON:\n\n");
								}
								else
								{
									if(numerovalidado==1)
									{
										for(x=0;x<i;x++)
										{
											if(x==eliminar)
											{
												while(x<i)
												{
													strcpy(EM[x].ID,EM[x+1].ID);
													
													strcpy(EM[x].NAME,EM[x+1].NAME);
													strcpy(EM[x].PHONE,EM[x+1].PHONE);
													strcpy(EM[x].RFC,EM[x+1].RFC);
													strcpy(EM[x].DIR,EM[x+1].DIR);
													
													strcpy(EM[x].CONTACTO,EM[x+1].CONTACTO);
													strcpy(EM[x].EMAIL,EM[x+1].EMAIL);
													x++;
												}
												break;
										  	}
										}
										i=i-1;
										system("cls");
										printf("\n\n\n\n\n\n\n\n\n\n\t\t\t    ELIMINADA CON EXITO!\n\n");
										printf("\t\t\t  SE LE REGRESARA AL MENU");
										getch();
										system("cls");
										MENU();
									}
									else
									{
										if(numerovalidado==2)
										{
											system("cls");
											printf("\n\n\n\n\n\n\n\n\n\n\t\t\t  SE LE REGRESARA AL MENU");
											system("cls");
											MENU();
										}
									}
								}
							}while(numerovalidado<1||numerovalidado>2||b==0);
						}	
					}
				}
				else
				{
					if(i<=0)
					{
						system("cls");
						printf("\n\n\n\n\n\n\n\n\n\n\t\tNO HAY EMPRESAS REGISTRADAS PARA ELIMINAR:(");
						getch();
						MENU();
					}
				}
		break;
		
		case 3:
				if(i>=1)
	   			{
	   				system("cls");
					printf("\n\n\t\t\t---------MENU EMPRESA/CAMBIOS---------\n\n");	
					for(x=0;x<i;x++)
					{
						printf("\t\t\t%d)%s\n",x,EM[x].NAME);
					}
		
					do
					{
						printf("\n\t\t\t=>NUMERO DE EMPRESA A MODIFICAR:");
						fflush(stdin);
						gets(op1);
						b=VALIDAR_SOLO_NUMEROS(op1);
						cambio=atoi(op1);
						if(cambio<i||cambio>i-1||b==0)
						{
							system("cls");
							printf("\n\n\t\t\t---------MENU EMPRESA/BAJAS---------\n\n");	
							for(x=0;x<i;x++)
							{
								printf("\t\t\t%d) %s\n",x,EM[x].NAME);
							}
						}
					}while(cambio<i-i||cambio>i-1||b==0);
				
					system("cls");
					printf("\n\n\t\t\tSE MODIFICARA LA EMPRESA CUYOS DATOS SON:\n\n");
					
					for(x=0;x<i;x++)
					{
						if(x==cambio)
						{
							do
							{
								printf("\t\t\t=>ID:%s\n\n",EM[x].ID);
			   					printf("\t\t\t=>NOMBRE DE LA EMPRESA:%s\n",EM[x].NAME);
			   					printf("\t\t\t=>RFC DE LA EMPRESA:%s\n",EM[x].RFC);
			   					printf("\t\t\t=>DIRECCION DE LA EMPRESA:%s\n",EM[x].DIR);
			   					printf("\t\t\t=>TELEFONO DE LA EMPRESA:%s\n",EM[x].PHONE);
			   					printf("\n\t\t\t=>NOMBRE DE CONTACTO:%s\n",EM[x].CONTACTO);
			   					printf("\t\t\t=>CORREO DE CONTACTO:%s\n\n",EM[x].EMAIL);
								printf("\n\t\t\tMODIFICAR?(1/SI 2/NO):");
								fflush(stdin);
								gets(op1);
								b=VALIDAR_SOLO_NUMEROS(op1);
								numerovalidado=atoi(op1);
								if(b==0||numerovalidado<1||numerovalidado>2)
								{
									system("cls");
									printf("\n\n\t\t\tSE MODIFICARA LA EMPRESA CUYOS DATOS SON:\n\n");
								}
							}while(numerovalidado<1||numerovalidado>2||b==0);
						}	
					} 
					
					if(numerovalidado==1)
					{
						system("cls");
						printf("\n\n\t\t\t---------[MODIFICANDO...]---------\n\n");	
						for(x=i;x>=0;x--)
						{
							if(x==cambio)
							{
								do //PEDIR ID(LO CREA EL USUARIO)
								{
									bandera1=0;
									printf("\t\t\t=>ID:"); //PEDIR ID DE EMPRESA//
									fflush(stdin);
					   				gets(EM[x].ID);
					   				strcpy(z,EM[x].ID);
					   				fflush(stdin);
					   				b=strlen(EM[x].ID);
					   				a=VALIDAR_CONTRASENIA(EM[x].ID);
		
					   				for(y=i;y>=0;y--)
						   			{
						   				strupr(z);
						   				strupr(EM[y].ID);
						   				if(strcmp(z,EM[y].ID)==0)
										{
											bandera1++;
										}
									}
									if(a!=0||b==0||bandera1>1)
									{
										system("cls");
										printf("\n\n\t\t\t---------[MODIFICANDO...]---------\n\n");	
									}
					   			}while(a!=0||b==0||bandera1>1);
					   			
								do //PEDIR NOMBRE DE EMPRESA
					   			{
					   				bandera1=0;
					   				printf("\n\t\t\t=>NOMBRE DE LA EMPRESA:");
					   				fflush(stdin);
					   				gets(EM[x].NAME);
					   				strcpy(z,EM[x].NAME);
					   				fflush(stdin);
					   				b=strlen(EM[x].NAME);
					   				a=VALIDAR_LETRAS_CON_NUMEROS(EM[x].NAME);
					   				for(y=i;y>=0;y--)
						   			{
						   				strupr(z);
						   				strupr(EM[y].NAME);
						   				if(strcmp(z,EM[y].NAME)==0)
										{
											bandera1++;
										}
									}
									if(a!=0||b==0||bandera1>1)
									{
										system("cls");
										printf("\n\n\t\t\t---------[MODIFICANDO...]---------\n\n");	
					   					printf("\t\t\t=>ID:%s\n",EM[x].ID);
									}
								}while(a!=0||b==0||bandera1>1);
									
								do //PEDIR RFC DE EMPRESA//
						 		{
						 			bandera1=0;
									printf("\t\t\t=>RFC DE LA EMPRESA:");
					   				fflush(stdin);
					   				gets(EM[x].RFC);
					   				strcpy(z,EM[x].RFC);
									fflush(stdin);
						   			b=strlen(EM[x].RFC);
				   					a=VALIDAR_CONTRASENIA(EM[x].RFC);
						   			for(y=i;y>=0;y--)
						   			{
						   				if(strcmp(z,EM[y].RFC)==0)
										{
											bandera1++;
										}
									}
									if(a!=0||b==0||bandera1>1)
									{
										system("cls");
										printf("\n\n\t\t\t---------[MODIFICANDO...]---------\n\n");	
					   					printf("\t\t\t=>ID:%s",EM[x].ID);
					   					printf("\n\n\t\t\t=>NOMBRE DE LA EMPRESA:%s\n",EM[x].NAME);
									}
				   				}while(a!=0||b==0||bandera1>1);
				   					
				   				do //PEDIR DIRECCION DE LA EMPRESA//
				   				{
				   					printf("\t\t\t=>DIRECCION DE LA EMPRESA:");
				   					fflush(stdin);
				   					gets(EM[x].DIR);
				   					b=strlen(EM[x].DIR);
				   					if(b==0)
				   					{
				   						system("cls");
										printf("\n\n\t\t\t---------[MODIFICANDO...]---------\n\n");	
					   					printf("\t\t\t=>ID:%s\n\n",EM[x].ID);
					   					printf("\t\t\t=>NOMBRE DE LA EMPRESA:%s\n",EM[x].NAME);
					   					printf("\t\t\t=>RFC DE LA EMPRESA:%s\n",EM[x].RFC);
									}
								}while(b==0);
				   		
				   				do //PEDIR TELEFONO DE LA EMPRESA//
				   				{
				   					bandera1=0;
									printf("\t\t\t=>TELEFONO DE LA EMPRESA:");
									fflush(stdin);
					   				gets(EM[x].PHONE);
					   				strcpy(z,EM[x].PHONE);
				   					fflush(stdin);
				   					b=strlen(EM[x].PHONE);
				   					a=VALIDAR_TELEFONO(EM[x].PHONE);
				   					for(y=i;y>=0;y--)
						   			{
						   				if(strcmp(z,EM[y].PHONE)==0)
										{
											bandera1++;
										}
									}
									if(a!=0||b==0||bandera1>1||b<10)
									{
										system("cls");
										printf("\n\n\t\t\t---------[MODIFICANDO...]---------\n\n");	
					   					printf("\t\t\t=>ID:%s\n\n",EM[x].ID);
					   					printf("\t\t\t=>NOMBRE DE LA EMPRESA:%s\n",EM[x].NAME);
					   					printf("\t\t\t=>RFC DE LA EMPRESA:%s\n",EM[x].RFC);
					   					printf("\t\t\t=>DIRECCION DE LA EMPRESA:%s\n",EM[x].DIR);
									}
								}while(a!=0||b==0||bandera1>1||b<10);
							
								do //PEDIR NOMBRE DE CONTACTO//
								{
									printf("\n\t\t\t=>NOMBRE DE CONTACTO:");
									fflush(stdin);
				   					gets(EM[x].CONTACTO);
				   					fflush(stdin);
				   					b=strlen(EM[x].CONTACTO);
				   					a=VALIDAR_SOLO_LETRAS(EM[x].CONTACTO);
				   					if(a!=0||b==0)
				   					{
				   						system("cls");
										printf("\n\n\t\t\t---------[MODIFICANDO...]---------\n\n");	
					   					printf("\t\t\t=>ID:%s\n\n",EM[x].ID);
					   					printf("\t\t\t=>NOMBRE DE LA EMPRESA:%s\n",EM[x].NAME);
					   					printf("\t\t\t=>RFC DE LA EMPRESA:%s\n",EM[x].RFC);
					   					printf("\t\t\t=>DIRECCION DE LA EMPRESA:%s\n",EM[x].DIR);
					   					printf("\t\t\t=>TELEFONO DE LA EMPRESA:%s\n",EM[x].PHONE);
									}
				   				}while(a!=0||b==0);
				   					
				   				do //PEDIR CORREO DE CONTACTO//
				   				{
				   					bandera1=0;
				   					printf("\t\t\t=>CORREO DE CONTACTO:");
				   					gets(EM[x].EMAIL);
				   					fflush(stdin);
				   					b=strlen(EM[x].EMAIL);
				   					a=VALIDAR_CORREO(EM[x].EMAIL);
				   					if(a!=0||b==0)
				   					{
				   						system("cls");
										printf("\n\n\t\t\t---------[MODIFICANDO...]---------\n\n");	
					   					printf("\t\t\t=>CREE UN ID:%s\n\n",EM[x].ID);
					   					printf("\t\t\t=>NOMBRE DE LA EMPRESA:%s\n",EM[x].NAME);
					   					printf("\t\t\t=>RFC DE LA EMPRESA:%s\n",EM[x].RFC);
					   					printf("\t\t\t=>DIRECCION DE LA EMPRESA:%s\n",EM[x].DIR);
					   					printf("\t\t\t=>TELEFONO DE LA EMPRESA:%s\n",EM[x].PHONE);
					   					printf("\n\t\t\t=>NOMBRE DE CONTACTO:%s\n",EM[x].CONTACTO);
									}
				   				}while(a!=0||b==0);
				   				
				   				printf("\n\t\t\t\tGUARDANDO...");
				   				getch();
				   				system("cls");
								printf("\n\n\n\n\n\n\n\n\n\n\t\t     EMPRESA MODIFICADA CORRECTAMENTE:)");
								printf("\n\n\n\n\n\n\n\n\n\n\t\t\t  SE LE REGRESARA AL MENU");
				   				getch();
								MENU();
				   			}
						}
					}
					else
					{
						if(numerovalidado==2)
						{
							system("cls");
							MENU();
						}
					}
				}
				else
				{
					if(i<1)
					{
						system("cls");
						printf("\n\n\n\n\n\n\n\n\n\n\t\tNO HAY EMPRESAS REGISTRADAS PARA MODIFICAR:(");
						getch();
						MENU();
					}	
				}
		break;
		
		case 4:
				system("cls");
				MENU();
		break;			
	}
}

void SUBMENU_PERFIL() //FUNCION ENCARGADA DE ACCIONES EN PERFILES(INCOMPLETO)//
{
	int x=0,y=0,bandera1=0,eliminar=0,cambio=0;
	int a=0,b=0,numerovalidado=0;
	char op1[' '],z[' '],cantidad[' '],op2[' '];
	char ID[10],NAME[35],DESC[15],ID_EM[15];
	int CANT,STAT,c=0;
	char estatus[' '];
	
	system("cls");
	printf("\n\n\t\t\t---------MENU PERFIL---------\n\n");	
	printf("\t\t\t1)ALTA\n\t\t\t2)BAJA\n\t\t\t3)CAMBIO\n\t\t\t4)REGRESAR AL MENU PRINCIPAL\n\n");
	do
	{
		printf("\t\t        ==>OPCION A ELEGIR: ");
		fflush(stdin);
		gets(op1);
		b=VALIDAR_SOLO_NUMEROS(op1);
		numerovalidado=atoi(op1);
	   	if(b==0||numerovalidado<1||numerovalidado>4)
		{
		    system("cls");
		    printf("\n\n\t\t\t---------MENU PERFIL---------\n\n");	
			printf("\t\t\t1)ALTA\n\t\t\t2)BAJA\n\t\t\t3)CAMBIO\n\t\t\t4)REGRESAR AL MENU PRINCIPAL\n\n");
		}
	}while(numerovalidado<1||numerovalidado>4||b==0);
		
	switch(numerovalidado)
	{
		case 1:
				do
				{
					system ("cls");
		   			printf("\n\n\t\t\t---------MENU PERFIL/ALTAS---------\n");	
		   			printf("\n\t\t\t     PERFIL REGISTRADO NO.%d\n\n",j+1);
		   			
					do //PEDIR ID DE PERFIL
					{
						bandera1=0;
						printf("\t\t\t=>CREE UN ID:");
						fflush(stdin);
		   				gets(PE[j].ID);
		   				strcpy(z,PE[j].ID);
		   				fflush(stdin);
		   				b=strlen(PE[j].ID);
		   				a=VALIDAR_CONTRASENIA(PE[j].ID);
		   				for(y=0;y<j;y++)
			   			{
			   				strupr(z);
			   				strupr(PE[y].ID);
			   				if(strcmp(z,PE[y].ID)==0)
							{
								bandera1++;
							}
						}
						if(a!=0||b==0||bandera1>0)
						{
							system ("cls");
		   					printf("\n\n\t\t\t---------MENU PERFIL/ALTAS---------\n");	
		   					printf("\n\t\t\t     PERFIL REGISTRADO NO.%d\n\n",j+1);
						}
		   			}while(a!=0||b==0||bandera1>0);
		   			
					do //PEDIR NOMBRE DEL PERFIL
		   			{
		   			
		   				printf("\n\t\t\t=>NOMBRE DEL PERFIL:");
		   				fflush(stdin);
		   				gets(PE[j].NAME);
		   				strcpy(z,PE[j].NAME);
		   				fflush(stdin);
		   				b=strlen(PE[j].NAME);
		   				a=VALIDAR_LETRAS_CON_NUMEROS(PE[j].NAME);
						if(a!=0||b==0||bandera1>0)
						{
							system ("cls");
		   					printf("\n\n\t\t\t---------MENU PERFIL/ALTAS---------\n");	
		   					printf("\n\t\t\t     PERFIL REGISTRADO NO.%d\n\n",j+1);
		   					printf("\t\t\t=>CREE UN ID:%s\n",PE[j].ID);
						}
					}while(a!=0||b==0||bandera1>0);
					
					do	//PEDIR DESCRIPCION//
					{
						printf("\t\t\t=>DESCRIPCION:");
						fflush(stdin);
						gets(PE[j].DESC);
						strcpy(z,PE[j].DESC);
						b=strlen(PE[j].DESC);
						a=VALIDAR_LETRAS_CON_NUMEROS(PE[j].DESC);
						if(a!=0||b==0)
						{
							system ("cls");
		   					printf("\n\n\t\t\t---------MENU PERFIL/ALTAS---------\n");	
		   					printf("\n\t\t\t     PERFIL REGISTRADO NO.%d\n\n",j+1);
		   					printf("\t\t\t=>CREE UN ID:%s\n",PE[j].ID);	
		   					printf("\n\t\t\t=>NOMBRE DEL PERFIL:%s\n",PE[j].NAME);
						}
					}while(a!=0||b==0);	
					
					do	//PEDIR ESTATUS//
	   				{
	   					printf("\n\t\t\t\t1)DISPONIBLE\n\t\t\t\t2)ASIGNADO\n\n");
	   					printf("\t\t\t=>ESTATUS:");
	   					fflush(stdin);
	   					gets(op2);
	   					b=strlen(op2);
	   					a=VALIDAR_SOLO_NUMEROS(op2);
	   					c=atoi(op2);
	   					
	   					if(a==0||b==0||(c<1||c>2))
	   					{
						   	system ("cls");
		   					printf("\n\n\t\t\t---------MENU PERFIL/ALTAS---------\n");	
		   					printf("\n\t\t\t     PERFIL REGISTRADO NO.%d\n\n",j+1);
		   					printf("\t\t\t=>CREE UN ID:%s\n",PE[j].ID);	
		   					printf("\n\t\t\t=>NOMBRE DEL PERFIL:%s\n",PE[j].NAME);
		   					printf("\t\t\t=>DESCRIPCION:%s\n",PE[j].DESC);
	   					}
	   					else
	   					{
	   						PE[j].STAT=atoi(op1);	
						}
	   				}while(a==0||b==0||c<1||c>2);
	   		
	   				do	//PEDIR CANTIDAD//
					{
						printf("\t\t\t=>CANTIDAD:");
						fflush(stdin);
						gets(cantidad);
						a=VALIDAR_SOLO_NUMEROS(cantidad);
						if(a!=0)
						{
							PE[j].CANT=atoi(cantidad);	
						}
						else
						{
							system ("cls");
		   					printf("\n\n\t\t\t---------MENU PERFIL/ALTAS---------\n");	
		   					printf("\n\t\t\t     PERFIL REGISTRADO NO.%d\n\n",j+1);
		   					printf("\t\t\t=>CREE UN ID:%s\n",PE[j].ID);	
		   					printf("\n\t\t\t=>NOMBRE DEL PERFIL:%s\n",PE[j].NAME);
		   					printf("\t\t\t=>DESCRIPCION:%s\n",PE[j].DESC);
		   					printf("\n\t\t\t\t1)DISPONIBLE\n\t\t\t\t2)ASIGNADO\n\n");
	   						printf("\t\t\t=>ESTATUS:%d\n",PE[j].STAT);
						}
					}while(a==0);
					
					do //PEDIR ID DE EMPRESA EXISTENTE
					{
						bandera1=0;
						printf("\n\t\t\t=>ID DE EMPRESA:");
		   				gets(PE[j].ID_EM);
		   				fflush(stdin);
		   				b=strlen(PE[j].ID_EM);
		   				a=VALIDAR_CONTRASENIA(PE[j].ID_EM);
		   				for(y=0;y<i;y++)
			   			{
							strupr(PE[j].ID_EM);
			   				strupr(EM[y].ID);
			   				if(strcmp(PE[j].ID_EM,EM[y].ID)==0)
							{
								bandera1++;
							}
						}
						if(a!=0||b==0||bandera1<=0)
						{
							system ("cls");
							printf("\n\n\n\n\n\n\n\n\n\n\t\t\tLA EMPRESA NO EXISTE:(");
							
							do
							{
								printf("\n\n\t\t  DESEA VOLVER AL MENU?(1/SI 2/NO):");
								fflush(stdin);
								gets(op1);
								b=VALIDAR_SOLO_NUMEROS(op1);
								numerovalidado=atoi(op1);
								if(b==0||numerovalidado<1||numerovalidado>2)
								{
									system ("cls");
									printf("\n\n\n\n\n\n\n\n\n\n\t\t\tLA EMPRESA NO EXISTE:(");
								}
								if(numerovalidado==1)
								{
									system("cls");
									MENU();
								}
								else
								{
									if(numerovalidado==2)
									{
										system ("cls");
		   								printf("\n\n\t\t\t---------MENU PERFIL/ALTAS---------\n");	
					   					printf("\n\t\t\t     PERFIL REGISTRADO NO.%d\n\n",j+1);
					   					printf("\t\t\t=>CREE UN ID:%s\n",PE[j].ID);	
					   					printf("\n\t\t\t=>NOMBRE DEL PERFIL:%s\n",PE[j].NAME);
					   					printf("\t\t\t=>DESCRIPCION:%s\n",PE[j].DESC);
					   					printf("\n\t\t\t\t1)DISPONIBLE\n\t\t\t\t2)ASIGNADO\n\n");
				   						printf("\t\t\t=>ESTATUS:%d\n",PE[j].STAT);
				   						printf("\t\t\t=>CANTIDAD:%d\n",PE[j].CANT);
									}
								}
							}while(b==0||numerovalidado<1||numerovalidado>2);
						}
		   			}while(a!=0||b==0||bandera1<=0);
					
	   				do //PEDIR SI LO INGRESADO ES CORRECTO//
					{
						do
						{
							printf("\n\n\t\t\t=>LOS DATOS INGRESADOS SON CORRECTOS?(1/SI 2/NO):");
							fflush(stdin);
							gets(op1);
							fflush(stdin);
							b=VALIDAR_SOLO_NUMEROS(op1);
							numerovalidado=atoi(op1);
							if(b==0||numerovalidado<1||numerovalidado>2)
							{
								system ("cls");
		   						printf("\n\n\t\t\t---------MENU PERFIL/ALTAS---------\n");	
					   			printf("\n\t\t\t     PERFIL REGISTRADO NO.%d\n\n",j+1);
					   			printf("\t\t\t=>CREE UN ID:%s\n",PE[j].ID);	
					   			printf("\n\t\t\t=>NOMBRE DEL PERFIL:%s\n",PE[j].NAME);
					   			printf("\t\t\t=>DESCRIPCION:%s\n",PE[j].DESC);
					   			printf("\n\t\t\t\t1)DISPONIBLE\n\t\t\t\t2)ASIGNADO\n\n");
				   				printf("\t\t\t=>ESTATUS:%d\n",PE[j].STAT);
				   				printf("\t\t\t=>CANTIDAD:%d\n",PE[j].CANT);
				   				printf("\n\t\t\t=>ID DE EMPRESA:%s\n",PE[j].ID_EM);
							}
						}while(b==0||numerovalidado<1||numerovalidado>2);
						
						if(numerovalidado==1)
						{
							do //PEDIR SI SE DESEA AGREGAR OTRO PERFIL//
							{
								do
								{
									printf("\t\t\t=>DESEA AGREGAR OTRO PERFIL?(1/SI 2/NO):");
									fflush(stdin);
									gets(op1);
									b=VALIDAR_SOLO_NUMEROS(op1);
									if(b==0||numerovalidado<1||numerovalidado>2)
									{
										system ("cls");
				   						printf("\n\n\t\t\t---------MENU PERFIL/ALTAS---------\n");	
							   			printf("\n\t\t\t     PERFIL REGISTRADO NO.%d\n\n",j+1);
							   			printf("\t\t\t=>CREE UN ID:%s\n",PE[j].ID);	
							   			printf("\n\t\t\t=>NOMBRE DEL PERFIL:%s\n",PE[j].NAME);
							   			printf("\t\t\t=>DESCRIPCION:%s\n",PE[j].DESC);
							   			printf("\n\t\t\t\t1)DISPONIBLE\n\t\t\t\t2)ASIGNADO\n\n");
						   				printf("\t\t\t=>ESTATUS:%d\n",PE[j].STAT);
						   				printf("\t\t\t=>CANTIDAD:%d\n",PE[j].CANT);
						   				printf("\n\t\t\t=>ID DE EMPRESA:%s\n",PE[j].ID_EM);
						   				printf("\n\n\t\t\t=>LOS DATOS INGRESADOS SON CORRECTOS?(1/SI 2/NO):%d\n",numerovalidado);
									}
								}while(b==0);
								numerovalidado=atoi(op1);
								if(numerovalidado==1)
								{
									j++;
								}
								else
								{
									if(numerovalidado==2)
									{
										j++;
										system("cls");
										MENU();
									}
								}
							}while(numerovalidado<1||numerovalidado>2);
						}
						else
						{
							if(numerovalidado==2)
							{
								system("cls");
								numerovalidado=1;
							}
						}
					}while(numerovalidado<1||numerovalidado>2);
	   			}while(numerovalidado==1);	
	   	break;
	   			
	   	case 2:
	   			if(j>=1)
	   			{
	   				system("cls");
					printf("\n\n\t\t\t---------MENU PERFIL/BAJAS---------\n\n");
						
					for(x=0;x<j;x++)
					{
						printf("\t\t\t%d)%s\n\n",x,PE[x].NAME);
						fflush(stdin);
					}
		
					do
					{
						printf("\n\t\t\t=>NUMERO DE PERFIL A ELIMINAR:");
						fflush(stdin);
						gets(op1);
						b=VALIDAR_SOLO_NUMEROS(op1);
						eliminar=atoi(op1);
						if(eliminar<j||eliminar>j-1||b==0)
						{
							system("cls");
							printf("\n\n\t\t\t---------MENU PERFIL/BAJAS---------\n\n");	
							for(x=0;x<j;x++)
							{
								printf("\t\t\t%d)%s\n",x,PE[x].NAME);
							}
						}
					}while(eliminar<j-j||eliminar>j-1||b==0);
				
					system("cls");
					printf("\n\n\t\t\tSE ELIMINARA EL PERFIL CUYOS DATOS SON:\n\n");
					for(x=0;x<j;x++)
					{
						if(x==eliminar)
						{
							do
							{
								printf("\t\t\t=>ID:%s\n",PE[x].ID);	
							   	printf("\n\t\t\t=>NOMBRE DEL PERFIL:%s\n",PE[x].NAME);
							   	printf("\t\t\t=>DESCRIPCION:%s\n",PE[x].DESC);
							   	if(PE[x].STAT==1)
							   	{
							   		printf("\t\t\t=>ESTATUS:DISPONIBLE\n");	
								}
								else
								{
									printf("\t\t\t=>ESTATUS:ASIGNADO\n");	
								}
						   		printf("\t\t\t=>CANTIDAD:%d\n",PE[x].CANT);
						   		printf("\n\t\t\t=>ID DE EMPRESA:%s\n",PE[x].ID_EM);
								printf("\n\n\n\t\t\tELIMINAR?(1/SI 2/NO):");
								fflush(stdin);
								gets(op1);
								b=VALIDAR_SOLO_NUMEROS(op1);
								numerovalidado=atoi(op1);
								if(b==0||numerovalidado<1||numerovalidado>2)
								{
									system("cls");
									printf("\n\n\t\t\tSE ELIMINARA EL PERFIL CUYOS DATOS SON:\n\n");
								}
								else
								{
									if(numerovalidado==1)
									{
										for(x=0;x<j;x++)
										{
											if(x==eliminar)
											{
												while(x<j)
												{
													strcpy(PE[x].ID,PE[x+1].ID);
													strcpy(PE[x].NAME,PE[x+1].NAME);
													strcpy(PE[x].DESC,PE[x+1].DESC);
													PE[x].STAT=PE[x+1].STAT;
													PE[x].CANT=PE[x+1].CANT;
													strcpy(PE[x].ID_EM,PE[x+1].ID_EM);
													x++;
												}
												break;
										  	}
										}
										j=j-1;
										system("cls");
										printf("\n\n\n\n\n\n\n\n\n\n\t\t\t    ELIMINADO CON EXITO!\n\n");
										printf("\t\t\t  SE LE REGRESARA AL MENU");
										getch();
										system("cls");
										MENU();
									}
									else
									{
										if(numerovalidado==2)
										{
											system("cls");
											printf("\n\n\n\n\n\n\n\n\n\n\t\t\t  SE LE REGRESARA AL MENU");
											getch();
											system("cls");
											MENU();
										}
									}
								}
							}while(numerovalidado<1||numerovalidado>2||b==0);
						}	
					}
				}
				else
				{
					if(j<=0)
					{
						system("cls");
						printf("\n\n\n\n\n\n\n\n\n\n\t\tNO HAY PERFILES REGISTRADAS PARA ELIMINAR:(");
						getch();
						MENU();
					}
				}
		break;
		
		case 3:
				if(j>=1)
	   			{
	   				system("cls");
					printf("\n\n\t\t\t---------MENU PERFIL/CAMBIOS---------\n\n");	
					
					for(x=0;x<j;x++)
					{
						printf("\t\t\t%d)%s\n",x,PE[x].NAME);
					}
		
					do
					{
						printf("\n\t\t\t=>NUMERO DE PERFIL A MODIFICAR:");
						fflush(stdin);
						gets(op1);
						b=VALIDAR_SOLO_NUMEROS(op1);
						cambio=atoi(op1);
						if(cambio<j||cambio>j-1||b==0)
						{
							system("cls");
							printf("\n\n\t\t\t---------MENU PERFIL/MODIFICAR---------\n\n");	
							for(x=0;x<j;x++)
							{
								printf("\t\t\t%d)%s\n",x,PE[x].NAME);
							}
						}
					}while(cambio<j-j||cambio>j-1||b==0);
				
					system("cls");
					printf("\n\n\t\t\tSE MODIFICARA EL PERFIL CUYOS DATOS SON:\n\n");
					
					for(x=0;x<j;x++)
					{
						if(x==cambio)
						{
							do
							{
								printf("\t\t\t=>ID:%s\n\n",PE[x].ID);
				   				printf("\t\t\t=>NOMBRE DEL PERFIL:%s\n",PE[x].NAME);
				   				printf("\t\t\t=>CANTIDAD:%d\n",PE[x].CANT);
				   				printf("\n\t\t\t=>ID DE EMPRESA:%s",PE[x].ID_EM);
								printf("\n\n\n\t\t\tMODIFICAR?(1/SI 2/NO):");
								fflush(stdin);
								gets(op1);
								b=VALIDAR_SOLO_NUMEROS(op1);
								numerovalidado=atoi(op1);
								if(b==0||numerovalidado<1||numerovalidado>2)
								{
									system("cls");
									printf("\n\n\t\t\tSE MODIFICARA EL PERFIL CUYOS DATOS SON:\n\n");
								}
							}while(numerovalidado<1||numerovalidado>2||b==0);
						}	
					} 
					
					if(numerovalidado==1)
					{
						system("cls");
						printf("\n\n\t\t\t---------[MODIFICANDO...]---------\n\n");	
						for(x=j;x>=0;x--)
						{
							if(x==cambio)
							{
								do //PEDIR ID DE PERFIL
								{
									bandera1=0;
									printf("\t\t\t=>ID:");
									fflush(stdin);
		   							gets(ID);
		   							strcpy(z,ID);
		   							fflush(stdin);
		   							b=strlen(ID);
		   							a=VALIDAR_CONTRASENIA(ID);
					   				for(y=j;y>=0;y--)
						   			{
						   				strupr(z);
						   				strupr(PE[y].ID);
						   				if(strcmp(z,PE[y].ID)==0)
										{
											bandera1++;
										}
									}
									if(a!=0||b==0||bandera1>1)
									{
										system("cls");
										printf("\n\n\t\t\t---------[MODIFICANDO...]---------\n\n");	
									}
					   			}while(a!=0||b==0||bandera1>1);
									
								do //PEDIR NOMBRE DEL PERFIL
					   			{
					   				bandera1=0;
					   				printf("\t\t\t=>NOMBRE DEL PERFIL:");
					   				fflush(stdin);
					   				gets(NAME);
					   				strcpy(z,NAME);
					   				fflush(stdin);
					   				b=strlen(NAME);
					   				a=VALIDAR_LETRAS_CON_NUMEROS(NAME);
									if(a!=0||b==0||bandera1>1)
									{
										system("cls");
										printf("\n\n\t\t\t---------[MODIFICANDO...]---------\n\n");	
					   					printf("\t\t\t=>ID:%s\n",ID);
									}
								}while(a!=0||b==0);
									
				   				do	//PEDIR DESCRIPCION//
								{
									printf("\t\t\t=>DESCRIPCION:");
									fflush(stdin);
									gets(DESC);
									strcpy(z,DESC);
									b=strlen(DESC);
									a=VALIDAR_LETRAS_CON_NUMEROS(DESC);
									if(a!=0||b==0)
									{
										system("cls");
										printf("\n\n\t\t\t---------[MODIFICANDO...]---------\n\n");	
					   					printf("\t\t\t=>ID:%s\n",ID);
					   					printf("\n\t\t\t=>NOMBRE DEL PERFIL:%s\n",NAME);
									}
								}while(a!=0||b==0);	
								
								do	//PEDIR ESTATUS//
				   				{
				   					printf("\n\t\t\t\t1)DISPONIBLE\n\t\t\t\t2)ASIGNADO\n\n");
				   					printf("\t\t\t=>ESTATUS:");
				   					fflush(stdin);
				   					gets(estatus);
				   					b=strlen(estatus);
				   					a=VALIDAR_SOLO_NUMEROS(estatus);
				   					c=atoi(estatus);
				   					
				   					if(a==0||b==0||(c<1||c>2))
				   					{
									   	system("cls");
										printf("\n\n\t\t\t---------[MODIFICANDO...]---------\n\n");	
					   					printf("\t\t\t=>ID:%s\n",ID);
					   					printf("\n\t\t\t=>NOMBRE DEL PERFIL:%s\n",NAME);
					   					printf("\t\t\t=>DESCRIPCION:%s\n",DESC);
					   				}
				   					else
				   					{
				   						STAT=atoi(estatus);	
									}
				   				}while(a==0||b==0||c<1||c>2);
								
				   				do	//PEDIR CANTIDAD//
								{
									printf("\t\t\t=>CANTIDAD:");
									fflush(stdin);
									gets(cantidad);
									a=VALIDAR_SOLO_NUMEROS(cantidad);
									if(a!=0)
									{
										CANT=atoi(cantidad);	
									}
									else
									{
										system("cls");
										printf("\n\n\t\t\t---------[MODIFICANDO...]---------\n\n");	
					   					printf("\t\t\t=>ID:%s\n",ID);
					   					printf("\n\t\t\t=>NOMBRE DEL PERFIL:%s\n",NAME);
					   					printf("\t\t\t=>DESCRIPCION:%s\n",DESC);
					   					printf("\n\t\t\t\t1)DISPONIBLE\n\t\t\t\t2)ASIGNADO\n\n");
				   						printf("\t\t\t=>ESTATUS:%d\n",PE[x].STAT);
				   					}	
								}while(a==0);
								
								do //PEDIR ID DE EMPRESA EXISTENTE
								{
									bandera1=0;
									printf("\n\t\t\t=>ID DE EMPRESA:");
					   				gets(ID_EM);
					   				fflush(stdin);
					   				b=strlen(ID_EM);
					   				a=VALIDAR_CONTRASENIA(ID_EM);
					   				for(y=j;y>=0;y--)
						   			{
										strupr(ID_EM);
						   				strupr(EM[y].ID);
						   				if(strcmp(ID_EM,EM[y].ID)==0)
										{
											bandera1++;
										}	
									}
									if(a!=0||b==0||bandera1==0)
									{
										system ("cls");
										printf("\n\n\n\n\n\n\n\n\n\n\t\t\tLA EMPRESA NO EXISTE:(");
							
										do
										{
											printf("\n\n\t\t  DESEA VOLVER AL MENU?(1/SI 2/NO):");
											fflush(stdin);
											gets(op1);
											b=VALIDAR_SOLO_NUMEROS(op1);
											numerovalidado=atoi(op1);
											if(b==0||numerovalidado<1||numerovalidado>2)
											{
												system ("cls");
												printf("\n\n\n\n\n\n\n\n\n\n\t\t\tLA EMPRESA NO EXISTE:(");
											}
											if(numerovalidado==1)
											{
												system("cls");
												MENU();
											}
											else
											{
												if(numerovalidado==2)
												{
													system("cls");
													printf("\n\n\t\t\t---------[MODIFICANDO...]---------\n\n");	
								   					printf("\t\t\t=>ID:%s\n",ID);
								   					printf("\n\t\t\t=>NOMBRE DEL PERFIL:%s\n",NAME);
								   					printf("\t\t\t=>DESCRIPCION:%s\n",DESC);
								   					printf("\n\t\t\t\t1)DISPONIBLE\n\t\t\t\t2)ASIGNADO\n\n");
							   						printf("\t\t\t=>ESTATUS:%d\n",STAT);
							   						printf("\t\t\t=>CANTIDAD:%d",CANT);
												}
											}
										}while(b==0||numerovalidado<1||numerovalidado>2);
									}
					   			}while(a!=0||b==0||bandera1==0);
										
							   	printf("\n\t\t\t\tGUARDANDO...");
							   	
							   	strcpy(PE[x].ID,ID);
							   	strcpy(PE[x].NAME,NAME);
							   	strcpy(PE[x].DESC,DESC);
							   	PE[x].STAT=STAT;
								PE[x].CANT=CANT;
								strcpy(PE[x].ID_EM,ID_EM);
				   				getch();
				   				
				   				system("cls");
								printf("\n\n\n\n\n\n\n\n\n\n\t\t     EMPRESA MODIFICADA CORRECTAMENTE:)");
								printf("\n\n\n\n\n\n\n\n\n\n\t\t\t  SE LE REGRESARA AL MENU");
				   				getch();
								MENU();
				   			}
						}
					}
					else
					{
						if(numerovalidado==2)
						{
							system("cls");
							MENU();
						}
					}
				}
				else
				{
					if(j<1)
					{
						system("cls");
						printf("\n\n\n\n\n\n\n\n\n\n\t\tNO HAY PERFILES REGISTRADOS PARA MODIFICAR:(");
						getch();
						MENU();
					}	
				}
		break;
		
		case 4:
				system("cls");
				MENU();
		break;			
	}
}

void SUBMENU_EMPLEADO() //FUNCION ENCARGADA DE ACCIONES EN EMPLEADOS(COMPLETO)//
{
	int edad_actuarial,x,eliminar,cambio=0;
	int b=0,numerovalidado=0;
	char z[' '],op1[3],op2[3],op[1];
	int bandera1=0,a=0,y=0,c=0;
	char cad1[10]="MASCULINO",cad2[10]="FEMENINO";
	char cad3[20]="NO ESPECIFICADO",cad4[15]="DISPONIBLE";
	char cad5[15]="ASIGNADO",op3[3],op4[3],op5[3];
	
	time_t tiempoahora;//FUNCIONES PARA LA EDAD//
	time(&tiempoahora);//FUNCIONES PARA LA EDAD//
	struct tm *mitiempo=localtime(&tiempoahora);

	system("cls");
	printf("\n\n\t\t\t---------MENU EMPLEADO---------\n\n");	
	printf("\t\t\t1)ALTA\n\t\t\t2)BAJA\n\t\t\t3)CAMBIO\n\t\t\t4)REGRESAR AL MENU PRINCIPAL\n\n");
	
	do
	{
		printf("\t\t        ==>OPCION A ELEGIR: ");
		fflush(stdin);
		gets(op1);
		b=VALIDAR_SOLO_NUMEROS(op1);
		numerovalidado=atoi(op1);
	   	if(b==0||numerovalidado<1||numerovalidado>4)
		{
		    system("cls");
		    printf("\n\n\t\t\t---------MENU EMPLEADO---------\n\n");	
			printf("\t\t\t1)ALTA\n\t\t\t2)BAJA\n\t\t\t3)CAMBIO\n\t\t\t4)REGRESAR AL MENU PRINCIPAL\n\n");
		}
	}while(numerovalidado<1||numerovalidado>4||b==0);
	
	switch(numerovalidado)
	{
		case 1:
				do
				{
					system ("cls");
		   			printf("\n\n\t\t\t---------MENU EMPLEADO/ALTAS---------\n");	
		   			printf("\n\t\t\t     EMPLEADO REGISTRADO NO.%d\n\n",k+1);
		   			
					do //PEDIR ID(LO CREA EL USUARIO)
					{
						bandera1=0;
						printf("\t\t\t=>CREE UN ID:"); //PEDIR ID DE EMPRESA//
						fflush(stdin);
		   				gets(EMP[k].ID);
		   				strcpy(z,EMP[k].ID);
		   				fflush(stdin);
		   				b=strlen(EMP[k].ID);
		   				a=VALIDAR_CONTRASENIA(EMP[k].ID);
		   				for(y=0;y<k;y++)
			   			{
			   				strupr(z);
			   				strupr(EMP[y].ID);
			   				if(strcmp(z,EMP[y].ID)==0)
							{
								bandera1++;
							}
						}
						if(a!=0||b==0||b>10||bandera1>0)
						{
							system ("cls");
		   					printf("\n\n\t\t\t---------MENU EMPLEADO/ALTAS---------\n");	
		   					printf("\n\t\t\t     EMPLEADO REGISTRADO NO.%d\n\n",k+1);
						}
		   			}while(a!=0||b==0||b>10||bandera1>0);
		   			
		   			do //PEDIR NOMBRE DE CONTACTO//
					{
						printf("\n\t\t\t=>NOMBRE DE EMPLEADO:");
						fflush(stdin);
	   					gets(EMP[k].NAME);
	   					fflush(stdin);
	   					b=strlen(EMP[k].NAME);
	   					a=VALIDAR_SOLO_LETRAS(EMP[k].NAME);
	   					
	   					if(a!=0||b==0||b>50)
	   					{
	   						system ("cls");
		   					printf("\n\n\t\t\t---------MENU EMPLEADO/ALTAS---------\n");	
		   					printf("\n\t\t\t     EMPLEADO REGISTRADO NO.%d\n\n",k+1);
		   					printf("\t\t\t=>CREE UN ID:%s\n",EMP[k].ID);
		   				}
						
	   				}while(a!=0||b==0||b>50);
	   				
	   				do	//PEDIR EL SEXO//
	   				{
	   					printf("\n\t\t\t\t0)MASCULINO\n\t\t\t\t2)FEMENINO\n\n");
	   					printf("\t\t\t=>SEXO:");
	   					fflush(stdin);
	   					gets(op);
	   					b=strlen(op);
	   					a=VALIDAR_SOLO_NUMEROS(op);
	   					c=atoi(op);
	   					if(a==0||b==0||(c!=0&&c!=2))
	   					{
						   	system ("cls");
		   					printf("\n\n\t\t\t---------MENU EMPLEADO/ALTAS---------\n");	
		   					printf("\n\t\t\t     EMPLEADO REGISTRADO NO.%d\n\n",k+1);
		   					printf("\t\t\t=>CREE UN ID:%s\n",EMP[k].ID);
		   					printf("\n\t\t\t=>NOMBRE DE EMPLEADO:%s\n",EMP[k].NAME);
	   					}
	   					else
	   					{
	   						EMP[k].SEX=atoi(op);	
						}
					}while(a==0||b==0||c!=0&&c!=2);
					
					do	//PEDIR ESTATUS//
	   				{
	   					printf("\n\t\t\t\t1)DISPONIBLE\n\t\t\t\t2)ASIGNADO\n\n");
	   					printf("\t\t\t=>ESTATUS:");
	   					fflush(stdin);
	   					gets(op1);
	   					b=strlen(op1);
	   					a=VALIDAR_SOLO_NUMEROS(op1);
	   					c=atoi(op1);
	   					
	   					if(a==0||b==0||(c<1||c>2))
	   					{
						   	system ("cls");
		   					printf("\n\n\t\t\t---------MENU EMPLEADO/ALTAS---------\n");	
		   					printf("\n\t\t\t     EMPLEADO REGISTRADO NO.%d\n\n",k+1);
		   					printf("\t\t\t=>CREE UN ID:%s\n",EMP[k].ID);
		   					printf("\n\t\t\t=>NOMBRE DE EMPLEADO:%s\n",EMP[k].NAME);
		   					printf("\n\t\t\t\t0)MASCULINO\n\t\t\t\t2)FEMENINO\n\n");
	   						printf("\t\t\t=>SEXO:%d\n",EMP[k].SEX);
	   					}
	   					else
	   					{
	   						EMP[k].STAT=atoi(op1);	
						}
	   				}while(a==0||b==0||c<1||c>2);
					
					do	//PEDIR PERFIL//
					{
						printf("\t\t\t=>PERFIL:");
						fflush(stdin);
						gets(EMP[k].PERF);
						b=strlen(EMP[k].PERF);
						if(b==0||b>25)
						{
							system ("cls");
		   					printf("\n\n\t\t\t---------MENU EMPLEADO/ALTAS---------\n");	
		   					printf("\n\t\t\t     EMPLEADO REGISTRADO NO.%d\n\n",k+1);
		   					printf("\t\t\t=>CREE UN ID:%s\n",EMP[k].ID);
		   					printf("\n\t\t\t=>NOMBRE DE EMPLEADO:%s\n",EMP[k].NAME);
		   					printf("\n\t\t\t\t0)MASCULINO\n\t\t\t\t2)FEMENINO\n\n");
	   						printf("\t\t\t=>SEXO:%d\n",EMP[k].SEX);
		   					printf("\n\t\t\t\t1)DISPONIBLE\n\t\t\t\t2)ASIGNADO\n\n");
		   					printf("\t\t\t=>ESTATUS:%d\n",EMP[k].STAT);
						}	
					}while(b==0||b>25);
					
					do	//PEDIR FECHA DE NACIMIENTO(DIA) PARA GENERAR EDAD//
					{
						do
						{
							printf("\n\t\t\t=>FECHA DE NACIMIENTO:");
							printf("\n\n\t\t\t\t1)DIA:");
							gets(op2);
							b=strlen(op2);
		   					a=VALIDAR_SOLO_NUMEROS(op2);
		   					c=atoi(op2);
		   					if(a==0||b==0||(c<1||c>31))
		   					{
		   						system ("cls");
			   					printf("\n\n\t\t\t---------MENU EMPLEADO/ALTAS---------\n");	
			   					printf("\n\t\t\t     EMPLEADO REGISTRADO NO.%d\n\n",k+1);
			   					printf("\t\t\t=>CREE UN ID:%s\n",EMP[k].ID);
			   					printf("\n\t\t\t=>NOMBRE DE EMPLEADO:%s\n",EMP[k].NAME);
			   					printf("\n\t\t\t\t0)MASCULINO\n\t\t\t\t2)FEMENINO\n\n");
		   						printf("\t\t\t=>SEXO:%d\n",EMP[k].SEX);
			   					printf("\n\t\t\t\t1)DISPONIBLE\n\t\t\t\t2)ASIGNADO\n\n");
			   					printf("\t\t\t=>ESTATUS:%d",EMP[k].STAT);
			   					printf("\n\t\t\t=>PERFIL:%s\n",EMP[k].PERF);
							}
							else
							{
								ED[k].DIA=atoi(op2);
							}
						}while(a==0||b==0||(c<1||c>31));
					
						do	//PEDIR FECHA DE NACIMIENTO(MES) PARA GENERAR EDAD//
						{
							printf("\t\t\t\t2)MES:");
							gets(op3);
							b=strlen(op3);
		   					a=VALIDAR_SOLO_NUMEROS(op3);
		   					c=atoi(op3);
		   					if(a==0||b==0||(c<1||c>12))
		   					{
		   						system ("cls");
			   					printf("\n\n\t\t\t---------MENU EMPLEADO/ALTAS---------\n");	
			   					printf("\n\t\t\t     EMPLEADO REGISTRADO NO.%d\n\n",k+1);
			   					printf("\t\t\t=>CREE UN ID:%s\n",EMP[k].ID);
			   					printf("\n\t\t\t=>NOMBRE DE EMPLEADO:%s\n",EMP[k].NAME);
			   					printf("\n\t\t\t\t0)MASCULINO\n\t\t\t\t2)FEMENINO\n\n");
		   						printf("\t\t\t=>SEXO:%d\n",EMP[k].SEX);
			   					printf("\n\t\t\t\t1)DISPONIBLE\n\t\t\t\t2)ASIGNADO\n\n");
			   					printf("\t\t\t=>ESTATUS:%d",EMP[k].STAT);
			   					printf("\n\t\t\t=>PERFIL:%s\n",EMP[k].PERF);
			   					printf("\n\t\t\t=>FECHA DE NACIMIENTO:");
								printf("\n\n\t\t\t\t1)DIA:%d\n",ED[k].DIA);
							}
							else
							{
								ED[k].MES=atoi(op3);
							}
						}while(a==0||b==0||(c<1||c>12));
						
						do	//PEDIR FECHA DE NACIMIENTO(AÑO) PARA GENERAR EDAD//
						{
							printf("\t\t\t\t3)ANIO:");
							gets(op4);
							b=strlen(op4);
		   					a=VALIDAR_SOLO_NUMEROS(op4);
		   					c=atoi(op4);
		   					if(a==0||b==0||c<1900||c>=mitiempo->tm_year+1900)
		   					{
		   						system ("cls");
			   					printf("\n\n\t\t\t---------MENU EMPLEADO/ALTAS---------\n");	
			   					printf("\n\t\t\t     EMPLEADO REGISTRADO NO.%d\n\n",k+1);
			   					printf("\t\t\t=>CREE UN ID:%s\n",EMP[k].ID);
			   					printf("\n\t\t\t=>NOMBRE DE EMPLEADO:%s\n",EMP[k].NAME);
			   					printf("\n\t\t\t\t0)MASCULINO\n\t\t\t\t2)FEMENINO\n\n");
		   						printf("\t\t\t=>SEXO:%d\n",EMP[k].SEX);
			   					printf("\n\t\t\t\t1)DISPONIBLE\n\t\t\t\t2)ASIGNADO\n\n");
			   					printf("\t\t\t=>ESTATUS:%d",EMP[k].STAT);
			   					printf("\n\t\t\t=>PERFIL:%s\n",EMP[k].PERF);
			   					printf("\n\t\t\t=>FECHA DE NACIMIENTO:");
								printf("\n\n\t\t\t\t1)DIA:%d\n",ED[k].DIA);
								printf("\t\t\t\t2)MES:%d\n",ED[k].MES);
							}
							else
							{
								ED[k].ANIO=atoi(op4);
							}
							
							struct tm *mitiempo=localtime(&tiempoahora);	
	
							if((mitiempo->tm_year+1900)>ED[k].ANIO&&(mitiempo->tm_mon+1)>ED[k].MES)
							{
								EMP[k].FCHA=(mitiempo->tm_year+1900)-ED[k].ANIO;
							
							}
							else
							{
								if((mitiempo->tm_year+1900)>ED[k].ANIO&&(mitiempo->tm_mon+1)<ED[k].MES)
								{
									EMP[k].FCHA=(mitiempo->tm_year+1900)-ED[k].ANIO-1;
								
								}
								else
								{
									if((mitiempo->tm_year+1900)>ED[k].ANIO&&(mitiempo->tm_mon+1)==ED[k].MES)
									{
										if(mitiempo->tm_mday>=ED[k].DIA)
										{
											EMP[k].FCHA=(mitiempo->tm_year+1900)-ED[k].ANIO;
										
										}
										else
										{
											if(mitiempo->tm_mday<ED[k].DIA)
											{
												EMP[k].FCHA=(mitiempo->tm_year+1900)-ED[k].ANIO-1;
											
											}
										}
									}
								}
							}
						}while(a==0||b==0||c<1900||c>=mitiempo->tm_year+1900);
						if(EMP[k].FCHA>104||EMP[k].FCHA<16)
						{
							system ("cls");
			   				printf("\n\n\t\t\t---------MENU EMPLEADO/ALTAS---------\n");	
			   				printf("\n\t\t\t     EMPLEADO REGISTRADO NO.%d\n\n",k+1);
			   				printf("\t\t\t=>CREE UN ID:%s\n",EMP[k].ID);
			   				printf("\n\t\t\t=>NOMBRE DE EMPLEADO:%s\n",EMP[k].NAME);
			   				printf("\n\t\t\t\t0)MASCULINO\n\t\t\t\t2)FEMENINO\n\n");
		   					printf("\t\t\t=>SEXO:%d\n",EMP[k].SEX);
			   				printf("\n\t\t\t\t1)DISPONIBLE\n\t\t\t\t2)ASIGNADO\n\n");
			   				printf("\t\t\t=>ESTATUS:%d",EMP[k].STAT);
			   				printf("\n\t\t\t=>PERFIL:%s\n",EMP[k].PERF);
						}
					}while(EMP[k].FCHA>104||EMP[k].FCHA<16);
					
					printf("\n\t\t\t=>EDAD:%d",EMP[k].FCHA); //EDAD GENERADA//
					
					do	//PEDIR SI ES FUMADOR//
					{
						printf("\n\t\t\t=>FUMADOR(0/SI 2/NO):");
						fflush(stdin);
						gets(op5);			
						b=strlen(op5);
	   					a=VALIDAR_SOLO_NUMEROS(op5);
	   					c=atoi(op5);
	   					if(a==0||b==0||c!=0&&c!=2)
	   					{
	   						system ("cls");
		   					printf("\n\n\t\t\t---------MENU EMPLEADO/ALTAS---------\n");	
		   					printf("\n\t\t\t     EMPLEADO REGISTRADO NO.%d\n\n",k+1);
		   					printf("\t\t\t=>CREE UN ID:%s\n",EMP[k].ID);
		   					printf("\n\t\t\t=>NOMBRE DE EMPLEADO:%s\n",EMP[k].NAME);
		   					printf("\n\t\t\t\t0)MASCULINO\n\t\t\t\t2)FEMENINO\n\n");
	   						printf("\t\t\t=>SEXO:%d\n",EMP[k].SEX);
		   					printf("\n\t\t\t\t1)DISPONIBLE\n\t\t\t\t2)ASIGNADO\n\n");
		   					printf("\t\t\t=>ESTATUS:%d",EMP[k].STAT);
		   					printf("\n\t\t\t=>PERFIL:%s\n",EMP[k].PERF);
		   					printf("\n\t\t\t=>FECHA DE NACIMIENTO:");
							printf("\n\n\t\t\t\t1)DIA:%d\n",ED[k].DIA);
							printf("\t\t\t\t2)MES:%d\n",ED[k].MES);
							printf("\t\t\t\t3)ANIO:%d\n",ED[k].ANIO);
							printf("\n\t\t\t=>EDAD:%d",EMP[k].FCHA);
						}
						else
						{
							EMP[k].FUMA=atoi(op5);
						}
					}while(a==0||b==0||c!=0&&c!=2);
					
					edad_actuarial=EMP[k].FCHA-EMP[k].SEX-EMP[k].FUMA;	//FORMULA EDAD ACTUARIAL
					
					if(edad_actuarial<18)
					{
						EMP[k].SUMA_ASEG=100000;	//SUMA ASEGURADA
					}
					else
					{
						if(edad_actuarial>=18&&edad_actuarial<=25)
						{
							EMP[k].SUMA_ASEG=200000;	//SUMA ASEGURADA
						}
						else
						{
							if(edad_actuarial>=26&&edad_actuarial<=35)
							{
								EMP[k].SUMA_ASEG=400000;	//SUMA ASEGURADA
							}
							else
							{
								if(edad_actuarial>=36&&edad_actuarial<=45)
								{
									EMP[k].SUMA_ASEG=800000;	//SUMA ASEGURADA
								}
								else
								{
									if(edad_actuarial>=46)
									{
										EMP[k].SUMA_ASEG=1600000;	//SUMA ASEGURADA
									}
								}
							}
						}
					}
					
					printf("\n\t\t\t=>SUMA ASEGURADA:$%d",EMP[k].SUMA_ASEG); //GENERAMOS SUMA ASEGURADA// 
					EMP[k].TARIFA=VERIFICACION(EMP[k].SUMA_ASEG,edad_actuarial); //MANDAMOS A FUNCION PARA TARIFA ANUAL//
					printf("\n\t\t\t=>PRIMA TARIFA ANUAL:$%.2f\n",EMP[k].TARIFA); //GENERAMOS TARIFA ANUAL//
					
					do //PEDIR SI SE DESEA AGREGAR OTRO EMPLEADO//
					{
						do
						{
							printf("\n\n\t\t\t=>LOS DATOS INGRESADOS SON CORRECTOS?(1/SI 2/NO):");
							fflush(stdin);
							gets(op1);
							b=VALIDAR_SOLO_NUMEROS(op1);
							if(b==0||numerovalidado<1||numerovalidado>2)
							{
								system ("cls");
			   					printf("\n\n\t\t\t---------MENU EMPLEADO/ALTAS---------\n");	
			   					printf("\n\t\t\t     EMPLEADO REGISTRADO NO.%d\n\n",k+1);
			   					printf("\t\t\t=>CREE UN ID:%s\n",EMP[k].ID);
			   					printf("\n\t\t\t=>NOMBRE DE EMPLEADO:%s\n",EMP[k].NAME);
			   					printf("\n\t\t\t\t0)MASCULINO\n\t\t\t\t2)FEMENINO\n\n");
		   						printf("\t\t\t=>SEXO:%d\n",EMP[k].SEX);
			   					printf("\n\t\t\t\t1)DISPONIBLE\n\t\t\t\t2)ASIGNADO\n\n");
			   					printf("\t\t\t=>ESTATUS:%d",EMP[k].STAT);
			   					printf("\n\t\t\t=>PERFIL:%s\n",EMP[k].PERF);
			   					printf("\n\t\t\t=>FECHA DE NACIMIENTO:");
								printf("\n\n\t\t\t\t1)DIA:%d\n",ED[k].DIA);
								printf("\t\t\t\t2)MES:%d\n",ED[k].MES);
								printf("\t\t\t\t3)ANIO:%d\n",ED[k].ANIO);
								printf("\n\t\t\t=>EDAD:%d",EMP[k].FCHA);
								printf("\n\t\t\t=>FUMADOR(0/SI 2/NO):%d\n",EMP[k].FUMA);
								printf("\n\t\t\t=>SUMA ASEGURADA:$%d",EMP[k].SUMA_ASEG);
								printf("\n\t\t\t=>PRIMA TARIFA ANUAL:$%.2f\n",EMP[k].TARIFA);
							}
						}while(b==0);
						numerovalidado=atoi(op1);
						
						if(numerovalidado==1)
						{
							do //PEDIR SI SE DESEA AGREGAR OTRO EMPLEADO//
							{
								do
								{
									printf("\t\t\t=>DESEA AGREGAR OTRO EMPLEADO?(1/SI 2/NO):");
									fflush(stdin);
									gets(op1);
									b=VALIDAR_SOLO_NUMEROS(op1);
									if(b==0||numerovalidado<1||numerovalidado>2)
									{
										system ("cls");
					   					printf("\n\n\t\t\t---------MENU EMPLEADO/ALTAS---------\n");	
					   					printf("\n\t\t\t     EMPLEADO REGISTRADO NO.%d\n\n",k+1);
					   					printf("\t\t\t=>CREE UN ID:%s\n",EMP[k].ID);
					   					printf("\n\t\t\t=>NOMBRE DE EMPLEADO:%s\n",EMP[k].NAME);
					   					printf("\n\t\t\t\t0)MASCULINO\n\t\t\t\t2)FEMENINO\n\n");
				   						printf("\t\t\t=>SEXO:%d\n",EMP[k].SEX);
					   					printf("\n\t\t\t\t1)DISPONIBLE\n\t\t\t\t2)ASIGNADO\n\n");
					   					printf("\t\t\t=>ESTATUS:%d",EMP[k].STAT);
					   					printf("\n\t\t\t=>PERFIL:%s\n",EMP[k].PERF);
					   					printf("\n\t\t\t=>FECHA DE NACIMIENTO:");
										printf("\n\n\t\t\t\t1)DIA:%d\n",ED[k].DIA);
										printf("\t\t\t\t2)MES:%d\n",ED[k].MES);
										printf("\t\t\t\t3)ANIO:%d\n",ED[k].ANIO);
										printf("\n\t\t\t=>EDAD:%d",EMP[k].FCHA);
										printf("\n\t\t\t=>FUMADOR(0/SI 2/NO):%d\n",EMP[k].FUMA);
										printf("\n\t\t\t=>SUMA ASEGURADA:$%d",EMP[k].SUMA_ASEG);
										printf("\n\t\t\t=>PRIMA TARIFA ANUAL:$%.2f\n\n",EMP[k].TARIFA);
									}
								}while(b==0);
								numerovalidado=atoi(op1);
								if(numerovalidado==1)
								{
									k++;
								}
								else
								{
									if(numerovalidado==2)
									{
										k++;
										system("cls");
										MENU();
									}
								}
							}while(numerovalidado<1||numerovalidado>2);
						}
						else
						{
							if(numerovalidado==2)
							{
								system("cls");
								numerovalidado=1;
							}
						}
					}while(numerovalidado<1||numerovalidado>2);
				}while(numerovalidado==1);	
		break;
		
		case 2:
				if(k>=1)
	   			{
	   				system("cls");
					printf("\n\n\t\t\t---------MENU EMPLEADO/BAJAS---------\n\n");
						
					for(x=0;x<k;x++)
					{
						printf("\t\t\t%d)%s\n\n",x,EMP[x].NAME);
						fflush(stdin);
					}
		
					do
					{
						printf("\n\t\t\t=>NUMERO DE EMPLEADO A ELIMINAR:");
						fflush(stdin);
						gets(op1);
						b=VALIDAR_SOLO_NUMEROS(op1);
						eliminar=atoi(op1);
						if(eliminar<k||eliminar>k-1||b==0)
						{
							system("cls");
							printf("\n\n\t\t\t---------MENU EMPLEADO/BAJAS---------\n\n");	
							for(x=0;x<k;x++)
							{
								printf("\t\t\t%d)%s\n",x,EMP[x].NAME);
							}
						}
					}while(eliminar<k-k||eliminar>k-1||b==0);
					system("cls");
					printf("\n\n\t\t\tSE ELIMINARA EL EMPLEADO CUYOS DATOS SON:\n\n");
					for(x=0;x<k;x++)
					{
						if(x==eliminar)
						{
							do
							{
								printf("\t\t\t=>ID:\t\t\t%s\n",EMP[x].ID);
					   			printf("\n\t\t\t=>NOMBRE:\t\t%s\n",EMP[x].NAME);
					   			if(EMP[x].SEX==0)
					   			{
					   				printf("\t\t\t=>SEXO:\t\t\tHOMBRE\n");
								}
								else
								{
									printf("\t\t\t=>SEXO:\t\t\tFEMENINO\n");
								}
								if(EMP[x].STAT==1)
								{
									printf("\t\t\t=>ESTATUS:\t\tDISPONIBLE\n");
								}
								else
								{
									printf("\t\t\t=>ESTATUS:\t\tASIGNADO\n");
								}
					   			printf("\n\t\t\t=>PERFIL:\t\t%s\n",EMP[x].PERF);
					   			printf("\n\t\t\t=>FECHA DE NACIMIENTO:\t%d/%d/%d\n",ED[x].DIA,ED[x].MES,ED[x].ANIO);
								printf("\n\t\t\t=>EDAD:\t\t\t%d",EMP[x].FCHA);
								if(EMP[x].FUMA==0)
								{
									printf("\n\t\t\t=>FUMADOR:\t\tSI\n");
								}
								else
								{
									printf("\n\t\t\t=>FUMADOR:\t\tN0\n");
								}
								printf("\n\t\t\t=>SUMA ASEGURADA:\t$%d",EMP[x].SUMA_ASEG);
								printf("\n\t\t\t=>PRIMA TARIFA ANUAL:\t$%.2f\n\n",EMP[x].TARIFA);
								printf("\n\t\t\tELIMINAR?(1/SI 2/NO):");
								fflush(stdin);
								gets(op1);
								b=VALIDAR_SOLO_NUMEROS(op1);
								numerovalidado=atoi(op1);
								if(b==0||numerovalidado<1||numerovalidado>2)
								{
									system("cls");
									printf("\n\n\t\t\tSE ELIMINARA EL EMPLEADO CUYOS DATOS SON:\n\n");
								}
								else
								{
									if(numerovalidado==1)
									{
										for(x=0;x<k;x++)
										{
											if(x==eliminar)
											{
												while(x<k)
												{
													strcpy(EMP[x].ID,EMP[x+1].ID);
													
													strcpy(EMP[x].NAME,EMP[x+1].NAME);
													EMP[x].SEX=EMP[x+1].SEX;
													EMP[x].STAT=EMP[x+1].STAT;
													strcpy(EMP[x].PERF,EMP[x+1].PERF);
													ED[x].DIA=ED[x+1].DIA;
													ED[x].MES=ED[x+1].MES;
													ED[x].ANIO=ED[x+1].ANIO;
													EMP[x].FCHA=EMP[x+1].FCHA;
													EMP[x].FUMA=EMP[x+1].FUMA;
											
													EMP[x].SUMA_ASEG=EMP[x+1].SUMA_ASEG;
													EMP[x].TARIFA=EMP[x+1].TARIFA;
													x++;
												}
												break;
										  	}
										}
										k=k-1;
										system("cls");
										printf("\n\n\n\n\n\n\n\n\n\n\t\t\t    ELIMINADA CON EXITO!\n\n");
										printf("\t\t\t  SE LE REGRESARA AL MENU");
										getch();
										system("cls");
										MENU();
									}
									else
									{
										if(numerovalidado==2)
										{
											system("cls");
											printf("\n\n\n\n\n\n\n\n\n\n\t\t\t  SE LE REGRESARA AL MENU");
											system("cls");
											MENU();
										}
									}
								}
							}while(numerovalidado<1||numerovalidado>2||b==0);
						}	
					}
				}
				else
				{
					if(k<=0)
					{
						system("cls");
						printf("\n\n\n\n\n\n\n\n\n\n\t\tNO HAY EMPLEADOS REGISTRADOS PARA ELIMINAR:(");
						getch();
						MENU();
					}
				}
		break;
		
		case 3:
				if(k>=1)
				{
					system("cls");
					printf("\n\n\t\t\t---------MENU EMPLEADO/CAMBIOS---------\n\n");
					for(x=0;x<k;x++)
					{
						printf("\t\t\t%d)%s\n\n",x,EMP[x].NAME);
						fflush(stdin);
					}
					do
					{
						printf("\n\t\t\t=>NUMERO DE EMPLEADO A MODIFICAR:");
						fflush(stdin);
						gets(op1);
						b=VALIDAR_SOLO_NUMEROS(op1);
						cambio=atoi(op1);
						if(cambio<k||cambio>k-1||b==0)
						{
							system("cls");
							printf("\n\n\t\t\t---------MENU EMPLEADO/CAMBIOS---------\n\n");	
							for(x=0;x<k;x++)
							{
								printf("\t\t\t%d)%s\n\n",x,EMP[x].NAME);
							}
						}
					}while(cambio<k-k||cambio>k-1||b==0);
					
					system("cls");
					printf("\n\n\t\t\tSE MODIFICARA EL EMPLEADO CUYOS DATOS SON:\n\n");
					
					for(x=0;x<k;x++)
					{
						if(x==cambio)
						{
							do
							{	
								printf("\t\t\t=>ID:\t\t\t%s\n",EMP[x].ID);
					   			printf("\n\t\t\t=>NOMBRE:\t\t%s\n",EMP[x].NAME);
					   			if(EMP[x].SEX==0)
					   			{
					   				printf("\t\t\t=>SEXO:\t\t\tHOMBRE\n");
								}
								else
								{
									printf("\t\t\t=>SEXO:\t\t\tFEMENINO\n");
								}
								if(EMP[x].STAT==1)
								{
									printf("\t\t\t=>ESTATUS:\t\tDISPONIBLE\n");
								}
								else
								{
									printf("\t\t\t=>ESTATUS:\t\tASIGNADO\n");
								}
					   			printf("\n\t\t\t=>PERFIL:\t\t%s\n",EMP[x].PERF);
					   			printf("\n\t\t\t=>FECHA DE NACIMIENTO:\t%d/%d/%d\n",ED[x].DIA,ED[x].MES,ED[x].ANIO);
								printf("\n\t\t\t=>EDAD:\t\t\t%d",EMP[x].FCHA);
								if(EMP[x].FUMA==0)
								{
									printf("\n\t\t\t=>FUMADOR:\t\tSI\n");
								}
								else
								{
									printf("\n\t\t\t=>FUMADOR:\t\tN0\n");
								}
								printf("\n\t\t\t=>SUMA ASEGURADA:\t$%d",EMP[x].SUMA_ASEG);
								printf("\n\t\t\t=>PRIMA TARIFA ANUAL:\t$%.2f\n\n",EMP[x].TARIFA);
								printf("\n\t\t\tMODIFICAR?(1/SI 2/NO):");
								fflush(stdin);
								gets(op1);
								b=VALIDAR_SOLO_NUMEROS(op1);
								numerovalidado=atoi(op1);
								if(b==0||numerovalidado<1||numerovalidado>2)
								{
									system("cls");
									printf("\n\n\t\t\tSE MODIFICARA EL EMPLEADO CUYOS DATOS SON:\n\n");
								}
							}while(numerovalidado<1||numerovalidado>2||b==0);
							
							if(numerovalidado==1)
							{
								system("cls");
								printf("\n\n\t\t\t---------[MODIFICANDO...]---------\n\n");	
								for(x=k;x>=0;x--)
								{
									if(x==cambio)
									{
										do //PEDIR ID(LO CREA EL USUARIO)
										{
											bandera1=0;
											printf("\t\t\t=>ID:"); //PEDIR ID DE EMPRESA//
											fflush(stdin);
							   				gets(EMP[x].ID);
							   				strcpy(z,EMP[x].ID);
							   				fflush(stdin);
							   				b=strlen(EMP[x].ID);
							   				a=VALIDAR_CONTRASENIA(EMP[x].ID);
							   				for(y=k;y>=0;y--)
								   			{
								   				strupr(z);
								   				strupr(EMP[y].ID);
								   				if(strcmp(z,EMP[y].ID)==0)
												{
													bandera1++;
												}
											}
											if(a!=0||b==0||b>10||bandera1>1)
											{
												system("cls");
												printf("\n\n\t\t\t---------[MODIFICANDO...]---------\n\n");	
											}
							   			}while(a!=0||b==0||b>10||bandera1>1);
							   			
							   			do //PEDIR NOMBRE DE CONTACTO//
										{
											printf("\n\t\t\t=>NOMBRE DE EMPLEADO:");
											fflush(stdin);
						   					gets(EMP[x].NAME);
						   					fflush(stdin);
						   					b=strlen(EMP[x].NAME);
						   					a=VALIDAR_SOLO_LETRAS(EMP[x].NAME);
						   					
						   					if(a!=0||b==0||b>50)
						   					{
						   						system("cls");
												printf("\n\n\t\t\t---------[MODIFICANDO...]---------\n\n");	
												printf("\t\t\t=>ID:%s\n",EMP[x].ID);
							   				}
											
						   				}while(a!=0||b==0||b>50);
						   				
						   				do
						   				{
						   					printf("\n\t\t\t\t0)MASCULINO\n\t\t\t\t2)FEMENINO\n\n");
						   					printf("\t\t\t=>SEXO:");
						   					fflush(stdin);
						   					gets(op);
						   					b=strlen(op);
						   					a=VALIDAR_SOLO_NUMEROS(op);
						   					c=atoi(op);
						   					if(a==0||b==0||(c!=0&&c!=2))
						   					{
											  	system("cls");
												printf("\n\n\t\t\t---------[MODIFICANDO...]---------\n\n");	
												printf("\t\t\t=>ID:%s\n",EMP[x].ID);
												printf("\n\t\t\t=>NOMBRE DE EMPLEADO:%s\n",EMP[x].NAME);
						   					}
						   					else
						   					{
						   						EMP[x].SEX=atoi(op);	
											}
										}while(a==0||b==0||c!=0&&c!=2);
										
										do
						   				{
						   					printf("\n\t\t\t\t1)DISPONIBLE\n\t\t\t\t2)ASIGNADO\n\n");
						   					printf("\t\t\t=>ESTATUS:");
						   					fflush(stdin);
						   					gets(op1);
						   					b=strlen(op1);
						   					a=VALIDAR_SOLO_NUMEROS(op1);
						   					c=atoi(op1);
						   					
						   					if(a==0||b==0||(c<1||c>2))
						   					{
						   						system("cls");
												printf("\n\n\t\t\t---------[MODIFICANDO...]---------\n\n");	
							   					printf("\t\t\t=>ID:%s\n",EMP[x].ID);
							   					printf("\n\t\t\t=>NOMBRE DE EMPLEADO:%s\n",EMP[x].NAME);
							   					printf("\n\t\t\t\t0)MASCULINO\n\t\t\t\t2)FEMENINO\n\n");
						   						printf("\t\t\t=>SEXO:%d\n",EMP[x].SEX);
						   					}
						   					else
						   					{
						   						EMP[x].STAT=atoi(op1);	
											}
						   				}while(a==0||b==0||c<1||c>2);
						   				
						   				do
										{
											printf("\t\t\t=>PERFIL:");
											fflush(stdin);
											gets(EMP[x].PERF);
											b=strlen(EMP[x].PERF);
											if(b==0||b>25)
											{
												system("cls");
												printf("\n\n\t\t\t---------[MODIFICANDO...]---------\n\n");	
							   					printf("\t\t\t=>ID:%s\n",EMP[x].ID);
							   					printf("\n\t\t\t=>NOMBRE DE EMPLEADO:%s\n",EMP[x].NAME);
							   					printf("\n\t\t\t\t0)MASCULINO\n\t\t\t\t2)FEMENINO\n\n");
						   						printf("\t\t\t=>SEXO:%d\n",EMP[x].SEX);
								   				printf("\n\t\t\t\t1)DISPONIBLE\n\t\t\t\t2)ASIGNADO\n\n");
								   				printf("\t\t\t=>ESTATUS:%d\n",EMP[x].STAT);
											}	
										}while(b==0||b>25);
										
										do
										{
											do
											{
												printf("\n\t\t\t=>FECHA DE NACIMIENTO:");
												printf("\n\n\t\t\t\t1)DIA:");
												gets(op2);
												b=strlen(op2);
							   					a=VALIDAR_SOLO_NUMEROS(op2);
							   					c=atoi(op2);
							   					if(a==0||b==0||(c<1||c>31))
							   					{
							   						system("cls");
													printf("\n\n\t\t\t---------[MODIFICANDO...]---------\n\n");	
								   					printf("\t\t\t=>ID:%s\n",EMP[x].ID);
								   					printf("\n\t\t\t=>NOMBRE DE EMPLEADO:%s\n",EMP[x].NAME);
								   					printf("\n\t\t\t\t0)MASCULINO\n\t\t\t\t2)FEMENINO\n\n");
							   						printf("\t\t\t=>SEXO:%d\n",EMP[x].SEX);
								   					printf("\n\t\t\t\t1)DISPONIBLE\n\t\t\t\t2)ASIGNADO\n\n");
								   					printf("\t\t\t=>ESTATUS:%d",EMP[x].STAT);
								   					printf("\n\t\t\t=>PERFIL:%s\n",EMP[x].PERF);
												}
												else
												{
													ED[x].DIA=atoi(op2);
												}
											}while(a==0||b==0||(c<1||c>31));
										
											do
											{
												printf("\t\t\t\t2)MES:");
												gets(op3);
												b=strlen(op3);
							   					a=VALIDAR_SOLO_NUMEROS(op3);
							   					c=atoi(op3);
							   					if(a==0||b==0||(c<1||c>12))
							   					{
							   						system("cls");
													printf("\n\n\t\t\t---------[MODIFICANDO...]---------\n\n");	
								   					printf("\t\t\t=>ID:%s\n",EMP[x].ID);
								   					printf("\n\t\t\t=>NOMBRE DE EMPLEADO:%s\n",EMP[x].NAME);
								   					printf("\n\t\t\t\t0)MASCULINO\n\t\t\t\t2)FEMENINO\n\n");
							   						printf("\t\t\t=>SEXO:%d\n",EMP[x].SEX);
								   					printf("\n\t\t\t\t1)DISPONIBLE\n\t\t\t\t2)ASIGNADO\n\n");
								   					printf("\t\t\t=>ESTATUS:%d",EMP[x].STAT);
								   					printf("\n\t\t\t=>PERFIL:%s\n",EMP[x].PERF);
								   					printf("\n\t\t\t=>FECHA DE NACIMIENTO:");
													printf("\n\n\t\t\t\t1)DIA:%d\n",ED[x].DIA);
												}
												else
												{
													ED[x].MES=atoi(op3);
												}
											}while(a==0||b==0||(c<1||c>12));
						
											do
											{
												printf("\t\t\t\t3)ANIO:");
												gets(op4);
												b=strlen(op4);
							   					a=VALIDAR_SOLO_NUMEROS(op4);
							   					c=atoi(op4);
							   					if(a==0||b==0||c<1900||c>=mitiempo->tm_year+1900)
							   					{
							   						system("cls");
													printf("\n\n\t\t\t---------[MODIFICANDO...]---------\n\n");	
								   					printf("\t\t\t=>ID:%s\n",EMP[x].ID);
								   					printf("\n\t\t\t=>NOMBRE DE EMPLEADO:%s\n",EMP[x].NAME);
								   					printf("\n\t\t\t\t0)MASCULINO\n\t\t\t\t2)FEMENINO\n\n");
							   						printf("\t\t\t=>SEXO:%d\n",EMP[x].SEX);
								   					printf("\n\t\t\t\t1)DISPONIBLE\n\t\t\t\t2)ASIGNADO\n\n");
								   					printf("\t\t\t=>ESTATUS:%d",EMP[x].STAT);
								   					printf("\n\t\t\t=>PERFIL:%s\n",EMP[x].PERF);
								   					printf("\n\t\t\t=>FECHA DE NACIMIENTO:");
													printf("\n\n\t\t\t\t1)DIA:%d\n",ED[x].DIA);
													printf("\t\t\t\t2)MES:%d\n",ED[x].MES);
												}
												else
												{
													ED[x].ANIO=atoi(op4);
												}
												
												struct tm *mitiempo=localtime(&tiempoahora);	
						
												if((mitiempo->tm_year+1900)>ED[x].ANIO&&(mitiempo->tm_mon+1)>ED[x].MES)
												{
													EMP[x].FCHA=(mitiempo->tm_year+1900)-ED[x].ANIO;
												}
												else
													{
													if((mitiempo->tm_year+1900)>ED[x].ANIO&&(mitiempo->tm_mon+1)<ED[x].MES)
													{
														EMP[k].FCHA=(mitiempo->tm_year+1900)-ED[x].ANIO-1;
													}
													else
													{
														if((mitiempo->tm_year+1900)>ED[x].ANIO&&(mitiempo->tm_mon+1)==ED[x].MES)
														{
															if(mitiempo->tm_mday>=ED[x].DIA)
															{
																EMP[x].FCHA=(mitiempo->tm_year+1900)-ED[x].ANIO;
															}
															else
															{
																if(mitiempo->tm_mday<ED[x].DIA)
																{
																	EMP[x].FCHA=(mitiempo->tm_year+1900)-ED[x].ANIO-1;
																
																}
															}
														}
													}
												}
											}while(a==0||b==0||c<1900||c>=mitiempo->tm_year+1900);
											if(EMP[x].FCHA>104||EMP[x].FCHA<16)
											{
												system("cls");
												printf("\n\n\t\t\t---------[MODIFICANDO...]---------\n\n");	
								   				printf("\t\t\t=>ID:%s\n",EMP[x].ID);
								   				printf("\n\t\t\t=>NOMBRE DE EMPLEADO:%s\n",EMP[x].NAME);
								   				printf("\n\t\t\t\t0)MASCULINO\n\t\t\t\t2)FEMENINO\n\n");
							   					printf("\t\t\t=>SEXO:%d\n",EMP[x].SEX);
								   				printf("\n\t\t\t\t1)DISPONIBLE\n\t\t\t\t2)ASIGNADO\n\n");
								   				printf("\t\t\t=>ESTATUS:%d",EMP[x].STAT);
								   				printf("\n\t\t\t=>PERFIL:%s\n",EMP[x].PERF);
											}
										}while(EMP[x].FCHA>104||EMP[x].FCHA<16);
						
										printf("\n\t\t\t=>EDAD:%d",EMP[x].FCHA);
										
										do
										{
											printf("\n\t\t\t=>FUMADOR(0/SI 2/NO):");
											fflush(stdin);
											gets(op5);			
											b=strlen(op5);
						   					a=VALIDAR_SOLO_NUMEROS(op5);
						   					c=atoi(op5);
						   					if(a==0||b==0||c!=0&&c!=2)
						   					{
						   						system("cls");
												printf("\n\n\t\t\t---------[MODIFICANDO...]---------\n\n");	
								   				printf("\t\t\t=>ID:%s\n",EMP[x].ID);
								   				printf("\n\t\t\t=>NOMBRE DE EMPLEADO:%s\n",EMP[x].NAME);
								   				printf("\n\t\t\t\t0)MASCULINO\n\t\t\t\t2)FEMENINO\n\n");
							   					printf("\t\t\t=>SEXO:%d\n",EMP[x].SEX);
								   				printf("\n\t\t\t\t1)DISPONIBLE\n\t\t\t\t2)ASIGNADO\n\n");
								   				printf("\t\t\t=>ESTATUS:%d",EMP[x].STAT);
								   				printf("\n\t\t\t=>PERFIL:%s\n",EMP[x].PERF);
							   					printf("\n\t\t\t=>FECHA DE NACIMIENTO:");
												printf("\n\n\t\t\t\t1)DIA:%d\n",ED[x].DIA);
												printf("\t\t\t\t2)MES:%d\n",ED[x].MES);
												printf("\t\t\t\t3)ANIO:%d\n",ED[x].ANIO);
												printf("\n\t\t\t=>EDAD:%d",EMP[x].FCHA);
											}
											else
											{
												EMP[x].FUMA=atoi(op5);
											}
										}while(a==0||b==0||c!=0&&c!=2);
					
										edad_actuarial=EMP[x].FCHA-EMP[x].SEX-EMP[x].FUMA;	//FORMULA EDAD ACTUARIAL
										
										if(edad_actuarial<18)
										{
											EMP[x].SUMA_ASEG=100000;	//SUMA ASEGURADA
										}
										else
										{
											if(edad_actuarial>=18&&edad_actuarial<=25)
											{
												EMP[x].SUMA_ASEG=200000;	//SUMA ASEGURADA
											}
											else
											{
												if(edad_actuarial>=26&&edad_actuarial<=35)
												{
													EMP[x].SUMA_ASEG=400000;	//SUMA ASEGURADA
												}
												else
												{
													if(edad_actuarial>=36&&edad_actuarial<=45)
													{
														EMP[x].SUMA_ASEG=800000;	//SUMA ASEGURADA
													}
													else
													{
														if(edad_actuarial>=46)
														{
															EMP[x].SUMA_ASEG=1600000;	//SUMA ASEGURADA
														}
													}
												}
											}
										}
										
										printf("\n\t\t\t=>SUMA ASEGURADA:$%d",EMP[x].SUMA_ASEG);
										EMP[k].TARIFA=VERIFICACION(EMP[x].SUMA_ASEG,edad_actuarial);
										printf("\n\t\t\t=>PRIMA TARIFA ANUAL:$%.2f\n",EMP[x].TARIFA);
										printf("\n\t\t\t\tGUARDANDO...");
						   				getch();
						   				system("cls");
										printf("\n\n\n\n\n\n\n\n\n\n\t\t     EMPLEADO MODIFICADA CORRECTAMENTE:)");
										printf("\n\n\n\n\n\n\n\n\n\n\t\t\t  SE LE REGRESARA AL MENU");
						   				getch();
										MENU();
									}
								}
							}
							else
							{
								if(numerovalidado==2)
								{
									system("cls");
									MENU();	
								}	
							}					
						}	
					} 
				}
				else
				{
					if(k<=0)
					{
						system("cls");
						printf("\n\n\n\n\n\n\n\n\n\n\t\tNO HAY EMPLEADOS REGISTRADOS PARA MODIFICAR:(");
						getch();
						MENU();
					}
				}		
		break;
		
		case 4:
				system("cls");
				MENU();
		break;	
	}
}

void SUBMENU_BUSQUEDAS()
{
	char op[' '],buscar[' '];
	int b=0,numerovalidado=0;
	int x=0,y=0;

	system("cls");
	printf("\n\n\t\t\t---------MENU BUSQUEDA---------\n\n");
	printf("\t\t\t1)EMPLEADO(NO ASIGNADO)\n\t\t\t2)EMPRESAS\n\t\t\t");
	printf("3)EMPLEADO POR EMPRESA\n\t\t\t4)REGRESAR AL MENU PRINCIPAL\n\n");
	do
	{
		printf("\t\t        ==>OPCION A ELEGIR: ");
		fflush(stdin);
		gets(op);
		b=VALIDAR_SOLO_NUMEROS(op);
		numerovalidado=atoi(op);
		if(b==0||numerovalidado<1||numerovalidado>6)
		{
		   	system("cls");
			printf("\n\n\t\t\t---------MENU BUSQUEDA---------\n\n");
			printf("\t\t\t1)EMPLEADO(NO ASIGNADO)\n\t\t\t2)EMPRESAS\n\t\t\t");
			printf("3)EMPLEADO POR EMPRESA\n\t\t\t4)REGRESAR AL MENU PRINCIPAL\n\n");
		}
	}while(numerovalidado<1||numerovalidado>6||b==0);	
	
	switch(numerovalidado)
	{
		case 1:
				if(k>=1)
				{
					system("cls");
					printf("\n\n\n\n\n\n\t\t\t   A CONTINUACION, SI EL ID INGRESADA\n");
					printf("\t\t\tNO CORRESPONDE A UN EMPLEADO NO ASIGNADO\n\n");
					printf("\t\t      ---LA BUSQUEDA SE MOSTRARA COMO INCORRECTA---");
					getch();
					system("cls");
					printf("\n\n\t\t\t---------MENU BUSQUEDA/EMPLEADO---------\n\n");
					printf("\t\t\t=>ID DE EMPLEADO A BUSCAR:");
					fflush(stdin);
					gets(buscar);
					
					for(x=0;x<k;x++)
					{
						if(strcmp(buscar,EMP[x].ID)==0)
						{
							if(EMP[x].STAT==1)
							{
					   			printf("\n\t\t\t=>NOMBRE:\t\t%s\n",EMP[x].NAME);
					   			if(EMP[x].SEX==0)
					   			{
					   				printf("\t\t\t=>SEXO:\t\t\tHOMBRE\n");
								}
								else
								{
									printf("\t\t\t=>SEXO:\t\t\tFEMENINO\n");
								}
								if(EMP[x].STAT==1)
								{
									printf("\t\t\t=>ESTATUS:\t\tDISPONIBLE\n");
								}
								else
								{
									printf("\t\t\t=>ESTATUS:\t\tASIGNADO\n");
								}
					   			printf("\n\t\t\t=>PERFIL:\t\t%s\n",EMP[x].PERF);
					   			printf("\n\t\t\t=>FECHA DE NACIMIENTO:\t%d/%d/%d\n",ED[x].DIA,ED[x].MES,ED[x].ANIO);
								printf("\n\t\t\t=>EDAD:\t\t\t%d",EMP[x].FCHA);
								if(EMP[x].FUMA==0)
								{
									printf("\n\t\t\t=>FUMADOR:\t\tSI\n");
								}
								else
								{
									printf("\n\t\t\t=>FUMADOR:\t\tN0\n");
								}
								printf("\n\t\t\t=>SUMA ASEGURADA:\t$%d",EMP[x].SUMA_ASEG);
								printf("\n\t\t\t=>PRIMA TARIFA ANUAL:\t$%.2f\n\n",EMP[x].TARIFA);
								printf("\n\n\t\t\t   CLIC PARA VOLVER AL MENU");
								getch();
								MENU();
							}
							else
							{
								if(EMP[x].STAT==2)
								{
									system("cls");
									printf("\n\n\n\n\n\n\n\n\n\n\t\t\t EL EMPLEADO ESTA ASIGNADO");
									printf("\n\n\n\n\n\n\n\n\n\n\t\t\t  SE LE REGRESARA AL MENU");
									getch();
									MENU();
								}
							}
						}
						else
						{
							if((stricmp(buscar,EMP[x].ID)!=0)&&x==k-1)
							{
								system("cls");
								printf("\n\n\n\n\n\n\n\n\n\n\t\t\t EL EMPLEADO NO EXISTE:(");
								printf("\n\n\n\n\n\n\n\n\n\n\t\t\t  SE LE REGRESARA AL MENU");
								getch();
								system("cls");
								MENU();
							}
						}
					}
				}
				else
				{
					if(k<=0)
					{
						system("cls");
						printf("\n\n\n\n\n\n\n\n\n\n\t\tNO HAY EMPLEADOS REGISTRADOS PARA BUSCAR:(");
						getch();
						SUBMENU_BUSQUEDAS();
					}
				}
		break;
		
		case 2:
				if(i>=1)
				{
					system("cls");
					printf("\n\n\t\t\t---------MENU BUSQUEDA/EMPRESA---------\n\n");
					for(x=0;x<i;x++)
					{
						printf("\t\t\t>%s\n",EM[x].NAME);
					}
					printf("\n\n\n\t\t\t=>ID DE EMPRESA A BUSCAR:");
					fflush(stdin);
					gets(buscar);
					system("cls");
					printf("\n\t\t     LA EMPRESA BUSCA LOS SIGUIENTES PERFILES:\n\n");
					for(x=0;x<i;x++)
					{
						if(strcmp(buscar,EM[x].ID)==0)
						{
							for(y=0;y<j;y++)
							{
								if(strcmp(EM[x].ID,PE[y].ID_EM)==0)
								{
									printf("\t\t\t=>%s\n",PE[y].DESC);
								}
							}
			   				printf("\n\t\t\t   CLIC PARA VOLVER AL MENU");
			   				getch();
			   				system("cls");
			   				MENU();
			   			}
						else
						{
							if((stricmp(buscar,EM[x].ID)!=0)&&x==i-1)
							{
								system("cls");
								printf("\n\n\n\n\n\n\n\n\n\n\t\t\t  LA EMPRESA NO EXISTE:(");
								printf("\n\n\n\n\n\n\n\n\n\n\t\t\t  SE LE REGRESARA AL MENU");
								getch();
								system("cls");
								MENU();
							}
						}
					}
				}
				else
				{
					if(i<=0)
					{
						system("cls");
						printf("\n\n\n\n\n\n\n\n\n\n\t\tNO HAY EMPRESAS REGISTRADAS PARA BUSCAR:(");
						getch();
						SUBMENU_BUSQUEDAS();
					}
				}
		break;
		
		case 3:
		/*	//	if(i>=1&&k>=1)
			//	{
					system("cls");
					printf("\n\n\t\t\t---------MENU BUSQUEDA/EMPRESA---------\n\n");
					for(x=0;x<i;x++)
					{
						if(strcmp(EM[x].ID),EMP[x].)
					}
			//	}*/
		
		break;
		
		case 4:
				system("cls");
				MENU();
		break;	
	}

}

void ASIGNAR_EMPLEADO()
{
	int x=0,y=0,z=0,b=0,a=0;
	char asignar[' '],op1[' '];
	char asignar2[' '];
	int bandera=0,numerovalidado=0;
	
	system("cls");
	printf("\n\n\t\t---------MENU EMPRESA/ASIGNAR EMPLEADO---------\n\n");	
	printf("\n\n\n\n\t\t\t=>ID DE EMPRESA:");
	fflush(stdin);
	gets(asignar);
	system("cls");
	printf("\n\n\t\t---------MENU EMPRESA/ASIGNAR EMPLEADO---------\n\n\n");
	bandera=0;
	for(x=0;x<i;x++)
	{
		if(strcmp(asignar,EM[x].ID)==0)
		{
			bandera++;
			printf("%d",strcmp(asignar,EM[x].ID));
			getch();
			for(y=0;y<k;y++)
			{
				for(z=0;z<j;z++)
				{
					if((strcmp(EMP[y].PERF,PE[z].DESC)==0)&&(strcmp(EM[x].ID,PE[z].ID_EM)==0))
					{
						if(EMP[y].STAT==1)
						{
							printf("\t\t=>%s\t\t%4s\n\n",EMP[y].NAME,EMP[y].PERF);
						}
					}
					else
					{
						continue;
					}
				}
			}
		}
		else
		{
			if(strcmp(asignar,EM[x].ID)!=0&&x==i-1&&bandera==0)
			{
				printf(" %d",strcmp(asignar,EM[x].ID));
				getch();
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n\t\t\t  LA EMPRESA NO EXISTE:(");
				printf("\n\n\n\n\n\n\n\n\n\n\t\t\t  SE LE REGRESARA AL MENU");
				getch();
				system("cls");
				MENU();
			}
		}
	}
	
	printf("\n");
	do
	{
		bandera=0;
		printf("\t\t\t=>ID DE EMPLEADO A ASIGNAR:");
		fflush(stdin);
		gets(asignar2);
		for(y=0;y<i;y++)
		{
			for(x=0;x<k;x++)
			{
				if(strcmp(asignar2,EMP[x].ID)==0)
				{
					for(z=0;z<j;z++)
					{
						if((strcmp(EMP[x].PERF,PE[z].DESC)==0)&&strcmp(EM[y].ID,PE[z].ID_EM)==0)
						{
							bandera++;
							do
							{
								system("cls");
								printf("\n\n\t\t---------MENU EMPRESA/ASIGNAR EMPLEADO---------\n\n");
								printf("\t\t\t=>ID:\t\t\t%s\n",EMP[x].ID);
							   	printf("\n\t\t\t=>NOMBRE:\t\t%s\n",EMP[x].NAME);
								if(EMP[x].SEX==0)
								{
								   	printf("\t\t\t=>SEXO:\t\t\tHOMBRE\n");
								}
								else
								{
									printf("\t\t\t=>SEXO:\t\t\tFEMENINO\n");
								}
								if(EMP[x].STAT==1)
								{
									printf("\t\t\t=>ESTATUS:\t\tDISPONIBLE\n");
								}
								else
								{
									printf("\t\t\t=>ESTATUS:\t\tASIGNADO\n");
								}
								printf("\n\t\t\t=>PERFIL:\t\t%s\n",EMP[x].PERF);
							  	printf("\n\t\t\t=>FECHA DE NACIMIENTO:\t%d/%d/%d\n",ED[x].DIA,ED[x].MES,ED[x].ANIO);
								printf("\n\t\t\t=>EDAD:\t\t\t%d",EMP[x].FCHA);
								if(EMP[x].FUMA==0)
								{
									printf("\n\t\t\t=>FUMADOR:\t\tSI\n");
								}
								else
								{
									printf("\n\t\t\t=>FUMADOR:\t\tN0\n");
								}
								printf("\n\t\t\t=>SUMA ASEGURADA:\t$%d",EMP[x].SUMA_ASEG);
								printf("\n\t\t\t=>PRIMA TARIFA ANUAL:\t$%.2f\n\n",EMP[x].TARIFA);
								printf("\n\t\t\tASIGNAR?(1/SI 2/NO):");
								fflush(stdin);
								gets(op1);
								b=VALIDAR_SOLO_NUMEROS(op1);
								numerovalidado=atoi(op1);
								if(b==0||numerovalidado<1||numerovalidado>2)
								{
									system("cls");
									printf("\n\n\t\t---------MENU EMPRESA/ASIGNAR EMPLEADO---------\n\n");
								}
								if(numerovalidado==2)
								{
									system("cls");
									printf("\n\n\n\n\n\n\n\n\n\n\t\t\t EL EMPLEADO NO SE ASIGNO");
									printf("\n\n\n\n\n\n\n\n\n\n\t\t\t  SE LE REGRESARA AL MENU");
									getch();
									system("cls");
									MENU();
								}
								if(numerovalidado==1)
								{
									strcpy(EM[i].ASIGN,EMP[y].ID);
									
									printf("%s",EM[i].ASIGN);
									getch();
									system("cls");
									printf("\n\n\n\n\n\n\n\n\n\n\t\t     EL EMPLEADO SE ASIGNO CORRECTAMENTE");
									printf("\n\n\n\n\n\n\n\n\n\n\t\t\t  SE LE REGRESARA AL MENU");
									getch();
									system("cls");
									MENU();
								}
							}while(b==0||numerovalidado<1||numerovalidado>2);
						}
						else
						{
							if((strcmp(EMP[x].PERF,PE[z].DESC)==0)&&strcmp(EM[y].ID,PE[z].ID_EM)==0&&y==i-1&&x==k-1&&z==j-1)
							{
								system("cls");
								printf("\n\n\n\n\n\n\n\t\t\t\tBIEN");
								getch();
								MENU();
							}
						}
					}
				}
				else
				{
				if(strcmp(asignar2,EMP[x].ID)!=0&&x==k-1&&bandera==0)
				{
					printf(" %d",strcmp(asignar2,EMP[x].ID));
					getch();
					system("cls");
					printf("\n\n\n\n\n\n\n\n\n\n\t\t\t  EL EMPLEADO NO EXISTE:(");
					printf("\n\n\n\n\n\n\n\n\n\n\t\t\t  SE LE REGRESARA AL MENU");
					getch();
					system("cls");
					MENU();
				}
			}
		}
	}
}while(bandera>0);
	
	getch();
	MENU();
}

int VALIDAR_SOLO_LETRAS(char x[' ']) //FUNCION QUE SOLO ADMITE LETRAS (LEE ESPACIOS)//
{
	int k=0,bandera=0,bandera1=0;
	
	for(k=0;x[k];k++)
	{
		if((x[k]>=97&&x[k]<=122)||(x[k]>=65&&x[k]<=90)||x[k]==32)
		{
			bandera1++;
		}
		else
		{
			bandera++;
		}
	}
	if(bandera>0)
	{
		return bandera;
	}
}

int VALIDAR_USUARIO(char x[' ']) //FUNCION QUE SOLO PERMITE LETRAS,NUMERO Y GUION BAJO (NO LEE ESPACIOS)//
{
	int k=0,bandera=0,bandera1=0;
	
	for(k=0;x[k];k++)
	{
		if((x[k]>=97&&x[k]<=122)||(x[k]>=65&&x[k]<=90)||(x[k]>=48&&x[k]<=57)||(x[k]==95))
		{
			bandera1++;
		}
		else
		{
			bandera++;
		}
	}
	if(bandera>0)
	{
		return bandera;
	}
}

int VALIDAR_CONTRASENIA(char x[' ']) //FUNCION QUE PERMITE SOLO NUMEROS Y LETRAS (NO LEE ESPACIOS)//
{
	int k=0,bandera=0,bandera1=0;
	
	for(k=0;x[k];k++)
	{
		if((x[k]>=97&&x[k]<=122)||(x[k]>=65&&x[k]<=90)||(x[k]>=48&&x[k]<=57))
		{
			bandera1++;
		}
		else
		{
			bandera++;
		}
	}
	if(bandera>0)
	{
		return bandera;
	}
}

int VALIDAR_CORREO(char x[' ']) //FUNCION QUE ADMITE LETRAS,NUMERO,@,GUION BAJO,GUION MEDIO Y PUNTO (NO LEE ESPACIOS)//
{
	int k=0,bandera=0,bandera1=0;
	
	for(k=0;x[k];k++)
	{
		if((x[k]>=97&&x[k]<=122)||(x[k]>=65&&x[k]<=90)||(x[k]>=48&&x[k]<=57)||(x[k]==64)||(x[k]==45)||(x[k]==95)||(x[k]==46))
		{
			bandera1++;
		}
		else
		{
			bandera++;
		}
	}
	if(bandera>0)
	{
		return bandera;
	}
}

int VALIDAR_TELEFONO(char x[' '])//FUNCION QUE SOLO ADIMITE NUMEROS (NO LEE ESPACIOS)//
{
	int k=0,bandera=0,bandera1=0;
	
	for(k=0;x[k];k++)
	{
		if(x[k]>=48&&x[k]<=57)
		{
			bandera1++;
		}
		else
		{
			bandera++;
		}
	}
	if(bandera>0)
	{
		return bandera;
	}
}

int VALIDAR_LETRAS_CON_NUMEROS(char x[' ']) //FUNCION QUE ADMITE LETRAS Y NUMEROS GUION MEDIO Y BAJO(LEE ESPACIOS)//
{
	int k=0,bandera=0,bandera1=0;
	
	for(k=0;x[k];k++)
	{
		if((x[k]>=97&&x[k]<=122)||(x[k]>=65&&x[k]<=90)||(x[k]>=48&&x[k]<=57)||(x[k]==32)||(x[k]==45)||x[k]==95)
		{
			bandera1++;
		}
		else
		{
			bandera++;
		}
	}
	if(bandera>0)
	{
		return bandera;
	}
}

int VALIDAR_SOLO_NUMEROS(char x[' ']) //FUNCION QUE SOLO ACEPTA NUMERO Y REGRESA EL NUMERO INGRESADO EN CARACTER COMO ENTERO
{
	int i=1;
	for(i=0;i<strlen(x);i++)
	{
		if(isdigit(x[i]))
		{
			continue;
		}
		else
		{
			return 0;
		}
	}
}

float VERIFICACION(int suma_asegurada,int edad)
{
	float prima_riesgo,tarifa_anual;
	
	switch(edad)
	{
		case 12:
				prima_riesgo=suma_asegurada*0.000396;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;	
		break;
		
		case 13:
				prima_riesgo=suma_asegurada*0.000427;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;	
		break;	
		
		case 14:
				prima_riesgo=suma_asegurada*0.000460;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;	
		break;	
		
		case 15:
				prima_riesgo=suma_asegurada*0.000495;	
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;	
		break;	
		
		case 16:
				prima_riesgo=suma_asegurada*0.000533;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;	
		break;
		
		case 17:
				prima_riesgo=suma_asegurada*0.000575;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;		
		break;	
		
		case 18:
				prima_riesgo=suma_asegurada*0.000619;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;		
		break;
		
		case 19:
				prima_riesgo=suma_asegurada*0.000667;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;		
		break;	
		
		case 20:
				prima_riesgo=suma_asegurada*0.000718;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;		
		break;
		
		case 21:
				prima_riesgo=suma_asegurada*0.000773;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;		
		break;	
		
		case 22:
				prima_riesgo=suma_asegurada*0.000833;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;		
		break;	
		
		case 23:
				prima_riesgo=suma_asegurada*0.000897;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;		
		break;
		
		case 24:
				prima_riesgo=suma_asegurada*0.000966;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 25:
				prima_riesgo=suma_asegurada*0.001041;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;		
		
		case 26:
				prima_riesgo=suma_asegurada*0.001121;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 27:
				prima_riesgo=suma_asegurada*0.001207;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 28:
				prima_riesgo=suma_asegurada*0.001300;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;	
		break;	
		
		case 29:
				prima_riesgo=suma_asegurada*0.001400;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 30:
				prima_riesgo=suma_asegurada*0.001508;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;
		
		case 31:
				prima_riesgo=suma_asegurada*0.001624;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 32:
				prima_riesgo=suma_asegurada*0.001749;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;
		
		case 33:
				prima_riesgo=suma_asegurada*0.001884;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 34:
				prima_riesgo=suma_asegurada*0.002029;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 35:
				prima_riesgo=suma_asegurada*0.002186;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 36:
				prima_riesgo=suma_asegurada*0.002354;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 37:
				prima_riesgo=suma_asegurada*0.002535;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 38:
				prima_riesgo=suma_asegurada*0.002730;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 39:
				prima_riesgo=suma_asegurada*0.002940;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 40:
				prima_riesgo=suma_asegurada*0.003166;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;	
		break;	
		
		case 41:
				prima_riesgo=suma_asegurada*0.003410;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;	
		break;
		
		case 42:
				prima_riesgo=suma_asegurada*0.003672;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 43:
				prima_riesgo=suma_asegurada*0.003954;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 44:
				prima_riesgo=suma_asegurada*0.004258;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;
		
		case 45:
				prima_riesgo=suma_asegurada*0.004585;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 46:
				prima_riesgo=suma_asegurada*0.004938;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 47:
				prima_riesgo=suma_asegurada*0.005317;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 48:
				prima_riesgo=suma_asegurada*0.005725;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 49:
				prima_riesgo=suma_asegurada*0.006164;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 50:	
				prima_riesgo=suma_asegurada*0.006637;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;		
		
		case 51:
				prima_riesgo=suma_asegurada*0.007145;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;
		
		case 52:
				prima_riesgo=suma_asegurada*0.007693;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 53:
				prima_riesgo=suma_asegurada*0.008282;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 54:
				prima_riesgo=suma_asegurada*0.008915;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 55:
				prima_riesgo=suma_asegurada*0.009597;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 56:
				prima_riesgo=suma_asegurada*0.010330;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 57:
				prima_riesgo=suma_asegurada*0.011119;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 58:
				prima_riesgo=suma_asegurada*0.011967;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 59:
				prima_riesgo=suma_asegurada*0.012879;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 60:
				prima_riesgo=suma_asegurada*0.013860;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 61:
				prima_riesgo=suma_asegurada*0.014914;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 62:
				prima_riesgo=suma_asegurada*0.016048;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;
		
		case 63:
				prima_riesgo=suma_asegurada*0.017265;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 64:
				prima_riesgo=suma_asegurada*0.018574;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 65:
				prima_riesgo=suma_asegurada*0.019980;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;	
		break;	
		
		case 66:
				prima_riesgo=suma_asegurada*0.021490;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;
		
		case 67:
				prima_riesgo=suma_asegurada*0.023111;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;
		
		case 68:
				prima_riesgo=suma_asegurada*0.024851;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 69:
				prima_riesgo=suma_asegurada*0.026720;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 70:
				prima_riesgo=suma_asegurada*0.028724;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 71:
				prima_riesgo=suma_asegurada*0.030874;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 72:
				prima_riesgo=suma_asegurada*0.033180;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 73:
				prima_riesgo=suma_asegurada*0.035651;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 74:
				prima_riesgo=suma_asegurada*0.038300;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 75:
				prima_riesgo=suma_asegurada*0.041136;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;	
		break;	
		
		case 76:
				prima_riesgo=suma_asegurada*0.044174;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 77:
				prima_riesgo=suma_asegurada*0.047424;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 78:
				prima_riesgo=suma_asegurada*0.050902;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 79:
				prima_riesgo=suma_asegurada*0.054619;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 80:
				prima_riesgo=suma_asegurada*0.058592;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 81:
				prima_riesgo=suma_asegurada*0.062834;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 82:
				prima_riesgo=suma_asegurada*0.067362;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 83:
				prima_riesgo=suma_asegurada*0.072190;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;	
		break;	
		
		case 84:
				prima_riesgo=suma_asegurada*0.077337;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 85:
				prima_riesgo=suma_asegurada*0.082817;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 86:
				prima_riesgo=suma_asegurada*0.088649;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 87:
				prima_riesgo=suma_asegurada*0.094850;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 88:
				prima_riesgo=suma_asegurada*0.101436;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 89:
				prima_riesgo=suma_asegurada*0.108424;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 90:
				prima_riesgo=suma_asegurada*0.115832;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 91:
				prima_riesgo=suma_asegurada*0.123677;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 92:
				prima_riesgo=suma_asegurada*0.131973;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 93:
				prima_riesgo=suma_asegurada*0.140737;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 94:
				prima_riesgo=suma_asegurada*0.149983;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 95:
				prima_riesgo=suma_asegurada*0.159723;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 96:
				prima_riesgo=suma_asegurada*0.169970;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 97:
				prima_riesgo=suma_asegurada*0.180733;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 98:
				prima_riesgo=suma_asegurada*0.192020;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 99:
				prima_riesgo=suma_asegurada*0.203837;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
		
		case 100:
				prima_riesgo=suma_asegurada*1.000000;
				tarifa_anual=(prima_riesgo)/(1-0.13-0.4-0.05);
				return tarifa_anual;
		break;	
	}
}
