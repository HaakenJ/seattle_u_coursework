//
// Created by Kevin Lundeen on 10/7/20.
// Seattle University, CPSC 5005
//

#include <iostream>
#include "IntBST.h"
using namespace std;

bool first_test() {
    string title = "first test: ";

    IntBST bsti;
    cout << title << "check if empty tree has 1" << endl;
    if (bsti.has(1))
        return false;

    cout << title << "add 1 and check has(1)" << endl;
    bsti.add(1);
    IntBST bst2(bsti);
    if (!bsti.has(1))
        return false;

    cout << title << "remove 1 and check" << endl;
    bsti.remove(1);
    if (bsti.has(1))
        return false;

    cout << title << "check copy" << endl;
    if (!bst2.has(1))
        return false;

    bsti = bst2;
    cout << title << "check assigned version" << endl;
    if (!bsti.has(1))
        return false;

    cout << title;
    return true;
}

int main() {
    cout << (first_test() ? "passed" : "failed") << endl;
    return EXIT_SUCCESS;
}
