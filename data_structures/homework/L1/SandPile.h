//
// Created by Kramer Johnson on 9/15/2020.
//

#ifndef L1_SANDPILE_H
#define L1_SANDPILE_H

#include <vector>
#include <string>

/**
 * A class to model the functionality of a 3x3
 * abelian sand pile.
 */

const int ARRAY_SIZE = 9;
const int MAX_STABLE = 3;

class SandPile {
public:
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
    int pile[ARRAY_SIZE];

    /**
     * A helper function to return a vector of indexes that border the
     * passed in index in a 3x3 array.
     * @param a positive integer index in a 3x3 array (0 - 8)
     * @return a vector of integer indexes that border the passed index
     */
    std::vector<int> getBorders(const int index) const;

    /**
     * A helper function to find and return the index of an element
     * in the pile with a size more than MAX_STABLE.
     * @return index of the first element in the pile that is over the
     * MAX_STABLE size. -1 if no element is found
     */
     int getSpillElement() const;
};


#endif //L1_SANDPILE_H
