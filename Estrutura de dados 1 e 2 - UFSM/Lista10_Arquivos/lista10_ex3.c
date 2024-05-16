// LISTA 10 - lEONARDO CAMARGO ROSSATO //
// MATRICULA: 201613053 //
// #####   E X E R C I C I O - 3 #####//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario Funcionario;
struct funcionario{
char nome[81];
float valor_hora;
int horas_mes;
};

void carrega(int n,Funcionario** vet_dados, char* arquivo){
  FILE* dados_carrega;
  dados_carrega = fopen(arquivo,"rt");
  if (dados_carrega == NULL){printf("\nErro na leitura do arquivo.\n"); exit(1);}

  float valor_hora2; int horas_mes2; char nome2[81];
  char linha[81]; int i = 0;
  while(fgets(linha,81,dados_carrega)){
    if((linha[0] >='0') && (linha[0] <='9')){
      sscanf(linha,"%f %d",&valor_hora2,&horas_mes2);
      if(vet_dados[i] == NULL){vet_dados[i] = (Funcionario*)malloc(sizeof(Funcionario));}
      strcpy(vet_dados[i]->nome,nome2);
      vet_dados[i]->valor_hora = valor_hora2;
      vet_dados[i]->horas_mes = horas_mes2;
      i++;
    }
    else{
      sscanf(linha,"%[^\n]",nome2);
    }
  }
  fclose(dados_carrega);
}

int main(){
  char* arquivo = "dados_funcionarios.txt";

  FILE* dados = fopen(arquivo,"rt");
  if(dados == NULL){printf("\nErro na leitura do arquivo.\n"); exit(1);}

  int cont_linhas = 0; char linha[100];
  while(fgets(linha,100,dados)){
    cont_linhas++;
  }
  int n = cont_linhas/2; //tamanho do vetor de ponteiros (q vai carregar os dados dos func)
  fclose(dados);

  Funcionario** vet_dados = (Funcionario**)malloc(n*sizeof(Funcionario*));
  for(int i = 0; i<n; i++){ vet_dados[i] = NULL ;}

  carrega(n,vet_dados,arquivo);

  puts("\nArquivo: Dados dos funcionarios");
  for(int i = 0; i<n; i++){

    printf("\nNome: %s",vet_dados[i]->nome);
  printf("\t| Valor Hora: %.1f\t| Horas no Mes: %d",
    vet_dados[i]->valor_hora,vet_dados[i]->horas_mes);
  }
  puts("\n\n");

  for(int i = 0; i<n; i++){free(vet_dados[i]);} free(vet_dados);
  return 0;
}
