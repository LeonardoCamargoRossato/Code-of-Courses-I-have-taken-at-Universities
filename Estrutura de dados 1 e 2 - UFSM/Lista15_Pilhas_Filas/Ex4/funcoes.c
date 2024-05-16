#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h"
#include "pilha.h"
#include "num_complexo.h"

struct calc{
  // char f[21]; //pra info que vão aparacer na tela;
  Pilha* p;
};

Calc* cria_calc(void){
  Calc* c = (Calc*)malloc(sizeof(Calc));
  // strcpy(c->f,formato);
  c->p = pilha_cria();
  return c;
}

void operando_calc(Calc* c, float v){
  pilha_push(c->p,v);
  printf("Operando -->  %.2f\n",v);
}

void operador_calc(Calc* c, char op){
  //tira da pilha os operandos complexos
  float v4 = pilha_vazia(c->p) ? 0.0f : pilha_pop(c->p);
  float v3 = pilha_vazia(c->p) ? 0.0f : pilha_pop(c->p);
  Num_Complexo* u2 = num_complexo_cria(v3,v4);
  float v2 = pilha_vazia(c->p) ? 0.0f : pilha_pop(c->p);
  float v1 = pilha_vazia(c->p) ? 0.0f : pilha_pop(c->p);
  Num_Complexo* u1 = num_complexo_cria(v1,v2);

  float v_aux1, v_aux2;
  Num_Complexo* v = num_complexo_cria(v_aux1,v_aux2);
  //= (Num_Complexo*)malloc(sizeof(Num_Complexo));
  //faz operação
  switch(op){
    case '+': v = num_complexo_soma(u1,u2); break;
    case '-': v = num_complexo_subtrai(u1,u2); break;
    case '*': v = num_complexo_multiplica(u1,u2); break;
    case '/': v = num_complexo_divide(u1,u2); break;
  }
  printf("u1%cu2 = v:(%.2f,%.2f)\n",op,v->a,v->b); //printa topo da pilha
  pilha_push(c->p,v->a); //bota no topo da pilha o resultado
  pilha_push(c->p,v->b); //bota no topo da pilha o resultado

  //free(v);
  num_complexo_libera(u2); num_complexo_libera(u1);
}

void libera_calc(Calc* c){
  pilha_libera(c->p);
  free(c);
}
