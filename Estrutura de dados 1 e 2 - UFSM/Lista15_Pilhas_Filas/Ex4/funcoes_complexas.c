#include "num_complexo.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>


Num_Complexo* num_complexo_cria(float a, float b){
  Num_Complexo* u = (Num_Complexo*)malloc(sizeof(Num_Complexo));
  u->a = a;
  u->b = b;
  return u;
}

void num_complexo_printa(Num_Complexo* u){
  if(u->b < 0)
    printf("%.1f %.1fi",u->a,u->b);
  else
    printf("%.1f + %.1fi",u->a,u->b);
}

void num_complexo_libera(Num_Complexo* u){
 free(u);
}

Num_Complexo* num_complexo_soma(Num_Complexo* u, Num_Complexo* v){
  Num_Complexo* u_aux;
  u_aux->a = u->a + v->a;
  u_aux->b = u->b + v->b;
  return u_aux;
}

Num_Complexo* num_complexo_subtrai(Num_Complexo* u, Num_Complexo* v){
  Num_Complexo* u_aux;
  u_aux->a = u->a - v->a;
  u_aux->b = u->b - v->b;
  return u_aux;
}

Num_Complexo* num_complexo_multiplica(Num_Complexo* u, Num_Complexo* v){
  Num_Complexo* u_aux;
  printf("u:(%.2f,%.2f)*v:(%.2f,%.2f)\n",u->a,u->b,v->a,v->b);
  u_aux->a = u->a*v->a - u->b*v->b; // parte real
  float ub = u->b; float va = v->a;
  float imag1 = ub*va;
  float ua = u->a; float vb = v->b;
  float imag2 = ua*vb;
  u_aux->b = imag1 + imag2; // parte imaginária
  return u_aux;
}

Num_Complexo* num_complexo_divide(Num_Complexo* u, Num_Complexo* v){
  Num_Complexo* u_aux;
  u_aux->a = (u->a*v->a + u->b*v->b)/(v->a*v->a + v->b*v->b);
  u_aux->b = (u->b*v->a - u->a*v->b)/(v->a*v->a + v->b*v->b);
  return u_aux;
}
