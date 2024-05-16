//TAD ARVORE BINÁRIA

typedef struct arvbino ArvBiNo;
typedef struct arvbi ArvBi;

ArvBiNo* arvbi_criano(int info,ArvBiNo* esq,ArvBiNo* dir);
ArvBi* arvbi_cria(ArvBiNo* r);
void arvbi_imprime(ArvBi* a);
void arvbi_libera(ArvBi* a);
int arvbi_pertence(ArvBi* a, int x);
ArvBiNo* arvbi_busca(ArvBi* a,int x);

int pares(ArvBi* a); //Conta o número de valores pares que há na ArvBi;
int folhas(ArvBi* a); //Conta o número de nós folhas que há na ArvBi;
int um_filho(ArvBi* a); //conta o número de nós com apenas um filho que há na ArvBi;
int igual(ArvBi* a,ArvBi* b); //compara duas arvbi e diz se são iguais (resultando: 1, são iguais);
ArvBi* copia(ArvBi* a); //copia e aloca uma nova arvbi que é igual ao do argumento;
int nfolhas_maiores(ArvBi*a,int x); //Conta o número de nós que há na ArvBi que estejam acima de um valor x;
int soma_xy(ArvBi* a, int x,int y); //SOMA TODOS OS VALORES DA ArvBi Q ESTÃO ENTRE OS VALORES DE X E Y; com (x>y).
int nivel(ArvBi* a, int x); //Informa o nível que um valor x se encontra na ArvBi;
