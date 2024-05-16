#include "num_complexo.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void){

  puts("\n Numeros Complexos: prog1 \n");
  Num_Complexo* u = num_complexo_cria(1,1);
  Num_Complexo* v = num_complexo_cria(2,-1);

  printf(" Número complexo u = ");
  num_complexo_printa(u);
  printf("\n Número complexo v = ");
  num_complexo_printa(v);

  Num_Complexo* soma = num_complexo_soma(u,v);
  printf("\n\n Soma: u+v = ");
  num_complexo_printa(soma);

  Num_Complexo* subtrai = num_complexo_subtrai(u,v);
  printf("\n Subtrai: u-v = ");
  num_complexo_printa(subtrai);

  Num_Complexo* multiplica = num_complexo_multiplica(u,v);
  printf("\n Multiplica: u*v = ");
  num_complexo_printa(multiplica);


  Num_Complexo* divide = num_complexo_divide(u,v);
  printf("\n Divide: u/v = ");
  num_complexo_printa(divide);
  puts("\n");

  num_complexo_libera(u);
  num_complexo_libera(v);
  return 0;
}
