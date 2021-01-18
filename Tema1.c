//Version del compilador 
//gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0

#include <stdio.h>
//Esta funcion va verificar si es N es potencia de dos
int potencia2(int n){
	while(n > 2){
		if (n % 2 == 0)
		{
			n  = n / 2; 
		} else return 1;
	}
	return 0;
}
//Esta es la funcion requerida por el problema 
#include <stdio.h>
#include <stdlib.h>

int** hadamard(int n);

int main(void) {
  int n, i, j;
  printf("\nN: ");
  scanf("%d",&n);
  int** mat = hadamard(n);
  //imprimir
  printf("Matriz hadamard\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (mat[i][j] == 0) printf("F ");
      if (mat[i][j] == 1) printf("V ");
    }
    printf("\n");
  }
  printf("\n");
  return 0;
}


int** hadamard(int n) {
  int i,j;

  int **m = (int**) malloc(sizeof(int*)*n);

  for (int k = 0; k < i; k++) {
    m[k] = (int*) malloc(sizeof(int)*n);
  }

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      m[i][j]= 0;
    }
  }

  int final, k = 1;

  while(k<=n){
    if (k==1){m[0][0] = 1;}  
    else {
      final = k / 2;
      for(i = 0; i < final; i++) {
        for(j = 0; j < final; j++) {
          m[i][final+j] = m[i][j];    
          m[final+i][j] = m[i][j];
          m[final + i][final + j] = !m[i][j];
        }
      }
    }
    k=2*k;
  }

  return m;
}