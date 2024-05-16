#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvbi_string.h"

int main(){
  Arv* a = cria();
  insere(a,"Isa Nass",6,7.4,8.6);
  insere(a,"Larissa Martins",4,4.4,5.6);
  insere(a,"Cassia Schirmann",9,7.4,8.6);
  insere(a,"Aldren Pizzio",6.5,3.8,4.7);
  insere(a,"Juliana Almeida",5,3.4,2.6);
  insere(a,"Lissa Corrêa",6,5.4,5.6);
  insere(a,"Lena Maria Eduarda",3,2.4,1.6);
  insere(a,"Gabriela Amaral",6,6.4,5.6);
  insere(a,"Thamires Miranda",6,4.4,5.6);
  insere(a,"Barbara Collares",4.5,5,6.2);
  // insere(a,"Bruna Fragoso",8,7.4,8.6);
  // insere(a,"Gicelli Martelli",8,7.4,8.6);
  // insere(a,"Renata Anhalt",4,5.4,3.6);
  // insere(a,"Vitória Carrião",4,6.4,8.6);
  // insere(a,"Letícia Pascotto",4,6.4,8.6);
  // insere(a,"Taíse Levy",8,7.4,8.6);
  // insere(a,"Astridd",3,2.4,1.6);
  // insere(a,"Maria Eduarda",7,7.4,6.6);
  // insere(a,"Giovana Santos",7.5,8,7.2);

  printf("Árvore das Notas das Mina: ");
  imprime_arv(a);
  printf("\n## Dados das Mina:");
  imprime_dados(a);

  retira(a,"Thamires Miranda");
  retira(a,"Aldren Pizzio");

  printf("\n\nÁrvore das Notas das Mina: ");
  imprime_arv(a);
  printf("\n## Dados das Mina:");
  imprime_dados(a);

  retira(a,"Cassia Schirmann");

  printf("\n\nÁrvore das Notas das Mina: ");
  imprime_arv(a);
  printf("\n## Dados das Mina:");
  imprime_dados(a);

  puts("\n");
  libera(a);
  return 0;
}
