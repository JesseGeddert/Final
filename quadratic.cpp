#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <quadratic.h>

int Quadratic::TestForReal(double A, double B, double C)
{
    radicand = B*B - 4*A*C;
    if(radicand >= 0)
    {
        return 1;
    }
    if(radicand < 0)
    {
        return 0;
    }
    return 2;   //function shouldn't ever return 2
}

//called if roots are real
double Quadratic::FindRoot1(double A, double B, double C)
{
    x_re = (-B + sqrt(B*B - 4*A*C))/(2*A);
    return x_re;
}
double Quadratic::FindRoot2(double A, double B, double C)
{
    x_re = (-B - sqrt(B*B - 4*A*C))/(2*A);
    return x_re;
}

//called if roots are complex
double Quadratic::FindRootRe(double A, double B)
{
    x_re = -B/(2*A);
    return x_re;
}
double Quadratic::FindRootIm(double A, double B, double C)
{
    x_im = sqrt(-1*(B*B - 4*A*C))/(2*A);
    if(x_im < 0)    x_im *= -1;     //take absolute value
    return x_im;
}


