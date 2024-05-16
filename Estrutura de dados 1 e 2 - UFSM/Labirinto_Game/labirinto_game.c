#include <stdio.h>
#include <stdlib.h>

int** cria_matriz_zeros(int n){

  int** matriz = (int**)malloc(n*sizeof(int*));
  for(int i = 0; i<n; ++i){
    matriz[i] = (int*)malloc((i+1)*sizeof(int));
  }
  return matriz;
}

void printa_matriz(int** cria_main, int n){

  printf("\n   ");
  for(int i = 0; i<=n; ++i){ printf("##"); if (i == n){ printf("###");}}
  printf("\n   # ");
  for(int i = 0; i<n; ++i){
    for(int j = 0; j<=n; ++j){
      printf("%d ", cria_main[i][j]);
      if (j == n){ printf("#");}
    }
    if (i < n-1){ printf("\n   # ");}
  }
  printf("\n   ");
  for(int i = 0; i<=n; ++i){ printf("##"); if (i == n){ printf("###");}}
  printf("\n\n");
}

void atribui_matriz_direta(int** cria_main, int i,int j,int n, int user){
  cria_main[i][j] = user;
  printa_matriz(cria_main,n);
}
int IrPraEsquerda(int** cria_main, int i,int j,int n){
  cria_main[i][j-1] = cria_main[i][j];
  cria_main[i][j] = 0;
  printf("\n\n ##### LABIRINTO GAME ##### \n\n");
  printa_matriz(cria_main,n);
  return j = j-1;
}

int IrPraDireita(int** cria_main, int i,int j,int n){
  cria_main[i][j+1] = cria_main[i][j];
  cria_main[i][j] = 0;
  printf("\n\n ##### LABIRINTO GAME ##### \n\n");
  printa_matriz(cria_main,n);
  return j = j+1;
}
int IrPraCima(int** cria_main, int i,int j,int n){
  cria_main[i-1][j] = cria_main[i][j];
  cria_main[i][j] = 0;
  printf("\n\n ##### LABIRINTO GAME ##### \n\n");
  printa_matriz(cria_main,n);
  return i = i-1;
}
int IrPraBaixo(int** cria_main, int i,int j,int n){
  cria_main[i+1][j] = cria_main[i][j];
  cria_main[i][j] = 0;
  printf("\n\n ##### LABIRINTO GAME ##### \n\n");
  printa_matriz(cria_main,n);
  return i = i+1;
}


int main(){
  int n = 5; int user = 5;
  printf("\n\n ##### LABIRINTO GAME ##### \n\n");

  int** cria_main = cria_matriz_zeros(n);

  //1°Turno: 5 começa na CASA (3,0)
  int i = 3; int j = 0;
  atribui_matriz_direta(cria_main,i,j,n,user);

  char x; int IrPraCima_main; int IrPraEsquerda_main;
  int IrPraDireita_main; int IrPraBaixo_main;
  volta: printf(" 'w': Ir pra Cima. \n 'd': Ir pra Direita. \n 'a': Ir pra Esquerda.  \n 's': Ir pra Baixo \n 'e':  p/sair do programa. \n --> ");
  scanf(" %c", &x);
  if (x == 'w'){ IrPraCima_main = IrPraCima(cria_main,i,j,n);
    i = IrPraBaixo_main; goto volta;}
  else if(x == 'd'){ IrPraDireita_main = IrPraDireita(cria_main,i,j,n);
    j = IrPraDireita_main; goto volta;}
  else if(x == 'a'){ IrPraEsquerda_main = IrPraEsquerda(cria_main,i,j,n);
    j = IrPraEsquerda_main; goto volta;}
  else if(x == 's'){ IrPraBaixo_main = IrPraBaixo(cria_main,i,j,n);
    i = IrPraBaixo_main; goto volta;}
  else if(x == 'e') {exit(0);}

  for(int i = 0; i<n; i++){ free(cria_main[i]); }
  free(cria_main);
  return 0;
}
