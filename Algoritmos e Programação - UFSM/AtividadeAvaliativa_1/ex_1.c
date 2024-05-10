//------------------------------------------------//
// Disciplina: Algoritmos e lógica de programação //
//------------------------------------------------//
// ATIVIDADE AVALIATIVA 1 //
// ALUNO: LEONARDO CAMARGO ROSSATO //
// MATRICULA: 2020520162 //
//------------------------------------------------//
// #####   E X E R C I C I O - 01 #####//
//------------------------------------------------//

#include <stdio.h>

float calc_peso(float g, float peso){
	float p;
	p = (peso*g*9.81)/10;
	return p;
}

int main(void)
{
	 //Declaração das Variáveis 
    float peso, g;
    int planeta;
    
    //Chamada e leitura dos dados de entrada
    printf("\n\n # Digite valor do Peso de uma Pessoa na Terra e o número do Planeta Escolhido: \n  --> ");
    scanf("%f %d",&peso,&planeta);
    
    printf("\n"); // *Esse print só serve pra pular a linha no terminal
    
    //Bloco de Comando: Switch Case, usando int como tipo de variável base
     switch ( planeta )
  {
    case 1 :
    g = 0.37;
    printf (" 1 - Mercúrio | Novo peso da pessoa é p = %f \n", calc_peso(g,peso));
    break;
    
    case 2 :
    g = 0.88;
    printf (" 2 - Vênus | Novo peso da pessoa é p = %f \n", calc_peso(g,peso));
    break;
    
    case 3 :
    g = 0.38;
    printf (" 3 - Marte | Novo peso da pessoa é p = %f \n", calc_peso(g,peso));
    break;
    
    case 4 :
    g = 2.64;
    printf (" 4 - Júpiter | Novo peso da pessoa é p = %f \n", calc_peso(g,peso));
    break;
    
    case 5 :
    g = 1.15;
    printf (" 5 - Saturno | Novo peso da pessoa é p = %f \n", calc_peso(g,peso));
    break;
    
    case 6 :
    g = 1.17;
    printf (" 6 - Urano | Novo peso da pessoa é p = %f \n", calc_peso(g,peso));
    break;
    
    case 7 :
    g = 1.18;
    printf (" 7 - Netuno | Novo peso da pessoa é p = %f \n", calc_peso(g,peso));
    break;
    
    default :
    printf (" --> Número do Planeta invalido!\n");
  }
    
    return 0;
}

