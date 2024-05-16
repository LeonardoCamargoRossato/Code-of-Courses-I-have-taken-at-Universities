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

void carrega(int n,Funcionario** v, char* arquivo,float* salario){
  FILE* dados_carrega = fopen(arquivo,"rt");
  if (dados_carrega == NULL){printf("\nErro na leitura do arquivo.\n"); exit(1);}

  float valor_hora_aux; int horas_mes_aux; char nome_aux[81];
  char linha[100]; int i = 0;
  while(fgets(linha,100,dados_carrega)){
    if((linha[0] >='0') && (linha[0] <='9')){
      sscanf(linha,"%f %d",&valor_hora_aux,&horas_mes_aux);
      if(v[i] == NULL){v[i] = (Funcionario*)malloc(sizeof(Funcionario));}
      strcpy(v[i]->nome,nome_aux);
      v[i]->valor_hora = valor_hora_aux;
      v[i]->horas_mes = horas_mes_aux;
      salario[i] = valor_hora_aux*horas_mes_aux;
      i++;
    }
    else{
      sscanf(linha,"%[^\n]",nome_aux);
    }
  }
  fclose(dados_carrega);
}

int compara_salario(float salario1,float salario2){
  if(salario1 > salario2){
    printf("salario1 %.1f | salario2 %.1f\n",salario1,salario2);
    return 1;}
  else { return 0;}
}

void imprime_marajas(int n, Funcionario** v,float* salario){
  Funcionario** v_aux = (Funcionario**)malloc(n*sizeof(Funcionario*));
  //Funcionario** v_aux2 = (Funcionario**)malloc(n*sizeof(Funcionario*));
  int temp; int troca; int i; int j;
  //int kk = 0; int kk2 = 0;
//  float salario1; float salario2; int j1 = 0;
  for(i = n-1; i>0; i--){
    troca = 0;
    for(j = 0; j<i; j++){

      if(compara_salario(salario[j+1],salario[j]) > 0){
        temp = j;  // AONDE TROCA
      //  kk2++; printf("kk2: %d\n",kk2);
        //salario[temp] = salario[j];
        strcpy(v_aux[temp]->nome,v[j]->nome);
        v_aux[temp]->valor_hora = v[j]->valor_hora;
        v_aux[temp]->horas_mes = v[j]->horas_mes;

        //salario[j] = salario[j+1];
        strcpy(v[j]->nome,v[j+1]->nome);
        v[j]->valor_hora = v[j+1]->valor_hora;
        v[j]->horas_mes = v[j+1]->horas_mes;

        //salario[j+1] = salario[temp];
        strcpy(v[j+1]->nome,v_aux[temp]->nome);
        v[j+1]->valor_hora = v_aux[temp]->valor_hora;
        v[j+1]->horas_mes = v_aux[temp]->horas_mes;

        troca = 1;
      }
      //printf("%d| salario[j]: %.2f R$| salario[j+1]: %.2f R$\n",j,salario[j], salario[j+1]);
    }
    if (troca == 0){
      break;
    }
  }
//  printf("Nome: %s | salario1: %.1f\n",v[j]->nome,salario1);
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
  float* salario = (float*)malloc(n*sizeof(float));

  carrega(n,v,arquivo,salario);
  //for(int i =0; i<n; i++)
    //printf("salario[%d]: %.1f\n",i,salario[i]);

  imprime_marajas(n,v,salario);

  float* salario_main;
  //PRINTA OS MARAJA
  puts("\nArquivo: Top 5 marajas ");
  for(int i = 0; i<n; i++){
    salario_main[i] = (v[i]->horas_mes)*(v[i]->valor_hora);
    printf("\n %s \t| salario_main[%d]: %.1f",v[i]->nome,i,salario_main[i]);
  }
  puts("\n\n");

  for(int i = 0; i<n;i++){free(v[i]);} free(v);
  return 0;
}
