#include<stdio.h>
#include<stdlib.h>

int* point(int n){
  int* p = &n; //p = &n;
  printf("Valor de p = %d\n", *p);
  return p;
}

int* atribui(int p_main){
  int* p1;
  p1 = &p_main;
  printf("Valor de pi antes da atribuição = %d\n", *p1);

  int n1;
  printf("Digite um valor para atribuir ao ponteiro: ");
  scanf("%d",&n1);
  p1 = &n1;
  printf("Valor de pi dps da atribuição = %d\n", *p1);

  return p1;
}

int main(){
  int n;
  printf("\n\nDigite um valor (n): ");
  scanf("%d",&n);
  printf("\nPrimeiro Valor (n) = %d\n",n);

  int* p_main;
  p_main = point(n);
  printf("\nValor do p_main = %d\n", *p_main);

  int* p1_main;
  p1_main = atribui(*p_main);
  printf("\nValor do p1_main = %d \n\n", *p1_main);

  printf("\nValor do p_main = %d\n", *p_main);
  printf("valor de (n): %d \n\n",n);
  return 0;
}
