#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[81];
    float valorHora;
    int horasMes;
} Funcionario;

int comp(Funcionario* a, Funcionario* b){
    float valorA = (a->valorHora) * ( (float) a->horasMes);
    float valorB = (b->valorHora) * ( (float) b->horasMes);

    if(valorA > valorB)
        return 1;
    if(valorA < valorB)
        return -1;
    else
        return 0;

}

void imprimeMarajas(int n, Funcionario** vet){

    qsort(vet[0], n, sizeof(Funcionario), comp);

    for(int i = n - 1 ; i > n - 6 && i >= 0; i--)
        printf("%s %f %i\n", vet[i]->nome, ((int) (vet[i]->horasMes)) * (vet[i]->valorHora), i);

}

int main(){
    Funcionario** testVector = malloc(9 * sizeof(Funcionario*));

    testVector[0] = &((Funcionario) {.nome = "Carlos", .horasMes = 40, .valorHora = 9});
    testVector[1] = &((Funcionario) {.nome = "Daniel", .horasMes = 40, .valorHora = 8});
    testVector[2] = &((Funcionario) {.nome = "Emilio", .horasMes = 40, .valorHora = 7});
    testVector[3] = &((Funcionario) {.nome = "Fernando", .horasMes = 40, .valorHora = 6});
    testVector[4] = &((Funcionario) {.nome = "Gustavo", .horasMes = 40, .valorHora = 5});
    testVector[5] = &((Funcionario) {.nome = "Heitor", .horasMes = 40, .valorHora = 4});
    testVector[6] = &((Funcionario) {.nome = "Igor", .horasMes = 40, .valorHora = 3});
    testVector[7] = &((Funcionario) {.nome = "Joao", .horasMes = 40, .valorHora = 2});
    testVector[8] = &((Funcionario) {.nome = "Kleber", .horasMes = 40, .valorHora = 1});

    imprimeMarajas(9, testVector);

    free(testVector);

    return 0;
}
