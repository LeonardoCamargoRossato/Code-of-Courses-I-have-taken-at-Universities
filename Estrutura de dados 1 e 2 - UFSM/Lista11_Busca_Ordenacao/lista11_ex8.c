// LISTA 11 - lEONARDO CAMARGO ROSSATO //
// MATRICULA: 201613053 //
// #####   E X E R C I C I O - 8 #####//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario Funcionario;
struct funcionario{
  char nome[81];
  int dia, mes;
};

void carrega(int n,Funcionario* v, char* arquivo){
  FILE* dados_carrega;
  dados_carrega = fopen(arquivo,"rt");
  if (dados_carrega == NULL){printf("\nErro na leitura do arquivo.\n"); exit(1);}

  int dia_aux, mes_aux; char nome_aux[81];
  char linha[81]; int i = 0;
  while(fgets(linha,81,dados_carrega)){
    if((linha[0] >='0') && (linha[0] <='9')){
      sscanf(linha,"%d %d",&dia_aux,&mes_aux);
      strcpy(v[i].nome,nome_aux);
      v[i].dia = dia_aux;
      v[i].mes = mes_aux;
      i++;
    }
    else{
      sscanf(linha,"%[^\n]",nome_aux);
    }
  }
  fclose(dados_carrega);
}

void printa_dados(int n, Funcionario* v){
  puts("\nArquivo: Dados das pessoas");
  for(int i = 0; i<n-1; i++){
    printf("\nNome: %s  |  Data nascimento: %d/%d",
      v[i].nome,v[i].dia,v[i].mes);
  }
  puts("\n\n");
}

//FUNÇÃO CALLBACK para COMPARA_DATA
static int compara_nomes(const void* p1,const void* p2){
  //Converte ponteiros genéricos em inteiros
  Funcionario **v1 = (Funcionario**)p1;
  Funcionario **v2 = (Funcionario**)p2;

  char c1, c2;
  while((sscanf((*v1) ->nome," %c",&c1)) && (sscanf((*v2)->nome," %c",&c2))){
    if(c1 > c2)
      return 1;
    else if (c1 < c2)
      return -1;
    else
      return 0;
  }
}


//FUNÇÃO CALLBACK para QSORT
static int compara_data(const void* p1,const void* p2){

  //Converte ponteiros genéricos em inteiros
  Funcionario** v1 = (Funcionario**)p1;   // provavelmente o valor do mês ?
  Funcionario** v2 = (Funcionario**)p2;   // provavelmente o valor do dia ?
  printf("aaaaaaeeeoeoeoeooer\n");
  if((*v1)->mes < (*v2)->mes){ return -1;}
  if((*v1)->mes > (*v2)->mes){ return 1;}
  else{
    if((*v1)->dia < (*v2)->dia){ return -1;}
    if((*v1)->dia > (*v2)->dia){ return 1;}
    else {return compara_nomes((*v1)->nome,(*v2)->nome);}
  }
}


int main(){
 char* arquivo = "dados_funcionarios_lista8.txt";
 FILE* dados = fopen(arquivo,"rt");
 if(dados == NULL){printf("\nErro na leitura do arquivo.\n"); exit(1);}

 int cont_linhas = 0; char linha[100];
 while(fgets(linha,100,dados)){
   cont_linhas++;
 }
 int n = cont_linhas/2; //tamanho do vetor de ponteiros (q vai carregar os dados das pessoas)
 fclose(dados);

 Funcionario* v = (Funcionario*)malloc(n*sizeof(Funcionario));
 carrega(n,v,arquivo);
 printa_dados(n,v);

 qsort(v,n,sizeof(Funcionario),compara_data);

 printa_dados(n,v);


 return 0;
}
