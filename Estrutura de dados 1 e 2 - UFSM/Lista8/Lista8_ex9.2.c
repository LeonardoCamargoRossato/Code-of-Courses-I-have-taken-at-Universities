#include <stdio.h>
#include <stdlib.h>

char* concatena(char* s1, char* s2, char sep){
  char* vetor_concatena; // = (char*)malloc(101*sizeof(char));
  int cont = 0; int i = 0;
  while(vetor_concatena[i] != '\0'){
    i++;
    for(int j = 0; s1[j] != '\0' ; j++){
      vetor_concatena[i] = s1[j];
      cont++;
    }
    vetor_concatena[i] = '\0';
  }
  vetor_concatena[cont+2] = sep;

  printf("%c\n",vetor_concatena[cont+2]);

  while(vetor_concatena[i] != '\0'){
    i++;
    for(int j = 0; s2[j] != '\0'; j++){
      vetor_concatena[j+cont+3] = s2[j];
    }
    vetor_concatena[i] = '\0';
  }

  return vetor_concatena;
}

char* main(){
  char* s1 = (char*)malloc(101*sizeof(char));
  printf("\n\n Digite um texto: \n --> ");
  scanf(" %100[^\n]", s1);

  char* s2 = (char*)malloc(101*sizeof(char));
  printf("\n Digite um segundo texto: \n --> ");
  scanf(" %100[^\n]", s2);

  char sep;
  printf("\n Digite o caractere de separação: \n -->  ");
  scanf(" %c", &sep);

  char* concatena_main = concatena(s1,s2,sep);

  printf("\nTexto de saída da função: \n :{  ");
  for(int i = 0; concatena_main[i] != '\0'; i++)
    printf("%c",concatena_main[i]);

  puts("  }\n");
  printf("%c",concatena_main[0]);
    printf("%c",concatena_main[1]);
      printf("%c",concatena_main[2]);
        printf("%c",concatena_main[3]);
          printf("%c",concatena_main[4]);
            printf("%c",concatena_main[5]);
              printf("%c",concatena_main[6]);
                printf("%c",concatena_main[7]);
                  printf("%c",concatena_main[8]);
  puts("  }\n");

  //free(s1); free(s2);
//  free(concatena_main);

  return 0;//concatena_main;
}
