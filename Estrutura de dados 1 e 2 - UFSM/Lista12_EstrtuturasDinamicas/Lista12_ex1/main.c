#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "ponto.h"

int main(void){
  Ponto* p = pto_cria(2.0,1.0);

  //Coord Polares do Ponto
  float r = pto_raio(p);
  float ang = pto_angulo(p);

  printf("\n Coord.Polares do ponto em (raio,angulo): (%f,%f)\n",r,ang);

  pto_libera(p);
  return 0;
}
