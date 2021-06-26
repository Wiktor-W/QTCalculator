#ifndef SYMBOL_H
#define SYMBOL_H
#include <string>

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
    std::string charToString() const { return "" + symbol; }
    std::string intToString() const { return "" + value; }
};

#endif // SYMBOL_H
