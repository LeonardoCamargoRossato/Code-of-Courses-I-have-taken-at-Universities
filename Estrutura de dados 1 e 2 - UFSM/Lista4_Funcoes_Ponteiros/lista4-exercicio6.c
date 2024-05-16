// LISTA 4 - lEONARDO CAMARGO ROSSATO //
// MATRICULA: 201613053 //
// #####   E X E R C I C I O - 06  #####//


#include <stdio.h>
#include <math.h>
#define PI  3.14159


int coeficiente (int n,int k)
{
    if((n > k) && (k > 0))
        return coeficiente(n - 1, k) + coeficiente(n - 1, k - 1);
    else
        return 1;
}
int main(void)
{
    int n1,k1;
    n1 = 5;
    k1 = 6;
    printf("\n Digite dois numeros inteiros para calcular o Binomio de Newton: \n ");
    // scanf("%d %d",&n1,&k1);

    coeficiente(n1,k1);
    printf("\nResultado Binomio De Newton: %d \n",coeficiente(n1,k1));


    return 0;
}
