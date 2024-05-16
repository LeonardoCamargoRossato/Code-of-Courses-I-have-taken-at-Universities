// LISTA 6 - lEONARDO CAMARGO ROSSATO //
// MATRICULA: 201613053 //
// #####   E X E R C I C I O - 10 #####//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


void captura (int n, float* v){
    printf("Digite os valores do vetor: \n ---> ");

   // int n2 = random(n);

    for (int i=0;i<n;i++)
        scanf("%f",&v[i]);
}

void histograma (int n, float* v, float *h){

    float vet = 0.0;
    for (int i = 0; i<n; i++){

        vet = v[i];

        if ((vet >= 0.0) && (vet < 0.1)){
            float cont;
            cont = cont + 1.0;
            h[0]= cont;
        }
        else if ((vet >= 0.1) && (vet < 0.2)){
            float cont;
            cont = cont + 1.0;
            h[1]= cont;
        }
        else if ((vet >= 0.2) && (vet < 0.3)){
            float cont;
            cont = cont + 1.0;
            h[2]= cont;
        }
        else if ((vet >= 0.3) && (vet < 0.4)){
            float cont;
            cont = cont + 1.0;
            h[3]= cont;
        }
        else if ((vet >= 0.4) && (vet < 0.5)){
            float cont;
            cont = cont + 1.0;
            h[4]= cont;
        }
        else if ((vet >= 0.5) && (vet < 0.6)){
            float cont;
            cont = cont + 1.0;
            h[5]= cont;
        }
        else if ((vet >= 0.6) && (vet < 0.7)){
            float cont;
            cont = cont + 1.0;
            h[6]= cont;
        }
        else if ((vet >= 0.7) && (vet < 0.8)){
            float cont;
            cont = cont + 1.0;
            h[7]= cont;
        }
        else if ((vet >= 0.8) && (vet < 0.9)){
            float cont;
            cont = cont + 1.0;
            h[8]= cont;
        }
        else if ((vet >= 0.9) && (vet <= 1.0)){
            float cont;
            cont = cont + 1.0;
            h[9]= cont;
        }
        else{
            printf("Há um valor fora de V! \n Região possível: (0.0 <= v <= 1.0)");
            return 0;
        }

    }

    printf("\n\nValores de h: \n ---> h = {");
    for (int i=0;i<9;i++)
        printf("%.0f, ",h[i]);
    printf("%.0f} \n",h[9]);


}

void main(){
    int n;
    printf("\nDigite o tamanho do vetor: \n ---> ");
    scanf("%d",&n);

    float* v = (float*)calloc(n,sizeof(float));
    float* h = (float*)calloc(10,sizeof(char));

    captura(n,v);
    histograma(n,v,h);

    return 0;
}
