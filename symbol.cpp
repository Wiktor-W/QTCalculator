#include "symbol.h"

Symbol::Symbol(char newSymbol)
{
    switch (newSymbol) {
      case '(':
        symbol = newSymbol;
        priority = 1;
        isNum = false;
        isChar = true;
        break;
      case ')':
        symbol = newSymbol;
        priority = 1;
        isNum = false;
        isChar = true;
        break;
      case '/':
        symbol = newSymbol;
        priority = 2;
        isNum = false;
        isChar = true;
        break;
      case '*':
        symbol = newSymbol;
        priority = 3;
        isNum = false;
        isChar = true;
        break;
      case '+':
        symbol = newSymbol;
        priority = 4;
        isNum = false;
        isChar = true;
        break;
      case '-':
        symbol = newSymbol;
        priority = 5;
        isNum = false;
        isChar = true;
        break;
      default:
        symbol = newSymbol;
        priority = 0;
    }
}
Symbol::Symbol(int newValue)
{
    value = newValue;
    isNum = true;
    isChar = false;
}
Symbol::Symbol(){
    value = 0;
}

