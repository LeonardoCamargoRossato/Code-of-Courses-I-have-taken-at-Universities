#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h"
#include "pilha.h"

struct calc{
  char f[21]; //pra info que vão aparacer na tela;
  Pilha* p;
};

Calc* cria_calc(char* formato){
  Calc* c = (Calc*)malloc(sizeof(Calc));
  strcpy(c->f,formato);
  c->p = pilha_cria();
  return c;
}

void operando_calc(Calc* c, float v){
  pilha_push(c->p,v);
  printf("Operando -->  ");
  printf(c->f,v);
}

void operador_calc(Calc* c, char op){
  //tira da pilha os operandos
  float v2 = pilha_vazia(c->p) ? 0.0f : pilha_pop(c->p);
  float v1 = pilha_vazia(c->p) ? 0.0f : pilha_pop(c->p);

  //faz operação
  float v;
  switch(op){
    case '+': v = v1+v2; break;
    case '-': v = v1-v2; break;
    case '*': v = v1*v2; break;
    case '/': v = v1/v2; break;
  }
  pilha_push(c->p,v); //bota no topo da pilha o resultado
  printf("--> ");
  printf(c->f,v); //printa topo da pilha
}

void libera_calc(Calc* c){
  pilha_libera(c->p);
  free(c);
}
