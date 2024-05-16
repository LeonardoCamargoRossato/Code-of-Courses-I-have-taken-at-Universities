#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ponto Ponto;
struct ponto {
  int i; int j;
};

typedef struct circ Circ;
struct circ {
  Ponto o; float r;
};

typedef struct ret Ret;
struct ret {
  Ponto v1; Ponto v2;
};

Ret* ret_circunscrito(Circ* c, float h){
  int rx = sqrt(((h/2)*(h/2)) + (c->r)*(c->r)); //Componente R->x
  float Area_Ret = 2*rx*h;
  printf("Area Maxima do Retangulo Circunscrito: %.2f",Area_Ret);

  //RETORNA OS VÉRTICES DO RETANGULO CIRCUNSCRITO MAXIMO
  Ret* ret;
  ret->v1.i = -rx; ret->v1.j = -h/2;
  ret->v2.i = rx; ret->v2.j = h/2;
  return ret;
}

Circ* circ_interno(Ret* r){
  Circ* circ;
  circ->o.i = 0; circ->o.j = 0;

  if(r->v2.i <= r->v2.j){
    circ->r = r->v2.i; return circ;}
  else{
    circ->r = r->v2.j; return circ;}
}
0
void main(){
  printf("\n\n## Funcao: Maior Retangulo Circunscrito ##\n");
  Ponto* origem_circulo = (struct ponto*)malloc(sizeof(struct ponto));
  Circ* c = (struct circ*)malloc(sizeof(struct circ));
  Ret* ret_main = (struct ret*)malloc(sizeof(struct ret));
  Circ* circ_main = (struct circ*)malloc(sizeof(struct circ));
  float h; float raio; int i; int j;

  printf("\nDigite: Origem Circulo:(i,j); Raio(r); Altura Retangulo(h); \n --> ");
  scanf("%d %d %f %f",&i,&j,&raio,&h);
  if (2*raio < h){
    printf("\nValores de input invalidos: (2*r < h). \n Try Again.\n"); exit(1);
  }

  origem_circulo->i = i; origem_circulo->j = j;
  c->o = *origem_circulo; c->r = raio;
//  printf("\norigem_circulo->i: %d, i = %d, c->r = %.0f \n",origem_circulo->i,i,c->r); printf("\norigem_circulo->j: %d, j = %d \n",origem_circulo->j,j); printf("\nc->o = %d , %d \n",c->o.i,c->o.j);
  ret_main = ret_circunscrito(c,h);
  puts("\n\nVertices do Retangulo Circunscrito Maximo:");
  printf(" ret{v1(i,j),v2(i,j)} = {(%d,%d),(%d,%d)}\n",ret_main->v1.i,ret_main->v1.j,ret_main->v2.i,ret_main->v2.j);

  circ_main = circ_interno(ret_main);
  puts("\n\nRaio do Círculo Interno Maximo; E cord. do Centro:");
  printf(" raio = %0.2f \n Centro = (%d,%d)\n\n",circ_main->r,circ_main->o.i,circ_main->o.j);


  free(origem_circulo); free(c); //free(Retangulo_main);
  exit(1);
}
