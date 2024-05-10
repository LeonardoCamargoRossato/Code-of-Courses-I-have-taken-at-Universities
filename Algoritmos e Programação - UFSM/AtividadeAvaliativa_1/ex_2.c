//------------------------------------------------//
// Disciplina: Algoritmos e lógica de programação //
//------------------------------------------------//
// ATIVIDADE AVALIATIVA 1 //
// ALUNO: LEONARDO CAMARGO ROSSATO //
// MATRICULA: 2020520162 //
//------------------------------------------------//
// #####   E X E R C I C I O - 02 #####//
//------------------------------------------------//

#include <stdio.h>

int main(void)
{
    //Declaração das Variáveis 
    char tipo_de_pag;  
    float preco; 
    
    //Chamada e leitura dos dados de entrada
    printf("\n\n # Digite o Preço da compra e o tipo de pagamento escolhido: \n  --> ");
    scanf("%f %c",&preco,&tipo_de_pag);
    
    printf("\n"); // *Esse print só serve pra pular a linha no terminal
    
    //Bloco de Comando: Switch Case, usando char como tipo de variável base
     switch ( tipo_de_pag )
  {
    case 'A' :
    printf ("\n Modalidade de Pagamento: à vista em dinheiro ou PIX \n");
    printf (" --> Desconto de 10%% | Preço Final = %.2f R$ \n", preco - preco*0.1 );
    break;
    
    case 'B' :
    printf ("\n Modalidade de Pagamento: à vista no cartão de crédito \n");
	 printf (" --> Desconto de 5%% | Preço Final = %.2f R$ \n", preco - preco*0.05 );
    break;
    
    case 'C' :
    printf ("\n Modalidade de Pagamento: em duas vezes, preço normal da etiqueta \n");
	 printf (" --> Sem Desconto | Preço Final = %.2f R$ \n", preco);
    break;
    
    default :
    printf (" --> Tipo de pagamento invalido!\n ");
  }
    printf("\n");
    return 0;
}

