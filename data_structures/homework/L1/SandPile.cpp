//
// Created by Kramer Johnson on 9/15/2020.
// CPSC 5910 03 20FQ Data Structures
//

#include "SandPile.h"
#include <sstream>

using namespace std;

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