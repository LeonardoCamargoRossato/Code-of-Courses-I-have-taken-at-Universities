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

void libera_lista(Lista* l){
  ListaNo* p = l->prim;
  while(p != NULL){
    ListaNo* t = p->prox;
    free(p);
    p = t;
  }
  free(l);
}

Lista* concatena(Lista* l1,Lista* l2){
  ListaNo* p;
  for(ListaNo* p=l2->prim; p!=NULL; p=p->prox){
    insere_lista(l1,p->info);
  }
  libera_lista(l2);
  return l1;
}

int main(){
  Lista* l_main1 = cria_lista();
  insere_lista(l_main1,8);
  insere_lista(l_main1,16);
  insere_lista(l_main1,89);
  insere_lista(l_main1,123);
  puts("\nLista1");
  imprime_lista(l_main1);

  Lista* l_main2 = cria_lista();
  insere_lista(l_main2,1);
  insere_lista(l_main2,2);
  insere_lista(l_main2,3);
  insere_lista(l_main2,5);
  insere_lista(l_main2,7);
  insere_lista(l_main2,11);
  puts("\nLista2");
  imprime_lista(l_main2);

  Lista* lst = concatena(l_main1,l_main2);
  puts("\nLista Concatenada: lst");
  imprime_lista(lst);

  return 0;
}
