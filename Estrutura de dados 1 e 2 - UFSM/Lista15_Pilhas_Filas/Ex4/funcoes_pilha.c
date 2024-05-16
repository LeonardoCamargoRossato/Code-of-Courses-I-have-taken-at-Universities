#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

typedef struct listano ListaNo;
struct listano{
  float info;
  ListaNo* prox;
};

struct pilha{
  ListaNo* prim;
};

Pilha* pilha_cria(void){
  Pilha* p = (Pilha*)malloc(sizeof(Pilha));
  p->prim = NULL;
  return p;
}

void pilha_push(Pilha* p,float v){
  ListaNo* n = (ListaNo*)malloc(sizeof(ListaNo));
  n->info = v;
    n->prox = p->prim;
  p->prim = n;
}

float pilha_pop(Pilha* p){
  ListaNo* t = p->prim;
  float v = t->info;
  p->prim = t->prox;
  free(t);
  return v;
}

int pilha_vazia(Pilha* p){
  return (p->prim==NULL);
}

void pilha_libera(Pilha* p){
  ListaNo* q = p->prim;
  while(q!=NULL){
    ListaNo* t = q->prox;
    free(q);
    q = t;
  }
  free(p);
}

void pilha_imprime(Pilha* p){
  ListaNo* q = p->prim;
  printf("{");
  while(q!=NULL){
    printf(" %.1f",q->info);
    q=q->prox;
  }
  printf(" }");
}

float topo(Pilha* p){
  ListaNo* t = p->prim;
  return t->info;
}

void concatena_pilhas(Pilha* p1,Pilha* p2){
  ListaNo* q = p2->prim;
  while(q!=NULL){
    pilha_push(p1,q->info);
    q=q->prox;
  }
  pilha_libera(p2);
}

Pilha* copia_pilha(Pilha* p){
  Pilha* pi = pilha_cria();
  ListaNo* q = p->prim;
  while(q!=NULL){
    pilha_push(pi,q->info);
    q=q->prox;
  }
  Pilha* pi2 = pilha_cria();
  ListaNo* q2 = pi->prim;
  while(q2!=NULL){
    pilha_push(pi2,q2->info);
    q2=q2->prox;
  }
  return pi2;
}
