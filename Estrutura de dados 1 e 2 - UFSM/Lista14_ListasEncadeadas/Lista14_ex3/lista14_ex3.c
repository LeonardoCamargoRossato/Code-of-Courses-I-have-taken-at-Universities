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
  for(ListaNo* p=l->prim; p!=NULL; p=p->prox){
    printf("info = %d\n", p->info);
  }
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

int main(){
  Lista* l_main = cria_lista();
  insere_lista(l_main,8);
  insere_lista(l_main,16);
  insere_lista(l_main,89);
  insere_lista(l_main,123);
  imprime_lista(l_main);

  int ult = ultimo(l_main);
  printf("\nÚltimo número da lista: %d \n",ult);
  return 0;
}
