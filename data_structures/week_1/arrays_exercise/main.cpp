#include <iostream>
using namespace std;

// *x is how you pass an array into a function
// It tells c++ that you are passing an address
void printArray(int *x, int count) {
    for (int i = 0; i < count; i++) {
        cout << "x[" << i << "]: " << x[i] << "  ";
    }
}

int main() {
    const int SIZE = 3;
    int x[SIZE];
    cout << "Enter 3 integers (sep. by spaces): ";
    for (int i = 0; i < SIZE; i+=) {
        cin >> x[i];
    }
    for (int i = 0; i < SIZE; i++) {
        cout << "x[" << i << "]: " << x[i] << " ";
    }
    cout << endl;
    return 0;
}
