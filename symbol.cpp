#include "symbol.h"

Symbol::Symbol(char newSymbol)
{
    switch (newSymbol) {
      case '(':
        symbol = newSymbol;
        priority = 1;
        break;
      case ')':
        symbol = newSymbol;
        priority = 1;
        break;
      case '/':
        symbol = newSymbol;
        priority = 2;
        break;
      case '*':
        symbol = newSymbol;
        priority = 3;
        break;
      case '+':
        symbol = newSymbol;
        priority = 4;
        break;
      case '-':
        symbol = newSymbol;
        priority = 5;
        break;
      default:
        symbol = newSymbol;
        priority = 0;
    }
}
Symbol::Symbol(int newValue)
{
    value = newValue;
}
Symbol::Symbol(){
    value = 0;
}

