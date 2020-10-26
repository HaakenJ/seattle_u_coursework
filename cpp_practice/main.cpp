#include <iostream>

using namespace std;

void writeLine(char c, int n) {
    if (n > 0) {
        cout << c;
        writeLine(c, n - 1);
    }
}

void writeBlock(char c, int n, int m) {
    if (m > 0) {
        writeLine(c, n);
        cout << endl;
        writeBlock(c, n, m - 1);
    }
}

int getMax(int *arr, int start, int end) {
    if (start == end)
        return arr[start];
    else {
        int mid = (start + end) / 2;
        int left = getMax(arr, start, mid);
        int right = getMax(arr, mid + 1, end);
        return (left > right ? left : right);
    }
}

int main() {
    int arr[] = {1, 3, 22, 56, 100, 5, 3};
    cout << getMax(arr, 0, 6);
    return 0;
}
