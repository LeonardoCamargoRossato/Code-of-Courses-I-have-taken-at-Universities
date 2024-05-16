// LISTA 6 - lEONARDO CAMARGO ROSSATO //
// MATRICULA: 201613053 //
// #####   E X E R C I C I O - 01 #####//

#include <stdio.h>
#include <stdlib.h>

int captura (int n, int* vet)
{
    printf("Digite os valores do vetor: ");
    for (int i = 0; i<n; ++i)
        scanf("%d", &vet[i]);
}

int par (int n, int* vet)
{
    printf("\n\nEsses sãos os pares que há no vetor: \n Pares = {");

    for (int i = 0; i<n; ++i)
    {
        if (vet[i]%2 == 0 || vet[i] == 0)
            printf (" %d", vet[i]);
    }
    printf(" }\n");
}

int main ()
{
    int n;
    int* vet;

    printf("\nDigite a cardinalidade do vetor: ");
    scanf("%d",&n);

    captura (n,vet);
    par(n,vet);

    return 0;
}
