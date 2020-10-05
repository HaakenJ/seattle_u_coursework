//
// Created by Haake on 10/2/2020.
//

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    cout << "how many elements would you like in the array?" << endl;
    int capacity;
    cin >> capacity;

    auto arr = new int[capacity];

    for (int i = 0; i < capacity; i++) {
        arr[i] = (rand() % 100) + 1;
    }

    for (int i = 0; i < capacity; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    delete [] arr;
}
