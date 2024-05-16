/* TAD: Numero Complexo (a + bi) */

#ifndef NUM_COMPLEXO
#define NUM_COMPLEXO

/* Tipo exportado e a Struct exportada*/
typedef struct num_complexo Num_Complexo;
struct num_complexo{
  float a; //Parte Real
  float b; //Parte Imaginária
};

/* FUNÇÕES EXPORTADAS */

/* função cria
** Aloca e retorna um número complexo z(a,b) = a+ib; Onde a = Re(z); b = Im(z);
*/
Num_Complexo* num_complexo_cria(float a, float b);

/* função printa
** Printa (faz um printf de) um número complexo z(a,b) = a+ib; Onde a = Re(z); b = Im(z);
*/
void num_complexo_printa(Num_Complexo* u);

/* função libera
** Libera a memoria de uma struct Num_Complexo de um
** número complexo z(a,b) = a+ib; Onde a = Re(z); b = Im(z);
*/
void num_complexo_libera(Num_Complexo* u);

/* função soma
** Soma dois números complexos z1(a,b) e z2(a,b);
*/
Num_Complexo* num_complexo_soma(Num_Complexo* u, Num_Complexo* v);

/* função subtrai
** Subtrai dois números complexos z1(a,b) e z2(a,b);
*/
Num_Complexo* num_complexo_subtrai(Num_Complexo* u, Num_Complexo* v);

/* função Multiplica
** Multiplica dois números complexos z1(a,b) e z2(a,b);
*/
Num_Complexo* num_complexo_multiplica(Num_Complexo* u, Num_Complexo* v);

/* função Divide
** Divide dois números complexos z1(a,b) e z2(a,b);
*/
Num_Complexo* num_complexo_divide(Num_Complexo* u, Num_Complexo* v);

#endif
