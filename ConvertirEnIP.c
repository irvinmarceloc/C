#include <stdio.h>
int potencia_2(int n ){
	if (n==0) return 1;
	if (n==1) return 2;
	if (n==2) return 4;
	if (n==3) return 8;
	if (n==4) return 16;
	if (n==5) return 32;
	if (n==6) return 64;
	if (n==7) return 128;
}

//OBS no sabía como hacer para ingresar un numero de 32 digitos por teclado por que lo maximo que conzco son meter 19 digitos por teclado
//Otra opcion era usar cadenas pero eso es un vector 
//El principal problema fue la lectura de los numeros 

int main(int argc, char const *argv[])
{
	char a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc,dd,ee,ff;
	int cantidad,con ,a_out,b_out,c_out,d_out;
	do
	{
		printf("\nCantidad de IP> ");
		scanf("%d", &cantidad);
	} while (cantidad>9 || cantidad<1);
	
	for ( con = 0; con < cantidad; ++con)
	{

			printf("\nEntrada >  ");
			scanf(" %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c",&a,&b,&c,&d,&e,&f,&g,&h,&i,&j,&k,&l,&m,&n,&o,&p,&q,&r,&s,&t,&u,&v,&w,&x,&y,&z,&aa,&bb,&cc,&dd,&ee,&ff);
			//printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc,dd,ee,ff);
		
			a_out = (a - 48)*potencia_2(7) + (b - 48)*potencia_2(6) + (c - 48)*potencia_2(5) + (d - 48)*potencia_2(4) + (e - 48)*potencia_2(3) + (f - 48)*potencia_2(2) + (g - 48)*potencia_2(1) +(h - 48);

			b_out = (i - 48)*potencia_2(7) + (j - 48)*potencia_2(6) + (k - 48)*potencia_2(5) + (l - 48)*potencia_2(4) + (m - 48)*potencia_2(3) + (n - 48)*potencia_2(2) + (o - 48)*potencia_2(1) +(p - 48);
			
			c_out = (q - 48)*potencia_2(7) + (r - 48)*potencia_2(6) + (s - 48)*potencia_2(5) + (t - 48)*potencia_2(4) + (u - 48)*potencia_2(3) + (v - 48)*potencia_2(2) + (w - 48)*potencia_2(1) +(x - 48);

			d_out = (y - 48)*potencia_2(7) + (z - 48)*potencia_2(6) + (aa - 48)*potencia_2(5) + (bb - 48)*potencia_2(4) + (cc - 48)*potencia_2(3) + (dd - 48)*potencia_2(2) + (ee - 48)*potencia_2(1) +(ff - 48);

			printf("\n\nSalida > %d.%d.%d.%d \n\n",a_out,b_out,c_out,d_out);
						
	}

	return 0;
} 