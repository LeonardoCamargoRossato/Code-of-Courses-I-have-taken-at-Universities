#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stringd.h"


struct strdin
{
    char* v;
};

StrDin* sd_criavazia (void)
{
    return sd_criacopia ("");
}

StrDin* sd_criacopia (const char* s)
{
    StrDin* sd = (StrDin*) malloc(sizeof(StrDin));
    sd->v = NULL;
    sd_atribui (sd, s);
    return sd;
}

static void realoca (StrDin* sd, int i)
{
    sd->v = (char*) realloc(sd->v,i*sizeof(char));
}

void sd_atribui (StrDin* sd, const char* s)
{
  if(n >= nmax){
    realoca (sd,nmax *= 2);
    strcpy(sd->v,s);
    int cont0 = 0;
    printf("0.5 repetiu %d\n", cont0);
  }
  else if(n <= 0.5*nmax){
    realoca (sd,nmax/2);
    strcpy(sd->v,s);
    int cont1 = 0;
  }
  n++;
}

void sd_concatena (StrDin* sd, const char* s)
{
  n += nmax+strlen(s);
  if(n >= nmax){
    realoca (sd, n);
  }
  else if(n <= 0.5*nmax){
    realoca (sd, nmax/2);
  }
  strcat(sd->v,s);
}

const char* sd_acessa (StrDin* sd)
{
    return sd->v;
}

int sd_dimensao (StrDin* sd)
{
    return (strlen(sd->v));
}

void sd_libera (StrDin* sd)
{
    free(sd->v);
    free(sd);
}
