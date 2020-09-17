//
// Created by Kramer Johnson on 9/15/2020.
// CPSC 5910 03 20FQ Data Structures
//

#include <iostream>
#include "SandPile.h"

using namespace std;

int main() {
    SandPile sp;

    cout << "Required Tests:" << endl;
    // Test One
    int pile[9] = {0, 0, 0, 0, 4, 0, 0, 0, 0};
    sp.setPile(pile);
    cout << "Test one before stabilization: " << sp.toString();
    sp.stabilize();
    cout << " after: " << sp.toString() << endl;

    // Test Two
    int pile2[9] = {4, 0, 0, 0, 4, 0, 0, 0, 0};
    sp.setPile(pile2);
    cout << "Test two before stabilization: " << sp.toString();
    sp.stabilize();
    cout << " after: " << sp.toString() << endl;

    // Test Three
    int pile3[9] = {4, 0, 0, 0, 10, 0, 0, 0, 0};
    sp.setPile(pile3);
    cout << "Test three before stabilization: " << sp.toString();
    sp.stabilize();
    cout << " after: " << sp.toString() << endl << endl;


    /*
     * What follows is a suite of tests to test each option of the switch
     * statement in getBorders()
     */
    cout << "Tests for getBorders() statement coverage:" << endl;
    // Test Four
    int pile4[9] = {4, 0, 0, 0, 0, 0, 0, 0, 0};
    sp.setPile(pile4);
    cout << "Test four before stabilization: " << sp.toString();
    sp.stabilize();
    cout << " after: " << sp.toString() << endl;

    // Test Five
    int pile5[9] = {0, 4, 0, 0, 0, 0, 0, 0, 0};
    sp.setPile(pile5);
    cout << "Test five before stabilization: " << sp.toString();
    sp.stabilize();
    cout << " after: " << sp.toString() << endl;

    // Test Six
    int pile6[9] = {0, 0, 4, 0, 0, 0, 0, 0, 0};
    sp.setPile(pile6);
    cout << "Test six before stabilization: " << sp.toString();
    sp.stabilize();
    cout << " after: " << sp.toString() << endl;

    // Test Seven
    int pile7[9] = {0, 0, 0, 4, 0, 0, 0, 0, 0};
    sp.setPile(pile7);
    cout << "Test seven before stabilization: " << sp.toString();
    sp.stabilize();
    cout << " after: " << sp.toString() << endl;

    // Test Eight
    // This is the same as test one but I added it again for continuity
    int pile8[9] = {0, 0, 0, 0, 4, 0, 0, 0, 0};
    sp.setPile(pile8);
    cout << "Test eight before stabilization: " << sp.toString();
    sp.stabilize();
    cout << " after: " << sp.toString() << endl;

    // Test Nine
    int pile9[9] = {0, 0, 0, 0, 0, 4, 0, 0, 0};
    sp.setPile(pile9);
    cout << "Test nine before stabilization: " << sp.toString();
    sp.stabilize();
    cout << " after: " << sp.toString() << endl;

    // Test ten
    int pile10[9] = {0, 0, 0, 0, 0, 0, 4, 0, 0};
    sp.setPile(pile10);
    cout << "Test ten before stabilization: " << sp.toString();
    sp.stabilize();
    cout << " after: " << sp.toString() << endl;

    // Test eleven
    int pile11[9] = {0, 0, 0, 0, 0, 0, 0, 4, 0};
    sp.setPile(pile11);
    cout << "Test eleven before stabilization: " << sp.toString();
    sp.stabilize();
    cout << " after: " << sp.toString() << endl;

    // Test twelve
    int pile12[9] = {0, 0, 0, 0, 0, 0, 0, 0, 4};
    sp.setPile(pile12);
    cout << "Test twelve before stabilization: " << sp.toString();
    sp.stabilize();
    cout << " after: " << sp.toString() << endl << endl;

    // Test Thirteen - Test that stabilize() does not alter a stable pile
    cout << "Test that a stable pile remains unaltered:" << endl;
    int pile13[9] = {3, 3, 3, 3, 3, 3, 3, 3, 3};
    sp.setPile(pile13);
    cout << "Test thirteen before stabilization: " << sp.toString();
    sp.stabilize();
    cout << " after: " << sp.toString() << endl;

    return 0;
}
