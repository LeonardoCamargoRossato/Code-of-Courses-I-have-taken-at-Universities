#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct aluno Aluno;
struct aluno{
  char nome;
  char matricula;
  char turma;
  float p1;
  float p2;
  float p3;
};

void inicializa(int n, Aluno** turmas){
  for (int i =0; i<n;i++){
    turmas[i] = NULL;
  }
}

void imprime_aprovados(int n, Aluno** turmas){
  //if((i<0) || (i>n)){ puts("Indice (n) fora dos limites do vetor."); exit(1);}
  float media = 0;
  for(int i = 0; i<n; i++){
    if (turmas[i] != NULL){
      media = (turmas[i]->p1 + turmas[i]->p2 + turmas[i]->p3)/3;
      if ( media >= 5.0){
        printf("Aprovado.\t %c ; %c;\n",turmas[i]->nome,turmas[i]->turma);
      }
    }
  }
}

int main(){
  printf("\n\nDigite o total de alunos: ");
  int n; scanf("%d",&n);
  Aluno** turmas = (struct aluno**)malloc(sizeof(struct aluno*)); inicializa(n,turmas);
  int i = 0;
  printf("\nAgora os dados de cada um: nome;matricula;turma; notas:p1;p2;p3; \n");
  scanf(" %s %s %s",&turmas[i]->nome,&turmas[i]->turma,&turmas[i]->matricula);
  puts("Hedll");

//  volta: i++;
  if(i<n){
    printf("Nome: "); scanf(" %s",&turmas[i]->nome);
    printf("Turma: "); scanf(" %s",&turmas[i]->turma);
    printf("Matrícula: "); scanf(" %s",&turmas[i]->matricula);
    printf("Notas(p1,p2,p3) : "); scanf("%f %f %f",&turmas[i]->p1,&turmas[i]->p2,&turmas[i]->p3);
//    goto volta;
  }



  imprime_aprovados(n,turmas);

  free(turmas);
  return 0;
}
