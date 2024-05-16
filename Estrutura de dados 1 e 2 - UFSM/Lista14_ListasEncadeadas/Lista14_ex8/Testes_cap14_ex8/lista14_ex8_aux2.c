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

//CALLBACK lst_retira_nos
static ListaNo* retira_nos(ListaNo* p,int x){
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
void lst_retira_nos(Lista*l,int x){
  l->prim = retira_nos(l->prim,x);
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

void inverte(Lista* l1){
  ListaNo* p = l1->prim;

  Lista* l1_aux = cria_lista();
  while(p!=NULL){
    insere_lista(l1_aux,p->info);
    p=p->prox;
  }
  ListaNo* p1;
  for(p1=l1->prim;p1!=NULL;p1=p1->prox){
    ListaNo* p1 = l1->prim;
    lst_retira_nos(l1,p1->info);
    printf("p1->info = %d \n",p1->info);
  }
  // retira_n(l1,123);
  // retira_n(l1,89);
  // retira_n(l1,2);
  // retira_n(l1,156);
  // retira_n(l1,16);
  // retira_n(l1,8);
  imprime_lista(l1_aux);

  ListaNo* p2 = l1_aux->prim;
  while(p2!=NULL){
    insere_lista(l1,p2->info);
    p2=p2->prox;
  }
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

  inverte(l1);

  puts("\n-> Após Inverter Lista \n\nLista l1: ");
  imprime_lista(l1);

  return 0;
}
