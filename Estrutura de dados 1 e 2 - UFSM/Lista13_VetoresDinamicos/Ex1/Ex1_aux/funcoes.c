#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "aluno.h"


struct aluno{
  char nome[81];
  float p1,p2,p3;
};

Aluno* sd_criavazia (void)
{
    return sd_criacopia ("");
}

Aluno* sd_criacopia (const char* s)
{
    Aluno* sd_aluno = (Aluno*) malloc(sizeof(Aluno));
    sd_aluno->nome == NULL;
    sd_atribui (sd_aluno, s);
    return sd_aluno;
}

static void realoca (Aluno* sd_aluno, int i)
{
    sd_aluno->nome == (char*) realloc(sd_aluno->nome,i*sizeof(char));
}

void sd_atribui (Aluno* sd_aluno, const char* s)
{
  if(n >= nmax){
    realoca (sd_aluno,nmax *= 2);
    strcpy(sd_aluno->nome,s);
  }
  n++;
}

void sd_concatena (Aluno* sd_aluno, const char* s)
{
  n += nmax+strlen(s);
  if(n >= nmax){
    realoca (sd_aluno, n);
  }
  strcat(sd_aluno->nome,s);
}

const char* sd_acessa (Aluno* sd_aluno)
{
    return sd_aluno->nome;
}

int sd_dimensao (Aluno* sd_aluno)
{
    return (strlen(sd_aluno->nome));
}

void sd_libera (Aluno* sd_aluno)
{
    free(sd_aluno->nome);
    free(sd_aluno);
}
