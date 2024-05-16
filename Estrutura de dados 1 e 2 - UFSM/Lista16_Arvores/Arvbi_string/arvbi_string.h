//TAD ÁRVORE BINÁRIA (pra uma struct com string)
//A ARVORE É ORDENADA POR ORDEM ALFABÉTICA NOS NOMES

typedef struct aluno Aluno;
typedef struct arv Arv;
typedef struct arvno ArvNo;

Arv* cria(void);
void insere(Arv* a, char* nome,float p1,float p2,float p3);
void retira(Arv* a,char* v);
void imprime_dados(Arv* a);
void imprime_arv(Arv* a);
void libera(Arv* a);
