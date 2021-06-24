#include "calculatorwindow.h"
#include "ui_calculatorwindow.h"
#include "symbol.h"

CalculatorWindow::CalculatorWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CalculatorWindow)
{
    ui->setupUi(this);
    this->statusBar()->setSizeGripEnabled(false);
}

CalculatorWindow::~CalculatorWindow()
{
    delete ui;
}


void CalculatorWindow::on_Zero_clicked()
{

    expression += "0 ";
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Evaluate_clicked()
{
    ui->numberDisplay->setText(QString::fromStdString("1 + 2"));
}


void CalculatorWindow::on_One_clicked()
{
    expression += "1 ";
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Two_clicked()
{
    expression += "2 ";
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Three_clicked()
{
    expression += "3 ";
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Four_clicked()
{
    expression += "4 ";
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Five_clicked()
{
    expression += "5 ";
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Six_clicked()
{
    expression += "6 ";
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Seven_clicked()
{
    expression += "7 ";
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Eight_clicked()
{
    expression += "8 ";
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Nine_clicked()
{
    expression += "9 ";
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Add_clicked()
{
    expression += "+ ";
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Subtract_clicked()
{
    expression += "- ";
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Multiply_clicked()
{
    expression += "* ";
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Divide_clicked()
{
    expression += "/ ";
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_LeftBracket_clicked()
{
    expression += "( ";
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_RightBracket_clicked()
{
    expression += ") ";
    ui->numberDisplay->setText(expression);
}

