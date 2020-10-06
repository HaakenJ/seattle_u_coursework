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

//Rating &Rating::operator=(const Rating &rhs) {
//    if (this != &rhs) {
//
//        // Deallocate memory
//        clear();
//
//        // Assign capacity from rhs
//        this->bookCapacity = rhs.bookCapacity;
//        this->memberCapacity = rhs.memberCapacity;
//
//        // Allocate memory with new capacities
//        this->ratingArray = new int*[memberCapacity];
//        for (int i = 0; i < memberCapacity; ++i) {
//            ratingArray[i] = new int[bookCapacity];
//        }
//
//        // Copy over elements from rhs
//        for (int i = 0; i < memberCapacity; ++i) {
//            for (int j = 0; j < bookCapacity; ++j) {
//                ratingArray[i][j] = rhs.ratingArray[i][j];
//            }
//        }
//    }
//}

Rating::~Rating() {
//    clear();

}

void Rating::addRating(int memberId, int bookId, int rating) {
    ratingArray[memberId][bookId] = rating;
}

int Rating::getRating(int memberId, int bookId) {
    return ratingArray[memberId][bookId];
}

int Rating::mostSimilar(int memberId) {
    // Keep track of highest dot product
    int maxDotProduct = 0;
    // Keep track of most similar member
    int mostSimId = 0;
    // Keep track of current dot product
    int currDotProduct = 0;

    // Loop through the ratings array
    // Compare each member with each other member
    // Calculate the dot product of each member combo
    // Overwrite the maxDotProduct each time a most similar is found
    // Overwrite mostSimid with the member id of the most similar
    for (int i = 0; i < memberCapacity; ++i) {
        for (int j = 0; j < memberCapacity; ++j) {
            // Skip comparing member against self
            if (i == j) continue;
            for (int k = 0; k < bookCapacity; ++k) {
                // Member one that stays same is ratingsArray[i][k]
                // Member two that is being compared is ratingsArray[j][k]
                currDotProduct += ratingArray[i][k] * ratingArray[j][k];
            }
            if (currDotProduct > maxDotProduct) {
                maxDotProduct = currDotProduct;
                mostSimId = j;
            }
            currDotProduct = 0;
        }
    }
    // Return the most similar member's id
    return mostSimId;
}

// What does this function even do???
void Rating::addMember(int memberId) {

}

void Rating::addBook(int bookId) {

}

void Rating::resizeCol(int newCount) {

}

void Rating::resizeRow(int newCount) {

}

void Rating::clear() {

}
