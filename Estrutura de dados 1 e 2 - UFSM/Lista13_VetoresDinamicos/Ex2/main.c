#include <stdio.h>
#include <stdlib.h>
#include "stringd.h"


StrDin* le_texto (char *arquivo)
{
    FILE* f = fopen(arquivo,"rt");
    if (f == NULL) return NULL;
    StrDin* s = sd_criavazia();
    char buffer[120];
    while(fgets(buffer,120,f) != NULL) sd_concatena(s,buffer);
    fclose(f);
    return s;
}

int main()
{
    StrDin* s = le_texto ("alunos.txt");
    printf("%s\n",sd_acessa(s));
    printf("Tamanho da String = %d\n",sd_dimensao(s));
    sd_libera(s);
    return 0;
}
