#include <iostream>
#include "SandPile.h"

void print(std::vector <int> const &a) {
    std::cout << "The vector elements are : ";

    for(int i=0; i < a.size(); i++)
        std::cout << a.at(i) << ' ';
}

int main() {
    SandPile sp;
    print(sp.getBorders(3));
    print(sp.getBorders(1));
    print(sp.getBorders(4));
    return 0;
}
