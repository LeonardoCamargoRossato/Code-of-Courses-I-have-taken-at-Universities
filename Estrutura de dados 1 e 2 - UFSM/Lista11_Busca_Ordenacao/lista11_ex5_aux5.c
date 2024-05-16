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

void carrega(int n,Funcionario** vet_dados, char* arquivo){
  FILE* dados_carrega = fopen(arquivo,"rt");
  if (dados_carrega == NULL){printf("\nErro na leitura do arquivo.\n"); exit(1);}

  float valor_hora_aux; int horas_mes_aux; char nome_aux[81];
  char linha[100]; int i = 0;
  while(fgets(linha,100,dados_carrega)){
    if((linha[0] >='0') && (linha[0] <='9')){
      sscanf(linha,"%f %d",&valor_hora_aux,&horas_mes_aux);
      if(vet_dados[i] == NULL){vet_dados[i] = (Funcionario*)malloc(sizeof(Funcionario));}
      strcpy(vet_dados[i]->nome,nome_aux);
      vet_dados[i]->valor_hora = valor_hora_aux;
      vet_dados[i]->horas_mes = horas_mes_aux;
      i++;
    }
    else{
      sscanf(linha,"%81[^\n]",nome_aux);
    }
  }
  fclose(dados_carrega);
}

//FUNÇÃO CALLBACK imprime_marajas
int comp(Funcionario* a, Funcionario* b){
    float salario1 = (a->valor_hora) * ( (float) a->horas_mes);
    float salario2 = (b->valor_hora) * ( (float) b->horas_mes);

    if(salario1 > salario2)
        return 1;
    if(salario1 < salario2)
        return -1;
    else
        return 0;
}

void imprime_marajas(int n, Funcionario** v){
  Funcionario** v_aux = (Funcionario**)malloc(n*sizeof(Funcionario*));
  int temp; int troca; int i; int j; //float** salario1, salario2;
  //int kk = 0; int kk2 = 0;

  for(i = n-1; i>0; i--){
    troca = 0;
    for(j = 0; j<i; j++){
      if(comp(v,j) > 0){ //MAIOR Q ZERO, TROCA
        temp = j;  // AONDE TROCA
        //kk2++; printf("kk2: %d | temp: %d \n",kk2, temp);
        strcpy(v_aux[temp]->nome,v[j]->nome);
        v_aux[temp]->valor_hora = v[j]->valor_hora;
        v_aux[temp]->horas_mes = v[j]->horas_mes;
      //  printf("v_aux[temp]->horas_mes: %d\n",v_aux[temp]->horas_mes);

        strcpy(v[j]->nome,v[j+1]->nome);
        v[j]->valor_hora = v[j+1]->valor_hora;
        v[j]->horas_mes = v[j+1]->horas_mes;

        strcpy(v[j+1]->nome,v_aux[temp]->nome);
        v[j+1]->valor_hora = v_aux[temp]->valor_hora;
        v[j+1]->horas_mes = v_aux[temp]->horas_mes;

        //kk++;
        troca = 1;
      }
    }
    if (troca == 0){
      break;
    }
  }
  //printf("Nome: %s | salario1: %.1f\n",v[j]->nome,salario1);
}

int main(){
  char* arquivo = "dados_funcionarios_ordenado.txt";

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

  //PRINTA OS MARAJA
  puts("\nArquivo: Top 5 marajas "); float salario;
  for(int i = 0; i<5; i++){
    salario = v[i]->horas_mes*v[i]->valor_hora;
    printf("\nNome: %s \t| salario: %.1f",v[i]->nome,salario);
  }
  puts("\n\n");

  for(int i = 0; i<n;i++){free(v[i]);} free(v);
  return 0;
}
