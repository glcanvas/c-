//
// Created by Python on 05.04.2017.
//
#include <iostream>

class Expression {
protected:
    Expression *left, *right;
    std::pair<int, int> pos;
    int size = 1;
    std::string type = "";
public:
    Expression() {
    }

    Expression(Expression *left, Expression *right, std::pair<int, int> pos, int size) {
        this->left = left;
        this->right = right;
        this->pos = pos;
        this->size = size;
    }

    virtual int evaluate() {
        return 0;
    }

    int getMax() {
        return size;
    }

    void setSize(int x) {
        size = x / size;
    }

    std::pair<int, int> getCord() {
        return pos;
    }

    void setCord(std::pair<int, int> cord) {
        this->pos = cord;
    }

    Expression *getLeft() {
        return left;
    }

    Expression *getRight() {
        return right;
    }
    std::string getType() {
        return type;
    }
};

#include <iostream>
#include <math.h>

class Add : public Expression {
public:
    Add(Expression *left, Expression *right, std::pair<int, int> pos, int size) : Expression(left, right, pos, size) {
        type = "+";
    }

    int evaluate() {
        std::cout << "in add " << left << " " << right << " " << size << "\n";
        return left->evaluate() + right->evaluate();
    }


};


class Subtract : public Expression {
public :
    Subtract(Expression *left, Expression *right, std::pair<int, int> pos, int size) : Expression(left, right, pos,
                                                                                                  size) {
        type = "-";
    }

    int evaluate() {
        std::cout << "in sub " << left << " " << right << " " << size << "\n";
        return left->evaluate() - right->evaluate();
    }


};

class Divide : public Expression {
public :
    Divide(Expression *left, Expression *right, std::pair<int, int> pos, int size) : Expression(left, right, pos,
                                                                                                size) {
        type = "/";
    }

    int evaluate() {
        std::cout << "in div " << left << " " << right << " " << size << "\n";
        return left->evaluate() / right->evaluate();
    }


};

class Multiply : public Expression {
public:
    Multiply(Expression *left, Expression *right, std::pair<int, int> pos, int size) : Expression(left, right, pos,
                                                                                                  size) {
        type = "*";
    }

    int evaluate() {
        std::cout << "in mull " << left << " " << right << " " << size << "\n";
        return left->evaluate() * right->evaluate();
    }

};

class Const : public Expression {
private:
    int x;
public:
    Const(int x, std::pair<int, int> pos, int size) : Expression(nullptr, nullptr, pos, size) {
        this->x = x;
        type = std::to_string(x);
    }

    int evaluate() {
        std::cout << "in const " << x << " " << size << "\n";
        return x;
    }


};


class Combination : public Expression {
public:
    Combination(Expression *left, Expression *right, std::pair<int, int> pos, int size) : Expression(left, right, pos,
                                                                                                     size) {
        type = "c";
    }

    int factorial(int x) {
        if (x == 0 || x == 1) {
            return 1;
        }
        int ans = 1;
        for (int i = 1; i <= x; i++) {
            ans *= i;
        }
        return ans;
    }

    int evaluate() {
        std::cout << "in comb " << left << " " << right << " " << size << "\n";
        int n = left->evaluate();
        int m = right->evaluate();
        return factorial(n) / (factorial(m) * (factorial(n - m)));
    }


};

class Brackets : public Expression {
public:
    Brackets(Expression *left, std::pair<int, int> pos, int size) : Expression(left, nullptr, pos, size) {
        type = "(";
    }

    int evaluate() {
        std::cout << "in brak " << left << " " << size << "\n";
        int n = left->evaluate();
        return n;
    }


};
