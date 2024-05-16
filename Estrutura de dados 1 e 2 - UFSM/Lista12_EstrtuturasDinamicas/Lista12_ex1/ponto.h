/* TAD: Ponto (x,y) */

/*Tipo exportado */
typedef struct ponto Ponto;

/*Funções exportadas */

/*Função cria
**Aloca e retorna um ponto com coord (x,y);
*/
Ponto* pto_cria(float x,float y);


/*Função libera
** Libera a memória de um ponto previamente criado;
*/
void pto_libera (Ponto* p);

/*Função Acessa
** Retorna os vaores das coord de um ponto;
*//* TAD: Ponto (x,y) */

/*Tipo exportado */
typedef struct ponto Ponto;
typedef struct ponto_polar Ponto_polar;

/*Funções exportadas */

/*Função cria
**Aloca e retorna um ponto com coord (x,y);
*/
Ponto* pto_cria(float x,float y);

/*Função pto_polar
**Aloca e retorna um ponto com coord Polares (r,teta);
*/
Ponto_polar* pto_criapolar(Ponto* p);

/*Função pto_raio
**Retorna o valor da coord. raio do ponto_polar;
*/
float pto_raio(Ponto* p);

/*Função pto_angulo
**Retorna o valor da coord. angular do ponto_polar;
*/
float pto_angulo(Ponto* p);


/*Função libera
** Libera a memória de um ponto previamente criado;
*/
void pto_libera (Ponto* p);

/*Função Acessa
** Retorna os vaores das coord de um ponto;
*/
void pto_acessa (Ponto* p, float* x, float* y);

/*Função Atribui
** Atribui novos valores às coordenadas de um ponto;
*/
void pto_atribui(Ponto* p,float x,float y);


/*Função Distancia
** Retorna a distância entre dois pontos;
*/
float pto_distancia(Ponto* p1, Ponto* p2);


void pto_acessa (Ponto* p, float* x, float* y);

/*Função Atribui
** Atribui novos valores às coordenadas de um ponto;
*/
void pto_atribui(Ponto*p,float x,float y);


/*Função Distancia
** Retorna a distância entre dois pontos;
*/
float pto_distancia(Ponto* p1, Ponto* p2);
