#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "aluno.h"

static int n = 0;
static int nmax = 4;

Aluno* aluno_cria(void){
  //int n = 0;
  //int nmax = 81;
  Aluno* vd_aluno = (Aluno*)malloc(sizeof(Aluno));
  vd_aluno->nome == (char*)malloc(nmax*sizeof(char));
  return vd_aluno;
}

//FUNÇAO CALLBACK
static void realoca(Aluno* vd_aluno){
    nmax *= 2;
    vd_aluno->nome == (char*)realloc(vd_aluno->nome, nmax*sizeof(float)); //REALLOC
}

void aluno_insere_float(Aluno* vd_aluno,float x){
  if (n >= nmax)
    realoca(vd_aluno);
  vd_aluno->nome[n++] = x;
}

void aluno_insere_nome(Aluno* vd_aluno,char c){
  if (n == nmax)
    realoca(vd_aluno);
  vd_aluno->nome[n] = x;
  n++;
}

int aluno_tam(Aluno* vd_aluno){
  return n;
}

char aluno_acessa_nome(Aluno* vd_aluno,int i){
  assert(i>=0 && i<n);
  return vd_aluno->nome[i];
}

float aluno_acessa_p1(Aluno* vd_aluno, int i){
  assert(i>=0 && i<n);
  return vd_aluno->p1;
}

float aluno_acessa_p2(Aluno* vd_aluno, int i){
  assert(i>=0 && i<n);
  return vd_aluno->p2;
}

float aluno_acessa_p3(Aluno* vd_aluno, int i){
  assert(i>=0 && i<n);
  return vd_aluno->p3;
}

void printa_aluno(Aluno* vd_aluno, int i){
  assert(i>=0 && i<n);
  printf("Nome: %s | P1 = %.1f P2 = %.1f P3 = %.1f\n",
    vd_aluno[i].nome, vd_aluno[i].p1,vd_aluno[i].p2,vd_aluno[i].p3);
}

void printa_turma(Aluno* vd_aluno){
  for(int i = 0; i<n; i++){
    printf("Nome: %s | P1 = %.1f P2 = %.1f P3 = %.1f\n",
      vd_aluno[i].nome, vd_aluno[i].p1,vd_aluno[i].p2,vd_aluno[i].p3);
  }
}

void aluno_libera(Aluno* vd_aluno){
  free(vd_aluno->nome);
  free(vd_aluno);
}
