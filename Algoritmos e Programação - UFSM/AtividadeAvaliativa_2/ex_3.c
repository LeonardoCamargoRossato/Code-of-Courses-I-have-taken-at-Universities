//------------------------------------------------//
// Disciplina: Algoritmos e lógica de programação //
//------------------------------------------------//
// ATIVIDADE AVALIATIVA 2 //
// ALUNO: LEONARDO CAMARGO ROSSATO //
// MATRICULA: 2020520162 //
//------------------------------------------------//
// #####   E X E R C I C I O - 03 #####//
//------------------------------------------------//

#include<stdio.h>
#include <stdlib.h>

void multiplo_de_quatro(){
	int N,i;
	printf("\n\n");
	
	 //Chamada e leitura dos dados de entrada
    printf("\n\n # Digite um valor inteiro 'N': \n  --> ");
    scanf("%d",&N);
    
  //Loop de seleção e print dos Dados 
  for ( i=1; i<=N; i++ ){
		if( i%4 == 0) printf( "PI, ");
		else printf( "%d, ",i);
	}
	
}

//A função principal está aqui apenas para 
//chamar a função TicTac.
int main(void)
{
	multiplo_de_quatro();  		
	return 0;
}


