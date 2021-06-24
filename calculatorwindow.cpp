#include "calculatorwindow.h"
#include "ui_calculatorwindow.h"
#include "symbol.h"
#include <iostream>

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

void CalculatorWindow::on_Evaluate_clicked()
{
    ui->numberDisplay->setText(QString::fromStdString("1 + 2"));
}

void CalculatorWindow::on_Zero_clicked()
{
    expression += "0";
    stack.push(Symbol(0));
    ui->numberDisplay->setText(expression);
}

void CalculatorWindow::on_One_clicked()
{
    expression += "1";
    stack.push(Symbol(1));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Two_clicked()
{
    expression += "2";
    stack.push(Symbol(2));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Three_clicked()
{
    expression += "3";
    stack.push(Symbol(3));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Four_clicked()
{
    expression += "4";
    stack.push(Symbol(4));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Five_clicked()
{
    expression += "5";
    stack.push(Symbol(5));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Six_clicked()
{
    expression += "6";
    stack.push(Symbol(6));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Seven_clicked()
{
    expression += "7";
    stack.push(Symbol(7));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Eight_clicked()
{
    expression += "8";
    stack.push(Symbol(8));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Nine_clicked()
{
    expression += "9";
    stack.push(Symbol(9));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Add_clicked()
{
    expression += "+";
    stack.push(Symbol('+'));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Subtract_clicked()
{
    expression += "-";
    stack.push(Symbol('-'));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Multiply_clicked()
{
    expression += "*";
    stack.push(Symbol('*'));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Divide_clicked()
{
    expression += "/";
    stack.push(Symbol('/'));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_LeftBracket_clicked()
{
    expression += "(";
    stack.push(Symbol('('));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_RightBracket_clicked()
{
    expression += ")";
    stack.push(Symbol(')'));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_backspace_clicked()
{
    expression.chop(1);
    if (!stack.isEmpty()){
        stack.pop();
    }
    ui->numberDisplay->setText(expression);
}

