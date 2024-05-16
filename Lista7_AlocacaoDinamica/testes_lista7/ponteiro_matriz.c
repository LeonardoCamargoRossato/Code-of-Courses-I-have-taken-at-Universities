#include <stdio.h>
#include <stdlib.h>

float** cria_matriz_zeros(int n){

  float** matriz = (float**)malloc(n*sizeof(float*));
  for(int i = 0; i<n; ++i){
    matriz[i] = (float*)malloc((i+1)*sizeof(float));
  }
  return matriz;
}

void printa_matriz(float** cria_main, int n){

  printf("\n Matriz_Atribuida: \n\n   ");
  for(int i = 0; i<n; ++i){
    for(int j = 0; j<=i; ++j){
      printf("%.0f ", cria_main[i][j]);
    }
    printf("\n   ");
  }
  printf("\n");
}

void atribui_matriz(float** cria_main){
  int i; int j; float x;
  printf("\n Digite o elemento (i,j) da matriz; e o valor de atribuição: \n --> ");
  scanf("%d %d %f", &i, &j, &x);

  if (i>=j){
    cria_main[i][j] = x;
  }
  else {
    puts("\n\n Ops... esse elemento tem coordenadas (i>j) e portanto, inválido. \n --> Try Again. ");
  }
}

void atribui_vetor_na_matriz(float** cria_main, int n){

  printf(" Digite 1: p/adicionar o vetor em uma linha da matriz. \n Digite 0: p/adicionar o vetor em uma coluna da matriz. \n --> ");
  int x; scanf("%d",&x);
  switch (x) {
    case 1: {
      int i; int n_vetor;
      float* vetor_atribuicao = (float*)malloc(n_vetor*sizeof(float));
      printf(" Digite: \n A linha (i) da matriz: "); scanf("%d",&i);
      printf(" O tamanho do vetor: "); scanf("%d",&n_vetor);
      printf(" Valores do Vetor: ");
      if ((n_vetor <= i+1) && (i<=n)){
        for (int k = 0; k < n_vetor; k++) {
          scanf("%f",&vetor_atribuicao[k]);
          cria_main[i][k] = vetor_atribuicao[k];
        }
        break;
      }
      else if(i>n){
        printf(" Ops... Vc digitou uma linha (i) que é maior que o tamanho da matriz (i>n). \n");
        break;
      }
      else {
        printf(" Ops... O tamanho do vetor que vc escolheu excede a quantia de elementos da coluna.\n");
        break;
      }
    }
    case 0: {
      int j; int n_vetor0;
      float* vetor_atribuicao0 = (float*)malloc(n_vetor0*sizeof(float));
      printf(" Digite: \n A coluna (j) da matriz: "); scanf("%d",&j);
      printf(" O tamanho do vetor: "); scanf("%d",&n_vetor0);
      printf(" Valores do Vetor: ");
      if((n_vetor0 <= n-j) && (j<=n)){

        for (int k = 0; k < n; k++) {
          scanf("%f",&vetor_atribuicao0[k]);
          printf("  %.0f ",vetor_atribuicao0[k]);
        }

        int x = 0;

        //  printf("  %.d ",x);
        for (int k = 0; k < n; k++) {
          //x = j+k;
          cria_main[j][k] = vetor_atribuicao0[k];
        }
        break;
      }
      else if(j>n){
        printf("\n\n Ops... Vc digitou uma coluna (j) que é maior que o tamanho da matriz (j>n). \n\n");
        break;
      }
      else {
        printf("\n\n Ops... O tamanho do vetor que vc escolheu excede a quantia de elementos da linha.\n\n");
        break;
      }
    }
    default: break;
  }
}


int main(){
  int n;
  printf("\n\n Digite a dimensão da matriz: ");
  scanf("%d", &n);

  float** cria_main = cria_matriz_zeros(n);
  printa_matriz(cria_main,n);

  int x;
  volta: printf(" Digite 3:  p/atribuir um vetor de valores à matriz. \n Digite 2:  p/atribuir um valor a um elemento da matriz. \n Digite 1:  p/printar a matriz triangular. \n Digite 0:  p/sair do programa. \n --> ");
  scanf("%d", &x);

  switch (x) {
    case 3: atribui_vetor_na_matriz(cria_main,n); goto volta;
    case 2: atribui_matriz(cria_main); goto volta;
    case 1: printa_matriz(cria_main,n); puts("\n"); goto volta;
    case 0: break;
    default: break;
  }

  for(int i = 0; i<n; i++){ free(cria_main[i]); }
  free(cria_main);
  return 0;
}
