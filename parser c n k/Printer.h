//
// Created by Python on 27.03.2017.
//

#ifndef UNTITLED2_PRINTER_H
#define UNTITLED2_PRINTER_H

#include "Header.h"

class Printer {
public:
    Printer();

    void printString(Expression *expr);

    void printScreen();

    void printLetter(char c);

private:
    map<char, vector<string> > dictionary;

    vector<vector<char> > screen;
    int n, m;

    void setChar(int scale, char c, pair<int, int> cur);

    int getMax(Expression *expr);

    void setSize(Expression *expr, int mx);

    void dfs3(Expression *expr, pair<int, int> pos);

};


#endif //UNTITLED2_PRINTER_H
