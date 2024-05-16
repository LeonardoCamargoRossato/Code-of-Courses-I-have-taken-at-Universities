// LISTA 6 - lEONARDO CAMARGO ROSSATO //
// MATRICULA: 201613053 //
// #####   E X E R C I C I O - 02 #####//

#include <stdio.h>
#include <stdlib.h>

void captura (int n, int* vet)
{
    printf("Digite os valores do vetor: ");
    for (int i = 0; i<n; ++i)
        scanf("%d", &vet[i]);
}

void inverte (int n, int* vet)
{
    printf("\n\nVetor Invertido = {");

    for (int i = n-1; i>=0; --i)
    {
        int vet_invertido = vet[i];
        printf(" %d", vet_invertido);
    }
    printf(" }\n");
}

int main()
{
    int n;
    int* vet;
    printf("\nDigite o tamanho do vetor: ");
    scanf("%d", &n);

    captura(n,vet);
    inverte(n,vet);

    return 0;
}
