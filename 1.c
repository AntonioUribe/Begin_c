#include<stdio.h>
int A[10], i, N, B;

int main()
{
	printf("Programa que trabaja con punteros\n");
	for(i=0; i<10; i++)
	{
		printf("\nDa el valor: ");
		scanf("%d", A+i);
	}
	printf("\nQue numero quiere buscar? ");
	scanf("%d", &N);
	B=0;
	for(i=0; i<10; i++)
	{
		if( N==*(A+i) )
		{
			printf("\nEl numero %d esta en %d",N,i+1);
			B=1;
		}
	}
	if(B==0)
	printf("\nEl numero %d no existe",N);

	return 0;
}

