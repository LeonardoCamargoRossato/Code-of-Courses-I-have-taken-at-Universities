#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;
struct aluno{
  char mat[8]; //matricula
  char nome[81];
  float cr; //coeficiente de rendimento
};

void carrega(int n,Aluno* v, char* arquivo){
  FILE* dados_alunos = fopen(arquivo,"rt");
  if(dados_alunos == NULL){printf("\nErro na leitura do arquivo.\n"); exit(1);}

  char linha[100];// char nome_aux[81];
  char mat_aux[8];
  char* nome_aux = (char*)malloc(81*sizeof(char));
  //char* mat_aux = (char*)malloc(8*sizeof(char));
  float cr_aux; int i = 0;
  while(fgets(linha,100,dados_alunos)){
    if((linha[0] >= '0') && (linha[0] <= '9')){
      sscanf(linha,"%s %f",mat_aux,&cr_aux);
      strcpy(v[i].nome,nome_aux); printf("v[%d].nome| %s\n",i,v[i].nome);
    //  memcpy(v[i].mat,mat_aux,81);
      v[i].cr = cr_aux;
      i++;
    }
    else{
      sscanf(linha," %81[^\n]",nome_aux);
    }
  }
  fclose(dados_alunos);
}

void printa(int n, Aluno* v){

  //PRINTA OS DADOS DOS ALUNOS EM ORDEM ALFABETICA
  puts("\nArquivo: Dados dos Alunos");
  for(int i = 0; i<n; i++){
    printf("\nNome: %s | cr: %.1f",v[i].nome,v[i].cr);
  }
  int med = n/2;
  printf("\n\nAluno mediano: \n --> Nome: %s | cr: %.1f",
    v[med].nome,v[med].cr);
  puts("\n\n");
}

void mediano(int n,Aluno* v){
Aluno* v_aux = (Aluno*)malloc(n*sizeof(Aluno));
int temp; int troca; int i; int j;
for(i = n-1; i>0; i--){
  troca = 0;
  for(j = 0; j<i; j++){
    if(v[j].cr > v[j+1].cr){
      temp = j;  // AONDE TROCA
      strcpy(v_aux[temp].nome,v[j].nome);
      //strcpy(v_aux[temp].mat,v[j].mat);
      v_aux[temp].cr = v[j].cr;

      strcpy(v[j].nome,v[j+1].nome);
      //strcpy(v[j].mat,v[j+1].mat);
      v[j].cr = v[j+1].cr;

      strcpy(v[j+1].nome,v_aux[temp].nome);
      //strcpy(v[j+1].mat,v_aux[temp].mat);
      v[j+1].cr = v_aux[temp].cr;

      troca = 1;
    }
  }
  //printf("j: %d | troca: %d | temp: %d | i: %d\n", j,troca,temp,i);
  if (troca == 0){
    break;
  }
}
}

int main(){
  char* arquivo = "dados_alunos2.txt";
  FILE* dados = fopen(arquivo,"rt");
  if(dados == NULL){ printf("\nErro na leitura do arquivo\n"); exit(1); }
  char linha[81]; int cont_linhas = 0;
  while(fgets(linha,81,dados)){
    cont_linhas++;
  }
  int n = cont_linhas/2;
  fclose(dados);

  Aluno* v = (Aluno*)malloc(n*sizeof(Aluno));
  carrega(n,v,arquivo);

  for(int i = 0; i<n-1; i++){
    printf("v[%d].nome| %s\n",i,v[i].nome);
    //printf("   v[%d].mat| %s     ",i,v[i].mat);
  }
  mediano(n,v);
  printa(n,v);

  free(v);
  return 0;
}
