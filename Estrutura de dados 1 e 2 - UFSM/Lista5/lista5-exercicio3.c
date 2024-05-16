// LISTA 5 - lEONARDO CAMARGO ROSSATO //
// MATRICULA: 201613053 //
// #####   E X E R C I C I O - 03 #####//

#include <stdio.h>
#include <stdlib.h>

int Fibonacci(int i){

    if(i < 2)
        return i;
    else{
        int a = 0, b = 1;
        for(int j = 0; j <= i; j++) {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
}

int main() {
    int n, x;
    printf("Digite quantos 'n' termos vc quer da sequencia de Fibonacci \n e digite numero 'x' para saber se pertence ou não a serie: \n --> ");
    scanf("%d%d",&n,&x);

    printf("\nEsses são os %i primeiros termos da serie de Fibonacci: \n--> [", n);


    for(int i = 0; i < n; i++) // Letra A: Imprimir os primeiros "n" termos da serie de Fibonacci
        printf("%i, ", Fibonacci(i));
    printf("\b\b]\n");


    for(int i = 0;  ; i++)  // Letra B: Determinar se "x" pertence ou nao a serie de Fibonacci
        if(Fibonacci(i) < x)
            continue;
        else if(Fibonacci(i) == x){
            printf("\n--> %i e o %iº elemento da serie de Fibonacci\n", x, i);
            break;}
        else{
            printf("\n--> %i nao pertence a serie de Fibonacci\n", x);
            break;}

    return 0;
}
