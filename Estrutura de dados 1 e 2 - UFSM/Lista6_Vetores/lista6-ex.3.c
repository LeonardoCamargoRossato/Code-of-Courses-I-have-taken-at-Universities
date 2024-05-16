// LISTA 6 - lEONARDO CAMARGO ROSSATO //
// MATRICULA: 201613053 //
// #####   E X E R C I C I O - 03 #####//

#include <stdio.h>
#include <stdlib.h>

void captura (int n, float* v)
{
    printf("Digite os valores do vetor: ");
    for (int i = 0; i<n; ++i)
        scanf("%f", &v[i]);
}


float minimo (int n, float* v)
{
    if (n == 1)
        return v[0];
    else {
        float min_sub = minimo(n-1, &v[1]);
        return v[0] < min_sub ? v[0] : min_sub;
    }
}

float main()
{
    int n;
    float* v;
    printf("Digite o tamanho do vetor: ");
    scanf("%d",&n);

    captura(n,v);
    float min = minimo(n,v);
    printf("\n\nMinimo do Vetor: %f ", min);

    return 0;
}
