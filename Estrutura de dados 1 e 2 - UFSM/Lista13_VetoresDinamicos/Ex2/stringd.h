#ifndef STRINGD_H
#define STRINGD_H


static int n = 0;
static int nmax = 4;

typedef struct strdin StrDin;

StrDin* sd_criavazia (void);
StrDin* sd_criacopia (const char* s);
void sd_atribui (StrDin* sd, const char* s);
void sd_concatena (StrDin* sd, const char* s);
const char* sd_acessa (StrDin* sd);
int sd_dimensao (StrDin* sd);
void sd_libera (StrDin* sd);

#endif
