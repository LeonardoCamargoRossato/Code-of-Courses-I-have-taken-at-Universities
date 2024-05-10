//------------------------------------------------//
// Disciplina: Algoritmos e lógica de programação //
//------------------------------------------------//
// ATIVIDADE AVALIATIVA 3 //
// ALUNO: LEONARDO CAMARGO ROSSATO //
// MATRICULA: 2020520162 //
//------------------------------------------------//
// #####  E X E R C I C I O - 03   ####//
//------------------------------------------------//

#include<stdio.h>
#include <stdlib.h>

/*
	Nessa versão, a função calc_media:
	- lê valores de uma	matriz de dados; 
	- verifica se o quadrado é mágico; 
	- printa a info se é ou não quadrado mágico;
	- não retorna valor (é uma função "void").
*/
void quad_magico(int lin, int col, int mat[lin][col]){
	int i,j,cont_lin,cont_col;
	printf("\n");
	
	cont_lin = 0;
	cont_col = 0;
  for ( i=0; i<lin; i++ ){
  	for ( j=0; j<col; j++ ){
  		cont_lin = cont_lin + mat[i][j]; 
  		cont_col = cont_col + mat[j][i]; 
		}
		if(cont_lin != cont_col){
			printf("\n Não é Quadrado Mágico. \n");
			break;
		} 
		cont_lin = 0;
		cont_col = 0;
		if(i == lin-1){
			printf("\n É Quadrado Mágico. \n");
		}		
	}
}

/* A função principal está aqui apenas para:
   - Declarar Variáveis
   - Chamar Função que verifica se o quadrado é mágico 
*/ 
int main(void)
{
  //Declaração das Variáveis 
  int i,j; 
  int lin = 3; 
  int col = 3;
  int matriz[lin][col]; 

  //Declaração de Matriz Quadrada (usando rand) 
  for ( i=0; i<lin; i++ ){
  	for ( j=0; j<col; j++ ){
  	//Para facilitar a atribuição de valores aos alunos --> foi  utilizado a função rand()
  	matriz[i][j] = (int)rand() %101; 
  	}
	}
	
  // Chama a Função externa:
  puts("# Matriz_1");
	quad_magico(lin,col,matriz); 
  printf("\n\n");  		
  
//------------------------------------------------------  
  
  //Declaração Manual de Matriz Quadrada Mágica (3x3)
  int matriz2[3][3];
  
  matriz2[0][0] = 8; matriz2[0][1] = 0; matriz2[0][2] = 7;
  matriz2[1][0] = 4; matriz2[1][1] = 5; matriz2[1][2] = 6;  
  matriz2[2][0] = 3; matriz2[2][1] = 10; matriz2[2][2] = 2; 
  
  // Chama a Função externa:
  
  puts("# Matriz_2");
	quad_magico(lin,col,matriz2); 
	
  printf("\n\n");  
  
  return 0;
}

