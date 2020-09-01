#include <stdio.h>
#include <math.h>

const int infinity = -1; // if there are infinity roots

int solveSQW(double a, double b, double c, double* x1, double* x2);
int solveLN(double b, double c, double* x1, double* x2); // bx + c = 0
double findDiscr(double a, double b, double c);
int choseFunction(double a, double b, double c, double* x1, double* x2);

int main(){
    int nRoots;
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    printf("Enter coefficients a, b and c: \n");
    scanf ("%lg %lg %lg", &a, &b, &c);
    nRoots = choseFunction(a, b, c, &x1, &x2);
    switch(nRoots){
        case 0:  printf("There is not any roots \n");
                break;

        case 1:  printf("x = %lg \n", x1);
                break;

        case 2:  printf("x1 = %lg and x2 = %lg \n", x1, x2);
                break;
        case infinity: printf("There is infinite roots");
                break;

    }
}


int solveSQW(double a, double b, double c, double* x1, double* x2)
{
    double d = findDiscr(a, b, c);

    if(d < 0)                      // 0 roots
    {
        return 0;
    }

    else if(d == 0)               // 1 root because d == 0
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


int solveLN(double b, double c, double* x1, double* x2)
{
    if(b == 0 and c == 0)             // infinite 0x + 0 = 0
    {
        return infinity;
    }

    else if(b == 0)                   // for example 0x + 5 = 0
    {
        return 0;
    }

    else                              // bx + c = 0
    {
        *x1 = -c/b;
        *x2 = *x1;
    return 1;
    }
}


double findDiscr(double a, double b, double c)
{
    double discriminant = b*b - 4*a*c;
    return discriminant;
}

int choseFunction(double a, double b, double c, double* x1, double* x2)
{
    if(a == 0){
        int nRoots = solveLN(b, c, x1, x2);
        return nRoots;
    }

    else
    {
        int nRoots = solveSQW(a, b, c, x1, x2);
        return nRoots;
    }
}
