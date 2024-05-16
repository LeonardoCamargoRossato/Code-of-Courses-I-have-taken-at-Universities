// LISTA 4 - lEONARDO CAMARGO ROSSATO //
// MATRICULA: 201613053 //
// #####   E X E R C I C I O - 01 #####//


#include <stdio.h>

#define PI  3.14159

// raio = r; altura = h

float vol_cilindro(float r_cilindro, float h_cilindro)
{
    float v_cilindro;
    v_cilindro = PI * r_cilindro * h_cilindro;
    return v_cilindro;
}

float vol_esfera(float r_esfera, float h_esfera)
{
    float v_esfera;
    v_esfera = ((PI * h_esfera * h_esfera)/3)*(3*r_esfera - h_esfera);
    return v_esfera;
}

int main(void)
{
    float raio_cilindro,raio_esfera,altura,volume;
    printf("Digite valor do Raio e ALtura do Cilindro: \n");
    scanf("%f %f",&raio_cilindro,&altura);

    printf("Digite valor do Raio da Calota Esferica: \n");
    scanf("%f",&raio_esfera);

    volume = (vol_esfera(raio_esfera,altura)) - (vol_cilindro(raio_cilindro,altura));

    printf("Volume Objeto (Calota Esférica - Cilindro Central) = %f \n", volume);
    return 0;
}
