#ifndef SYMBOL_H
#define SYMBOL_H
#include <string>

class Symbol
{
private:
    float value;
    char symbol;
    int priority;
    bool isNum;
    bool isChar;
public:
    Symbol(char newChar);
    Symbol(float newValue);
    Symbol();
    char getChar() const { return symbol; };
    float getValue() const { return value; };
    int getPriority() const { return priority; };
    bool isNumber() const { return isNum; };
    bool isCharacter() const { return isChar; };
    std::string symbolToString() const { return std::to_string(symbol); }
    std::string valueToString() const { return std::to_string(value); }
};

#endif // SYMBOL_H
