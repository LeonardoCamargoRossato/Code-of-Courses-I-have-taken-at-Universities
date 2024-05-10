//------------------------------------------------//
// Disciplina: Algoritmos e lógica de programação //
//------------------------------------------------//
// ATIVIDADE AVALIATIVA 3 //
// ALUNO: LEONARDO CAMARGO ROSSATO //
// MATRICULA: 2020520162 //
//------------------------------------------------//
// #####   E X E R C I C I O - 02 #####//
//------------------------------------------------//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int conta_palavras(char* str){
	//Declaração de variáveis
	int i,tam,cont;
	
	//Retorna tamanho da string
	tam = strlen(str);

  //Conta nº de palavras
	cont = 1;
	for ( i=0; i<tam; i++ ){
		if(str[i] == ' ') cont++;
	}
	
	//Retorna valor da função
	return(cont);
}

int main(void){

	//Declaração de variáveis
	int n_palavras,i,tam,cont;
	char str[100];
	 

	//Leitura de input dentro do código
	puts(" Digite um texto: \n  ");
  fgets(str,100,stdin);
	
	//Chama a função externa
	n_palavras = conta_palavras(str);
	
	//Printa nº palavras da string
	printf("\n nº de Palavras no texto é: %d \n\n",n_palavras);
	
	return 0;
}

