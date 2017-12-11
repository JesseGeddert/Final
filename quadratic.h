#ifndef QUADRATIC_H
#define QUADRATIC_H

class Quadratic
{
protected:
    double A;
    double B;
    double C;
    double x_re;
    double x_im;
    double radicand;

public:
    int TestForReal(double, double, double);    //determine whether roots are real or complex

    double FindRoot1(double, double, double);   //use if roots are real
    double FindRoot2(double, double, double);   //use if roots are real

    double FindRootRe(double, double);          //real part of complex root
    double FindRootIm(double, double, double);  //imaginary part of complex root (absolute value)
};

#endif // QUADRATIC_H
