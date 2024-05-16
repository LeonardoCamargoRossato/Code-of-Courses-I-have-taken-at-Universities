/* TAD: Matriz m por n */

#ifndef MATRIZ_H
#define MATRIZ_H

/* Tipo exportado e a Struct exportada*/
typedef struct matriz Matriz;

/* FUNÇÕES EXPORTADAS */

/* função cria
** Aloca e retorna um vetor simples de matriz com dimensão (mxn); Onde m = n° linha; n = n° colunas;
*/
Matriz* mat_cria(int m, int n);

/* função libera
** Libera a memória alocada para a matriz;
*/
void mat_libera(Matriz* mat);

/* função acessa
** acessa o elemento da linha i e da coluna j  da matriz;
** Obs* como é uma matriz de vetor simples vetor[k]; Onde k = i*n + m;
*/
float mat_acessa(Matriz* mat,int i,int j);

/* função atribui
** atribui o elemento da linha i e da coluna j  da matriz;
** Obs* como é uma matriz de vetor simples vetor[k]; Onde k = i*n + m;
*/
void mat_atribui(Matriz* mat, int i, int j, float v);

/* função linhas
** Retorna o número de linhas da matriz alocada;
*/
int mat_linhas(Matriz* mat);

/* função colunas
** Retorna o número de colunas da matriz alocada;
*/
int mat_colunas(Matriz* mat);

#endif
