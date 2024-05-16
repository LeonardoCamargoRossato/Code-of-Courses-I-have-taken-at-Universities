// LISTA 8 - lEONARDO CAMARGO ROSSATO //
// MATRICULA: 201613053 //
// #####   E X E R C I C I O - 05 #####//

#include <stdio.h>
#include <stdlib.h>

void string_oposta(char* str){
  for(int i = 0; str[i] != '\0'; i++){
    if((str[i] > 'A') && (str[i] < 'Z')){
      str[i] = ('Z'-(str[i]-'A'));
    }
    if((str[i] > 'a') && (str[i] < 'z')){
      str[i] = ('z'-(str[i]-'a'));
    }
    else if (str[i] == 'z'){ str[i] = 'a'; }
    else if (str[i] == 'Z'){ str[i] = 'A'; }
    else if (str[i] == 'a'){ str[i] = 'z'; }
    else if (str[i] == 'A'){ str[i] = 'Z'; }
  }
}

char* main(){
  char* str = (char*)malloc(101*sizeof(char));
  printf("\n\nDigite um texto: \n --> ");
  scanf(" %100[^\n]", str);

  string_oposta(str);
  printf(" ");
  printf("\nTexto de saída da função: \n :{  %s  }.",str);

  puts("\n");
  free(str);
  return str;
}
