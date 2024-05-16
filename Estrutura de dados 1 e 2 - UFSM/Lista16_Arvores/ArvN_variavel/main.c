#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
#include "arvn.h"

int main(){
  //CRIA NÓS COMO FOLHAS DE UMA ÁRVORE BINARIA
  ArvnNo* no1 = arvn_criano(1);
  ArvnNo* no2 = arvn_criano(2);
  ArvnNo* no3 = arvn_criano(3);
  ArvnNo* no5 = arvn_criano(5); //RAÍZ
  ArvnNo* no7 = arvn_criano(7);
  ArvnNo* no10 = arvn_criano(10);
  ArvnNo* no13 = arvn_criano(13);
  //CRIA A HIERAQUIA
  arvn_insere(no7,no13);
  arvn_insere(no5,no10);
  arvn_insere(no2,no3);
  arvn_insere(no1,no2);
  arvn_insere(no5,no7);
  arvn_insere(no5,no1);

  //CRIA RAIZ DA ARVORE N-VARIÁVEL
  Arvn* arvNvar = arvn_cria(no5);

  puts("\n ##FIRST N-Variable TREE: ");
  arvn_imprime(arvNvar);

  //INTEIRO BUSCADO
  int x = 7;
  ArvnNo* no_search = arvn_busca(arvNvar,x);
  Arvn* arv_search = arvn_cria(no_search);
  if(arv_search->raiz==NULL)
    puts("\n\n ARV_SEARCH->raiz TA NULO PORRA;");
  printf("\n\n Nó_Search do int %d:",x);
  arvn_imprime(arv_search);

  //EX1 - CAP16
  int par = pares(arvNvar);
  printf("\nEX1: Quantia de Pares na arvNvar: %d\n",par);

  //EX2 - CAP16
  int foia = folhas(arvNvar);
  printf("\nEX2: Quantia de Folhas na arvNvar: %d\n",foia);

  //EX3 - CAP16
  int un_hirro = um_filho(V);
  printf("\nEX3: Quantia de Nós Com Apenas Um Filho na arvNvar: %d\n",un_hirro);

  puts("\n");
  arvn_libera(arvBi);
  return 0;
}
