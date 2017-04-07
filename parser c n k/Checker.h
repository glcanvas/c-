//
// Created by Python on 28.03.2017.
//

#ifndef UNTITLED2_CHECKER_H
#define UNTITLED2_CHECKER_H

#include "Header.h"

class Checker {
public:
    bool check(string &s);

private:
    bool checkBracket(string& s);
    bool checkSign(string&s);
    bool checkFormula(string&s);
};


#endif //UNTITLED2_CHECKER_H
