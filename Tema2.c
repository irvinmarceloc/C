/*
	TEMA 2 del segundo final, detalles y consideraciones 

		1. Version del compilador  gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0

		2. Aunque también se ejecuta en el compilador web que esta recomendando en educa

		3. Yo verifiqué la compilacion correcta de este tema en el entorno mencionado, lenguaje C
*/


#include <stdio.h>
#include <string.h>

/*Función obtenida de los materiales dispuestos en educa AulaVirtual // Bibliografia de Referencia // Punteros_deitel.pdf */
/*Esta funcion intercambia los caracteres dentro de un arreglo*/
void swap(char *element1Ptr, char *element2Ptr){
	int temp;
	temp = *element1Ptr;
	*element1Ptr = *element2Ptr;
	*element2Ptr = temp;
}

/*Función autoria propia TAREA 6*/
/*Invierte una cadena*/
void inversa (char *v, int longitud){
	int n = longitud / 2;
	int i, j = longitud - 1;
	for (i = 0; i < n; ++i)	swap(&v[i], &v[j-i]);
}

/*Esta funcion la saque de mi segundo parcial adaptando para lo requerido, es de escritura propia*/
/*Convierte un numero y los carga en los punteros tipo cadena que apunta a conv y conv_invertido*/
void convertir (int num, char *conv, char *conv_invertido){	
	
	char dig[16] = {'0','1','2','3','4','5','6','7', '8','9','A','B', 'C','D','E','F'}, c;//c va ser un auxiliar para guardar caracteres
	int i=0, res;

	//Primera etapa de la conversion, sale con los digitos alrevez
	//Que tenga los digitos alrevez aprovecho para agregar un cero en caso de numero impar de digitos
	do
	{
		res = num % 16;
		num = num / 16;
		*(conv + i) = *(dig + res); 
		i++;
	} while (num >= 16);
	*(conv + i) = dig[num];
	*(conv + i + 1) = '\0';
	
	//Si es impar se agrega un cero al final, al invertir queda al principio
	if (strlen(conv)%2 != 0) { 
		*(conv + i + 1) = '0';
		*(conv + i + 2) = '\0';
	}

	//La conversion del paso anterior sale con los digitos invertidos, por eso esta funcion 
	inversa(conv, strlen(conv));

	//Se carga en conv_invertido las mitades invertidas
	strcpy(conv_invertido, conv);
	for (i = 0; i < strlen(conv)/2; ++i) swap(&*(conv_invertido + i), &*(conv_invertido + strlen(conv)/2 + i));
	
}


//Funcion principal
int main(int argc, char const *argv[])
{	
	int N, i;

	printf("\nN: ");
	scanf("%d",&N);

		
	int decimal;
	char cad[50], cad_intercambio[50];
	
	FILE *f = fopen ("salida.txt","w"); //Se declara el puntero
	fprintf(f,"En decimal		En hexadecimal		Intercambiado");

	for (i = 0; i < N; i++)
	{
		printf("Numero %d: ", i+1);
		scanf("%d", &decimal);
		convertir(decimal, cad, cad_intercambio);
		fprintf(f,"\n%d				%s		%s",decimal, cad, cad_intercambio);
	}

	printf("\nFin del proceso!\n");
	
	return 0;
}