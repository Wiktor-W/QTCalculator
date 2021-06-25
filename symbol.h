#ifndef SYMBOL_H
#define SYMBOL_H


class Symbol
{
private:
    int value;
    char symbol;
    int priority;
    bool isNum;
    bool isChar;
public:
    Symbol(char newChar);
    Symbol(int newValue);
    Symbol();
    char getChar() const { return symbol; };
    int getValue() const { return value; };
    int getPriority() const { return priority; };
    bool isNumber() const { return isNum; };
    bool isCharacter() const { return isChar; };
};

#endif // SYMBOL_H
