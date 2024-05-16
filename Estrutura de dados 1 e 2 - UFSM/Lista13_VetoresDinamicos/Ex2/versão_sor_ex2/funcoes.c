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

static void realoca (StrDin* sd, int n)
{
    sd->v = (char*) realloc(sd->v,n+1);
}

void sd_atribui (StrDin* sd, const char* s)
{
    realoca (sd, strlen(s));
    strcpy(sd->v,s);
}

void sd_concatena (StrDin* sd, const char* s)
{
    realoca (sd, strlen(sd->v)+strlen(s));
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
