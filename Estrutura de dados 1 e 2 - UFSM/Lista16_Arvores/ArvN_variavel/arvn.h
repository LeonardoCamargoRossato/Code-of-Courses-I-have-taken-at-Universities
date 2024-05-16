// TAD GRAFO

typedef struct arvn Arvn; //aponta pra raíz da árvore
typedef struct arvnno ArvnNo; //aponta para lista de nós da árvore

struct arvnno{
  int info;
  ArvnNo* prim;
  ArvnNo* prox;
};

struct arvn{
  ArvnNo* raiz;
};

ArvnNo* arvn_criano(int x);
void arvn_insere(ArvnNo* a, ArvnNo* sa);
Arvn* arvn_cria(ArvnNo* r);
void arvn_imprime(Arvn* a);
ArvnNo* arvn_busca(Arvn* a, int x);
void arvn_libera(Arvn* a);

int pares(Arvn* a); //(GENERALIZADA)
int pares2(Arvn* a); //(NÃO GENERALIZADA)

int folhas(Arvn* a);
int um_filho(Arvn* a);
//#################################################
//########## DESCRIÇÕES DAS FUNÇÕES: ##############
//#################################################

//arvn_criano: cria e aloca um nó da árvore contendo a informação de um inteiro;

//arvn_insere: insere um nó de uma sub-árvore em um nó da árvore;

//arvn_cria: cria e aloca uma árvore dada um nó incial;

//arvn_imprime: printa as informações da árvore, partindo de uma certa ordenação;

//arvn_busca: busca uma informação (de um inteiro), dentro da árvore, passando por um caminho ordenado;

//arvn_libera: libera a alocação da memória de uma árvore;

//####################################################################################
//########## A PARTIR AS FUNÇÕES SÓ VALEM PARA O TIPO DE ÁRVORE BINÁRIA ##############
//####################################################################################

//pares: busca e informa quantos números pares há dentro da árvore binária;
