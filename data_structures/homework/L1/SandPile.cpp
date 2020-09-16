//
// Created by Haake on 9/15/2020.
//

#include "SandPile.h"

using namespace std;

// Set the pile value
void SandPile::setPile(const int *cells) {
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        pile[i] = cells[i];
    }
}

// Check if the pile is stable
bool SandPile::isStable() const {
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (pile[i] > MAX_STABLE) return false;
    }
    return true;
}

// Stabilize the pile
void SandPile::stabilize() {
    int spillIndex;
    while (!isStable()) {
        // Get index of the first element over MAX_STABLE size
        spillIndex = getSpillElement();
        pile[spillIndex] -= 4;

        // Get the indexes of the bordering elements in the pile
        vector<int> boundaries = getBorders(spillIndex);
        // Increase the size of each bounding element
        for (int boundary: boundaries) {
            pile[boundary]++;
        }
    }
}

string SandPile::toString() const {
    string result;
    int count = 1;
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        result = result + " " + to_string(pile[i]);
        if (count == 3) {
            result += " /";
            count = 0;
        }
        else count++;
    }
}

// Get a vector of the bordering elements to an index
 vector<int> SandPile::getBorders(const int index) const {
    // return a vector of the bordering indexes
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

// Get the index of an element that will spill
int SandPile::getSpillElement() const {
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (pile[i] > MAX_STABLE) return pile[i];
    }
    return -1;
}