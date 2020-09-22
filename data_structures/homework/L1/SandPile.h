//
// Created by Kramer Johnson on 9/15/2020.
// CPSC 5910 03 20FQ Data Structures
//

#ifndef L1_SANDPILE_H
#define L1_SANDPILE_H

#include <iostream>
#include <string>

/**
 * A class to model the functionality of a 3x3
 * abelian sand pile.
 */

class SandPile {
public:
    static const int DIM = 3;
    static const int MAX_STABLE = 3;
    /**
     * Set the values of each cell in this sand pile.
     * 
     * @precon all elements are 0 or greater
     * @param cells 1st row elements, then 2nd, etc. all
     * in one flat array
     */
    void setPile(const int *cells);

    /**
     * Is this sand pile stable or will it topple?
     * i.e., if there are any cells over 3 (SandPile::MAX_STABLE)
     * then it will topple.
     *
     * @return true if the sand pile won't topple, false if it will
     */
    bool isStable() const;

    /**
     * Topple this sand pile until it is stable (according to toppling
     * rules).
     * Each unstable cell spills one grain of sand in each direction.
     * If they fall off the edge, that's okay.
     *
     */
    void stabilize();

    /**
     * Get a string suitable for printing out.
     * @return a 3-line string with the contents of this sand pile.
     */
    std::string toString() const;

private:
    static const int ARRAY_SIZE = DIM * DIM;  // size of flat array
    int pile[ARRAY_SIZE];

    static int index(int row, int col);  // helper to map from r,c --> index into flat array
};


#endif //L1_SANDPILE_H
