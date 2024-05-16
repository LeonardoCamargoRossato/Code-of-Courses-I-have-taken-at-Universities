//TAD* ALUNO

typedef struct aluno Aluno;
struct aluno{
  char nome[81];
  float p1,p2,p3;
};

Aluno* aluno_cria(void);
void aluno_insere(Aluno* aluno,float x);
int aluno_tam(Aluno* aluno);

float aluno_acessa_p1(Aluno* aluno, int i);
float aluno_acessa_p2(Aluno* aluno, int i);
float aluno_acessa_p3(Aluno* aluno, int i);
char aluno_acessa_nome(Aluno* aluno, int i);

void printa_aluno(Aluno* vd_aluno, int i);
void printa_turma(Aluno* vd_aluno);

void aluno_libera(Aluno* aluno);
