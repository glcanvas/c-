//
// Created by Python on 28.03.2017.
//

#include "Calk.h"

string Calk::replaceSpace(string str) {
    string s = "";
    for (int i = 0; i < str.size(); i++) {
        if (isspace(str[i])) {
            continue;
        }
        s += str[i];
    }
    return s;
}

Expression *Calk::parse(string inp) {
    expression = replaceSpace(inp);
    return addSub();
}

Expression *Calk::addSub() {
    Expression *left = mullDiv();
    for (;;) {
        switch (current) {
            case minus:
                left = new Subtract(left, mullDiv(), make_pair(0, 0), size);
                break;
            case plus:
                left = new Add(left, mullDiv(), make_pair(0, 0), size);
                break;
            default:
                return left;
        }
    }
}

Expression *Calk::mullDiv() {
    Expression *left = atomic();
    for (;;) {
        switch (current) {
            case asterisk:
                left = new Multiply(left, atomic(), make_pair(0, 0), size);
                break;

            case slash:
                left = new Divide(left, atomic(), make_pair(0, 0), size);
                break;

            default:
                return left;
        }
    }
}

Expression *Calk::atomic() {
    getNext();
    Expression *ret = nullptr, *l, *r, *brek;
    switch (current) {
        case number:
            ret = new Const(constant, make_pair(0, 0), size);
            getNext();
            break;

        case minus:
            ret = new Subtract(new Const(0, make_pair(0, 0), size), atomic(), make_pair(0, 0), size);
            break;

        case lparen:
            brek = addSub();
            if (current != rparen) {
                getNext();
                exit(1);
            }
            ret = new Brackets(brek, make_pair(0, 0), size);
            getNext();
            break;

        case rparen:
            break;

        case comma:
            ret = addSub();
            break;

        case combin:
            nextChar();
            size *= 2;
            cout << size << "!!!!\n";
            l = addSub();
            r = addSub();
            getNext();
            size /= 2;
            ret = new Combination(l, r, make_pair(0, 0), size);

            break;

        default:
            cout << "error, in position=" << index << " " << expression[index];
            exit(0);
    }
    return ret;
}

void Calk::getNext() {
    char c = nextChar();
    if (isdigit(c)) {
        string str = "";
        while (isdigit(c)) {
            str += c;
            c = nextChar();
        }
        index--;
        constant = stoi(str);
        current = number;
    } else if (c == '+') {
        current = plus;
    } else if (c == '-') {
        current = minus;
    } else if (c == '*') {
        current = asterisk;
    } else if (c == '/') {
        current = slash;
    } else if (c == '(') {
        current = lparen;
    } else if (c == ')') {
        current = rparen;
    } else if (c == ',') {
        current = comma;
    } else if (c == 'c') {
        current = combin;
    }
}

char Calk::nextChar() {
    if (index < expression.length()) {
        char ret = expression[index];
        index++;
        return ret;
    } else {
        return '#';
    }
}