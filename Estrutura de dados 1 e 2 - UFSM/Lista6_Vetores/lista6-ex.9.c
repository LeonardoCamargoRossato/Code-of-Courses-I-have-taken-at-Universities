// LISTA 6 - lEONARDO CAMARGO ROSSATO //
// MATRICULA: 201613053 //
// #####   E X E R C I C I O - 09 #####//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float captura (int nA,int nB, float* a, float* b) {

	printf("Digite os coeficientes do polinomio A: \n ---> ");

	for (int i = 0; i < nA; i++)
		scanf("%f", &a[i]);

	printf("Digite os coeficientes do polinomio B: \n ---> ");

	for (int i = 0; i < nB; i++)
		scanf("%f", &b[i]);
}

int max (int nA,int nB)
{
    if (nA > nB)
        return nA;
    else
        return nB;
}

float soma_polinomio(int nA,int nB, float* a,float* b,float* c)
{
    printf("\n\nSoma dos Polinômios:\n ---> S = { ");
    if (nA > nB){
        for (int i = 0; i<nA; i++){
            c[i] = a[i] + b[i];
            printf("%f ",c[i]);
        }
    }
    else{
        for (int i = 0; i<nB; i++){
            c[i] = a[i] + b[i];
            printf("%f ",c[i]);
        }
    }
    printf("}");
}

float produto_polinomio(int nA,int nB, float *a,float *b,float *d)
{
    int m = (nA+nB) - 1;
    printf("\n\Produto dos Polinômios:\n ---> P = { ");

    if (nA>nB){
        for (int k = 0; k<m; k++)
        {
            d[k]=0.0;
            for (int i = 0; i<k; i++)
            {
                if ((i<nA) && ((k-1) < nA))
                {
                    d[k] = d[k] + a[i]*b[k-i];
                }
            }
            printf("%f ",d[k]);
        }
        printf("}\n");
    }
    else
        for (int k = 0; k<m; k++)
        {
            d[k];
            for (int i = 0; i<=k; i++)
            {
                if ((i<nB) && ((k-1) < nB))
                {
                    d[k] = d[k] + a[i]*b[k-i];
                }
            }
            printf("%f ",d[k]);
        }

        printf("}\n");
}

int main () {

	int nA,nB; //Cardinalidade dos Polinômios (tamanho do vetor)

	printf("\nFUNCAO P/ CALC. SOMA E PRODUTO DE POLINÔMIOS \n\n");
	printf("Digite a cardinalidade do polinômio A e do B: \n ---> ");
	scanf("%d %d",&nA,&nB);


    float* a = (float*)calloc(nA,sizeof(float));
    float* b = (float*)calloc(nB,sizeof(float));

    int maxi = max(nA,nB);
    float* c = (float*)calloc(maxi,sizeof(float));
    float* d = (float*)calloc(nA+nB-1,sizeof(float));

	captura(nA,nB,a,b);
	soma_polinomio(nA,nB,a,b,c);
    produto_polinomio(nA,nB,a,b,d);

	//printf("\n\nSoma dos Polinômios: %f \n", s);
	//printf("Produto dos Polinômios: %f \n", p);

	return 0;
}
