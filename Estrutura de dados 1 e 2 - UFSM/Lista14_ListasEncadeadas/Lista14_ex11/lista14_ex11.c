#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listadupla ListaDupla;
typedef struct listanoduplo ListaNoDuplo;

struct listadupla{
  ListaNoDuplo* prim;
  ListaNoDuplo* ult;
};

struct listanoduplo{
  int info;
  ListaNoDuplo* ant;
  ListaNoDuplo* prox;
};

ListaDupla* cria_listadupla(void){
  ListaDupla* l = (ListaDupla*)malloc(sizeof(ListaDupla));
  l->prim = NULL;
  l->ult = NULL;
  return l;
}

void insere_inicio(ListaDupla* l, int info){
  ListaNoDuplo* novo = (ListaNoDuplo*)malloc(sizeof(ListaNoDuplo));
  novo->info = info;
  novo->prox = l->prim;
  novo->ant = NULL;

  if(l->prim != NULL){
    l->prim->ant = novo;
  }
  else
    l->ult = novo;
  l->prim = novo;
}

void insere_final(ListaDupla* l, int info){
  ListaNoDuplo* novo = (ListaNoDuplo*)malloc(sizeof(ListaNoDuplo));
  novo->info = info;
  novo->ant = l->ult;
  novo->prox = NULL;

  if(l->ult != NULL){
    l->ult->prox = novo;
  }
  else
    l->prim = novo;
  l->ult = novo;
}

void imprime_lista(ListaDupla* l){
  ListaNoDuplo* p;
  printf("{ ");
  for(ListaNoDuplo* p=l->prim; p!=l->ult; p=p->prox){
    printf("%d ", p->info);
  }
  printf("}\n");
}

void retira_inicio(ListaDupla* l){
  ListaNoDuplo* p = l->prim;
  if(p == NULL){
    return;
  }
  else
    l->prim = p->prox;
  free(p);
}
void retira_final(ListaDupla* l){
  ListaNoDuplo* p = l->ult;
  l->ult = p->ant;
  free(p);
}

int main(){
  ListaDupla* l1 = cria_listadupla();
  insere_final(l1,8);
  insere_inicio(l1,16);
  insere_inicio(l1,156);
  insere_inicio(l1,2);
  insere_inicio(l1,89);
  insere_final(l1,123);
  puts("\nLista Original l1: ");
  imprime_lista(l1);

  retira_inicio(l1);
  puts("\nLista Depois de Remover primeiro: ");
  imprime_lista(l1);

  retira_final(l1);
  puts("\nLista Depois de Remover ultimo: ");
  imprime_lista(l1);

  return 0;
}
