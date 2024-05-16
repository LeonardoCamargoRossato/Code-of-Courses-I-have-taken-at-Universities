// LISTA 8 - lEONARDO CAMARGO ROSSATO //
// MATRICULA: 201613053 //
// #####   E X E R C I C I O - 06#####//

#include <stdio.h>
#include <stdlib.h>

void roda_string(char* str){
  char p;
  for(int i = 0; str[i] != '\0'; i++){
    if(((str[i] >= 'A') && (str[i] <= 'Z')) || ((str[i] >= 'a') && (str[i] <= 'z'))) {
      if (str[i+1] == '\0'){
        p = str[i];
        break;}
    }
  }
  char* v_troca;
  v_troca[0] = p;
  for(int i = 0; str[i] != '\0'; i++){
    v_troca[i+1] = str[i];
    if(((str[i] >= 'A') && (str[i] <= 'Z')) || ((str[i] >= 'a') && (str[i] <= 'z'))) {
      v_troca[i+1] = str[i];
    }
  }
  str[0] = p;
  for(int i = 0; str[i] != '\0'; i++){
    if(((str[i] >= 'A') && (str[i] <= 'Z')) || ((str[i] >= 'a') && (str[i] <= 'z'))) {
      str[i] = v_troca[i];
    }
  }
}

char* main(){
  char* str = (char*)malloc(101*sizeof(char));
  printf("\n\nDigite um texto: \n --> ");
  scanf(" %100[^\n]", str);

  roda_string(str);
  printf(" ");
  printf("\nTexto de saída da função: \n :{  %s  }.",str);

  puts("\n");
  free(str);
  return str;
}
