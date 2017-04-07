//
// Created by Python on 28.03.2017.
//

#include "Checker.h"

bool Checker::check(string &s) {
    bool a = checkBracket(s);
    bool b = checkSign(s);
    bool c = checkFormula(s);
    return a & b & c;
}

bool Checker::checkBracket(string &s) {
    int cmp = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            cmp++;
        } else if (s[i] == ')') {
            if (cmp <= 0) {
                return false;
            }
            cmp--;
        }
    }
    return cmp == 0;
}

bool Checker::checkSign(string &s) {
    string str = "+/*)";
    for (int i = 1; i < s.size(); i++) {
        for (int j = 0; j < str.size(); j++) {
            if (s[i] == str[j] &&
                (s[i - 1] == '(' || s[i - 1] == '+' ||
                 s[i - 1] == '*' || s[i - 1] == '/' ||
                 s[i - 1] == '-' || s[i - 1] == ',')) {
                return false;
            }
        }
    }
    return true;
}

bool Checker::checkFormula(string &str) {
    int cmp = 0;
    string s = "     " + str;
    for (int i = 3; i < s.size() - 1; i++) {
        string sb = s.substr(i - 3, 4);
        if (sb == "cnk(") {
            cmp++;
        } else if (s[i] == ',') {
            if (cmp <= 0) {
                return false;
            }
            cmp--;
        }
    }
    return cmp == 0;
}