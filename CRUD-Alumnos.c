#include <stdio.h>

typedef struct 
{
	int id;
	char name[30];
	int sex;
	int exam1;
	int exam2;
	int tot;
}alumno;
alumno alumnos[20];
int i; 

void agregar (){
	for (i = 0; i < 20; ++i){
		printf("\nid = %d ", i);
		alumnos[i].id = i;
		printf("\nNombre: ");
		scanf(" %s",alumnos[i].name);
		printf("\nSexo: M...1 F...2: ");
		scanf("%d",&alumnos[i].sex);
		printf("\nExamen 1 : ");
		scanf("%d",&alumnos[i].exam1);
		printf("\nExamen 2 : ");
		scanf("%d",&alumnos[i].exam2);
		alumnos[i].tot = alumnos[i].exam1 + alumnos[i].exam2;
	}
}
void eliminar(){
	printf("\nIngrese ID del estudiante que desea eliminar: ");
	scanf("%d", &i);
	alumnos[i].id = -1;
	alumnos[i].name[0] = '\0';
	alumnos[i].sex = 0 ;
	alumnos[i].exam1 = 0;
	alumnos[i].exam2 = 0;
	alumnos[i].tot = 0;
}

void actualizar(){
	printf("\nIngrese ID del estudiante que desea Actualizar: ");
	scanf("%d", &i);
	printf("\nNombre: ");
	scanf("%s",alumnos[i].name);
	printf("\nSexo: M...1 F...2: ");
	scanf("%d",&alumnos[i].sex);
	printf("\nExamen 1 : ");
	scanf("%d", &alumnos[i].exam1);
	printf("\nExamen 2 : ");
	scanf("%d", &alumnos[i].exam2);
	alumnos[i].tot = alumnos[i].exam1 + alumnos[i].exam2;
}

void ver_registros(){
	printf("\nTodos los registros de estudiantes");
	printf("\nid Nombre Sexo Examen 1 Examen 2 Total");
	for (i = 0; i < 20; ++i) 
	if (alumnos[i].id!=-1)
	printf("\n%d %s %c       %d        %d        %d", alumnos[i].id, alumnos[i].name, alumnos[i].sex, alumnos[i].exam1, alumnos[i].exam2, alumnos[i].tot);
}

void ordenar(){
	int j;
	alumno temp;
	for (i=1;i<20;i++)
	{
       for (j=0; j < 20-i ;j++) 
       {
          if (alumnos[j].tot < alumnos[j+1].tot)
          {
            temp=alumnos[j];
            alumnos[j]=alumnos[j+1];
            alumnos[j+1]=temp;
          }
       }
	}
}



int main(int argc, char const *argv[])
{
	char salir;
	int  opt, max;
	do{
	
		do
		{
			printf("\n==================================\nMenu\n==================================\n");
			printf("1. Agregar registros de estudiantes");
			printf("\n2. Eliminar registros de estudiantes");
			printf("\n3. Actualizar registros de estudiantes");
			printf("\n4. Ver todos los registros de estudiantes");
			printf("\n5. Calcular un promedio de las calificaciones de un estudiante seleccionado");
			printf("\n6. Mostrar el estudiante que obtiene la puntuación maxima");
			printf("\n7. Mostrar el estudiante que obtiene la puntuación minima");
			printf("\n8. Buscar por ID");
			printf("\n9. Ordenar registros por puntajes totales\n______:");
			scanf("%d", &opt);
		} while (opt<0 && opt>10);		

		switch(opt){
			case 1: 
				agregar();
				break;
			case 2: 
				eliminar();
				break; 
			case 3: 
				actualizar();
				break;
			case 4: 
				ver_registros();
				break;
			case 5: 
				printf("\nIngrese ID del estudiante que desea Calcular el promedio de calificaciones: ");
				scanf("%d", &i);
				printf("\nEl promedio de calificaciones es : %.1f", (float) (alumnos[i].tot)/2 );
				break;
			case 6: 
				max = 0;
				for (i = 0; i < 20; ++i) if (alumnos[i].id != -1 && alumnos[i].tot>max)	max = i;
				printf("\nEl alumno con maxima califiacion es %s y es de %d ",alumnos[i].name, alumnos[i].tot);
				break;
			case 7: 
				for (i = 0; i < 20; ++i) if (alumnos[i].id != -1 && alumnos[i].tot>max)	max = i;
				int min = alumnos[i].tot;
				for (i = 0; i < 20; ++i) if (alumnos[i].id != -1 && alumnos[i].tot<min)	min = i;
				printf("\nEl alumno con minima califiacion es %s y es de %d ",alumnos[i].name, alumnos[i].tot);
				break;
			case 8: 
				printf("\nBuscar un estudiantes por ID: ");
				scanf("%d", &i);
				printf("\nResultado: ");
				printf("%d %s %c %d %d %d", alumnos[i].id, alumnos[i].name, alumnos[i].sex, alumnos[i].exam1, alumnos[i].exam2, alumnos[i].tot);
				break;
			case 9:
				ordenar();
				ver_registros();
				break;
		}

		do
		{
			printf("\nDesea salir del menú? \nNo = 0\nSi = 1\n====> ");
			scanf(" %c", &salir);
			salir = salir - '0';
		} while (salir!=0 && salir!=1);

	} while (salir==0);	

	return 0;
}