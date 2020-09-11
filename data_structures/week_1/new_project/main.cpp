#include <iostream>
#include "Rectangle.h"
using namespace std;

int main() {
    Rectangle r; // this actually calls the zero-arg constructor
    Rectangle r2(5, 7); // this calls the two arg ctor

    // print first rectangle
    cout << "height: " << r.getHeight() << endl;
    cout << "width: " << r.getWidth() << endl;
    cout << "area: " << r.getArea() << endl;

    // print second rectangle
    cout << "height: " << r2.getHeight() << endl;
    cout << "width: " << r2.getWidth() << endl;
    cout << "area: " << r2.getArea() << endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
