//
// Created by Kramer Johnson on 9/15/2020.
// CPSC 5910 03 20FQ Data Structures
//

#include "SandPile.h"

using namespace std;

/**
 * Test the stabilize method and print the results.
 * @param title the title of the test
 * @param args starting elements of the sandpile
**/
void testStabilize(const string &title, const int *args) {
    SandPile test;
    test.setPile(args);
    cout << title << " before stabilization: " << test.toString();
    test.stabilize();
    cout << " after: " << test.toString() << endl;
}

void testAdd(const string &title, const int *argA, const int *argB) {
    SandPile testA(argA);
    SandPile testB(argB);
    cout << title << " a: " << testA.toString();
    cout << "   b: " << testB.toString();

    testA.addPile(testB);
    cout << "   a + b: " << testA.toString() << endl;
}

void testIsInGroup(const string &title, const int *args) {
    SandPile test(args);
    string result;
    test.isInGroup() == 1 ? result = "in group" : result = "not in group";
    cout << title << " + zero: " << test.toString() << " is ";
    cout << result;
}

/**
 * Recursive helper for counting sandpiles in the abelian group.
 * @param args      DIM*DIM-element array to construct a SandPile
 * @param remaining number of elements not yet set in args
 * @param inGroup   accumulates additional SandPiles found in the group (pass by reference)
 * @param inTotal   accumulates total number of SandPiles checked (pass by reference)
 */
void countGroupRec(int *args, int remaining, int &inGroup, int &inTotal) {
    int n = SandPile::DIM * SandPile::DIM;
    if (remaining == n) {
        SandPile test(args);
        if (test.isInGroup()) inGroup++;
        inTotal++;
    } else {
        for (int i = 0; i <= SandPile::DIM; i++) {
            args[remaining] = i;
            countGroupRec(args, remaining + 1, inGroup, inTotal);
            args[remaining] = i;
        }
    }
}

/** Count the total amount of piles in the abelian group and total tested
 * piles. Returns either total abelian piles or total tested piles based
 * on boolean flag.  (True returns abelian)
 * @param bool flag true to return abelian piles, false to return total piles
 * @return either total piles in abelian group or total piles tested
 */
int countPiles(bool abelianFlag) {
    int totalAbelian = 0;
    int totalTested = 0;

    for (int i0 = 0; i0 <= SandPile::MAX_STABLE; i0++) {
        for (int i1 = 0; i1 <= SandPile::MAX_STABLE; i1++) {
            for (int i2 = 0; i2 <= SandPile::MAX_STABLE; i2++) {
                for (int i3 = 0; i3 <= SandPile::MAX_STABLE; i3++) {
                    for (int i4 = 0; i4 <= SandPile::MAX_STABLE; i4++) {
                        for (int i5 = 0; i5 <= SandPile::MAX_STABLE; i5++) {
                            for (int i6 = 0; i6 <= SandPile::MAX_STABLE; i6++) {
                                for (int i7 = 0; i7 <= SandPile::MAX_STABLE; i7++) {
                                    for (int i8 = 0; i8 <= SandPile::MAX_STABLE; i8++) {
                                        int pile[] = {i0, i1, i2, i3, i4, i5, i6, i7, i8};
                                        SandPile sp(pile);
                                        if (sp.isInGroup()) totalAbelian++;
                                        totalTested++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return abelianFlag ? totalAbelian : totalTested;
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

    cout << endl;
    cout << "Tests of isInGroup():" << endl;

    int groupTest1[9] = {3, 3, 3, 3, 3, 3, 3, 3, 3};
    testIsInGroup("all 3's", groupTest1);
    cout << " (expect in group)" << endl;

    int groupTest2[9] = {2, 2, 2, 2, 2, 2, 2, 2, 2};
    testIsInGroup("all 2's", groupTest2);
    cout << " (expect in group)" << endl;

    int groupTest3[9] = {3, 2, 2, 2, 1, 1, 3, 3, 3};
    testIsInGroup("all 3's", groupTest3);
    cout << " (expect in group)" << endl;

    int groupTest4[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    testIsInGroup("all 3's", groupTest4);
    cout << " (expect not in group)" << endl;

    cout << endl;
    cout << "Iterative Abelian Group Tests: " << endl;
    cout << "sand piles in group: " << countPiles(true) << endl;
    cout << "out of total 3x3 sand piles: " << countPiles(false) << endl;

    cout << endl;
    cout << "Recursive Abelian Group Tests: " << endl;
    int args[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int inGroup = 0;
    int inTotal = 0;
    countGroupRec(args, 0, inGroup, inTotal);
    cout << "sand piles in group: " << inGroup << endl;
    cout << "out of total 3x3 sand piles: " << inTotal << endl;

    return 0;
}
