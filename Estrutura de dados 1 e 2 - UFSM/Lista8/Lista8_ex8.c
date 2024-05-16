// LISTA 8 - lEONARDO CAMARGO ROSSATO //
// MATRICULA: 201613053 //
// #####   E X E R C I C I O - 08 #####//

#include <stdio.h>
#include <stdlib.h>

char* converte(char* str){

  char* v_troca = (char*)malloc(101*sizeof(char));

    for(int i = 0; str[i] != '\0'; i++){
      if(((str[i] >= 'A') && (str[i] <= 'Z')) || ((str[i] >= 'a') && (str[i] <= 'z'))) {
        v_troca[i] = str[i];
      }
    }
  return v_troca;
}

char* main(){
  char* str = (char*)malloc(101*sizeof(char));
  printf("\n\nDigite um texto: \n --> ");
  scanf(" %100[^\n]", str);

  char* str_converte = converte(str);

  printf("\nTexto de saída da função: \n :{  " );
  for(int i = 0; str[i] != '\0'; i++)
    printf("%c",str_converte[i]);
  puts("  }\n");
  free(str);
  free(str_converte);
  return 0;
}
