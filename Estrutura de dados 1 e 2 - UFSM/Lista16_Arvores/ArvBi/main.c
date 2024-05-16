#include<stdio.h>
#include<stdlib.h>
#include "arvbi.h"

int main(){
  //CRIANDO ARVORE BINARIA
  ArvBi* arv1 = arvbi_cria(
                arvbi_criano(5,
                    arvbi_criano(1,
                        arvbi_criano(2,
                            arvbi_criano(3,NULL,NULL),
                            NULL
                        ),
                        NULL
                    ),
                    arvbi_criano(7,
                        arvbi_criano(10,NULL,NULL),
                        arvbi_criano(13,NULL,NULL)
                    )
                )
             );

  puts("# ÁRVORE BINÁRIA: ");
  arvbi_imprime(arv1);

  int x = 2;
  ArvBiNo* a_no = arvbi_busca(arv1,x);
  ArvBi* arv2 = arvbi_cria(a_no);
  printf("\nBusca pelo nó com info = %d: ",x);
  arvbi_imprime(arv2);

  //EX1 - CAP_16 (ARVORES)
  int par = pares(arv1);
  printf("\n\nQuantia de Pares na ArvBi: %d",par);

  //EX2 - CAP_16 (ARVORES)
  int foia = folhas(arv1);
  printf("\nQuantia de Folhas na ArvBi: %d",foia);

  //EX3 - CAP_16 (ARVORES)
  int unfio = um_filho(arv1);
  printf("\nQuantia de Nó com um só filho na ArvBi: %d\n",unfio);

  ArvBi* arv3 = arvbi_cria(
                arvbi_criano(5,
                    arvbi_criano(1,
                        arvbi_criano(2,
                            arvbi_criano(3,NULL,NULL),
                            NULL
                        ),
                        NULL
                    ),
                    arvbi_criano(7,
                        arvbi_criano(13,NULL,NULL),
                        arvbi_criano(10,NULL,NULL)
                    )
                )
             );

  //EX4 - CAP_16 (ARVORES)
  int ig = igual(arv1,arv3);
  printf("\nÁs arvores (arv1,arv3) são iguais? -->  %d \n",ig);

  //EX5 - CAP_16 (ARVORES)
  ArvBi* copy = copia(arv1);
  puts("Copia Arv1:");
  arvbi_imprime(copy);

  //EX6 - CAP_16 (ARVORES)
  int xf = 4;
  int nfoia = nfolhas_maiores(arv1,xf); //DIZ QUANTAS FOLHAS HÁ NA ARV MAIORES Q XF
  printf("\nQuantia de Folhas na ArvBi maiores que %d: %d",xf,nfoia);

  //EX6 - CAP_16 (ARVORES)
  int x1 = 10; int y1 = 1;
  int soma_nos = soma_xy(arv1,x1,y1);
  printf("\nSoma de todos os valores do grafo do Nó (%d até %d) = %d\n",y1,x1,soma_nos);
  puts("\n");

  //EX6 - CAP_17 (ARVORES)
  ArvBi* arv4 = arvbi_cria(
                arvbi_criano(9, // nivel 0
                    arvbi_criano(1, //nivel 1
                        arvbi_criano(2, //nivel 2
                            arvbi_criano(6,NULL,NULL), //nivel 3
                            arvbi_criano(8,NULL,NULL) //nivel 3
                        ),
                        arvbi_criano(4,NULL,NULL) //nivel 2
                    ),
                    arvbi_criano(11, //nivel 1
                        arvbi_criano(13,NULL, //nivel 2
                            arvbi_criano(17,NULL,NULL) //nivel 3
                        ),
                        arvbi_criano(15,NULL,NULL) //nivel 2
                    )
                )
             );
  int no = 4; arvbi_imprime(arv4);
  int niveu = nivel(arv4,no);
  printf("\nNivel do Nó %d = %d\n",no,niveu);

  arvbi_libera(arv1); arvbi_libera(arv3); arvbi_libera(copy);
  return 0;
}
