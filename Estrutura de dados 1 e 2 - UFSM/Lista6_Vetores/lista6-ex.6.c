// LISTA 6 - lEONARDO CAMARGO ROSSATO //
// #####   E X E R C I C I O - 06 #####//
// MATRICULA: 201613053 //

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void captura(int n, float* v)
{
    printf("Digite o conjunto de valores do vetor: ");
    for (int i = 0; i<n; ++i)
        scanf("%f", &v[i]);
}

float geometrica (int n, float* v)
{
    float g = 1;
    for (int i = 1; i<n; ++i)
        g = g*v[i];

    return g = pow(g,1.0/n);
}

float main()
{
    printf("\nFUNCAO P/ CALC. MEDIA GEOMETRICA \n\n");

    int n;
    float* v;
    printf("Digite a cardinalidade do conjunto: ");
    scanf("%d",&n);

    captura(n,v);
    float g = geometrica(n,v);
    printf("\n\nMedia Geometrica do Conjunto: %f \n", g);

    return 0;
}
