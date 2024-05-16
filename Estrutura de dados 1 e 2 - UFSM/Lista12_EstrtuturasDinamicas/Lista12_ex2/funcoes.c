#include "matriz.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct matriz Matriz;
struct matriz {
  int lin;
  int col;
  float* v;
};

Matriz* mat_cria(int m, int n){
  Matriz* mat = (Matriz*)malloc(m*n*sizeof(Matriz));
  if (mat == NULL){
    printf("\nMemoria Insuficiente!\n");
    exit(1);
  }
  mat->lin = m; mat->col = n;
  mat->v = (float*)malloc(m*n*sizeof(float));
  return mat;
}

void mat_libera(Matriz* mat){
  free(mat->v);
}

float mat_acessa(Matriz* mat,int i,int j){
  int k = i*mat->col + j;
  return mat->v[k];
}

void mat_atribui(Matriz* mat, int i, int j, float v){
  int k = i*mat->col + j;
  mat->v[k] = v;
}

int mat_linhas(Matriz* mat){
  return mat->lin;
}

int mat_colunas(Matriz* mat){
  return mat->col;
}
