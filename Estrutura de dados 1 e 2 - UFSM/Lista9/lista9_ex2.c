#include <stdio.h>
#include <stdlib.h>

typedef struct vetor Vetor;
struct vetor{
  float x; float y; float z;
};

void captura(Vetor* v1,Vetor* v2){
  printf("\nDigite os vetores: v1:(x,y,z) ; v2:(x,y,z) \n --> ");
  scanf("%f %f %f %f %f %f", &v1->x,&v1->y,&v1->z,&v2->x,&v2->y,&v2->z);
}

float escalar (Vetor* v1,Vetor* v2){
  float X = v1->x + v2->x;
  float Y = v1->y + v2->y;
  float Z = v1->z + v2->z;
  float XYZ = X+Y+Z;
  return XYZ;
}

int main(){
  printf("\n\n#Função:Calcula Produto Escalar de Vetores 3D\n");
  Vetor* v1 = (struct vetor*)malloc(sizeof(struct vetor));
  Vetor* v2 = (struct vetor*)malloc(sizeof(struct vetor));

  captura(v1,v2);
  float XYZ_main = escalar(v1,v2);
  printf("Produto Escalar v1 * v2 = %.2f \n\n",XYZ_main);

  return 0;
}
