typedef struct pilha Pilha;

//pilha_cria: cria e aloca uma struct de Pilha;
Pilha* pilha_cria(void);

//pilha_push: Adiciona um elemento "v", no topo da pilha;
void pilha_push(Pilha* p,float v);

//pilha_pop: Retira um elemento do topo da pilha;
float pilha_pop(Pilha* p);

//pilha_vazia: retorna se a pilha está ou não vazia;
int pilha_vazia(Pilha* p);

//pilha_libera: Libera a memória alocada por uma struct de Pilha;
void pilha_libera(Pilha* p);

//pilha_imprime: Printa as informações de uma Pilha;
void pilha_imprime(Pilha* p);

//topo: retorna o valor da informação do topo da pilha;
float topo(Pilha* p);

//Concatena duas pilhas (a pilha 2 é colacada em cima da pilha 1);
void concatena_pilhas(Pilha* p1,Pilha* p2);

//copia_pilha: Cria uma nova pilha que é uma cópia do argumento da função;
Pilha* copia_pilha(Pilha* p);
