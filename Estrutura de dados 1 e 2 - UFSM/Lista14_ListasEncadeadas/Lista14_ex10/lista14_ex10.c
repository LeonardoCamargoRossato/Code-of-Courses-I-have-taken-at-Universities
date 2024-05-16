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

void para_circular(Lista* l1){
  ListaNo* p; int cont = 0;
  for(ListaNo* p=l1->prim; p!=NULL; p=p->prox){
      cont++;
  }
  int cont2 = 0;
  for(ListaNo* p=l1->prim; p!=NULL; p=p->prox){
    cont2++;
    if(cont2 == cont){
      p->prox = l1->prim; break;
    }
  }
}

void imprime_circular(Lista* l1){
  ListaNo* p = l1->prim;
  printf("{ ");
  if(p!=NULL) do {
    printf("%d ",p->info);
    p=p->prox;
  } while(p!=l1->prim);
  printf("} \n");
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

  para_circular(l1);

  puts("\nLista Circular l1: ");
  imprime_circular(l1);

  return 0;
}
