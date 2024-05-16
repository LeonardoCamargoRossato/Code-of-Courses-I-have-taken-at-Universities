// LISTA 8 - lEONARDO CAMARGO ROSSATO //
// MATRICULA: 201613053 //
// #####   E X E R C I C I O - 09 #####//

#include <stdio.h>
#include <stdlib.h>

char* concatena(char* s1, char* s2, char sep){
  char* vetor_concatena; //= (char*)malloc(101*sizeof(char));
  int cont = 0;
  for(int i = 0; s1[i] != '\0' ; i++){
    vetor_concatena[i] = s1[i];
    cont++;
//    if(((s1[i] >= 'A') && (s1[i] <= 'Z')) || ((s1[i] >= 'a') && (s1[i] <= 'z'))) {
//      vetor_concatena[i] = s1[i];}
  }
  vetor_concatena[cont] = sep;
  int cont2 = 0;
  for(int i = 0; s2[i] != '\0'; i++){
    vetor_concatena[i+cont+1] = s2[i];
    cont2++;
//    if(((s2[i] >= 'A') && (s2[i] <= 'Z')) || ((s2[i] >= 'a') && (s2[i] <= 'z'))) {
//      vetor_concatena[i+cont+1] = s2[i];}
  }

  vetor_concatena[cont2+cont+1]='\0'; //CARACTERE PRA FECHAR STRING

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
  scanf(" %s", &sep);

  char* concatena_main = concatena(s1,s2,sep);

  printf("\nTexto de saída da função: \n :{  ");
  for(int i = 0; concatena_main[i] != '\0'; i++){
    printf("%c",concatena_main[i]);}

  puts("  }\n");


  free(s1); free(s2);
  //free(concatena_main);

  return concatena_main;
}
