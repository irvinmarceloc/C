//Version del compilador 
//gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0

#include <stdio.h>
int esprimo(int n){
	int i, div = 0;
	if (n == 2 || n == 3) return 1; 
	if (n<=0) return 0;
	if (n == 1) return 0;

	for (i = 2; i < n; ++i) if (n%i == 0) div++;

	if (div == 0) return 1;
	if (div > 0)  return 0;
}


int main()
{
	int n; 

	FILE *fEnt = fopen ("numeros.txt","r");
	FILE *fPrimo = fopen ("primos.txt","w");
	FILE *fPar = fopen ("pares.txt","w");
	FILE *fImpar = fopen ("impares.txt","w");

	while ( fscanf(fEnt, "%d", &n) != EOF){
		if (esprimo(n) == 1)
		{
			fprintf(fPrimo,"%d \n", n);
		} else {
			if (n%2 == 0 ) fprintf(fPar,"%d \n", n);
			else fprintf(fImpar,"%d \n", n);
		}
	}
	return 0;
}