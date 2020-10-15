#include <iostream>
#include "LinkedList.h"

using namespace std;

/**
 * Testing function for the getLastNegative method
 * @tparam ArrType a numeric type for the array passed in
 * @tparam KeyType a numeric type for the list elements
 * @param arr      an array of numeric elements
 * @param ll       a LinkedList object
 * @param n        the number of elements in arr
 */
template <class ArrType, class KeyType>
void testLastNegative(ArrType *arr, LinkedList<KeyType> &ll, int n) {
    cout << "Linked list values: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << "  ";
        ll.add(arr[i], "something");
    }
    cout << endl;

    cout << "Last negative number: ";
    cout << ll.getLastNegative() << endl;
}

int main() {
    LinkedList<int> ll;
    LinkedList<double> ll2;

    int intArr[] = {3, -2, 5, 12, -2, -4, 5};
    double dblArr[] = {-3.2, 2.14, -5.7, -12.01, -2.99, 4.6, 5.2};

    testLastNegative(intArr, ll, 7);
    testLastNegative(dblArr, ll2, 7);

    return 0;
}
