#include <iostream>

#include "Stack.h"
using namespace std;
int main() {
    Stack s;

    s.push("world");
    s.push("Hello");
    cout << s.pop() << " ";
    cout << s.pop() << endl;
    return 0;
}
