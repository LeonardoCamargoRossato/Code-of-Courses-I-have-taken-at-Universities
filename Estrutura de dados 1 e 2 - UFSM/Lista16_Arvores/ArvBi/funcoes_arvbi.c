#include<stdio.h>
#include<stdlib.h>
#include "arvbi.h"

struct arvbino{
  int info;
  ArvBiNo* esq;
  ArvBiNo* dir;
};

struct arvbi{
  ArvBiNo* raiz;
};

ArvBiNo* arvbi_criano(int x,ArvBiNo* esq,ArvBiNo* dir){
  ArvBiNo* p = (ArvBiNo*)malloc(sizeof(ArvBiNo));
  p->info = x;
  p->esq = esq;
  p->dir = dir;
  return p;
}

ArvBi* arvbi_cria(ArvBiNo* r){
  ArvBi* p = (ArvBi*)malloc(sizeof(ArvBi));
  p->raiz = r;
  return p;
}

//CALLBACK arvbi_imprime
static void imprime(ArvBiNo* r){
  printf("<");
  if(r!=NULL){
    printf("%d ",r->info);
    imprime(r->esq);
    imprime(r->dir);
  }
  printf("> ");
}

void arvbi_imprime(ArvBi* a){
  imprime(a->raiz);
}

//CALLBACK arvbi_libera
static void libera(ArvBiNo* r){
  if(r!=NULL){
    libera(r->esq);
    libera(r->dir);
    free(r);
  }
}
void arvbi_libera(ArvBi* a){
  libera(a->raiz);
  free(a);
}

//CALLBACK busca
static ArvBiNo* busca(ArvBiNo* r,int x){
  if(r==NULL)
     return NULL;
  else if(x==r->info)
    return r;
  else{
    ArvBiNo* p = busca(r->esq,x);
    if(p!=NULL)
      return p;
    else
      return busca(r->dir,x);
  }
}

ArvBiNo* arvbi_busca(ArvBi* a,int x){
  return(busca(a->raiz,x));
}

//CALLBACK arvbi_pertence
static int pertence(ArvBiNo* r,int x){
  if(r==NULL)
    return 0;
  else{
    return x==r->info || pertence(r->esq,x) || pertence(r->dir,x);
  }
}
int arvbi_pertence(ArvBi* a, int x){
  int p = pertence(a->raiz,x);
  return p;
}

//CALLBACK PARES
static int cont_par = 0;
static int busca_par(ArvBiNo* r){
  if(r!=NULL){
    //printf("\n|%d ; r->info: %d ",cont_par,r->info);
    busca_par(r->esq);
    busca_par(r->dir);
    if(r->info%2 == 0){
      cont_par++; //printf("\ncont_par: %d",cont_par);
    }
  }
  return cont_par;
}
int pares(ArvBi* a){
  int n = busca_par(a->raiz);
  cont_par = 0;
  return n;
}

//CALLBACK FOLHAS
static int cont_folhas = 0;
static int busca_folhas(ArvBiNo* r){
  if(r!=NULL){
    //printf("\n|%d ; r->info: %d ",cont_folhas,r->info);
    busca_folhas(r->esq);
    busca_folhas(r->dir);
    if(r->esq == NULL && r->dir == NULL){
      cont_folhas++; //printf("\ncont_folhas: %d",cont_folhas);
    }
  }
  return cont_folhas;
}
int folhas(ArvBi* a){
  int n = busca_folhas(a->raiz);
  cont_folhas = 0;
  return n;
}

//CALLBACK FOLHAS
static int cont_umfio = 0;
static int busca_umfilho(ArvBiNo* r){
  if(r!=NULL){
    busca_umfilho(r->esq);
    busca_umfilho(r->dir);
    if(r->esq != NULL && r->dir == NULL){
      //printf("\n|%d ; r->info: %d ",cont_umfio,r->info);
      ArvBiNo* e1 = r->esq; //FILHO ESQUERDO
      if(e1->esq == NULL && e1->dir == NULL) //IF DA FOLHA
        cont_umfio++; //printf("\ncont_umfio: %d",cont_umfio);
    }
    else if(r->esq == NULL && r->dir != NULL){
      ArvBiNo* d1 = r->dir; //FILHO DIREITO
      if(d1->esq == NULL && d1->dir == NULL)
        cont_umfio++; //printf("\ncont_umfio: %d",cont_umfio);}
    }
  }
  return cont_umfio;
}
int um_filho(ArvBi* a){
    int n = busca_umfilho(a->raiz);
    cont_umfio = 0;
    return n;
}

static int ig = 0;
static int verifica_igualdade(ArvBiNo* a,ArvBiNo* b){ // SE HOUVER ALGO DIFERENTE, IG++ e função fica != 0
  if(a!=NULL && b!=NULL){
    verifica_igualdade(a->esq,b->esq);
    verifica_igualdade(a->dir,b->dir);
    //printf("\na->info: %d | b->info: %d ",a->info,b->info);
    if(a->info != b->info){
      //printf("\n#### a->info: %d | b->info: %d",a->info,b->info);
      ig++; //printf("\nig: %d",ig);
    }
    else if(ig!=0) //SE IG != 0, a função retorna 1 e logo, arvores são diferentes
      return 1;
    else
      return 0;
  }
}
int igual(ArvBi* a,ArvBi* b){
    int n = verifica_igualdade(a->raiz,b->raiz) > 0 ? 0 : 1;
    ig = 0;
    return(n);  //SÃO IGUAIS: 1 == SIM; 0 == NÃO;
}

