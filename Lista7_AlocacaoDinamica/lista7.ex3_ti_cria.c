#include <stdio.h>
#include <stdlib.h>

float ti_cria (int n){

  float** mat = (float**)malloc(n*n*sizeof(float*));
  for(int i = 0; i<n; ++i){
    for(int j = 0; j<n; ++j){
      mat[i][j];
    }
  }
  printf("\nFuncao ti_cria (matriz zero): \n\n   ");
  for(int i = 0; i<n; ++i){
    for(int j = 0; j<n; ++j){
      float mat[i][j] = 0;
      printf("%.0f ", mat[i]]j);
    }
    printf("\n   ");
  }
  printf("\n");
}

float ti_atribui(int i, int j, float x){
  int n;
// ATRIBUI VALOR AO ELEMENTO DA MATRIZ E PRINTA A MATRIZ
  float** mat;
  for(int k = 0; k<n; ++i){
    for(int l = 0; l<n; ++j){
      if ((k == i) && (l == j)) {
        mat = x;
        printf("%.0f ", mat);
      }
      else {
        mat = 0;
        printf("%.0f ", mat);
      }
    }
    printf("\n   ");
  }
  printf("\n");
}

int main(){
  int n;
  printf("\n\nDigite a dimensão da Matriz Quadrada: ");
  scanf("%d",&n);
  ti_cria(n);

  printf("\nDigite qual elemento (i,j) vc quer acessar e qual valor deseja atribuí-lo: \n --> ");
  int i; int j; float x;
  scanf("%d %d %f", &i, &j, &x);
  ti_atribui(i,j,x);



  return 0;
}
