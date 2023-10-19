#include <stdio.h>

#define MAX 100000

typedef struct calificaciones 
{
	int calificacion_1;
	int calificacion_2;
	
}Tcalif;

void leer_c(Tcalif registros[MAX], int tamano);
void ordenar_calif(Tcalif registros[MAX], int tamano);
void imprimir(Tcalif registros[MAX], int tamano);

int main() 
{
	int tamano;
	scanf("%d",&tamano);
	Tcalif registros[MAX];
	leer_c(registros, tamano);
	ordenar_calif(registros, tamano);
	imprimir(registros, tamano);
	return 0;
}

void leer_c(Tcalif registros[MAX], int tamano)
{
	int i = 0;
	while(i < tamano)
	{
		scanf("%d",&registros[i].calificacion_1);
		scanf("%d",&registros[i].calificacion_2);
		i++;
	}
}

void ordenar_calif(Tcalif registros[MAX], int tamano)
{
	for (int i = 1; i < tamano; i++)
	{
		Tcalif valor = registros[i];
		int j = i;
		while (j > 0 && (registros[j - 1].calificacion_1 < valor.calificacion_1 
        || (registros[j - 1].calificacion_1 == valor.calificacion_1 && registros[j - 1].calificacion_2 > valor.calificacion_2)))
		{
			registros[j] = registros[j - 1];
			j = j - 1;
		}
		registros[j] = valor;
	}
}

void imprimir(Tcalif registros[MAX], int tamano)
{
	int i = 0;
	while(i<tamano)
	{
		printf("%d %d",registros[i].calificacion_1, registros[i].calificacion_2);
		printf("\n");
		i++;
	}
}