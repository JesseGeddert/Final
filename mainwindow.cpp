#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    eq = new Quadratic;

    A_validator = new QDoubleValidator(-9999, 9999, 4, NULL);
    ui->A_text->setValidator(A_validator);
    B_validator = new QDoubleValidator(-9999, 9999, 4, NULL);
    ui->B_text->setValidator(B_validator);
    C_validator = new QDoubleValidator(-9999, 9999, 4, NULL);
    ui->C_text->setValidator(C_validator);
}

MainWindow::~MainWindow()
{
    delete ui;

    delete A_validator;
    delete B_validator;
    delete C_validator;
}

void MainWindow::CalculateButtonClicked()
{
    //acquire coefficients
    QString Atext = ui->A_text->text();
    float A = Atext.toDouble();
    QString Btext = ui->B_text->text();
    float B = Btext.toDouble();
    QString Ctext = ui->C_text->text();
    float C = Ctext.toDouble();

    int real;       //1 if roots are real, 0 if roots are complex
    double x1_re;   //real part of first root
    double x1_im;   //imaginary part of first root
    double x2_re;   //real part of second root
    double x2_im;   //imaginary part of second root

    real = eq->TestForReal(A, B, C);    //are the roots real or complex?

    QString RealRoot("x = %1");         //use for real roots, or real part of complex roots
    QString ComplexRoot1("+ %1 i");     //use for imaginary part of first complex root
    QString ComplexRoot2("- %1 i");     //use for imaginary part of second complex root

    if(real == 1)   //roots are real
    {
        x1_re = eq->FindRoot1(A, B, C);                 //calculate first root
        ui->root1_label->setText(RealRoot.arg(x1_re));  //print first root
        ui->root1_im_label->setText("");    //display nothing in imaginary component

        x2_re = eq->FindRoot2(A, B, C);                 //calculate second root
        ui->root2_label->setText(RealRoot.arg(x2_re));  //print second root
        ui->root2_im_label->setText("");    //display nothing in imaginary component
    }

    if(real == 0)   //roots are complex
    {
        x1_re = eq->FindRootRe(A, B);       //calculate real part of first root
        x1_im = eq->FindRootIm(A, B, C);    //calculate absolute value of imaginary part of first root
        ui->root1_label->setText(RealRoot.arg(x1_re));          //print real part
        ui->root1_im_label->setText(ComplexRoot1.arg(x1_im));   //print  + |imaginary part|

        x2_re = eq->FindRootRe(A, B);       //calculate real part of second root
        x2_im = eq->FindRootIm(A, B, C);    //calculate absolute value of imaginary part of second root
        ui->root2_label->setText(RealRoot.arg(x2_re));          //print real part
        ui->root2_im_label->setText(ComplexRoot2.arg(x2_im));   //print  - |imaginary part|
    }
}
