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
void testStabilize(string title, const int *args) {
    SandPile test;
    test.setPile(args);
    cout << title << " before stabilization: " << test.toString();
    test.stabilize();
    cout << " after: " << test.toString() << endl;
}

int main() {
    SandPile sp;

    // cout << "Required Tests:" << endl;
    // // Test One
    // int pile[9] = {0, 0, 0, 0, 4, 0, 0, 0, 0};
    // testStabilize("test1", pile);

    // // Test Two
    // int pile2[9] = {4, 0, 0, 0, 4, 0, 0, 0, 0};
    // testStabilize("test2", pile2);

    // // Test Three
    // int pile3[9] = {4, 0, 0, 0, 10, 0, 0, 0, 0};
    // testStabilize("test3", pile3);

    // int pile4[9] = {4, 4, 0, 0, 10, 0, 0, 0, 0};
    // testStabilize("test4", pile4);

    // int pile5[9] = {4, 4, 4, 10, 10, 0, 22, 1, 5};
    // testStabilize("test5", pile5);

    // // Test Thirteen - Test that stabilize() does not alter a stable pile
    // cout << "Test that a stable pile remains unaltered:" << endl;
    // int pile6[9] = {3, 3, 3, 3, 3, 3, 3, 3, 3};
    // testStabilize("test6", pile6);

    cout << sp.toString();

    return 0;
}
