#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
  {
  int r;
  volta: for(int i = 0; i<5; i++){
    r = rand()%11;
    RAND_MAX;
    srand( (unsigned)time(NULL) );
    if (r<=5){printf("Numero: %d\n", r); break;}
  }
  if (r>5){ goto volta;}
}
