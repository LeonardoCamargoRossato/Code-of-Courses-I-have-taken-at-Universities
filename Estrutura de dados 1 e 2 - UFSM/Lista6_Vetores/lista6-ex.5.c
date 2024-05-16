// LISTA 6 - lEONARDO CAMARGO ROSSATO //
// MATRICULA: 201613053 //
// #####   E X E R C I C I O - 05 #####//

#include <stdio.h>
#include <stdlib.h>

void captura(int n, float* v)
{
    printf("Digite o conjunto de valores do vetor: ");
    for (int i = 0; i<n; ++i)
        scanf("%f",&v[i]);
}

float harmonica (int n, float* v)
{
    float h = 0;
    for (int i = 0; i<n; ++i)
        h = h + 1.0/v[i];

    return h = 1.0/h;
}

float main()
{
    printf("\nFUNCAO P/ CALC. MEDIA HARMONICA \n\n");
    int n;
    float* v;
    printf("Digite a cardinalidade do conjunto: ");
    scanf("%d",&n);

    captura(n,v);
    float h = harmonica(n,v);
    printf("\n\nMedia Hamonica do Conjunto: %f \n",h);

    return 0;
}
