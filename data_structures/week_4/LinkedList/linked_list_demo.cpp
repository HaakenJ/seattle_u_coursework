#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
    LinkedList x;

    x.add(1, "one");
//    x.add(2, "two");
//    x.add(3, "three");
    x.add(4, "four");
//    x.add(5, "five");
    cout << "search(4) \"" << x.search(4) << "\"" << endl;
    cout << "search(1) \"" << x.search(1) << "\"" << endl;
    cout << "search(100) \"" << x.search(100) << "\"" << endl;
    return 0;
}
