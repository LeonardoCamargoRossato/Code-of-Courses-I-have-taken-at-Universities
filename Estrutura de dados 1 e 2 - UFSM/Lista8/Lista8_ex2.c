// LISTA 8 - lEONARDO CAMARGO ROSSATO //
// MATRICULA: 201613053 //
// #####   E X E R C I C I O - 02 #####//

#include <stdio.h>
#include <stdlib.h>

int conta_vogais(char* str){
  int cont = 0;
  for(int i = 0; str[i] != '\0'; i++){
    if( (str[i] == 'a') || (str[i] == 'e') || (str[i] == 'i') || (str[i] == 'o') || (str[i] == 'u')  ||  (str[i] == 'A') || (str[i] == 'E') || (str[i] == 'I') || (str[i] == 'O') || (str[i] == 'U') ){
      cont++;
    }
  }
  return cont;
}

int main(){
  char* str = (char*)malloc(101*sizeof(char));
  printf("\n\nDigite um texto: \n --> ");
  scanf(" %100[^\n]", str);

  int contador = conta_vogais(str);
  printf("\n A Quantia de vogais no texto é = { %d }." , contador);
  puts("\n\n");
  free(str);
  return contador;
}
