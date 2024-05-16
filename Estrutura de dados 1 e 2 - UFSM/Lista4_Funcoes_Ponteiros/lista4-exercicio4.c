// LISTA 4 - lEONARDO CAMARGO ROSSATO //
// MATRICULA: 201613053 //
// #####   E X E R C I C I O - 04 #####//


#include <stdio.h>
#include <math.h>
#define PI  3.14159


double pot (double x,int k)
{
    double r;

    if (k>0)
        return x*pot(x,k-1);

    else if (k<0)
        return (1/x)*pot(x,k+1);

    else
        return 1;

}
double main(void)
{
    double x1,k1;
    printf("\n *Potenciaçao Recursiva: x^k . \n\nDigite o valor 'x' que voce quer elevar e o valor do expoente 'k': \n ");
    scanf("%lf %lf",&x1,&k1);

    pow(x1,k1);
    printf("\nResultado da potenciaçao recursiva: %lf \n",pot(x1,k1));
    printf("Valor obtido pela funcao 'pow' padrao: %lf \n",pow(x1,k1));

    return 0;
}
