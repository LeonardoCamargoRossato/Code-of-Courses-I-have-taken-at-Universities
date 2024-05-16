#include <stdio.h>
#include <stdlib.h>

int analisar_triang_inf(int n, int mat[n][n]){
  for(int i = 0; i<n; ++i){
    for(int j = i+1; j<n; ++j){
      if(mat[i][j] != 0){
        printf("\nReturn: 0 \n");
        return 0;
      }
    }
  }
  printf("\nReturn: 1 \n");
  return 1;
}

int main(){
  int n = 4;
  int m = 4;
  //printf("\nDigite a dimensão da matriz quadrada: ");
  //scanf("%d",&n);
//  int* mat = (int*)malloc(m*n*sizeof(int));
  int mat[4][4] = {
    {1, 0, 3, 0},
    {1, 1, 0, 0},
    {1, 1, 1, 0},
    {1, 1, 1, 1}
  };

  analisar_triang_inf(n,mat);

  return 3;
}
