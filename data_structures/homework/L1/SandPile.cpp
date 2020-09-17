//
// Created by Kramer Johnson on 9/15/2020.
// CPSC 5910 03 20FQ Data Structures
//

#include "SandPile.h"
#include <iostream>
#include <sstream>

using namespace std;

// Set the pile value
void SandPile::setPile(const int *cells) {
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        pile[i] = cells[i];
    }
}

// Check if the pile is stable (i.e. if all elements are below MAX_STABLE)
bool SandPile::isStable() const {
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (pile[i] > MAX_STABLE) return false;
    }
    return true;
}

// Stabilize the pile (i.e. topple all elements greater than MAX_STABLE)
void SandPile::stabilize() {
    int spillIndex;
    while (!isStable()) {
        // Get index of the first element over MAX_STABLE size
        spillIndex = getSpillElement();
        // Reduce the size of the oversized element
        pile[spillIndex] -= 4;

        // Get the indexes of the bordering elements in the pile
        vector<int> boundaries = getBorders(spillIndex);
        // Increase the size of each bounding element
        for (int boundary: boundaries) {
            pile[boundary]++;
        }
    }
}

// Convert the pile to a formatted string for output
string SandPile::toString() const {
    // Create an output string stream
    std::ostringstream os;
    int count = 1;
    for (int i: pile) {
        // Add the current pile element onto the stream along with a space
        // Add a forward-slash every three elements
        os << i;
        os << " ";
        if (count % 3 == 0 && count != ARRAY_SIZE) os << "/ ";
        count++;
    }
    // Get the content from the output stream and return it as a string
    std::string str(os.str());
    return str;
}

// Get a vector of the bordering elements to an index
vector<int> SandPile::getBorders(const int index) const {
    vector<int> borders;

    switch (index) {
        case 0:
            borders.push_back(1);
            borders.push_back(3);
            return borders;
        case 1:
            borders.push_back(0);
            borders.push_back(2);
            borders.push_back(4);
            return borders;
        case 2:
            borders.push_back(1);
            borders.push_back(5);
            return borders;
        case 3:
            borders.push_back(0);
            borders.push_back(4);
            borders.push_back(6);
            return borders;
        case 4:
            borders.push_back(1);
            borders.push_back(3);
            borders.push_back(5);
            borders.push_back(7);
            return borders;
        case 5:
            borders.push_back(2);
            borders.push_back(4);
            borders.push_back(8);
            return borders;
        case 6:
            borders.push_back(3);
            borders.push_back(7);
            return borders;
        case 7:
            borders.push_back(4);
            borders.push_back(6);
            borders.push_back(8);
            return borders;
        default:
            borders.push_back(5);
            borders.push_back(7);
            return borders;
    }
}

// Get the index of an element that is over MAX_STABLE size
int SandPile::getSpillElement() const {
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (pile[i] > MAX_STABLE) return i;
    }
    return -1;
}