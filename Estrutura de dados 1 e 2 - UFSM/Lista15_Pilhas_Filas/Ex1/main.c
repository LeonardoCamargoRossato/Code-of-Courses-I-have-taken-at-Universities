#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main(){
  Pilha* p1 = pilha_cria();
  pilha_push(p1,12.0);
  pilha_push(p1,21.1);
  pilha_push(p1,32.2);
  pilha_push(p1,45.3);
  pilha_push(p1,56.4);
  pilha_push(p1,89.5);
  puts("\nPilha 1: ");
  pilha_imprime(p1);

  float top = topo(p1);
  printf("\nTopo da Pilha 1: %.1f ",top);


  Pilha* p2 = pilha_cria();
  pilha_push(p2,1.0);
  pilha_push(p2,2.0);
  pilha_push(p2,3.0);
  pilha_push(p2,5.0);
  pilha_push(p2,7.0);
  puts("\nPilha 2: ");
  pilha_imprime(p2);

  concatena_pilhas(p1,p2);
  puts("\nPilha Concatenada (p1+p2): ");
  pilha_imprime(p1);

  Pilha* p3 = pilha_cria();
  p3 = copia_pilha(p1);
  puts("\nPilha 3 (cópia de p1): ");
  pilha_imprime(p3);

  puts("\n");
  pilha_libera(p1);
  return 0;
}
