#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

int main(){
  Fila* f1 = fila_cria();
  fila_insere(f1,11.1);
  fila_insere(f1,22.2);
  fila_insere(f1,33.3);
  fila_insere(f1,55.4);
  fila_insere(f1,77.5);
  fila_insere(f1,99.6);
  fila_insere(f1,145.6);
  puts("\nFila 1: ");
  fila_imprime(f1);

  Fila* f2 = fila_cria();
  fila_insere(f2,1.0);
  fila_insere(f2,2.0);
  fila_insere(f2,3.0);
  fila_insere(f2,5.0);
  fila_insere(f2,7.0);
  puts("\nFila 2: ");
  fila_imprime(f2);

  puts("\nFila Combinada (f1+f2): ");
  Fila* f_res = fila_cria();
  combina_filas(f_res,f1,f2);
  fila_imprime(f_res);

  puts("\n");
  fila_libera(f_res);
  return 0;
}
