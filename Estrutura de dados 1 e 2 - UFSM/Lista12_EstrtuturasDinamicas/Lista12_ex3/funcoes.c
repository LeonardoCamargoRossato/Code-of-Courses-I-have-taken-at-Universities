#include "num_complexo.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>


Num_Complexo* num_complexo_cria(int a, int b){
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
  puts("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
  return u_aux;
}

Num_Complexo* num_complexo_multiplica(Num_Complexo* u, Num_Complexo* v){
  Num_Complexo* u_aux;
  u_aux->a = u->a*v->a - u->b*v->b; // parte real
  u_aux->b = u->a*v->b + u->b*v->a; // parte imaginária
  printf("u_aux->a:%.2f | u_aux->b:%.2f\n",u_aux->a,u_aux->b);
  return u_aux;
}

Num_Complexo* num_complexo_divide(Num_Complexo* u, Num_Complexo* v){
  Num_Complexo* u_aux;
  u_aux->a = (u->a*v->a + u->b*v->b)/(v->a*v->a + v->b*v->b);
  u_aux->b = (u->b*v->a - u->a*v->b)/(v->a*v->a + v->b*v->b);
  return u_aux;
}
