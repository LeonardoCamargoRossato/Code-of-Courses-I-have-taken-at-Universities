#ifndef ALUNO_H
#define ALUNO_H


static int n = 0;
static int nmax = 4;

typedef struct aluno Aluno;

Aluno* sd_criavazia (void);
Aluno* sd_criacopia (const char* s);
void sd_atribui (Aluno* sd_aluno, const char* s);
void sd_concatena (Aluno* sd_aluno, const char* s);
const char* sd_acessa (Aluno* sd_aluno);
int sd_dimensao (Aluno* sd_aluno);
void sd_libera (Aluno* sd_aluno);

#endif
