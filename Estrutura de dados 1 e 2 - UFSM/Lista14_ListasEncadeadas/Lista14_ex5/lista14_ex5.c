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

int comprimento(Lista* l){
  ListaNo* p; int cont = 0;
  for(ListaNo* p=l->prim; p!=NULL; p=p->prox){
    cont++;
  }
  return cont;
}

int maiores(Lista* l,int x){
  ListaNo* p; int cont = 0;
  for(ListaNo* p=l->prim; p!=NULL; p=p->prox){
    if(p->info > x)
      cont++;
  }
  return cont;
}

int ultimo(Lista*l){
  ListaNo* p; int cont = 0;
  for(ListaNo* p=l->prim; p!=NULL; p=p->prox){
      cont++;
  }
  int cont2 = 0;
  for(ListaNo* p=l->prim; p!=NULL; p=p->prox){
    cont2++;
    if(cont2 == cont)
      return p->info;
  }
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

int main(){
  Lista* l_main = cria_lista();
  insere_lista(l_main,8);
  insere_lista(l_main,16);
  insere_lista(l_main,89);
  insere_lista(l_main,123);
  puts("\nLista Original:");
  imprime_lista(l_main);

  retira_n(l_main,16);
  puts("\nelemento: 16");
  puts("Lista(após retirar elemento):");
  imprime_lista(l_main);

  return 0;
}
