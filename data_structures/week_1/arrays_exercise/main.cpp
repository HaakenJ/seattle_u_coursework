#include <iostream>
using namespace std;

// *x is how you pass an array into a function
// It tells c++ that you are passing an address
void printArray(int *x, int count) {
    for (int i = 0; i < count; i++) {
        cout << "x[" << i << "]: " << x[i] << "  ";
    }
}

// The star lets it known that it will return a pointer to an array
int *makeArray(int count) {
    // You need to use new or the array will be deleted at the end of this
    // function's scope
    int *x = new int[count];
    for (int i = 0; i < count; i++) {
        cin >> x[i];
    }
    return x;
}

int main() {
    const int SIZE = 3;
    int *x;
    cout << "Enter 3 integers (sep. by spaces): ";
    for (int i = 0; i < SIZE; i+=) {
        cin >> x[i];
    }
    for (int i = 0; i < SIZE; i++) {
        cout << "x[" << i << "]: " << x[i] << " ";
    }
    cout << endl;

    // Since you used 'new' to create the array you must delete it from the heap
    // Without this you would have a memory leak
    delete[] x;
    return 0;
}
