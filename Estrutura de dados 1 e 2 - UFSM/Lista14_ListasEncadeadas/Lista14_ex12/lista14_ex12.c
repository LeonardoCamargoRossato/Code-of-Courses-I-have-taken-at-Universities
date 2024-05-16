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

void para_circular(ListaDupla* l1){
  ListaNoDuplo* p; int cont1 = 0;
  for(ListaNoDuplo* p=l1->prim; p!=NULL; p=p->prox){
      cont1++;
  }
  int cont2 = 0;
  for(ListaNoDuplo* p=l1->prim; p!=NULL; p=p->prox){
    cont2++;
    if(cont2 == cont1){
      p->prox = l1->prim; break;
    }
  }

  ListaNoDuplo* p1; int cont3 = 0;
  for(ListaNoDuplo* p1=l1->ult; p1!=NULL; p1=p1->ant){
      cont3++;
  }
  int cont4 = 0;
  for(ListaNoDuplo* p1=l1->ult; p1!=NULL; p1=p1->ant){
    cont4++;
    if(cont4 == cont3){
     p1->ant = l1->ult; break;
    }
  }
}

void imprime_lista(ListaDupla* l){
  ListaNoDuplo* p;
  printf("{ ");
  for(ListaNoDuplo* p=l->prim; p!=NULL; p=p->prox){
    printf("%d ", p->info);
  }
  printf("}\n");
}

void imprime_circular(ListaDupla* l1){
  ListaNoDuplo* p = l1->prim;
  printf("{ ");
  if(p!=NULL) do {
    printf("%d ",p->info);
    p=p->prox;
  } while(p!=l1->prim);
  printf("} \n");
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

  para_circular(l1);
  puts("\nLista Depois do para_circular: ");
  imprime_circular(l1);

  return 0;
}
