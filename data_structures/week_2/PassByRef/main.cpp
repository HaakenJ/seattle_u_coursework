#include <iostream>
using namespace std;

struct ThreePoint {
    double x, y, z;
};


// a and b are "passed by reference"
void swap(double &a, double &b) {  // the & here is NOT an address-of operator
    double tmp = a;
    a = b;
    b = tmp;
}

// compare ot "pass by pointer"
void swapp(double *a, double *b) {
    double tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    double x, y;
    cout << "enter two doubles: ";
    cin >> x;
    cin >> y;
    swap(x, y);
    cout << "your first was " << y << endl;
    cout << "your second was " << x << endl;
    swapp(&x, &y);
    cout << "your first was " << x << endl;
    cout << "your second was " << y << endl;


    ThreePoint u, w;
    u.x = 1; u.y = 2; u.z = 4;
    w.x = -1; w.y = -2; w.z = -u.z;
    swap(u.x, w.x);
    cout << "u: " << u.x << ", " << u.y << ", " << u.z << endl;
    cout << "w: " << w.x << ", " << w.y << ", " << w.z << endl;

    return 0;
}
