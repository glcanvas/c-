//
// Created by Python on 27.03.2017.
//

#include "Printer.h"

Printer::Printer() {
    freopen("dictionary.txt", "r", stdin);
    screen.resize(500, vector<char>(500, ' '));
    cin >> n >> m;
    char c;
    while (cin >> c) {
        if (c != '>') {
            cout << "wrong input";
            exit(1);
        }
        char symbol;
        cin >> symbol;
        dictionary[symbol].resize((unsigned int) n);
        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;
            str += "     ";
            for (int j = 0; j < str.size(); j++) {
                if (str[j] == '_') {
                    str[j] = ' ';
                }
            }
            str = str.substr(0, 3);
            dictionary[symbol][i] = str;
        }
    }
    for (auto it: dictionary) {
    }
    fclose(stdin);
}

void Printer::printLetter(char c) {
    if (dictionary.find(c) == dictionary.end()) {
        cout << "letter not found";
        return;
    }
    for (int i = 0; i < dictionary[c].size(); i++) {
        cout << dictionary[c][i] << "\n";
    }
}

int Printer::getMax(Expression *e) {
    //cout << e->getMax() << " " << e->getLeft() << " " << e->getRight() << "\n";
    int a = -1, b = -1;
    if (e->getLeft() != nullptr) {
        a = getMax(e->getLeft());
    }
    if (e->getRight() != nullptr) {
        b = getMax(e->getRight());
    }
    return max(e->getMax(), max(a, b));
}

void Printer::setSize(Expression *e, int x) {
    e->setSize(x);
    if (e->getLeft() != nullptr) {
        setSize(e->getLeft(), x);
    }
    if (e->getRight() != nullptr) {
        setSize(e->getRight(), x);
    }

}

void Printer::dfs3(Expression *e, pair<int, int> pos) {
    if (e->getType() == "c") {
        setChar(e->getMax(), 'c', pos);
        pos = make_pair(pos.first, pos.second + m * e->getMax() + 1);
    } else if (e->getType() == "(") {
        setChar(e->getMax(), '(', pos);
        pos = make_pair(pos.first, pos.second + m * e->getMax() + 1);
    } else if (isdigit(e->getType()[0]) || e->getType().size() > 1) {
        for (int i = 0; i < e->getType().size(); i++) {
            setChar(e->getMax(), e->getType()[i], pos);
            pos = make_pair(pos.first, pos.second + m * e->getMax() + 1);
        }
        e->setCord(pos);
        return;
    }
    pair<int, int> a, b;
    if (e->getLeft() != nullptr) {
        dfs3(e->getLeft(), pos);
        a = make_pair(pos.first, e->getLeft()->getCord().second);
        cout << e->getType() << "   " << e->getLeft()->getCord().first << " " << e->getLeft()->getCord().second << '\n';
    }


    if (e->getType() == "+" || e->getType() == "-" || e->getType() == "*" || e->getType() == "/") {
        setChar(e->getMax(), e->getType()[0], a);
        a.second += (e->getMax() * m + 1);
    }

    if (e->getRight() != nullptr) {
        if (e->getType() == "c") {
            dfs3(e->getRight(), make_pair(pos.first + e->getMax() * n / 2, pos.second));
            b = make_pair(pos.first, e->getRight()->getCord().second);
        } else {
            dfs3(e->getRight(), a);
            b = make_pair(a.first, e->getRight()->getCord().second + 1);
        }
    }
    if (e->getType() == "c") {
        e->setCord(make_pair(a.first, max(a.second, b.second) + 1));
    } else if (e->getType() == "(") {
        setChar(e->getMax(), ')', a);
        e->setCord(make_pair(a.first, a.second + m * e->getMax() + 1));
    } else if (e->getType() == "+" || e->getType() == "-" || e->getType() == "*" || e->getType() == "/") {
        e->setCord(b);
    }
    return;
}

void Printer::printString(Expression *expr) {
    int mx = getMax(expr);
    setSize(expr, mx);
    getMax(expr);
    dfs3(expr, make_pair(1, 1));
}


void Printer::printScreen() {
    freopen("screen.txt", "w", stdout);
    for (int i = 0; i < screen.size(); i++) {
        for (int j = 0; j < screen[i].size(); j++) {
            cout << screen[i][j];
        }
        cout << "\n";
    }
    fclose(stdout);
}

void Printer::setChar(int scale, char c, pair<int, int> cur) {
    if (dictionary.find(c) == dictionary.end()) {
        cout << " letter " << c << " not found in dictionary\n";
        return;
    }
    for (int i = 0; i < n * scale; i++) {
        for (int j = 0; j < m * scale; j++) {
            screen[get<0>(cur) + i][get<1>(cur) + j] = dictionary[c][i / scale][j / scale];
        }
    }
}
