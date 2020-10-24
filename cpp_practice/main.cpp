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

int main() {
    writeBlock('*', 5, 3);
    return 0;
}
