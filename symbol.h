#ifndef SYMBOL_H
#define SYMBOL_H


class Symbol
{
private:
    int value;
    char symbol;
    int priority;
public:
    Symbol(char newChar);
    Symbol(int newValue);
    Symbol();
    char getChar(){ return symbol; };
    int getValue(){ return value; };
    int getPriority(){ return priority; };
};

#endif // SYMBOL_H
