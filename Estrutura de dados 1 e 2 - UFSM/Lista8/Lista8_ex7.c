// LISTA 8 - lEONARDO CAMARGO ROSSATO //
// MATRICULA: 201613053 //
// #####   E X E R C I C I O - 07 #####//

#include <stdio.h>
#include <stdlib.h>

char* retira_sufixo(char* str,int n){
  int cont = 0;
  for(int i = 0; str[i] != '\0'; i++){
    cont++;
  }
  char* v_troca = (char*)malloc(101*sizeof(char));
  if (n<cont){
    for(int i = 0; str[i] != '\0'; i++){
      v_troca[i] = str[i];
      if(((str[i] >= 'A') && (str[i] <= 'Z')) || ((str[i] >= 'a') && (str[i] <= 'z'))) {
        v_troca[i] = str[i];
        if (str[i+(n+1)] == '\0')
          break;
      }
    }
  }
  else{
    printf("\n\n --> Há mais elementos para serem retirados da string do que a quantia total que a string possui.\n\n");
    exit(1);
  }
  return v_troca;
}

char* main(){
  char* str = (char*)malloc(101*sizeof(char));
  printf("\n\nDigite um texto: \n --> ");
  scanf(" %100[^\n]", str);
  printf("Digite a quantia (n) que será retirada do texto(de trás pra frente): \n --> ");
  int n;  scanf("%d",&n);

  char* str_sem_sufixo = retira_sufixo(str,n);
  printf("\nTexto de saída da função: \n :{  %s  }.",str_sem_sufixo);
  puts("\n");
  free(str);
//  free(v_troca);
  free(str_sem_sufixo);
  return str_sem_sufixo;
}
