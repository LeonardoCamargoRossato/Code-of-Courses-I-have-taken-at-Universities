// LISTA 10 - lEONARDO CAMARGO ROSSATO //
// MATRICULA: 201613053 //
// #####   E X E R C I C I O - 4 #####//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;
struct aluno{
char matricula[8];
char nome[81];
float cr; //coeficiente de rendimento
};

Aluno* carrega (char* arquivo, int *n){

  FILE* dados_carrega = fopen(arquivo,"rt");
  if (dados_carrega == NULL){printf("\nErro na leitura do arquivo.\n"); exit(1);}

  Aluno* vet_alunos;
  vet_alunos = (Aluno*)malloc(n[0]*sizeof(Aluno));

  char aux_matricula[8]; char aux_nome[81];char aux_nome2[81]; float aux_cr;
  char linha[100]; int i = 0; int i2 = 0; char espaco[2] = " ";
  while(fgets(linha,100,dados_carrega)){
    if(i2 != 0){
      sscanf(linha,"%s %s %s %f",aux_matricula,aux_nome,aux_nome2,&aux_cr);
      strncat(aux_nome,espaco,20); strncat(aux_nome,aux_nome2,81);
      strcpy(vet_alunos[i].matricula,aux_matricula);
      strcpy(vet_alunos[i].nome,aux_nome);
      vet_alunos[i].cr = aux_cr;
      i++;
    }
    i2++;
  }
  fclose(dados_carrega);
  return vet_alunos;
}

int main(){
  char* arquivo = "dados_alunos.txt";

  FILE* conta_tam_arquivo = fopen(arquivo,"rt");
  if(conta_tam_arquivo == NULL){printf("\nErro na leitura do arquivo.\n"); exit(1);}

  int *n = (int*)malloc(sizeof(int));
  fscanf(conta_tam_arquivo,"%d",n);
  fclose(conta_tam_arquivo);

  Aluno* vet_alunos_main = (Aluno*)malloc(n[0]*sizeof(Aluno));
  vet_alunos_main = carrega(arquivo,n);

  puts("\n\nArquivo: Dados dos Alunos\n");
  printf("Número de alunos: %d\n",n[0]);
  for(int i = 0; i<n[0]; i++){
  printf("Matricula: %s | Aluno: %s | Cr: %.1f \n",
    vet_alunos_main[i].matricula,vet_alunos_main[i].nome,vet_alunos_main[i].cr);
  }

  free(vet_alunos_main); free(n);
  return 0;
}
