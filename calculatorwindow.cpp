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
    if (numInputBuff != ""){
        inputQueue.append(Symbol(numInputBuff.toFloat()));
        numInputBuff = "";
    }
    convertToPostfix();
    evaluateReversePolish();
    std::cout << "evaluated:" << std::endl;
    std::cout << expression.toStdString() << std::endl;
}

void CalculatorWindow::on_Zero_clicked()
{
    expression += "0";
    numInputBuff.append("0");
    ui->numberDisplay->setText(expression);
}

void CalculatorWindow::on_One_clicked()
{
    expression += "1";
    numInputBuff.append("1");
    ui->numberDisplay->setText(expression);
}

void CalculatorWindow::on_Two_clicked()
{
    expression += "2";
    numInputBuff.append("2");
    ui->numberDisplay->setText(expression);
}

void CalculatorWindow::on_Three_clicked()
{
    expression += "3";
    numInputBuff.append("3");
    ui->numberDisplay->setText(expression);
}

void CalculatorWindow::on_Four_clicked()
{
    expression += "4";
    numInputBuff.append("4");
    ui->numberDisplay->setText(expression);
}

void CalculatorWindow::on_Five_clicked()
{
    expression += "5";
    numInputBuff.append("5");
    ui->numberDisplay->setText(expression);
}

void CalculatorWindow::on_Six_clicked()
{
    expression += "6";
    numInputBuff.append("6");
    ui->numberDisplay->setText(expression);
}

void CalculatorWindow::on_Seven_clicked()
{
    expression += "7";
    numInputBuff.append("7");
    ui->numberDisplay->setText(expression);
}

void CalculatorWindow::on_Eight_clicked()
{
    expression += "8";
    numInputBuff.append("8");
    ui->numberDisplay->setText(expression);
}

void CalculatorWindow::on_Nine_clicked()
{
    expression += "9";
    numInputBuff.append("9");
    ui->numberDisplay->setText(expression);
}

void CalculatorWindow::on_Add_clicked()
{
    expression += " + ";
    if (!numInputBuff.isEmpty()){
        inputQueue.append(Symbol(numInputBuff.toFloat()));
        numInputBuff = "";
    }
    inputQueue.append(Symbol('+'));
    ui->numberDisplay->setText(expression);
}

void CalculatorWindow::on_Subtract_clicked()
{
    expression += " - ";
    if (!numInputBuff.isEmpty()){
        inputQueue.append(Symbol(numInputBuff.toFloat()));
        numInputBuff = "";
    }
    inputQueue.append(Symbol('-'));
    ui->numberDisplay->setText(expression);
}

void CalculatorWindow::on_Multiply_clicked()
{
    expression += " * ";
    if (!numInputBuff.isEmpty()){
        inputQueue.append(Symbol(numInputBuff.toFloat()));
        numInputBuff = "";
    }
    inputQueue.append(Symbol('*'));
    ui->numberDisplay->setText(expression);
}

void CalculatorWindow::on_Divide_clicked()
{
    expression += " / ";
    if (numInputBuff != ""){
        inputQueue.append(Symbol(numInputBuff.toFloat()));
        numInputBuff = "";
    }
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
    if (numInputBuff != ""){
        inputQueue.append(Symbol(numInputBuff.toFloat()));
        numInputBuff = "";
    }
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

void CalculatorWindow::evaluateReversePolish(){
    Symbol cur;
    while (!outputQueue.isEmpty()){
        while(!outputQueue.head().isCharacter()){
            cur = outputQueue.dequeue();
            operatorStack.push(cur);
        }
        float value2 = operatorStack.pop().getValue();
        float value1 = operatorStack.pop().getValue();
        cur = outputQueue.dequeue();
        switch (cur.getChar()) {
            case '+':
              operatorStack.push(value1 + value2);
              break;
            case '-':
              operatorStack.push(value1 - value2);
              break;
            case '*':
              operatorStack.push(value1 * value2);
              break;
            case '/':
              operatorStack.push(value1 / value2);
              break;
            default:
              std::cout << "An error has occured" << std::endl;
        }
        if (operatorStack.size() == 1){
            expression = QString::fromStdString(std::to_string(operatorStack.pop().getValue()));
            if (expression.contains('.')){
                while(expression.back() == '0'){
                    expression.chop(1);
                }
                if(expression.back() == '.'){
                    expression.chop(1);
                }
            }
            ui->numberDisplay->setText(expression);
        }
    }
}

