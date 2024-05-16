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
      sscanf(linha,"%[^\n]",nome_aux);
    }
  }
  fclose(dados_carrega);
}

//FUNÇÃO CALLBACK QSORT
static int compara_salario(const void* p1,const void* p2){

//  float salario1 = (v[j]->horas_mes)*(v[j]->valor_hora);
//  float salario2 = (v[j+1]->horas_mes)*(v[j+1]->valor_hora);

  //Converte ponteiros genéricos em inteiros
  //Funcionario** a = (Funcionario**)p1;
//  Funcionario** b = (Funcionario**)p2;

 // (*(Funcionario**)p1)->horas_mes) == INT (4BYTES)
 // (*(Funcionario**)p1)->valor_hora) == FLOAT
  float horas_mesp1 = (*(Funcionario**)p1->horas_mes);
  float horas_mesp2 = (*(Funcionario**)p2->horas_mes);
  float valor_horap1 = (*(Funcionario**)p1->valor_hora);
  float valor_horap2 = (*(Funcionario**)p2->valor_hora);

  float salario1 = horas_mesp1*valor_horap1;
  float salario2 = horas_mesp2*valor_horap2;
  //float salario1 = ((*(Funcionario**)p1)->horas_mes)*((*(Funcionario**)p1)->valor_hora);
  //float salario2 = ((*(Funcionario**)p2)->horas_mes)*((*(Funcionario**)p2)->valor_hora);

  return(salario1-salario2);
}

int imprime_marajas(int n,Funcionario** v){
  puts("aiaieie");
  qsort(v,n,sizeof(Funcionario),compara_salario);

  //PRINTA OS MARAJA
  puts("\nArquivo: Top 5 marajas "); float salario;
  for(int i = 0; i<5; i++){
    salario = v[i]->horas_mes*v[i]->valor_hora;
    printf("\nNome: %s \t| salario: %.1f",v[i]->nome,salario);
  }
  puts("\n\n");

  return 0;
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
