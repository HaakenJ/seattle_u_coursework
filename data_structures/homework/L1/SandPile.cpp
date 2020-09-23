//
// Created by Kramer Johnson on 9/15/2020.
// CPSC 5910 03 20FQ Data Structures
//

#include "SandPile.h"
#include <sstream>

using namespace std;

// Default ctor that sets pile to zero element
SandPile::SandPile() {
    pile = new int[ARRAY_SIZE];
    int zeroPile[] = {2, 1, 2, 1, 0, 1, 2, 1, 2};
    setPile(zeroPile);
}

// Single arg ctor
SandPile::SandPile(const int *cells) {
    pile = new int[ARRAY_SIZE];
    setPile(cells);
}

// Destructor
SandPile::~SandPile() {
    delete [] pile;
}

// Copy ctor
SandPile::SandPile(const SandPile &sp) {};

// Assignment overload
SandPile & SandPile::operator=(const SandPile &sp) {};

// Add a sandpile to this one
void SandPile::addPile(const SandPile &other) {
    int *otherPile = other.getPile();
    for (int i = 0; i < ARRAY_SIZE; i++) {
        pile[i] += otherPile[i];
    }
    // No need to run stabilize if the pile is already stable
    if (!isStable()) stabilize();
}

// Determine if sandpile is in abelian group
bool SandPile::isInGroup() const {
    int copy[ARRAY_SIZE];
    // Make a copy of the current pile for determining change after adding
    for (int i = 0; i < ARRAY_SIZE; i++) {
        copy[i] = pile[i];
    }

    SandPile zeroPile;
    SandPile copyPile(copy);

    // Add the copied pile and the zero pile
    copyPile.addPile(zeroPile);

    // Determine if the copied pile, added with zero, is equal to this pile
    const int* resultPile = copyPile.getPile();
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (resultPile[i] != pile[i]) return false;
    }
    return true;
}

// Set the pile value
void SandPile::setPile(const int *cells) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (cells[i] < 0)
            return;
    }
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        pile[i] = cells[i];
    }
}

const int * SandPile::getPile() const {
    return pile;
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
    while (!isStable()) {
        for (int i = 0; i < ARRAY_SIZE; i++) {
            if (pile[i] > MAX_STABLE) {
                int row = i / DIM;
                int col = i % DIM;
                pile[i] -= MAX_STABLE + 1;
                if (row > 0)
                    pile[index(row - 1, col)] += 1;
                if (row + 1 < DIM)
                    pile[index(row + 1, col)] += 1;
                if (col > 0)
                    pile[index(row, col - 1)] += 1;
                if (col + 1 < DIM)
                    pile[index(row, col + 1)] += 1;
            }
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

int SandPile::index(int row, int col) {
    return row * DIM + col;
}