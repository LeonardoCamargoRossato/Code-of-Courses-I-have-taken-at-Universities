#include <stdio.h>
#include <stdlib.h>

float** ti_cria (int n){
// ALOCA DINAMICAMENTE OS VALORES DOS ELEMENTOS DA MATRIZ
  float **mat = (float**)malloc(n*sizeof(float*));
  for(int i = 0; i<n; ++i){
      mat[i] = (float*)malloc((i+1)*sizeof(float));
    }

// PRINTA "SIMBOLICAMENTE" A MATRIZ ZERO
  printf("\nFuncao ti_cria (matriz zero): \n\n   ");

  for(int i = 0; i<n; ++i){
    for(int j = 0; j<n; ++j){
        **mat = 1;
        printf("%g ", **mat);
    }
    printf("\n   ");
  }
  printf("\n");
  return mat;
}

float **ti_atribui(int n, float mat, int i, int j, float x){
  // ALOCA DINAMICAMENTE OS VALORES DOS ELEMENTOS DA MATRIZ
    **mat = (float**)malloc(n*sizeof(float*));
    for(int i = 0; i<n; ++i){
        mat[i] = (float*)malloc((i+1)*sizeof(float));
      }
  // TRAVA - MATRIZ TRIANGULAR INFERIOR (A PARTE ACIMA DA DIAGONAL É TUDO ZERO)
  printf("\n   ");
  if (j>i){
    printf("Esse elemento da Matriz não pode ser acessado, pois (j>i). \n *Lembre que essa é uma matriz triangular superior.\n\n");
    exit(0);
  }
  // ATRIBUI VALOR AO ELEMENTO DA MATRIZ E PRINTA A MATRIZ
  for(int k = 0; k<n; ++k){
    for(int l = 0; l<n; ++l){
      if ((k == i) && (l == j)) {
        printf("%.0f ", x);
      }
      else{
        printf("%.0f ", mat);
      }
    }
    printf("\n   ");
  }
  printf("\n");
  //return mat;
}

float** ti_acessa (int n, float mat, int i, int j){
  // ATRIBUI VALOR AO ELEMENTO DA MATRIZ E PRINTA A MATRIZ
  //printf("%f ", mat[i][j]);
  for(int p = 0; p<n; ++p){
    for(int q = 0; q<n; ++q){
      if ((p == i) && (q == j)) {
        printf("%0.f ", mat);
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
  float **mat = ti_cria(n);

  printf("\nDigite: qual elemento (i,j) vc quer atribuir valor; E o respectivo valor : \n --> ");
  int i; int j; float x;
  scanf("%d %d %f", &i, &j, &x);
  mat = ti_atribui(n,**mat,i,j,x);

  printf("\nDigite: qual elemento (i,j) vc quer atribuir valor; E o respectivo valor : \n --> ");
  int i3; int j3; float x3;
  scanf("%d %d %f", &i3, &j3, &x3);
  ti_atribui(n,**mat,i3,j3,x3);

  printf("\nDigite: qual elemento (i,j) vc quer acessar: \n --> ");
  int i2; int j2;
  scanf("%d %d", &i2, &j2);
  ti_acessa(n,**mat,i2,j2);


  return 0;
}
