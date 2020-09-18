#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    struct ThreePoint {
        double x, y, z;
    };

    b = new ThreePoint;
    b->z = 12.0;
    b->x = b->y = 0.0;
    delete b;

    b = new ThreePoint[10];
    b[0].x = 0;
    b[0].y = 12;
    b[0].z = -1.1;

    cout << b[0].x << ", " << b[0].y << ", " << b[0].z << endl;

    return 0;
}
