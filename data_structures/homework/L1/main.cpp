#include <iostream>
#include "SandPile.h"

void print(std::vector <int> const &a) {
    std::cout << "The vector elements are : ";

    for(int i=0; i < a.size(); i++)
        std::cout << a.at(i) << ' ';
}

int main() {
    SandPile sp;
    int pile[9] = {0, 0, 0, 0, 4, 0, 0, 0 ,0};
    sp.setPile(pile);
    sp.stabilize();
    std::cout << sp.toString();
    return 0;
}
