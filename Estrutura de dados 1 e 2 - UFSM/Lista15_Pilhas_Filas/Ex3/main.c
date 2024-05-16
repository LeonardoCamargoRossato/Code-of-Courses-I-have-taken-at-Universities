#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

int main(){
  puts("Calculadora Real Pós-Fixada:");
  printf("--> ");
  Calc* math = cria_calc("%.2f\n");
  while(1){
    char c;
    scanf(" %c",&c);
    if(c=='+' || c=='-' || c=='*'|| c=='/')
      operador_calc(math,c);
    else if (c=='q')
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
