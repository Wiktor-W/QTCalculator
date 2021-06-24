#ifndef CALCULATORWINDOW_H
#define CALCULATORWINDOW_H

#include <QMainWindow>
#include <QStack>
#include <symbol.h>

QT_BEGIN_NAMESPACE
namespace Ui { class CalculatorWindow; }
QT_END_NAMESPACE

class CalculatorWindow : public QMainWindow
{
    Q_OBJECT

public:
    CalculatorWindow(QWidget *parent = nullptr);
    ~CalculatorWindow();

private slots:
    void on_Zero_clicked();

    void on_Evaluate_clicked();

    void on_One_clicked();

    void on_Two_clicked();

    void on_Three_clicked();

    void on_Four_clicked();

    void on_Five_clicked();

    void on_Six_clicked();

    void on_Seven_clicked();

    void on_Eight_clicked();

    void on_Nine_clicked();

    void on_Add_clicked();

    void on_Subtract_clicked();

    void on_Multiply_clicked();

    void on_Divide_clicked();

    void on_LeftBracket_clicked();

    void on_RightBracket_clicked();

private:
    Ui::CalculatorWindow *ui;
    QString expression;
    QStack<Symbol> stack;
};
#endif // CALCULATORWINDOW_H
