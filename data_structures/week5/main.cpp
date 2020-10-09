#include <iostream>
#include "IntBST.h"

using namespace std;

bool first_test() {
    IntBST bst;
    bst.add(1);
    if (!bst.has(1))
        return false;
    bst.add(10);
    bst.add(-7);
    if (!bst.has(-7))
        return false;
    if (bst.has(9))
        return false;

    int data[] = {-5, 6, 99, 4, 34, 8, -2, -1000};
    for (int i : data) {
        bst.add(i);
    }

    for (int i : data) {
        if (!bst.has(i))
            return false;
    }
    return true;
}

int main() {
    cout << (first_test() ? "success" : "failed") << endl;
    return 0;
}