ArvBi* copia(ArvBi* a){
  ArvBi* copy = (ArvBi*)malloc(sizeof(ArvBi));
  copy = a;
  return copy;
}

//CALLBACK nfolhas_maiores
static int busca_nfolhas_maiores(ArvBiNo* r,int x){
  if(r!=NULL){
    //printf("\n|%d ; r->info: %d ",cont_folhas,r->info);
    busca_nfolhas_maiores(r->esq,x);
    busca_nfolhas_maiores(r->dir,x);
    if(r->esq == NULL && r->dir == NULL){
      if(r->info > x)
        cont_folhas++; //printf("\ncont_folhas: %d",cont_folhas);
    }
  }
  return cont_folhas;
}
int nfolhas_maiores(ArvBi*a,int x){
  int n = busca_nfolhas_maiores(a->raiz,x);
  cont_folhas = 0;
  return n;
}

//CALLBACK busca_soma_xy
static int busca_soma_xy(ArvBiNo* r,int x,int y){
  if(r!=NULL){
    busca_soma_xy(r->esq,x,y);
    busca_soma_xy(r->dir,x,y);
    if(r->info < x && r->info > y){
      //printf("\n|%d ; r->info: %d ",cont_folhas,r->info);
      cont_folhas += r->info; //printf("\ncont_folhas: %d",cont_folhas);
    }
  }
  return cont_folhas;
}
int soma_xy(ArvBi* a, int x,int y){
  int n = busca_soma_xy(a->raiz,x,y);
  cont_folhas = 0;
  return n;
}

static int kkk= 0; static int grau_arv= -1;
static ArvBiNo* n; //VARÍAVEL DO TERNÁRIO PRA DIZER QUAL DOS ARGUMENTOS É MAIOR
//CALLBACK conta_grau  ##CONTA O GRAU DA ÁRVORE
static int conta_grau(ArvBiNo* r){
  if(r!=NULL){
    conta_grau(n = r->esq > r->dir ? r->esq : r->dir);
    if(r->esq !=NULL || r->dir == NULL)
      grau_arv++; printf("\ngrau_arv %d | r->info = %d",grau_arv,r->info);
  }
  return grau_arv;
}
//CALLBACK busca_nivel
// static int busca_nivel(ArvBiNo* r,int x,int grau){
//   if(r!=NULL){
//     busca_nivel(r->esq,x,grau);
//     kkk++;
//     printf("\n|## %d ; r->info: %d ",kkk,r->info);
//     busca_nivel(r->dir,x,grau);
//     if(r->info == x){
//       cont = kkk; printf("\ncont %d", cont);
//     }
//     //cont_folhas += r->info; //printf("\ncont_folhas: %d",cont_folhas);
//   }
//   return cont;
// }

// static int conta = -1;
// //CALLBACK busca_nivell
// static int pertence2(ArvBiNo* r,int x){
//   if(r==NULL)
//     return -1;
//   else if(x!=r->info)
//     return(1|| pertence2(r->esq,x) || pertence2(r->dir,x));
//     //conta++; printf("\n##conta: %d | r->info: %d",conta,r->info);
//   }
// }
// static int busca_nivell(ArvBiNo* r,int x,int grau){
//     int no0 = pertence(r->esq);
//     if(no0 == 1){
//       int e0 = pertence(r->esq);
//       if(e0 == 1){
//           int e1 = pertence(r->esq);
//           if(e1 == 1){
//               return
//           }
//       }
//       else{
//           int e0d = pertence(r->dir);
//       }
//
//
//     }
//     else{
//       int d0 = pertence(r->esq);
//
//     }
// }

// static int busca_nivell(ArvBiNo* r,int x,int grau){
//     pertence2(r,x);
//     return conta;
// }
// static int busca_nivell(ArvBiNo* r,int x,int grau){
//     return(1 == pertence2(r->esq,x) ? busca_nivel(r->esq,x,grau) : busca_nivel(r->dir,x,grau));
// }
static int cont = -1;
static int ta_na_esq(ArvBiNo* r,int x){
  while(1){
    r=r->esq;
    if(x==r->info)
      return 1;
  }
}
static int ta_na_dir(ArvBiNo* r,int x){
  while(x!=r->info){
    r=r->dir;
  }
  return (x == r->info ? 1 : 0);
}

static int h;
static int busca_niveu(ArvBiNo* r,int x){
  if(r==NULL) return cont;
  else if(x != r->info){
    cont++;
    printf("\ncont: %d | r->info: %d",cont,r->info);
    h = pertence(r,x);
    if(h == 1 )
      busca_niveu(r->esq,x);
    else //if (h == 0)
      busca_niveu(r->dir,x);
  }
  return cont;
}
int nivel(ArvBi* a, int x){
    //int grau = conta_grau(a->raiz); printf("\ngrau %d",grau);
    int n = busca_niveu(a->raiz,x);
    printf("\n n: %d\n",n);
    grau_arv = 0; cont_folhas = 0; cont = 0;
    return n;
}
