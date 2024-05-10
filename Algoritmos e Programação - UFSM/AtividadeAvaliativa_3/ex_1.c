//------------------------------------------------//
// Disciplina: Algoritmos e lógica de programação //
//------------------------------------------------//
// ATIVIDADE AVALIATIVA 3 //
// ALUNO: LEONARDO CAMARGO ROSSATO //
// MATRICULA: 2020520162 //
//------------------------------------------------//
// #####   E X E R C I C I O - 01 #####//
//------------------------------------------------//

#include<stdio.h>
#include <stdlib.h>

int menor_par(int* v){

	//Declaração de variáveis
	int menor_interv,i,a,b;

	//Filtra o menor intervalo dentro do vetor
	menor_interv = abs(v[1]-v[0]);
	for( i=1; i<9; i++){
		if(abs(v[i+1]-v[i]) < menor_interv){
			menor_interv = abs(v[i+1]-v[i]);
			a = i;
			b = i+1;
		}	
	}
	
	//Printa os valores dos pares que tem o menor intervalo	
	printf("\n # Dentro da Função #  \n");
	printf("\n %d ; %d  \n",v[a],v[b]);
	
	//Retorna o valor de menor intervalo para main
	return menor_interv;
}


int main(void){

	//Declaração de variáveis
	int vet[10],i, menor_interv;

	//Leitura de input dentro do código
	vet[0] = 0; vet[1] = 5; vet[2] = 12; vet[3] = 8; vet[4] = 19;
	vet[5] = -7; vet[6] = -8; vet[7] = 15; vet[8] = 6; vet[9] = 12;

//Leitura de input pelo terminal
//	for( i=0; i<10; i++){
//		scanf("%d", &vet[i]);
//	}
	
	//Chama a função menor_par e print o valor de menor intervalo
	menor_interv = menor_par(vet);  		
	printf("\n # Dentro da Main #  \n");
	printf("\n Menor Intervalo =  %d \n",menor_interv);
	return 0;
}


