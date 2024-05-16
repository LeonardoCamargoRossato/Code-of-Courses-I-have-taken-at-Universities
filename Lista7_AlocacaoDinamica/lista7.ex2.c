#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int captura (int n, int* v){
    printf("Digite os valores do vetor: \n --> ");
    for (int i = 0; i < n; ++i)
        scanf("%d",&v[i]);
}

int somente_pares (int n, int* v, int* npares){

    printf("\n\nValores pares = {");
    int cont = 0;
    for (int i = 0; i<n; ++i){
        if (v[i]%2 == 0){
            cont = 1 + cont;
            printf(" %d",v[i]);
        }

    }
    printf(" } \n");
    printf("Dimensão do Vetor dos Pares: %d \n",cont);
    return *npares=cont;
}

int main(){
    int n;
    printf("Digite a dimensão do vetor de entrada: \n --> ");
    scanf("%d",&n);

    int* v = (int*)malloc(n*sizeof(int));
    int* npares = (int*)malloc(n*sizeof(int));
    captura(n,v);
    somente_pares(n,v,npares);
    free(v);

    int r = *npares;
    free(npares);


    return r;
}
