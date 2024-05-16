#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

typedef struct listano ListaNo;
struct listano{
  float info;
  ListaNo* prox;
};

struct fila{
  ListaNo* ini;
  ListaNo* fim;
};

Fila* fila_cria(void){
  Fila* f = (Fila*)malloc(sizeof(Fila));
  f->ini = f->fim = NULL;
  return f;
}

void fila_insere(Fila* f, float v){
  ListaNo* n = (ListaNo*)malloc(sizeof(ListaNo));
  n->info = v;
  n->prox = NULL; //Como a inserção é no fim da fila, o nó prox é dps do último,logo NULL
  if(f->fim!=NULL)
    f->fim->prox = n;
  else
    f->ini = n;
  f->fim = n;
}

float fila_retira(Fila* f){
  ListaNo* t = f->ini;
  float v = t->info;
  f->ini = t->prox;
  if(f->ini == NULL) // caso fila fique vazia
    f->fim = NULL;
  free(t);
  return v;
}

int fila_vazia(Fila* f){
  return(f->ini==NULL);
}

void fila_libera(Fila* f){
  ListaNo* q = f->ini;
  while(q!=NULL){
    ListaNo* t = q->prox;
    free(q);
    q = t;
  }
  free(f);
}

void fila_imprime(Fila* f){
  ListaNo* q = f->ini;
  printf("{");
  while(q!=NULL){
    printf(" %.1f",q->info);
    q=q->prox;
  }
  printf(" }");
}

void combina_filas(Fila* f_res,Fila* f1,Fila* f2){
  ListaNo* q1 = f1->ini;
  ListaNo* q2 = f2->ini;
  int cont1 = 0;
  while(q1!=NULL && q2!=NULL){
    fila_insere(f_res,q1->info);
    q1=q1->prox;
    fila_insere(f_res,q2->info);
    q2=q2->prox;
    cont1++;
  }
  int cont2 = 0;
  ListaNo* q3 = f1->ini;
  while(q3!=NULL){
    cont2++;
    if(cont2 > cont1){
      fila_insere(f_res,q3->info);
      q3=q3->prox;
    }
    else
      q3=q3->prox;
  }
  int cont3 = 0;
  ListaNo* q4 = f2->ini;
  while(q4!=NULL){
    cont3++;
    if(cont3 > cont1){
      fila_insere(f_res,q4->info);
      q4=q4->prox;
    }
    else
      q4=q4->prox;
  }
  fila_libera(f1);
  fila_libera(f2);
}
