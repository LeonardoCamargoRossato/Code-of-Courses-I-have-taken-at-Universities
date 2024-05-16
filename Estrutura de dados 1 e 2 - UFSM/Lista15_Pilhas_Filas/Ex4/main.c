#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

int main(){
  printf("---------------------------------\n");
  puts(" Calculadora Complexa Pós-Fixada:");
  printf("---------------------------------\n");
  puts(" *Obs* num_complexo := { u = (a,b) onde a ~ Parte Real | b ~ Parte Imaginária }.");
  puts(" *Digite 'q' para sair da Calculadora.");
  printf("\n\n--> ");

  Calc* math = cria_calc();
  while(1){
    char c;
    scanf(" %c",&c);
    if(c=='+' || c=='-' || c=='*'|| c=='/')
      operador_calc(math,c);
    else if (c == 'q')
      break;
    else{
      float v;
      ungetc(c,stdin);
      if(scanf("%f",&v) == 1)
        operando_calc(math,v);
      else{
        printf("Erro na leitura.\n");
        exit(1);
      }
    }
  }
  libera_calc(math);
  return 0;
}
