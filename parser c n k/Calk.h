//
// Created by Python on 28.03.2017.
//

#ifndef UNTITLED2_CALK_H
#define UNTITLED2_CALK_H

#include "Header.h"

class Calk {
private:
    int index = 0;
    string expression;
    int constant;
    int size = 1;
    enum State {
        number, plus, minus, asterisk, slash, combin, lparen, rparen, comma
    };
    State current;

    char nextChar();

    string replaceSpace(string str);

    void getNext();

    Expression *atomic();

    Expression *mullDiv();

    Expression *addSub();

public:
    Calk() {

    }

    Expression *parse(string input);
};


#endif //UNTITLED2_CALK_H
