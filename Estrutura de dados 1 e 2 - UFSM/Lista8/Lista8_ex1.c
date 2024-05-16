// LISTA 8 - lEONARDO CAMARGO ROSSATO //
// MATRICULA: 201613053 //
// #####   E X E R C I C I O - 01 #####//

#include <stdio.h>
#include <stdlib.h>

int conta_ocorrencias (char* s, char c){
  int cont = 0;
  for (int i = 0; s[i]!='\0'; i++){
    if (s[i]==c){
    cont++;
    }
  }
  return cont;
}

int main(){
  char* s = (char*)malloc(81*sizeof(char));
  char c;
  printf("\n\nDigite um texto: \n --> ");
  scanf(" %80[^\n]", s);


  printf("\nDigite o caractere que vc quer procurar no texto: \n --> ");
  scanf("%s",&c);

  int contador = conta_ocorrencias(s,c);
  printf("\nQuantia de Ocorrencias do caractere \"%c\" no texto: %d",c,contador);
  puts("\n\n");
  free(s);
  return 0;
}
