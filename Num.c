#include <stdio.h>

#define MAX 100000

void leer_arreglo(int arreglo[MAX], int tamano);
void ordenamiento(int arreglo[MAX], int tamano);
void imprimir_arreglo(int arreglo[MAX], int tamano);
void ordenar_por_cifras(int arreglo[MAX], int tamano);
int contar_cifras(int numero);
void cambio(int *a, int *b);

int main() 
{
    int tamano;
    scanf("%d", &tamano);
    int arreglo[MAX];
    leer_arreglo(arreglo, tamano);
    ordenamiento(arreglo, tamano);
    ordenar_por_cifras(arreglo, tamano);
    imprimir_arreglo(arreglo, tamano);
    return 0;
}

void leer_arreglo(int arreglo[MAX], int tamano)
{
    for (int i = 0; i < tamano; i++)
    {
        scanf("%d", &arreglo[i]);
    }
}

void ordenamiento(int arreglo[MAX], int tamano)
{
    for (int i = 1; i < tamano; i++)
    {
        int valor = arreglo[i];
        int j = i;
        while (j > 0 && arreglo[j - 1] > valor)
        {
            arreglo[j] = arreglo[j - 1];
            j = j - 1;
        }
        arreglo[j] = valor;
    }
}

void ordenar_por_cifras(int arreglo[MAX], int tamano)
{
    int i, j;
    for (i = 0; i < tamano - 1; i++)
    {
        for (j = i + 1; j < tamano; j++)
        {
            if (contar_cifras(arreglo[i]) == contar_cifras(arreglo[j]) && arreglo[i] < arreglo[j])
            {
                cambio(&arreglo[i], &arreglo[j]);
            }
        }
    }
}

int contar_cifras(int numero)
{
    int cifras = 0;
    while (numero != 0)
    {
        numero = numero / 10;
        cifras++;
    }
    return cifras;
}

void cambio(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void imprimir_arreglo(int arreglo[MAX], int tamano)
{
    for (int i = 0; i < tamano; i++)
    {
        printf("%d ", arreglo[i]);
    }
}

