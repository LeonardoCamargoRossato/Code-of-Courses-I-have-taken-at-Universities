// LISTA 10 - lEONARDO CAMARGO ROSSATO //
// MATRICULA: 201613053 //
// #####   E X E R C I C I O - 2 #####//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void aprovados(char* notas_da_turma){
  FILE* in = fopen(notas_da_turma, "rt");
  if(in == NULL){
    printf("Erro na abertura do arquivo!\n");
    exit(1);
  }
  FILE* out = fopen("aprovados.txt","wt");
  if(out == NULL){
    printf("Erro na abertura do arquivo!\n");
    exit(1);
  }

  char nome[40]; char sobrenome[40]; float p1; float p2;
  char linha[100]; int i = 0; float media;

  fputs("\nLista dos Aprovados: \n\n",out);
  while(fgets(linha,100,in)){
    if ((linha[0] >= '0') && (linha[0] <= '9')){
      sscanf(linha,"%f %f",&p1,&p2);
      media = (p1+p2)/2.0;
      if(media >= 5.0){
        fprintf(out, "\n%s %s: \t", nome,sobrenome);
        fprintf(out, "%.1f ",media);}
    }
    else{
      sscanf(linha,"%s %s",nome,sobrenome);
    }
  }
  fputs("\n\n",out);
  fclose(in); fclose(out);
}


int main(){

  char* notas_da_turma = "turmas.txt";
  aprovados(notas_da_turma);

  return 0;
}
