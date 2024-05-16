#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  char nome[81];
  float valorHora;
  int horasMes;
} Funcionario;

void carrega(int n, Funcionario** vet, char* arquivo){
    char buffer[81];
    FILE* inputFile = fopen(arquivo, "rt");

    if(inputFile == NULL){
        printf("Impossivel abrir o arquivo %s\n", arquivo);
        exit(1);
    }

    for(int i = 0; i < n; i++){

        fgets(buffer, 80, inputFile);
        strcpy(vet[i]->nome, buffer);

        fgets(buffer, 80, inputFile);
        sscanf(buffer, "%f %i", &vet[i]->valorHora, &vet[i]->horasMes);

    }
}

int main(int argc, const char** argv){

    // Verifies given arguments
    if(argc != 3){
        printf("Uso correto: ./Ex3 <ArquivoTexto> <QTD Funcionarios>\n");
        exit(1);
    }

    // Sets arguments for carrega()
    int n = strtol(argv[2], NULL, 10);
    Funcionario* vet = malloc(n * sizeof(Funcionario));
    char* arquivo = argv[1];

    // Parses given text file
    carrega(n, &vet, arquivo);

    free(vet);

    return 0;
}
