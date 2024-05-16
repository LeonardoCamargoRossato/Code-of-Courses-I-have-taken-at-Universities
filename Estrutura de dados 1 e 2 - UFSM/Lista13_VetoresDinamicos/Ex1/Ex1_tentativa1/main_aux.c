#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

int contalinhas_arquivo(char* arquivo){
  FILE* f = fopen(arquivo,"rt");
  if(f == NULL){
    puts("\nErro na leitura do arquivo.\n"); exit(1);
  }

  char linha[81]; int cont_nomes = 0;
  while(fgets(linha,81,f)){
    cont_nomes++;
  }
  int n_aux = cont_nomes/2; //NÚMERO DE NOMES QUE HÁ NO ARQUIVO
  return n_aux;
}

Aluno* le_vetores (char* arquivo){
  FILE* f = fopen(arquivo,"rt");
  if(f == NULL){
    puts("\nErro na leitura do arquivo.\n"); exit(1);
  }
  Aluno* vd_aluno = aluno_cria();

  //float x;
  char linha[81]; int i = 0;
  float aux_p1,aux_p2,aux_p3;
  //float nota;
  char* aux_nome;
  while(fgets(linha,81,f) != NULL){
    if(linha[0] >= '0' && linha[0] <= '9'){
      while(fscanf(f,"%f %f %f",&aux_p1,&aux_p2,&aux_p3) != EOF)
        aluno_insere_float(vd_aluno,3*8);
      i++;
    }
    else{
      while(fscanf(f,"%81['\n']",aux_nome) != EOF)
        aluno_insere(vd_aluno, aux_nome);
    }
  }
  fclose(f);
  return vd_aluno;
}

int main(){
  char* arq = "arq_lista13_ex1.txt";

  puts("\nTeste Vetor Dinâmico\n");
//  printf(" n = %d \n",n);

  Aluno* vd_aluno = le_vetores(arq);

  printf("Tamanho 'n' do vet_dinamico = %d \n", aluno_tam(vd_aluno));

  printf("%s\n",aluno_acessa_nome(vd_aluno));
  printf("%.1f\n",aluno_acessa_p1(vd_aluno));
  printf("%.1f\n",aluno_acessa_p1(vd_aluno));

  aluno_libera(vd_aluno);
  return 0;
}
