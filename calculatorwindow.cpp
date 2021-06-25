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
    list.append(Symbol(0));
    ui->numberDisplay->setText(expression);
}

void CalculatorWindow::on_One_clicked()
{
    expression += "1";
    list.append(Symbol(1));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Two_clicked()
{
    expression += "2";
    list.append(Symbol(2));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Three_clicked()
{
    expression += "3";
    list.append(Symbol(3));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Four_clicked()
{
    expression += "4";
    list.append(Symbol(4));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Five_clicked()
{
    expression += "5";
    list.append(Symbol(5));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Six_clicked()
{
    expression += "6";
    list.append(Symbol(6));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Seven_clicked()
{
    expression += "7";
    list.append(Symbol(7));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Eight_clicked()
{
    expression += "8";
    list.append(Symbol(8));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Nine_clicked()
{
    expression += "9";
    list.append(Symbol(9));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Add_clicked()
{
    expression += " + ";
    list.append(Symbol('+'));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Subtract_clicked()
{
    expression += " - ";
    list.append(Symbol('-'));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Multiply_clicked()
{
    expression += " * ";
    list.append(Symbol('*'));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Divide_clicked()
{
    expression += " / ";
    list.append(Symbol('/'));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_LeftBracket_clicked()
{
    expression += "(";
    list.append(Symbol('('));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_RightBracket_clicked()
{
    expression += ")";
    list.append(Symbol(')'));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_backspace_clicked()
{
//    expression.chop(1);
//    if (!list.isEmpty()){
//        list.removeLast();
//    }
//    ui->numberDisplay->setText(expression);
//    std::cout << typeid(list.at(0).getChar()).name() << std::endl;
//    std::cout << list.at(0).getChar() << std::endl;
//    std::cout << typeid(list.at(0).getValue()).name() << std::endl;
    if (list.at(0).isCharacter()){
        std::cout << "its a character!" << std::endl;
    } else if (list.at(0).isNumber()){
        std::cout << "its a number!" << std::endl;
    }
}

void CalculatorWindow::convertToPostfix(){
    int i = 0;
    while(!list.isEmpty()){
        Symbol cur = list.at(i);
    }
}

