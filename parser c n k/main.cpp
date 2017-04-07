#include "Header.h"
#include "Printer.h"
#include "Calk.h"
int main() {
    Printer printer = Printer();
    Calk calk = Calk();
    string st = "c(1+c((4+3/4),c(1,1)*2), 1)+3";
    Expression *expr = calk.parse(st);
    int x = expr->evaluate();
    cout << "@!!! " << x << "\n";
    printer.printString(expr);
    printer.printScreen();
    return 0;
}