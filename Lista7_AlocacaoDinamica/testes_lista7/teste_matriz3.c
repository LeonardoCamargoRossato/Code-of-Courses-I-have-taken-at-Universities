#include <stdio.h>

int main(){
  printf("\n");
  int mat[4][4] = {
    {1, 1, 1, 1},
    {1, 1, 1, 0},
    {1, 1, 0, 0},
    {1, 0, 0, 0}
  };

  for(int i = 0; i<4; i++){
    for(int j = 0; j<4; j++){
      printf(" %d ",mat[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  return 0;
}
