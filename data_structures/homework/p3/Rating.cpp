//
// Created by Haake on 10/5/2020.
//

#include "Rating.h"

Rating::Rating(int initialBookCapacity) {
    memberCapacity = INITIAL_MEMBER_CAPACITY;
    bookCapacity = initialBookCapacity;

    // Allocate memory for 2D array
    ratingArray = new int*[memberCapacity];
    for (int i = 0; i < memberCapacity; ++i) {
        ratingArray[i] = new int[bookCapacity];
    }
}

Rating::Rating(const Rating &other) {
    // Copy data elements
    memberCapacity = other.memberCapacity;
    bookCapacity = other.bookCapacity;

    // Allocate memory with new capacity
    ratingArray = new int*[memberCapacity];
    for (int i = 0; i < memberCapacity; ++i) {
        ratingArray[i] = new int[bookCapacity];
    }

    // Copy over elements from other
    for (int i = 0; i < memberCapacity; ++i) {
        for (int j = 0; j < bookCapacity; ++j) {
            ratingArray[i][j] = other.ratingArray[i][j];
        }
    }
}

Rating &Rating::operator=(const Rating &rhs) {
    if (this != &rhs) {

        // Deallocate memory
        clear();

        // Assign capacity from rhs
        this->bookCapacity = rhs.bookCapacity;
        this->memberCapacity = rhs.memberCapacity;

        // Allocate memory with new capacities
        this->ratingArray = new int*[memberCapacity];
        for (int i = 0; i < memberCapacity; ++i) {
            ratingArray[i] = new int[bookCapacity];
        }

        // Copy over elements from rhs
        for (int i = 0; i < memberCapacity; ++i) {
            for (int j = 0; j < bookCapacity; ++j) {
                ratingArray[i][j] = rhs.ratingArray[i][j];
            }
        }
    }
}

Rating::~Rating() {
    clear();
}

