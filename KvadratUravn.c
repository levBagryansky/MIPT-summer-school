#include <stdio.h>
#include <math.h>

int solve(double a, double b, double c, double x1, double x2)
{
    double d = b*b - 4*a*c;
    if(d < 0)
    {
        return 0;
    }
    else
    {
        if(d == 0)
        {
            x1 = -b / (2*a);
            x2 = x1;
            return 1;
        }
        else
        {
            x1 = (-b - sqrt(d))/2;
            x2 = (-b + sqrt(d))/2;
            return 2;
        }
    }
}

int main(){
    int nRoots;
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    scanf ("%lg %lg %lg", &a, &b, &c);
    nRoots = solve(a, b, c, x1, x2);
    switch(nRoots){
        case 0: printf("There is not any roots \n");
        case 1: printf("x = %lg \n", x1);
        case 2: printf("x1 = %lg and x2 = %lg \n", x1, x2);
    }

}
