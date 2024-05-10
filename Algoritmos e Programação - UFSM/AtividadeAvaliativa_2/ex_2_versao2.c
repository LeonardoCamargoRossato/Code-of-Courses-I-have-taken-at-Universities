//------------------------------------------------//
// Disciplina: Algoritmos e lógica de programação //
//------------------------------------------------//
// ATIVIDADE AVALIATIVA 2 //
// ALUNO: LEONARDO CAMARGO ROSSATO //
// MATRICULA: 2020520162 //
//------------------------------------------------//
// #####  E X E R C I C I O - 02 ( VERSÃO 2)  ####//
//------------------------------------------------//

#include<stdio.h>
#include <stdlib.h>

/*
	Nessa versão, a função calc_media:
	- lê valores de uma	matriz de dados; 
	- calcula a media; 
	- printa as notas dos alunos;
	- não retorna valor (é uma função "void").
*/
void calc_media(int lin, int col, float al[lin][col]){
	float media;
	int i;
	printf("\n");
  for ( i=0; i<10; i++ ){
  	media = (al[i][0] + 2*al[i][1] + 3*al[i][2] + 2*al[i][3])/8;
		printf( "\n Média Aluno[%d] = %.2f ",i, media);
	}
}

/* A função principal está aqui apenas para:
   - Declarar Variáveis
   - Chamar Função que calcula as medias 
*/ 
int main(void)
{
 //Declaração das Variáveis 
  int i,j; 
  int lin = 10; 
  int col = 4;
  float Aluno[10][4];

 //Notas dos Alunos da Escola   
  for ( i=0; i<10; i++ ){
  	for ( j=0; j<4; j++ ){
  	//Para facilitar a atribuição de valores aos alunos --> foi utilizado a função rand()
  	Aluno[i][j] = rand() % 10; 
//    printf ("\nAluno[%d][%d] = %f", i, j,Aluno[i][j]);
  	}
	}
	
/* Chama a Função Calc_media informando:
linhas, colunas e a matriz contendo as notas dos alunos*/
	calc_media(lin,col,Aluno); 
	
  printf("\n\n");  		
  return 0;
}

