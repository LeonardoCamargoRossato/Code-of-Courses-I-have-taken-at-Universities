// LISTA 6 - lEONARDO CAMARGO ROSSATO //
// MATRICULA: 201613053 //
// #####   E X E R C I C I O - 08 #####//

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int captura (int n, int* v)
{
    printf("Digite o conjunto de valores do vetor: \n ---> ");

	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);
}

int testa_PA(int n, int* v)
{
    int k,m;
    for (int i = 1; i<n; i++){
        k = ( v[i] - v[0] )/i;
        printf("%d\n",k);
       // m = (v[i+2] - v[i+1])/k;
      //  printf("%d\n",m);
        //printf("(%d, %d) \n",k,m);
        //if (k != m)
          //  printf("(%d != %d)",k,m);
            //printf("Deu ruim, clã! Isso n é uma PA. \n");
            //return 0;
    }
    printf("Esse conjunto de valores é uma PA. \n");
}

int main()
{
    int n;
    printf("Digite a cardinalidade do conjunto: \n ---> ");
    scanf("%d",&n);

    int* v = (int*)malloc(n*sizeof(int));

    captura(n,v);
    testa_PA(n,v);

    return 0;
}
