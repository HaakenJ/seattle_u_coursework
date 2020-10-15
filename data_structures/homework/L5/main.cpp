#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList<int> ll;

    int arr[] = {3, 2, 5, 12, 22, 4, -5};

    for (int i: arr)
        ll.add(i, "something");

    std::cout << ll.getLastNegative();

    return 0;
}
