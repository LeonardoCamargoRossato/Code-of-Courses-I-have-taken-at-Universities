#include "matriz.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void){

  Matriz* matriz = mat_cria(3,4);
  int linhas = mat_linhas(matriz);
  int colunas = mat_colunas(matriz);
  printf("\n Linhas: %d | Colunas: %d",linhas,colunas);

  mat_atribui(matriz,0,0,9);
  mat_atribui(matriz,0,2,1);
  mat_atribui(matriz,1,1,5);
  mat_atribui(matriz,1,3,6);
  mat_atribui(matriz,2,1,2);
  mat_atribui(matriz,2,0,5);
  mat_atribui(matriz,2,3,2.5);

  float elem;
  printf("\n   ");
  for(int i = 0; i<3; i++){
    printf("\n   ");
    for(int j = 0; j<4; j++){
      elem = mat_acessa(matriz,i,j);
      printf("%.1f  ", elem);
    }
  }
  puts("\n   ");

  //CRIAR MATRIZ TRANSPOSTA
  Matriz* mat_transposta = mat_cria(4,3);
  int lin_transposta = mat_linhas(mat_transposta);
  int col_transposta = mat_colunas(mat_transposta);
  puts("Matriz Transposta:");
  printf("\n Linhas: %d | Colunas: %d",lin_transposta,col_transposta);

  // k = i*n + j
  float elem_transposta;
  for(int i = 0; i<3; i++){
    for(int j = 0; j<4; j++){
      elem_transposta = mat_acessa(matriz,i,j);
      mat_atribui(mat_transposta,j,i,elem_transposta);
    }
  }

  printf("\n   ");
  for(int i = 0; i<4; i++){
    printf("\n   ");
    for(int j = 0; j<3; j++){
      elem_transposta = mat_acessa(mat_transposta,i,j);
      printf("%.1f  ", elem_transposta);
    }
  }
  puts("\n   ");

  mat_libera(matriz);
  mat_libera(mat_transposta);
  return 0;
}
