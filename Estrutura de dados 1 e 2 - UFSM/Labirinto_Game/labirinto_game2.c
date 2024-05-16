#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char** cria_matriz_zeros(int n){

  char** matriz = (char**)malloc(n*sizeof(char*));
  for(int i = 0; i<n; ++i){
    matriz[i] = (char*)malloc(n*sizeof(char));
  }
  for(int i = 0; i<n; i++){
    for(int j = 0; j<n; j++){
      matriz[i][j] = ' ';
    }
  }

  return matriz;
}

void printa_matriz(char** cria_main, int n){

  printf("\n   ");
  for(int i = 0; i<=n; ++i){ printf("##"); if (i == n){ printf("#");}}
  printf("\n   # ");
  for(int i = 0; i<n; ++i){
    for(int j = 0; j<n; ++j){
      printf("%c ", cria_main[i][j]);
      if (j == n-1){ printf("#");}
    }
    if (i < n-1){ printf("\n   # ");}
  }
  printf("\n   ");
  for(int i = 0; i<=n; ++i){ printf("##"); if (i == n){ printf("#");}}
  printf("\n\n");
}

void atribui_matriz_direta(char** cria_main, int i,int j,int n, const int user){
  cria_main[i][j] = user; printa_matriz(cria_main,n);
}

int gera_numero(){
  int r;
  volta: for(int i = 0; i<2; i++){
    r = rand()%11; RAND_MAX;
    srand( (unsigned)time(NULL) );
    if (r<=10){break;}
  }
  if (r>10){ goto volta;}
  return r;
}

int IrPraEsquerda(char** cria_main,int i,int j,int n,int cont_pontos){
  printf("\n\n ### LABIRINTO GAME ### \n Pontos: %d  \n",cont_pontos);
  if ((i > n) || (j > n) || (j < 0) || (i < 0)){
    printa_matriz(cria_main,n); return j;}
  cria_main[i][j-1] = cria_main[i][j];
  cria_main[i][j] = ' ';
  printa_matriz(cria_main,n);
  return j = j-1;
}

int IrPraDireita(char** cria_main,int i,int j,int n,int cont_pontos){
  printf("\n\n ### LABIRINTO GAME ### \n Pontos: %d  \n",cont_pontos);
  if ((i > n) || (j > n) || (j < 0) || (i < 0)){
    printa_matriz(cria_main,n); return j;}
  cria_main[i][j+1] = cria_main[i][j];
  cria_main[i][j] = ' ';
  printa_matriz(cria_main,n);
  return j = j+1;
}
int IrPraCima(char** cria_main,int i,int j,int n,int cont_pontos){
  printf("\n\n ### LABIRINTO GAME ### \n Pontos: %d  \n",cont_pontos);
  if ((i > n) || (j > n) || (j < 0) || (i < 0)){
    printa_matriz(cria_main,n); return i;}
  cria_main[i-1][j] = cria_main[i][j];
  cria_main[i][j] = ' ';
  printa_matriz(cria_main,n);
  return i = i-1;
}
int IrPraBaixo(char** cria_main,int i,int j,int n,int cont_pontos){
  printf("\n\n ### LABIRINTO GAME ### \n Pontos: %d  \n",cont_pontos);
  if ((i > n) || (j > n) || (j < 0) || (i < 0)){
    printa_matriz(cria_main,n); return i;}
  cria_main[i+1][j] = cria_main[i][j];
  cria_main[i][j] = ' ';
  printa_matriz(cria_main,n);
  return i = i+1;
}
void func_free(char** cria_main,int n){
  for(int i = 0; i<n; i++){ free(cria_main[i]); }
  free(cria_main);
}

int main(){
  int n = 10; char user = 'o';
  printf("\n\n ##### LABIRINTO GAME ##### \n Pontos: 0\n");

  char** cria_main = cria_matriz_zeros(n);

  int i = 0; int j = 0; //1°Turno: 5 começa na CASA (0,0)
  cria_main[i][j] = user;

  int r_i, r_j, cont_pontos = 0; char bola = '+';
  int IrPraCima_main, IrPraEsquerda_main, IrPraDireita_main, IrPraBaixo_main;
  char x;
  r_i = gera_numero(); r_j = gera_numero();
  atribui_matriz_direta(cria_main,r_i,r_j,n,bola);
  volta: printf(" 'w': Ir pra Cima. \t 'd': Ir pra Direita. \t 'a': Ir pra Esquerda.  \t  's': Ir pra Baixo \t 'e': Sair do programa. \n --> ");
  scanf(" %c", &x);
  if((r_i==i) && (r_j==j)){ cont_pontos++;
    r_i = gera_numero(); r_j = gera_numero(); atribui_matriz_direta(cria_main,r_i,r_j,n,bola);
    IrPraDireita_main = IrPraDireita(cria_main,i,j,n,cont_pontos);j = IrPraDireita_main;
    IrPraEsquerda_main = IrPraEsquerda(cria_main,i,j,n,cont_pontos);j = IrPraEsquerda_main;
    goto volta;}
  switch (x) {
    case 'w':{ IrPraCima_main = IrPraCima(cria_main,i,j,n,cont_pontos);
      i = IrPraCima_main; goto volta;}
    case 'd':{ IrPraDireita_main = IrPraDireita(cria_main,i,j,n,cont_pontos);
      j = IrPraDireita_main; goto volta;}
    case 'a':{ IrPraEsquerda_main = IrPraEsquerda(cria_main,i,j,n,cont_pontos);
      j = IrPraEsquerda_main; goto volta;}
    case 's':{ IrPraBaixo_main = IrPraBaixo(cria_main,i,j,n,cont_pontos);
      i = IrPraBaixo_main; goto volta;}
    case 'e': break;
    default: break;
  }

  return 0;
}
