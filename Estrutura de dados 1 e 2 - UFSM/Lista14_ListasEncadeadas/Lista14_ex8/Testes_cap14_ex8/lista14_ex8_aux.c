#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista Lista;
typedef struct listano ListaNo;

struct lista{
  ListaNo* prim;
};

struct listano{
  int info;
  ListaNo* prox;
};

Lista* cria_lista(void){
  Lista* l = (Lista*)malloc(sizeof(Lista));
  l->prim = NULL;
  return l;
}

void insere_lista(Lista* l, int info){
  ListaNo* novo = (ListaNo*)malloc(sizeof(ListaNo));
  novo->info = info;
  novo->prox = l->prim;
  l->prim = novo;
}

void imprime_lista(Lista* l){
  ListaNo* p;
  printf("{ ");
  for(ListaNo* p=l->prim; p!=NULL; p=p->prox){
    printf("%d ", p->info);
  }
  printf("}\n");
}

void libera_lista(Lista* l){
  ListaNo* p = l->prim;
  while(p != NULL){
    ListaNo* t = p->prox;
    free(p);
    p = t;
  }
  free(l);
}
void retira_n(Lista* l,int x){
  ListaNo* p = l->prim;
  ListaNo* ant = NULL;
  while(p != NULL && p->info != x){
    ant = p;
    p = p->prox;
  }
  if(p != NULL){ //verifica se achou o valor x na lista
    if(ant == NULL) //retira elem se x == ao primeiro elem da lista
      l->prim = p->prox;
    else //retira elem para (todos) os outros casos
      ant->prox = p->prox;
    free(p);
  }
}
static ListaNo* retira_nos(ListaNo* p,int x){
  puts("AAAAAA");
  if(p!=NULL){
    if(p->info == x){
      ListaNo* t = p;
      p=p->prox;
      free(t);
    }
    else
      p->prox = retira_nos(p->prox,x);
  }
  return p;
}

Lista* inverte(Lista* l1){
  ListaNo* p = l1->prim;
  Lista* l1_aux = cria_lista();
  int cont = 0;
  while(p!=NULL){
    cont++;
    insere_lista(l1_aux,p->info);
    p=p->prox;
  }
  libera_lista(l1);
  return l1_aux;
}

int main(){
  Lista* l1 = cria_lista();
  insere_lista(l1,8);
  insere_lista(l1,16);
  insere_lista(l1,156);
  insere_lista(l1,2);
  insere_lista(l1,89);
  insere_lista(l1,123);
  puts("\nLista Original l1: ");
  imprime_lista(l1);

  l1 = inverte(l1);

  puts("\n-> Após Inverter Lista \n\nLista l1: ");
  imprime_lista(l1);

  return 0;
}
