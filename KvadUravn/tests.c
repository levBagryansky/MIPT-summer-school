#include <stdio.h>
#pragma once
#include "functions_kvadratUravn.c"

const int infinity = -1;


void findDiscrTest(void);

void findDiscrTest(void)
{
    double a, b, c, d;
    a = 0; b = 0; c = 0;
    d = findDiscr(a, b, c);
    if(d == 0)
    {
        printf("Expected 0 and answer 0. All right \n");
    }
    else
    {
        printf("Expected 0, but there is %fl", d);
    }

    d = findDiscr(2, -5, -3);
    if( d - 49 <= 0.01 and 49 - d <= 0.01)
    {
        printf("All right");
    }
    else
    {
        printf("Expected 7 but there is %fl \n", d);
    }
}
