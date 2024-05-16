typedef struct fila Fila;

//pilha_fila: cria e aloca uma struct de Fila;
Fila* fila_cria(void);

//fila_insere: Adiciona um elemento "v", no fim da fim;
void fila_insere(Fila* f,float v);

//fila_retira: Retira o elemento do inicio da fila;
float fila_retira(Fila* f);

//fila_vazia: retorna se a Fila está ou não vazia;
int fila_vazia(Fila* f);

//fila_libera: Libera a memória alocada por uma struct de Fila;
void fila_libera(Fila* f);

//fila_imprime: Printa as informações de uma Fila;
void fila_imprime(Fila* f);

//combina_filas: Combina em uma fila, alternadamente os elementos de duas filas;
//O primeiro argumento é aonde será alocada a fila resultante;
//Os últimos argumentos (filas) da função, serão liberados da memória;
//*Obs: se as filas não possuírem a mesma dimensão, a fila maior terá os elementos excedentes
//inseridos em sequência na fila resultante (da combinação);
void combina_filas(Fila* f_res,Fila* f1,Fila* f2);
