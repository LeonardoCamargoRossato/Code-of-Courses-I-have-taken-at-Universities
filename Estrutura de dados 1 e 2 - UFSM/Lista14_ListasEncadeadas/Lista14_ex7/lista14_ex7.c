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
//FUNÇÃO CALLBACK MERGE
int compara(Lista* l1,Lista*l2){
  ListaNo* p1 = l1->prim;
  ListaNo* p2 = l2->prim;
  int cont1 = 0; int cont2 = 0;
  while(p1!=NULL){
    cont1++; p1=p1->prox;
  }
  while(p2!=NULL){
    cont2++; p2=p2->prox;
  }
  if(cont1 >=cont2)
    return 1;
  else
    return -1;
}
Lista* merge(Lista* l1,Lista* l2){
  Lista* l3_aux = (Lista*)malloc(sizeof(Lista));
  Lista* l3 = (Lista*)malloc(sizeof(Lista));
  ListaNo* p1 = l1->prim;
  ListaNo* p2 = l2->prim;
  int cont = 0;
  while(p1!=NULL && p2!=NULL){
    insere_lista(l3_aux,p1->info);
    p1=p1->prox;
    insere_lista(l3_aux,p2->info);
    p2=p2->prox;
    cont++;
  }
  int p = compara(l1,l2);
  int cont2 = 0;
  if(p==1){
    while(p1!=NULL){
      cont2++;
      if(cont2 > cont){
        insere_lista(l3_aux,p1->info);
        p1=p1->prox;
      }
    }
  }
  else if(p==-1){
    while(p2!=NULL){
      cont2++;
      if(cont2 > cont){
        insere_lista(l3_aux,p2->info);
        p2=p2->prox;
      }
    }
  }
  ListaNo* p3 = l3_aux->prim;
  while(p3!=NULL){
    insere_lista(l3,p3->info);
    p3 = p3->prox;
  }
  libera_lista(l1); libera_lista(l2);
  return l3;
}

int main(){
  Lista* l1 = cria_lista();
  insere_lista(l1,8);
  insere_lista(l1,16);
  insere_lista(l1,89);
  insere_lista(l1,123);
  puts("\nLista1");
  imprime_lista(l1);

  Lista* l2 = cria_lista();
  insere_lista(l2,1);
  insere_lista(l2,2);
  insere_lista(l2,3);
  insere_lista(l2,5);
  insere_lista(l2,7);
  insere_lista(l2,11);
  puts("\nLista2");
  imprime_lista(l2);

  Lista* lst = merge(l1,l2);
  puts("\nLista Misturada: lst");
  imprime_lista(lst);

  return 0;
}
