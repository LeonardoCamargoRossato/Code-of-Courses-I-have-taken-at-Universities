// LISTA 5 - lEONARDO CAMARGO ROSSATO //
// MATRICULA: 201613053 //
// #####   E X E R C I C I O - 01 #####//

#include <stdio.h>
#include <stdlib.h>

int MDC(int x, int y){
    int r;
    int cont;
    while(cont = 1){
        r = x % y;

        if(r == 0)
            return y;
        else {
            x = y;
            y = r;
        }
    ++cont;
    }
return (200*cont);
}

int main() {
    int x,y,cont;
    printf("Digite 2 numeros inteiros para calcular o MDC entre eles: \n --> ");
    scanf("%d%d",&x,&y);

    printf("\nMDC de %i e %i = %i\n", x, y, MDC(x, y));
    printf("contador : %d",cont);
    return 0;
}

