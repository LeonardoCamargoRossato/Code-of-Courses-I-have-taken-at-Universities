#include<stdio.h>
#include<stdlib.h>

int* vetor_captura(int n){
  printf("Digite os valores do vetor: \n --> ");
  int* vetor = (int*)malloc(n*sizeof(int)); //p = &n;
  //for (int i = 0; i<n; i++){
  //  scanf("%d",&vetor[i]); // &p[i] == p
  //}
  printf("\n Vetor de ZEROS: {");
    for (int i = 0; i<n; i++){
      vetor[i] = 0;
      printf("%d ", vetor[i]);
    }
  printf("}\n");

  return vetor;
}

void atribui(int *vetor_main, int n){

  int valor_elemento_i; int elemento_i;

  // PRINTA O VETOR_1 Pré ATRIBUIÇAO
//  printf("\nValor do vetor1 PRE atribuição = { ");
  //for (int i = 0; i<n;++i){
    //printf("%d ", vetor1[i]);
  //}
//  printf("}\n");

  printf("\nDigite o elemento (i) que vc quer atribuir;E o valor correspondente: \n --> ");
  scanf("%d %d", &elemento_i, &valor_elemento_i);

  vetor_main[elemento_i] = valor_elemento_i;

  // PRINTA O VETOR_1 PÓS ATRIBUIÇAO
  //printf("\nValor do vetor1 PÓS atribuição = { ");
  //for (int i = 0; i<n;++i){
    //printf("%d ", vetor1[i]);
  //}
  //printf("}\n");

  //return *vetor_main;
}

int main(){
  int n;
  printf("\n\nDigite o tamanho do vetor (n): ");
  scanf("%d",&n);

  int* vetor_main = vetor_captura(n);

  printf("Valor do vetor_main(captura) = { ");
  for (int i = 0; i<n;++i){
    printf("%d ", vetor_main[i]);
  }
  printf("}\n");

  //int vetor1_main =
  atribui(vetor_main,n);

  printf("Valor do vetor_main = { ");
  for (int i = 0; i<n;++i){
    printf("%d ", vetor_main[i]);
  }
  printf("}\n");


  // TESTES PRA VER SE OS VALORES DOS VETORES ORIGINAIS MUDOU
  printf("\nvalor de (n): %d ",n);
  printf("\nValor do vetor_main= { ");
  for (int i = 0; i<n;++i){
    printf("%d ", vetor_main[i]);
  }
  printf("}\n\n");

  free(vetor_main);
//  free(vetor1_main);
  return 0;
}
