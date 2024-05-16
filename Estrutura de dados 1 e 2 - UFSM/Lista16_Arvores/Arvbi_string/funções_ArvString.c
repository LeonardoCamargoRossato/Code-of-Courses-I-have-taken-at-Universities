#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvbi_string.h"

struct aluno{
  char nome[81];
  float p1,p2,p3;
};

struct arvno{
  Aluno info;
  ArvNo* esq;
  ArvNo* dir;
};

struct arv{
  ArvNo* raiz;
};

Arv* cria(void){
  Arv* b = (Arv*)malloc(sizeof(Arv));
  b->raiz = NULL;
  return b;
}

//CALLBACK insere_alfabet
static int compara(ArvNo* r,Aluno* alu){
  char c1, c2;
  while((sscanf(r->info.nome," %c",&c1)) && (sscanf(alu->nome," %c",&c2))){
    if(c1 > c2)
      return -1; //caso  alu->nome > r->info_nome
    else if (c1 < c2)
      return 1;  //caso  alu->nome < r->info_nome
    else
      return 0;  //caso  alu->nome == r->info_nome
  }
}
//VAI FAZER A INSERÇÃO EM ORDEM ALFABÉTICA
//CALLBACK insere
static ArvNo* insere_alfabet(ArvNo* r,Aluno* alu){
  if(r==NULL){
    r = (ArvNo*)malloc(sizeof(ArvNo));
    strcpy(r->info.nome,alu->nome);
    r->info.p1 = alu->p1;
    r->info.p2 = alu->p2;
    r->info.p3 = alu->p3;
    r->esq = r->dir = NULL;
  }
  else if(compara(r,alu) < 0){    //Se { alu->nome < r->info->nome } := -1
    r->esq = insere_alfabet(r->esq,alu);
  }
  else // compara(r,alu) > 0     //Se { alu->nome >= r->info->nome } := 1 ou 0
    r->dir = insere_alfabet(r->dir,alu);
  return r;
}
void insere(Arv* a,char* nome,float p1,float p2,float p3){
  Aluno* alu = (Aluno*)malloc(sizeof(Aluno));
  strcpy(alu->nome,nome);
  alu->p1 = p1; alu->p2 = p2; alu->p3 = p3;
  a->raiz = insere_alfabet(a->raiz,alu);
}

//CALLBACK imprime
static void imprime_sim(ArvNo* r){
  if(r!=NULL){
    imprime_sim(r->esq);
    printf("\nNome: %s |p1: %.1f |p2: %.1f |p3: %.1f",
      r->info.nome,r->info.p1,r->info.p2,r->info.p3);
    imprime_sim(r->dir);
  }
}
void imprime_dados(Arv* a){
    imprime_sim(a->raiz);
}

//CALLBACK imprime
static void imprime_sim2(ArvNo* r){
  printf(" <");
  if(r!=NULL){
    printf("%c", r->info.nome[0]);
    imprime_sim2(r->esq);
    imprime_sim2(r->dir);
  }
  printf(">");
}
void imprime_arv(Arv* a){
    imprime_sim2(a->raiz);
}

//CALLBACK retira_alfabetic
static int compara2(ArvNo* r,char* alu){
  char c1, c2;
  while((sscanf(r->info.nome," %c",&c1)) && (sscanf(alu," %c",&c2))){
    if(c1 > c2)
      return -1; //caso  v < r->info_nome
    else if (c1 < c2)
      return 1;  //caso  v > r->info_nome
    else
      return 0;  //caso  v == r->info_nome
  }
}
static ArvNo* retira_alfabetic(ArvNo* r, char* v){
  if(r==NULL)
    return NULL;
  else if(compara2(r,v) < 0){
    printf("\n r->esq.info: %s",r->info.nome);
    r->esq = retira_alfabetic(r->esq,v);}
  else if(compara2(r,v) > 0){
    printf("\n r->dir.info: %s",r->info.nome);
    r->dir = retira_alfabetic(r->dir,v);}
  else{ //ACHOU O ELEMENTO
    printf("\n # r->info: %s ",r->info.nome);
    if(r->esq == NULL && r->dir == NULL){ //É UM NÓ FOLHA
      free(r);
      r = NULL;
    }
    else if(r->esq == NULL){ //SÓ TEM FILHO À DIREITA
      ArvNo* t = r;
      //printf("\n r->info: %s \n",r->info.nome);
      //imprime_sim2(r->esq);
      r = r->dir;
      free(t);
      //printf("\n r->info: %s ",r->info.nome);
    }
    else if(r->dir == NULL){ //SÓ TEM FILHO À ESQUERDA
      ArvNo* t = r;
      r = r->esq;
      free(t);
    }
    else{
     ArvNo* f = (ArvNo*)malloc(sizeof(ArvNo));
     f = r->esq;
     while(f->dir != NULL){
      f = f->dir;
     }
     r->info = f->info;
     strcpy(f->info.nome,v);
     r->esq = retira_alfabetic(r->esq,v);
    }
  }
  return r;
}
void retira(Arv* a,char* v){
  a->raiz = retira_alfabetic(a->raiz,v);
}

void libera(Arv* a){
  if(a->raiz != NULL){
    free(a); a = NULL;
  }
}
