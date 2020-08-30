#include <stdio.h>
#include <math.h>

int solve(double a, double b, double c, double* x1, double* x2);
double findDiscr(double a, double b, double c);

int main(){
    int nRoots;
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0, d = 0;
    printf("Enter coefficients a, b and c: \n");
    scanf ("%lg %lg %lg", &a, &b, &c);
    nRoots = solve(a, b, c, &x1, &x2);
    switch(nRoots){
        case 0:  printf("There is not any roots \n");
                break;

        case 1:  printf("x = %lg \n", x1);
                break;

        case 2:  printf("x1 = %lg and x2 = %lg \n", x1, x2);
                break;
        case -1: printf("There is infinite roots");
                break;

    }
}


int solve(double a, double b, double c, double* x1, double* x2)
{
    if(a == 0 and b == 0 and c == 0) // infinite
    {
        return -1;
    }
    else
    {
        double d = findDiscr(a, b, c);
        if(a == 0)                          // 1 root because a == 0
        {
            *x1 = -c/b;
            *x2 = *x1;
        return 1;
        }
        else
        {
            if(d < 0)                      // 0 roots
            {
                return 0;
            }
            else
            {
                if(d == 0)               // 1 root because d == 0
                {
                    *x1 = -b / (2*a);
                    *x2 = *x1;
                    return 1;
                }
                else                         // 2 roots
                {
                    *x1 = (-b - sqrt(d))/2;
                    *x2 = (-b + sqrt(d))/2;
                    return 2;
                }
            }
        }
    }
}


double findDiscr(double a, double b, double c)
{
    double discriminant = b*b - 4*a*c;
    printf("Discriminant of the equation: %.1f \n", discriminant);
    return discriminant;
}
