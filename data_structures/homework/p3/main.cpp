#include <iostream>
#include "BST.h"

using namespace std;

/**
 * Testing function for getLeafCount()
 * @param arr        array of elements to add
 * @param size       size of array
 * @param expLeaves  expected number of leaves in tree
 * @return           true if tree has expected number of leaves
 */
bool testLeafCount(int *arr, int size, int expLeaves) {
    BST<int> bst;

    for (int i = 0; i < size; ++i) {
        bst.add(arr[i]);
    }

    return bst.getLeafCount() == expLeaves;
}

bool first_test() {
    string title = "first test: ";

    BST<int> bsti;

    cout << title << "check if empty tree is empty" << endl;
    if (!bsti.empty())
        return false;

    cout << title << "check that empty tree has size of 0" << endl;
    if (bsti.size() != 0)
        return false;

    cout << title << "check if empty tree has 1" << endl;
    if (bsti.has(1))
        return false;

    cout << title << "add 1 and check has(1)" << endl;
    bsti.add(1);
    BST<int> bst2(bsti);
    if (!bsti.has(1))
        return false;

    cout << title << "check that 1 element tree has 1 leaf" << endl;
    if (bsti.getLeafCount() != 1)
        return false;

    cout << title << "check if non-empty tree is empty" << endl;
    if (bsti.empty())
        return false;

    cout << title << "check that size of tree is 1" << endl;
    if (bsti.size() != 1)
        return false;

    cout << title << "remove 1 and check" << endl;
    bsti.remove(1);
    if (bsti.has(1))
        return false;

    cout << title << "add four elements and check size" << endl;
    for (int i = 0; i < 4; ++i) {
        bsti.add(i);
    }

    if (bsti.size() != 4)
        return false;

    for (int i = 0; i < 4; ++i) {
        bsti.remove(i);
    }

    cout << "create 15 element balanced tree and check leaf count" << endl;
    int elements[] = {8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15};

    if (!testLeafCount(elements, 15, 8))
        return false;

    cout << "create max-height 5 element tree and check leaf count" << endl;
    int elements2[] = {0, 1, 2, 3, 4};

    if (!testLeafCount(elements2, 5, 1))
        return false;

    cout << "create 6 element unblanced tree and check leaf count" << endl;
    int elements3[] = {5, 3, 7, 8, 1, 4};

    if (!testLeafCount(elements3, 6, 3))
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
//    cout << (first_test() ? "passed" : "failed") << endl;

    BST<string> bst;

    bst.add("d");
    bst.add("e");
    bst.add("f");
    bst.add("a");
    bst.add("g");

    cout << bst.getHeight() << endl;

    return EXIT_SUCCESS;

}