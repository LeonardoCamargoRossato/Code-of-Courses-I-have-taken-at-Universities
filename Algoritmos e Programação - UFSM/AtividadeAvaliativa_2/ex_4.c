//------------------------------------------------//
// Disciplina: Algoritmos e lógica de programação //
//------------------------------------------------//
// ATIVIDADE AVALIATIVA 2 //
// ALUNO: LEONARDO CAMARGO ROSSATO //
// MATRICULA: 2020520162 //
//------------------------------------------------//
// #####   E X E R C I C I O - 04 #####//
//------------------------------------------------//

#include<stdio.h>
#include <stdlib.h>

void TicTac(){
	int N,i;
	printf("\n\n");
	
	//Chamada e leitura dos dados de entrada
	printf("\n\n # Digite um valor inteiro 'N': \n  --> ");
	scanf("%d",&N);
  
  //Loop de seleção e print dos Dados 
  for ( i=1; i<=N; i++ ){
		if( i%2 == 0 && i%3 == 0 && i%5 == 0) printf( "TicTac, ");
		else if( i%5 == 0) printf( "Tac, ");
		else if( i%2 == 0 && i%3 == 0) printf( "Tic, ");
		else printf( "%d, ",i);
	}
	printf("\n\n");
}

//A função principal está aqui apenas para 
//chamar a função TicTac.
int main(void)
{
	TicTac();  		
	return 0;
}


