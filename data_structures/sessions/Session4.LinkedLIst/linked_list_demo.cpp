#include <iostream>
#include "LinkedList.h"
using namespace std;

void print(string title, const LinkedList &list) {
    cout << title << endl;
    cout << "search(4) \"" << list.search(4) << "\"" << endl;
    cout << "search(1) \"" << list.search(1) << "\"" << endl;
    cout << "search(100) \"" << list.search(100) << "\"" << endl;
    cout << endl;
}


int main() {
    LinkedList x;
    x.add(1, "one");
    x.add(4, "four");
    print("x with 1 and 4", x);

    LinkedList y(x);  // copy ctor
    x.remove(4);
    print("y, a copy of x", y);
    print("x after removing 4", x);

    y = x;  // assignment operator
    print("y a copy of x without the 4", y);
    return 0;
}
