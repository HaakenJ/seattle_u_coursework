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
    delete[] pile;
}

// Copy ctor
SandPile::SandPile(const SandPile &rhs) {
    pile = new int[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        pile[i] = rhs.pile[i];
    }
}

// Assignment overload
SandPile &SandPile::operator=(const SandPile &rhs) {
    if (&rhs != this) {
        delete[] pile; // Get rid of old data (do what dtor would do

        // copy constructor code
        pile = new int[ARRAY_SIZE];
        for (int i = 0; i < ARRAY_SIZE; i++) {
            pile[i] = rhs.pile[i];
        }
    }
    return *this;
}

// Add a sandpile to this one
void SandPile::addPile(const SandPile &other) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        pile[i] += other.pile[i];
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
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (copyPile.pile[i] != pile[i]) return false;
    }
    return true;
}

// Set the pile value
// ***Added loop to test for negative values from L1 solution
void SandPile::setPile(const int *cells) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (cells[i] < 0)
            throw invalid_argument("No values can be negative.");
    }
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
// *** This implementation is from L1 solution
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
// *** This implementation is from L1 solution
string SandPile::toString() const {
    ostringstream buffer;
    for (int row = 0; row < DIM; row++) {
        buffer << pile[index(row, 0)] << " " << pile[index(row, 1)] << " " << pile[index(row, 2)]
               << (row == DIM - 1 ? "" : " / ");
    }
    return buffer.str();
}

// Return the index in a flat array given the indexes in a 2D array
// *** Implementation is from L1 solution
int SandPile::index(int row, int col) {
    return row * DIM + col;
}