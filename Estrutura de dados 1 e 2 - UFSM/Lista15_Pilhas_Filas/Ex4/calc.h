typedef struct calc Calc;

Calc* cria_calc(void);
void operando_calc(Calc* c, float v);
void operador_calc(Calc* c, char op);
void libera_calc(Calc* c);
