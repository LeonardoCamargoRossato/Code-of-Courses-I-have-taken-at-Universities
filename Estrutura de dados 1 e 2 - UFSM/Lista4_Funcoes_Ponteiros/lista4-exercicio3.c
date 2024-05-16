// LISTA 4 - lEONARDO CAMARGO ROSSATO //
// MATRICULA: 201613053 //
// #####   E X E R C I C I O - 03 #####//


#include <stdio.h>
#include <math.h>
#define PI  3.14159

double raizes (double a, double b, double c)
{
    if (a==0.0)
    {
        double x1 = -c/b;
        printf("Uma raiz real: %lf \n",x1);
        return x1;
    }
    else
    {
        double delta = b*b - 4*a*c;
        if (delta<0)
        {
            printf("Raizes Reais Inexistentes. \n");
            double x2 = 0;
            return x2;
        }
        else if (delta == 0.0)
        {
            double x3 = -b/(2*a);
            printf(" Uma raiz real: %lf \n",x3);
            return x3;
        }
        else
        {
            delta = sqrt(delta);
            double r1 = (-b + delta)/(2*a);
            double r2 = (-b - delta)/(2*a);
            double x4 = r1+r2*0.0001;
            printf(" Duas raizes reais: %lf %lf \n",r1,r2);
            return x4;
        }

    }
}

double main(void)
{
    double a1,b1,c1;
    printf("Digite os coeficientes da equacao (a,b,c) : \n");
    scanf("%lf%lf%lf",&a1,&b1,&c1);

    raizes(a1,b1,c1);

    return 0;
}
