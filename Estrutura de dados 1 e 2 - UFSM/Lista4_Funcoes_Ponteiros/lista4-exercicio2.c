// LISTA 4 - lEONARDO CAMARGO ROSSATO //
// MATRICULA: 201613053 //
// #####   E X E R C I C I O - 02 #####//


#include <stdio.h>

#define PI  3.14159

int mdc(int x,int y)
{
    int r = x % y;
    if (r == 0)
        return y;
    else
        return mdc(y,r);
}
int main(void)
{
    int x1,x2,x3;
    printf("Digite 3 numeros inteiros: \n");
    scanf("%d%d%d",&x1,&x2,&x3);


    printf("MDC = %d \n", mdc(mdc(x1,x2),x3) );
    return 0;
}
