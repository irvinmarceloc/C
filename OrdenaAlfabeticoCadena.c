/*Ordenar los elementos de una cadena en orden alfabético . 
(Todas las operaciones realizar con  Punteros)*/

#include <stdio.h>
#include <string.h>

void bubbleSort(char *, const int SIZE);
void swap(char *, char *);

int main(int argc, char const *argv[])
{
	char in[101], *input; 
	
	printf("\nEntrada: ");
	scanf("%s",in);

	input = in;

	bubbleSort(input,strlen(input));

	printf("Salida: %s\n",input);
	return 0;
}

void bubbleSort(char *array, const int SIZE){
	int pass, j;

	for (pass = 0; pass < SIZE ; pass++)
		for(j = 0; j< SIZE - 1; j++)
			if (array[j] > array[j+1])
				swap(&array[j],&array[j + 1]);
}

void swap(char *element1Ptr, char *element2Ptr){
	int temp;
	temp = *element1Ptr;
	*element1Ptr = *element2Ptr;
	*element2Ptr = temp;
}
