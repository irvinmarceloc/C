#include<stdio.h> 

int main(int argc, char const *argv[])
{
	int cen,cantidad, i=0;
	int moneda[8] = {200,100,50,20,10,5,2,1};
	int division[16];
	printf("\nIndique cantidad de centimos: ");
	scanf("%d",&cen);
	do
	{
		cantidad = cen/moneda[i];
		cen = cen%moneda[i];
		division[2*i] = moneda[i];
		division[2*i+1] = cantidad;
		i++;
	} while (cen > 1);
	printf("\nMonedas necesarias: %d ",i);
	for(i=0;i< 8;i++) if(division[2*i +1] != 0 ) printf("\n %d monedas de %d centimo",division[2*i + 1], division[2*i]);
	return 0;
}

