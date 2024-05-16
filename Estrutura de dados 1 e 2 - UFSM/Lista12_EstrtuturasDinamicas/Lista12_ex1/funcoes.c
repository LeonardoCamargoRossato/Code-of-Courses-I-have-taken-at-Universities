#include "ponto.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct ponto{
  float x;
  float y;
};

struct ponto_polar{
  float r;
  float teta;
};

Ponto* pto_cria (float x, float y){
  Ponto* p = (Ponto*) malloc(sizeof(Ponto));
  if (p == NULL){
    printf("\nMemoria Insuficiente!\n");
    exit(1);
  }
  p->x = x;
  p->y = y;
  return p;
}

Ponto_polar* pto_criapolar(Ponto* p){
  Ponto_polar* pp = (Ponto_polar*)malloc(sizeof(Ponto_polar));
  if (pp == NULL){
    printf("\nMemoria Insuficiente!\n");
    exit(1);
  }
  pp->r = sqrt(p->x*p->x + p->y*p->y);
  pp->teta = p->y/p->x;

  return pp;
}

float pto_raio(Ponto* p){
  float raio = sqrt(p->x*p->x + p->y*p->y);
  return raio;
}

float pto_angulo(Ponto* p){
  float angulo = p->y/p->x;
  return angulo;
}



void pto_libera(Ponto* p){
 free(p);
}

void pto_acessa(Ponto* p, float* x,float* y){
  *x = p->x;
  *y = p->y;
}

void pto_atribui(Ponto* p, float x,float y){
  p->x = x;
  p->y = y;
}

float pto_distancia(Ponto* p1,Ponto* p2){
  float dx = p2->x - p1->x;
  float dy = p2->y - p1->y;
  return sqrt(dx*dx + dy*dy);
}
