#include <iostream>
#include "Rectangle.h"

using namespace std;

/**
 * Main entry point for tests.
 * @return always 0
 */
int main() {
    Rectangle<int> r;
    r.setWidth(5);
    r.setLength(7);
    cout << "printing int-dimensioned rectangle..." << endl;
    cout << "\twidth: " << r.getWidth() << endl;
    cout << "\tlength: " << r.getLength() << endl;
    cout << "\tarea: " << r.getArea() << endl;

    Rectangle<double> rd;
    rd.setWidth(5.02);
    rd.setLength(7.39);
    cout << "printing doulbe-dimensioned rectangle..." << endl;
    cout << "\twidth: " << rd.getWidth() << endl;
    cout << "\tlength: " << rd.getLength() << endl;
    cout << "\tarea: " << rd.getArea() << endl;

    return 0;
}
