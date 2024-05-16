#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
#include "arvn.h"


// struct arvnno{
//   int info;
//   ArvnNo* prim;
//   ArvnNo* prox;
// };
//
// struct arvn{
//   ArvnNo* raiz;
// };

ArvnNo* arvn_criano(int x){
  ArvnNo* a = (ArvnNo*)malloc(sizeof(ArvnNo));
  a->info = x;
  a->prim = NULL;
  a->prox = NULL;
  return a;
}

void arvn_insere(ArvnNo* a, ArvnNo* sa){
  sa->prox = a->prim;
  a->prim = sa;
}

Arvn* arvn_cria(ArvnNo* r){
  Arvn* a = (Arvn*)malloc(sizeof(Arvn));
  a->raiz = r;
  return a;
}

//CALLBACK arvn_imprime
static void imprime(ArvnNo* r){
  ArvnNo* p;
  printf(" <%d",r->info);
  for(p=r->prim; p!=NULL; p=p->prox)
    imprime(p);  // imprime cada sub-arvore filha
  printf(">");
}

void arvn_imprime(Arvn* a){
  if(a->raiz != NULL)
    imprime(a->raiz);
  else
    printf(" 0");
}

//CALLBACK arvn_busca
static ArvnNo* busca(ArvnNo* r,int x){
  ArvnNo* p;
  if(r->info == x)
    return r;
  else{
    for(p=r->prim;p!=NULL;p=p->prox){
      ArvnNo* q = busca(p,x);
      if(q!=NULL)
        return q;
    }
    return NULL;
  }
}

ArvnNo* arvn_busca(Arvn* a,int x){
  if(a->raiz == NULL){
    return NULL;}
  else{
    return busca(a->raiz,x);
  }
}

//CALLBACK arvn_libera
static void libera(ArvnNo* r){
  ArvnNo* p = r->prim;
  while(p!=NULL){
    ArvnNo* t = p->prox;
    libera(p);
    p = t;
  }
  free(r);
}

void arvn_libera(Arvn* a){
  if(a->raiz != NULL)
    libera(a->raiz);
  free(a);
}

//CALLBACK PARES2 (NÃO-GENERALIZADA)
//(APENAS PARA ARVORES ORDENADAS EM ELEMENTOS CONSECUTIVOS NÃO-NULOS)
static int busca_par2(Arvn* a){
  int cont = 0; int i = 0;
  ArvnNo* par_no;
  Arvn* par_arv = arvn_cria(par_no);
  while(1){
    i++; printf("\ni: %d  |  ",i);
    par_no = arvn_busca(a,i);
    par_arv->raiz = par_no;
    if(par_arv->raiz!=NULL){
      printf("par_no->info: %d\n",par_no->info );
      arvn_imprime(par_arv);
      if(par_no->info%2 == 0)
        cont++;
    }
    else
      break;
  }
  return cont;
}
int pares2(Arvn* a){
  int n = busca_par2(a);
  return n;
}

static int fora = 0; //CONTADOR EXTERNO GLOBAL da FUNÇÃO PAR

//CALLBACK PARES (GENERALIZADA)
static int busca_par(ArvnNo* a){
  ArvnNo* p;
  for(p=a->prim; p!=NULL;p=p->prox){
    if(p->info%2==0){
      fora++;
    }
    busca_par(p);
  }
  return fora;
}

int pares(Arvn* a){
  int n = busca_par(a->raiz);
  return n;
}

//CALLBACK FOLHAS
static int cont_folha = 0; //VARIÁVEL GLOBAL
static int busca_folhas(ArvnNo* a){
  ArvnNo* p;
  for(p=a->prim;p!=NULL;p=p->prox){
    if(p->prim == NULL){
      cont_folha++;
      //printf("\n%d|p->info: %d",cont_folha,p->info);
    }
    busca_folhas(p);
  }
  return cont_folha;
}

int folhas(Arvn* a){
  int n = busca_folhas(a->raiz);
  return n;
}

//CALLBACK UM_FILHO
static int cont_um_filho = 0; //VARIAVEL GLOBAL
static int busca_um_filho(ArvnNo* a){
  ArvnNo* p;
  for(p=a->prim;p!=NULL;p=p->prox){
    if(p->prim != NULL && p->prox != NULL){
      cont_um_filho++;
      printf("\n%d|p->info: %d",cont_um_filho,p->info);
    }
    busca_um_filho(p);
  }
  return cont_um_filho;
}
int um_filho(Arvn* a){
  int n = busca_um_filho(a->raiz);
  return n;
}
