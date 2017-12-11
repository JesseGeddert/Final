#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDoubleValidator>
#include <quadratic.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    Quadratic* eq;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QDoubleValidator* A_validator;
    QDoubleValidator* B_validator;
    QDoubleValidator* C_validator;

public slots:
    void CalculateButtonClicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
