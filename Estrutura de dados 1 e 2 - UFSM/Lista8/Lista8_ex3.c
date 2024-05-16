// LISTA 8 - lEONARDO CAMARGO ROSSATO //
// MATRICULA: 201613053 //
// #####   E X E R C I C I O - 03 #####//

#include <stdio.h>
#include <stdlib.h>

void minusculo(char* str){
  for(int i = 0; str[i] != '\0'; i++){
    if((str[i] >= 'A') && (str[i] <= 'Z')){
      str[i] += ('a'-'A');
    }
  }
}

char* main(){
  char* str = (char*)malloc(101*sizeof(char));
  printf("\n\nDigite um texto: \n --> ");
  scanf(" %100[^\n]", str);

  minusculo(str);
  printf(" ");
  printf("\nTexto de saída da função (Só com Letras Minúsculas): \n :{  %s  }.",str);

  puts("\n");
  free(str);
  return str;
}
