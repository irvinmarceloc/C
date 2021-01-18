/*
	TEMA 1 del segundo final, detalles y consideraciones 

		1. Version del compilador  gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0

		2. Aunque también se ejecuta en el compilador web que esta recomendando en educa

		3. Yo verifiqué la compilacion correcta de este tema en el entorno mencionado, lenguaje C
*/


#include <stdio.h>

//Estas variables se declaran como globales por que son utilizadas en mas de una función
int M,N;

/*Esta funcion verifica si es que la matriz cumple o no con la condicion de ser monge*/
/*Retorna la cantidad de veces que no se cumple la condicion para ser Monge*/
/*La condicion que utilice la saque de Wikipedia, condicion necesaria y suficiente para que una matriz sea monge*/
/*https://en.wikipedia.org/wiki/Monge_array*/

int verifica(int *p){
	int i,j, a,b;
	int con = 0; //ese contador verifica cuantas veces no se cumple la relacion //Si es monge se mantiene en cero 
	for (i = 0; i < M - 1; ++i)
	{
		for (j = 0; j < N - 1; ++j)
		{
			a = *(p + N*i + j) + *(p + N*(i + 1) + (j + 1)); 
			b = *(p + N*i + j + 1) + *(p + N*(i + 1) + j);	
			if (a>b)//Cuando no se cumple la condicion sumamos 1, para saber la cantidad de veces que no se cumple
			{
				con++;
			}
		}
	}
	return con;
}


int main(int argc, char const *argv[])
{
	int i,j; 

	printf("\nNumero de filas: ");
	scanf("%d",&M);
	printf("\nNumero de columnas: ");
	scanf("%d",&N);

	//Inicializa matriz
	int mat[M][N];	


	//Apunta un elemento de la matriz al puntero
	//Por simplicidad para la aritmetica de punteros apuntamos al elemento 0 0 
	int *p = &mat[0][0];

	//Lectura de la matriz 
	for (i = 0; i < M; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			printf("M[%d][%d]: ", i,j);
			scanf("%d",&*(p + N*i + j));
		}
	}

	//Se envia la matriz a un puntero de la funcion, esta funcion retorna cero si es una matriz monge 
	int verificar = verifica(&mat[0][0]);


	//Se imprimen las salidas deseadas 
	if (verificar == 0)
	{
		printf("\nEs una matriz MONGE\n");
	}else{
		printf("\nLa matriz NO ES MONGE\n");
		printf("Cantidad de relaciones que no se cumplieron %d ", verificar);		
	}

	return 0;
}