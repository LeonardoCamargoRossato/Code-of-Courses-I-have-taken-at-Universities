#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista Lista;
typedef struct listano ListaNo;

struct lista{
  ListaNo* prim;
};

struct listano{
  char* info;
  ListaNo* prox;
};

Lista* cria_lista(void){
  Lista* l = (Lista*)malloc(sizeof(Lista));
  l->prim = NULL;
  return l;
}

void insere_lista(Lista* l, char* info){
  ListaNo* novo = (ListaNo*)malloc(sizeof(ListaNo));
  novo->info = info;
  novo->prox = l->prim;
  l->prim = novo;
}

void imprime_lista(Lista* l){
  ListaNo* p;
  printf("{ ");
  for(ListaNo* p=l->prim; p!=NULL; p=p->prox){
    printf("%s ", p->info);
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

Lista* copia(Lista* l1){
  ListaNo* p = l1->prim;

  Lista* l1_aux = cria_lista();
  while(p!=NULL){
    insere_lista(l1_aux,p->info);
    p=p->prox;
  }
  Lista* l2_aux = cria_lista();
  ListaNo* p2 = l1_aux->prim;
  l1->prim = p2;
  while(p2!=NULL){
    insere_lista(l2_aux,p2->info);
    p2=p2->prox;
  }
  libera_lista(l1_aux);
  return l2_aux;
}

int main(){
  Lista* l1 = cria_lista();

  char* a = "Mariana Martaparado";
  char* b = "Débora Debutantis";
  char* c = "Jacinto Calafrios";
  insere_lista(l1,a);
  insere_lista(l1,b);
  insere_lista(l1,c);
  insere_lista(l1,"Maximiliano SempreBom");

  puts("\nLista Original l1: ");
  imprime_lista(l1);

  Lista* l2 = cria_lista();
  l2 = copia(l1);

  puts("\nLista Copiada l2: ");
  imprime_lista(l2);

  return 0;
}
