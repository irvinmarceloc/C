/*Este programa convierte un numero arabigo a romano*/
#include<stdio.h>
void main()
{
	int  Vn[13]={ 1000, 900, 500, 400, 100, 90, 50, 40,   10, 9, 5, 4, 1 }, numero, i;
	char *Vc[13]={"m","cm","d","cd", "c","xc","l","xl",  "x","ix","v","iv","i"};
	/*Validacion de entrada LA MAXIMA ENTRADA QUE PUEDE SER REPRESENTADA EN ESTA NOTACION ES 3999 Y MAYOR A CERO*/
	do{ 
		printf("\nEntrada: ");
		scanf("%d",&numero);
	} while (numero>3999 || numero<0);		
	/*Este bloque imprime cada digito romano que corresponde a un intervalo usando las condiciones planteadas en el problema*/
	printf("\nSalida : ");
	while(numero) {	
		if (numero >= 1000) {
			printf("%s",Vc[12]);
			numero -= 1000;
		}else{
				for (i=11;i;--i) 
					if (numero >= Vn[i + 1] && numero < Vn[i]) {	
						printf("%s",Vc[i + 1]);
						numero -= Vn[i + 1];
					}
		}
	} //Fin del bloque de impresion
	printf("\n\n");    
}