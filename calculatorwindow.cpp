#include "calculatorwindow.h"
#include "ui_calculatorwindow.h"
#include "symbol.h"
#include <iostream>
#include <string>

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
    convertToPostfix();
    std::cout << "converted to postfix: " << std::endl;
    printPostfix();
    ui->numberDisplay->setText(QString::fromStdString("3"));
}

void CalculatorWindow::on_Zero_clicked()
{
    expression += "0";
    inputQueue.append(Symbol(0));
    ui->numberDisplay->setText(expression);
}

void CalculatorWindow::on_One_clicked()
{
    expression += "1";
    inputQueue.append(Symbol(1));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Two_clicked()
{
    expression += "2";
    inputQueue.append(Symbol(2));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Three_clicked()
{
    expression += "3";
    inputQueue.append(Symbol(3));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Four_clicked()
{
    expression += "4";
    inputQueue.append(Symbol(4));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Five_clicked()
{
    expression += "5";
    inputQueue.append(Symbol(5));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Six_clicked()
{
    expression += "6";
    inputQueue.append(Symbol(6));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Seven_clicked()
{
    expression += "7";
    inputQueue.append(Symbol(7));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Eight_clicked()
{
    expression += "8";
    inputQueue.append(Symbol(8));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Nine_clicked()
{
    expression += "9";
    inputQueue.append(Symbol(9));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Add_clicked()
{
    expression += " + ";
    inputQueue.append(Symbol('+'));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Subtract_clicked()
{
    expression += " - ";
    inputQueue.append(Symbol('-'));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Multiply_clicked()
{
    expression += " * ";
    inputQueue.append(Symbol('*'));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_Divide_clicked()
{
    expression += " / ";
    inputQueue.append(Symbol('/'));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_LeftBracket_clicked()
{
    expression += "(";
    inputQueue.append(Symbol('('));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_RightBracket_clicked()
{
    expression += ")";
    inputQueue.append(Symbol(')'));
    ui->numberDisplay->setText(expression);
}


void CalculatorWindow::on_backspace_clicked()
{
    expression.chop(1);
    if (!inputQueue.isEmpty()){
        inputQueue.removeLast();
    }
    ui->numberDisplay->setText(expression);
}

//No parameters as there is only one input that can be converted to postfix
void CalculatorWindow::convertToPostfix(){
    int i = 0;
    //for (int j = 0; j < )
    while(!inputQueue.isEmpty()){
        Symbol cur = inputQueue.dequeue();
        if (cur.isNumber()){
             outputQueue.enqueue(cur);
        } else if (cur.isCharacter() && cur.getChar() != '('){
            if (!operatorStack.isEmpty()){
                while(operatorStack.top().getPriority() > cur.getPriority()){
                    Symbol stackOperator = operatorStack.pop();
                    outputQueue.enqueue(stackOperator);
                }
            }
            operatorStack.push(cur);
        } else if (cur.isCharacter() && cur.getChar() == '('){
            operatorStack.push(cur);
        } else if (cur.isCharacter() && cur.getChar() == ')'){
            if (!operatorStack.isEmpty()){
                while (operatorStack.top().getChar() != '('){
                    Symbol stackOperator = operatorStack.pop();
                    outputQueue.enqueue(stackOperator);
                }
                operatorStack.pop();
            }
        }
        i++;
    }
    while (!operatorStack.isEmpty()){
        Symbol stackOperator = operatorStack.pop();
        outputQueue.enqueue(stackOperator);
    }
}

void CalculatorWindow::printPostfix(){
    std::cout << "converted to postfix: " << std::endl;
    while (!outputQueue.isEmpty()){
        Symbol cur = outputQueue.dequeue();
        if (cur.isCharacter()){
            std::cout << cur.getChar() << std::endl;
        } else if (cur.isNumber()){
            std::cout << cur.getValue() << std::endl;
        }
    }
}

