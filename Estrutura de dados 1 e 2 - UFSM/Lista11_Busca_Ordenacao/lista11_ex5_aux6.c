// LISTA 11 - lEONARDO CAMARGO ROSSATO //
// MATRICULA: 201613053 //
// #####   E X E R C I C I O - 5 #####//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario Funcionario;
struct funcionario{
char nome[81];
float valor_hora;
int horas_mes;
};

Funcionario** carrega(int n,Funcionario** v, char* arquivo){
  FILE* dados_carrega = fopen(arquivo,"rt");
  if (dados_carrega == NULL){printf("\nErro na leitura do arquivo.\n"); exit(1);}

  Funcionario* v_aux;// (Funcionario**)malloc(n*sizeof(Funcionario*));
  for(int i = 0;i<n;i++){
    v[i] = NULL;
  }
  //float valor_hora_aux; int horas_mes_aux; char nome_aux[81];
  char linha[100]; int i = 0;
  while(fgets(linha,100,dados_carrega)){
    if((linha[0] >='0') && (linha[0] <='9')){
      sscanf(linha,"%f %d",v_aux[i].valor_hora,v_aux[i].horas_mes);
      if(v[i] == NULL){v[i] = (Funcionario*)malloc(n*sizeof(Funcionario));}
      strcpy(v[i]->nome,v_aux[i].nome);
      v[i]->valor_hora = v_aux[i].valor_hora;
      v[i]->horas_mes = v_aux[i].horas_mes;
      i++;
    }
    else{
      sscanf(linha,"%[^\n]",v_aux[i].nome);
    }
  }
  fclose(dados_carrega);
  return v_aux;
}

//FUNÇÃO CALLBACK QSORT
static int comp(const Funcionario* a,const Funcionario* b){
    float salario1 = (a->valor_hora) * ( (float) a->horas_mes);
    float salario2 = (b->valor_hora) * ( (float) b->horas_mes);

    if(salario1 > salario2)
        return 1;
    if(salario1 < salario2)
        return -1;
    else
        return 0;
}

int imprime_marajas(int n,Funcionario** v){

  qsort(v,n,sizeof(Funcionario),comp);

  puts("\nArquivo: Top 5 marajas "); float salario;
  for(int i = 0; i<n; i++){
    salario = (v[i]->horas_mes) * (v[i]->valor_hora);
    printf("\nNome: %s \t| salario: %.1f",v[i]->nome,salario);
  }
  puts("\n\n");


  //PRINTA OS MARAJA
  puts("\nArquivo: Top 5 marajas \n");
  for(int i = n - 1 ; i > n - 6 && i >= 0; i--)
      printf("%s | %.2f | %i\n", v[i]->nome, ((int) (v[i]->horas_mes)) * ((float) v[i]->valor_hora), i);
  puts("\n");
  }


int main(){
  char* arquivo = "dados_funcionarios.txt";

  FILE* dados = fopen(arquivo, "rt");
  if(dados == NULL){printf("\nErro na leitura do arquivo.\n"); exit(1);}
  int cont_linhas = 0; char linhas[100];
  while(fgets(linhas,100,dados)){
    cont_linhas++;
  }
  int n = cont_linhas/2;
  fclose(dados);

  Funcionario** v = (Funcionario**)malloc(n*sizeof(Funcionario*));
  for(int i = 0;i<n;i++){
    v[i] = NULL;
  }

  carrega(n,v,arquivo);
  imprime_marajas(n,v);


  for(int i = 0; i<n;i++){free(v[i]);} free(v);
  return 0;
}
