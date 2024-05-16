// LISTA 5 - lEONARDO CAMARGO ROSSATO //
// MATRICULA: 201613053 //
// #####   E X E R C I C I O - 02 #####//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool Primo(int n){

    if(n == 2)
        return true;
    else if(n < 2 || n % 2 == 0)
        return false;
    else
        for(int i = 3; i <= sqrt(n); i++)
            if(n % i == 0)
                return false;

    return true;
}

int main() {
    int n, x;
    printf("Digite um numero 'x' para descobrir todos os primos menores que 'x'\nDigite 'n' saber os primeiros primos até 'n' \n --> ");
	scanf("%d %d",&n,&x);


    // Resposta da letra (a) - Imprimir todos os numeros primos menores que um valor "x"
    printf("Numeros primos < %i: [", x);
    for(int i = 0; i < x; i++)
        if(Primo(i))
            printf("%i, ", i);
    printf("\b\b]\n");

    // Resposta da letra (b) - Imprimir os primeiros "n" numeros primos
    printf("%i primeiros numeros primos: [", n);
    for(int i = 0; n > 0; i++)
        if(Primo(i)) {
            printf("%i, ", i);
            n--;
        }
    printf("\b\b]\n");

    return 0;
}
