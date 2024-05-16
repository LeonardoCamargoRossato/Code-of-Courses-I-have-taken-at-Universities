// LISTA 4 - lEONARDO CAMARGO ROSSATO //
// MATRICULA: 201613053 //
// #####   E X E R C I C I O - 05 #####//


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI  3.14159

int fibonacci (int i)
{
    if ((i == 0) || (i == 1)){
        printf("caso1: %d \n",i);
        return i;}
    else{
        printf("caso2: %d \n",i);
        return fibonacci(i - 1) + fibonacci(i - 2);}

}
int main (void)
{
    int x;
    printf("Digite o primeiro numero da sequencia de fibonacci: ");
    scanf("%d",&x);
    fibonacci(x);

    printf("\n \n Sequencia 'i' : %d \n\n",fibonacci (x));

    return 0;
}
