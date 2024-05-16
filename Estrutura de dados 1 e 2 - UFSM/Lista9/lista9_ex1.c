#include <stdio.h>
#include <stdlib.h>

typedef struct ponto Ponto;
struct ponto {
  int i; int j;
};

void captura(Ponto* v1,Ponto* v2,Ponto* p){
  printf("\nDigite: v.inf v1:(i,j); vert.sup v2:(i,j); E o ponto p:(i,j) \n --> ");
  scanf("%d %d %d %d %d %d", &v1->i,&v1->j,&v2->i,&v2->j,&p->i,&p->j);
}

int dentroRet(Ponto* v1,Ponto* v2,Ponto* p){
  if (((p->i <= v1->i) && (p->j >= v1->j)) && ((p->i >= v2->i) && (p->j <= v2->j))){
    printf("1\n");
    free(v1); free(v2); free(p);
    return 1;
  }
  else{
    printf("0\n");
    free(v1); free(v2); free(p);
    return 0;}
}

void main(){
  printf("\n\n#Descrição Função:Diz se o ponto p:(i,j) está dentro do retângulo de vértices v1 e v2\n");
  Ponto* v1; v1 = (struct ponto*)malloc(sizeof(struct ponto));
  Ponto* v2; v2 = (struct ponto*)malloc(sizeof(struct ponto));
  Ponto* p;  p  = (struct ponto*)malloc(sizeof(struct ponto));

  captura(v1,v2,p);
  dentroRet(v1,v2,p);
}
