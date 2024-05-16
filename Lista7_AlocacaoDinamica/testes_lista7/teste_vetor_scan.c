#include<stdio.h>
#include<stdlib.h>

int main(){
  printf("Digite o tamanho do vetor: ");
  int n;
  scanf("%d",&n);

  int* v;
  printf("Digite os valores do vetor: ");
  for(int i = 0; i<n; ++i){
    scanf("%d",&v[i]);
    printf(" %d",2*v[i]);
  }

  printf("\nVetor = {");
  for(int i = 0; i<n; ++i){
    printf(" %d",2*v[i]);
  }
  printf(" }\n\n");

  return 0;
}
