// LISTA 10 - lEONARDO CAMARGO ROSSATO //
// MATRICULA: 201613053 //
// #####   E X E R C I C I O - 1 #####//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float media(char* mat, char* nome_arquivo){

  //Abre arquivo
  FILE* nome = fopen(nome_arquivo, "rt");
  if(nome == NULL){
    printf("Erro na abertura do arquivo!\n");
    exit(1);
  }

  //Ler e Armazenar dados da Matrícula[8]
  int n = 0; //conta Numero de linhas
  char linha[22];
  int cont = 0;
  while(fgets(linha,22,nome) != NULL){
    n++;
      if( strstr(linha,mat) != NULL){
        cont ++; break;
      }
  }

  if(cont == 0){
    printf("\nMatrícula não encontrada. \n\n"); return -1;
  }

  else{
    float p1 = (linha[10] - 48) + (linha[12] - 48)/10.0;
    float p2 = (linha[14] - 48) + (linha[16] - 48)/10.0;
    float p3 = (linha[18] - 48) + (linha[20] - 48)/10.0;
    return (p1+p2+p3)/3.0;
  }
  fclose(nome);
}

float main(FILE* arquivo){

  char* nome_arquivo = "arquivo.txt";

  printf("\nDigite o número de matrícula do aluno: \n --> ");
  char* mat = (char*)malloc(9*sizeof(char));
  scanf(" %9[^\n]", mat);

  //Tranca Matricula com menos de 9 digitos;
  int cont = 0;
  for(int i = 0; mat[i] != '\0'; i++){
    cont++;
  }
  if(cont != 9){printf("\nMatrícula não encontrada. \n\n");return -1;}

  float media_main = media(mat,nome_arquivo);
  if(media_main == -1){return -1;}
  printf("\n Matricula: %s  |  Média: %.1f \n\n",mat,media_main);

  free(mat);
  return media_main;
}
