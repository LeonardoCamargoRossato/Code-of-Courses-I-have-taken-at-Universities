#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float captura (int n, float* v){
    printf("Digite os valores do Vetor: \n --> ");
    for (int i = 0; i < n; i++)
        scanf("%f", &v[i]);
}


float* reverso (int n, float* v){

    printf("\n\nVetor Reverso = { ");
    float *v_reverso = (float*)malloc(n*sizeof(float));
    for (int i = n-1; i>=0; --i){
        *v_reverso = v[i];
        printf(" %.2f", *v_reverso);
    }
    printf(" } \n");
}

void main (){
    int n;
    printf("\nDigite o tamanho do vetor: \n -->  ");
    scanf("%d",&n);

    float* v = (float*)malloc(n*sizeof(float));
    captura(n,v);
    reverso(n,v);
    free(v);

    return 0;
}
