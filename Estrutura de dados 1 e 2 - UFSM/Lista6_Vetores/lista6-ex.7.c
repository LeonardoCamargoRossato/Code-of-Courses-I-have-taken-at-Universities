// LISTA 6 - lEONARDO CAMARGO ROSSATO //
// MATRICULA: 201613053 //
// #####   E X E R C I C I O - 07 #####//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void captura (int n, float* v, float* w) {

	printf("Digite o conjunto de valores do vetor: \n ---> ");

	for (int i = 0; i < n; i++)
		scanf("%f", &v[i]);

	printf("Digite o conjunto dos respectivos pesos do vetor: \n ---> ");

	for (int i = 0; i < n; i++)
		scanf("%f", &w[i]);
}

float media_ponderada (int n, float* v, float* w) {

	float p1 = 0;
	for (int i = 0; i<n; ++i)
		p1 = p1 + v[i] * w[i];

	float p2 = 0;
	for (int i = 0; i<n; ++i)
		p2 = p2 + w[i];

	float p;
	return p = p1/p2;
}

int main () {

	int n; //Cardinalidade do conjunto (tamanho do vetor)

	printf("\nFUNCAO P/ CALC. MEDIA PONDERADA \n\n");
	printf("Digite a cardinalidade do conjunto: \n ---> ");
	scanf("%d",&n);


	//float* v; // Vetor de Valores
	//float* w; // Vetor dos Pesos

	//v = (float*) malloc(sizeof(float)*n);
	//w = (float*) malloc(sizeof(float)*n);

    float* v = (float*)calloc(n,sizeof(float));
    float* w = (float*)calloc(n,sizeof(float));

	captura(n, v, w);

	float p = media_ponderada(n, v, w);
	printf("\n\nMedia Ponderada do Conjunto: %f \n", p);
	return 0;
}
