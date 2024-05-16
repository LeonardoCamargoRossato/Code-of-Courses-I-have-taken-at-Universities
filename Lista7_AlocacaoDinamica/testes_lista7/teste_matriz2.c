#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
    printf("\n ");
  float mat [3][4] = {
    {1.0f, 2.0f, 3.0f, 4.0f},
    {1.0f, 2.0f, 3.0f, 4.0f},
    {1.0f, 2.0f, 3.0f, 4.0f}
  };

  for(int i = 0;i<3;i++){
    for(int j = 0; j<4;j++){
      printf(" M(%d,%d) = %.1f ", i, j, mat [i][j]);
    }
    printf("\n ");
  }
  return 0;
}
