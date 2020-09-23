//
// Created by Kramer Johnson on 9/15/2020.
// CPSC 5910 03 20FQ Data Structures
//

#include <iostream>
#include "SandPile.h"

using namespace std;

/**
 * Test the stabilize method and print the results.
 * @param title the title of the test
 * @param args starting elements of the sandpile
**/
void testStabilize(const string title, const int *args) {
    SandPile test;
    test.setPile(args);
    cout << title << " before stabilization: " << test.toString();
    test.stabilize();
    cout << " after: " << test.toString() << endl;
}

void testAdd(const string title, const int *argA, const int *argB) {
    SandPile testA(argA);
    SandPile testB(argB);
    cout << title << " a: " << testA.toString();
    cout << "   b: " << testB.toString();

    testA.addPile(testB);
    cout << "   a + b: " << testA.toString() << endl;
}

int main() {
    SandPile zero;
    cout << "zero (using no-arg ctor): " << zero.toString() << endl;

    SandPile sp;

    cout << endl;
    cout << "Tests of stabilize():" << endl;
    // Test One
    int pile[9] = {0, 0, 0, 0, 4, 0, 0, 0, 0};
    testStabilize("test1", pile);

    // Test Two
    int pile2[9] = {4, 0, 0, 0, 4, 0, 0, 0, 0};
    testStabilize("test2", pile2);

    // Test Three
    int pile3[9] = {4, 0, 0, 0, 10, 0, 0, 0, 0};
    testStabilize("test3", pile3);

    int pile4[9] = {4, 4, 0, 0, 10, 0, 0, 0, 0};
    testStabilize("test4", pile4);

    int pile5[9] = {4, 4, 4, 10, 10, 0, 22, 1, 5};
    testStabilize("test5", pile5);

    // Test Thirteen - Test that stabilize() does not alter a stable pile
    cout << "Test that a stable pile remains unaltered:" << endl;
    int pile6[9] = {3, 3, 3, 3, 3, 3, 3, 3, 3};
    testStabilize("test6", pile6);

    cout << endl;
    cout << "Tests of addPile():" << endl;

    int addTest1[9] = {0, 0, 0, 0, 2, 0, 0, 0, 0};
    testAdd("add1", addTest1, addTest1);

    int addTest2A[9] = {1, 2, 0, 2, 1, 1, 0, 1, 3};
    int addTest2B[9] = {2, 1, 3, 1, 0, 1, 0, 1, 0};
    testAdd("add2", addTest2A, addTest2B);

    int addTest3[9] = {3, 3, 3, 3, 3, 3, 3, 3, 3};
    testAdd("add2", addTest3, addTest3);

    return 0;
}
