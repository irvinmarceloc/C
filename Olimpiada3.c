#include<stdio.h>
#include<string.h>
int main(int argc, char const *argv[])
{
	char cadena[50],resultado[50], cifrar_descifrar[1];
	int cesar,i, c_d = 1;
	printf("\nCifrar o descifrar ");
	scanf("%s",cifrar_descifrar);
	printf("\nNumero del Cesar ");
	scanf("%d",&cesar);	
	printf("\nCadena ");
	scanf("%s",cadena);
	if (cifrar_descifrar[0] == "d") c_d = -1;
	else c_d = 1;
	
	for ( i = 0; i < strlen(cadena); ++i)
	{
		resultado[i]=  c_d*cesar + cadena[i];
		if (resultado[i]> 122) resultado[i] = resultado[i] - 122 + 94;
	}

	resultado[strlen(cadena)] = "\0";
	
	printf("\nResultado: %s", resultado);
	return 0;
}
