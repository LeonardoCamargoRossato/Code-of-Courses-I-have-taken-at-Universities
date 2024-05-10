//------------------------------------------------//
// Disciplina: Algoritmos e lógica de programação //
//------------------------------------------------//
// ATIVIDADE AVALIATIVA 2 //
// ALUNO: LEONARDO CAMARGO ROSSATO //
// MATRICULA: 2020520162 //
//------------------------------------------------//
// #####   E X E R C I C I O - 02 #####//
//------------------------------------------------//

#include<stdio.h>
#include <stdlib.h>

/*
	Nessa versão, a função calc_media:
	- lê valores de um vetor de dados; 
	- calcula a média; 
	- printa a média das notas de aluno por vez;
	- não retorna valor (é uma função "void").
*/
void calc_media(float *al){
	float media;
	media = (al[0] + 2*al[1] + 3*al[2] + 2*al[3])/8;
	printf( "\n Média Aluno = %.2f ", media);
}

/* A função principal está aqui apenas para:
   - Declarar Variáveis
   - Chamar Função que calcula as medias 
*/ 
int main(void)
{
	 //Declaração das Variáveis 
	  int i,n;
    float Al1[4],Al2[4],Al3[4],Al4[4],Al5[4],Al6[4],Al7[4],Al8[4],Al9[4],Al10[4];
        
    //Atribuição das Notas dos Alunos da Escola
		Al1[0] = 9; Al1[1] = 8; Al1[2] = 8.54; Al1[3] = 10;
		Al2[0] = 6; Al2[1] = 2; Al2[2] = 6.00; Al2[3] = 8;
		Al3[0] = 8; Al3[1] = 3; Al3[2] = 5.00; Al3[3] = 1;
		Al4[0] = 8; Al4[1] = 8; Al4[2] = 0.05; Al4[3] = 10;		
		Al5[0] = 7; Al5[1] = 3; Al5[2] = 6.00; Al5[3] = 8;
		Al6[0] = 7; Al6[1] = 8; Al6[2] = 8;2;  Al6[3] = 10;
		Al7[0] = 6; Al7[1] = 2; Al7[2] = 6.00; Al7[3] = 8;
		Al8[0] = 6; Al8[1] = 6; Al8[2] = 5.00; Al8[3] = 1;
		Al9[0] = 6; Al9[1] = 8; Al9[2] = 8.00; Al9[3] = 10;		
		Al10[0] = 4; Al10[1] = 2; Al10[2] = 6; Al10[3] = 8;

		/*
		Trecho que código que chama individualmente, 
		para cada aluno, a função calc_media    
    */
    printf(" \n Médias dos Alunos: \n");
		calc_media(Al1); 
		calc_media(Al2);
		calc_media(Al3);
		calc_media(Al4);
		calc_media(Al5);
		calc_media(Al6);
		calc_media(Al7);
		calc_media(Al8);
		calc_media(Al9);
		calc_media(Al10);
    
    printf("\n\n");
    return 0;
}

