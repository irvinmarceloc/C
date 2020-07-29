 #include<stdio.h>
int main(int argc, char const *argv[])
{
	int i,n,j, k;
	printf("\n Cantidad de linea> ");
	scanf("%i", &n);
	for (i = 0; i < n; ++i){
		for(k = n  ; k > i ; k--) printf(" ") ;
		for (j = 0; j < 2*i + 1; ++j)
		{
			if (j*11 % 2 == 0 ) printf("*");
			else printf("O");
		}
		printf("\n");
	}
	return 0;
}
