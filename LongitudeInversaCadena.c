/* 
Realiza una función para obtener la cantidad de caracteres
que posee la palabra y otra  invertir la cadena.
*/
#include <stdio.h>

int longitud(char *);
void inversa(char *, int );
void swap(char *, char *);

int main(int argc, char const *argv[])
{
	char cadena[101], *v; 
	
	printf("\nEntrada: ");
	scanf("%s",cadena); 
	
	v = cadena;
	int strlen = longitud(v);
	inversa(cadena, strlen);
	printf("Cantidad de caracteres de la palabra: %i", strlen);
	printf("\nCadena inversa: %s\n\n", v);
	return 0;
}

int longitud(char *v){
	int i =0;
	while(v[i] != '\0') i++;
	return i;
}

void inversa (char *v, int longitud){
	int n = longitud / 2;
	int i, j = longitud - 1;
	for (i = 0; i < n; ++i)	swap(&v[i], &v[j-i]);
}

void swap(char *element1Ptr, char *element2Ptr){
	int temp;
	temp = *element1Ptr;
	*element1Ptr = *element2Ptr;
	*element2Ptr = temp;
}