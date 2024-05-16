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

Lista* separa(Lista* l1,int x){
  ListaNo* p = l1->prim;
  int cont1 = 0; int cont_total = 0;
  while(p!=NULL && p->info!=x){
    cont1++; p = p->prox;
  }
  Lista* l2 = (Lista*)malloc(sizeof(Lista));
  Lista* l1_aux = (Lista*)malloc(sizeof(Lista));
  int cont2 = 0;
  for(ListaNo* p=l1->prim; p!=NULL; p=p->prox){
    cont2++;
    if(cont2 > cont1+1){
      insere_lista(l2,p->info);
    }
    else
      insere_lista(l1_aux,p->info);
  }
  free(l1);
  for(ListaNo* p=l1_aux->prim; p!=NULL; p=p->prox){
    cont2++;
    l1->prim = l1_aux->prim;
  }
  return l2;
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

  Lista* l2 = separa(l1,156);

  puts("\n-> Após Separar Listas no elemento 156 \n\nLista l1: ");
  imprime_lista(l1);
  puts("\nLista l2: ");
  imprime_lista(l2);

  return 0;
}
