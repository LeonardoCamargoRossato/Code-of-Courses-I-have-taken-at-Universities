#include<stdio.h>
#include<stdlib.h>

void v_captura(int n, float *v){

  int i;
  for(int i = 0; i<n; ++i){
    v[i] = 0; // v ~ &v[i]; //ENDEREÇAMENTO DO VETOR
}

float* v_cria(int n, float *v){

  //PRINTAR VETOR DE ZEROS
  printf("\nVetor de Zeros: \n   v = { ");
  for(int i = 0; i<n; ++i){
    *v = 1.0;
    printf("%.0f ", *v);
  }
  printf("} \n\n");
  return v;
}

void v_atribui(int n, float *v, int i, float x){
  //ATRIBUIÇAO DO VALOR X NO VETOR V[I]
  x = v[i];
  v[i] = x;
  // PRINTAR VETOR
  printf("\nVetor Alterado: \n   v = { ");
  for(int i = 0; i<n; ++i){
    printf("%.0f ", *v);
  }
  printf("} \n\n");
}

int main(){
  int n;
  //ALOCAÇÃO DINÂMICA DO VETOR DE ZEROS
  float *v = (float*)malloc(n*sizeof(float));

  v_captura(n);
  printf("\nDigite o tamanho do vetor: \n -->  ");
  scanf("%d",&n);

  v = v_cria(n);

  printf("Digite o elemento (i) que vc quer atribuir; E o valor correspondente: \n --> ");
  int i; float x;
  scanf("%d %f", &i, &x);
  v_atribui(n,v,i,x);


  return 0;
}
