#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3,1416


typedef struct ponto Ponto;
struct ponto {
  int x; int y;
};

typedef struct circulo Circulo;
struct circulo {
  Ponto c; float r;
};


int intersecao(Circulo* a,Circulo* b){
  int n = a->r;
  for (int i = 0; i <= n ; i++){
    for(int k = 0; k<=PI; k++){
      if ( ((a[i].r*cos(k)+a->c.x)-(b->c.x-b[i].r*cos(k))) >= 0 && ((a[i].r*sin(k)+a->c.y)-(b->c.y)-b[i].r*sin(k)) >= 0 ) {
        printf("\n 1     Há Interseçao.\n"); return 1;
      }
      else{
        printf("\n 0     Não há Interseçao.\n"); return 0;
      }
    }
  }
}


int main(){

  Circulo* a = (struct circulo*)malloc(sizeof(struct circulo));
  Circulo* b = (struct circulo*)malloc(sizeof(struct circulo));

  printf("\nDigite: Raio A ; Raio B \n --> ");
  scanf("%f %f",&a->r,&b->r);
  printf("\nDigite: Centro A: (x,y); Centro B: (x,y) \n --> ");
  scanf("%d %d %d %d ",&a->c.x,&a->c.y,&b->c.x,&b->c.y);
  //int aleatorio; scanf("%d\n",&aleatorio);

  printf("a->c.x: %d\n",a->c.x);
  printf("a->c.y: %d\n",a->c.y);
  printf("b->c.x: %d\n",b->c.x);
  printf("b->c.y: %d\n",b->c.y);

  int intersecao_main = intersecao(a,b);

  free(a); free(b);
  return 0;
}
